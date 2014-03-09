#ifndef __CProto_COMMON_H__ 
#define __CProto_COMMON_H__ 

#include <fcntl.h>
#ifdef WIN32
#include <WinSock2.h>
#pragma warning(disable:4290)
typedef long long int int64_t;
typedef unsigned long long uint64_t;

#define XJOL_NTOHLL(x)  (((int64_t)(ntohl((x) & 0xFFFFFFFF)) << 32) | (ntohl(((x) >> 32) & 0xFFFFFFFF)))
#define XJOL_NTOHL(x)   ntohl((x))
#define XJOL_NTOHS(x)   ntohs((x))
#define XJOL_HTONLL(x)  (((int64_t)(htonl((x) & 0xFFFFFFFF)) << 32) | (htonl(((x) >> 32) & 0xFFFFFFFF)))
#define XJOL_HTONL(x)   htonl((x))
#define XJOL_HTONS(x)   htons((x))

#elif defined(MacOS) || defined(IOS)

#include <libkern/OSByteOrder.h>

#define XJOL_NTOHLL(x) OSSwapInt64(x)
#define XJOL_NTOHL(x) OSSwapInt32(x)
#define XJOL_NTOHS(x) OSSwapInt16(x)
#define XJOL_HTONLL(x) OSSwapInt64(x)
#define XJOL_HTONL(x) OSSwapInt32(x)
#define XJOL_HTONS(x) OSSwapInt16(x)

#else

#include <unistd.h>
#include <endian.h>
#include <byteswap.h>
#include <stdint.h>
#include <inttypes.h>

#if __BYTE_ORDER == __BIG_ENDIAN
/**The host byte order is the same as network byte order, so these functions are all just identity */
    #define XJOL_NTOHLL(x)  (x)
    #define XJOL_NTOHL(x)   (x)
    #define XJOL_NTOHS(x)   (x)
    #define XJOL_HTONLL(x)  (x)
    #define XJOL_HTONL(x)   (x)
    #define XJOL_HTONS(x)   (x)
#else
    #if __BYTE_ORDER == __LITTLE_ENDIAN
        #define XJOL_NTOHLL(x) bswap_64(x)
        #define XJOL_NTOHL(x)  bswap_32(x)
        #define XJOL_NTOHS(x)  bswap_16(x)
        #define XJOL_HTONLL(x) bswap_64(x)
        #define XJOL_HTONL(x)  bswap_32(x)
        #define XJOL_HTONS(x)  bswap_16(x)
    #endif
#endif

#endif
#include <errno.h>
#include <assert.h>
#include <memory.h>
#include <exception>
#include <string>



namespace CProto {
    
    class EncodeError : public std::exception{};

    class DecodeError : public std::exception{};

    class PackBody
    {
    public:
        virtual ~PackBody() {};
	virtual void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError) = 0; 
	virtual void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError) = 0;
        virtual int CommandID() = 0;
	
    };

    static inline void h2n_32(unsigned char *buffer,unsigned int i)
    {
       unsigned int tmp = XJOL_HTONL(i);
       memcpy(buffer,&tmp,sizeof(unsigned int));
    }
    static inline void h2n_16(unsigned char *buffer,unsigned short sh)
    {
        unsigned short tmp = XJOL_HTONS(sh);
        memcpy(buffer,&tmp,sizeof(unsigned short));
    }
    static inline void h2n_64(unsigned char *buffer,uint64_t l) 
    {
        uint64_t tmp = XJOL_HTONLL(l);
        memcpy(buffer, &tmp, sizeof(uint64_t));
    }
    static inline void h2n_float(unsigned char *buffer,float f) 
    {
        int tmp;
        memcpy(&tmp,&f,sizeof(int));
        return h2n_32( buffer,tmp );
    }
    static inline void h2n_double(unsigned char *buffer,double d)
    {
        int64_t tmp;
        memcpy(&tmp,&d,sizeof(int64_t));
        return h2n_64( buffer,tmp );
    }
    static inline unsigned int n2h_32(const unsigned char *buffer)
    {
        //char temp[4]; 
        //memcpy(temp, buffer, 4);
        unsigned int tmp = *(const unsigned int *)buffer;
        return XJOL_NTOHL(tmp);
    }
    static inline unsigned short n2h_16(const unsigned char *buffer)
    {
        unsigned short tmp = *(const unsigned short *)buffer;
        return XJOL_NTOHS(tmp);
    }
    static inline uint64_t n2h_64(const unsigned char *buffer) 
    {
        uint64_t tmp;
	memcpy(&tmp,buffer,sizeof(uint64_t));
        return XJOL_NTOHLL(tmp);
    }
    static inline float n2h_float(const unsigned char *buffer) 
    {
        int tmp = n2h_32(buffer);
        float f;
        memcpy( &f,&tmp,sizeof(f));
        return f;
    }
    static inline double n2h_double(const unsigned char *buffer)
    {
        int64_t tmp = n2h_64( buffer );
        double d;
        memcpy(&d,&tmp,sizeof(d));
        return d;
    }

#include "proto_string.h"
#include "proto_vector.h"
}

#endif

