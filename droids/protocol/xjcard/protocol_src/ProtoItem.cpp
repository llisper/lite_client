
//#include "stdafx.h"


#include "ProtoItem.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {

/* body */
void XJCMD_CSC_ITEM_OPERCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = opertype;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = containertype;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (opertype==IOT_SOLD || opertype==IOT_PUTON) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridids_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 * MAX_LEN_SMALL > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<gridids_arraylen; ++i) {
        CProto::h2n_16(p, gridids[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
	}
  
    if (leftsize == 0)
        throw EncodeError();
    *p = opercnt;
    ++buffersize;
    ++p;
    --leftsize;

	if (opertype==IOT_PUTON) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = equipbattle;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (opertype==IOT_PUTON) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = equipassist;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (opertype==IOT_SOLID) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, equipsolidtype);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (opertype==IOT_UPGRADE) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, materialgrids_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 * MAX_LEN_SMALL > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<materialgrids_arraylen; ++i) {
        CProto::h2n_16(p, materialgrids[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
	}

	if (opertype==IOT_UPGRADE) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, materialcnts_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 * MAX_LEN_SMALL > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<materialcnts_arraylen; ++i) {
        CProto::h2n_16(p, materialcnts[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
	}
}

void XJCMD_CSC_ITEM_OPERCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    opertype = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    containertype = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    gridid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

	if (opertype==IOT_SOLD || opertype==IOT_PUTON) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&gridids, 0, sizeof(unsigned short)*MAX_LEN_SMALL);
    gridids_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        gridids[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    gridids_arraylen = arraysize;
	}
    if (1 > buffersize)
        throw DecodeError();
    opercnt = *p;
    --buffersize;
    ++p;

	if (opertype==IOT_PUTON) {    if (1 > buffersize)
        throw DecodeError();
    equipbattle = *p;
    --buffersize;
    ++p;
	}

	if (opertype==IOT_PUTON) {    if (1 > buffersize)
        throw DecodeError();
    equipassist = *p;
    --buffersize;
    ++p;
	}

	if (opertype==IOT_SOLID) {  
    if (2 > buffersize)
        throw DecodeError();
    equipsolidtype = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (opertype==IOT_UPGRADE) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&materialgrids, 0, sizeof(unsigned short)*MAX_LEN_SMALL);
    materialgrids_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        materialgrids[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    materialgrids_arraylen = arraysize;
	}

	if (opertype==IOT_UPGRADE) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&materialcnts, 0, sizeof(unsigned short)*MAX_LEN_SMALL);
    materialcnts_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        materialcnts[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    materialcnts_arraylen = arraysize;
	}
}

int XJCMD_CSC_ITEM_OPERCS::CommandID()
{
    return XJCMD_CSC_ITEM_OPER;
}
int XJCMD_CSC_ITEM_OPERCS::GetCommandID()
{
    return XJCMD_CSC_ITEM_OPER;
}

XJCMD_CSC_ITEM_OPERCS::XJCMD_CSC_ITEM_OPERCS()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_OPERCS::SetDefault()
{
    gridids_arraylen = 0;
    materialgrids_arraylen = 0;
    materialcnts_arraylen = 0;

}

void XJCMD_CSC_ITEM_OPERSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = opertype;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = containertype;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;

	if (opertype==IOT_SOLD) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridids_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (2 * MAX_LEN_SMALL > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<gridids_arraylen; ++i) {
        CProto::h2n_16(p, gridids[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
	}
  
    if (leftsize == 0)
        throw EncodeError();
    *p = operstatus;
    ++buffersize;
    ++p;
    --leftsize;
}

void XJCMD_CSC_ITEM_OPERSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    opertype = *p;
    --buffersize;
    ++p;
    if (1 > buffersize)
        throw DecodeError();
    containertype = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    gridid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;

	if (opertype==IOT_SOLD) {  
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&gridids, 0, sizeof(unsigned short)*MAX_LEN_SMALL);
    gridids_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
        throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        gridids[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    gridids_arraylen = arraysize;
	}
    if (1 > buffersize)
        throw DecodeError();
    operstatus = *p;
    --buffersize;
    ++p;
}

int XJCMD_CSC_ITEM_OPERSC::CommandID()
{
    return XJCMD_CSC_ITEM_OPER;
}
int XJCMD_CSC_ITEM_OPERSC::GetCommandID()
{
    return XJCMD_CSC_ITEM_OPER;
}

XJCMD_CSC_ITEM_OPERSC::XJCMD_CSC_ITEM_OPERSC()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_OPERSC::SetDefault()
{
    gridids_arraylen = 0;

}

void XJCMD_CSC_ITEM_2_EXPCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, item_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_ITEM_2_EXPCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    item_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (2 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_ITEM_2_EXPCS::CommandID()
{
    return XJCMD_CSC_ITEM_2_EXP;
}
int XJCMD_CSC_ITEM_2_EXPCS::GetCommandID()
{
    return XJCMD_CSC_ITEM_2_EXP;
}

XJCMD_CSC_ITEM_2_EXPCS::XJCMD_CSC_ITEM_2_EXPCS()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_2_EXPCS::SetDefault()
{

}

void XJCMD_CSC_ITEM_2_EXPSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, item_id);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = levels_upgraded;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, general_index);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
}

void XJCMD_CSC_ITEM_2_EXPSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    item_id = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    levels_upgraded = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    general_index = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
}

int XJCMD_CSC_ITEM_2_EXPSC::CommandID()
{
    return XJCMD_CSC_ITEM_2_EXP;
}
int XJCMD_CSC_ITEM_2_EXPSC::GetCommandID()
{
    return XJCMD_CSC_ITEM_2_EXP;
}

XJCMD_CSC_ITEM_2_EXPSC::XJCMD_CSC_ITEM_2_EXPSC()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_2_EXPSC::SetDefault()
{

}

};

