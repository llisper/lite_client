
//#include "stdafx.h"


#include "ProtoSyt.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void SytProgress::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = level;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = pve_index;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = ev_index;
    ++buffersize;
    ++p;
    --leftsize;
}

void SytProgress::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    level = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    pve_index = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    ev_index = *p;
    --buffersize;
    ++p;
}

SytProgress::SytProgress()
{
    SetDefault();
}
void SytProgress::SetDefault()
{

}

void SytEvPveData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, dialog_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytEvPveData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    stage_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    dialog_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytEvPveData::SytEvPveData()
{
    SetDefault();
}
void SytEvPveData::SetDefault()
{

}

void SytEvPvpData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = reserved;
    ++buffersize;
    ++p;
    --leftsize;
}

void SytEvPvpData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    reserved = *p;
    --buffersize;
    ++p;
}

SytEvPvpData::SytEvPvpData()
{
    SetDefault();
}
void SytEvPvpData::SetDefault()
{

}

void SytEvTCAwardItem::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, item_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = count;
    ++buffersize;
    ++p;
    --leftsize;
}

void SytEvTCAwardItem::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    item_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    count = *p;
    --buffersize;
    ++p;
}

SytEvTCAwardItem::SytEvTCAwardItem()
{
    SetDefault();
}
void SytEvTCAwardItem::SetDefault()
{

}

void SytEvTreasureChestData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, chest_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, silver);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, gold);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, guard_stage_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;

	if (guard_stage_id != -1) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, dialog_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}
}

void SytEvTreasureChestData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (4 > buffersize)
        throw DecodeError();
    chest_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&items, 0, sizeof(SytEvTCAwardItem)*MAX_NUM_TC_AWARD_ITEM);
    items_arraylen = 0;
    if (arraysize > MAX_NUM_TC_AWARD_ITEM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        items[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    items_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    silver = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    gold = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    guard_stage_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;

	if (guard_stage_id != -1) {  
    if (4 > buffersize)
        throw DecodeError();
    dialog_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}
}

SytEvTreasureChestData::SytEvTreasureChestData()
{
    SetDefault();
}
void SytEvTreasureChestData::SetDefault()
{
    items_arraylen = 0;
    guard_stage_id = -1;

}

void SytEvAdvData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, target_general_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = candidates_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * NUM_ADV_GP_CDD > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<candidates_arraylen; ++i) {
        CProto::h2n_32(p, candidates[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, ask_dialog_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, success_dialog_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, fail_dialog_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytEvAdvData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    target_general_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&candidates, 0, sizeof(int)*NUM_ADV_GP_CDD);
    candidates_arraylen = 0;
    if (arraysize > NUM_ADV_GP_CDD) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        candidates[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    candidates_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    ask_dialog_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    success_dialog_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    fail_dialog_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytEvAdvData::SytEvAdvData()
{
    SetDefault();
}
void SytEvAdvData::SetDefault()
{
    candidates_arraylen = 0;

}

void SytEvRandAwardData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, money);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytEvRandAwardData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    money = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytEvRandAwardData::SytEvRandAwardData()
{
    SetDefault();
}
void SytEvRandAwardData::SetDefault()
{

}

void SytEvent::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, tag);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (tag == SytEvPveBoss || tag == SytEvPve) {  
    arraysize = leftsize;
    pve.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (tag == SytEvPvp) {  
    arraysize = leftsize;
    pvp.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (tag == SytEvTreasureChest) {  
    arraysize = leftsize;
    treasure_chest.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (tag == SytEvAdvanture) {  
    arraysize = leftsize;
    adv_data.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (tag == SytEvRandAward) {  
    arraysize = leftsize;
    rand_award_data.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}
}

void SytEvent::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    tag = static_cast<SytEventTag>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;

	if (tag == SytEvPveBoss || tag == SytEvPve) {  
    arraysize = buffersize;
    pve.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (tag == SytEvPvp) {  
    arraysize = buffersize;
    pvp.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (tag == SytEvTreasureChest) {  
    arraysize = buffersize;
    treasure_chest.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (tag == SytEvAdvanture) {  
    arraysize = buffersize;
    adv_data.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (tag == SytEvRandAward) {  
    arraysize = buffersize;
    rand_award_data.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}
}

SytEvent::SytEvent()
{
    SetDefault();
}
void SytEvent::SetDefault()
{

}

void SytEvSeq::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = level;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = seq_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<seq_arraylen; ++i) {
        arraysize = leftsize;
        seq[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void SytEvSeq::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    level = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&seq, 0, sizeof(SytEvent)*MAX_NUM_EVENTS);
    seq_arraylen = 0;
    if (arraysize > MAX_NUM_EVENTS) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        seq[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    seq_arraylen = arraysize;
}

SytEvSeq::SytEvSeq()
{
    SetDefault();
}
void SytEvSeq::SetDefault()
{
    seq_arraylen = 0;

}

void SytJAL_ITEM::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, item_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, con_idx);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, count);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytJAL_ITEM::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    item_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    con_idx = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    count = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytJAL_ITEM::SytJAL_ITEM()
{
    SetDefault();
}
void SytJAL_ITEM::SetDefault()
{

}

void SytJAL_Soul::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, general_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, con_idx);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, count);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytJAL_Soul::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    general_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    con_idx = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    count = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytJAL_Soul::SytJAL_Soul()
{
    SetDefault();
}
void SytJAL_Soul::SetDefault()
{

}

void SytJAL_GENERAL_AWARD::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    levelup_info.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, assist_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    assist_levelup_info.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void SytJAL_GENERAL_AWARD::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    levelup_info.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    assist_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    assist_levelup_info.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

SytJAL_GENERAL_AWARD::SytJAL_GENERAL_AWARD()
{
    SetDefault();
}
void SytJAL_GENERAL_AWARD::SetDefault()
{

}

void SytJAL_SKILL::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, skill_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, con_idx);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, count);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void SytJAL_SKILL::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    skill_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    con_idx = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    count = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

SytJAL_SKILL::SytJAL_SKILL()
{
    SetDefault();
}
void SytJAL_SKILL::SetDefault()
{

}

void SytJumpAwardList::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, energy);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, spirit);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, silver);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    levelup_info.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, general_exp);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = item_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<item_arraylen; ++i) {
        arraysize = leftsize;
        item[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = soul_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<soul_arraylen; ++i) {
        arraysize = leftsize;
        soul[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = general_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<general_arraylen; ++i) {
        arraysize = leftsize;
        general[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = skill_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<skill_arraylen; ++i) {
        arraysize = leftsize;
        skill[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void SytJumpAwardList::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    energy = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    spirit = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    silver = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    levelup_info.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    general_exp = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&item, 0, sizeof(SytJAL_ITEM)*MAX_AWARD_ITEM_NUM);
    item_arraylen = 0;
    if (arraysize > MAX_AWARD_ITEM_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        item[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    item_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&soul, 0, sizeof(SytJAL_Soul)*MAX_AWARD_CARD_NUM);
    soul_arraylen = 0;
    if (arraysize > MAX_AWARD_CARD_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        soul[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    soul_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&general, 0, sizeof(SytJAL_GENERAL_AWARD)*MAX_BATTLE_OBJ_NUM);
    general_arraylen = 0;
    if (arraysize > MAX_BATTLE_OBJ_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        general[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    general_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&skill, 0, sizeof(SytJAL_SKILL)*MAX_AWARD_SKILL_NUM);
    skill_arraylen = 0;
    if (arraysize > MAX_AWARD_SKILL_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        skill[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    skill_arraylen = arraysize;
}

SytJumpAwardList::SytJumpAwardList()
{
    SetDefault();
}
void SytJumpAwardList::SetDefault()
{
    item_arraylen = 0;
    soul_arraylen = 0;
    general_arraylen = 0;
    skill_arraylen = 0;

}


/* body */
void XJCMD_QUERY_PROGRESSCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_QUERY_PROGRESSCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_QUERY_PROGRESSCS::CommandID()
{
    return XJCMD_QUERY_PROGRESS;
}
int XJCMD_QUERY_PROGRESSCS::GetCommandID()
{
    return XJCMD_QUERY_PROGRESS;
}

XJCMD_QUERY_PROGRESSCS::XJCMD_QUERY_PROGRESSCS()
{
    SetDefault();
}
void XJCMD_QUERY_PROGRESSCS::SetDefault()
{

}

void XJCMD_QUERY_PROGRESSSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = firsttime;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = levels_can_jump;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = play_times;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = max_play_times;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = have_progress;
    ++buffersize;
    ++p;
    --leftsize;

	if (have_progress == 1) {  
    arraysize = leftsize;
    progress.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}
}

void XJCMD_QUERY_PROGRESSSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

        if (1 > buffersize)
        throw DecodeError();
    firsttime = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    levels_can_jump = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    play_times = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    max_play_times = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    have_progress = *p;
    --buffersize;
    ++p;

	if (have_progress == 1) {  
    arraysize = buffersize;
    progress.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}
}

int XJCMD_QUERY_PROGRESSSC::CommandID()
{
    return XJCMD_QUERY_PROGRESS;
}
int XJCMD_QUERY_PROGRESSSC::GetCommandID()
{
    return XJCMD_QUERY_PROGRESS;
}

XJCMD_QUERY_PROGRESSSC::XJCMD_QUERY_PROGRESSSC()
{
    SetDefault();
}
void XJCMD_QUERY_PROGRESSSC::SetDefault()
{
    levels_can_jump = 0;

}

void XJCMD_LEVEL_STARTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, opt);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (opt == SytStartNew) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = jump_levels;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void XJCMD_LEVEL_STARTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    opt = static_cast<SytStartOpt>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;

	if (opt == SytStartNew) {    if (1 > buffersize)
        throw DecodeError();
    jump_levels = *p;
    --buffersize;
    ++p;
	}
}

int XJCMD_LEVEL_STARTCS::CommandID()
{
    return XJCMD_LEVEL_START;
}
int XJCMD_LEVEL_STARTCS::GetCommandID()
{
    return XJCMD_LEVEL_START;
}

XJCMD_LEVEL_STARTCS::XJCMD_LEVEL_STARTCS()
{
    SetDefault();
}
void XJCMD_LEVEL_STARTCS::SetDefault()
{
    jump_levels = 0;

}

void XJCMD_LEVEL_STARTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (leftsize == 0)
        throw EncodeError();
    *p = jump_levels;
    ++buffersize;
    ++p;
    --leftsize;

	if (retcode == SYT_GOOD) {  
    arraysize = leftsize;
    ev_seq.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (jump_levels > 0 && (retcode == SYT_GOOD || retcode == SYT_ALL_LEVEL_FINISHED)) {  
    arraysize = leftsize;
    jump_award_list.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (retcode == SYT_GOOD) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = firsttime;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void XJCMD_LEVEL_STARTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<SytECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    jump_levels = *p;
    --buffersize;
    ++p;

	if (retcode == SYT_GOOD) {  
    arraysize = buffersize;
    ev_seq.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (jump_levels > 0 && (retcode == SYT_GOOD || retcode == SYT_ALL_LEVEL_FINISHED)) {  
    arraysize = buffersize;
    jump_award_list.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (retcode == SYT_GOOD) {    if (1 > buffersize)
        throw DecodeError();
    firsttime = *p;
    --buffersize;
    ++p;
	}
}

int XJCMD_LEVEL_STARTSC::CommandID()
{
    return XJCMD_LEVEL_START;
}
int XJCMD_LEVEL_STARTSC::GetCommandID()
{
    return XJCMD_LEVEL_START;
}

XJCMD_LEVEL_STARTSC::XJCMD_LEVEL_STARTSC()
{
    SetDefault();
}
void XJCMD_LEVEL_STARTSC::SetDefault()
{
    retcode = SYT_GOOD;
    jump_levels = 0;

}

void XJCMD_LEVEL_NEXTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_LEVEL_NEXTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_LEVEL_NEXTCS::CommandID()
{
    return XJCMD_LEVEL_NEXT;
}
int XJCMD_LEVEL_NEXTCS::GetCommandID()
{
    return XJCMD_LEVEL_NEXT;
}

XJCMD_LEVEL_NEXTCS::XJCMD_LEVEL_NEXTCS()
{
    SetDefault();
}
void XJCMD_LEVEL_NEXTCS::SetDefault()
{

}

void XJCMD_LEVEL_NEXTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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

	if (retcode == SYT_GOOD) {  
    arraysize = leftsize;
    ev_seq.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (retcode == SYT_GOOD) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = firsttime;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void XJCMD_LEVEL_NEXTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<SytECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;

	if (retcode == SYT_GOOD) {  
    arraysize = buffersize;
    ev_seq.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (retcode == SYT_GOOD) {    if (1 > buffersize)
        throw DecodeError();
    firsttime = *p;
    --buffersize;
    ++p;
	}
}

int XJCMD_LEVEL_NEXTSC::CommandID()
{
    return XJCMD_LEVEL_NEXT;
}
int XJCMD_LEVEL_NEXTSC::GetCommandID()
{
    return XJCMD_LEVEL_NEXT;
}

XJCMD_LEVEL_NEXTSC::XJCMD_LEVEL_NEXTSC()
{
    SetDefault();
}
void XJCMD_LEVEL_NEXTSC::SetDefault()
{
    retcode = SYT_GOOD;

}

void XJCMD_PROCESS_EVENTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = parameters_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * MAX_NUM_EV_INT_PARAM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<parameters_arraylen; ++i) {
        CProto::h2n_32(p, parameters[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
}

void XJCMD_PROCESS_EVENTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&parameters, 0, sizeof(int)*MAX_NUM_EV_INT_PARAM);
    parameters_arraylen = 0;
    if (arraysize > MAX_NUM_EV_INT_PARAM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        parameters[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    parameters_arraylen = arraysize;
}

int XJCMD_PROCESS_EVENTCS::CommandID()
{
    return XJCMD_PROCESS_EVENT;
}
int XJCMD_PROCESS_EVENTCS::GetCommandID()
{
    return XJCMD_PROCESS_EVENT;
}

XJCMD_PROCESS_EVENTCS::XJCMD_PROCESS_EVENTCS()
{
    SetDefault();
}
void XJCMD_PROCESS_EVENTCS::SetDefault()
{
    parameters_arraylen = 0;

}

void XJCMD_PROCESS_EVENTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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

void XJCMD_PROCESS_EVENTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

      
    if (2 > buffersize)
        throw DecodeError();
    retcode = static_cast<SytECode>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_PROCESS_EVENTSC::CommandID()
{
    return XJCMD_PROCESS_EVENT;
}
int XJCMD_PROCESS_EVENTSC::GetCommandID()
{
    return XJCMD_PROCESS_EVENT;
}

XJCMD_PROCESS_EVENTSC::XJCMD_PROCESS_EVENTSC()
{
    SetDefault();
}
void XJCMD_PROCESS_EVENTSC::SetDefault()
{
    retcode = SYT_GOOD;

}

};

