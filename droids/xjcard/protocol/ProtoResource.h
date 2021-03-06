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

#include "ProtoResourceDef.h"

#ifndef __ProtoResource_H__ 
#define __ProtoResource_H__ 

#include "CProto_Common.h"

#include "CProto.h"



namespace CProto {
class XJCMD_CSC_RESOURCE_SYNSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_CSC_RESOURCE_SYNSC();
    void SetDefault();

    
/* 静态数据类型 */
    unsigned char res_type;
/* 技能静态资源数据版本号 */
    int version_res;
/* 1全量，其他增量 */
    char full_flag;
/* 技能静态资源更新数据 */
    proto_vector<char> resdata;

private:
    unsigned int arraysize;
};
};


#endif

