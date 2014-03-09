
//#include "stdafx.h"


#include "ProtoChat.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CSC_CHATCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chatType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chatContent_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_CHAT_NUM) 
        throw EncodeError();
    memcpy(p, &chatContent[0], chatContent_arraylen);
    buffersize += chatContent_arraylen;
    p += chatContent_arraylen;
    leftsize-= chatContent_arraylen;
}

void XJCMD_CSC_CHATCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    chatType = static_cast<eChatTypeEnum>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&chatContent, 0, sizeof(char)*MAX_CHAT_NUM);
    chatContent_arraylen = 0;
    if (arraysize > MAX_CHAT_NUM) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&chatContent, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    chatContent_arraylen = arraysize;
}

int XJCMD_CSC_CHATCS::CommandID()
{
    return XJCMD_CSC_CHAT;
}
int XJCMD_CSC_CHATCS::GetCommandID()
{
    return XJCMD_CSC_CHAT;
}

XJCMD_CSC_CHATCS::XJCMD_CSC_CHATCS()
{
    SetDefault();
}
void XJCMD_CSC_CHATCS::SetDefault()
{
    chatContent_arraylen = 0;

}

void XJCMD_CSC_CHATSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chatType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chatContent_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_CHAT_NUM) 
        throw EncodeError();
    memcpy(p, &chatContent[0], chatContent_arraylen);
    buffersize += chatContent_arraylen;
    p += chatContent_arraylen;
    leftsize-= chatContent_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, srcName_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &srcName[0], srcName_arraylen);
    buffersize += srcName_arraylen;
    p += srcName_arraylen;
    leftsize-= srcName_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, srcID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_CHATSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    chatType = static_cast<eChatTypeEnum>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&chatContent, 0, sizeof(char)*MAX_CHAT_NUM);
    chatContent_arraylen = 0;
    if (arraysize > MAX_CHAT_NUM) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&chatContent, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    chatContent_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&srcName, 0, sizeof(char)*MAX_NAME_LEN);
    srcName_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&srcName, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    srcName_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    srcID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_CHATSC::CommandID()
{
    return XJCMD_CSC_CHAT;
}
int XJCMD_CSC_CHATSC::GetCommandID()
{
    return XJCMD_CSC_CHAT;
}

XJCMD_CSC_CHATSC::XJCMD_CSC_CHATSC()
{
    SetDefault();
}
void XJCMD_CSC_CHATSC::SetDefault()
{
    chatContent_arraylen = 0;
    srcName_arraylen = 0;

}

};

