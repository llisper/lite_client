
//#include "stdafx.h"


#include "ProtoLogin.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stDataVersion::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, version_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 * DATA_TYPE_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<version_arraylen; ++i) {
        CProto::h2n_32(p, version[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
}

void stDataVersion::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&version, 0, sizeof(int)*DATA_TYPE_NUM);
    version_arraylen = 0;
    if (arraysize > DATA_TYPE_NUM) {
        throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        version[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    version_arraylen = arraysize;
}

stDataVersion::stDataVersion()
{
    SetDefault();
}
void stDataVersion::SetDefault()
{
    version_arraylen = 0;

}

void stPartInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, partid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, name_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &name[0], name_arraylen);
    buffersize += name_arraylen;
    p += name_arraylen;
    leftsize-= name_arraylen;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = status;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = newflag;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = recommendflag;
    ++buffersize;
    ++p;
    --leftsize;
}

void stPartInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    partid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&name, 0, sizeof(char)*MAX_LEN_SMALL);
    name_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&name, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    name_arraylen = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    status = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    newflag = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    recommendflag = *p;
    --buffersize;
    ++p;
}

stPartInfo::stPartInfo()
{
    SetDefault();
}
void stPartInfo::SetDefault()
{
    name_arraylen = 0;

}


/* body */
void XJCMD_CH2S_CLOSECS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_CH2S_CLOSECS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_CH2S_CLOSECS::CommandID()
{
    return XJCMD_CH2S_CLOSE;
}
int XJCMD_CH2S_CLOSECS::GetCommandID()
{
    return XJCMD_CH2S_CLOSE;
}

XJCMD_CH2S_CLOSECS::XJCMD_CH2S_CLOSECS()
{
    SetDefault();
}
void XJCMD_CH2S_CLOSECS::SetDefault()
{

}

void XJCMD_S2CH_RESETSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_S2CH_RESETSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_S2CH_RESETSC::CommandID()
{
    return XJCMD_S2CH_RESET;
}
int XJCMD_S2CH_RESETSC::GetCommandID()
{
    return XJCMD_S2CH_RESET;
}

XJCMD_S2CH_RESETSC::XJCMD_S2CH_RESETSC()
{
    SetDefault();
}
void XJCMD_S2CH_RESETSC::SetDefault()
{

}

void XJCMD_S2CH_KICKSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_S2CH_KICKSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_S2CH_KICKSC::CommandID()
{
    return XJCMD_S2CH_KICK;
}
int XJCMD_S2CH_KICKSC::GetCommandID()
{
    return XJCMD_S2CH_KICK;
}

XJCMD_S2CH_KICKSC::XJCMD_S2CH_KICKSC()
{
    SetDefault();
}
void XJCMD_S2CH_KICKSC::SetDefault()
{

}

void XJCMD_CSC_VERSIONCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, user_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &user[0], user_arraylen);
    buffersize += user_arraylen;
    p += user_arraylen;
    leftsize-= user_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sign_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &sign[0], sign_arraylen);
    buffersize += sign_arraylen;
    p += sign_arraylen;
    leftsize-= sign_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, mac_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &mac[0], mac_arraylen);
    buffersize += mac_arraylen;
    p += mac_arraylen;
    leftsize-= mac_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, fullVer_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &fullVer[0], fullVer_arraylen);
    buffersize += fullVer_arraylen;
    p += fullVer_arraylen;
    leftsize-= fullVer_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, ver_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &ver[0], ver_arraylen);
    buffersize += ver_arraylen;
    p += ver_arraylen;
    leftsize-= ver_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, platform_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &platform[0], platform_arraylen);
    buffersize += platform_arraylen;
    p += platform_arraylen;
    leftsize-= platform_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, key);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, version);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, channel_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &channel[0], channel_arraylen);
    buffersize += channel_arraylen;
    p += channel_arraylen;
    leftsize-= channel_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, statId_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &statId[0], statId_arraylen);
    buffersize += statId_arraylen;
    p += statId_arraylen;
    leftsize-= statId_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, statChannel_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &statChannel[0], statChannel_arraylen);
    buffersize += statChannel_arraylen;
    p += statChannel_arraylen;
    leftsize-= statChannel_arraylen;
  
    arraysize = leftsize;
    dataversion.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
}

void XJCMD_CSC_VERSIONCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&user, 0, sizeof(char)*MAX_LEN_SMALL);
    user_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&user, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    user_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&sign, 0, sizeof(char)*MAX_LEN_LARGE);
    sign_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&sign, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    sign_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&mac, 0, sizeof(char)*MAX_LEN_SMALL);
    mac_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&mac, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    mac_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&fullVer, 0, sizeof(char)*MAX_LEN_SMALL);
    fullVer_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&fullVer, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    fullVer_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&ver, 0, sizeof(char)*MAX_LEN_SMALL);
    ver_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&ver, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    ver_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&platform, 0, sizeof(char)*MAX_LEN_SMALL);
    platform_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&platform, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    platform_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    key = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    version = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&channel, 0, sizeof(char)*MAX_LEN_SMALL);
    channel_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&channel, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    channel_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&statId, 0, sizeof(char)*MAX_LEN_SMALL);
    statId_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&statId, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    statId_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&statChannel, 0, sizeof(char)*MAX_LEN_SMALL);
    statChannel_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&statChannel, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    statChannel_arraylen = arraysize;
  
    arraysize = buffersize;
    dataversion.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
}

int XJCMD_CSC_VERSIONCS::CommandID()
{
    return XJCMD_CSC_VERSION;
}
int XJCMD_CSC_VERSIONCS::GetCommandID()
{
    return XJCMD_CSC_VERSION;
}

XJCMD_CSC_VERSIONCS::XJCMD_CSC_VERSIONCS()
{
    SetDefault();
}
void XJCMD_CSC_VERSIONCS::SetDefault()
{
    user_arraylen = 0;
    sign_arraylen = 0;
    mac_arraylen = 0;
    fullVer_arraylen = 0;
    ver_arraylen = 0;
    platform_arraylen = 0;
    channel_arraylen = 0;
    statId_arraylen = 0;
    statChannel_arraylen = 0;

}

void XJCMD_CSC_VERSIONSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = loginstatus;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    loginmsg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = updatestatus;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    updatemsg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, uin);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_VERSIONSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    loginstatus = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    loginmsg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    updatestatus = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    updatemsg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    uin = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_VERSIONSC::CommandID()
{
    return XJCMD_CSC_VERSION;
}
int XJCMD_CSC_VERSIONSC::GetCommandID()
{
    return XJCMD_CSC_VERSION;
}

XJCMD_CSC_VERSIONSC::XJCMD_CSC_VERSIONSC()
{
    SetDefault();
}
void XJCMD_CSC_VERSIONSC::SetDefault()
{

}

void XJCMD_CS_ENTERGAME_STARTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CS_ENTERGAME_STARTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
}

int XJCMD_CS_ENTERGAME_STARTCS::CommandID()
{
    return XJCMD_CS_ENTERGAME_START;
}
int XJCMD_CS_ENTERGAME_STARTCS::GetCommandID()
{
    return XJCMD_CS_ENTERGAME_START;
}

XJCMD_CS_ENTERGAME_STARTCS::XJCMD_CS_ENTERGAME_STARTCS()
{
    SetDefault();
}
void XJCMD_CS_ENTERGAME_STARTCS::SetDefault()
{

}

void XJCMD_SC_ENTERGAME_FINISHSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = type;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_SC_ENTERGAME_FINISHSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    type = *p;
    --buffersize;
    ++p;
}

int XJCMD_SC_ENTERGAME_FINISHSC::CommandID()
{
    return XJCMD_SC_ENTERGAME_FINISH;
}
int XJCMD_SC_ENTERGAME_FINISHSC::GetCommandID()
{
    return XJCMD_SC_ENTERGAME_FINISH;
}

XJCMD_SC_ENTERGAME_FINISHSC::XJCMD_SC_ENTERGAME_FINISHSC()
{
    SetDefault();
}
void XJCMD_SC_ENTERGAME_FINISHSC::SetDefault()
{

}

void XJCMD_CSC_LOGINCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, user_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &user[0], user_arraylen);
    buffersize += user_arraylen;
    p += user_arraylen;
    leftsize-= user_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sign_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &sign[0], sign_arraylen);
    buffersize += sign_arraylen;
    p += sign_arraylen;
    leftsize-= sign_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &type[0], type_arraylen);
    buffersize += type_arraylen;
    p += type_arraylen;
    leftsize-= type_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, channel_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &channel[0], channel_arraylen);
    buffersize += channel_arraylen;
    p += channel_arraylen;
    leftsize-= channel_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, platform_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &platform[0], platform_arraylen);
    buffersize += platform_arraylen;
    p += platform_arraylen;
    leftsize-= platform_arraylen;
}

void XJCMD_CSC_LOGINCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&user, 0, sizeof(char)*MAX_LEN_LARGE);
    user_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&user, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    user_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&sign, 0, sizeof(char)*MAX_LEN_LARGE);
    sign_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&sign, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    sign_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&type, 0, sizeof(char)*MAX_LEN_SMALL);
    type_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&type, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    type_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&channel, 0, sizeof(char)*MAX_LEN_SMALL);
    channel_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&channel, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    channel_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&platform, 0, sizeof(char)*MAX_LEN_SMALL);
    platform_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&platform, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    platform_arraylen = arraysize;
}

int XJCMD_CSC_LOGINCS::CommandID()
{
    return XJCMD_CSC_LOGIN;
}
int XJCMD_CSC_LOGINCS::GetCommandID()
{
    return XJCMD_CSC_LOGIN;
}

XJCMD_CSC_LOGINCS::XJCMD_CSC_LOGINCS()
{
    SetDefault();
}
void XJCMD_CSC_LOGINCS::SetDefault()
{
    user_arraylen = 0;
    sign_arraylen = 0;
    type_arraylen = 0;
    channel_arraylen = 0;
    platform_arraylen = 0;

}

void XJCMD_CSC_LOGINSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = loginstatus;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    loginmsg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sid_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &sid[0], sid_arraylen);
    buffersize += sid_arraylen;
    p += sid_arraylen;
    leftsize-= sid_arraylen;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, uin);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, partlist_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    for (unsigned int i=0; i<partlist_arraylen; ++i) {
        arraysize = leftsize;
        partlist[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_CSC_LOGINSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    loginstatus = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    loginmsg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&sid, 0, sizeof(char)*MAX_LEN_SMALL);
    sid_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&sid, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    sid_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    uin = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&partlist, 0, sizeof(stPartInfo)*MAX_LEN_SMALL);
    partlist_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        partlist[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    partlist_arraylen = arraysize;
}

int XJCMD_CSC_LOGINSC::CommandID()
{
    return XJCMD_CSC_LOGIN;
}
int XJCMD_CSC_LOGINSC::GetCommandID()
{
    return XJCMD_CSC_LOGIN;
}

XJCMD_CSC_LOGINSC::XJCMD_CSC_LOGINSC()
{
    SetDefault();
}
void XJCMD_CSC_LOGINSC::SetDefault()
{
    sid_arraylen = 0;
    partlist_arraylen = 0;

}

void XJCMD_CSC_GSDISPATCHCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, partid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_GSDISPATCHCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    partid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_GSDISPATCHCS::CommandID()
{
    return XJCMD_CSC_GSDISPATCH;
}
int XJCMD_CSC_GSDISPATCHCS::GetCommandID()
{
    return XJCMD_CSC_GSDISPATCH;
}

XJCMD_CSC_GSDISPATCHCS::XJCMD_CSC_GSDISPATCHCS()
{
    SetDefault();
}
void XJCMD_CSC_GSDISPATCHCS::SetDefault()
{

}

void XJCMD_CSC_GSDISPATCHSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = loginstatus;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    loginmsg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, connect_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &connect[0], connect_arraylen);
    buffersize += connect_arraylen;
    p += connect_arraylen;
    leftsize-= connect_arraylen;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
}

void XJCMD_CSC_GSDISPATCHSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    loginstatus = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    loginmsg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    gid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&connect, 0, sizeof(char)*MAX_LEN_SMALL);
    connect_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&connect, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    connect_arraylen = arraysize;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
}

int XJCMD_CSC_GSDISPATCHSC::CommandID()
{
    return XJCMD_CSC_GSDISPATCH;
}
int XJCMD_CSC_GSDISPATCHSC::GetCommandID()
{
    return XJCMD_CSC_GSDISPATCH;
}

XJCMD_CSC_GSDISPATCHSC::XJCMD_CSC_GSDISPATCHSC()
{
    SetDefault();
}
void XJCMD_CSC_GSDISPATCHSC::SetDefault()
{
    connect_arraylen = 0;

}

void XJCMD_CSC_GSLOGINCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, user_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &user[0], user_arraylen);
    buffersize += user_arraylen;
    p += user_arraylen;
    leftsize-= user_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sign_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &sign[0], sign_arraylen);
    buffersize += sign_arraylen;
    p += sign_arraylen;
    leftsize-= sign_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, type_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &type[0], type_arraylen);
    buffersize += type_arraylen;
    p += type_arraylen;
    leftsize-= type_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, channel_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &channel[0], channel_arraylen);
    buffersize += channel_arraylen;
    p += channel_arraylen;
    leftsize-= channel_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, platform_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_SMALL) 
        throw EncodeError();
    memcpy(p, &platform[0], platform_arraylen);
    buffersize += platform_arraylen;
    p += platform_arraylen;
    leftsize-= platform_arraylen;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, sid_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_LEN_LARGE) 
        throw EncodeError();
    memcpy(p, &sid[0], sid_arraylen);
    buffersize += sid_arraylen;
    p += sid_arraylen;
    leftsize-= sid_arraylen;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    arraysize = leftsize;
    dataversion.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = checkflag;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_GSLOGINCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&user, 0, sizeof(char)*MAX_LEN_LARGE);
    user_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&user, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    user_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&sign, 0, sizeof(char)*MAX_LEN_LARGE);
    sign_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&sign, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    sign_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&type, 0, sizeof(char)*MAX_LEN_SMALL);
    type_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&type, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    type_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&channel, 0, sizeof(char)*MAX_LEN_SMALL);
    channel_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&channel, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    channel_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&platform, 0, sizeof(char)*MAX_LEN_SMALL);
    platform_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&platform, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    platform_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&sid, 0, sizeof(char)*MAX_LEN_LARGE);
    sid_arraylen = 0;
    if (arraysize > MAX_LEN_LARGE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&sid, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    sid_arraylen = arraysize;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    arraysize = buffersize;
    dataversion.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    checkflag = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_GSLOGINCS::CommandID()
{
    return XJCMD_CSC_GSLOGIN;
}
int XJCMD_CSC_GSLOGINCS::GetCommandID()
{
    return XJCMD_CSC_GSLOGIN;
}

XJCMD_CSC_GSLOGINCS::XJCMD_CSC_GSLOGINCS()
{
    SetDefault();
}
void XJCMD_CSC_GSLOGINCS::SetDefault()
{
    user_arraylen = 0;
    sign_arraylen = 0;
    type_arraylen = 0;
    channel_arraylen = 0;
    platform_arraylen = 0;
    sid_arraylen = 0;

}

void XJCMD_CSC_GSLOGINSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = loginstatus;
    ++buffersize;
    ++p;
    --leftsize;
  
    arraysize = leftsize;
    loginmsg.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = haschar;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, uin);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_GSLOGINSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    loginstatus = *p;
    --buffersize;
    ++p;
  
    arraysize = buffersize;
    loginmsg.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
    if (1 > buffersize)
        throw DecodeError();
    haschar = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    uin = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_GSLOGINSC::CommandID()
{
    return XJCMD_CSC_GSLOGIN;
}
int XJCMD_CSC_GSLOGINSC::GetCommandID()
{
    return XJCMD_CSC_GSLOGIN;
}

XJCMD_CSC_GSLOGINSC::XJCMD_CSC_GSLOGINSC()
{
    SetDefault();
}
void XJCMD_CSC_GSLOGINSC::SetDefault()
{

}

};

