
//#include "stdafx.h"


#include "ProtoExplore.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stExploreStageDataEx::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    *p = section_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = map_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stage_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dirtyflag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(ESTAGE_DES_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dirtyflag[0], dirtyflag_arraylen);
    buffersize += dirtyflag_arraylen;
    p += dirtyflag_arraylen;
    leftsize-= dirtyflag_arraylen;

	if (dirtyflag[ESTAGE_DES_OPENSTATE>>3]&(1<<(ESTAGE_DES_OPENSTATE&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = open_state;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ESTAGE_DES_LEFTTIME>>3]&(1<<(ESTAGE_DES_LEFTTIME&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, left_time);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[ESTAGE_DES_FIGHTTIMES>>3]&(1<<(ESTAGE_DES_FIGHTTIMES&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = fight_times;
    ++buffersize;
    ++p;
    --leftsize;
	}

	buffer[0] = buffersize;
}

void stExploreStageDataEx::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    section_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    map_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stage_index = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dirtyflag, 0, sizeof(unsigned char)*(1+(ESTAGE_DES_NUM-1)/8));
    dirtyflag_arraylen = 0;
    if (arraysize > (1+(ESTAGE_DES_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dirtyflag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dirtyflag_arraylen = arraysize;

	if (dirtyflag[ESTAGE_DES_OPENSTATE>>3]&(1<<(ESTAGE_DES_OPENSTATE&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    open_state = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ESTAGE_DES_LEFTTIME>>3]&(1<<(ESTAGE_DES_LEFTTIME&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    left_time = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[ESTAGE_DES_FIGHTTIMES>>3]&(1<<(ESTAGE_DES_FIGHTTIMES&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    fight_times = *p;
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

stExploreStageDataEx::stExploreStageDataEx()
{
    SetDefault();
}
void stExploreStageDataEx::SetDefault()
{
    dirtyflag_arraylen = 0;

}

void stExploreStageSynData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = 14;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = section_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = map_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stage_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = isfinish;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = star;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stage_type;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = del_flag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dirtyflag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(ESTAGE_DES_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dirtyflag[0], dirtyflag_arraylen);
    buffersize += dirtyflag_arraylen;
    p += dirtyflag_arraylen;
    leftsize-= dirtyflag_arraylen;

	if (dirtyflag[ESTAGE_DES_OPENSTATE>>3]&(1<<(ESTAGE_DES_OPENSTATE&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = open_state;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ESTAGE_DES_LEFTTIME>>3]&(1<<(ESTAGE_DES_LEFTTIME&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, left_time);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[ESTAGE_DES_FIGHTTIMES>>3]&(1<<(ESTAGE_DES_FIGHTTIMES&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = fight_times;
    ++buffersize;
    ++p;
    --leftsize;
	}

	buffer[0] = buffersize;
}

void stExploreStageSynData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    section_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    map_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stage_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    isfinish = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    star = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stage_type = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    del_flag = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dirtyflag, 0, sizeof(unsigned char)*(1+(ESTAGE_DES_NUM-1)/8));
    dirtyflag_arraylen = 0;
    if (arraysize > (1+(ESTAGE_DES_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dirtyflag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dirtyflag_arraylen = arraysize;

	if (dirtyflag[ESTAGE_DES_OPENSTATE>>3]&(1<<(ESTAGE_DES_OPENSTATE&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    open_state = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ESTAGE_DES_LEFTTIME>>3]&(1<<(ESTAGE_DES_LEFTTIME&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    left_time = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[ESTAGE_DES_FIGHTTIMES>>3]&(1<<(ESTAGE_DES_FIGHTTIMES&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    fight_times = *p;
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

stExploreStageSynData::stExploreStageSynData()
{
    SetDefault();
}
void stExploreStageSynData::SetDefault()
{
    dirtyflag_arraylen = 0;

}


/* body */
void XJCMD_CSC_USEREXPLORE_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = dirtyflag.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < dirtyflag.size()) 
        throw EncodeError();
    memcpy(p,&dirtyflag[0], dirtyflag.size());
    buffersize += dirtyflag.size();
    p += dirtyflag.size();
    leftsize-= dirtyflag.size();

	if (dirtyflag[USER_EXPLORE_ASC_SECTION_OPEN>>3]&(1<<(USER_EXPLORE_ASC_SECTION_OPEN&0x7))) {   
    if (1 > leftsize) 
        throw EncodeError();
    *p = section_open_flag.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < section_open_flag.size()) 
        throw EncodeError();
    memcpy(p,&section_open_flag[0], section_open_flag.size());
    buffersize += section_open_flag.size();
    p += section_open_flag.size();
    leftsize-= section_open_flag.size();
	}

	if (dirtyflag[USER_EXPLORE_ASC_MAP_OPEN>>3]&(1<<(USER_EXPLORE_ASC_MAP_OPEN&0x7))) {    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, map_open_flag.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < map_open_flag.size()) 
        throw EncodeError();
    memcpy(p,&map_open_flag[0], map_open_flag.size());
    buffersize += map_open_flag.size();
    p += map_open_flag.size();
    leftsize-= map_open_flag.size();
	}
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = stage_data.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<stage_data.size(); ++i) {
        arraysize = leftsize;
        stage_data[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_CSC_USEREXPLORE_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    arraysize = *p;
    --buffersize;
    ++p;
    dirtyflag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    dirtyflag.resize(arraysize);
    memcpy(&dirtyflag[0], p, arraysize*sizeof(char));
    dirtyflag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;

	if (dirtyflag[USER_EXPLORE_ASC_SECTION_OPEN>>3]&(1<<(USER_EXPLORE_ASC_SECTION_OPEN&0x7))) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    section_open_flag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    section_open_flag.resize(arraysize);
    memcpy(&section_open_flag[0], p, arraysize*sizeof(char));
    section_open_flag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
	}

	if (dirtyflag[USER_EXPLORE_ASC_MAP_OPEN>>3]&(1<<(USER_EXPLORE_ASC_MAP_OPEN&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    map_open_flag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    map_open_flag.resize(arraysize);
    memcpy(&map_open_flag[0], p, arraysize*sizeof(char));
    map_open_flag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
	}
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    stage_data.clear();
  
    stage_data.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        stage_data[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_CSC_USEREXPLORE_SYNSC::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_SYN;
}
int XJCMD_CSC_USEREXPLORE_SYNSC::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_SYN;
}

XJCMD_CSC_USEREXPLORE_SYNSC::XJCMD_CSC_USEREXPLORE_SYNSC()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_SYNSC::SetDefault()
{
    dirtyflag.clear();
    section_open_flag.clear();
    map_open_flag.clear();
    stage_data.clear();

}

void XJCMD_CSC_USEREXPLORE_FULLDATASC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    *p = section_num;
    ++buffersize;
    ++p;
    --leftsize;
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, finishflag.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < finishflag.size()) 
        throw EncodeError();
    memcpy(p,&finishflag[0], finishflag.size());
    buffersize += finishflag.size();
    p += finishflag.size();
    leftsize-= finishflag.size();
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, stars.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < stars.size()) 
        throw EncodeError();
    memcpy(p,&stars[0], stars.size());
    buffersize += stars.size();
    p += stars.size();
    leftsize-= stars.size();
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = section_open_flag.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < section_open_flag.size()) 
        throw EncodeError();
    memcpy(p,&section_open_flag[0], section_open_flag.size());
    buffersize += section_open_flag.size();
    p += section_open_flag.size();
    leftsize-= section_open_flag.size();
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, map_open_flag.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < map_open_flag.size()) 
        throw EncodeError();
    memcpy(p,&map_open_flag[0], map_open_flag.size());
    buffersize += map_open_flag.size();
    p += map_open_flag.size();
    leftsize-= map_open_flag.size();
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, elite_data_ex.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<elite_data_ex.size(); ++i) {
        arraysize = leftsize;
        elite_data_ex[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, boss_data_ex.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<boss_data_ex.size(); ++i) {
        arraysize = leftsize;
        boss_data_ex[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, hide_data_ex.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<hide_data_ex.size(); ++i) {
        arraysize = leftsize;
        hide_data_ex[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
    if (2 > leftsize)
        throw EncodeError();;
    CProto::h2n_16(p, award_data_ex.size());
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<award_data_ex.size(); ++i) {
        arraysize = leftsize;
        award_data_ex[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_CSC_USEREXPLORE_FULLDATASC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    section_num = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    finishflag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    finishflag.resize(arraysize);
    memcpy(&finishflag[0], p, arraysize*sizeof(char));
    finishflag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    stars.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    stars.resize(arraysize);
    memcpy(&stars[0], p, arraysize*sizeof(char));
    stars.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    section_open_flag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    section_open_flag.resize(arraysize);
    memcpy(&section_open_flag[0], p, arraysize*sizeof(char));
    section_open_flag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    map_open_flag.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    map_open_flag.resize(arraysize);
    memcpy(&map_open_flag[0], p, arraysize*sizeof(char));
    map_open_flag.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    elite_data_ex.clear();
  
    elite_data_ex.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        elite_data_ex[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    boss_data_ex.clear();
  
    boss_data_ex.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        boss_data_ex[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    hide_data_ex.clear();
  
    hide_data_ex.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        hide_data_ex[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    award_data_ex.clear();
  
    award_data_ex.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        award_data_ex[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_CSC_USEREXPLORE_FULLDATASC::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_FULLDATA;
}
int XJCMD_CSC_USEREXPLORE_FULLDATASC::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_FULLDATA;
}

XJCMD_CSC_USEREXPLORE_FULLDATASC::XJCMD_CSC_USEREXPLORE_FULLDATASC()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_FULLDATASC::SetDefault()
{
    finishflag.clear();
    stars.clear();
    section_open_flag.clear();
    map_open_flag.clear();
    elite_data_ex.clear();
    boss_data_ex.clear();
    hide_data_ex.clear();
    award_data_ex.clear();

}

void XJCMD_CSC_USEREXPLORE_RES_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, version_res_section);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = version_res_section_type;
    ++buffersize;
    ++p;
    --leftsize;
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, resdata_section.size());
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < resdata_section.size()) 
        throw EncodeError();
    memcpy(p,&resdata_section[0], resdata_section.size());
    buffersize += resdata_section.size();
    p += resdata_section.size();
    leftsize-= resdata_section.size();
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, version_res_stage);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = version_res_stage_type;
    ++buffersize;
    ++p;
    --leftsize;
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, resdata_stage.size());
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < resdata_stage.size()) 
        throw EncodeError();
    memcpy(p,&resdata_stage[0], resdata_stage.size());
    buffersize += resdata_stage.size();
    p += resdata_stage.size();
    leftsize-= resdata_stage.size();
}

void XJCMD_CSC_USEREXPLORE_RES_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    version_res_section = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    version_res_section_type = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    resdata_section.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    resdata_section.resize(arraysize);
    memcpy(&resdata_section[0], p, arraysize*sizeof(char));
    resdata_section.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    version_res_stage = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    version_res_stage_type = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    resdata_stage.clear();
  
    if (arraysize > buffersize)
        throw DecodeError();
    resdata_stage.resize(arraysize);
    memcpy(&resdata_stage[0], p, arraysize*sizeof(char));
    resdata_stage.setsize(arraysize);
    buffersize -= arraysize;
    p += arraysize;
}

int XJCMD_CSC_USEREXPLORE_RES_SYNSC::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_RES_SYN;
}
int XJCMD_CSC_USEREXPLORE_RES_SYNSC::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_RES_SYN;
}

XJCMD_CSC_USEREXPLORE_RES_SYNSC::XJCMD_CSC_USEREXPLORE_RES_SYNSC()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_RES_SYNSC::SetDefault()
{
    resdata_section.clear();
    resdata_stage.clear();

}

void XJCMD_CSC_USEREXPLORE_CHALLENGECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = section_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = map_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stage_index;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_USEREXPLORE_CHALLENGECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    section_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    map_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stage_index = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_USEREXPLORE_CHALLENGECS::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_CHALLENGE;
}
int XJCMD_CSC_USEREXPLORE_CHALLENGECS::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_CHALLENGE;
}

XJCMD_CSC_USEREXPLORE_CHALLENGECS::XJCMD_CSC_USEREXPLORE_CHALLENGECS()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_CHALLENGECS::SetDefault()
{

}

void XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = section_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = map_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stage_index;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    section_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    map_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stage_index = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT;
}
int XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT;
}

XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS::SetDefault()
{

}

void XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    *p = stage_type;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    data_ex.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    stage_type = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    data_ex.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::CommandID()
{
    return XJCMD_CSC_USEREXPLORE_SYN_BATCH;
}
int XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::GetCommandID()
{
    return XJCMD_CSC_USEREXPLORE_SYN_BATCH;
}

XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::XJCMD_CSC_USEREXPLORE_SYN_BATCHSC()
{
    SetDefault();
}
void XJCMD_CSC_USEREXPLORE_SYN_BATCHSC::SetDefault()
{

}

};

