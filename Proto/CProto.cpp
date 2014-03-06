
//#include "stdafx.h"


#include "CProto.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void LevelUpRelated::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = exp_rate_before;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = exp_rate_after;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level_before);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = level_delta;
    ++buffersize;
    ++p;
    --leftsize;
}

void LevelUpRelated::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    exp_rate_before = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    exp_rate_after = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    level_before = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    level_delta = *p;
    --buffersize;
    ++p;
}

LevelUpRelated::LevelUpRelated()
{
    SetDefault();
}
void LevelUpRelated::SetDefault()
{

}

void BattleReslutGeneral::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    generalLevelRelated.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, assistantIndex);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    assistantLevelRelated.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void BattleReslutGeneral::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    generalLevelRelated.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    assistantIndex = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    assistantLevelRelated.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

BattleReslutGeneral::BattleReslutGeneral()
{
    SetDefault();
}
void BattleReslutGeneral::SetDefault()
{

}

void DropItem::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, awardtype);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, conIndex);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = count;
    ++buffersize;
    ++p;
    --leftsize;
}

void DropItem::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    awardtype = static_cast<eRewardType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    conIndex = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    count = *p;
    --buffersize;
    ++p;
}

DropItem::DropItem()
{
    SetDefault();
}
void DropItem::SetDefault()
{

}

void ButtonItem::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (1 > leftsize)
        throw EncodeError();
    *p = param_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * MAX_BUTTON_PARAM_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<param_arraylen; ++i) {
        CProto::h2n_32(p, param[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
}

void ButtonItem::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&param, 0, sizeof(int)*MAX_BUTTON_PARAM_NUM);
    param_arraylen = 0;
    if (arraysize > MAX_BUTTON_PARAM_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        param[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    param_arraylen = arraysize;
}

ButtonItem::ButtonItem()
{
    SetDefault();
}
void ButtonItem::SetDefault()
{
    param_arraylen = 0;

}

void ScoreRankItem::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = rankId;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, portraitId);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = name_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &name[0], name_arraylen);
    buffersize += name_arraylen;
    p += name_arraylen;
    leftsize-= name_arraylen;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, sore);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void ScoreRankItem::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    rankId = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    portraitId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&name, 0, sizeof(char)*MAX_NAME_LEN);
    name_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&name, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    name_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    sore = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

ScoreRankItem::ScoreRankItem()
{
    SetDefault();
}
void ScoreRankItem::SetDefault()
{
    name_arraylen = 0;

}

void stQhtml::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
        if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, value.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < value.size()) 
        throw EncodeError();
    memcpy(p,&value[0], value.size());
    buffersize += value.size();
    p += value.size();
    leftsize-= value.size();
}

void stQhtml::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    value.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    value.resize(arraysize);
    memcpy(&value[0], p, arraysize*sizeof(char));
    value.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

stQhtml::stQhtml()
{
    SetDefault();
}
void stQhtml::SetDefault()
{
    value.clear();

}


/* body */
};

