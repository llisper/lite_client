
//#include "stdafx.h"


#include "ProtoBattle.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void ProtoBattleCampInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
       
    if (1 > leftsize) 
        throw EncodeError();
    *p = user_guid.size();
    ++buffersize;
    ++p;
    --leftsize;
    if (8 * user_guid.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< user_guid.size(); ++i) {
        CProto::h2n_64(p, user_guid[i]);
        buffersize += 8;
        p += 8;
        leftsize -= 8;
    }
}

void ProtoBattleCampInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    user_guid.clear();
  
    if (8 * arraysize > buffersize)
        throw DecodeError();
    user_guid.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        user_guid.push_back(CProto::n2h_64(p));
        buffersize -= 8;
        p += 8;
    }
}

ProtoBattleCampInfo::ProtoBattleCampInfo()
{
    SetDefault();
}
void ProtoBattleCampInfo::SetDefault()
{
    user_guid.clear();

}

void ProtoBattleFightInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
       
    if (1 > leftsize) 
        throw EncodeError();
    *p = battle_array_id.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * battle_array_id.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< battle_array_id.size(); ++i) {
        CProto::h2n_32(p, battle_array_id[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (leftsize == 0)
        throw EncodeError();
    *p = super_element;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleFightInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    battle_array_id.clear();
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    battle_array_id.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        battle_array_id.push_back(CProto::n2h_32(p));
        buffersize -= 4;
        p += 4;
    }
    if (1 > buffersize)
        throw DecodeError();
    super_element = *p;
    --buffersize;
    ++p;
}

ProtoBattleFightInfo::ProtoBattleFightInfo()
{
    SetDefault();
}
void ProtoBattleFightInfo::SetDefault()
{
    battle_array_id.clear();

}

void ProtoBattleGeneralInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, assist_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = pos;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, max_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void ProtoBattleGeneralInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    assist_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    pos = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    max_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

ProtoBattleGeneralInfo::ProtoBattleGeneralInfo()
{
    SetDefault();
}
void ProtoBattleGeneralInfo::SetDefault()
{

}

void ProtoBattleAttackerObj::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, max_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, diff_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fight_state.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < fight_state.size()) 
        throw EncodeError();
    memcpy(p,&fight_state[0], fight_state.size());
    buffersize += fight_state.size();
    p += fight_state.size();
    leftsize-= fight_state.size();
  
    if (leftsize == 0)
        throw EncodeError();
    *p = assist_value;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleAttackerObj::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    max_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    diff_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fight_state.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    fight_state.resize(arraysize);
    memcpy(&fight_state[0], p, arraysize*sizeof(char));
    fight_state.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
    if (1 > buffersize)
        throw DecodeError();
    assist_value = *p;
    --buffersize;
    ++p;
}

ProtoBattleAttackerObj::ProtoBattleAttackerObj()
{
    SetDefault();
}
void ProtoBattleAttackerObj::SetDefault()
{
    fight_state.clear();

}

void ProtoBattleAttacker::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    arraysize = leftsize;
    obj_data.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void ProtoBattleAttacker::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    pos = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    obj_data.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

ProtoBattleAttacker::ProtoBattleAttacker()
{
    SetDefault();
}
void ProtoBattleAttacker::SetDefault()
{

}

void ProtoBattleDefenderObj::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, max_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, diff_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fight_state.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < fight_state.size()) 
        throw EncodeError();
    memcpy(p,&fight_state[0], fight_state.size());
    buffersize += fight_state.size();
    p += fight_state.size();
    leftsize-= fight_state.size();
  
    if (leftsize == 0)
        throw EncodeError();
    *p = assist_value;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleDefenderObj::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    max_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    diff_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fight_state.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    fight_state.resize(arraysize);
    memcpy(&fight_state[0], p, arraysize*sizeof(char));
    fight_state.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
    if (1 > buffersize)
        throw DecodeError();
    assist_value = *p;
    --buffersize;
    ++p;
}

ProtoBattleDefenderObj::ProtoBattleDefenderObj()
{
    SetDefault();
}
void ProtoBattleDefenderObj::SetDefault()
{
    fight_state.clear();

}

void ProtoBattleDefender::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    arraysize = leftsize;
    obj_data.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void ProtoBattleDefender::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    pos = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    obj_data.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

ProtoBattleDefender::ProtoBattleDefender()
{
    SetDefault();
}
void ProtoBattleDefender::SetDefault()
{

}

void ProtoBattleImpactObj::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, max_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, diff_hp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fight_state.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < fight_state.size()) 
        throw EncodeError();
    memcpy(p,&fight_state[0], fight_state.size());
    buffersize += fight_state.size();
    p += fight_state.size();
    leftsize-= fight_state.size();
  
    if (leftsize == 0)
        throw EncodeError();
    *p = assist_value;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleImpactObj::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    max_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    diff_hp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fight_state.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    fight_state.resize(arraysize);
    memcpy(&fight_state[0], p, arraysize*sizeof(char));
    fight_state.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
    if (1 > buffersize)
        throw DecodeError();
    assist_value = *p;
    --buffersize;
    ++p;
}

ProtoBattleImpactObj::ProtoBattleImpactObj()
{
    SetDefault();
}
void ProtoBattleImpactObj::SetDefault()
{
    fight_state.clear();

}

void ProtoBattleImpacter::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = op_type;
    ++buffersize;
    ++p;
    --leftsize;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = impact_id.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * impact_id.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< impact_id.size(); ++i) {
        CProto::h2n_32(p, impact_id[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (leftsize == 0)
        throw EncodeError();
    *p = pos;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    obj_data.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void ProtoBattleImpacter::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    op_type = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    impact_id.clear();
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    impact_id.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        impact_id.push_back(CProto::n2h_32(p));
        buffersize -= 4;
        p += 4;
    }
    if (1 > buffersize)
        throw DecodeError();
    pos = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    obj_data.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

ProtoBattleImpacter::ProtoBattleImpacter()
{
    SetDefault();
}
void ProtoBattleImpacter::SetDefault()
{
    impact_id.clear();

}

void ProtoBattleSkillInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = attackers.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<attackers.size(); ++i) {
        arraysize = leftsize;
        attackers[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = defenders.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<defenders.size(); ++i) {
        arraysize = leftsize;
        defenders[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = impacters.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<impacters.size(); ++i) {
        arraysize = leftsize;
        impacters[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
  
    if (leftsize == 0)
        throw EncodeError();
    *p = super_value;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, score);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void ProtoBattleSkillInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    arraysize = *p;
    --buffersize;
    ++p;
    attackers.clear();
  
    attackers.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        attackers[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    defenders.clear();
  
    defenders.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        defenders[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    impacters.clear();
  
    impacters.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        impacters[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    if (1 > buffersize)
        throw DecodeError();
    super_value = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    score = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

ProtoBattleSkillInfo::ProtoBattleSkillInfo()
{
    SetDefault();
}
void ProtoBattleSkillInfo::SetDefault()
{
    attackers.clear();
    defenders.clear();
    impacters.clear();

}

void ProtoBattleJointAttackData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
       
    if (1 > leftsize) 
        throw EncodeError();
    *p = joint_pos.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < joint_pos.size()) 
        throw EncodeError();
    memcpy(p,&joint_pos[0], joint_pos.size());
    buffersize += joint_pos.size();
    p += joint_pos.size();
    leftsize-= joint_pos.size();
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fly_pos.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < fly_pos.size()) 
        throw EncodeError();
    memcpy(p,&fly_pos[0], fly_pos.size());
    buffersize += fly_pos.size();
    p += fly_pos.size();
    leftsize-= fly_pos.size();
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = joint_rate.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < joint_rate.size()) 
        throw EncodeError();
    memcpy(p,&joint_rate[0], joint_rate.size());
    buffersize += joint_rate.size();
    p += joint_rate.size();
    leftsize-= joint_rate.size();
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, score);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void ProtoBattleJointAttackData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    joint_pos.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    joint_pos.resize(arraysize);
    memcpy(&joint_pos[0], p, arraysize*sizeof(char));
    joint_pos.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fly_pos.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    fly_pos.resize(arraysize);
    memcpy(&fly_pos[0], p, arraysize*sizeof(char));
    fly_pos.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    joint_rate.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    joint_rate.resize(arraysize);
    memcpy(&joint_rate[0], p, arraysize*sizeof(char));
    joint_rate.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    score = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

ProtoBattleJointAttackData::ProtoBattleJointAttackData()
{
    SetDefault();
}
void ProtoBattleJointAttackData::SetDefault()
{
    joint_pos.clear();
    fly_pos.clear();
    joint_rate.clear();

}

void ProtoBattleJointAttackInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
        if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, joint_datas.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<joint_datas.size(); ++i) {
        arraysize = leftsize;
        joint_datas[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void ProtoBattleJointAttackInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    joint_datas.clear();
  
    joint_datas.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        joint_datas[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

ProtoBattleJointAttackInfo::ProtoBattleJointAttackInfo()
{
    SetDefault();
}
void ProtoBattleJointAttackInfo::SetDefault()
{
    joint_datas.clear();

}

void ProtoBattleAttackOrderInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
       
    if (1 > leftsize) 
        throw EncodeError();
    *p = attack_order.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < attack_order.size()) 
        throw EncodeError();
    memcpy(p,&attack_order[0], attack_order.size());
    buffersize += attack_order.size();
    p += attack_order.size();
    leftsize-= attack_order.size();
}

void ProtoBattleAttackOrderInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    attack_order.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    attack_order.resize(arraysize);
    memcpy(&attack_order[0], p, arraysize*sizeof(char));
    attack_order.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

ProtoBattleAttackOrderInfo::ProtoBattleAttackOrderInfo()
{
    SetDefault();
}
void ProtoBattleAttackOrderInfo::SetDefault()
{
    attack_order.clear();

}

void ProtoBattleRoundInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = curr_round;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleRoundInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    curr_round = *p;
    --buffersize;
    ++p;
}

ProtoBattleRoundInfo::ProtoBattleRoundInfo()
{
    SetDefault();
}
void ProtoBattleRoundInfo::SetDefault()
{

}

void ProtoBattleTurnInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = curr_turn;
    ++buffersize;
    ++p;
    --leftsize;
}

void ProtoBattleTurnInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    curr_turn = *p;
    --buffersize;
    ++p;
}

ProtoBattleTurnInfo::ProtoBattleTurnInfo()
{
    SetDefault();
}
void ProtoBattleTurnInfo::SetDefault()
{

}

void ProtoBattleFightNode::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void ProtoBattleFightNode::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

ProtoBattleFightNode::ProtoBattleFightNode()
{
    SetDefault();
}
void ProtoBattleFightNode::SetDefault()
{

}

void ProtoBattleField::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, stage_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = camps.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<camps.size(); ++i) {
        arraysize = leftsize;
        camps[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = flags.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < flags.size()) 
        throw EncodeError();
    memcpy(p,&flags[0], flags.size());
    buffersize += flags.size();
    p += flags.size();
    leftsize-= flags.size();
  
    if (leftsize == 0)
        throw EncodeError();
    *p = max_turn;
    ++buffersize;
    ++p;
    --leftsize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, fights.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<fights.size(); ++i) {
        arraysize = leftsize;
        fights[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, general_add.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<general_add.size(); ++i) {
        arraysize = leftsize;
        general_add[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, skills.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<skills.size(); ++i) {
        arraysize = leftsize;
        skills[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, rounds.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<rounds.size(); ++i) {
        arraysize = leftsize;
        rounds[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, turns.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<turns.size(); ++i) {
        arraysize = leftsize;
        turns[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, attack_orders.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<attack_orders.size(); ++i) {
        arraysize = leftsize;
        attack_orders[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, joint_attacks.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<joint_attacks.size(); ++i) {
        arraysize = leftsize;
        joint_attacks[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, fight_node_array.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<fight_node_array.size(); ++i) {
        arraysize = leftsize;
        fight_node_array[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void ProtoBattleField::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    stage_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    camps.clear();
  
    camps.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        camps[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    flags.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    flags.resize(arraysize);
    memcpy(&flags[0], p, arraysize*sizeof(char));
    flags.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
    if (1 > buffersize)
        throw DecodeError();
    max_turn = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    fights.clear();
  
    fights.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        fights[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    general_add.clear();
  
    general_add.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        general_add[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    skills.clear();
  
    skills.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        skills[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    rounds.clear();
  
    rounds.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        rounds[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    turns.clear();
  
    turns.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        turns[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    attack_orders.clear();
  
    attack_orders.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        attack_orders[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    joint_attacks.clear();
  
    joint_attacks.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        joint_attacks[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    fight_node_array.clear();
  
    fight_node_array.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        fight_node_array[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

ProtoBattleField::ProtoBattleField()
{
    SetDefault();
}
void ProtoBattleField::SetDefault()
{
    camps.clear();
    flags.clear();
    fights.clear();
    general_add.clear();
    skills.clear();
    rounds.clear();
    turns.clear();
    attack_orders.clear();
    joint_attacks.clear();
    fight_node_array.clear();

}


/* body */
void XJCMD_SC_BATTLESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    arraysize = leftsize;
    battleFiled.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, battleType);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = resultFlag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, totalScore);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = scoreRankList.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<scoreRankList.size(); ++i) {
        arraysize = leftsize;
        scoreRankList[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, userExp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    userExpRelated.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, userMoneySilver);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = userLevelUpFlag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, generalExpAdd);
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
  
    if (1 > leftsize)
        throw EncodeError();
    *p = items_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<items_arraylen; ++i) {
        arraysize = leftsize;
        items[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = buttons_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<buttons_arraylen; ++i) {
        arraysize = leftsize;
        buttons[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_SC_BATTLESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    arraysize = buffersize;
    battleFiled.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    battleType = static_cast<eBattleType>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    resultFlag = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    totalScore = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    scoreRankList.clear();
  
    scoreRankList.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        scoreRankList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (4 > buffersize)
        throw DecodeError();
    userExp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    userExpRelated.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    userMoneySilver = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    userLevelUpFlag = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    generalExpAdd = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&generals, 0, sizeof(BattleReslutGeneral)*MAX_BATTLE_OBJ_NUM);
    generals_arraylen = 0;
    if (arraysize > MAX_BATTLE_OBJ_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        generals[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    generals_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&items, 0, sizeof(DropItem)*MAX_BATTLE_DROP_ITEM_NUM);
    items_arraylen = 0;
    if (arraysize > MAX_BATTLE_DROP_ITEM_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        items[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    items_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&buttons, 0, sizeof(ButtonItem)*MAX_BUTTON_NUM);
    buttons_arraylen = 0;
    if (arraysize > MAX_BUTTON_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        buttons[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    buttons_arraylen = arraysize;
}

int XJCMD_SC_BATTLESC::CommandID()
{
    return XJCMD_SC_BATTLE;
}
int XJCMD_SC_BATTLESC::GetCommandID()
{
    return XJCMD_SC_BATTLE;
}

XJCMD_SC_BATTLESC::XJCMD_SC_BATTLESC()
{
    SetDefault();
}
void XJCMD_SC_BATTLESC::SetDefault()
{
    scoreRankList.clear();
    generals_arraylen = 0;
    items_arraylen = 0;
    buttons_arraylen = 0;

}

};

