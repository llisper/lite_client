
//#include "stdafx.h"


#include "ProtoPinJian.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stFightUserGeneralInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = 8;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_id);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, combat_power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;

	buffer[0] = buffersize;
}

void stFightUserGeneralInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        int oldsize = buffersize; 
    int skiplen = 0;
    if (1 > buffersize)
        throw DecodeError();
    skiplen = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    general_id = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    combat_power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stFightUserGeneralInfo::stFightUserGeneralInfo()
{
    SetDefault();
}
void stFightUserGeneralInfo::SetDefault()
{

}

void stFightUserInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, portait);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    name.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, combat_power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void stFightUserInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (4 > buffersize)
        throw DecodeError();
    portait = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    name.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    combat_power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

stFightUserInfo::stFightUserInfo()
{
    SetDefault();
}
void stFightUserInfo::SetDefault()
{

}

void stTopUserInfo::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = -1;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, portait);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    arraysize = leftsize;
    name.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, level);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, combat_power);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = generals_id.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * generals_id.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< generals_id.size(); ++i) {
        CProto::h2n_16(p, generals_id[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }

	buffer[0] = buffersize;
}

void stTopUserInfo::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        int oldsize = buffersize; 
    int skiplen = 0;
    if (1 > buffersize)
        throw DecodeError();
    skiplen = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (4 > buffersize)
        throw DecodeError();
    portait = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    arraysize = buffersize;
    name.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    level = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (4 > buffersize)
        throw DecodeError();
    combat_power = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    generals_id.clear();
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    generals_id.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        generals_id.push_back(CProto::n2h_16(p));
        buffersize-=2; p+=2;
    }

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stTopUserInfo::stTopUserInfo()
{
    SetDefault();
}
void stTopUserInfo::SetDefault()
{
    generals_id.clear();

}


/* body */
void XJCMD_CSC_PINJIAN_OPENCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_CSC_PINJIAN_OPENCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_CSC_PINJIAN_OPENCS::CommandID()
{
    return XJCMD_CSC_PINJIAN_OPEN;
}
int XJCMD_CSC_PINJIAN_OPENCS::GetCommandID()
{
    return XJCMD_CSC_PINJIAN_OPEN;
}

XJCMD_CSC_PINJIAN_OPENCS::XJCMD_CSC_PINJIAN_OPENCS()
{
    SetDefault();
}
void XJCMD_CSC_PINJIAN_OPENCS::SetDefault()
{

}

void XJCMD_CSC_PINJIAN_OPENSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = fight_users.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<fight_users.size(); ++i) {
        arraysize = leftsize;
        fight_users[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_CSC_PINJIAN_OPENSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    fight_users.clear();
  
    fight_users.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        fight_users[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_CSC_PINJIAN_OPENSC::CommandID()
{
    return XJCMD_CSC_PINJIAN_OPEN;
}
int XJCMD_CSC_PINJIAN_OPENSC::GetCommandID()
{
    return XJCMD_CSC_PINJIAN_OPEN;
}

XJCMD_CSC_PINJIAN_OPENSC::XJCMD_CSC_PINJIAN_OPENSC()
{
    SetDefault();
}
void XJCMD_CSC_PINJIAN_OPENSC::SetDefault()
{
    fight_users.clear();

}

void XJCMD_CSC_PINJIAN_FIGHTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, target_guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, target_rank);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_PINJIAN_FIGHTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (8 > buffersize)
        throw DecodeError();
    target_guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (2 > buffersize)
        throw DecodeError();
    target_rank = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_PINJIAN_FIGHTCS::CommandID()
{
    return XJCMD_CSC_PINJIAN_FIGHT;
}
int XJCMD_CSC_PINJIAN_FIGHTCS::GetCommandID()
{
    return XJCMD_CSC_PINJIAN_FIGHT;
}

XJCMD_CSC_PINJIAN_FIGHTCS::XJCMD_CSC_PINJIAN_FIGHTCS()
{
    SetDefault();
}
void XJCMD_CSC_PINJIAN_FIGHTCS::SetDefault()
{

}

void XJCMD_CSC_PINJIAN_TOPLISTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
    
}

void XJCMD_CSC_PINJIAN_TOPLISTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

    
}

int XJCMD_CSC_PINJIAN_TOPLISTCS::CommandID()
{
    return XJCMD_CSC_PINJIAN_TOPLIST;
}
int XJCMD_CSC_PINJIAN_TOPLISTCS::GetCommandID()
{
    return XJCMD_CSC_PINJIAN_TOPLIST;
}

XJCMD_CSC_PINJIAN_TOPLISTCS::XJCMD_CSC_PINJIAN_TOPLISTCS()
{
    SetDefault();
}
void XJCMD_CSC_PINJIAN_TOPLISTCS::SetDefault()
{

}

void XJCMD_CSC_PINJIAN_TOPLISTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
       
    if (1 > leftsize) 
        throw EncodeError();
    *p = top_user.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<top_user.size(); ++i) {
        arraysize = leftsize;
        top_user[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_CSC_PINJIAN_TOPLISTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    top_user.clear();
  
    top_user.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        top_user[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_CSC_PINJIAN_TOPLISTSC::CommandID()
{
    return XJCMD_CSC_PINJIAN_TOPLIST;
}
int XJCMD_CSC_PINJIAN_TOPLISTSC::GetCommandID()
{
    return XJCMD_CSC_PINJIAN_TOPLIST;
}

XJCMD_CSC_PINJIAN_TOPLISTSC::XJCMD_CSC_PINJIAN_TOPLISTSC()
{
    SetDefault();
}
void XJCMD_CSC_PINJIAN_TOPLISTSC::SetDefault()
{
    top_user.clear();

}

};

