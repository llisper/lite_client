
//#include "stdafx.h"


#include "ProtoActivity.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stActivityData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = changeflag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = activeflag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = stateflag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = times;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = maxtimes;
    ++buffersize;
    ++p;
    --leftsize;
}

void stActivityData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    if (1 > buffersize)
        throw DecodeError();
    changeflag = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    activeflag = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    stateflag = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    times = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    maxtimes = *p;
    --buffersize;
    ++p;
}

stActivityData::stActivityData()
{
    SetDefault();
}
void stActivityData::SetDefault()
{

}

void stActivityCommand::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, command);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = commandname_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &commandname[0], commandname_arraylen);
    buffersize += commandname_arraylen;
    p += commandname_arraylen;
    leftsize-= commandname_arraylen;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = intparams_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * MAX_ACTIVITY_COMMAND_PARAM_INT_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<intparams_arraylen; ++i) {
        CProto::h2n_32(p, intparams[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = guidparams_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (8 * MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<guidparams_arraylen; ++i) {
        CProto::h2n_64(p, guidparams[i]);
        buffersize += 8;
        p += 8;
        leftsize -= 8;
    }
}

void stActivityCommand::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    command = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&commandname, 0, sizeof(char)*MAX_LEN_SMALL);
    commandname_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&commandname, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    commandname_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&intparams, 0, sizeof(int)*MAX_ACTIVITY_COMMAND_PARAM_INT_NUM);
    intparams_arraylen = 0;
    if (arraysize > MAX_ACTIVITY_COMMAND_PARAM_INT_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        intparams[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    intparams_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&guidparams, 0, sizeof(uint64_t)*MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM);
    guidparams_arraylen = 0;
    if (arraysize > MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM) {
       throw DecodeError();
    }
  
    if (8 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        guidparams[i] = CProto::n2h_64(p);
        buffersize -= 8;
        p += 8;
    }
    guidparams_arraylen = arraysize;
}

stActivityCommand::stActivityCommand()
{
    SetDefault();
}
void stActivityCommand::SetDefault()
{
    commandname_arraylen = 0;
    intparams_arraylen = 0;
    guidparams_arraylen = 0;

}

void stActivityRetCommand::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, command);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = intparams_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * MAX_ACTIVITY_COMMAND_PARAM_INT_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<intparams_arraylen; ++i) {
        CProto::h2n_32(p, intparams[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = guidparams_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (8 * MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<guidparams_arraylen; ++i) {
        CProto::h2n_64(p, guidparams[i]);
        buffersize += 8;
        p += 8;
        leftsize -= 8;
    }
  
    if (1 > leftsize)
        throw EncodeError();
    *p = qhtmlparams_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<qhtmlparams_arraylen; ++i) {
        arraysize = leftsize;
        qhtmlparams[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void stActivityRetCommand::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    command = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&intparams, 0, sizeof(int)*MAX_ACTIVITY_COMMAND_PARAM_INT_NUM);
    intparams_arraylen = 0;
    if (arraysize > MAX_ACTIVITY_COMMAND_PARAM_INT_NUM) {
       throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        intparams[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    intparams_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&guidparams, 0, sizeof(uint64_t)*MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM);
    guidparams_arraylen = 0;
    if (arraysize > MAX_ACTIVITY_COMMAND_PARAM_GUID_NUM) {
       throw DecodeError();
    }
  
    if (8 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        guidparams[i] = CProto::n2h_64(p);
        buffersize -= 8;
        p += 8;
    }
    guidparams_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&qhtmlparams, 0, sizeof(stQhtml)*MAX_ACTIVITY_COMMAND_PARAM_QHTML_NUM);
    qhtmlparams_arraylen = 0;
    if (arraysize > MAX_ACTIVITY_COMMAND_PARAM_QHTML_NUM) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        qhtmlparams[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    qhtmlparams_arraylen = arraysize;
}

stActivityRetCommand::stActivityRetCommand()
{
    SetDefault();
}
void stActivityRetCommand::SetDefault()
{
    intparams_arraylen = 0;
    guidparams_arraylen = 0;
    qhtmlparams_arraylen = 0;

}


/* body */
void XJCMD_SC_ACTIVITYS_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, activitydatas_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<activitydatas_arraylen; ++i) {
        arraysize = leftsize;
        activitydatas[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_SC_ACTIVITYS_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&activitydatas, 0, sizeof(stActivityData)*1024);
    activitydatas_arraylen = 0;
    if (arraysize > 1024) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        activitydatas[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    activitydatas_arraylen = arraysize;
}

int XJCMD_SC_ACTIVITYS_SYNSC::CommandID()
{
    return XJCMD_SC_ACTIVITYS_SYN;
}
int XJCMD_SC_ACTIVITYS_SYNSC::GetCommandID()
{
    return XJCMD_SC_ACTIVITYS_SYN;
}

XJCMD_SC_ACTIVITYS_SYNSC::XJCMD_SC_ACTIVITYS_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_ACTIVITYS_SYNSC::SetDefault()
{
    activitydatas_arraylen = 0;

}

void XJCMD_CSC_ACTIVITY_COMMANDCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    cmd.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_ACTIVITY_COMMANDCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    cmd.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_ACTIVITY_COMMANDCS::CommandID()
{
    return XJCMD_CSC_ACTIVITY_COMMAND;
}
int XJCMD_CSC_ACTIVITY_COMMANDCS::GetCommandID()
{
    return XJCMD_CSC_ACTIVITY_COMMAND;
}

XJCMD_CSC_ACTIVITY_COMMANDCS::XJCMD_CSC_ACTIVITY_COMMANDCS()
{
    SetDefault();
}
void XJCMD_CSC_ACTIVITY_COMMANDCS::SetDefault()
{

}

void XJCMD_CSC_ACTIVITY_COMMANDSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = status;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    arraysize = leftsize;
    cmd.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = nextcmds_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<nextcmds_arraylen; ++i) {
        arraysize = leftsize;
        nextcmds[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_ACTIVITY_COMMANDSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    status = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    arraysize = buffersize;
    cmd.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&nextcmds, 0, sizeof(stActivityCommand)*MAX_LEN_SMALL);
    nextcmds_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        nextcmds[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    nextcmds_arraylen = arraysize;
}

int XJCMD_CSC_ACTIVITY_COMMANDSC::CommandID()
{
    return XJCMD_CSC_ACTIVITY_COMMAND;
}
int XJCMD_CSC_ACTIVITY_COMMANDSC::GetCommandID()
{
    return XJCMD_CSC_ACTIVITY_COMMAND;
}

XJCMD_CSC_ACTIVITY_COMMANDSC::XJCMD_CSC_ACTIVITY_COMMANDSC()
{
    SetDefault();
}
void XJCMD_CSC_ACTIVITY_COMMANDSC::SetDefault()
{
    nextcmds_arraylen = 0;

}

};

