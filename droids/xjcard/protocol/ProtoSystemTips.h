/********************************************************************
 * This file is generated by program cap
 * Please do not change it directly
 * 
 * protocol name: CProto
 * protocol version: 1.0
 * protocol author:   
 * protocol desc: 仙剑卡牌客户端后台交互协议-控制协议
 *
 * history:
 * 2013-02-22 : 创建 (V1.0)
********************************************************************/

#include "ProtoSystemTipsDef.h"

#ifndef __ProtoSystemTips_H__ 
#define __ProtoSystemTips_H__ 

#include "CProto_Common.h"

#include "CProto.h"



namespace CProto {
/* 奖励信息结构 */
struct stAwardUnit {
public:
    void Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer, unsigned int& bufferlen) throw (DecodeError);

    stAwardUnit();
    void SetDefault();

/* 奖励类型（eSystemAwardType） */
    char type;
/* 奖励额度 */
    int cnt;
/* 奖励项的ID */
    int id;
/* 奖励money时的type */
    char moneytype;

private:
    unsigned int arraysize;
};
/* 系统醒目提示消息信息结构体 */
struct stHighlightMsgUnit {
public:
    void Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer, unsigned int& bufferlen) throw (DecodeError);

    stHighlightMsgUnit();
    void SetDefault();

/* 消息类型（eSystemHighlightMsgType） */
    char type;
/* utf8编码的消息字符串（要保证是美术资源里面有的字符） */
    unsigned short msg_arraylen;	char msg[MAX_LEN_LARGE];

private:
    unsigned int arraysize;
};
class XJCMD_SC_SYSTEM_TIPSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_SC_SYSTEM_TIPSC();
    void SetDefault();

    
/* 消息显示类型 */
    eSystemTipShowEnum tipType;
/* 聊天频道类型，值为-1时不放入相应聊天频道 */
    eChatTypeEnum chatType;
/* 消息内容 */
    proto_string<0> tipContent;

private:
    unsigned int arraysize;
};
class XJCMD_SC_AWARD_TIPSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_SC_AWARD_TIPSC();
    void SetDefault();

    
/* 奖励信息数组 */
    unsigned char awarddata_arraylen;	stAwardUnit awarddata[255];

private:
    unsigned int arraysize;
};
class XJCMD_SC_HIGHLIGHT_TIPSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_SC_HIGHLIGHT_TIPSC();
    void SetDefault();

    
/* 系统醒目提示消息数组 */
    unsigned char msgs_arraylen;	stHighlightMsgUnit msgs[255];

private:
    unsigned int arraysize;
};
};


#endif

