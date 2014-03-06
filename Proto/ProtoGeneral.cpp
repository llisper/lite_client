
//#include "stdafx.h"


#include "ProtoGeneral.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stGeneralFateAddition::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    name.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    arraysize = leftsize;
    desc.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = isopen;
    ++buffersize;
    ++p;
    --leftsize;
}

void stGeneralFateAddition::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    name.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    arraysize = buffersize;
    desc.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    isopen = *p;
    --buffersize;
    ++p;
}

stGeneralFateAddition::stGeneralFateAddition()
{
    SetDefault();
}
void stGeneralFateAddition::SetDefault()
{

}

void stSkillEx::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
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
  
    arraysize = leftsize;
    skillLeveData.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void stSkillEx::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
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
  
    arraysize = buffersize;
    skillLeveData.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

stSkillEx::stSkillEx()
{
    SetDefault();
}
void stSkillEx::SetDefault()
{

}

void stGeneralData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = star;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = practice_level;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = practice_growth_value;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, m_consumed_souls_in_practice);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, m_consumed_item_num_in_practice);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = base_attr_basic_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_BASIC_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<base_attr_basic_arraylen; ++i) {
        CProto::h2n_32(p, base_attr_basic[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = attr_basic_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_BASIC_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<attr_basic_arraylen; ++i) {
        CProto::h2n_32(p, attr_basic[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = attr_element_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_ELEMENT_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<attr_element_arraylen; ++i) {
        CProto::h2n_32(p, attr_element[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = attr_spec_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_SPEC_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<attr_spec_arraylen; ++i) {
        CProto::h2n_32(p, attr_spec[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    arraysize = leftsize;
    defaul_skill.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    arraysize = leftsize;
    assist_skill.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = fate_fix_flag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_GENERAL_FATE_FIX_NUM) 
        throw EncodeError();
    memcpy(p, &fate_fix_flag[0], fate_fix_flag_arraylen);
    buffersize += fate_fix_flag_arraylen;
    p += fate_fix_flag_arraylen;
    leftsize-= fate_fix_flag_arraylen;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fate_addition.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<fate_addition.size(); ++i) {
        arraysize = leftsize;
        fate_addition[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, combat_power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, maxexp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, kungfu_points);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, consumed_pills_in_training);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stGeneralData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    star = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    practice_level = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    practice_growth_value = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    m_consumed_souls_in_practice = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    m_consumed_item_num_in_practice = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&base_attr_basic, 0, sizeof(int)*PROTO_GENERAL_FIGHT_BASIC_NUM);
    base_attr_basic_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_BASIC_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        base_attr_basic[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    base_attr_basic_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&attr_basic, 0, sizeof(int)*PROTO_GENERAL_FIGHT_BASIC_NUM);
    attr_basic_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_BASIC_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        attr_basic[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    attr_basic_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&attr_element, 0, sizeof(int)*PROTO_GENERAL_FIGHT_ELEMENT_NUM);
    attr_element_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_ELEMENT_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        attr_element[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    attr_element_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&attr_spec, 0, sizeof(int)*PROTO_GENERAL_FIGHT_SPEC_NUM);
    attr_spec_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_SPEC_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        attr_spec[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    attr_spec_arraylen = arraysize;
  
    arraysize = buffersize;
    defaul_skill.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    arraysize = buffersize;
    assist_skill.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&fate_fix_flag, 0, sizeof(unsigned char)*MAX_GENERAL_FATE_FIX_NUM);
    fate_fix_flag_arraylen = 0;
    if (arraysize > MAX_GENERAL_FATE_FIX_NUM) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&fate_fix_flag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    fate_fix_flag_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fate_addition.clear();
  
    fate_addition.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        fate_addition[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (4 > buffersize)
        throw DecodeError();
    combat_power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    maxexp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    kungfu_points = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    consumed_pills_in_training = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stGeneralData::stGeneralData()
{
    SetDefault();
}
void stGeneralData::SetDefault()
{
    base_attr_basic_arraylen = 0;
    attr_basic_arraylen = 0;
    attr_element_arraylen = 0;
    attr_spec_arraylen = 0;
    fate_fix_flag_arraylen = 0;
    fate_addition.clear();

}

void stLostGeneralData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void stLostGeneralData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

stLostGeneralData::stLostGeneralData()
{
    SetDefault();
}
void stLostGeneralData::SetDefault()
{

}

void stGeneralSoulData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = soulnum;
    ++buffersize;
    ++p;
    --leftsize;
}

void stGeneralSoulData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    soulnum = *p;
    --buffersize;
    ++p;
}

stGeneralSoulData::stGeneralSoulData()
{
    SetDefault();
}
void stGeneralSoulData::SetDefault()
{

}

void stBattleArrayEquip::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void stBattleArrayEquip::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

stBattleArrayEquip::stBattleArrayEquip()
{
    SetDefault();
}
void stBattleArrayEquip::SetDefault()
{

}

void stBattleArrayGeneral::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, assist_container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, skill_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = fightgeneral_equip_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<fightgeneral_equip_arraylen; ++i) {
        arraysize = leftsize;
        fightgeneral_equip[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = assistgeneral_equip_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<assistgeneral_equip_arraylen; ++i) {
        arraysize = leftsize;
        assistgeneral_equip[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void stBattleArrayGeneral::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    assist_container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    skill_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&fightgeneral_equip, 0, sizeof(stBattleArrayEquip)*MAX_GENERAL_EQUIP_NUM);
    fightgeneral_equip_arraylen = 0;
    if (arraysize > MAX_GENERAL_EQUIP_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        fightgeneral_equip[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    fightgeneral_equip_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&assistgeneral_equip, 0, sizeof(stBattleArrayEquip)*MAX_GENERAL_EQUIP_NUM);
    assistgeneral_equip_arraylen = 0;
    if (arraysize > MAX_GENERAL_EQUIP_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        assistgeneral_equip[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    assistgeneral_equip_arraylen = arraysize;
}

stBattleArrayGeneral::stBattleArrayGeneral()
{
    SetDefault();
}
void stBattleArrayGeneral::SetDefault()
{
    fightgeneral_equip_arraylen = 0;
    assistgeneral_equip_arraylen = 0;

}

void stBattleArray::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = battlearray_general_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<battlearray_general_arraylen; ++i) {
        arraysize = leftsize;
        battlearray_general[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void stBattleArray::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&battlearray_general, 0, sizeof(stBattleArrayGeneral)*MAX_BATTLEARRAY_GENERAL_NUM);
    battlearray_general_arraylen = 0;
    if (arraysize > MAX_BATTLEARRAY_GENERAL_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        battlearray_general[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    battlearray_general_arraylen = arraysize;
}

stBattleArray::stBattleArray()
{
    SetDefault();
}
void stBattleArray::SetDefault()
{
    battlearray_general_arraylen = 0;

}

void st10DrawResult::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = souls;
    ++buffersize;
    ++p;
    --leftsize;
}

void st10DrawResult::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    general_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    souls = *p;
    --buffersize;
    ++p;
}

st10DrawResult::st10DrawResult()
{
    SetDefault();
}
void st10DrawResult::SetDefault()
{

}


/* body */
void XJCMD_SC_USERGENERAL_FULLDATASC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    *p = version_db_res;
    ++buffersize;
    ++p;
    --leftsize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, generals.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<generals.size(); ++i) {
        arraysize = leftsize;
        generals[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, generalsouls.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < generalsouls.size()) 
        throw EncodeError();
    memcpy(p,&generalsouls[0], generalsouls.size());
    buffersize += generalsouls.size();
    p += generalsouls.size();
    leftsize-= generalsouls.size();
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, lostgenerals.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<lostgenerals.size(); ++i) {
        arraysize = leftsize;
        lostgenerals[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_SC_USERGENERAL_FULLDATASC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    version_db_res = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    generals.clear();
  
    generals.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        generals[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    generalsouls.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    generalsouls.resize(arraysize);
    memcpy(&generalsouls[0], p, arraysize*sizeof(char));
    generalsouls.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    lostgenerals.clear();
  
    lostgenerals.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        lostgenerals[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_SC_USERGENERAL_FULLDATASC::CommandID()
{
    return XJCMD_SC_USERGENERAL_FULLDATA;
}
int XJCMD_SC_USERGENERAL_FULLDATASC::GetCommandID()
{
    return XJCMD_SC_USERGENERAL_FULLDATA;
}

XJCMD_SC_USERGENERAL_FULLDATASC::XJCMD_SC_USERGENERAL_FULLDATASC()
{
    SetDefault();
}
void XJCMD_SC_USERGENERAL_FULLDATASC::SetDefault()
{
    generals.clear();
    generalsouls.clear();
    lostgenerals.clear();

}

void XJCMD_SC_USERGENERAL_BATTLEARRAYSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    arraysize = leftsize;
    battlearray.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = battlearray_id;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = battlemapIdArray_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_BATTLEMAP_NUM) 
        throw EncodeError();
    memcpy(p, &battlemapIdArray[0], battlemapIdArray_arraylen);
    buffersize += battlemapIdArray_arraylen;
    p += battlemapIdArray_arraylen;
    leftsize-= battlemapIdArray_arraylen;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = attr_assit_level;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = attr_ratio;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_SC_USERGENERAL_BATTLEARRAYSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    version_db = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    battlearray.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    battlearray_id = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&battlemapIdArray, 0, sizeof(unsigned char)*MAX_BATTLEMAP_NUM);
    battlemapIdArray_arraylen = 0;
    if (arraysize > MAX_BATTLEMAP_NUM) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&battlemapIdArray, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    battlemapIdArray_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    attr_assit_level = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    attr_ratio = *p;
    --buffersize;
    ++p;
}

int XJCMD_SC_USERGENERAL_BATTLEARRAYSC::CommandID()
{
    return XJCMD_SC_USERGENERAL_BATTLEARRAY;
}
int XJCMD_SC_USERGENERAL_BATTLEARRAYSC::GetCommandID()
{
    return XJCMD_SC_USERGENERAL_BATTLEARRAY;
}

XJCMD_SC_USERGENERAL_BATTLEARRAYSC::XJCMD_SC_USERGENERAL_BATTLEARRAYSC()
{
    SetDefault();
}
void XJCMD_SC_USERGENERAL_BATTLEARRAYSC::SetDefault()
{
    battlemapIdArray_arraylen = 0;

}

void XJCMD_SC_USERGENERAL_RES_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, general_version_res);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = general_full_flag;
    ++buffersize;
    ++p;
    --leftsize;
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, general_resdata.size());
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < general_resdata.size()) 
        throw EncodeError();
    memcpy(p,&general_resdata[0], general_resdata.size());
    buffersize += general_resdata.size();
    p += general_resdata.size();
    leftsize-= general_resdata.size();
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, battlemap_version_res);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = battlemap_full_flag;
    ++buffersize;
    ++p;
    --leftsize;
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, battlemap_resdata.size());
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < battlemap_resdata.size()) 
        throw EncodeError();
    memcpy(p,&battlemap_resdata[0], battlemap_resdata.size());
    buffersize += battlemap_resdata.size();
    p += battlemap_resdata.size();
    leftsize-= battlemap_resdata.size();
}

void XJCMD_SC_USERGENERAL_RES_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    general_version_res = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    general_full_flag = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    general_resdata.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    general_resdata.resize(arraysize);
    memcpy(&general_resdata[0], p, arraysize*sizeof(char));
    general_resdata.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    battlemap_version_res = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    battlemap_full_flag = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    battlemap_resdata.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    battlemap_resdata.resize(arraysize);
    memcpy(&battlemap_resdata[0], p, arraysize*sizeof(char));
    battlemap_resdata.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

int XJCMD_SC_USERGENERAL_RES_SYNSC::CommandID()
{
    return XJCMD_SC_USERGENERAL_RES_SYN;
}
int XJCMD_SC_USERGENERAL_RES_SYNSC::GetCommandID()
{
    return XJCMD_SC_USERGENERAL_RES_SYN;
}

XJCMD_SC_USERGENERAL_RES_SYNSC::XJCMD_SC_USERGENERAL_RES_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_USERGENERAL_RES_SYNSC::SetDefault()
{
    general_resdata.clear();
    battlemap_resdata.clear();

}

void XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = pos;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    pos = *p;
    --buffersize;
    ++p;
}

int XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::CommandID()
{
    return XJCMD_CS_BATTLEARR_ASSITPOS_OPEN;
}
int XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::GetCommandID()
{
    return XJCMD_CS_BATTLEARR_ASSITPOS_OPEN;
}

XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS()
{
    SetDefault();
}
void XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS::SetDefault()
{

}

void XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    battlearray.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = battlearray_id;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    battlearray.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    battlearray_id = *p;
    --buffersize;
    ++p;
}

int XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::CommandID()
{
    return XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE;
}
int XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::GetCommandID()
{
    return XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE;
}

XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS()
{
    SetDefault();
}
void XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS::SetDefault()
{

}

void XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = result;
    ++buffersize;
    ++p;
    --leftsize;

	if (result==1) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = version_db;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;

	if (result==1) {    if (1 > buffersize)
        throw DecodeError();
    version_db = *p;
    --buffersize;
    ++p;
	}
}

int XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::CommandID()
{
    return XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET;
}
int XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::GetCommandID()
{
    return XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET;
}

XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC()
{
    SetDefault();
}
void XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC::SetDefault()
{

}

void XJCMD_CSC_SUMMON_GENERALCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_SUMMON_GENERALCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_SUMMON_GENERALCS::CommandID()
{
    return XJCMD_CSC_SUMMON_GENERAL;
}
int XJCMD_CSC_SUMMON_GENERALCS::GetCommandID()
{
    return XJCMD_CSC_SUMMON_GENERAL;
}

XJCMD_CSC_SUMMON_GENERALCS::XJCMD_CSC_SUMMON_GENERALCS()
{
    SetDefault();
}
void XJCMD_CSC_SUMMON_GENERALCS::SetDefault()
{

}

void XJCMD_CSC_SUMMON_GENERALSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = ret;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    msg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_SUMMON_GENERALSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    ret = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    msg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_SUMMON_GENERALSC::CommandID()
{
    return XJCMD_CSC_SUMMON_GENERAL;
}
int XJCMD_CSC_SUMMON_GENERALSC::GetCommandID()
{
    return XJCMD_CSC_SUMMON_GENERAL;
}

XJCMD_CSC_SUMMON_GENERALSC::XJCMD_CSC_SUMMON_GENERALSC()
{
    SetDefault();
}
void XJCMD_CSC_SUMMON_GENERALSC::SetDefault()
{

}

void XJCMD_CSC_GENERAL_PRACTICECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERAL_PRACTICECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERAL_PRACTICECS::CommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE;
}
int XJCMD_CSC_GENERAL_PRACTICECS::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE;
}

XJCMD_CSC_GENERAL_PRACTICECS::XJCMD_CSC_GENERAL_PRACTICECS()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRACTICECS::SetDefault()
{

}

void XJCMD_CSC_GENERAL_PRACTICESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (retcode == Practice_GOOD) {  
    if (1 > leftsize)
        throw EncodeError();
    *p = base_attr_basic_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_BASIC_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<base_attr_basic_arraylen; ++i) {
        CProto::h2n_32(p, base_attr_basic[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
	}
}

void XJCMD_CSC_GENERAL_PRACTICESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<PracticeECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

	if (retcode == Practice_GOOD) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&base_attr_basic, 0, sizeof(int)*PROTO_GENERAL_FIGHT_BASIC_NUM);
    base_attr_basic_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_BASIC_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        base_attr_basic[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    base_attr_basic_arraylen = arraysize;
	}
}

int XJCMD_CSC_GENERAL_PRACTICESC::CommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE;
}
int XJCMD_CSC_GENERAL_PRACTICESC::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE;
}

XJCMD_CSC_GENERAL_PRACTICESC::XJCMD_CSC_GENERAL_PRACTICESC()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRACTICESC::SetDefault()
{
    base_attr_basic_arraylen = 0;

}

void XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::CommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE_REBUILD;
}
int XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE_REBUILD;
}

XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS::SetDefault()
{

}

void XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (retcode == Practice_GOOD) {  
    if (1 > leftsize)
        throw EncodeError();
    *p = base_attr_basic_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * PROTO_GENERAL_FIGHT_BASIC_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<base_attr_basic_arraylen; ++i) {
        CProto::h2n_32(p, base_attr_basic[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
	}
}

void XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<PracticeECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

	if (retcode == Practice_GOOD) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&base_attr_basic, 0, sizeof(int)*PROTO_GENERAL_FIGHT_BASIC_NUM);
    base_attr_basic_arraylen = 0;
    if (arraysize > PROTO_GENERAL_FIGHT_BASIC_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        base_attr_basic[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    base_attr_basic_arraylen = arraysize;
	}
}

int XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::CommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE_REBUILD;
}
int XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRACTICE_REBUILD;
}

XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC::SetDefault()
{
    base_attr_basic_arraylen = 0;

}

void XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, container_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, fate_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, target_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    container_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    fate_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    target_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::CommandID()
{
    return XJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
}
int XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::GetCommandID()
{
    return XJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
}

XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS::SetDefault()
{

}

void XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    desc.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    desc.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::CommandID()
{
    return XJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
}
int XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::GetCommandID()
{
    return XJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
}

XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC::SetDefault()
{

}

void XJCMD_CSC_TRAININGCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = count;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_TRAININGCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    count = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_TRAININGCS::CommandID()
{
    return XJCMD_CSC_TRAINING;
}
int XJCMD_CSC_TRAININGCS::GetCommandID()
{
    return XJCMD_CSC_TRAINING;
}

XJCMD_CSC_TRAININGCS::XJCMD_CSC_TRAININGCS()
{
    SetDefault();
}
void XJCMD_CSC_TRAININGCS::SetDefault()
{

}

void XJCMD_CSC_TRAININGSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (retcode == CProto::Training_GOOD) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, serial_number);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = attr_plus_type;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, attr_plus_val);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = attr_minus_type;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, attr_minus_val);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, kungfu_points_consumed);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}
}

void XJCMD_CSC_TRAININGSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<TrainingECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

	if (retcode == CProto::Training_GOOD) {  
    if (2 > buffersize)
        throw DecodeError();
    serial_number = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (retcode == CProto::Training_GOOD) {    if (1 > buffersize)
        throw DecodeError();
    attr_plus_type = *p;
    --buffersize;
    ++p;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > buffersize)
        throw DecodeError();
    attr_plus_val = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (retcode == CProto::Training_GOOD) {    if (1 > buffersize)
        throw DecodeError();
    attr_minus_type = *p;
    --buffersize;
    ++p;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > buffersize)
        throw DecodeError();
    attr_minus_val = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (retcode == CProto::Training_GOOD) {  
    if (2 > buffersize)
        throw DecodeError();
    kungfu_points_consumed = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}
}

int XJCMD_CSC_TRAININGSC::CommandID()
{
    return XJCMD_CSC_TRAINING;
}
int XJCMD_CSC_TRAININGSC::GetCommandID()
{
    return XJCMD_CSC_TRAINING;
}

XJCMD_CSC_TRAININGSC::XJCMD_CSC_TRAININGSC()
{
    SetDefault();
}
void XJCMD_CSC_TRAININGSC::SetDefault()
{

}

void XJCMD_CSC_TRAINING_CONFIRMCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, serial_number);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = just_do_it;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_TRAINING_CONFIRMCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    serial_number = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    just_do_it = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_TRAINING_CONFIRMCS::CommandID()
{
    return XJCMD_CSC_TRAINING_CONFIRM;
}
int XJCMD_CSC_TRAINING_CONFIRMCS::GetCommandID()
{
    return XJCMD_CSC_TRAINING_CONFIRM;
}

XJCMD_CSC_TRAINING_CONFIRMCS::XJCMD_CSC_TRAINING_CONFIRMCS()
{
    SetDefault();
}
void XJCMD_CSC_TRAINING_CONFIRMCS::SetDefault()
{

}

void XJCMD_CSC_TRAINING_CONFIRMSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, serial_number);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_TRAINING_CONFIRMSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<TrainingECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    serial_number = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_TRAINING_CONFIRMSC::CommandID()
{
    return XJCMD_CSC_TRAINING_CONFIRM;
}
int XJCMD_CSC_TRAINING_CONFIRMSC::GetCommandID()
{
    return XJCMD_CSC_TRAINING_CONFIRM;
}

XJCMD_CSC_TRAINING_CONFIRMSC::XJCMD_CSC_TRAINING_CONFIRMSC()
{
    SetDefault();
}
void XJCMD_CSC_TRAINING_CONFIRMSC::SetDefault()
{

}

void XJCMD_CSC_KUNGFU_TRANSMITCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, transmitter_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, transmittee_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, transmit_type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_KUNGFU_TRANSMITCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    transmitter_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    transmittee_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    transmit_type = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_KUNGFU_TRANSMITCS::CommandID()
{
    return XJCMD_CSC_KUNGFU_TRANSMIT;
}
int XJCMD_CSC_KUNGFU_TRANSMITCS::GetCommandID()
{
    return XJCMD_CSC_KUNGFU_TRANSMIT;
}

XJCMD_CSC_KUNGFU_TRANSMITCS::XJCMD_CSC_KUNGFU_TRANSMITCS()
{
    SetDefault();
}
void XJCMD_CSC_KUNGFU_TRANSMITCS::SetDefault()
{

}

void XJCMD_CSC_KUNGFU_TRANSMITSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (retcode == CProto::KFT_GOOD || retcode == CProto::KFT_RETURN_STUFF_ERROR) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, transmittee_levels_changed);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (retcode == CProto::KFT_GOOD || retcode == CProto::KFT_RETURN_STUFF_ERROR) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp_to_transmittee);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}
}

void XJCMD_CSC_KUNGFU_TRANSMITSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<KungfuTransmitECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;

	if (retcode == CProto::KFT_GOOD || retcode == CProto::KFT_RETURN_STUFF_ERROR) {  
    if (4 > buffersize)
        throw DecodeError();
    transmittee_levels_changed = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (retcode == CProto::KFT_GOOD || retcode == CProto::KFT_RETURN_STUFF_ERROR) {  
    if (4 > buffersize)
        throw DecodeError();
    exp_to_transmittee = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}
}

int XJCMD_CSC_KUNGFU_TRANSMITSC::CommandID()
{
    return XJCMD_CSC_KUNGFU_TRANSMIT;
}
int XJCMD_CSC_KUNGFU_TRANSMITSC::GetCommandID()
{
    return XJCMD_CSC_KUNGFU_TRANSMIT;
}

XJCMD_CSC_KUNGFU_TRANSMITSC::XJCMD_CSC_KUNGFU_TRANSMITSC()
{
    SetDefault();
}
void XJCMD_CSC_KUNGFU_TRANSMITSC::SetDefault()
{

}

void XJCMD_CSC_CARDLOTTERY_DRAWCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, lottery_type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_CARDLOTTERY_DRAWCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    lottery_type = static_cast<CardLotteryType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_CARDLOTTERY_DRAWCS::CommandID()
{
    return XJCMD_CSC_CARDLOTTERY_DRAW;
}
int XJCMD_CSC_CARDLOTTERY_DRAWCS::GetCommandID()
{
    return XJCMD_CSC_CARDLOTTERY_DRAW;
}

XJCMD_CSC_CARDLOTTERY_DRAWCS::XJCMD_CSC_CARDLOTTERY_DRAWCS()
{
    SetDefault();
}
void XJCMD_CSC_CARDLOTTERY_DRAWCS::SetDefault()
{

}

void XJCMD_CSC_CARDLOTTERY_DRAWSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = souls;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = times_to_get_top_card;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_CARDLOTTERY_DRAWSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<CardLotteryECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    general_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    souls = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    times_to_get_top_card = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_CARDLOTTERY_DRAWSC::CommandID()
{
    return XJCMD_CSC_CARDLOTTERY_DRAW;
}
int XJCMD_CSC_CARDLOTTERY_DRAWSC::GetCommandID()
{
    return XJCMD_CSC_CARDLOTTERY_DRAW;
}

XJCMD_CSC_CARDLOTTERY_DRAWSC::XJCMD_CSC_CARDLOTTERY_DRAWSC()
{
    SetDefault();
}
void XJCMD_CSC_CARDLOTTERY_DRAWSC::SetDefault()
{
    times_to_get_top_card = -1;

}

void XJCMD_CSC_CARDLOTTERY_10_DRAWCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_CSC_CARDLOTTERY_10_DRAWCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_CSC_CARDLOTTERY_10_DRAWCS::CommandID()
{
    return XJCMD_CSC_CARDLOTTERY_10_DRAW;
}
int XJCMD_CSC_CARDLOTTERY_10_DRAWCS::GetCommandID()
{
    return XJCMD_CSC_CARDLOTTERY_10_DRAW;
}

XJCMD_CSC_CARDLOTTERY_10_DRAWCS::XJCMD_CSC_CARDLOTTERY_10_DRAWCS()
{
    SetDefault();
}
void XJCMD_CSC_CARDLOTTERY_10_DRAWCS::SetDefault()
{

}

void XJCMD_CSC_CARDLOTTERY_10_DRAWSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, retcode);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = result_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<result_arraylen; ++i) {
        arraysize = leftsize;
        result[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (leftsize == 0)
        throw EncodeError();
    *p = times_to_get_top_card;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_CARDLOTTERY_10_DRAWSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<CardLotteryECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&result, 0, sizeof(st10DrawResult)*10);
    result_arraylen = 0;
    if (arraysize > 10) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        result[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    result_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    times_to_get_top_card = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_CARDLOTTERY_10_DRAWSC::CommandID()
{
    return XJCMD_CSC_CARDLOTTERY_10_DRAW;
}
int XJCMD_CSC_CARDLOTTERY_10_DRAWSC::GetCommandID()
{
    return XJCMD_CSC_CARDLOTTERY_10_DRAW;
}

XJCMD_CSC_CARDLOTTERY_10_DRAWSC::XJCMD_CSC_CARDLOTTERY_10_DRAWSC()
{
    SetDefault();
}
void XJCMD_CSC_CARDLOTTERY_10_DRAWSC::SetDefault()
{
    result_arraylen = 0;
    times_to_get_top_card = -1;

}

};

