/********************************************************************
 * This file is generated by program cap
 * Please do not change it directly
 * 
 * protocol name: CProto
 * protocol version: 1.0
 * protocol author:   
 * protocol desc: �ɽ����ƿͻ��˺�̨����Э��-����Э��
 *
 * history:
 * 2013-02-22 : ���� (V1.0)
********************************************************************/

#include "ProtoCardTreeDef.h"

#ifndef __ProtoCardTree_H__ 
#define __ProtoCardTree_H__ 

#include "CProto_Common.h"

#include "CProto.h"



namespace CProto {
class XJCMD_CSC_CARDTREE_REWARDCS : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_CSC_CARDTREE_REWARDCS();
    void SetDefault();

    
/* �����׸�id */
    unsigned char tree_id;
/* ������ϵ��id */
    unsigned char subTree_id;

private:
    unsigned int arraysize;
};
};


#endif
