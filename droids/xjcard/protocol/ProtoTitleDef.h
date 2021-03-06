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


#ifndef __ProtoTitle_Def_H__
#define __ProtoTitle_Def_H__


namespace CProto {
enum { /* 客户端展示个数最大值 */
	MAX_TITLE_MUTEX_NUM = 100, /* 客户端展示个数（互斥类型）最大值 */
};

enum eTitleStateType { /* 称号状态类型 */
	TITLE_STATE_INVALID = 0, /* 称号未获得 */
	TITLE_STATE_HAS = 1, /* 称号已获得，未被使用 */
	TITLE_STATE_INUSE = 2, /* 称号已获得，使用中 */
	TITLE_STATE_EXPIRED = 3, /* 称号过期 */
};

enum eTitleTimeoutType { /* 称号时效类型 */
	TITLE_TIMEOUT_NEVER = 0, /* 永久有效 */
	TITLE_TIMEOUT_ABSOLUTE = 1, /* 绝对时间 */
	TITLE_TIMEOUT_RELATIVE = 2, /* 相对时间 */
};

enum eTitleRewardType { /* 称号奖励类型，0-18客户端显示数值，19-21显示百分比 */
	TITLE_REWARD_TYPE_INVALID = -1, /* 无效 */
	TITLE_REWARD_TYPE_HEALTH = 0, /* 体 */
	TITLE_REWARD_TYPE_ATTACK = 1, /* 攻 */
	TITLE_REWARD_TYPE_DEFENCE = 2, /* 防 */
	TITLE_REWARD_TYPE_SPIRIT = 3, /* 灵 */
	TITLE_REWARD_TYPE_SPEED = 4, /* 速 */
	TITLE_REWARD_TYPE_STRENGTH = 5, /* 武 */
	TITLE_REWARD_TYPE_THUNDER = 6, /* 雷 */
	TITLE_REWARD_TYPE_WIND = 7, /* 风 */
	TITLE_REWARD_TYPE_SOIL = 8, /* 木 */
	TITLE_REWARD_TYPE_WATER = 9, /* 水 */
	TITLE_REWARD_TYPE_FIRE = 10, /* 火 */
	TITLE_REWARD_TYPE_BAOJI = 11, /* 暴击 */
	TITLE_REWARD_TYPE_SHENJI = 12, /* 神击 */
	TITLE_REWARD_TYPE_NINGSHEN = 13, /* 凝神 */
	TITLE_REWARD_TYPE_GEDANG = 14, /* 格挡 */
	TITLE_REWARD_TYPE_YUTI = 15, /* 御体 */
	TITLE_REWARD_TYPE_YUSHEN = 16, /* 御神 */
	TITLE_REWARD_TYPE_LIANJI = 17, /* 连击 */
	TITLE_REWARD_TYPE_SHANBI = 18, /* 闪避 */
	TITLE_REWARD_TYPE_USEREXP = 19, /* 角色阅历 */
	TITLE_REWARD_TYPE_GENRLEXP = 20, /* 伙伴经验 */
	TITLE_REWARD_TYPE_YINLIANG = 21, /* 银两 */
};

};


#endif

