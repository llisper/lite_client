
//#include "stdafx.h"


#include "ProtoGeneralTravel.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stGeneralDataProto::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendGeneralID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasFate;
    ++buffersize;
    ++p;
    --leftsize;
}

void stGeneralDataProto::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    friendGuid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    friendGeneralID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    hasFate = *p;
    --buffersize;
    ++p;
}

stGeneralDataProto::stGeneralDataProto()
{
    SetDefault();
}
void stGeneralDataProto::SetDefault()
{

}


/* body */
void XJCMD_CSC_GENERALTRAVEL_DETAILCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = detailRequest;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_GENERALTRAVEL_DETAILCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    detailRequest = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_GENERALTRAVEL_DETAILCS::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_DETAIL;
}
int XJCMD_CSC_GENERALTRAVEL_DETAILCS::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_DETAIL;
}

XJCMD_CSC_GENERALTRAVEL_DETAILCS::XJCMD_CSC_GENERALTRAVEL_DETAILCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_DETAILCS::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_DETAILSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, travelState);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = travelTimes;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = travelTimeMAX;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, remainTime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGUID);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendGeneralID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasFate;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_GENERALTRAVEL_DETAILSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    travelState = static_cast<eStateDetailType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    travelTimes = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    travelTimeMAX = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    remainTime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    generalID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    friendGUID = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    friendGeneralID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    hasFate = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_GENERALTRAVEL_DETAILSC::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_DETAIL;
}
int XJCMD_CSC_GENERALTRAVEL_DETAILSC::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_DETAIL;
}

XJCMD_CSC_GENERALTRAVEL_DETAILSC::XJCMD_CSC_GENERALTRAVEL_DETAILSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_DETAILSC::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, monyeType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    monyeType = static_cast<eMoneyType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_USEMONEY;
}
int XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_USEMONEY;
}

XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::XJCMD_CSC_GENERALTRAVEL_USEMONEYCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_USEMONEYCS::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, useRet);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, monyeType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    useRet = static_cast<eStateRetType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    monyeType = static_cast<eMoneyType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_USEMONEY;
}
int XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_USEMONEY;
}

XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::XJCMD_CSC_GENERALTRAVEL_USEMONEYSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_USEMONEYSC::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_BEGINCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, friendGUID);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, friendGeneralID);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERALTRAVEL_BEGINCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    generalID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    friendGUID = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    friendGeneralID = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERALTRAVEL_BEGINCS::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_BEGIN;
}
int XJCMD_CSC_GENERALTRAVEL_BEGINCS::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_BEGIN;
}

XJCMD_CSC_GENERALTRAVEL_BEGINCS::XJCMD_CSC_GENERALTRAVEL_BEGINCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_BEGINCS::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_BEGINSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, travellingState);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, remainTime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = hasFate;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_GENERALTRAVEL_BEGINSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    travellingState = static_cast<eStateRetType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    remainTime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    hasFate = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_GENERALTRAVEL_BEGINSC::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_BEGIN;
}
int XJCMD_CSC_GENERALTRAVEL_BEGINSC::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_BEGIN;
}

XJCMD_CSC_GENERALTRAVEL_BEGINSC::XJCMD_CSC_GENERALTRAVEL_BEGINSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_BEGINSC::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_GETREWARD;
}
int XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_GETREWARD;
}

XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::XJCMD_CSC_GENERALTRAVEL_GETREWARDCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_GETREWARDCS::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = travelPlace;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, getRet);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    travelPlace = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    getRet = static_cast<eStateRetType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_GETREWARD;
}
int XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_GETREWARD;
}

XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::XJCMD_CSC_GENERALTRAVEL_GETREWARDSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_GETREWARDSC::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_FATELISTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalIDOwn);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERALTRAVEL_FATELISTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    generalIDOwn = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERALTRAVEL_FATELISTCS::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_FATELIST;
}
int XJCMD_CSC_GENERALTRAVEL_FATELISTCS::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_FATELIST;
}

XJCMD_CSC_GENERALTRAVEL_FATELISTCS::XJCMD_CSC_GENERALTRAVEL_FATELISTCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_FATELISTCS::SetDefault()
{

}

void XJCMD_CSC_GENERALTRAVEL_FATELISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalIDOwn);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = friendFateList_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<friendFateList_arraylen; ++i) {
        arraysize = leftsize;
        friendFateList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_GENERALTRAVEL_FATELISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    generalIDOwn = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&friendFateList, 0, sizeof(stGeneralDataProto)*50);
    friendFateList_arraylen = 0;
    if (arraysize > 50) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        friendFateList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    friendFateList_arraylen = arraysize;
}

int XJCMD_CSC_GENERALTRAVEL_FATELISTSC::CommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_FATELIST;
}
int XJCMD_CSC_GENERALTRAVEL_FATELISTSC::GetCommandID()
{
    return XJCMD_CSC_GENERALTRAVEL_FATELIST;
}

XJCMD_CSC_GENERALTRAVEL_FATELISTSC::XJCMD_CSC_GENERALTRAVEL_FATELISTSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERALTRAVEL_FATELISTSC::SetDefault()
{
    friendFateList_arraylen = 0;

}

};

