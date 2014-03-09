
//#include "stdafx.h"


#include "ProtoChar.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CREATECHARCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, m_Name_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &m_Name[0], m_Name_arraylen);
    buffersize += m_Name_arraylen;
    p += m_Name_arraylen;
    leftsize-= m_Name_arraylen;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = m_Sex;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = m_MenPai;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CREATECHARCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&m_Name, 0, sizeof(char)*MAX_NAME_LEN);
    m_Name_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&m_Name, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    m_Name_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    m_Sex = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    m_MenPai = *p;
    --buffersize;
    ++p;
}

int XJCMD_CREATECHARCS::CommandID()
{
    return XJCMD_CREATECHAR;
}
int XJCMD_CREATECHARCS::GetCommandID()
{
    return XJCMD_CREATECHAR;
}

XJCMD_CREATECHARCS::XJCMD_CREATECHARCS()
{
    SetDefault();
}
void XJCMD_CREATECHARCS::SetDefault()
{
    m_Name_arraylen = 0;

}

void XJCMD_CREATECHARSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = m_Ret;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, m_ErrMsg_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &m_ErrMsg[0], m_ErrMsg_arraylen);
    buffersize += m_ErrMsg_arraylen;
    p += m_ErrMsg_arraylen;
    leftsize-= m_ErrMsg_arraylen;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, m_Guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CREATECHARSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    m_Ret = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&m_ErrMsg, 0, sizeof(char)*MAX_LEN_SMALL);
    m_ErrMsg_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&m_ErrMsg, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    m_ErrMsg_arraylen = arraysize;
  
    if (8 > buffersize)
        throw DecodeError();
    m_Guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CREATECHARSC::CommandID()
{
    return XJCMD_CREATECHAR;
}
int XJCMD_CREATECHARSC::GetCommandID()
{
    return XJCMD_CREATECHAR;
}

XJCMD_CREATECHARSC::XJCMD_CREATECHARSC()
{
    SetDefault();
}
void XJCMD_CREATECHARSC::SetDefault()
{
    m_ErrMsg_arraylen = 0;

}

void XJCMD_DELETECHARCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, m_Guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = m_DelType;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_DELETECHARCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    m_Guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
    if (1 > buffersize)
        throw DecodeError();
    m_DelType = *p;
    --buffersize;
    ++p;
}

int XJCMD_DELETECHARCS::CommandID()
{
    return XJCMD_DELETECHAR;
}
int XJCMD_DELETECHARCS::GetCommandID()
{
    return XJCMD_DELETECHAR;
}

XJCMD_DELETECHARCS::XJCMD_DELETECHARCS()
{
    SetDefault();
}
void XJCMD_DELETECHARCS::SetDefault()
{

}

void XJCMD_DELETECHARSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = m_Ret;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, m_ErrMsg_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &m_ErrMsg[0], m_ErrMsg_arraylen);
    buffersize += m_ErrMsg_arraylen;
    p += m_ErrMsg_arraylen;
    leftsize-= m_ErrMsg_arraylen;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = m_DelType;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, m_Guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_DELETECHARSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    m_Ret = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&m_ErrMsg, 0, sizeof(char)*MAX_LEN_SMALL);
    m_ErrMsg_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&m_ErrMsg, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    m_ErrMsg_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    m_DelType = *p;
    --buffersize;
    ++p;
  
    if (8 > buffersize)
        throw DecodeError();
    m_Guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_DELETECHARSC::CommandID()
{
    return XJCMD_DELETECHAR;
}
int XJCMD_DELETECHARSC::GetCommandID()
{
    return XJCMD_DELETECHAR;
}

XJCMD_DELETECHARSC::XJCMD_DELETECHARSC()
{
    SetDefault();
}
void XJCMD_DELETECHARSC::SetDefault()
{
    m_ErrMsg_arraylen = 0;

}

void XJCMD_CANCELDELETECHARCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, m_Guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CANCELDELETECHARCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    m_Guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CANCELDELETECHARCS::CommandID()
{
    return XJCMD_CANCELDELETECHAR;
}
int XJCMD_CANCELDELETECHARCS::GetCommandID()
{
    return XJCMD_CANCELDELETECHAR;
}

XJCMD_CANCELDELETECHARCS::XJCMD_CANCELDELETECHARCS()
{
    SetDefault();
}
void XJCMD_CANCELDELETECHARCS::SetDefault()
{

}

void XJCMD_CANCELDELETECHARSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = m_Ret;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, m_ErrMsg_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &m_ErrMsg[0], m_ErrMsg_arraylen);
    buffersize += m_ErrMsg_arraylen;
    p += m_ErrMsg_arraylen;
    leftsize-= m_ErrMsg_arraylen;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, m_Guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CANCELDELETECHARSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    m_Ret = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&m_ErrMsg, 0, sizeof(char)*MAX_LEN_SMALL);
    m_ErrMsg_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&m_ErrMsg, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    m_ErrMsg_arraylen = arraysize;
  
    if (8 > buffersize)
        throw DecodeError();
    m_Guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CANCELDELETECHARSC::CommandID()
{
    return XJCMD_CANCELDELETECHAR;
}
int XJCMD_CANCELDELETECHARSC::GetCommandID()
{
    return XJCMD_CANCELDELETECHAR;
}

XJCMD_CANCELDELETECHARSC::XJCMD_CANCELDELETECHARSC()
{
    SetDefault();
}
void XJCMD_CANCELDELETECHARSC::SetDefault()
{
    m_ErrMsg_arraylen = 0;

}

};

