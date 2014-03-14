
//#include "stdafx.h"


#include "ProtoFriend.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stFriendGeneral::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalLevel);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void stFriendGeneral::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    generalId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    generalLevel = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

stFriendGeneral::stFriendGeneral()
{
    SetDefault();
}
void stFriendGeneral::SetDefault()
{

}

void stFriendDataProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = portrait_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_URL_LEN) 
        throw EncodeError();
    memcpy(p, &portrait[0], portrait_arraylen);
    buffersize += portrait_arraylen;
    p += portrait_arraylen;
    leftsize-= portrait_arraylen;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = name_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_NAME_EX_LEN) 
        throw EncodeError();
    memcpy(p, &name[0], name_arraylen);
    buffersize += name_arraylen;
    p += name_arraylen;
    leftsize-= name_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, vipLevel);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, fightCap);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = present;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, faceId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, titleId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rankWorld);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, battleArray);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = generals_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<generals_arraylen; ++i) {
        arraysize = leftsize;
        generals[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void stFriendDataProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&portrait, 0, sizeof(char)*MAX_URL_LEN);
    portrait_arraylen = 0;
    if (arraysize > MAX_URL_LEN) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&portrait, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    portrait_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&name, 0, sizeof(char)*MAX_NAME_EX_LEN);
    name_arraylen = 0;
    if (arraysize > MAX_NAME_EX_LEN) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&name, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    name_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    vipLevel = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    fightCap = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    present = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    faceId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    titleId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    rankWorld = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    battleArray = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&generals, 0, sizeof(stFriendGeneral)*MAX_FRIEND_GENAL_NUM);
    generals_arraylen = 0;
    if (arraysize > MAX_FRIEND_GENAL_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        generals[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    generals_arraylen = arraysize;
}

stFriendDataProto::stFriendDataProto()
{
    SetDefault();
}
void stFriendDataProto::SetDefault()
{
    portrait_arraylen = 0;
    name_arraylen = 0;
    generals_arraylen = 0;

}

void stFriendEventDataProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, createtime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendEvent);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, eventParam);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void stFriendEventDataProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (4 > buffersize)
        throw DecodeError();
    createtime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    friendEvent = static_cast<eFriendEventType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    eventParam = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

stFriendEventDataProto::stFriendEventDataProto()
{
    SetDefault();
}
void stFriendEventDataProto::SetDefault()
{

}

void stFriendPresent::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = presentTime;
    ++buffersize;
    ++p;
    --leftsize;
}

void stFriendPresent::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
    if (1 > buffersize)
        throw DecodeError();
    presentTime = *p;
    --buffersize;
    ++p;
}

stFriendPresent::stFriendPresent()
{
    SetDefault();
}
void stFriendPresent::SetDefault()
{

}


/* body */
void XJCMD_CSC_FRIENDINFO_LISTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = clientRequest;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_FRIENDINFO_LISTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    clientRequest = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_FRIENDINFO_LISTCS::CommandID()
{
    return XJCMD_CSC_FRIENDINFO_LIST;
}
int XJCMD_CSC_FRIENDINFO_LISTCS::GetCommandID()
{
    return XJCMD_CSC_FRIENDINFO_LIST;
}

XJCMD_CSC_FRIENDINFO_LISTCS::XJCMD_CSC_FRIENDINFO_LISTCS()
{
    SetDefault();
}
void XJCMD_CSC_FRIENDINFO_LISTCS::SetDefault()
{

}

void XJCMD_CSC_FRIENDINFO_LISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = friendList_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<friendList_arraylen; ++i) {
        arraysize = leftsize;
        friendList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = friendNotice.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < friendNotice.size()) 
        throw EncodeError();
    memcpy(p,&friendNotice[0], friendNotice.size());
    buffersize += friendNotice.size();
    p += friendNotice.size();
    leftsize-= friendNotice.size();
}

void XJCMD_CSC_FRIENDINFO_LISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&friendList, 0, sizeof(stFriendDataProto)*MAX_FRIENDPROTO_NUM);
    friendList_arraylen = 0;
    if (arraysize > MAX_FRIENDPROTO_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        friendList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    friendList_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    friendNotice.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    friendNotice.resize(arraysize);
    memcpy(&friendNotice[0], p, arraysize*sizeof(char));
    friendNotice.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

int XJCMD_CSC_FRIENDINFO_LISTSC::CommandID()
{
    return XJCMD_CSC_FRIENDINFO_LIST;
}
int XJCMD_CSC_FRIENDINFO_LISTSC::GetCommandID()
{
    return XJCMD_CSC_FRIENDINFO_LIST;
}

XJCMD_CSC_FRIENDINFO_LISTSC::XJCMD_CSC_FRIENDINFO_LISTSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIENDINFO_LISTSC::SetDefault()
{
    friendList_arraylen = 0;
    friendNotice.clear();

}

void XJCMD_CSC_FRIENDEVENT_LISTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = clientRequest;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_FRIENDEVENT_LISTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    clientRequest = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_FRIENDEVENT_LISTCS::CommandID()
{
    return XJCMD_CSC_FRIENDEVENT_LIST;
}
int XJCMD_CSC_FRIENDEVENT_LISTCS::GetCommandID()
{
    return XJCMD_CSC_FRIENDEVENT_LIST;
}

XJCMD_CSC_FRIENDEVENT_LISTCS::XJCMD_CSC_FRIENDEVENT_LISTCS()
{
    SetDefault();
}
void XJCMD_CSC_FRIENDEVENT_LISTCS::SetDefault()
{

}

void XJCMD_CSC_FRIENDEVENT_LISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendEventList_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<friendEventList_arraylen; ++i) {
        arraysize = leftsize;
        friendEventList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_FRIENDEVENT_LISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&friendEventList, 0, sizeof(stFriendEventDataProto)*MAX_FRIEND_EVENT_NUM);
    friendEventList_arraylen = 0;
    if (arraysize > MAX_FRIEND_EVENT_NUM) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        friendEventList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    friendEventList_arraylen = arraysize;
}

int XJCMD_CSC_FRIENDEVENT_LISTSC::CommandID()
{
    return XJCMD_CSC_FRIENDEVENT_LIST;
}
int XJCMD_CSC_FRIENDEVENT_LISTSC::GetCommandID()
{
    return XJCMD_CSC_FRIENDEVENT_LIST;
}

XJCMD_CSC_FRIENDEVENT_LISTSC::XJCMD_CSC_FRIENDEVENT_LISTSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIENDEVENT_LISTSC::SetDefault()
{
    friendEventList_arraylen = 0;

}

void XJCMD_CSC_FRIEND_NEWCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = clientRequest;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_FRIEND_NEWCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    clientRequest = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_FRIEND_NEWCS::CommandID()
{
    return XJCMD_CSC_FRIEND_NEW;
}
int XJCMD_CSC_FRIEND_NEWCS::GetCommandID()
{
    return XJCMD_CSC_FRIEND_NEW;
}

XJCMD_CSC_FRIEND_NEWCS::XJCMD_CSC_FRIEND_NEWCS()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_NEWCS::SetDefault()
{

}

void XJCMD_CSC_FRIEND_NEWSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendNew_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<friendNew_arraylen; ++i) {
        arraysize = leftsize;
        friendNew[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_FRIEND_NEWSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&friendNew, 0, sizeof(stFriendDataProto)*MAX_FRIEND_REQUEST_NUM);
    friendNew_arraylen = 0;
    if (arraysize > MAX_FRIEND_REQUEST_NUM) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        friendNew[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    friendNew_arraylen = arraysize;
}

int XJCMD_CSC_FRIEND_NEWSC::CommandID()
{
    return XJCMD_CSC_FRIEND_NEW;
}
int XJCMD_CSC_FRIEND_NEWSC::GetCommandID()
{
    return XJCMD_CSC_FRIEND_NEW;
}

XJCMD_CSC_FRIEND_NEWSC::XJCMD_CSC_FRIEND_NEWSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_NEWSC::SetDefault()
{
    friendNew_arraylen = 0;

}

void XJCMD_CSC_FRIEND_OPCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, opType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_FRIEND_OPCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    opType = static_cast<eFriendOpType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_FRIEND_OPCS::CommandID()
{
    return XJCMD_CSC_FRIEND_OP;
}
int XJCMD_CSC_FRIEND_OPCS::GetCommandID()
{
    return XJCMD_CSC_FRIEND_OP;
}

XJCMD_CSC_FRIEND_OPCS::XJCMD_CSC_FRIEND_OPCS()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_OPCS::SetDefault()
{

}

void XJCMD_CSC_FRIEND_OPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, opType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = result;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_FRIEND_OPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    opType = static_cast<eFriendOpType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
    if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_FRIEND_OPSC::CommandID()
{
    return XJCMD_CSC_FRIEND_OP;
}
int XJCMD_CSC_FRIEND_OPSC::GetCommandID()
{
    return XJCMD_CSC_FRIEND_OP;
}

XJCMD_CSC_FRIEND_OPSC::XJCMD_CSC_FRIEND_OPSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_OPSC::SetDefault()
{

}

void XJCMD_CSC_FRIEND_PRESENTLISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendPresent_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<friendPresent_arraylen; ++i) {
        arraysize = leftsize;
        friendPresent[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, remainPresentTimes);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_FRIEND_PRESENTLISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&friendPresent, 0, sizeof(stFriendPresent)*MAX_FRIEND_PRESENT);
    friendPresent_arraylen = 0;
    if (arraysize > MAX_FRIEND_PRESENT) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        friendPresent[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    friendPresent_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    remainPresentTimes = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_FRIEND_PRESENTLISTSC::CommandID()
{
    return XJCMD_CSC_FRIEND_PRESENTLIST;
}
int XJCMD_CSC_FRIEND_PRESENTLISTSC::GetCommandID()
{
    return XJCMD_CSC_FRIEND_PRESENTLIST;
}

XJCMD_CSC_FRIEND_PRESENTLISTSC::XJCMD_CSC_FRIEND_PRESENTLISTSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_PRESENTLISTSC::SetDefault()
{
    friendPresent_arraylen = 0;

}

void XJCMD_CSC_FRIEND_GET_PRESENTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_FRIEND_GET_PRESENTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    type = static_cast<eFriendGetPresentType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_FRIEND_GET_PRESENTCS::CommandID()
{
    return XJCMD_CSC_FRIEND_GET_PRESENT;
}
int XJCMD_CSC_FRIEND_GET_PRESENTCS::GetCommandID()
{
    return XJCMD_CSC_FRIEND_GET_PRESENT;
}

XJCMD_CSC_FRIEND_GET_PRESENTCS::XJCMD_CSC_FRIEND_GET_PRESENTCS()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_GET_PRESENTCS::SetDefault()
{

}

void XJCMD_CSC_FRIEND_GET_PRESENTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGuid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = result;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, remainPresentTimes);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_FRIEND_GET_PRESENTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
    if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    remainPresentTimes = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_FRIEND_GET_PRESENTSC::CommandID()
{
    return XJCMD_CSC_FRIEND_GET_PRESENT;
}
int XJCMD_CSC_FRIEND_GET_PRESENTSC::GetCommandID()
{
    return XJCMD_CSC_FRIEND_GET_PRESENT;
}

XJCMD_CSC_FRIEND_GET_PRESENTSC::XJCMD_CSC_FRIEND_GET_PRESENTSC()
{
    SetDefault();
}
void XJCMD_CSC_FRIEND_GET_PRESENTSC::SetDefault()
{

}

};

