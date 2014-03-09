
//#include "stdafx.h"


#include "ProtoSkill.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stSkillItemRatio::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, itemid);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, moneyType);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, money);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, ratio);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stSkillItemRatio::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    itemid = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    moneyType = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    money = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    ratio = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stSkillItemRatio::stSkillItemRatio()
{
    SetDefault();
}
void stSkillItemRatio::SetDefault()
{

}

void stSkillLevelData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, attrvalue);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, duration);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, creditsupper);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, sameskillratio);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = skillratio_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<skillratio_arraylen; ++i) {
        arraysize = leftsize;
        skillratio[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = itemratio_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<itemratio_arraylen; ++i) {
        arraysize = leftsize;
        itemratio[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, costmoneyvalue);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, attrvalue2);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stSkillLevelData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    attrvalue = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    duration = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    creditsupper = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    sameskillratio = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&skillratio, 0, sizeof(stSkillItemRatio)*PROTO_SKILLITEM_TYPE_NUM);
    skillratio_arraylen = 0;
    if (arraysize > PROTO_SKILLITEM_TYPE_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        skillratio[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    skillratio_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&itemratio, 0, sizeof(stSkillItemRatio)*PROTO_SKILL_SPECITEM_NUM);
    itemratio_arraylen = 0;
    if (arraysize > PROTO_SKILL_SPECITEM_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        itemratio[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    itemratio_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    costmoneyvalue = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    attrvalue2 = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stSkillLevelData::stSkillLevelData()
{
    SetDefault();
}
void stSkillLevelData::SetDefault()
{
    skillratio_arraylen = 0;
    itemratio_arraylen = 0;

}

void stSkill::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = level;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, battlearray_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    skillLeveData.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    arraysize = leftsize;
    skillLeveDataCurrent.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void stSkill::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    index = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    level = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    battlearray_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    skillLeveData.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    arraysize = buffersize;
    skillLeveDataCurrent.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

stSkill::stSkill()
{
    SetDefault();
}
void stSkill::SetDefault()
{

}


/* body */
void XJCMD_CSC_SKILL_DATASC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = skill_version;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = skills_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<skills_arraylen; ++i) {
        arraysize = leftsize;
        skills[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (leftsize == 0)
        throw EncodeError();
    *p = max_skillcount;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_SKILL_DATASC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    skill_version = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&skills, 0, sizeof(stSkill)*PROTO_SKILL_NUM);
    skills_arraylen = 0;
    if (arraysize > PROTO_SKILL_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        skills[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    skills_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    max_skillcount = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_SKILL_DATASC::CommandID()
{
    return XJCMD_CSC_SKILL_DATA;
}
int XJCMD_CSC_SKILL_DATASC::GetCommandID()
{
    return XJCMD_CSC_SKILL_DATA;
}

XJCMD_CSC_SKILL_DATASC::XJCMD_CSC_SKILL_DATASC()
{
    SetDefault();
}
void XJCMD_CSC_SKILL_DATASC::SetDefault()
{
    skills_arraylen = 0;

}

void XJCMD_CS_ASK_SKILL_LEVELUPCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, general_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, skill_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, cost_skill_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, cost_skill_item_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = cost_itemindex_arr_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_SKILL_SPECITEM_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<cost_itemindex_arr_arraylen; ++i) {
        CProto::h2n_32(p, cost_itemindex_arr[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
}

void XJCMD_CS_ASK_SKILL_LEVELUPCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    skill_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    cost_skill_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    cost_skill_item_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&cost_itemindex_arr, 0, sizeof(int)*PROTO_SKILL_SPECITEM_NUM);
    cost_itemindex_arr_arraylen = 0;
    if (arraysize > PROTO_SKILL_SPECITEM_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        cost_itemindex_arr[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    cost_itemindex_arr_arraylen = arraysize;
}

int XJCMD_CS_ASK_SKILL_LEVELUPCS::CommandID()
{
    return XJCMD_CS_ASK_SKILL_LEVELUP;
}
int XJCMD_CS_ASK_SKILL_LEVELUPCS::GetCommandID()
{
    return XJCMD_CS_ASK_SKILL_LEVELUP;
}

XJCMD_CS_ASK_SKILL_LEVELUPCS::XJCMD_CS_ASK_SKILL_LEVELUPCS()
{
    SetDefault();
}
void XJCMD_CS_ASK_SKILL_LEVELUPCS::SetDefault()
{
    cost_itemindex_arr_arraylen = 0;

}

void XJCMD_SC_RET_SKILL_LEVELUPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, skill_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = result;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_SC_RET_SKILL_LEVELUPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    skill_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
}

int XJCMD_SC_RET_SKILL_LEVELUPSC::CommandID()
{
    return XJCMD_SC_RET_SKILL_LEVELUP;
}
int XJCMD_SC_RET_SKILL_LEVELUPSC::GetCommandID()
{
    return XJCMD_SC_RET_SKILL_LEVELUP;
}

XJCMD_SC_RET_SKILL_LEVELUPSC::XJCMD_SC_RET_SKILL_LEVELUPSC()
{
    SetDefault();
}
void XJCMD_SC_RET_SKILL_LEVELUPSC::SetDefault()
{

}

void XJCMD_CS_SKILL_ONCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, battlearray_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, skill_index);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CS_SKILL_ONCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    battlearray_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    skill_index = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CS_SKILL_ONCS::CommandID()
{
    return XJCMD_CS_SKILL_ON;
}
int XJCMD_CS_SKILL_ONCS::GetCommandID()
{
    return XJCMD_CS_SKILL_ON;
}

XJCMD_CS_SKILL_ONCS::XJCMD_CS_SKILL_ONCS()
{
    SetDefault();
}
void XJCMD_CS_SKILL_ONCS::SetDefault()
{

}

};

