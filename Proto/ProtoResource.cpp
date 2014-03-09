
//#include "stdafx.h"


#include "ProtoResource.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CSC_RESOURCE_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = res_type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, version_res);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = full_flag;
    ++buffersize;
    ++p;
    --leftsize;
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, resdata.size());
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < resdata.size()) 
        throw EncodeError();
    memcpy(p,&resdata[0], resdata.size());
    buffersize += resdata.size();
    p += resdata.size();
    leftsize-= resdata.size();
}

void XJCMD_CSC_RESOURCE_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    res_type = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    version_res = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    full_flag = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    resdata.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    resdata.resize(arraysize);
    memcpy(&resdata[0], p, arraysize*sizeof(char));
    resdata.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

int XJCMD_CSC_RESOURCE_SYNSC::CommandID()
{
    return XJCMD_CSC_RESOURCE_SYN;
}
int XJCMD_CSC_RESOURCE_SYNSC::GetCommandID()
{
    return XJCMD_CSC_RESOURCE_SYN;
}

XJCMD_CSC_RESOURCE_SYNSC::XJCMD_CSC_RESOURCE_SYNSC()
{
    SetDefault();
}
void XJCMD_CSC_RESOURCE_SYNSC::SetDefault()
{
    resdata.clear();

}

};

