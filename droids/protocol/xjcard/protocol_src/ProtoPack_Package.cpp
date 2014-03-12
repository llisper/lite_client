
//#include "stdafx.h"


#include "ProtoPack_Package.h"

#include "ProtoPack.h"
#include "ProtoUser.h"
#include "ProtoTitle.h"
#include "ProtoTest.h"
#include "ProtoSyt.h"
#include "ProtoSystemTips.h"
#include "ProtoSystemDialog.h"
#include "ProtoSkill.h"
#include "ProtoSenario.h"
#include "ProtoResource.h"
#include "ProtoPinJian.h"
#include "ProtoNotice.h"
#include "ProtoMail.h"
#include "ProtoLogin.h"
#include "ProtoLog.h"
#include "ProtoItem.h"
#include "ProtoGeneralTravel.h"
#include "ProtoGeneral.h"
#include "ProtoFriend.h"
#include "ProtoExplore.h"
#include "ProtoEmotion.h"
#include "ProtoDefine.h"
#include "ProtoContainer.h"
#include "ProtoChat.h"
#include "ProtoChar.h"
#include "ProtoCardTree.h"
#include "ProtoBattle.h"
#include "ProtoActivity.h"
#include "CProto.h"
#include "CProto_Command.h"

/* Implement */
namespace CProto {
int PackcHelper::GetBodySize(int cmd)
{
    switch (cmd) {
        case XJCMD_CSC_ACTIVITY_COMMAND:
	return sizeof(XJCMD_CSC_ACTIVITY_COMMANDCS);
	break;
    case XJCMD_CSC_CARDTREE_REWARD:
	return sizeof(XJCMD_CSC_CARDTREE_REWARDCS);
	break;
    case XJCMD_CREATECHAR:
	return sizeof(XJCMD_CREATECHARCS);
	break;
    case XJCMD_DELETECHAR:
	return sizeof(XJCMD_DELETECHARCS);
	break;
    case XJCMD_CANCELDELETECHAR:
	return sizeof(XJCMD_CANCELDELETECHARCS);
	break;
    case XJCMD_CSC_CHAT:
	return sizeof(XJCMD_CSC_CHATCS);
	break;
    case XJCMD_CSC_ITEM_DETAIL:
	return sizeof(XJCMD_CSC_ITEM_DETAILCS);
	break;
    case XJCMD_CSC_CHAT_STORY:
	return sizeof(XJCMD_CSC_CHAT_STORYCS);
	break;
    case XJCMD_CSC_ASK_DATE:
	return sizeof(XJCMD_CSC_ASK_DATECS);
	break;
    case XJCMD_CSC_GENERAL_PRESENT:
	return sizeof(XJCMD_CSC_GENERAL_PRESENTCS);
	break;
    case XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP:
	return sizeof(XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPCS);
	break;
    case XJCMD_CSC_PRESENT_SHOP:
	return sizeof(XJCMD_CSC_PRESENT_SHOPCS);
	break;
    case XJCMD_CSC_USEREXPLORE_CHALLENGE:
	return sizeof(XJCMD_CSC_USEREXPLORE_CHALLENGECS);
	break;
    case XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT:
	return sizeof(XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS);
	break;
    case XJCMD_CSC_FRIENDINFO_LIST:
	return sizeof(XJCMD_CSC_FRIENDINFO_LISTCS);
	break;
    case XJCMD_CSC_FRIENDEVENT_LIST:
	return sizeof(XJCMD_CSC_FRIENDEVENT_LISTCS);
	break;
    case XJCMD_CSC_FRIEND_NEW:
	return sizeof(XJCMD_CSC_FRIEND_NEWCS);
	break;
    case XJCMD_CSC_FRIEND_OP:
	return sizeof(XJCMD_CSC_FRIEND_OPCS);
	break;
    case XJCMD_CSC_FRIEND_GET_PRESENT:
	return sizeof(XJCMD_CSC_FRIEND_GET_PRESENTCS);
	break;
    case XJCMD_CS_BATTLEARR_ASSITPOS_OPEN:
	return sizeof(XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS);
	break;
    case XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE:
	return sizeof(XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS);
	break;
    case XJCMD_CSC_SUMMON_GENERAL:
	return sizeof(XJCMD_CSC_SUMMON_GENERALCS);
	break;
    case XJCMD_CSC_GENERAL_PRACTICE:
	return sizeof(XJCMD_CSC_GENERAL_PRACTICECS);
	break;
    case XJCMD_CSC_GENERAL_PRACTICE_REBUILD:
	return sizeof(XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS);
	break;
    case XJCMD_CSC_GENERAL_ADD_ADDITION_FATE:
	return sizeof(XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS);
	break;
    case XJCMD_CSC_TRAINING:
	return sizeof(XJCMD_CSC_TRAININGCS);
	break;
    case XJCMD_CSC_TRAINING_CONFIRM:
	return sizeof(XJCMD_CSC_TRAINING_CONFIRMCS);
	break;
    case XJCMD_CSC_KUNGFU_TRANSMIT:
	return sizeof(XJCMD_CSC_KUNGFU_TRANSMITCS);
	break;
    case XJCMD_CSC_CARDLOTTERY_DRAW:
	return sizeof(XJCMD_CSC_CARDLOTTERY_DRAWCS);
	break;
    case XJCMD_CSC_CARDLOTTERY_10_DRAW:
	return sizeof(XJCMD_CSC_CARDLOTTERY_10_DRAWCS);
	break;
    case XJCMD_CSC_GENERALTRAVEL_DETAIL:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_DETAILCS);
	break;
    case XJCMD_CSC_GENERALTRAVEL_USEMONEY:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_USEMONEYCS);
	break;
    case XJCMD_CSC_GENERALTRAVEL_BEGIN:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_BEGINCS);
	break;
    case XJCMD_CSC_GENERALTRAVEL_GETREWARD:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_GETREWARDCS);
	break;
    case XJCMD_CSC_GENERALTRAVEL_FATELIST:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_FATELISTCS);
	break;
    case XJCMD_CSC_ITEM_OPER:
	return sizeof(XJCMD_CSC_ITEM_OPERCS);
	break;
    case XJCMD_CSC_ITEM_2_EXP:
	return sizeof(XJCMD_CSC_ITEM_2_EXPCS);
	break;
    case XJCMD_CS_LOG:
	return sizeof(XJCMD_CS_LOGCS);
	break;
    case XJCMD_CH2S_CLOSE:
	return sizeof(XJCMD_CH2S_CLOSECS);
	break;
    case XJCMD_CSC_VERSION:
	return sizeof(XJCMD_CSC_VERSIONCS);
	break;
    case XJCMD_CS_ENTERGAME_START:
	return sizeof(XJCMD_CS_ENTERGAME_STARTCS);
	break;
    case XJCMD_CSC_LOGIN:
	return sizeof(XJCMD_CSC_LOGINCS);
	break;
    case XJCMD_CSC_GSDISPATCH:
	return sizeof(XJCMD_CSC_GSDISPATCHCS);
	break;
    case XJCMD_CSC_GSLOGIN:
	return sizeof(XJCMD_CSC_GSLOGINCS);
	break;
    case XJCMD_CSC_MAIL_DETAIL:
	return sizeof(XJCMD_CSC_MAIL_DETAILCS);
	break;
    case XJCMD_CSC_MAIL_SEND:
	return sizeof(XJCMD_CSC_MAIL_SENDCS);
	break;
    case XJCMD_CSC_MAIL_DELETE:
	return sizeof(XJCMD_CSC_MAIL_DELETECS);
	break;
    case XJCMD_CSC_MAIL_GET_ATTACH:
	return sizeof(XJCMD_CSC_MAIL_GET_ATTACHCS);
	break;
    case XJCMD_CSC_SYSTEM_NOTICE:
	return sizeof(XJCMD_CSC_SYSTEM_NOTICECS);
	break;
    case XJCMD_CSC_PINJIAN_OPEN:
	return sizeof(XJCMD_CSC_PINJIAN_OPENCS);
	break;
    case XJCMD_CSC_PINJIAN_FIGHT:
	return sizeof(XJCMD_CSC_PINJIAN_FIGHTCS);
	break;
    case XJCMD_CSC_PINJIAN_TOPLIST:
	return sizeof(XJCMD_CSC_PINJIAN_TOPLISTCS);
	break;
    case XJCMD_CS_ASK_SKILL_LEVELUP:
	return sizeof(XJCMD_CS_ASK_SKILL_LEVELUPCS);
	break;
    case XJCMD_CS_SKILL_ON:
	return sizeof(XJCMD_CS_SKILL_ONCS);
	break;
    case XJCMD_CS_SYSTEM_RECYCLECHECK:
	return sizeof(XJCMD_CS_SYSTEM_RECYCLECHECKCS);
	break;
    case XJCMD_QUERY_PROGRESS:
	return sizeof(XJCMD_QUERY_PROGRESSCS);
	break;
    case XJCMD_LEVEL_START:
	return sizeof(XJCMD_LEVEL_STARTCS);
	break;
    case XJCMD_LEVEL_NEXT:
	return sizeof(XJCMD_LEVEL_NEXTCS);
	break;
    case XJCMD_PROCESS_EVENT:
	return sizeof(XJCMD_PROCESS_EVENTCS);
	break;
    case XJCMD_SC_TEST:
	return sizeof(XJCMD_SC_TESTCS);
	break;
    case XJCMD_CSC_TITLE_USE:
	return sizeof(XJCMD_CSC_TITLE_USECS);
	break;
    case XJCMD_CSC_USERINFO_SYN:
	return sizeof(XJCMD_CSC_USERINFO_SYNCS);
	break;
    case XJCMD_CSC_CHANGEFACE:
	return sizeof(XJCMD_CSC_CHANGEFACECS);
	break;
    case XJCMD_CSC_ENCHANTMENT_ARTIFICE:
	return sizeof(XJCMD_CSC_ENCHANTMENT_ARTIFICECS);
	break;
    case XJCMD_CSC_ENCHANTMENT_LEVELUP:
	return sizeof(XJCMD_CSC_ENCHANTMENT_LEVELUPCS);
	break;
	default:
		break;
	}

}

void packc::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, length);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    head.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
if ((head.command>XJCMD_INVALID && head.command<XJCMD_MAXSIZE)) {
        arraysize = leftsize;
        if (packbody)
                packbody->Encode(p, arraysize);
        p += arraysize;
        buffersize += arraysize;
        leftsize -= arraysize;
	}

	/* package length */
	CProto::h2n_32(buffer, buffersize);
}

void packc::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    length = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    head.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	if ((head.command>XJCMD_INVALID && head.command<XJCMD_MAXSIZE)) {
        arraysize = buffersize;
        if (packbody)
                packbody->Decode(p, arraysize);
        p += buffersize - arraysize;
        buffersize = arraysize;
	}
}

void packc::DecodeHead(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
      
    if (4 > buffersize)
        throw DecodeError();
    length = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    head.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

XJCMD_CSC_ACTIVITY_COMMANDCS* packc::GetXJCMD_CSC_ACTIVITY_COMMANDCS()
{
    if (head.command == XJCMD_CSC_ACTIVITY_COMMAND)
	return csXJCMD_CSC_ACTIVITY_COMMAND;
    return 0;
}

XJCMD_CSC_CARDTREE_REWARDCS* packc::GetXJCMD_CSC_CARDTREE_REWARDCS()
{
    if (head.command == XJCMD_CSC_CARDTREE_REWARD)
	return csXJCMD_CSC_CARDTREE_REWARD;
    return 0;
}

XJCMD_CREATECHARCS* packc::GetXJCMD_CREATECHARCS()
{
    if (head.command == XJCMD_CREATECHAR)
	return csXJCMD_CREATECHAR;
    return 0;
}

XJCMD_DELETECHARCS* packc::GetXJCMD_DELETECHARCS()
{
    if (head.command == XJCMD_DELETECHAR)
	return csXJCMD_DELETECHAR;
    return 0;
}

XJCMD_CANCELDELETECHARCS* packc::GetXJCMD_CANCELDELETECHARCS()
{
    if (head.command == XJCMD_CANCELDELETECHAR)
	return csXJCMD_CANCELDELETECHAR;
    return 0;
}

XJCMD_CSC_CHATCS* packc::GetXJCMD_CSC_CHATCS()
{
    if (head.command == XJCMD_CSC_CHAT)
	return csXJCMD_CSC_CHAT;
    return 0;
}

XJCMD_CSC_ITEM_DETAILCS* packc::GetXJCMD_CSC_ITEM_DETAILCS()
{
    if (head.command == XJCMD_CSC_ITEM_DETAIL)
	return csXJCMD_CSC_ITEM_DETAIL;
    return 0;
}

XJCMD_CSC_CHAT_STORYCS* packc::GetXJCMD_CSC_CHAT_STORYCS()
{
    if (head.command == XJCMD_CSC_CHAT_STORY)
	return csXJCMD_CSC_CHAT_STORY;
    return 0;
}

XJCMD_CSC_ASK_DATECS* packc::GetXJCMD_CSC_ASK_DATECS()
{
    if (head.command == XJCMD_CSC_ASK_DATE)
	return csXJCMD_CSC_ASK_DATE;
    return 0;
}

XJCMD_CSC_GENERAL_PRESENTCS* packc::GetXJCMD_CSC_GENERAL_PRESENTCS()
{
    if (head.command == XJCMD_CSC_GENERAL_PRESENT)
	return csXJCMD_CSC_GENERAL_PRESENT;
    return 0;
}

XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPCS* packc::GetXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPCS()
{
    if (head.command == XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP)
	return csXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP;
    return 0;
}

XJCMD_CSC_PRESENT_SHOPCS* packc::GetXJCMD_CSC_PRESENT_SHOPCS()
{
    if (head.command == XJCMD_CSC_PRESENT_SHOP)
	return csXJCMD_CSC_PRESENT_SHOP;
    return 0;
}

XJCMD_CSC_USEREXPLORE_CHALLENGECS* packc::GetXJCMD_CSC_USEREXPLORE_CHALLENGECS()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_CHALLENGE)
	return csXJCMD_CSC_USEREXPLORE_CHALLENGE;
    return 0;
}

XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS* packc::GetXJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT)
	return csXJCMD_CSC_USEREXPLORE_CHALLENGE_BAT;
    return 0;
}

XJCMD_CSC_FRIENDINFO_LISTCS* packc::GetXJCMD_CSC_FRIENDINFO_LISTCS()
{
    if (head.command == XJCMD_CSC_FRIENDINFO_LIST)
	return csXJCMD_CSC_FRIENDINFO_LIST;
    return 0;
}

XJCMD_CSC_FRIENDEVENT_LISTCS* packc::GetXJCMD_CSC_FRIENDEVENT_LISTCS()
{
    if (head.command == XJCMD_CSC_FRIENDEVENT_LIST)
	return csXJCMD_CSC_FRIENDEVENT_LIST;
    return 0;
}

XJCMD_CSC_FRIEND_NEWCS* packc::GetXJCMD_CSC_FRIEND_NEWCS()
{
    if (head.command == XJCMD_CSC_FRIEND_NEW)
	return csXJCMD_CSC_FRIEND_NEW;
    return 0;
}

XJCMD_CSC_FRIEND_OPCS* packc::GetXJCMD_CSC_FRIEND_OPCS()
{
    if (head.command == XJCMD_CSC_FRIEND_OP)
	return csXJCMD_CSC_FRIEND_OP;
    return 0;
}

XJCMD_CSC_FRIEND_GET_PRESENTCS* packc::GetXJCMD_CSC_FRIEND_GET_PRESENTCS()
{
    if (head.command == XJCMD_CSC_FRIEND_GET_PRESENT)
	return csXJCMD_CSC_FRIEND_GET_PRESENT;
    return 0;
}

XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS* packc::GetXJCMD_CS_BATTLEARR_ASSITPOS_OPENCS()
{
    if (head.command == XJCMD_CS_BATTLEARR_ASSITPOS_OPEN)
	return csXJCMD_CS_BATTLEARR_ASSITPOS_OPEN;
    return 0;
}

XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS* packc::GetXJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS()
{
    if (head.command == XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE)
	return csXJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE;
    return 0;
}

XJCMD_CSC_SUMMON_GENERALCS* packc::GetXJCMD_CSC_SUMMON_GENERALCS()
{
    if (head.command == XJCMD_CSC_SUMMON_GENERAL)
	return csXJCMD_CSC_SUMMON_GENERAL;
    return 0;
}

XJCMD_CSC_GENERAL_PRACTICECS* packc::GetXJCMD_CSC_GENERAL_PRACTICECS()
{
    if (head.command == XJCMD_CSC_GENERAL_PRACTICE)
	return csXJCMD_CSC_GENERAL_PRACTICE;
    return 0;
}

XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS* packc::GetXJCMD_CSC_GENERAL_PRACTICE_REBUILDCS()
{
    if (head.command == XJCMD_CSC_GENERAL_PRACTICE_REBUILD)
	return csXJCMD_CSC_GENERAL_PRACTICE_REBUILD;
    return 0;
}

XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS* packc::GetXJCMD_CSC_GENERAL_ADD_ADDITION_FATECS()
{
    if (head.command == XJCMD_CSC_GENERAL_ADD_ADDITION_FATE)
	return csXJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
    return 0;
}

XJCMD_CSC_TRAININGCS* packc::GetXJCMD_CSC_TRAININGCS()
{
    if (head.command == XJCMD_CSC_TRAINING)
	return csXJCMD_CSC_TRAINING;
    return 0;
}

XJCMD_CSC_TRAINING_CONFIRMCS* packc::GetXJCMD_CSC_TRAINING_CONFIRMCS()
{
    if (head.command == XJCMD_CSC_TRAINING_CONFIRM)
	return csXJCMD_CSC_TRAINING_CONFIRM;
    return 0;
}

XJCMD_CSC_KUNGFU_TRANSMITCS* packc::GetXJCMD_CSC_KUNGFU_TRANSMITCS()
{
    if (head.command == XJCMD_CSC_KUNGFU_TRANSMIT)
	return csXJCMD_CSC_KUNGFU_TRANSMIT;
    return 0;
}

XJCMD_CSC_CARDLOTTERY_DRAWCS* packc::GetXJCMD_CSC_CARDLOTTERY_DRAWCS()
{
    if (head.command == XJCMD_CSC_CARDLOTTERY_DRAW)
	return csXJCMD_CSC_CARDLOTTERY_DRAW;
    return 0;
}

XJCMD_CSC_CARDLOTTERY_10_DRAWCS* packc::GetXJCMD_CSC_CARDLOTTERY_10_DRAWCS()
{
    if (head.command == XJCMD_CSC_CARDLOTTERY_10_DRAW)
	return csXJCMD_CSC_CARDLOTTERY_10_DRAW;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_DETAILCS* packc::GetXJCMD_CSC_GENERALTRAVEL_DETAILCS()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_DETAIL)
	return csXJCMD_CSC_GENERALTRAVEL_DETAIL;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_USEMONEYCS* packc::GetXJCMD_CSC_GENERALTRAVEL_USEMONEYCS()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_USEMONEY)
	return csXJCMD_CSC_GENERALTRAVEL_USEMONEY;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_BEGINCS* packc::GetXJCMD_CSC_GENERALTRAVEL_BEGINCS()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_BEGIN)
	return csXJCMD_CSC_GENERALTRAVEL_BEGIN;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_GETREWARDCS* packc::GetXJCMD_CSC_GENERALTRAVEL_GETREWARDCS()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_GETREWARD)
	return csXJCMD_CSC_GENERALTRAVEL_GETREWARD;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_FATELISTCS* packc::GetXJCMD_CSC_GENERALTRAVEL_FATELISTCS()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_FATELIST)
	return csXJCMD_CSC_GENERALTRAVEL_FATELIST;
    return 0;
}

XJCMD_CSC_ITEM_OPERCS* packc::GetXJCMD_CSC_ITEM_OPERCS()
{
    if (head.command == XJCMD_CSC_ITEM_OPER)
	return csXJCMD_CSC_ITEM_OPER;
    return 0;
}

XJCMD_CSC_ITEM_2_EXPCS* packc::GetXJCMD_CSC_ITEM_2_EXPCS()
{
    if (head.command == XJCMD_CSC_ITEM_2_EXP)
	return csXJCMD_CSC_ITEM_2_EXP;
    return 0;
}

XJCMD_CS_LOGCS* packc::GetXJCMD_CS_LOGCS()
{
    if (head.command == XJCMD_CS_LOG)
	return csXJCMD_CS_LOG;
    return 0;
}

XJCMD_CH2S_CLOSECS* packc::GetXJCMD_CH2S_CLOSECS()
{
    if (head.command == XJCMD_CH2S_CLOSE)
	return csXJCMD_CH2S_CLOSE;
    return 0;
}

XJCMD_CSC_VERSIONCS* packc::GetXJCMD_CSC_VERSIONCS()
{
    if (head.command == XJCMD_CSC_VERSION)
	return csXJCMD_CSC_VERSION;
    return 0;
}

XJCMD_CS_ENTERGAME_STARTCS* packc::GetXJCMD_CS_ENTERGAME_STARTCS()
{
    if (head.command == XJCMD_CS_ENTERGAME_START)
	return csXJCMD_CS_ENTERGAME_START;
    return 0;
}

XJCMD_CSC_LOGINCS* packc::GetXJCMD_CSC_LOGINCS()
{
    if (head.command == XJCMD_CSC_LOGIN)
	return csXJCMD_CSC_LOGIN;
    return 0;
}

XJCMD_CSC_GSDISPATCHCS* packc::GetXJCMD_CSC_GSDISPATCHCS()
{
    if (head.command == XJCMD_CSC_GSDISPATCH)
	return csXJCMD_CSC_GSDISPATCH;
    return 0;
}

XJCMD_CSC_GSLOGINCS* packc::GetXJCMD_CSC_GSLOGINCS()
{
    if (head.command == XJCMD_CSC_GSLOGIN)
	return csXJCMD_CSC_GSLOGIN;
    return 0;
}

XJCMD_CSC_MAIL_DETAILCS* packc::GetXJCMD_CSC_MAIL_DETAILCS()
{
    if (head.command == XJCMD_CSC_MAIL_DETAIL)
	return csXJCMD_CSC_MAIL_DETAIL;
    return 0;
}

XJCMD_CSC_MAIL_SENDCS* packc::GetXJCMD_CSC_MAIL_SENDCS()
{
    if (head.command == XJCMD_CSC_MAIL_SEND)
	return csXJCMD_CSC_MAIL_SEND;
    return 0;
}

XJCMD_CSC_MAIL_DELETECS* packc::GetXJCMD_CSC_MAIL_DELETECS()
{
    if (head.command == XJCMD_CSC_MAIL_DELETE)
	return csXJCMD_CSC_MAIL_DELETE;
    return 0;
}

XJCMD_CSC_MAIL_GET_ATTACHCS* packc::GetXJCMD_CSC_MAIL_GET_ATTACHCS()
{
    if (head.command == XJCMD_CSC_MAIL_GET_ATTACH)
	return csXJCMD_CSC_MAIL_GET_ATTACH;
    return 0;
}

XJCMD_CSC_SYSTEM_NOTICECS* packc::GetXJCMD_CSC_SYSTEM_NOTICECS()
{
    if (head.command == XJCMD_CSC_SYSTEM_NOTICE)
	return csXJCMD_CSC_SYSTEM_NOTICE;
    return 0;
}

XJCMD_CSC_PINJIAN_OPENCS* packc::GetXJCMD_CSC_PINJIAN_OPENCS()
{
    if (head.command == XJCMD_CSC_PINJIAN_OPEN)
	return csXJCMD_CSC_PINJIAN_OPEN;
    return 0;
}

XJCMD_CSC_PINJIAN_FIGHTCS* packc::GetXJCMD_CSC_PINJIAN_FIGHTCS()
{
    if (head.command == XJCMD_CSC_PINJIAN_FIGHT)
	return csXJCMD_CSC_PINJIAN_FIGHT;
    return 0;
}

XJCMD_CSC_PINJIAN_TOPLISTCS* packc::GetXJCMD_CSC_PINJIAN_TOPLISTCS()
{
    if (head.command == XJCMD_CSC_PINJIAN_TOPLIST)
	return csXJCMD_CSC_PINJIAN_TOPLIST;
    return 0;
}

XJCMD_CS_ASK_SKILL_LEVELUPCS* packc::GetXJCMD_CS_ASK_SKILL_LEVELUPCS()
{
    if (head.command == XJCMD_CS_ASK_SKILL_LEVELUP)
	return csXJCMD_CS_ASK_SKILL_LEVELUP;
    return 0;
}

XJCMD_CS_SKILL_ONCS* packc::GetXJCMD_CS_SKILL_ONCS()
{
    if (head.command == XJCMD_CS_SKILL_ON)
	return csXJCMD_CS_SKILL_ON;
    return 0;
}

XJCMD_CS_SYSTEM_RECYCLECHECKCS* packc::GetXJCMD_CS_SYSTEM_RECYCLECHECKCS()
{
    if (head.command == XJCMD_CS_SYSTEM_RECYCLECHECK)
	return csXJCMD_CS_SYSTEM_RECYCLECHECK;
    return 0;
}

XJCMD_QUERY_PROGRESSCS* packc::GetXJCMD_QUERY_PROGRESSCS()
{
    if (head.command == XJCMD_QUERY_PROGRESS)
	return csXJCMD_QUERY_PROGRESS;
    return 0;
}

XJCMD_LEVEL_STARTCS* packc::GetXJCMD_LEVEL_STARTCS()
{
    if (head.command == XJCMD_LEVEL_START)
	return csXJCMD_LEVEL_START;
    return 0;
}

XJCMD_LEVEL_NEXTCS* packc::GetXJCMD_LEVEL_NEXTCS()
{
    if (head.command == XJCMD_LEVEL_NEXT)
	return csXJCMD_LEVEL_NEXT;
    return 0;
}

XJCMD_PROCESS_EVENTCS* packc::GetXJCMD_PROCESS_EVENTCS()
{
    if (head.command == XJCMD_PROCESS_EVENT)
	return csXJCMD_PROCESS_EVENT;
    return 0;
}

XJCMD_SC_TESTCS* packc::GetXJCMD_SC_TESTCS()
{
    if (head.command == XJCMD_SC_TEST)
	return csXJCMD_SC_TEST;
    return 0;
}

XJCMD_CSC_TITLE_USECS* packc::GetXJCMD_CSC_TITLE_USECS()
{
    if (head.command == XJCMD_CSC_TITLE_USE)
	return csXJCMD_CSC_TITLE_USE;
    return 0;
}

XJCMD_CSC_USERINFO_SYNCS* packc::GetXJCMD_CSC_USERINFO_SYNCS()
{
    if (head.command == XJCMD_CSC_USERINFO_SYN)
	return csXJCMD_CSC_USERINFO_SYN;
    return 0;
}

XJCMD_CSC_CHANGEFACECS* packc::GetXJCMD_CSC_CHANGEFACECS()
{
    if (head.command == XJCMD_CSC_CHANGEFACE)
	return csXJCMD_CSC_CHANGEFACE;
    return 0;
}

XJCMD_CSC_ENCHANTMENT_ARTIFICECS* packc::GetXJCMD_CSC_ENCHANTMENT_ARTIFICECS()
{
    if (head.command == XJCMD_CSC_ENCHANTMENT_ARTIFICE)
	return csXJCMD_CSC_ENCHANTMENT_ARTIFICE;
    return 0;
}

XJCMD_CSC_ENCHANTMENT_LEVELUPCS* packc::GetXJCMD_CSC_ENCHANTMENT_LEVELUPCS()
{
    if (head.command == XJCMD_CSC_ENCHANTMENT_LEVELUP)
	return csXJCMD_CSC_ENCHANTMENT_LEVELUP;
    return 0;
}

packc::packc() {}
packc::~packc() {}

bool packc::Init(int cmd, void* body)
{
    if (!body)
	return false;

    head.command = cmd;
    aBody = body;
    bool ret = true;

    switch (head.command) {
            case XJCMD_CSC_ACTIVITY_COMMAND:
	        csXJCMD_CSC_ACTIVITY_COMMAND = new (aBody) XJCMD_CSC_ACTIVITY_COMMANDCS;
	        break;
        case XJCMD_CSC_CARDTREE_REWARD:
	        csXJCMD_CSC_CARDTREE_REWARD = new (aBody) XJCMD_CSC_CARDTREE_REWARDCS;
	        break;
        case XJCMD_CREATECHAR:
	        csXJCMD_CREATECHAR = new (aBody) XJCMD_CREATECHARCS;
	        break;
        case XJCMD_DELETECHAR:
	        csXJCMD_DELETECHAR = new (aBody) XJCMD_DELETECHARCS;
	        break;
        case XJCMD_CANCELDELETECHAR:
	        csXJCMD_CANCELDELETECHAR = new (aBody) XJCMD_CANCELDELETECHARCS;
	        break;
        case XJCMD_CSC_CHAT:
	        csXJCMD_CSC_CHAT = new (aBody) XJCMD_CSC_CHATCS;
	        break;
        case XJCMD_CSC_ITEM_DETAIL:
	        csXJCMD_CSC_ITEM_DETAIL = new (aBody) XJCMD_CSC_ITEM_DETAILCS;
	        break;
        case XJCMD_CSC_CHAT_STORY:
	        csXJCMD_CSC_CHAT_STORY = new (aBody) XJCMD_CSC_CHAT_STORYCS;
	        break;
        case XJCMD_CSC_ASK_DATE:
	        csXJCMD_CSC_ASK_DATE = new (aBody) XJCMD_CSC_ASK_DATECS;
	        break;
        case XJCMD_CSC_GENERAL_PRESENT:
	        csXJCMD_CSC_GENERAL_PRESENT = new (aBody) XJCMD_CSC_GENERAL_PRESENTCS;
	        break;
        case XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP:
	        csXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP = new (aBody) XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPCS;
	        break;
        case XJCMD_CSC_PRESENT_SHOP:
	        csXJCMD_CSC_PRESENT_SHOP = new (aBody) XJCMD_CSC_PRESENT_SHOPCS;
	        break;
        case XJCMD_CSC_USEREXPLORE_CHALLENGE:
	        csXJCMD_CSC_USEREXPLORE_CHALLENGE = new (aBody) XJCMD_CSC_USEREXPLORE_CHALLENGECS;
	        break;
        case XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT:
	        csXJCMD_CSC_USEREXPLORE_CHALLENGE_BAT = new (aBody) XJCMD_CSC_USEREXPLORE_CHALLENGE_BATCS;
	        break;
        case XJCMD_CSC_FRIENDINFO_LIST:
	        csXJCMD_CSC_FRIENDINFO_LIST = new (aBody) XJCMD_CSC_FRIENDINFO_LISTCS;
	        break;
        case XJCMD_CSC_FRIENDEVENT_LIST:
	        csXJCMD_CSC_FRIENDEVENT_LIST = new (aBody) XJCMD_CSC_FRIENDEVENT_LISTCS;
	        break;
        case XJCMD_CSC_FRIEND_NEW:
	        csXJCMD_CSC_FRIEND_NEW = new (aBody) XJCMD_CSC_FRIEND_NEWCS;
	        break;
        case XJCMD_CSC_FRIEND_OP:
	        csXJCMD_CSC_FRIEND_OP = new (aBody) XJCMD_CSC_FRIEND_OPCS;
	        break;
        case XJCMD_CSC_FRIEND_GET_PRESENT:
	        csXJCMD_CSC_FRIEND_GET_PRESENT = new (aBody) XJCMD_CSC_FRIEND_GET_PRESENTCS;
	        break;
        case XJCMD_CS_BATTLEARR_ASSITPOS_OPEN:
	        csXJCMD_CS_BATTLEARR_ASSITPOS_OPEN = new (aBody) XJCMD_CS_BATTLEARR_ASSITPOS_OPENCS;
	        break;
        case XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE:
	        csXJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE = new (aBody) XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGECS;
	        break;
        case XJCMD_CSC_SUMMON_GENERAL:
	        csXJCMD_CSC_SUMMON_GENERAL = new (aBody) XJCMD_CSC_SUMMON_GENERALCS;
	        break;
        case XJCMD_CSC_GENERAL_PRACTICE:
	        csXJCMD_CSC_GENERAL_PRACTICE = new (aBody) XJCMD_CSC_GENERAL_PRACTICECS;
	        break;
        case XJCMD_CSC_GENERAL_PRACTICE_REBUILD:
	        csXJCMD_CSC_GENERAL_PRACTICE_REBUILD = new (aBody) XJCMD_CSC_GENERAL_PRACTICE_REBUILDCS;
	        break;
        case XJCMD_CSC_GENERAL_ADD_ADDITION_FATE:
	        csXJCMD_CSC_GENERAL_ADD_ADDITION_FATE = new (aBody) XJCMD_CSC_GENERAL_ADD_ADDITION_FATECS;
	        break;
        case XJCMD_CSC_TRAINING:
	        csXJCMD_CSC_TRAINING = new (aBody) XJCMD_CSC_TRAININGCS;
	        break;
        case XJCMD_CSC_TRAINING_CONFIRM:
	        csXJCMD_CSC_TRAINING_CONFIRM = new (aBody) XJCMD_CSC_TRAINING_CONFIRMCS;
	        break;
        case XJCMD_CSC_KUNGFU_TRANSMIT:
	        csXJCMD_CSC_KUNGFU_TRANSMIT = new (aBody) XJCMD_CSC_KUNGFU_TRANSMITCS;
	        break;
        case XJCMD_CSC_CARDLOTTERY_DRAW:
	        csXJCMD_CSC_CARDLOTTERY_DRAW = new (aBody) XJCMD_CSC_CARDLOTTERY_DRAWCS;
	        break;
        case XJCMD_CSC_CARDLOTTERY_10_DRAW:
	        csXJCMD_CSC_CARDLOTTERY_10_DRAW = new (aBody) XJCMD_CSC_CARDLOTTERY_10_DRAWCS;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_DETAIL:
	        csXJCMD_CSC_GENERALTRAVEL_DETAIL = new (aBody) XJCMD_CSC_GENERALTRAVEL_DETAILCS;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_USEMONEY:
	        csXJCMD_CSC_GENERALTRAVEL_USEMONEY = new (aBody) XJCMD_CSC_GENERALTRAVEL_USEMONEYCS;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_BEGIN:
	        csXJCMD_CSC_GENERALTRAVEL_BEGIN = new (aBody) XJCMD_CSC_GENERALTRAVEL_BEGINCS;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_GETREWARD:
	        csXJCMD_CSC_GENERALTRAVEL_GETREWARD = new (aBody) XJCMD_CSC_GENERALTRAVEL_GETREWARDCS;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_FATELIST:
	        csXJCMD_CSC_GENERALTRAVEL_FATELIST = new (aBody) XJCMD_CSC_GENERALTRAVEL_FATELISTCS;
	        break;
        case XJCMD_CSC_ITEM_OPER:
	        csXJCMD_CSC_ITEM_OPER = new (aBody) XJCMD_CSC_ITEM_OPERCS;
	        break;
        case XJCMD_CSC_ITEM_2_EXP:
	        csXJCMD_CSC_ITEM_2_EXP = new (aBody) XJCMD_CSC_ITEM_2_EXPCS;
	        break;
        case XJCMD_CS_LOG:
	        csXJCMD_CS_LOG = new (aBody) XJCMD_CS_LOGCS;
	        break;
        case XJCMD_CH2S_CLOSE:
	        csXJCMD_CH2S_CLOSE = new (aBody) XJCMD_CH2S_CLOSECS;
	        break;
        case XJCMD_CSC_VERSION:
	        csXJCMD_CSC_VERSION = new (aBody) XJCMD_CSC_VERSIONCS;
	        break;
        case XJCMD_CS_ENTERGAME_START:
	        csXJCMD_CS_ENTERGAME_START = new (aBody) XJCMD_CS_ENTERGAME_STARTCS;
	        break;
        case XJCMD_CSC_LOGIN:
	        csXJCMD_CSC_LOGIN = new (aBody) XJCMD_CSC_LOGINCS;
	        break;
        case XJCMD_CSC_GSDISPATCH:
	        csXJCMD_CSC_GSDISPATCH = new (aBody) XJCMD_CSC_GSDISPATCHCS;
	        break;
        case XJCMD_CSC_GSLOGIN:
	        csXJCMD_CSC_GSLOGIN = new (aBody) XJCMD_CSC_GSLOGINCS;
	        break;
        case XJCMD_CSC_MAIL_DETAIL:
	        csXJCMD_CSC_MAIL_DETAIL = new (aBody) XJCMD_CSC_MAIL_DETAILCS;
	        break;
        case XJCMD_CSC_MAIL_SEND:
	        csXJCMD_CSC_MAIL_SEND = new (aBody) XJCMD_CSC_MAIL_SENDCS;
	        break;
        case XJCMD_CSC_MAIL_DELETE:
	        csXJCMD_CSC_MAIL_DELETE = new (aBody) XJCMD_CSC_MAIL_DELETECS;
	        break;
        case XJCMD_CSC_MAIL_GET_ATTACH:
	        csXJCMD_CSC_MAIL_GET_ATTACH = new (aBody) XJCMD_CSC_MAIL_GET_ATTACHCS;
	        break;
        case XJCMD_CSC_SYSTEM_NOTICE:
	        csXJCMD_CSC_SYSTEM_NOTICE = new (aBody) XJCMD_CSC_SYSTEM_NOTICECS;
	        break;
        case XJCMD_CSC_PINJIAN_OPEN:
	        csXJCMD_CSC_PINJIAN_OPEN = new (aBody) XJCMD_CSC_PINJIAN_OPENCS;
	        break;
        case XJCMD_CSC_PINJIAN_FIGHT:
	        csXJCMD_CSC_PINJIAN_FIGHT = new (aBody) XJCMD_CSC_PINJIAN_FIGHTCS;
	        break;
        case XJCMD_CSC_PINJIAN_TOPLIST:
	        csXJCMD_CSC_PINJIAN_TOPLIST = new (aBody) XJCMD_CSC_PINJIAN_TOPLISTCS;
	        break;
        case XJCMD_CS_ASK_SKILL_LEVELUP:
	        csXJCMD_CS_ASK_SKILL_LEVELUP = new (aBody) XJCMD_CS_ASK_SKILL_LEVELUPCS;
	        break;
        case XJCMD_CS_SKILL_ON:
	        csXJCMD_CS_SKILL_ON = new (aBody) XJCMD_CS_SKILL_ONCS;
	        break;
        case XJCMD_CS_SYSTEM_RECYCLECHECK:
	        csXJCMD_CS_SYSTEM_RECYCLECHECK = new (aBody) XJCMD_CS_SYSTEM_RECYCLECHECKCS;
	        break;
        case XJCMD_QUERY_PROGRESS:
	        csXJCMD_QUERY_PROGRESS = new (aBody) XJCMD_QUERY_PROGRESSCS;
	        break;
        case XJCMD_LEVEL_START:
	        csXJCMD_LEVEL_START = new (aBody) XJCMD_LEVEL_STARTCS;
	        break;
        case XJCMD_LEVEL_NEXT:
	        csXJCMD_LEVEL_NEXT = new (aBody) XJCMD_LEVEL_NEXTCS;
	        break;
        case XJCMD_PROCESS_EVENT:
	        csXJCMD_PROCESS_EVENT = new (aBody) XJCMD_PROCESS_EVENTCS;
	        break;
        case XJCMD_SC_TEST:
	        csXJCMD_SC_TEST = new (aBody) XJCMD_SC_TESTCS;
	        break;
        case XJCMD_CSC_TITLE_USE:
	        csXJCMD_CSC_TITLE_USE = new (aBody) XJCMD_CSC_TITLE_USECS;
	        break;
        case XJCMD_CSC_USERINFO_SYN:
	        csXJCMD_CSC_USERINFO_SYN = new (aBody) XJCMD_CSC_USERINFO_SYNCS;
	        break;
        case XJCMD_CSC_CHANGEFACE:
	        csXJCMD_CSC_CHANGEFACE = new (aBody) XJCMD_CSC_CHANGEFACECS;
	        break;
        case XJCMD_CSC_ENCHANTMENT_ARTIFICE:
	        csXJCMD_CSC_ENCHANTMENT_ARTIFICE = new (aBody) XJCMD_CSC_ENCHANTMENT_ARTIFICECS;
	        break;
        case XJCMD_CSC_ENCHANTMENT_LEVELUP:
	        csXJCMD_CSC_ENCHANTMENT_LEVELUP = new (aBody) XJCMD_CSC_ENCHANTMENT_LEVELUPCS;
	        break;
        default:
                packbody = 0;
                break;
        }


    return ret;
}

void CProto::packc::SetDefault()
{
packbody = 0;

}

int PacksHelper::GetBodySize(int cmd)
{
    switch (cmd) {
        case XJCMD_SC_ACTIVITYS_SYN:
	return sizeof(XJCMD_SC_ACTIVITYS_SYNSC);
	break;
    case XJCMD_CSC_ACTIVITY_COMMAND:
	return sizeof(XJCMD_CSC_ACTIVITY_COMMANDSC);
	break;
    case XJCMD_SC_BATTLE:
	return sizeof(XJCMD_SC_BATTLESC);
	break;
    case XJCMD_CREATECHAR:
	return sizeof(XJCMD_CREATECHARSC);
	break;
    case XJCMD_DELETECHAR:
	return sizeof(XJCMD_DELETECHARSC);
	break;
    case XJCMD_CANCELDELETECHAR:
	return sizeof(XJCMD_CANCELDELETECHARSC);
	break;
    case XJCMD_CSC_CHAT:
	return sizeof(XJCMD_CSC_CHATSC);
	break;
    case XJCMD_SC_USERBAG_SYN:
	return sizeof(XJCMD_SC_USERBAG_SYNSC);
	break;
    case XJCMD_SC_ITEMS_STATIC_SYN:
	return sizeof(XJCMD_SC_ITEMS_STATIC_SYNSC);
	break;
    case XJCMD_SC_EQUIPS_DISCARD_SYN:
	return sizeof(XJCMD_SC_EQUIPS_DISCARD_SYNSC);
	break;
    case XJCMD_CSC_ITEM_DETAIL:
	return sizeof(XJCMD_CSC_ITEM_DETAILSC);
	break;
    case XJCMD_CSC_CHAT_STORY:
	return sizeof(XJCMD_CSC_CHAT_STORYSC);
	break;
    case XJCMD_CSC_ASK_DATE:
	return sizeof(XJCMD_CSC_ASK_DATESC);
	break;
    case XJCMD_CSC_GENERAL_PRESENT:
	return sizeof(XJCMD_CSC_GENERAL_PRESENTSC);
	break;
    case XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP:
	return sizeof(XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPSC);
	break;
    case XJCMD_CSC_PRESENT_SHOP:
	return sizeof(XJCMD_CSC_PRESENT_SHOPSC);
	break;
    case XJCMD_SC_EMOTION_SYNC:
	return sizeof(XJCMD_SC_EMOTION_SYNCSC);
	break;
    case XJCMD_CSC_USEREXPLORE_SYN:
	return sizeof(XJCMD_CSC_USEREXPLORE_SYNSC);
	break;
    case XJCMD_CSC_USEREXPLORE_FULLDATA:
	return sizeof(XJCMD_CSC_USEREXPLORE_FULLDATASC);
	break;
    case XJCMD_CSC_USEREXPLORE_RES_SYN:
	return sizeof(XJCMD_CSC_USEREXPLORE_RES_SYNSC);
	break;
    case XJCMD_CSC_USEREXPLORE_SYN_BATCH:
	return sizeof(XJCMD_CSC_USEREXPLORE_SYN_BATCHSC);
	break;
    case XJCMD_CSC_FRIENDINFO_LIST:
	return sizeof(XJCMD_CSC_FRIENDINFO_LISTSC);
	break;
    case XJCMD_CSC_FRIENDEVENT_LIST:
	return sizeof(XJCMD_CSC_FRIENDEVENT_LISTSC);
	break;
    case XJCMD_CSC_FRIEND_NEW:
	return sizeof(XJCMD_CSC_FRIEND_NEWSC);
	break;
    case XJCMD_CSC_FRIEND_OP:
	return sizeof(XJCMD_CSC_FRIEND_OPSC);
	break;
    case XJCMD_CSC_FRIEND_PRESENTLIST:
	return sizeof(XJCMD_CSC_FRIEND_PRESENTLISTSC);
	break;
    case XJCMD_CSC_FRIEND_GET_PRESENT:
	return sizeof(XJCMD_CSC_FRIEND_GET_PRESENTSC);
	break;
    case XJCMD_SC_USERGENERAL_FULLDATA:
	return sizeof(XJCMD_SC_USERGENERAL_FULLDATASC);
	break;
    case XJCMD_SC_USERGENERAL_BATTLEARRAY:
	return sizeof(XJCMD_SC_USERGENERAL_BATTLEARRAYSC);
	break;
    case XJCMD_SC_USERGENERAL_RES_SYN:
	return sizeof(XJCMD_SC_USERGENERAL_RES_SYNSC);
	break;
    case XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET:
	return sizeof(XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC);
	break;
    case XJCMD_CSC_SUMMON_GENERAL:
	return sizeof(XJCMD_CSC_SUMMON_GENERALSC);
	break;
    case XJCMD_CSC_GENERAL_PRACTICE:
	return sizeof(XJCMD_CSC_GENERAL_PRACTICESC);
	break;
    case XJCMD_CSC_GENERAL_PRACTICE_REBUILD:
	return sizeof(XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC);
	break;
    case XJCMD_CSC_GENERAL_ADD_ADDITION_FATE:
	return sizeof(XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC);
	break;
    case XJCMD_CSC_TRAINING:
	return sizeof(XJCMD_CSC_TRAININGSC);
	break;
    case XJCMD_CSC_TRAINING_CONFIRM:
	return sizeof(XJCMD_CSC_TRAINING_CONFIRMSC);
	break;
    case XJCMD_CSC_KUNGFU_TRANSMIT:
	return sizeof(XJCMD_CSC_KUNGFU_TRANSMITSC);
	break;
    case XJCMD_CSC_CARDLOTTERY_DRAW:
	return sizeof(XJCMD_CSC_CARDLOTTERY_DRAWSC);
	break;
    case XJCMD_CSC_CARDLOTTERY_10_DRAW:
	return sizeof(XJCMD_CSC_CARDLOTTERY_10_DRAWSC);
	break;
    case XJCMD_CSC_GENERALTRAVEL_DETAIL:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_DETAILSC);
	break;
    case XJCMD_CSC_GENERALTRAVEL_USEMONEY:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_USEMONEYSC);
	break;
    case XJCMD_CSC_GENERALTRAVEL_BEGIN:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_BEGINSC);
	break;
    case XJCMD_CSC_GENERALTRAVEL_GETREWARD:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_GETREWARDSC);
	break;
    case XJCMD_CSC_GENERALTRAVEL_FATELIST:
	return sizeof(XJCMD_CSC_GENERALTRAVEL_FATELISTSC);
	break;
    case XJCMD_CSC_ITEM_OPER:
	return sizeof(XJCMD_CSC_ITEM_OPERSC);
	break;
    case XJCMD_CSC_ITEM_2_EXP:
	return sizeof(XJCMD_CSC_ITEM_2_EXPSC);
	break;
    case XJCMD_S2CH_RESET:
	return sizeof(XJCMD_S2CH_RESETSC);
	break;
    case XJCMD_S2CH_KICK:
	return sizeof(XJCMD_S2CH_KICKSC);
	break;
    case XJCMD_CSC_VERSION:
	return sizeof(XJCMD_CSC_VERSIONSC);
	break;
    case XJCMD_SC_ENTERGAME_FINISH:
	return sizeof(XJCMD_SC_ENTERGAME_FINISHSC);
	break;
    case XJCMD_CSC_LOGIN:
	return sizeof(XJCMD_CSC_LOGINSC);
	break;
    case XJCMD_CSC_GSDISPATCH:
	return sizeof(XJCMD_CSC_GSDISPATCHSC);
	break;
    case XJCMD_CSC_GSLOGIN:
	return sizeof(XJCMD_CSC_GSLOGINSC);
	break;
    case XJCMD_CSC_MAIL_LIST:
	return sizeof(XJCMD_CSC_MAIL_LISTSC);
	break;
    case XJCMD_CSC_MAIL_DETAIL:
	return sizeof(XJCMD_CSC_MAIL_DETAILSC);
	break;
    case XJCMD_CSC_MAIL_SEND:
	return sizeof(XJCMD_CSC_MAIL_SENDSC);
	break;
    case XJCMD_CSC_MAIL_DELETE:
	return sizeof(XJCMD_CSC_MAIL_DELETESC);
	break;
    case XJCMD_CSC_MAIL_GET_ATTACH:
	return sizeof(XJCMD_CSC_MAIL_GET_ATTACHSC);
	break;
    case XJCMD_CSC_SYSTEM_NOTICE:
	return sizeof(XJCMD_CSC_SYSTEM_NOTICESC);
	break;
    case XJCMD_CSC_PINJIAN_OPEN:
	return sizeof(XJCMD_CSC_PINJIAN_OPENSC);
	break;
    case XJCMD_CSC_PINJIAN_TOPLIST:
	return sizeof(XJCMD_CSC_PINJIAN_TOPLISTSC);
	break;
    case XJCMD_CSC_RESOURCE_SYN:
	return sizeof(XJCMD_CSC_RESOURCE_SYNSC);
	break;
    case XJCMD_SC_SENARIO_SYN:
	return sizeof(XJCMD_SC_SENARIO_SYNSC);
	break;
    case XJCMD_CSC_SKILL_DATA:
	return sizeof(XJCMD_CSC_SKILL_DATASC);
	break;
    case XJCMD_SC_RET_SKILL_LEVELUP:
	return sizeof(XJCMD_SC_RET_SKILL_LEVELUPSC);
	break;
    case XJCMD_SC_SYSTEM_DIALOG:
	return sizeof(XJCMD_SC_SYSTEM_DIALOGSC);
	break;
    case XJCMD_SC_SYSTEM_TIP:
	return sizeof(XJCMD_SC_SYSTEM_TIPSC);
	break;
    case XJCMD_SC_AWARD_TIP:
	return sizeof(XJCMD_SC_AWARD_TIPSC);
	break;
    case XJCMD_SC_HIGHLIGHT_TIP:
	return sizeof(XJCMD_SC_HIGHLIGHT_TIPSC);
	break;
    case XJCMD_QUERY_PROGRESS:
	return sizeof(XJCMD_QUERY_PROGRESSSC);
	break;
    case XJCMD_LEVEL_START:
	return sizeof(XJCMD_LEVEL_STARTSC);
	break;
    case XJCMD_LEVEL_NEXT:
	return sizeof(XJCMD_LEVEL_NEXTSC);
	break;
    case XJCMD_PROCESS_EVENT:
	return sizeof(XJCMD_PROCESS_EVENTSC);
	break;
    case XJCMD_SC_TEST:
	return sizeof(XJCMD_SC_TESTSC);
	break;
    case XJCMD_CSC_TITLE_ADD:
	return sizeof(XJCMD_CSC_TITLE_ADDSC);
	break;
    case XJCMD_SC_TITLE_STATE_LIST_SYN:
	return sizeof(XJCMD_SC_TITLE_STATE_LIST_SYNSC);
	break;
    case XJCMD_CSC_USERINFO_SYN:
	return sizeof(XJCMD_CSC_USERINFO_SYNSC);
	break;
    case XJCMD_CSC_CHANGEFACE:
	return sizeof(XJCMD_CSC_CHANGEFACESC);
	break;
    case XJCMD_CSC_ENCHANTMENT_ARTIFICE:
	return sizeof(XJCMD_CSC_ENCHANTMENT_ARTIFICESC);
	break;
    case XJCMD_CSC_ENCHANTMENT_LEVELUP:
	return sizeof(XJCMD_CSC_ENCHANTMENT_LEVELUPSC);
	break;
	default:
		break;
	}

}

void packs::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, length);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    head.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
if ((head.command>XJCMD_INVALID && head.command<XJCMD_MAXSIZE)) {
        arraysize = leftsize;
        if (packbody)
                packbody->Encode(p, arraysize);
        p += arraysize;
        buffersize += arraysize;
        leftsize -= arraysize;
	}

	/* package length */
	CProto::h2n_32(buffer, buffersize);
}

void packs::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    length = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    head.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	if ((head.command>XJCMD_INVALID && head.command<XJCMD_MAXSIZE)) {
        arraysize = buffersize;
        if (packbody)
                packbody->Decode(p, arraysize);
        p += buffersize - arraysize;
        buffersize = arraysize;
	}
}

void packs::DecodeHead(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
      
    if (4 > buffersize)
        throw DecodeError();
    length = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    head.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

XJCMD_SC_ACTIVITYS_SYNSC* packs::GetXJCMD_SC_ACTIVITYS_SYNSC()
{
    if (head.command == XJCMD_SC_ACTIVITYS_SYN)
	return scXJCMD_SC_ACTIVITYS_SYN;
    return 0;
}

XJCMD_CSC_ACTIVITY_COMMANDSC* packs::GetXJCMD_CSC_ACTIVITY_COMMANDSC()
{
    if (head.command == XJCMD_CSC_ACTIVITY_COMMAND)
	return scXJCMD_CSC_ACTIVITY_COMMAND;
    return 0;
}

XJCMD_SC_BATTLESC* packs::GetXJCMD_SC_BATTLESC()
{
    if (head.command == XJCMD_SC_BATTLE)
	return scXJCMD_SC_BATTLE;
    return 0;
}

XJCMD_CREATECHARSC* packs::GetXJCMD_CREATECHARSC()
{
    if (head.command == XJCMD_CREATECHAR)
	return scXJCMD_CREATECHAR;
    return 0;
}

XJCMD_DELETECHARSC* packs::GetXJCMD_DELETECHARSC()
{
    if (head.command == XJCMD_DELETECHAR)
	return scXJCMD_DELETECHAR;
    return 0;
}

XJCMD_CANCELDELETECHARSC* packs::GetXJCMD_CANCELDELETECHARSC()
{
    if (head.command == XJCMD_CANCELDELETECHAR)
	return scXJCMD_CANCELDELETECHAR;
    return 0;
}

XJCMD_CSC_CHATSC* packs::GetXJCMD_CSC_CHATSC()
{
    if (head.command == XJCMD_CSC_CHAT)
	return scXJCMD_CSC_CHAT;
    return 0;
}

XJCMD_SC_USERBAG_SYNSC* packs::GetXJCMD_SC_USERBAG_SYNSC()
{
    if (head.command == XJCMD_SC_USERBAG_SYN)
	return scXJCMD_SC_USERBAG_SYN;
    return 0;
}

XJCMD_SC_ITEMS_STATIC_SYNSC* packs::GetXJCMD_SC_ITEMS_STATIC_SYNSC()
{
    if (head.command == XJCMD_SC_ITEMS_STATIC_SYN)
	return scXJCMD_SC_ITEMS_STATIC_SYN;
    return 0;
}

XJCMD_SC_EQUIPS_DISCARD_SYNSC* packs::GetXJCMD_SC_EQUIPS_DISCARD_SYNSC()
{
    if (head.command == XJCMD_SC_EQUIPS_DISCARD_SYN)
	return scXJCMD_SC_EQUIPS_DISCARD_SYN;
    return 0;
}

XJCMD_CSC_ITEM_DETAILSC* packs::GetXJCMD_CSC_ITEM_DETAILSC()
{
    if (head.command == XJCMD_CSC_ITEM_DETAIL)
	return scXJCMD_CSC_ITEM_DETAIL;
    return 0;
}

XJCMD_CSC_CHAT_STORYSC* packs::GetXJCMD_CSC_CHAT_STORYSC()
{
    if (head.command == XJCMD_CSC_CHAT_STORY)
	return scXJCMD_CSC_CHAT_STORY;
    return 0;
}

XJCMD_CSC_ASK_DATESC* packs::GetXJCMD_CSC_ASK_DATESC()
{
    if (head.command == XJCMD_CSC_ASK_DATE)
	return scXJCMD_CSC_ASK_DATE;
    return 0;
}

XJCMD_CSC_GENERAL_PRESENTSC* packs::GetXJCMD_CSC_GENERAL_PRESENTSC()
{
    if (head.command == XJCMD_CSC_GENERAL_PRESENT)
	return scXJCMD_CSC_GENERAL_PRESENT;
    return 0;
}

XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPSC* packs::GetXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPSC()
{
    if (head.command == XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP)
	return scXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP;
    return 0;
}

XJCMD_CSC_PRESENT_SHOPSC* packs::GetXJCMD_CSC_PRESENT_SHOPSC()
{
    if (head.command == XJCMD_CSC_PRESENT_SHOP)
	return scXJCMD_CSC_PRESENT_SHOP;
    return 0;
}

XJCMD_SC_EMOTION_SYNCSC* packs::GetXJCMD_SC_EMOTION_SYNCSC()
{
    if (head.command == XJCMD_SC_EMOTION_SYNC)
	return scXJCMD_SC_EMOTION_SYNC;
    return 0;
}

XJCMD_CSC_USEREXPLORE_SYNSC* packs::GetXJCMD_CSC_USEREXPLORE_SYNSC()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_SYN)
	return scXJCMD_CSC_USEREXPLORE_SYN;
    return 0;
}

XJCMD_CSC_USEREXPLORE_FULLDATASC* packs::GetXJCMD_CSC_USEREXPLORE_FULLDATASC()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_FULLDATA)
	return scXJCMD_CSC_USEREXPLORE_FULLDATA;
    return 0;
}

XJCMD_CSC_USEREXPLORE_RES_SYNSC* packs::GetXJCMD_CSC_USEREXPLORE_RES_SYNSC()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_RES_SYN)
	return scXJCMD_CSC_USEREXPLORE_RES_SYN;
    return 0;
}

XJCMD_CSC_USEREXPLORE_SYN_BATCHSC* packs::GetXJCMD_CSC_USEREXPLORE_SYN_BATCHSC()
{
    if (head.command == XJCMD_CSC_USEREXPLORE_SYN_BATCH)
	return scXJCMD_CSC_USEREXPLORE_SYN_BATCH;
    return 0;
}

XJCMD_CSC_FRIENDINFO_LISTSC* packs::GetXJCMD_CSC_FRIENDINFO_LISTSC()
{
    if (head.command == XJCMD_CSC_FRIENDINFO_LIST)
	return scXJCMD_CSC_FRIENDINFO_LIST;
    return 0;
}

XJCMD_CSC_FRIENDEVENT_LISTSC* packs::GetXJCMD_CSC_FRIENDEVENT_LISTSC()
{
    if (head.command == XJCMD_CSC_FRIENDEVENT_LIST)
	return scXJCMD_CSC_FRIENDEVENT_LIST;
    return 0;
}

XJCMD_CSC_FRIEND_NEWSC* packs::GetXJCMD_CSC_FRIEND_NEWSC()
{
    if (head.command == XJCMD_CSC_FRIEND_NEW)
	return scXJCMD_CSC_FRIEND_NEW;
    return 0;
}

XJCMD_CSC_FRIEND_OPSC* packs::GetXJCMD_CSC_FRIEND_OPSC()
{
    if (head.command == XJCMD_CSC_FRIEND_OP)
	return scXJCMD_CSC_FRIEND_OP;
    return 0;
}

XJCMD_CSC_FRIEND_PRESENTLISTSC* packs::GetXJCMD_CSC_FRIEND_PRESENTLISTSC()
{
    if (head.command == XJCMD_CSC_FRIEND_PRESENTLIST)
	return scXJCMD_CSC_FRIEND_PRESENTLIST;
    return 0;
}

XJCMD_CSC_FRIEND_GET_PRESENTSC* packs::GetXJCMD_CSC_FRIEND_GET_PRESENTSC()
{
    if (head.command == XJCMD_CSC_FRIEND_GET_PRESENT)
	return scXJCMD_CSC_FRIEND_GET_PRESENT;
    return 0;
}

XJCMD_SC_USERGENERAL_FULLDATASC* packs::GetXJCMD_SC_USERGENERAL_FULLDATASC()
{
    if (head.command == XJCMD_SC_USERGENERAL_FULLDATA)
	return scXJCMD_SC_USERGENERAL_FULLDATA;
    return 0;
}

XJCMD_SC_USERGENERAL_BATTLEARRAYSC* packs::GetXJCMD_SC_USERGENERAL_BATTLEARRAYSC()
{
    if (head.command == XJCMD_SC_USERGENERAL_BATTLEARRAY)
	return scXJCMD_SC_USERGENERAL_BATTLEARRAY;
    return 0;
}

XJCMD_SC_USERGENERAL_RES_SYNSC* packs::GetXJCMD_SC_USERGENERAL_RES_SYNSC()
{
    if (head.command == XJCMD_SC_USERGENERAL_RES_SYN)
	return scXJCMD_SC_USERGENERAL_RES_SYN;
    return 0;
}

XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC* packs::GetXJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC()
{
    if (head.command == XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET)
	return scXJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET;
    return 0;
}

XJCMD_CSC_SUMMON_GENERALSC* packs::GetXJCMD_CSC_SUMMON_GENERALSC()
{
    if (head.command == XJCMD_CSC_SUMMON_GENERAL)
	return scXJCMD_CSC_SUMMON_GENERAL;
    return 0;
}

XJCMD_CSC_GENERAL_PRACTICESC* packs::GetXJCMD_CSC_GENERAL_PRACTICESC()
{
    if (head.command == XJCMD_CSC_GENERAL_PRACTICE)
	return scXJCMD_CSC_GENERAL_PRACTICE;
    return 0;
}

XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC* packs::GetXJCMD_CSC_GENERAL_PRACTICE_REBUILDSC()
{
    if (head.command == XJCMD_CSC_GENERAL_PRACTICE_REBUILD)
	return scXJCMD_CSC_GENERAL_PRACTICE_REBUILD;
    return 0;
}

XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC* packs::GetXJCMD_CSC_GENERAL_ADD_ADDITION_FATESC()
{
    if (head.command == XJCMD_CSC_GENERAL_ADD_ADDITION_FATE)
	return scXJCMD_CSC_GENERAL_ADD_ADDITION_FATE;
    return 0;
}

XJCMD_CSC_TRAININGSC* packs::GetXJCMD_CSC_TRAININGSC()
{
    if (head.command == XJCMD_CSC_TRAINING)
	return scXJCMD_CSC_TRAINING;
    return 0;
}

XJCMD_CSC_TRAINING_CONFIRMSC* packs::GetXJCMD_CSC_TRAINING_CONFIRMSC()
{
    if (head.command == XJCMD_CSC_TRAINING_CONFIRM)
	return scXJCMD_CSC_TRAINING_CONFIRM;
    return 0;
}

XJCMD_CSC_KUNGFU_TRANSMITSC* packs::GetXJCMD_CSC_KUNGFU_TRANSMITSC()
{
    if (head.command == XJCMD_CSC_KUNGFU_TRANSMIT)
	return scXJCMD_CSC_KUNGFU_TRANSMIT;
    return 0;
}

XJCMD_CSC_CARDLOTTERY_DRAWSC* packs::GetXJCMD_CSC_CARDLOTTERY_DRAWSC()
{
    if (head.command == XJCMD_CSC_CARDLOTTERY_DRAW)
	return scXJCMD_CSC_CARDLOTTERY_DRAW;
    return 0;
}

XJCMD_CSC_CARDLOTTERY_10_DRAWSC* packs::GetXJCMD_CSC_CARDLOTTERY_10_DRAWSC()
{
    if (head.command == XJCMD_CSC_CARDLOTTERY_10_DRAW)
	return scXJCMD_CSC_CARDLOTTERY_10_DRAW;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_DETAILSC* packs::GetXJCMD_CSC_GENERALTRAVEL_DETAILSC()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_DETAIL)
	return scXJCMD_CSC_GENERALTRAVEL_DETAIL;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_USEMONEYSC* packs::GetXJCMD_CSC_GENERALTRAVEL_USEMONEYSC()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_USEMONEY)
	return scXJCMD_CSC_GENERALTRAVEL_USEMONEY;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_BEGINSC* packs::GetXJCMD_CSC_GENERALTRAVEL_BEGINSC()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_BEGIN)
	return scXJCMD_CSC_GENERALTRAVEL_BEGIN;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_GETREWARDSC* packs::GetXJCMD_CSC_GENERALTRAVEL_GETREWARDSC()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_GETREWARD)
	return scXJCMD_CSC_GENERALTRAVEL_GETREWARD;
    return 0;
}

XJCMD_CSC_GENERALTRAVEL_FATELISTSC* packs::GetXJCMD_CSC_GENERALTRAVEL_FATELISTSC()
{
    if (head.command == XJCMD_CSC_GENERALTRAVEL_FATELIST)
	return scXJCMD_CSC_GENERALTRAVEL_FATELIST;
    return 0;
}

XJCMD_CSC_ITEM_OPERSC* packs::GetXJCMD_CSC_ITEM_OPERSC()
{
    if (head.command == XJCMD_CSC_ITEM_OPER)
	return scXJCMD_CSC_ITEM_OPER;
    return 0;
}

XJCMD_CSC_ITEM_2_EXPSC* packs::GetXJCMD_CSC_ITEM_2_EXPSC()
{
    if (head.command == XJCMD_CSC_ITEM_2_EXP)
	return scXJCMD_CSC_ITEM_2_EXP;
    return 0;
}

XJCMD_S2CH_RESETSC* packs::GetXJCMD_S2CH_RESETSC()
{
    if (head.command == XJCMD_S2CH_RESET)
	return scXJCMD_S2CH_RESET;
    return 0;
}

XJCMD_S2CH_KICKSC* packs::GetXJCMD_S2CH_KICKSC()
{
    if (head.command == XJCMD_S2CH_KICK)
	return scXJCMD_S2CH_KICK;
    return 0;
}

XJCMD_CSC_VERSIONSC* packs::GetXJCMD_CSC_VERSIONSC()
{
    if (head.command == XJCMD_CSC_VERSION)
	return scXJCMD_CSC_VERSION;
    return 0;
}

XJCMD_SC_ENTERGAME_FINISHSC* packs::GetXJCMD_SC_ENTERGAME_FINISHSC()
{
    if (head.command == XJCMD_SC_ENTERGAME_FINISH)
	return scXJCMD_SC_ENTERGAME_FINISH;
    return 0;
}

XJCMD_CSC_LOGINSC* packs::GetXJCMD_CSC_LOGINSC()
{
    if (head.command == XJCMD_CSC_LOGIN)
	return scXJCMD_CSC_LOGIN;
    return 0;
}

XJCMD_CSC_GSDISPATCHSC* packs::GetXJCMD_CSC_GSDISPATCHSC()
{
    if (head.command == XJCMD_CSC_GSDISPATCH)
	return scXJCMD_CSC_GSDISPATCH;
    return 0;
}

XJCMD_CSC_GSLOGINSC* packs::GetXJCMD_CSC_GSLOGINSC()
{
    if (head.command == XJCMD_CSC_GSLOGIN)
	return scXJCMD_CSC_GSLOGIN;
    return 0;
}

XJCMD_CSC_MAIL_LISTSC* packs::GetXJCMD_CSC_MAIL_LISTSC()
{
    if (head.command == XJCMD_CSC_MAIL_LIST)
	return scXJCMD_CSC_MAIL_LIST;
    return 0;
}

XJCMD_CSC_MAIL_DETAILSC* packs::GetXJCMD_CSC_MAIL_DETAILSC()
{
    if (head.command == XJCMD_CSC_MAIL_DETAIL)
	return scXJCMD_CSC_MAIL_DETAIL;
    return 0;
}

XJCMD_CSC_MAIL_SENDSC* packs::GetXJCMD_CSC_MAIL_SENDSC()
{
    if (head.command == XJCMD_CSC_MAIL_SEND)
	return scXJCMD_CSC_MAIL_SEND;
    return 0;
}

XJCMD_CSC_MAIL_DELETESC* packs::GetXJCMD_CSC_MAIL_DELETESC()
{
    if (head.command == XJCMD_CSC_MAIL_DELETE)
	return scXJCMD_CSC_MAIL_DELETE;
    return 0;
}

XJCMD_CSC_MAIL_GET_ATTACHSC* packs::GetXJCMD_CSC_MAIL_GET_ATTACHSC()
{
    if (head.command == XJCMD_CSC_MAIL_GET_ATTACH)
	return scXJCMD_CSC_MAIL_GET_ATTACH;
    return 0;
}

XJCMD_CSC_SYSTEM_NOTICESC* packs::GetXJCMD_CSC_SYSTEM_NOTICESC()
{
    if (head.command == XJCMD_CSC_SYSTEM_NOTICE)
	return scXJCMD_CSC_SYSTEM_NOTICE;
    return 0;
}

XJCMD_CSC_PINJIAN_OPENSC* packs::GetXJCMD_CSC_PINJIAN_OPENSC()
{
    if (head.command == XJCMD_CSC_PINJIAN_OPEN)
	return scXJCMD_CSC_PINJIAN_OPEN;
    return 0;
}

XJCMD_CSC_PINJIAN_TOPLISTSC* packs::GetXJCMD_CSC_PINJIAN_TOPLISTSC()
{
    if (head.command == XJCMD_CSC_PINJIAN_TOPLIST)
	return scXJCMD_CSC_PINJIAN_TOPLIST;
    return 0;
}

XJCMD_CSC_RESOURCE_SYNSC* packs::GetXJCMD_CSC_RESOURCE_SYNSC()
{
    if (head.command == XJCMD_CSC_RESOURCE_SYN)
	return scXJCMD_CSC_RESOURCE_SYN;
    return 0;
}

XJCMD_SC_SENARIO_SYNSC* packs::GetXJCMD_SC_SENARIO_SYNSC()
{
    if (head.command == XJCMD_SC_SENARIO_SYN)
	return scXJCMD_SC_SENARIO_SYN;
    return 0;
}

XJCMD_CSC_SKILL_DATASC* packs::GetXJCMD_CSC_SKILL_DATASC()
{
    if (head.command == XJCMD_CSC_SKILL_DATA)
	return scXJCMD_CSC_SKILL_DATA;
    return 0;
}

XJCMD_SC_RET_SKILL_LEVELUPSC* packs::GetXJCMD_SC_RET_SKILL_LEVELUPSC()
{
    if (head.command == XJCMD_SC_RET_SKILL_LEVELUP)
	return scXJCMD_SC_RET_SKILL_LEVELUP;
    return 0;
}

XJCMD_SC_SYSTEM_DIALOGSC* packs::GetXJCMD_SC_SYSTEM_DIALOGSC()
{
    if (head.command == XJCMD_SC_SYSTEM_DIALOG)
	return scXJCMD_SC_SYSTEM_DIALOG;
    return 0;
}

XJCMD_SC_SYSTEM_TIPSC* packs::GetXJCMD_SC_SYSTEM_TIPSC()
{
    if (head.command == XJCMD_SC_SYSTEM_TIP)
	return scXJCMD_SC_SYSTEM_TIP;
    return 0;
}

XJCMD_SC_AWARD_TIPSC* packs::GetXJCMD_SC_AWARD_TIPSC()
{
    if (head.command == XJCMD_SC_AWARD_TIP)
	return scXJCMD_SC_AWARD_TIP;
    return 0;
}

XJCMD_SC_HIGHLIGHT_TIPSC* packs::GetXJCMD_SC_HIGHLIGHT_TIPSC()
{
    if (head.command == XJCMD_SC_HIGHLIGHT_TIP)
	return scXJCMD_SC_HIGHLIGHT_TIP;
    return 0;
}

XJCMD_QUERY_PROGRESSSC* packs::GetXJCMD_QUERY_PROGRESSSC()
{
    if (head.command == XJCMD_QUERY_PROGRESS)
	return scXJCMD_QUERY_PROGRESS;
    return 0;
}

XJCMD_LEVEL_STARTSC* packs::GetXJCMD_LEVEL_STARTSC()
{
    if (head.command == XJCMD_LEVEL_START)
	return scXJCMD_LEVEL_START;
    return 0;
}

XJCMD_LEVEL_NEXTSC* packs::GetXJCMD_LEVEL_NEXTSC()
{
    if (head.command == XJCMD_LEVEL_NEXT)
	return scXJCMD_LEVEL_NEXT;
    return 0;
}

XJCMD_PROCESS_EVENTSC* packs::GetXJCMD_PROCESS_EVENTSC()
{
    if (head.command == XJCMD_PROCESS_EVENT)
	return scXJCMD_PROCESS_EVENT;
    return 0;
}

XJCMD_SC_TESTSC* packs::GetXJCMD_SC_TESTSC()
{
    if (head.command == XJCMD_SC_TEST)
	return scXJCMD_SC_TEST;
    return 0;
}

XJCMD_CSC_TITLE_ADDSC* packs::GetXJCMD_CSC_TITLE_ADDSC()
{
    if (head.command == XJCMD_CSC_TITLE_ADD)
	return scXJCMD_CSC_TITLE_ADD;
    return 0;
}

XJCMD_SC_TITLE_STATE_LIST_SYNSC* packs::GetXJCMD_SC_TITLE_STATE_LIST_SYNSC()
{
    if (head.command == XJCMD_SC_TITLE_STATE_LIST_SYN)
	return scXJCMD_SC_TITLE_STATE_LIST_SYN;
    return 0;
}

XJCMD_CSC_USERINFO_SYNSC* packs::GetXJCMD_CSC_USERINFO_SYNSC()
{
    if (head.command == XJCMD_CSC_USERINFO_SYN)
	return scXJCMD_CSC_USERINFO_SYN;
    return 0;
}

XJCMD_CSC_CHANGEFACESC* packs::GetXJCMD_CSC_CHANGEFACESC()
{
    if (head.command == XJCMD_CSC_CHANGEFACE)
	return scXJCMD_CSC_CHANGEFACE;
    return 0;
}

XJCMD_CSC_ENCHANTMENT_ARTIFICESC* packs::GetXJCMD_CSC_ENCHANTMENT_ARTIFICESC()
{
    if (head.command == XJCMD_CSC_ENCHANTMENT_ARTIFICE)
	return scXJCMD_CSC_ENCHANTMENT_ARTIFICE;
    return 0;
}

XJCMD_CSC_ENCHANTMENT_LEVELUPSC* packs::GetXJCMD_CSC_ENCHANTMENT_LEVELUPSC()
{
    if (head.command == XJCMD_CSC_ENCHANTMENT_LEVELUP)
	return scXJCMD_CSC_ENCHANTMENT_LEVELUP;
    return 0;
}

packs::packs() {}
packs::~packs() {}

bool packs::Init(int cmd, void* body)
{
    if (!body)
	return false;

    head.command = cmd;
    aBody = body;
    bool ret = true;

    switch (head.command) {
            case XJCMD_SC_ACTIVITYS_SYN:
	        scXJCMD_SC_ACTIVITYS_SYN = new (aBody) XJCMD_SC_ACTIVITYS_SYNSC;
	        break;
        case XJCMD_CSC_ACTIVITY_COMMAND:
	        scXJCMD_CSC_ACTIVITY_COMMAND = new (aBody) XJCMD_CSC_ACTIVITY_COMMANDSC;
	        break;
        case XJCMD_SC_BATTLE:
	        scXJCMD_SC_BATTLE = new (aBody) XJCMD_SC_BATTLESC;
	        break;
        case XJCMD_CREATECHAR:
	        scXJCMD_CREATECHAR = new (aBody) XJCMD_CREATECHARSC;
	        break;
        case XJCMD_DELETECHAR:
	        scXJCMD_DELETECHAR = new (aBody) XJCMD_DELETECHARSC;
	        break;
        case XJCMD_CANCELDELETECHAR:
	        scXJCMD_CANCELDELETECHAR = new (aBody) XJCMD_CANCELDELETECHARSC;
	        break;
        case XJCMD_CSC_CHAT:
	        scXJCMD_CSC_CHAT = new (aBody) XJCMD_CSC_CHATSC;
	        break;
        case XJCMD_SC_USERBAG_SYN:
	        scXJCMD_SC_USERBAG_SYN = new (aBody) XJCMD_SC_USERBAG_SYNSC;
	        break;
        case XJCMD_SC_ITEMS_STATIC_SYN:
	        scXJCMD_SC_ITEMS_STATIC_SYN = new (aBody) XJCMD_SC_ITEMS_STATIC_SYNSC;
	        break;
        case XJCMD_SC_EQUIPS_DISCARD_SYN:
	        scXJCMD_SC_EQUIPS_DISCARD_SYN = new (aBody) XJCMD_SC_EQUIPS_DISCARD_SYNSC;
	        break;
        case XJCMD_CSC_ITEM_DETAIL:
	        scXJCMD_CSC_ITEM_DETAIL = new (aBody) XJCMD_CSC_ITEM_DETAILSC;
	        break;
        case XJCMD_CSC_CHAT_STORY:
	        scXJCMD_CSC_CHAT_STORY = new (aBody) XJCMD_CSC_CHAT_STORYSC;
	        break;
        case XJCMD_CSC_ASK_DATE:
	        scXJCMD_CSC_ASK_DATE = new (aBody) XJCMD_CSC_ASK_DATESC;
	        break;
        case XJCMD_CSC_GENERAL_PRESENT:
	        scXJCMD_CSC_GENERAL_PRESENT = new (aBody) XJCMD_CSC_GENERAL_PRESENTSC;
	        break;
        case XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP:
	        scXJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP = new (aBody) XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UPSC;
	        break;
        case XJCMD_CSC_PRESENT_SHOP:
	        scXJCMD_CSC_PRESENT_SHOP = new (aBody) XJCMD_CSC_PRESENT_SHOPSC;
	        break;
        case XJCMD_SC_EMOTION_SYNC:
	        scXJCMD_SC_EMOTION_SYNC = new (aBody) XJCMD_SC_EMOTION_SYNCSC;
	        break;
        case XJCMD_CSC_USEREXPLORE_SYN:
	        scXJCMD_CSC_USEREXPLORE_SYN = new (aBody) XJCMD_CSC_USEREXPLORE_SYNSC;
	        break;
        case XJCMD_CSC_USEREXPLORE_FULLDATA:
	        scXJCMD_CSC_USEREXPLORE_FULLDATA = new (aBody) XJCMD_CSC_USEREXPLORE_FULLDATASC;
	        break;
        case XJCMD_CSC_USEREXPLORE_RES_SYN:
	        scXJCMD_CSC_USEREXPLORE_RES_SYN = new (aBody) XJCMD_CSC_USEREXPLORE_RES_SYNSC;
	        break;
        case XJCMD_CSC_USEREXPLORE_SYN_BATCH:
	        scXJCMD_CSC_USEREXPLORE_SYN_BATCH = new (aBody) XJCMD_CSC_USEREXPLORE_SYN_BATCHSC;
	        break;
        case XJCMD_CSC_FRIENDINFO_LIST:
	        scXJCMD_CSC_FRIENDINFO_LIST = new (aBody) XJCMD_CSC_FRIENDINFO_LISTSC;
	        break;
        case XJCMD_CSC_FRIENDEVENT_LIST:
	        scXJCMD_CSC_FRIENDEVENT_LIST = new (aBody) XJCMD_CSC_FRIENDEVENT_LISTSC;
	        break;
        case XJCMD_CSC_FRIEND_NEW:
	        scXJCMD_CSC_FRIEND_NEW = new (aBody) XJCMD_CSC_FRIEND_NEWSC;
	        break;
        case XJCMD_CSC_FRIEND_OP:
	        scXJCMD_CSC_FRIEND_OP = new (aBody) XJCMD_CSC_FRIEND_OPSC;
	        break;
        case XJCMD_CSC_FRIEND_PRESENTLIST:
	        scXJCMD_CSC_FRIEND_PRESENTLIST = new (aBody) XJCMD_CSC_FRIEND_PRESENTLISTSC;
	        break;
        case XJCMD_CSC_FRIEND_GET_PRESENT:
	        scXJCMD_CSC_FRIEND_GET_PRESENT = new (aBody) XJCMD_CSC_FRIEND_GET_PRESENTSC;
	        break;
        case XJCMD_SC_USERGENERAL_FULLDATA:
	        scXJCMD_SC_USERGENERAL_FULLDATA = new (aBody) XJCMD_SC_USERGENERAL_FULLDATASC;
	        break;
        case XJCMD_SC_USERGENERAL_BATTLEARRAY:
	        scXJCMD_SC_USERGENERAL_BATTLEARRAY = new (aBody) XJCMD_SC_USERGENERAL_BATTLEARRAYSC;
	        break;
        case XJCMD_SC_USERGENERAL_RES_SYN:
	        scXJCMD_SC_USERGENERAL_RES_SYN = new (aBody) XJCMD_SC_USERGENERAL_RES_SYNSC;
	        break;
        case XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET:
	        scXJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET = new (aBody) XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RETSC;
	        break;
        case XJCMD_CSC_SUMMON_GENERAL:
	        scXJCMD_CSC_SUMMON_GENERAL = new (aBody) XJCMD_CSC_SUMMON_GENERALSC;
	        break;
        case XJCMD_CSC_GENERAL_PRACTICE:
	        scXJCMD_CSC_GENERAL_PRACTICE = new (aBody) XJCMD_CSC_GENERAL_PRACTICESC;
	        break;
        case XJCMD_CSC_GENERAL_PRACTICE_REBUILD:
	        scXJCMD_CSC_GENERAL_PRACTICE_REBUILD = new (aBody) XJCMD_CSC_GENERAL_PRACTICE_REBUILDSC;
	        break;
        case XJCMD_CSC_GENERAL_ADD_ADDITION_FATE:
	        scXJCMD_CSC_GENERAL_ADD_ADDITION_FATE = new (aBody) XJCMD_CSC_GENERAL_ADD_ADDITION_FATESC;
	        break;
        case XJCMD_CSC_TRAINING:
	        scXJCMD_CSC_TRAINING = new (aBody) XJCMD_CSC_TRAININGSC;
	        break;
        case XJCMD_CSC_TRAINING_CONFIRM:
	        scXJCMD_CSC_TRAINING_CONFIRM = new (aBody) XJCMD_CSC_TRAINING_CONFIRMSC;
	        break;
        case XJCMD_CSC_KUNGFU_TRANSMIT:
	        scXJCMD_CSC_KUNGFU_TRANSMIT = new (aBody) XJCMD_CSC_KUNGFU_TRANSMITSC;
	        break;
        case XJCMD_CSC_CARDLOTTERY_DRAW:
	        scXJCMD_CSC_CARDLOTTERY_DRAW = new (aBody) XJCMD_CSC_CARDLOTTERY_DRAWSC;
	        break;
        case XJCMD_CSC_CARDLOTTERY_10_DRAW:
	        scXJCMD_CSC_CARDLOTTERY_10_DRAW = new (aBody) XJCMD_CSC_CARDLOTTERY_10_DRAWSC;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_DETAIL:
	        scXJCMD_CSC_GENERALTRAVEL_DETAIL = new (aBody) XJCMD_CSC_GENERALTRAVEL_DETAILSC;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_USEMONEY:
	        scXJCMD_CSC_GENERALTRAVEL_USEMONEY = new (aBody) XJCMD_CSC_GENERALTRAVEL_USEMONEYSC;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_BEGIN:
	        scXJCMD_CSC_GENERALTRAVEL_BEGIN = new (aBody) XJCMD_CSC_GENERALTRAVEL_BEGINSC;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_GETREWARD:
	        scXJCMD_CSC_GENERALTRAVEL_GETREWARD = new (aBody) XJCMD_CSC_GENERALTRAVEL_GETREWARDSC;
	        break;
        case XJCMD_CSC_GENERALTRAVEL_FATELIST:
	        scXJCMD_CSC_GENERALTRAVEL_FATELIST = new (aBody) XJCMD_CSC_GENERALTRAVEL_FATELISTSC;
	        break;
        case XJCMD_CSC_ITEM_OPER:
	        scXJCMD_CSC_ITEM_OPER = new (aBody) XJCMD_CSC_ITEM_OPERSC;
	        break;
        case XJCMD_CSC_ITEM_2_EXP:
	        scXJCMD_CSC_ITEM_2_EXP = new (aBody) XJCMD_CSC_ITEM_2_EXPSC;
	        break;
        case XJCMD_S2CH_RESET:
	        scXJCMD_S2CH_RESET = new (aBody) XJCMD_S2CH_RESETSC;
	        break;
        case XJCMD_S2CH_KICK:
	        scXJCMD_S2CH_KICK = new (aBody) XJCMD_S2CH_KICKSC;
	        break;
        case XJCMD_CSC_VERSION:
	        scXJCMD_CSC_VERSION = new (aBody) XJCMD_CSC_VERSIONSC;
	        break;
        case XJCMD_SC_ENTERGAME_FINISH:
	        scXJCMD_SC_ENTERGAME_FINISH = new (aBody) XJCMD_SC_ENTERGAME_FINISHSC;
	        break;
        case XJCMD_CSC_LOGIN:
	        scXJCMD_CSC_LOGIN = new (aBody) XJCMD_CSC_LOGINSC;
	        break;
        case XJCMD_CSC_GSDISPATCH:
	        scXJCMD_CSC_GSDISPATCH = new (aBody) XJCMD_CSC_GSDISPATCHSC;
	        break;
        case XJCMD_CSC_GSLOGIN:
	        scXJCMD_CSC_GSLOGIN = new (aBody) XJCMD_CSC_GSLOGINSC;
	        break;
        case XJCMD_CSC_MAIL_LIST:
	        scXJCMD_CSC_MAIL_LIST = new (aBody) XJCMD_CSC_MAIL_LISTSC;
	        break;
        case XJCMD_CSC_MAIL_DETAIL:
	        scXJCMD_CSC_MAIL_DETAIL = new (aBody) XJCMD_CSC_MAIL_DETAILSC;
	        break;
        case XJCMD_CSC_MAIL_SEND:
	        scXJCMD_CSC_MAIL_SEND = new (aBody) XJCMD_CSC_MAIL_SENDSC;
	        break;
        case XJCMD_CSC_MAIL_DELETE:
	        scXJCMD_CSC_MAIL_DELETE = new (aBody) XJCMD_CSC_MAIL_DELETESC;
	        break;
        case XJCMD_CSC_MAIL_GET_ATTACH:
	        scXJCMD_CSC_MAIL_GET_ATTACH = new (aBody) XJCMD_CSC_MAIL_GET_ATTACHSC;
	        break;
        case XJCMD_CSC_SYSTEM_NOTICE:
	        scXJCMD_CSC_SYSTEM_NOTICE = new (aBody) XJCMD_CSC_SYSTEM_NOTICESC;
	        break;
        case XJCMD_CSC_PINJIAN_OPEN:
	        scXJCMD_CSC_PINJIAN_OPEN = new (aBody) XJCMD_CSC_PINJIAN_OPENSC;
	        break;
        case XJCMD_CSC_PINJIAN_TOPLIST:
	        scXJCMD_CSC_PINJIAN_TOPLIST = new (aBody) XJCMD_CSC_PINJIAN_TOPLISTSC;
	        break;
        case XJCMD_CSC_RESOURCE_SYN:
	        scXJCMD_CSC_RESOURCE_SYN = new (aBody) XJCMD_CSC_RESOURCE_SYNSC;
	        break;
        case XJCMD_SC_SENARIO_SYN:
	        scXJCMD_SC_SENARIO_SYN = new (aBody) XJCMD_SC_SENARIO_SYNSC;
	        break;
        case XJCMD_CSC_SKILL_DATA:
	        scXJCMD_CSC_SKILL_DATA = new (aBody) XJCMD_CSC_SKILL_DATASC;
	        break;
        case XJCMD_SC_RET_SKILL_LEVELUP:
	        scXJCMD_SC_RET_SKILL_LEVELUP = new (aBody) XJCMD_SC_RET_SKILL_LEVELUPSC;
	        break;
        case XJCMD_SC_SYSTEM_DIALOG:
	        scXJCMD_SC_SYSTEM_DIALOG = new (aBody) XJCMD_SC_SYSTEM_DIALOGSC;
	        break;
        case XJCMD_SC_SYSTEM_TIP:
	        scXJCMD_SC_SYSTEM_TIP = new (aBody) XJCMD_SC_SYSTEM_TIPSC;
	        break;
        case XJCMD_SC_AWARD_TIP:
	        scXJCMD_SC_AWARD_TIP = new (aBody) XJCMD_SC_AWARD_TIPSC;
	        break;
        case XJCMD_SC_HIGHLIGHT_TIP:
	        scXJCMD_SC_HIGHLIGHT_TIP = new (aBody) XJCMD_SC_HIGHLIGHT_TIPSC;
	        break;
        case XJCMD_QUERY_PROGRESS:
	        scXJCMD_QUERY_PROGRESS = new (aBody) XJCMD_QUERY_PROGRESSSC;
	        break;
        case XJCMD_LEVEL_START:
	        scXJCMD_LEVEL_START = new (aBody) XJCMD_LEVEL_STARTSC;
	        break;
        case XJCMD_LEVEL_NEXT:
	        scXJCMD_LEVEL_NEXT = new (aBody) XJCMD_LEVEL_NEXTSC;
	        break;
        case XJCMD_PROCESS_EVENT:
	        scXJCMD_PROCESS_EVENT = new (aBody) XJCMD_PROCESS_EVENTSC;
	        break;
        case XJCMD_SC_TEST:
	        scXJCMD_SC_TEST = new (aBody) XJCMD_SC_TESTSC;
	        break;
        case XJCMD_CSC_TITLE_ADD:
	        scXJCMD_CSC_TITLE_ADD = new (aBody) XJCMD_CSC_TITLE_ADDSC;
	        break;
        case XJCMD_SC_TITLE_STATE_LIST_SYN:
	        scXJCMD_SC_TITLE_STATE_LIST_SYN = new (aBody) XJCMD_SC_TITLE_STATE_LIST_SYNSC;
	        break;
        case XJCMD_CSC_USERINFO_SYN:
	        scXJCMD_CSC_USERINFO_SYN = new (aBody) XJCMD_CSC_USERINFO_SYNSC;
	        break;
        case XJCMD_CSC_CHANGEFACE:
	        scXJCMD_CSC_CHANGEFACE = new (aBody) XJCMD_CSC_CHANGEFACESC;
	        break;
        case XJCMD_CSC_ENCHANTMENT_ARTIFICE:
	        scXJCMD_CSC_ENCHANTMENT_ARTIFICE = new (aBody) XJCMD_CSC_ENCHANTMENT_ARTIFICESC;
	        break;
        case XJCMD_CSC_ENCHANTMENT_LEVELUP:
	        scXJCMD_CSC_ENCHANTMENT_LEVELUP = new (aBody) XJCMD_CSC_ENCHANTMENT_LEVELUPSC;
	        break;
        default:
                packbody = 0;
                break;
        }


    return ret;
}

void CProto::packs::SetDefault()
{
packbody = 0;

}

};

