
//#include "stdafx.h"


#include "ProtoEmotion.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void dateReward::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
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

void dateReward::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
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

dateReward::dateReward()
{
    SetDefault();
}
void dateReward::SetDefault()
{
    scoreRankList.clear();
    generals_arraylen = 0;
    items_arraylen = 0;
    buttons_arraylen = 0;

}

void stAdmireInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, admireValue);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, lastContactTime);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = admireRewardFlag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(PROTO_MAX_ADMIRE_GENERAL_LEVEL-1)/8)) 
        throw EncodeError();
    memcpy(p, &admireRewardFlag[0], admireRewardFlag_arraylen);
    buffersize += admireRewardFlag_arraylen;
    p += admireRewardFlag_arraylen;
    leftsize-= admireRewardFlag_arraylen;
}

void stAdmireInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    generalId = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    admireValue = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (4 > buffersize)
        throw DecodeError();
    lastContactTime = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&admireRewardFlag, 0, sizeof(unsigned char)*(1+(PROTO_MAX_ADMIRE_GENERAL_LEVEL-1)/8));
    admireRewardFlag_arraylen = 0;
    if (arraysize > (1+(PROTO_MAX_ADMIRE_GENERAL_LEVEL-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&admireRewardFlag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    admireRewardFlag_arraylen = arraysize;
}

stAdmireInfo::stAdmireInfo()
{
    SetDefault();
}
void stAdmireInfo::SetDefault()
{
    admireRewardFlag_arraylen = 0;

}

void stAdmireList::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = admireList_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<admireList_arraylen; ++i) {
        arraysize = leftsize;
        admireList[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = jealousFlag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &jealousFlag[0], jealousFlag_arraylen);
    buffersize += jealousFlag_arraylen;
    p += jealousFlag_arraylen;
    leftsize-= jealousFlag_arraylen;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = chatted_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &chatted[0], chatted_arraylen);
    buffersize += chatted_arraylen;
    p += chatted_arraylen;
    leftsize-= chatted_arraylen;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dating_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dating[0], dating_arraylen);
    buffersize += dating_arraylen;
    p += dating_arraylen;
    leftsize-= dating_arraylen;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dated_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dated[0], dated_arraylen);
    buffersize += dated_arraylen;
    p += dated_arraylen;
    leftsize-= dated_arraylen;
}

void stAdmireList::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&admireList, 0, sizeof(stAdmireInfo)*PROTO_MAX_ADMIRE_GENERAL_NUM);
    admireList_arraylen = 0;
    if (arraysize > PROTO_MAX_ADMIRE_GENERAL_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        admireList[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    admireList_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&jealousFlag, 0, sizeof(unsigned char)*(1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8));
    jealousFlag_arraylen = 0;
    if (arraysize > (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&jealousFlag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    jealousFlag_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&chatted, 0, sizeof(unsigned char)*(1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8));
    chatted_arraylen = 0;
    if (arraysize > (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&chatted, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    chatted_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dating, 0, sizeof(unsigned char)*(1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8));
    dating_arraylen = 0;
    if (arraysize > (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dating, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dating_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dated, 0, sizeof(unsigned char)*(1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8));
    dated_arraylen = 0;
    if (arraysize > (1+(PROTO_MAX_ADMIRE_GENERAL_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dated, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dated_arraylen = arraysize;
}

stAdmireList::stAdmireList()
{
    SetDefault();
}
void stAdmireList::SetDefault()
{
    admireList_arraylen = 0;
    jealousFlag_arraylen = 0;
    chatted_arraylen = 0;
    dating_arraylen = 0;
    dated_arraylen = 0;

}


/* body */
void XJCMD_CSC_CHAT_STORYCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, chat_general_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, chat_story_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = chat_option;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_CHAT_STORYCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    chat_general_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    chat_story_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    chat_option = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_CHAT_STORYCS::CommandID()
{
    return XJCMD_CSC_CHAT_STORY;
}
int XJCMD_CSC_CHAT_STORYCS::GetCommandID()
{
    return XJCMD_CSC_CHAT_STORY;
}

XJCMD_CSC_CHAT_STORYCS::XJCMD_CSC_CHAT_STORYCS()
{
    SetDefault();
}
void XJCMD_CSC_CHAT_STORYCS::SetDefault()
{

}

void XJCMD_CSC_CHAT_STORYSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, admire_result);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = date_reward_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<date_reward_arraylen; ++i) {
        arraysize = leftsize;
        date_reward[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_CHAT_STORYSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    admire_result = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&date_reward, 0, sizeof(dateReward)*1);
    date_reward_arraylen = 0;
    if (arraysize > 1) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        date_reward[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    date_reward_arraylen = arraysize;
}

int XJCMD_CSC_CHAT_STORYSC::CommandID()
{
    return XJCMD_CSC_CHAT_STORY;
}
int XJCMD_CSC_CHAT_STORYSC::GetCommandID()
{
    return XJCMD_CSC_CHAT_STORY;
}

XJCMD_CSC_CHAT_STORYSC::XJCMD_CSC_CHAT_STORYSC()
{
    SetDefault();
}
void XJCMD_CSC_CHAT_STORYSC::SetDefault()
{
    date_reward_arraylen = 0;

}

void XJCMD_CSC_ASK_DATECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
    CProto::h2n_32(p, senario_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_ASK_DATECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
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
    senario_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_ASK_DATECS::CommandID()
{
    return XJCMD_CSC_ASK_DATE;
}
int XJCMD_CSC_ASK_DATECS::GetCommandID()
{
    return XJCMD_CSC_ASK_DATE;
}

XJCMD_CSC_ASK_DATECS::XJCMD_CSC_ASK_DATECS()
{
    SetDefault();
}
void XJCMD_CSC_ASK_DATECS::SetDefault()
{

}

void XJCMD_CSC_ASK_DATESC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
}

void XJCMD_CSC_ASK_DATESC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_ASK_DATESC::CommandID()
{
    return XJCMD_CSC_ASK_DATE;
}
int XJCMD_CSC_ASK_DATESC::GetCommandID()
{
    return XJCMD_CSC_ASK_DATE;
}

XJCMD_CSC_ASK_DATESC::XJCMD_CSC_ASK_DATESC()
{
    SetDefault();
}
void XJCMD_CSC_ASK_DATESC::SetDefault()
{

}

void XJCMD_CSC_GENERAL_PRESENTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, present_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, present_type);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GENERAL_PRESENTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    present_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    present_type = static_cast<USER_EMOTION_PRESENT_TYPE>(CProto::n2h_16(p));
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GENERAL_PRESENTCS::CommandID()
{
    return XJCMD_CSC_GENERAL_PRESENT;
}
int XJCMD_CSC_GENERAL_PRESENTCS::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRESENT;
}

XJCMD_CSC_GENERAL_PRESENTCS::XJCMD_CSC_GENERAL_PRESENTCS()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRESENTCS::SetDefault()
{

}

void XJCMD_CSC_GENERAL_PRESENTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, admire_count);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_GENERAL_PRESENTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    result = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    admire_count = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_GENERAL_PRESENTSC::CommandID()
{
    return XJCMD_CSC_GENERAL_PRESENT;
}
int XJCMD_CSC_GENERAL_PRESENTSC::GetCommandID()
{
    return XJCMD_CSC_GENERAL_PRESENT;
}

XJCMD_CSC_GENERAL_PRESENTSC::XJCMD_CSC_GENERAL_PRESENTSC()
{
    SetDefault();
}
void XJCMD_CSC_GENERAL_PRESENTSC::SetDefault()
{

}

void XJCMD_SC_EMOTION_SYNCSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
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
  
    if (1 > leftsize)
        throw EncodeError();
    *p = dirtyflag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(EMOTION_ASC_NUM-1)/8)) 
        throw EncodeError();
    memcpy(p, &dirtyflag[0], dirtyflag_arraylen);
    buffersize += dirtyflag_arraylen;
    p += dirtyflag_arraylen;
    leftsize-= dirtyflag_arraylen;

	if (dirtyflag[EMOTION_ASC_ADMIRE>>3]&(1<<(EMOTION_ASC_ADMIRE&0x7))) {  
    arraysize = leftsize;
    general_admire.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}

	if (dirtyflag[EMOTION_ASC_DATING>>3]&(1<<(EMOTION_ASC_DATING&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = dating;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void XJCMD_SC_EMOTION_SYNCSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    version = *p;
    --buffersize;
    ++p;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dirtyflag, 0, sizeof(unsigned char)*(1+(EMOTION_ASC_NUM-1)/8));
    dirtyflag_arraylen = 0;
    if (arraysize > (1+(EMOTION_ASC_NUM-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dirtyflag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dirtyflag_arraylen = arraysize;

	if (dirtyflag[EMOTION_ASC_ADMIRE>>3]&(1<<(EMOTION_ASC_ADMIRE&0x7))) {  
    arraysize = buffersize;
    general_admire.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}

	if (dirtyflag[EMOTION_ASC_DATING>>3]&(1<<(EMOTION_ASC_DATING&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    dating = *p;
    --buffersize;
    ++p;
	}
}

int XJCMD_SC_EMOTION_SYNCSC::CommandID()
{
    return XJCMD_SC_EMOTION_SYNC;
}
int XJCMD_SC_EMOTION_SYNCSC::GetCommandID()
{
    return XJCMD_SC_EMOTION_SYNC;
}

XJCMD_SC_EMOTION_SYNCSC::XJCMD_SC_EMOTION_SYNCSC()
{
    SetDefault();
}
void XJCMD_SC_EMOTION_SYNCSC::SetDefault()
{
    dirtyflag_arraylen = 0;

}

};

