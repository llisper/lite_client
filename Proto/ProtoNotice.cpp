
//#include "stdafx.h"


#include "ProtoNotice.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CSC_SYSTEM_NOTICECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = clientVersion_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &clientVersion[0], clientVersion_arraylen);
    buffersize += clientVersion_arraylen;
    p += clientVersion_arraylen;
    leftsize-= clientVersion_arraylen;
}

void XJCMD_CSC_SYSTEM_NOTICECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&clientVersion, 0, sizeof(char)*MAX_LEN_SMALL);
    clientVersion_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&clientVersion, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    clientVersion_arraylen = arraysize;
}

int XJCMD_CSC_SYSTEM_NOTICECS::CommandID()
{
    return XJCMD_CSC_SYSTEM_NOTICE;
}
int XJCMD_CSC_SYSTEM_NOTICECS::GetCommandID()
{
    return XJCMD_CSC_SYSTEM_NOTICE;
}

XJCMD_CSC_SYSTEM_NOTICECS::XJCMD_CSC_SYSTEM_NOTICECS()
{
    SetDefault();
}
void XJCMD_CSC_SYSTEM_NOTICECS::SetDefault()
{
    clientVersion_arraylen = 0;

}

void XJCMD_CSC_SYSTEM_NOTICESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = clientVersion_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &clientVersion[0], clientVersion_arraylen);
    buffersize += clientVersion_arraylen;
    p += clientVersion_arraylen;
    leftsize-= clientVersion_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, qhtmlcontent_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<qhtmlcontent_arraylen; ++i) {
        arraysize = leftsize;
        qhtmlcontent[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_SYSTEM_NOTICESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&clientVersion, 0, sizeof(char)*MAX_LEN_SMALL);
    clientVersion_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&clientVersion, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    clientVersion_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&qhtmlcontent, 0, sizeof(stQhtml)*MAX_NOTICE_NUM);
    qhtmlcontent_arraylen = 0;
    if (arraysize > MAX_NOTICE_NUM) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        qhtmlcontent[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    qhtmlcontent_arraylen = arraysize;
}

int XJCMD_CSC_SYSTEM_NOTICESC::CommandID()
{
    return XJCMD_CSC_SYSTEM_NOTICE;
}
int XJCMD_CSC_SYSTEM_NOTICESC::GetCommandID()
{
    return XJCMD_CSC_SYSTEM_NOTICE;
}

XJCMD_CSC_SYSTEM_NOTICESC::XJCMD_CSC_SYSTEM_NOTICESC()
{
    SetDefault();
}
void XJCMD_CSC_SYSTEM_NOTICESC::SetDefault()
{
    clientVersion_arraylen = 0;
    qhtmlcontent_arraylen = 0;

}

};

