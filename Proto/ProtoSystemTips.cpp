
//#include "stdafx.h"


#include "ProtoSystemTips.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stAwardUnit::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = 10;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, cnt);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;

	if (type==AwardType_Money) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = moneytype;
    ++buffersize;
    ++p;
    --leftsize;
	}

	buffer[0] = buffersize;
}

void stAwardUnit::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        int oldsize = buffersize; 
    int skiplen = 0;
    if (1 > buffersize)
        throw DecodeError();
    skiplen = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    cnt = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;

	if (type==AwardType_Money) {    if (1 > buffersize)
        throw DecodeError();
    moneytype = *p;
    --buffersize;
    ++p;
	}

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stAwardUnit::stAwardUnit()
{
    SetDefault();
}
void stAwardUnit::SetDefault()
{

}

void stHighlightMsgUnit::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = 2;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, msg_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &msg[0], msg_arraylen);
    buffersize += msg_arraylen;
    p += msg_arraylen;
    leftsize-= msg_arraylen;

	buffer[0] = buffersize;
}

void stHighlightMsgUnit::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        int oldsize = buffersize; 
    int skiplen = 0;
    if (1 > buffersize)
        throw DecodeError();
    skiplen = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&msg, 0, sizeof(char)*MAX_LEN_LARGE);
    msg_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&msg, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    msg_arraylen = arraysize;

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stHighlightMsgUnit::stHighlightMsgUnit()
{
    SetDefault();
}
void stHighlightMsgUnit::SetDefault()
{
    msg_arraylen = 0;

}


/* body */
void XJCMD_SC_SYSTEM_TIPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, tipType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chatType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    tipContent.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_SC_SYSTEM_TIPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    tipType = static_cast<eSystemTipShowEnum>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    chatType = static_cast<eChatTypeEnum>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    tipContent.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_SC_SYSTEM_TIPSC::CommandID()
{
    return XJCMD_SC_SYSTEM_TIP;
}
int XJCMD_SC_SYSTEM_TIPSC::GetCommandID()
{
    return XJCMD_SC_SYSTEM_TIP;
}

XJCMD_SC_SYSTEM_TIPSC::XJCMD_SC_SYSTEM_TIPSC()
{
    SetDefault();
}
void XJCMD_SC_SYSTEM_TIPSC::SetDefault()
{

}

void XJCMD_SC_AWARD_TIPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = awarddata_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<awarddata_arraylen; ++i) {
        arraysize = leftsize;
        awarddata[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_SC_AWARD_TIPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&awarddata, 0, sizeof(stAwardUnit)*255);
    awarddata_arraylen = 0;
    if (arraysize > 255) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        awarddata[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    awarddata_arraylen = arraysize;
}

int XJCMD_SC_AWARD_TIPSC::CommandID()
{
    return XJCMD_SC_AWARD_TIP;
}
int XJCMD_SC_AWARD_TIPSC::GetCommandID()
{
    return XJCMD_SC_AWARD_TIP;
}

XJCMD_SC_AWARD_TIPSC::XJCMD_SC_AWARD_TIPSC()
{
    SetDefault();
}
void XJCMD_SC_AWARD_TIPSC::SetDefault()
{
    awarddata_arraylen = 0;

}

void XJCMD_SC_HIGHLIGHT_TIPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = msgs_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<msgs_arraylen; ++i) {
        arraysize = leftsize;
        msgs[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_SC_HIGHLIGHT_TIPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&msgs, 0, sizeof(stHighlightMsgUnit)*255);
    msgs_arraylen = 0;
    if (arraysize > 255) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        msgs[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    msgs_arraylen = arraysize;
}

int XJCMD_SC_HIGHLIGHT_TIPSC::CommandID()
{
    return XJCMD_SC_HIGHLIGHT_TIP;
}
int XJCMD_SC_HIGHLIGHT_TIPSC::GetCommandID()
{
    return XJCMD_SC_HIGHLIGHT_TIP;
}

XJCMD_SC_HIGHLIGHT_TIPSC::XJCMD_SC_HIGHLIGHT_TIPSC()
{
    SetDefault();
}
void XJCMD_SC_HIGHLIGHT_TIPSC::SetDefault()
{
    msgs_arraylen = 0;

}

};

