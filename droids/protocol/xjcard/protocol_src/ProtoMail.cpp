
//#include "stdafx.h"


#include "ProtoMail.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stMailSystemDataProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, state);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, title_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAIL_MAX_TITLE_LEN) 
        throw EncodeError();
    memcpy(p, &title[0], title_arraylen);
    buffersize += title_arraylen;
    p += title_arraylen;
    leftsize-= title_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, attachName_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAIL_MAX_ATTACH_FILE_NAME) 
        throw EncodeError();
    memcpy(p, &attachName[0], attachName_arraylen);
    buffersize += attachName_arraylen;
    p += attachName_arraylen;
    leftsize-= attachName_arraylen;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = attachCount;
    ++buffersize;
    ++p;
    --leftsize;
}

void stMailSystemDataProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    type = static_cast<eMailType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    state = static_cast<eMailState>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&title, 0, sizeof(char)*MAIL_MAX_TITLE_LEN);
    title_arraylen = 0;
    if (arraysize > MAIL_MAX_TITLE_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&title, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    title_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&attachName, 0, sizeof(char)*MAIL_MAX_ATTACH_FILE_NAME);
    attachName_arraylen = 0;
    if (arraysize > MAIL_MAX_ATTACH_FILE_NAME) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&attachName, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    attachName_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    attachCount = *p;
    --buffersize;
    ++p;
}

stMailSystemDataProto::stMailSystemDataProto()
{
    SetDefault();
}
void stMailSystemDataProto::SetDefault()
{
    title_arraylen = 0;
    attachName_arraylen = 0;

}

void stMailFriendDataProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, state);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, title_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAIL_MAX_TITLE_LEN) 
        throw EncodeError();
    memcpy(p, &title[0], title_arraylen);
    buffersize += title_arraylen;
    p += title_arraylen;
    leftsize-= title_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, senderName_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &senderName[0], senderName_arraylen);
    buffersize += senderName_arraylen;
    p += senderName_arraylen;
    leftsize-= senderName_arraylen;
}

void stMailFriendDataProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    type = static_cast<eMailType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    state = static_cast<eMailState>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&title, 0, sizeof(char)*MAIL_MAX_TITLE_LEN);
    title_arraylen = 0;
    if (arraysize > MAIL_MAX_TITLE_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&title, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    title_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&senderName, 0, sizeof(char)*MAX_NAME_LEN);
    senderName_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&senderName, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    senderName_arraylen = arraysize;
}

stMailFriendDataProto::stMailFriendDataProto()
{
    SetDefault();
}
void stMailFriendDataProto::SetDefault()
{
    title_arraylen = 0;
    senderName_arraylen = 0;

}

void stMailDetailProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, state);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, sendTime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, senderGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, senderName_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &senderName[0], senderName_arraylen);
    buffersize += senderName_arraylen;
    p += senderName_arraylen;
    leftsize-= senderName_arraylen;
  
    arraysize = leftsize;
    content.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = iconType_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * MAIL_MAX_ATTACH_FILE_COUNT > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<iconType_arraylen; ++i) {
        CProto::h2n_16(p, iconType[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = iconID_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * MAIL_MAX_ATTACH_FILE_COUNT > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<iconID_arraylen; ++i) {
        CProto::h2n_16(p, iconID[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
}

void stMailDetailProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    type = static_cast<eMailType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    state = static_cast<eMailState>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    sendTime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (8 > buffersize)
        throw DecodeError();
    senderGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&senderName, 0, sizeof(char)*MAX_NAME_LEN);
    senderName_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&senderName, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    senderName_arraylen = arraysize;
  
    arraysize = buffersize;
    content.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&iconType, 0, sizeof(eAttachType)*MAIL_MAX_ATTACH_FILE_COUNT);
    iconType_arraylen = 0;
    if (arraysize > MAIL_MAX_ATTACH_FILE_COUNT) {
       throw DecodeError();
    }
  
    if (2 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        iconType[i] = static_cast<eAttachType>(CProto::n2h_16(p));
        buffersize -= 2;
        p += 2;
    }
    iconType_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&iconID, 0, sizeof(short)*MAIL_MAX_ATTACH_FILE_COUNT);
    iconID_arraylen = 0;
    if (arraysize > MAIL_MAX_ATTACH_FILE_COUNT) {
       throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        iconID[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    iconID_arraylen = arraysize;
}

stMailDetailProto::stMailDetailProto()
{
    SetDefault();
}
void stMailDetailProto::SetDefault()
{
    senderName_arraylen = 0;
    iconType_arraylen = 0;
    iconID_arraylen = 0;

}


/* body */
void XJCMD_CSC_MAIL_LISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mailSystemDataList_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<mailSystemDataList_arraylen; ++i) {
        arraysize = leftsize;
        mailSystemDataList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mailFriendDataList_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<mailFriendDataList_arraylen; ++i) {
        arraysize = leftsize;
        mailFriendDataList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mailFull);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mailListType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_MAIL_LISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&mailSystemDataList, 0, sizeof(stMailSystemDataProto)*MAIL_MAX_SYSTEM_MAIL_COUNT);
    mailSystemDataList_arraylen = 0;
    if (arraysize > MAIL_MAX_SYSTEM_MAIL_COUNT) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        mailSystemDataList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    mailSystemDataList_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&mailFriendDataList, 0, sizeof(stMailFriendDataProto)*MAIL_MAX_FRIEND_MAIL_COUNT);
    mailFriendDataList_arraylen = 0;
    if (arraysize > MAIL_MAX_FRIEND_MAIL_COUNT) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        mailFriendDataList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    mailFriendDataList_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    mailFull = static_cast<eMailState>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    mailListType = static_cast<eMailState>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_MAIL_LISTSC::CommandID()
{
    return XJCMD_CSC_MAIL_LIST;
}
int XJCMD_CSC_MAIL_LISTSC::GetCommandID()
{
    return XJCMD_CSC_MAIL_LIST;
}

XJCMD_CSC_MAIL_LISTSC::XJCMD_CSC_MAIL_LISTSC()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_LISTSC::SetDefault()
{
    mailSystemDataList_arraylen = 0;
    mailFriendDataList_arraylen = 0;

}

void XJCMD_CSC_MAIL_DETAILCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_MAIL_DETAILCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_MAIL_DETAILCS::CommandID()
{
    return XJCMD_CSC_MAIL_DETAIL;
}
int XJCMD_CSC_MAIL_DETAILCS::GetCommandID()
{
    return XJCMD_CSC_MAIL_DETAIL;
}

XJCMD_CSC_MAIL_DETAILCS::XJCMD_CSC_MAIL_DETAILCS()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_DETAILCS::SetDefault()
{

}

void XJCMD_CSC_MAIL_DETAILSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    mailDetail.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_MAIL_DETAILSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    mailDetail.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_MAIL_DETAILSC::CommandID()
{
    return XJCMD_CSC_MAIL_DETAIL;
}
int XJCMD_CSC_MAIL_DETAILSC::GetCommandID()
{
    return XJCMD_CSC_MAIL_DETAIL;
}

XJCMD_CSC_MAIL_DETAILSC::XJCMD_CSC_MAIL_DETAILSC()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_DETAILSC::SetDefault()
{

}

void XJCMD_CSC_MAIL_SENDCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, reciverGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, reciverName_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &reciverName[0], reciverName_arraylen);
    buffersize += reciverName_arraylen;
    p += reciverName_arraylen;
    leftsize-= reciverName_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, title_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAIL_MAX_TITLE_LEN) 
        throw EncodeError();
    memcpy(p, &title[0], title_arraylen);
    buffersize += title_arraylen;
    p += title_arraylen;
    leftsize-= title_arraylen;
  
    arraysize = leftsize;
    content.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_MAIL_SENDCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    type = static_cast<eMailType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    reciverGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&reciverName, 0, sizeof(char)*MAX_NAME_LEN);
    reciverName_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&reciverName, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    reciverName_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&title, 0, sizeof(char)*MAIL_MAX_TITLE_LEN);
    title_arraylen = 0;
    if (arraysize > MAIL_MAX_TITLE_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&title, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    title_arraylen = arraysize;
  
    arraysize = buffersize;
    content.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_MAIL_SENDCS::CommandID()
{
    return XJCMD_CSC_MAIL_SEND;
}
int XJCMD_CSC_MAIL_SENDCS::GetCommandID()
{
    return XJCMD_CSC_MAIL_SEND;
}

XJCMD_CSC_MAIL_SENDCS::XJCMD_CSC_MAIL_SENDCS()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_SENDCS::SetDefault()
{
    reciverName_arraylen = 0;
    title_arraylen = 0;

}

void XJCMD_CSC_MAIL_SENDSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sendResult);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_MAIL_SENDSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    sendResult = static_cast<eMailOpRet>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_MAIL_SENDSC::CommandID()
{
    return XJCMD_CSC_MAIL_SEND;
}
int XJCMD_CSC_MAIL_SENDSC::GetCommandID()
{
    return XJCMD_CSC_MAIL_SEND;
}

XJCMD_CSC_MAIL_SENDSC::XJCMD_CSC_MAIL_SENDSC()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_SENDSC::SetDefault()
{

}

void XJCMD_CSC_MAIL_DELETECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, deleteType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_MAIL_DELETECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    deleteType = static_cast<eMailDeleteType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_MAIL_DELETECS::CommandID()
{
    return XJCMD_CSC_MAIL_DELETE;
}
int XJCMD_CSC_MAIL_DELETECS::GetCommandID()
{
    return XJCMD_CSC_MAIL_DELETE;
}

XJCMD_CSC_MAIL_DELETECS::XJCMD_CSC_MAIL_DELETECS()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_DELETECS::SetDefault()
{

}

void XJCMD_CSC_MAIL_DELETESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, deleteResult);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mailRemain_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 * MAIL_MAX_SYSTEM_MAIL_COUNT+MAIL_MAX_FRIEND_MAIL_COUNT > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<mailRemain_arraylen; ++i) {
        CProto::h2n_64(p, mailRemain[i]);
        buffersize += 8;
        p += 8;
        leftsize -= 8;
    }
}

void XJCMD_CSC_MAIL_DELETESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    deleteResult = static_cast<eMailOpRet>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&mailRemain, 0, sizeof(uint64_t)*MAIL_MAX_SYSTEM_MAIL_COUNT+MAIL_MAX_FRIEND_MAIL_COUNT);
    mailRemain_arraylen = 0;
    if (arraysize > MAIL_MAX_SYSTEM_MAIL_COUNT+MAIL_MAX_FRIEND_MAIL_COUNT) {
        throw DecodeError();
    }
  
    if (8 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        mailRemain[i] = CProto::n2h_64(p);
        buffersize -= 8;
        p += 8;
    }
    mailRemain_arraylen = arraysize;
}

int XJCMD_CSC_MAIL_DELETESC::CommandID()
{
    return XJCMD_CSC_MAIL_DELETE;
}
int XJCMD_CSC_MAIL_DELETESC::GetCommandID()
{
    return XJCMD_CSC_MAIL_DELETE;
}

XJCMD_CSC_MAIL_DELETESC::XJCMD_CSC_MAIL_DELETESC()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_DELETESC::SetDefault()
{
    mailRemain_arraylen = 0;

}

void XJCMD_CSC_MAIL_GET_ATTACHCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, mailGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_MAIL_GET_ATTACHCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    mailGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_MAIL_GET_ATTACHCS::CommandID()
{
    return XJCMD_CSC_MAIL_GET_ATTACH;
}
int XJCMD_CSC_MAIL_GET_ATTACHCS::GetCommandID()
{
    return XJCMD_CSC_MAIL_GET_ATTACH;
}

XJCMD_CSC_MAIL_GET_ATTACHCS::XJCMD_CSC_MAIL_GET_ATTACHCS()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_GET_ATTACHCS::SetDefault()
{

}

void XJCMD_CSC_MAIL_GET_ATTACHSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, getResult);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_MAIL_GET_ATTACHSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    getResult = static_cast<eMailOpRet>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_MAIL_GET_ATTACHSC::CommandID()
{
    return XJCMD_CSC_MAIL_GET_ATTACH;
}
int XJCMD_CSC_MAIL_GET_ATTACHSC::GetCommandID()
{
    return XJCMD_CSC_MAIL_GET_ATTACH;
}

XJCMD_CSC_MAIL_GET_ATTACHSC::XJCMD_CSC_MAIL_GET_ATTACHSC()
{
    SetDefault();
}
void XJCMD_CSC_MAIL_GET_ATTACHSC::SetDefault()
{

}

};

