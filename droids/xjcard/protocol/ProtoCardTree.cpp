
//#include "stdafx.h"


#include "ProtoCardTree.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CSC_CARDTREE_REWARDCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = tree_id;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = subTree_id;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_CARDTREE_REWARDCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    tree_id = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    subTree_id = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_CARDTREE_REWARDCS::CommandID()
{
    return XJCMD_CSC_CARDTREE_REWARD;
}
int XJCMD_CSC_CARDTREE_REWARDCS::GetCommandID()
{
    return XJCMD_CSC_CARDTREE_REWARD;
}

XJCMD_CSC_CARDTREE_REWARDCS::XJCMD_CSC_CARDTREE_REWARDCS()
{
    SetDefault();
}
void XJCMD_CSC_CARDTREE_REWARDCS::SetDefault()
{

}

};

