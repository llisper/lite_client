
//#include "stdafx.h"


#include "ProtoLog.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stLogUnit::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    name.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    arraysize = leftsize;
    value.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void stLogUnit::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    name.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    arraysize = buffersize;
    value.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

stLogUnit::stLogUnit()
{
    SetDefault();
}
void stLogUnit::SetDefault()
{

}


/* body */
void XJCMD_CS_LOGCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    logname.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, logunits_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<logunits_arraylen; ++i) {
        arraysize = leftsize;
        logunits[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CS_LOGCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    logname.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&logunits, 0, sizeof(stLogUnit)*255);
    logunits_arraylen = 0;
    if (arraysize > 255) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        logunits[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    logunits_arraylen = arraysize;
}

int XJCMD_CS_LOGCS::CommandID()
{
    return XJCMD_CS_LOG;
}
int XJCMD_CS_LOGCS::GetCommandID()
{
    return XJCMD_CS_LOG;
}

XJCMD_CS_LOGCS::XJCMD_CS_LOGCS()
{
    SetDefault();
}
void XJCMD_CS_LOGCS::SetDefault()
{
    logunits_arraylen = 0;

}

};

