#include <stdio.h>
#include <signal.h>

#include <event2/util.h>
#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/bufferevent.h>

#include "ProtoLogin.h"
#include "CProto_Command.h"
#include "ProtoPack_Package.h"

#define SERVER_ADDR "10.1.152.64:5009"

static void sigint(evutil_socket_t, short, void *);
static void timer_tick(evutil_socket_t, short, void *);
static void event_cb(bufferevent* bev, short what, void* ctx);
static void recv_cb(bufferevent* bev, void* ctx);

char user_name[128];

int main(int argc, char *argv[]) {
    event_base *base;
    bufferevent *bev;
    event *ev_sigint, *ev_tick;
    sockaddr_in sin;
    int len = sizeof(sin);

    strncpy(argv[1], user_name, 128);

    base = event_base_new();

    ev_sigint = evsignal_new(base, SIGINT, sigint, base);
    evsignal_add(ev_sigint, NULL);

    ev_tick = event_new(base, -1, EV_PERSIST, timer_tick, NULL);
    timeval period = { 1, 0 };
    evtimer_add(ev_tick, &period);

    evutil_parse_sockaddr_port(SERVER_ADDR, (sockaddr*)&sin, &len);
    bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
	bufferevent_enable(bev, EV_WRITE|EV_READ);
    bufferevent_setcb(bev, recv_cb, NULL, event_cb, NULL);
    bufferevent_socket_connect(bev, (sockaddr*)&sin, len);

    event_base_dispatch(base);
    event_free(ev_sigint);
    event_free(ev_tick);
    event_base_free(base);

    printf("done\n");
    return 0;
}
 
void sigint(evutil_socket_t, short, void *arg) {
    event_base *base = (event_base*)arg;
    timeval delay = { 2, 0 };
    printf("Caught SIGINT, start finalize.\n");
    event_base_loopexit(base, &delay);
}

void timer_tick(evutil_socket_t, short, void *) {
}

static void event_cb(bufferevent* bev, short what, void* ctx)
{
    if (what & BEV_EVENT_CONNECTED)
    {
        printf("connected\n"); 
        // construct packet 101
        int packet_size = CProto::PackcHelper::GetBodySize(CProto::XJCMD_CSC_VERSION);
        char* buffer = new char[packet_size];
        CProto::packc packet;
        packet.Init(CProto::XJCMD_CSC_VERSION, buffer);
        CProto::XJCMD_CSC_VERSIONCS* body = packet.GetXJCMD_CSC_VERSIONCS();

        strcpy(body->user, user_name);
        body->user_arraylen = strlen(body->user);
        strcpy(body->sign, "i am llisper");
        body->sign_arraylen = strlen(body->sign);
        body->version = 2;
        strcpy(body->ver, "0.0.1");
        body->ver_arraylen = strlen(body->ver);
        memset(body->dataversion.version, 0, sizeof(body->dataversion.version));
        body->dataversion.version_arraylen = CProto::DATA_TYPE_NUM;
        // encode packet
        unsigned char send_buffer[65535];
        unsigned int send_len = 65535;
        packet.Encode(send_buffer, send_len);
        // send on wire
        evbuffer* output = bufferevent_get_output(bev);
        evbuffer_add(output, send_buffer, send_len);
        printf("send 101\n");
        delete buffer;
    }
    else
    {
        printf("connection error\n"); 
        bufferevent_free(bev);
    }
}

static void recv_cb(bufferevent* bev, void* ctx)
{
    evbuffer *input = bufferevent_get_input(bev);
    unsigned char recv_buffer[65535];
    unsigned int recv_len = 65535;
    recv_len = evbuffer_copyout(input, recv_buffer, recv_len);
    evbuffer_drain(input, recv_len);
    printf("recv %d bytes:\n", recv_len);
    for (int i = 0; i < recv_len; ++i)
    {
        printf("%02x ", (int)recv_buffer[i]);
        if ((i + 1) % 8 == 0)
            printf("\n");
        else if ((i + 1) % 4 == 0)
            printf("   ");
    }
    printf("\n");
    // decode it and print cmd id
    // skip length(4) and uin(4) directly
    unsigned short command = CProto::n2h_16(recv_buffer + 8);
    int body_size = CProto::PacksHelper::GetBodySize(command);
    char *body_buffer = new char[body_size];
    CProto::packs packet;
    packet.Init(command, body_buffer);
    packet.Decode(recv_buffer, recv_len);
    printf("command %d, %d bytes left\n", packet.head.command, recv_len);
    bufferevent_free(bev);
}

