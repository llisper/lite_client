
//#include "stdafx.h"


#include "ProtoSenario.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stHideStage::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, stageId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, senarioType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, remainTime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void stHideStage::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    stageId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    senarioType = static_cast<eSenarioType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    remainTime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    generalId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

stHideStage::stHideStage()
{
    SetDefault();
}
void stHideStage::SetDefault()
{

}

void stSenarioData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = senarioId;
    ++buffersize;
    ++p;
    --leftsize;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = senarioState.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < senarioState.size()) 
        throw EncodeError();
    memcpy(p,&senarioState[0], senarioState.size());
    buffersize += senarioState.size();
    p += senarioState.size();
    leftsize-= senarioState.size();
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = senarioDrop.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * senarioDrop.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< senarioDrop.size(); ++i) {
        CProto::h2n_16(p, senarioDrop[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = stageInfo.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<stageInfo.size(); ++i) {
        arraysize = leftsize;
        stageInfo[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void stSenarioData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    senarioId = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    senarioState.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    senarioState.resize(arraysize);
    memcpy(&senarioState[0], p, arraysize*sizeof(char));
    senarioState.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    senarioDrop.clear();
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    senarioDrop.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        senarioDrop.push_back(CProto::n2h_16(p));
        buffersize-=2; p+=2;
    }
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    stageInfo.clear();
  
    stageInfo.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        stageInfo[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

stSenarioData::stSenarioData()
{
    SetDefault();
}
void stSenarioData::SetDefault()
{
    senarioState.clear();
    senarioDrop.clear();
    stageInfo.clear();

}


/* body */
void XJCMD_SC_SENARIO_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = version_db;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = bossEventNum;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = storyEventNum;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = dateEventNum;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = generalNew;
    ++buffersize;
    ++p;
    --leftsize;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = senarioData.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<senarioData.size(); ++i) {
        arraysize = leftsize;
        senarioData[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_SC_SENARIO_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    version_db = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    bossEventNum = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    storyEventNum = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    dateEventNum = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    generalNew = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    senarioData.clear();
  
    senarioData.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        senarioData[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_SC_SENARIO_SYNSC::CommandID()
{
    return XJCMD_SC_SENARIO_SYN;
}
int XJCMD_SC_SENARIO_SYNSC::GetCommandID()
{
    return XJCMD_SC_SENARIO_SYN;
}

XJCMD_SC_SENARIO_SYNSC::XJCMD_SC_SENARIO_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_SENARIO_SYNSC::SetDefault()
{
    senarioData.clear();

}

};

