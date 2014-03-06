
//#include "stdafx.h"


#include "ProtoSystemDialog.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stSystemDlgBtnInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, btn_key);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    params.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void stSystemDlgBtnInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    btn_key = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    params.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

stSystemDlgBtnInfo::stSystemDlgBtnInfo()
{
    SetDefault();
}
void stSystemDlgBtnInfo::SetDefault()
{

}


/* body */
void XJCMD_SC_SYSTEM_DIALOGSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, key);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasClose;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasTitle;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    titleName.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasLftButton;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    lftButtonName.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, lftButtonKey.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < lftButtonKey.size()) 
        throw EncodeError();
    memcpy(p,&lftButtonKey[0], lftButtonKey.size());
    buffersize += lftButtonKey.size();
    p += lftButtonKey.size();
    leftsize-= lftButtonKey.size();
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasRgtButton;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    rgtButtonName.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, rgtButtonKey.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < rgtButtonKey.size()) 
        throw EncodeError();
    memcpy(p,&rgtButtonKey[0], rgtButtonKey.size());
    buffersize += rgtButtonKey.size();
    p += rgtButtonKey.size();
    leftsize-= rgtButtonKey.size();
  
    arraysize = leftsize;
    dlgContent.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_SC_SYSTEM_DIALOGSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    key = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    hasClose = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    hasTitle = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    titleName.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    hasLftButton = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    lftButtonName.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    lftButtonKey.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    lftButtonKey.resize(arraysize);
    memcpy(&lftButtonKey[0], p, arraysize*sizeof(char));
    lftButtonKey.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
    if (1 > buffersize)
        throw DecodeError();
    hasRgtButton = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    rgtButtonName.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    rgtButtonKey.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    rgtButtonKey.resize(arraysize);
    memcpy(&rgtButtonKey[0], p, arraysize*sizeof(char));
    rgtButtonKey.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    arraysize = buffersize;
    dlgContent.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_SC_SYSTEM_DIALOGSC::CommandID()
{
    return XJCMD_SC_SYSTEM_DIALOG;
}
int XJCMD_SC_SYSTEM_DIALOGSC::GetCommandID()
{
    return XJCMD_SC_SYSTEM_DIALOG;
}

XJCMD_SC_SYSTEM_DIALOGSC::XJCMD_SC_SYSTEM_DIALOGSC()
{
    SetDefault();
}
void XJCMD_SC_SYSTEM_DIALOGSC::SetDefault()
{
    lftButtonKey.clear();
    rgtButtonKey.clear();

}

void XJCMD_CS_SYSTEM_RECYCLECHECKCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    paramString.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CS_SYSTEM_RECYCLECHECKCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    paramString.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CS_SYSTEM_RECYCLECHECKCS::CommandID()
{
    return XJCMD_CS_SYSTEM_RECYCLECHECK;
}
int XJCMD_CS_SYSTEM_RECYCLECHECKCS::GetCommandID()
{
    return XJCMD_CS_SYSTEM_RECYCLECHECK;
}

XJCMD_CS_SYSTEM_RECYCLECHECKCS::XJCMD_CS_SYSTEM_RECYCLECHECKCS()
{
    SetDefault();
}
void XJCMD_CS_SYSTEM_RECYCLECHECKCS::SetDefault()
{

}

};

