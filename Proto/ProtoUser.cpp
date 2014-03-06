
//#include "stdafx.h"


#include "ProtoUser.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stUserResData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, 8);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, maxexp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, maxenergy);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, maxspirit);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	CProto::h2n_16(buffer, buffersize);
}

void stUserResData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        int oldsize = buffersize; 
    int skiplen = 0;
  
    if (2 > buffersize)
        throw DecodeError();
    skiplen = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    maxexp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    maxenergy = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    maxspirit = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stUserResData::stUserResData()
{
    SetDefault();
}
void stUserResData::SetDefault()
{

}

void stCardTree::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = treeid;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = subtreeid;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, cardmaxnum);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = awardtype;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, awardparam1);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, awardparam2);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stCardTree::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    treeid = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    subtreeid = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    cardmaxnum = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    awardtype = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    awardparam1 = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    awardparam2 = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stCardTree::stCardTree()
{
    SetDefault();
}
void stCardTree::SetDefault()
{

}

void stArtifice::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    *p = is_soul;
    ++buffersize;
    ++p;
    --leftsize;

	if (is_soul == 1) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, soul_num);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}
}

void stArtifice::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    general_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    is_soul = *p;
    --buffersize;
    ++p;

	if (is_soul == 1) {  
    if (2 > buffersize)
        throw DecodeError();
    soul_num = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}
}

stArtifice::stArtifice()
{
    SetDefault();
}
void stArtifice::SetDefault()
{
    is_soul = 0;

}


/* body */
void XJCMD_CSC_USERINFO_SYNCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = user_version;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, user_db_res_version);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, user_res_version);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_USERINFO_SYNCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    user_version = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    user_db_res_version = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    user_res_version = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_USERINFO_SYNCS::CommandID()
{
    return XJCMD_CSC_USERINFO_SYN;
}
int XJCMD_CSC_USERINFO_SYNCS::GetCommandID()
{
    return XJCMD_CSC_USERINFO_SYN;
}

XJCMD_CSC_USERINFO_SYNCS::XJCMD_CSC_USERINFO_SYNCS()
{
    SetDefault();
}
void XJCMD_CSC_USERINFO_SYNCS::SetDefault()
{

}

void XJCMD_CSC_USERINFO_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = version;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, version_db_res);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dirtyflag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(USER_ASC_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dirtyflag[0], dirtyflag_arraylen);
    buffersize += dirtyflag_arraylen;
    p += dirtyflag_arraylen;
    leftsize-= dirtyflag_arraylen;

	if (dirtyflag[USER_ASC_NAME>>3]&(1<<(USER_ASC_NAME&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, name_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &name[0], name_arraylen);
    buffersize += name_arraylen;
    p += name_arraylen;
    leftsize-= name_arraylen;
	}

	if (dirtyflag[USER_ASC_SEX>>3]&(1<<(USER_ASC_SEX&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = sex;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[USER_ASC_FACE>>3]&(1<<(USER_ASC_FACE&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, faceid);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_LEVEL>>3]&(1<<(USER_ASC_LEVEL&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[USER_ASC_EXP>>3]&(1<<(USER_ASC_EXP&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_VIP_LEVEL>>3]&(1<<(USER_ASC_VIP_LEVEL&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = viplevel;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[USER_ASC_SILVER>>3]&(1<<(USER_ASC_SILVER&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, silver);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_GOLD>>3]&(1<<(USER_ASC_GOLD&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, gold);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_CRYSTAL>>3]&(1<<(USER_ASC_CRYSTAL&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, crystal);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_ENERGY>>3]&(1<<(USER_ASC_ENERGY&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, energy);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[USER_ASC_ENERGY_RECOVER_TIME>>3]&(1<<(USER_ASC_ENERGY_RECOVER_TIME&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, energy_recover_time);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[USER_ASC_ENERGY_RECOVER_TIME>>3]&(1<<(USER_ASC_ENERGY_RECOVER_TIME&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, all_energy_recover_time);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_SPIRIT>>3]&(1<<(USER_ASC_SPIRIT&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, spirit);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[USER_ASC_SPIRIT_RECOVER_TIME>>3]&(1<<(USER_ASC_SPIRIT_RECOVER_TIME&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, spirit_recover_time);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[USER_ASC_SPIRIT_RECOVER_TIME>>3]&(1<<(USER_ASC_SPIRIT_RECOVER_TIME&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, all_spirit_recover_time);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_ENCHANTMENT>>3]&(1<<(USER_ASC_ENCHANTMENT&0x7))) {   
    if (1 > leftsize) 
        throw EncodeError();
    *p = enchantment_level.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * enchantment_level.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< enchantment_level.size(); ++i) {
        CProto::h2n_16(p, enchantment_level[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
	}

	if (dirtyflag[USER_ASC_YUANQI>>3]&(1<<(USER_ASC_YUANQI&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, yuanqi);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_RES>>3]&(1<<(USER_ASC_RES&0x7))) {  
    arraysize = leftsize;
    resdata.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (dirtyflag[USER_ASC_CARDTREE>>3]&(1<<(USER_ASC_CARDTREE&0x7))) {  
    if (1 > leftsize)
        throw EncodeError();
    *p = cardtree_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<cardtree_arraylen; ++i) {
        arraysize = leftsize;
        cardtree[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
	}

	if (dirtyflag[USER_ASC_COMBATPOWER>>3]&(1<<(USER_ASC_COMBATPOWER&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, combat_power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_RARE_DRAW_TIMESTAMP>>3]&(1<<(USER_ASC_RARE_DRAW_TIMESTAMP&0x7))) {  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, rare_draw_timestamp);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
	}

	if (dirtyflag[USER_ASC_EPIC_DRAW_TIMESTAMP>>3]&(1<<(USER_ASC_EPIC_DRAW_TIMESTAMP&0x7))) {  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, epic_draw_timestamp);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
	}

	if (dirtyflag[USER_ASC_PRESTIGE>>3]&(1<<(USER_ASC_PRESTIGE&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, prestige);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[USER_ASC_NEXT_EXPLORE_CHALLENGE_BAT_TIME>>3]&(1<<(USER_ASC_NEXT_EXPLORE_CHALLENGE_BAT_TIME&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, next_explore_challenge_bat_time);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}
}

void XJCMD_CSC_USERINFO_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    version = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    version_db_res = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dirtyflag, 0, sizeof(unsigned char)*(1+(USER_ASC_NUM-1)/8));
    dirtyflag_arraylen = 0;
    if (arraysize > (1+(USER_ASC_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dirtyflag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dirtyflag_arraylen = arraysize;

	if (dirtyflag[USER_ASC_NAME>>3]&(1<<(USER_ASC_NAME&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
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
	}

	if (dirtyflag[USER_ASC_SEX>>3]&(1<<(USER_ASC_SEX&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    sex = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[USER_ASC_FACE>>3]&(1<<(USER_ASC_FACE&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    faceid = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_LEVEL>>3]&(1<<(USER_ASC_LEVEL&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[USER_ASC_EXP>>3]&(1<<(USER_ASC_EXP&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_VIP_LEVEL>>3]&(1<<(USER_ASC_VIP_LEVEL&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    viplevel = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[USER_ASC_SILVER>>3]&(1<<(USER_ASC_SILVER&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    silver = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_GOLD>>3]&(1<<(USER_ASC_GOLD&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    gold = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_CRYSTAL>>3]&(1<<(USER_ASC_CRYSTAL&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    crystal = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_ENERGY>>3]&(1<<(USER_ASC_ENERGY&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    energy = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[USER_ASC_ENERGY_RECOVER_TIME>>3]&(1<<(USER_ASC_ENERGY_RECOVER_TIME&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    energy_recover_time = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[USER_ASC_ENERGY_RECOVER_TIME>>3]&(1<<(USER_ASC_ENERGY_RECOVER_TIME&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    all_energy_recover_time = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_SPIRIT>>3]&(1<<(USER_ASC_SPIRIT&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    spirit = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[USER_ASC_SPIRIT_RECOVER_TIME>>3]&(1<<(USER_ASC_SPIRIT_RECOVER_TIME&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    spirit_recover_time = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[USER_ASC_SPIRIT_RECOVER_TIME>>3]&(1<<(USER_ASC_SPIRIT_RECOVER_TIME&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    all_spirit_recover_time = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_ENCHANTMENT>>3]&(1<<(USER_ASC_ENCHANTMENT&0x7))) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    enchantment_level.clear();
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    enchantment_level.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        enchantment_level.push_back(CProto::n2h_16(p));
        buffersize-=2; p+=2;
    }
	}

	if (dirtyflag[USER_ASC_YUANQI>>3]&(1<<(USER_ASC_YUANQI&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    yuanqi = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_RES>>3]&(1<<(USER_ASC_RES&0x7))) {  
    arraysize = buffersize;
    resdata.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (dirtyflag[USER_ASC_CARDTREE>>3]&(1<<(USER_ASC_CARDTREE&0x7))) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&cardtree, 0, sizeof(stCardTree)*PROTO_MAX_CARDTREE_NUM);
    cardtree_arraylen = 0;
    if (arraysize > PROTO_MAX_CARDTREE_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        cardtree[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    cardtree_arraylen = arraysize;
	}

	if (dirtyflag[USER_ASC_COMBATPOWER>>3]&(1<<(USER_ASC_COMBATPOWER&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    combat_power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_RARE_DRAW_TIMESTAMP>>3]&(1<<(USER_ASC_RARE_DRAW_TIMESTAMP&0x7))) {  
    if (8 > buffersize)
        throw DecodeError();
    rare_draw_timestamp = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
	}

	if (dirtyflag[USER_ASC_EPIC_DRAW_TIMESTAMP>>3]&(1<<(USER_ASC_EPIC_DRAW_TIMESTAMP&0x7))) {  
    if (8 > buffersize)
        throw DecodeError();
    epic_draw_timestamp = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
	}

	if (dirtyflag[USER_ASC_PRESTIGE>>3]&(1<<(USER_ASC_PRESTIGE&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    prestige = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[USER_ASC_NEXT_EXPLORE_CHALLENGE_BAT_TIME>>3]&(1<<(USER_ASC_NEXT_EXPLORE_CHALLENGE_BAT_TIME&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    next_explore_challenge_bat_time = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}
}

int XJCMD_CSC_USERINFO_SYNSC::CommandID()
{
    return XJCMD_CSC_USERINFO_SYN;
}
int XJCMD_CSC_USERINFO_SYNSC::GetCommandID()
{
    return XJCMD_CSC_USERINFO_SYN;
}

XJCMD_CSC_USERINFO_SYNSC::XJCMD_CSC_USERINFO_SYNSC()
{
    SetDefault();
}
void XJCMD_CSC_USERINFO_SYNSC::SetDefault()
{
    dirtyflag_arraylen = 0;
    name_arraylen = 0;
    enchantment_level.clear();
    cardtree_arraylen = 0;

}

void XJCMD_CSC_CHANGEFACECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, newfaceid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_CHANGEFACECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    newfaceid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_CHANGEFACECS::CommandID()
{
    return XJCMD_CSC_CHANGEFACE;
}
int XJCMD_CSC_CHANGEFACECS::GetCommandID()
{
    return XJCMD_CSC_CHANGEFACE;
}

XJCMD_CSC_CHANGEFACECS::XJCMD_CSC_CHANGEFACECS()
{
    SetDefault();
}
void XJCMD_CSC_CHANGEFACECS::SetDefault()
{

}

void XJCMD_CSC_CHANGEFACESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, newfaceid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_CHANGEFACESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    newfaceid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_CHANGEFACESC::CommandID()
{
    return XJCMD_CSC_CHANGEFACE;
}
int XJCMD_CSC_CHANGEFACESC::GetCommandID()
{
    return XJCMD_CSC_CHANGEFACE;
}

XJCMD_CSC_CHANGEFACESC::XJCMD_CSC_CHANGEFACESC()
{
    SetDefault();
}
void XJCMD_CSC_CHANGEFACESC::SetDefault()
{

}

void XJCMD_CSC_ENCHANTMENT_ARTIFICECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, data_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<data_arraylen; ++i) {
        arraysize = leftsize;
        data[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_ENCHANTMENT_ARTIFICECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&data, 0, sizeof(stArtifice)*MAX_USERGENERAL_NUM);
    data_arraylen = 0;
    if (arraysize > MAX_USERGENERAL_NUM) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        data[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    data_arraylen = arraysize;
}

int XJCMD_CSC_ENCHANTMENT_ARTIFICECS::CommandID()
{
    return XJCMD_CSC_ENCHANTMENT_ARTIFICE;
}
int XJCMD_CSC_ENCHANTMENT_ARTIFICECS::GetCommandID()
{
    return XJCMD_CSC_ENCHANTMENT_ARTIFICE;
}

XJCMD_CSC_ENCHANTMENT_ARTIFICECS::XJCMD_CSC_ENCHANTMENT_ARTIFICECS()
{
    SetDefault();
}
void XJCMD_CSC_ENCHANTMENT_ARTIFICECS::SetDefault()
{
    data_arraylen = 0;

}

void XJCMD_CSC_ENCHANTMENT_ARTIFICESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
}

void XJCMD_CSC_ENCHANTMENT_ARTIFICESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<EnchantmentECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_ENCHANTMENT_ARTIFICESC::CommandID()
{
    return XJCMD_CSC_ENCHANTMENT_ARTIFICE;
}
int XJCMD_CSC_ENCHANTMENT_ARTIFICESC::GetCommandID()
{
    return XJCMD_CSC_ENCHANTMENT_ARTIFICE;
}

XJCMD_CSC_ENCHANTMENT_ARTIFICESC::XJCMD_CSC_ENCHANTMENT_ARTIFICESC()
{
    SetDefault();
}
void XJCMD_CSC_ENCHANTMENT_ARTIFICESC::SetDefault()
{

}

void XJCMD_CSC_ENCHANTMENT_LEVELUPCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = enchantment_index;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_ENCHANTMENT_LEVELUPCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    enchantment_index = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_ENCHANTMENT_LEVELUPCS::CommandID()
{
    return XJCMD_CSC_ENCHANTMENT_LEVELUP;
}
int XJCMD_CSC_ENCHANTMENT_LEVELUPCS::GetCommandID()
{
    return XJCMD_CSC_ENCHANTMENT_LEVELUP;
}

XJCMD_CSC_ENCHANTMENT_LEVELUPCS::XJCMD_CSC_ENCHANTMENT_LEVELUPCS()
{
    SetDefault();
}
void XJCMD_CSC_ENCHANTMENT_LEVELUPCS::SetDefault()
{

}

void XJCMD_CSC_ENCHANTMENT_LEVELUPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
}

void XJCMD_CSC_ENCHANTMENT_LEVELUPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<EnchantmentECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_ENCHANTMENT_LEVELUPSC::CommandID()
{
    return XJCMD_CSC_ENCHANTMENT_LEVELUP;
}
int XJCMD_CSC_ENCHANTMENT_LEVELUPSC::GetCommandID()
{
    return XJCMD_CSC_ENCHANTMENT_LEVELUP;
}

XJCMD_CSC_ENCHANTMENT_LEVELUPSC::XJCMD_CSC_ENCHANTMENT_LEVELUPSC()
{
    SetDefault();
}
void XJCMD_CSC_ENCHANTMENT_LEVELUPSC::SetDefault()
{

}

};

