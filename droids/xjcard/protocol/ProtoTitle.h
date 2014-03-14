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

#include "ProtoTitleDef.h"

#ifndef __ProtoTitle_H__ 
#define __ProtoTitle_H__ 

#include "CProto_Common.h"

#include "CProto.h"



namespace CProto {
/* �ƺ��б����� */
struct stTitleListData {
public:
    void Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer, unsigned int& bufferlen) throw (DecodeError);

    stTitleListData();
    void SetDefault();

/* �ƺ��������е����� */
    short titleIndex;
/* �ƺ�ID */
    short titleID;
/* �ƺ�״̬���� */
    char titleState;
/* ����ʱ�� */
    unsigned int timeOutValue;

private:
    unsigned int arraysize;
};
class XJCMD_CSC_TITLE_ADDSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_CSC_TITLE_ADDSC();
    void SetDefault();

    
/* �ƺ��������е����� */
    short titleIndex;
/* �ƺ�ID */
    short titleID;

private:
    unsigned int arraysize;
};
class XJCMD_SC_TITLE_STATE_LIST_SYNSC : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_SC_TITLE_STATE_LIST_SYNSC();
    void SetDefault();

    
/* ���ݰ汾�� */
    char user_version;
/* �ͻ�����ʾ�ƺ��б� */
    proto_vector<stTitleListData> titleStateList;

private:
    unsigned int arraysize;
};
class XJCMD_CSC_TITLE_USECS : public PackBody{
public:
    static int GetCommandID();
    void Encode(unsigned char *buffer,unsigned int& buffersize) throw (EncodeError);
    void Decode(const unsigned char* buffer,unsigned int& bufferlen) throw (DecodeError);
    int CommandID();

    XJCMD_CSC_TITLE_USECS();
    void SetDefault();

    
/* ʹ�÷�ʽ��0-ȡ����1-ʹ�ã� */
    char type;
/* Ҫʹ�óƺ��������е����� */
    short titleIndex;

private:
    unsigned int arraysize;
};
};


#endif
