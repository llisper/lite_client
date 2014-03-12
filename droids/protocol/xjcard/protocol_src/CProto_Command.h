#ifndef __CProto_COMMAND_H__ 
#define __CProto_COMMAND_H__ 

#include "CProto_Common.h"

namespace CProto {
	enum command {
		XJCMD_INVALID = -1, /* %Comment% */
		XJCMD_CH2S_CLOSE = 0, /* 客户端断线后Channel通知GameServer */
		XJCMD_S2CH_RESET = 1, /* GameServer重启后通知Channel重置 */
		XJCMD_S2CH_KICK = 2, /* GameServer通知Channel断开客户端连接 */
		XJCMD_S2CH_MAX = 99, /* 管理命令最大值 */
		XJCMD_SC_TEST = 100, /* 调试命令 */
		XJCMD_CSC_VERSION = 101, /* 版本检查登录检查协议 */
		XJCMD_CS_ENTERGAME_START = 102, /* 取消提示更新后进入游戏协议 */
		XJCMD_CREATECHAR = 103, /* 创建角色 */
		XJCMD_DELETECHAR = 104, /* 删除角色 */
		XJCMD_GET_CHAR = 105, /* 拉取角色 */
		XJCMD_SC_ENTERGAME_FINISH = 106, /* 数据同步完毕后进入游戏完成协议 */
		XJCMD_CANCELDELETECHAR = 108, /* 取消删除角色 */
		XJCMD_CSC_LOGIN = 110, /* 大区登陆协议 */
		XJCMD_CSC_GSLOGIN = 111, /* 大区登录GS协议 */
		XJCMD_CSC_GSDISPATCH = 112, /* 大区分配GS */
		XJCMD_CSC_USERINFO_SYN = 201, /* 请求主角信息 */
		XJCMD_CSC_CHANGEFACE = 202, /* 更换头像 */
		XJCMD_CSC_ENCHANTMENT_ARTIFICE = 203, /* 结界炼化 */
		XJCMD_CSC_ENCHANTMENT_LEVELUP = 204, /* 结界生层 */
		XJCMD_SC_ACTIVITYS_SYN = 205, /* 游历动态数据同步 */
		XJCMD_CSC_ACTIVITY_COMMAND = 206, /* 游历命令协议 */
		XJCMD_SC_USERBAG_SYN = 301, /* 主角背包信息 */
		XJCMD_CSC_ITEM_OPER = 302, /* 物品操作协议 */
		XJCMD_SC_ITEMS_STATIC_SYN = 303, /* 物品配置表数据 */
		XJCMD_CSC_TITLE_ADD = 304, /* 使用称号 */
		XJCMD_SC_TITLE_STATE_LIST_SYN = 305, /* 称号状态列表 */
		XJCMD_CSC_TITLE_USE = 306, /* 使用称号 */
		XJCMD_CSC_ITEM_DETAIL = 307, /* 他人物品动态数据获取 */
		XJCMD_CSC_SKILL_DATA = 308, /* 技能动态数据 */
		XJCMD_CSC_RESOURCE_SYN = 310, /* 静态数据同步 */
		XJCMD_CS_ASK_SKILL_LEVELUP = 311, /* 技能升级 */
		XJCMD_SC_RET_SKILL_LEVELUP = 312, /* 技能升级回复 */
		XJCMD_CSC_ITEM_2_EXP = 313, /* 经验道具 */
		XJCMD_SC_BATTLE = 401, /* 战斗攻击序列包 */
		XJCMD_CSC_USEREXPLORE_SYN = 501, /* 角色探索同步数据 */
		XJCMD_CSC_USEREXPLORE_FULLDATA = 502, /* 角色探索全量数据 */
		XJCMD_CSC_USEREXPLORE_CHALLENGE = 503, /* 探索关卡挑战 */
		XJCMD_CSC_USEREXPLORE_SYN_BATCH = 504, /* 探索关卡批量同步 */
		XJCMD_CSC_USEREXPLORE_RES_SYN = 505, /* 角色探索静态资源同步数据 */
		XJCMD_CSC_USEREXPLORE_CHALLENGE_BAT = 506, /* 探索关卡扫荡 */
		XJCMD_SC_USERGENERAL_FULLDATA = 600, /* 角色武将信息 */
		XJCMD_SC_USERGENERAL_SYN = 601, /* 角色武将同步信息 */
		XJCMD_CSC_SUMMON_GENERAL = 602, /* 召唤武将 */
		XJCMD_SC_USERGENERAL_BATTLEARRAY = 603, /* 角色阵容信息 */
		XJCMD_SC_USERGENERAL_RES_SYN = 604, /* 角色静态数据同步 */
		XJCMD_CS_USERGENERAL_BATTLEARRAY_CHANGE = 605, /* 角色阵容变更 */
		XJCMD_SC_USERGENERAL_BATTLEARRAY_CHANGE_RET = 606, /* 角色阵容变更回复 */
		XJCMD_CSC_GENERAL_PRACTICE = 607, /* 武将修炼 */
		XJCMD_CSC_GENERAL_PRACTICE_REBUILD = 608, /* 武将重修 */
		XJCMD_CSC_GENERAL_ADD_ADDITION_FATE = 609, /* 武将赋缘 */
		XJCMD_CS_SKILL_ON = 610, /* 技能装备 */
		XJCMD_CS_BATTLEARR_ASSITPOS_OPEN = 611, /* 武将阵型援护位激活 */
		XJCMD_CSC_SENARIO_ENTER = 612, /* 进入场景 */
		XJCMD_SC_SENARIO_SYN = 613, /* 同步场景 */
		XJCMD_CSC_TRAINING = 614, /* %Comment% */
		XJCMD_CSC_TRAINING_CONFIRM = 615, /* %Comment% */
		XJCMD_CSC_KUNGFU_TRANSMIT = 616, /* %Comment% */
		XJCMD_CSC_CARDLOTTERY_DRAW = 617, /* %Comment% */
		XJCMD_CSC_CARDLOTTERY_10_DRAW = 618, /* %Comment% */
		XJCMD_CSC_FRIENDINFO_LIST = 700, /* 好友列表 */
		XJCMD_CSC_FRIENDEVENT_LIST = 702, /* 好友动态 */
		XJCMD_CSC_FRIEND_NEW = 703, /* 新朋友 */
		XJCMD_CSC_FRIEND_PRESENTLIST = 704, /* 朋友赠送 */
		XJCMD_CSC_FRIEND_OP = 705, /* 修改相关类型 */
		XJCMD_CSC_FRIEND_GET_PRESENT = 706, /* 领取好友赠送 */
		XJCMD_CSC_GENERALTRAVEL_DETAIL = 720, /* 武将云游详情 */
		XJCMD_CSC_GENERALTRAVEL_USEMONEY = 721, /* 使用金钱刷成功率 */
		XJCMD_CSC_GENERALTRAVEL_BEGIN = 722, /* 开始云游 */
		XJCMD_CSC_GENERALTRAVEL_GETREWARD = 723, /* 领取奖励 */
		XJCMD_CSC_GENERALTRAVEL_FATELIST = 724, /* 获取武将缘列表 */
		XJCMD_CSC_MAIL_LIST = 800, /* 邮件列表 */
		XJCMD_CSC_MAIL_DETAIL = 801, /* 邮件详情 */
		XJCMD_CSC_MAIL_SEND = 802, /* 发送邮件 */
		XJCMD_CSC_MAIL_DELETE = 803, /* 删除邮件 */
		XJCMD_CSC_MAIL_GET_ATTACH = 804, /* 获取邮件附件 */
		XJCMD_CSC_SYSTEM_NOTICE = 900, /* 公告 */
		XJCMD_SC_SYSTEM_TIP = 901, /* 系统提示 */
		XJCMD_SC_SYSTEM_DIALOG = 902, /* 系统弹框 */
		XJCMD_CS_SYSTEM_RECYCLECHECK = 903, /* 系统弹框类消息透传 */
		XJCMD_CSC_CHAT = 904, /* 聊天 */
		XJCMD_CSC_CARDTREE_REWARD = 905, /* 卡牌谱领取奖励 */
		XJCMD_SC_EQUIPS_DISCARD_SYN = 906, /* 丢弃过且不在背包中装备列表 */
		XJCMD_SC_AWARD_TIP = 907, /* 系统通用奖励消息 */
		XJCMD_SC_HIGHLIGHT_TIP = 908, /* 系统醒目提示消息 */
		XJCMD_CS_LOG = 909, /* 客户端日志上报 */
		XJCMD_CSC_CHAT_STORY = 930, /* 剧情闲聊奖励 */
		XJCMD_CSC_ASK_DATE = 931, /* 剧情邀约 */
		XJCMD_SC_EMOTION_SYNC = 932, /* 情感系统同步 */
		XJCMD_CSC_GENERAL_PRESENT = 933, /* 剧情赠送 */
		XJCMD_CSC_GENERAL_ADMIRE_LEVEL_UP = 934, /* 好感度升级可领奖 */
		XJCMD_CSC_PRESENT_SHOP = 935, /* 商城购买破阶道具 */
		XJCMD_CSC_PINJIAN_OPEN = 1000, /* 品剑大会主界面 */
		XJCMD_CSC_PINJIAN_FIGHT = 1001, /* 品剑大会比武 */
		XJCMD_CSC_PINJIAN_TOPLIST = 1002, /* 品剑大会武榜 */
		XJCMD_QUERY_PROGRESS = 1100, /* 查询锁妖塔进度 */
		XJCMD_LEVEL_START = 1101, /* 锁妖塔请求层事件列表 */
		XJCMD_LEVEL_NEXT = 1102, /* 锁妖塔请求层事件列表 */
		XJCMD_PROCESS_EVENT = 1103, /* 锁妖塔执行下一步骤 */
		XJCMD_MAXSIZE = 2000, /* 协议最大值+1 */
	};
};


#endif

