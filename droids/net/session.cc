#include "session.h"
#include "net_droid.h"

#include <event2/event.h>
#include <event2/bufferevent.h>

Session::Session(size_t sid, NetDroid *nd, bufferevent *bev) {
    sid_ = sid;
    nd_ = nd;
    bev_ = bev;

    bufferevent_setcb(bev, bev_read, NULL, bev_event, this);
    bufferevent_enable(bev, EV_READ|EV_WRITE);
}

Session::~Session(void) { }

int Session::Sniff(const char*& dptr, size_t& sz) {
    dptr = cbuf_.Sniff(sz);
    return 0;
}

int Session::Drain(size_t sz) {
    return cbuf_.Drain(sz);
}

int Session::Send(const char* dptr, size_t sz) {
    return bufferevent_write(bev_, dptr, sz);
}

void Session::bev_event(bufferevent *bev, short what, void *ctx) {
    Session *s = (Session*)ctx;
    bufferevent_free(s->bev_);
    s->nd_->CloseSession(s->sid_);
}

void Session::bev_read(bufferevent *bev, void *ctx) {
    Session *s = (Session*)ctx;
    char buf[4096];
    size_t bytes_read = bufferevent_read(s->bev_, buf, 4096);
    s->cbuf_.Push(buf, bytes_read);
}

