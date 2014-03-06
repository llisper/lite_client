
//#include "stdafx.h"


#include "ProtoTitle.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stTitleListData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleIndex);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = titleState;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, timeOutValue);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stTitleListData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    titleIndex = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    titleID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    titleState = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    timeOutValue = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stTitleListData::stTitleListData()
{
    SetDefault();
}
void stTitleListData::SetDefault()
{

}


/* body */
void XJCMD_CSC_TITLE_ADDSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleIndex);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_TITLE_ADDSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    titleIndex = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    titleID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_TITLE_ADDSC::CommandID()
{
    return XJCMD_CSC_TITLE_ADD;
}
int XJCMD_CSC_TITLE_ADDSC::GetCommandID()
{
    return XJCMD_CSC_TITLE_ADD;
}

XJCMD_CSC_TITLE_ADDSC::XJCMD_CSC_TITLE_ADDSC()
{
    SetDefault();
}
void XJCMD_CSC_TITLE_ADDSC::SetDefault()
{

}

void XJCMD_SC_TITLE_STATE_LIST_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = user_version;
    ++buffersize;
    ++p;
    --leftsize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, titleStateList.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<titleStateList.size(); ++i) {
        arraysize = leftsize;
        titleStateList[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_SC_TITLE_STATE_LIST_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    user_version = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    titleStateList.clear();
  
    titleStateList.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        titleStateList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_SC_TITLE_STATE_LIST_SYNSC::CommandID()
{
    return XJCMD_SC_TITLE_STATE_LIST_SYN;
}
int XJCMD_SC_TITLE_STATE_LIST_SYNSC::GetCommandID()
{
    return XJCMD_SC_TITLE_STATE_LIST_SYN;
}

XJCMD_SC_TITLE_STATE_LIST_SYNSC::XJCMD_SC_TITLE_STATE_LIST_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_TITLE_STATE_LIST_SYNSC::SetDefault()
{
    titleStateList.clear();

}

void XJCMD_CSC_TITLE_USECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleIndex);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_TITLE_USECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    titleIndex = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_TITLE_USECS::CommandID()
{
    return XJCMD_CSC_TITLE_USE;
}
int XJCMD_CSC_TITLE_USECS::GetCommandID()
{
    return XJCMD_CSC_TITLE_USE;
}

XJCMD_CSC_TITLE_USECS::XJCMD_CSC_TITLE_USECS()
{
    SetDefault();
}
void XJCMD_CSC_TITLE_USECS::SetDefault()
{

}

};

