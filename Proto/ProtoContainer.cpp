
//#include "stdafx.h"


#include "ProtoContainer.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stEquipSignAttrData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = attrid;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, attrvalue);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = cnt;
    ++buffersize;
    ++p;
    --leftsize;
}

void stEquipSignAttrData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    attrid = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    attrvalue = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    cnt = *p;
    --buffersize;
    ++p;
}

stEquipSignAttrData::stEquipSignAttrData()
{
    SetDefault();
}
void stEquipSignAttrData::SetDefault()
{

}

void stEquipOnOffData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = ison;
    ++buffersize;
    ++p;
    --leftsize;

	if (ison==1) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = battleindex;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (ison==1) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = assistflag;
    ++buffersize;
    ++p;
    --leftsize;
	}
}

void stEquipOnOffData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    ison = *p;
    --buffersize;
    ++p;

	if (ison==1) {    if (1 > buffersize)
        throw DecodeError();
    battleindex = *p;
    --buffersize;
    ++p;
	}

	if (ison==1) {    if (1 > buffersize)
        throw DecodeError();
    assistflag = *p;
    --buffersize;
    ++p;
	}
}

stEquipOnOffData::stEquipOnOffData()
{
    SetDefault();
}
void stEquipOnOffData::SetDefault()
{

}

void stContainerGridData::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (1 > leftsize)
        throw EncodeError();
    *p = dirtyflag_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (leftsize < (1+(ITEM_SYNC_FLAG_MAX-1)/8)) 
        throw EncodeError();
    memcpy(p, &dirtyflag[0], dirtyflag_arraylen);
    buffersize += dirtyflag_arraylen;
    p += dirtyflag_arraylen;
    leftsize-= dirtyflag_arraylen;

	if (dirtyflag[ITEM_SYNC_FLAG_GRIDID>>3]&(1<<(ITEM_SYNC_FLAG_GRIDID&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridid);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_CHANGEFLAG>>3]&(1<<(ITEM_SYNC_FLAG_CHANGEFLAG&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = changeflag;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_ITEMID>>3]&(1<<(ITEM_SYNC_FLAG_ITEMID&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, itemid);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_BANDTYPE>>3]&(1<<(ITEM_SYNC_FLAG_BANDTYPE&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = bandtype;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_BANDSTATUS>>3]&(1<<(ITEM_SYNC_FLAG_BANDSTATUS&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = bandstatus;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_GUID>>3]&(1<<(ITEM_SYNC_FLAG_GUID&0x7))) {  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, guid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_OVERLAP>>3]&(1<<(ITEM_SYNC_FLAG_OVERLAP&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = overlap;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_TIMEOUT>>3]&(1<<(ITEM_SYNC_FLAG_TIMEOUT&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, timeout);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_SOLID>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_SOLID&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, equipsolidlevel);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_GRADE>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_GRADE&0x7))) {  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, equipgradelevel);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_GRADE>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_GRADE&0x7))) {  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, equipgradespirit);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_SIGNATTR>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_SIGNATTR&0x7))) {  
    if (1 > leftsize)
        throw EncodeError();
    *p = equipsignattrs_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<equipsignattrs_arraylen; ++i) {
        arraysize = leftsize;
        equipsignattrs[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_SKILL_STATUS>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_SKILL_STATUS&0x7))) {  
    if (leftsize == 0)
        throw EncodeError();
    *p = equipskillstatus;
    ++buffersize;
    ++p;
    --leftsize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_ONOFF_INFO>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_ONOFF_INFO&0x7))) {  
    arraysize = leftsize;
    equiponoffinfo.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}
}

void stContainerGridData::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&dirtyflag, 0, sizeof(unsigned char)*(1+(ITEM_SYNC_FLAG_MAX-1)/8));
    dirtyflag_arraylen = 0;
    if (arraysize > (1+(ITEM_SYNC_FLAG_MAX-1)/8)) {
       throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&dirtyflag, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    dirtyflag_arraylen = arraysize;

	if (dirtyflag[ITEM_SYNC_FLAG_GRIDID>>3]&(1<<(ITEM_SYNC_FLAG_GRIDID&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    gridid = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_CHANGEFLAG>>3]&(1<<(ITEM_SYNC_FLAG_CHANGEFLAG&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    changeflag = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_ITEMID>>3]&(1<<(ITEM_SYNC_FLAG_ITEMID&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    itemid = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_BANDTYPE>>3]&(1<<(ITEM_SYNC_FLAG_BANDTYPE&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    bandtype = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_BANDSTATUS>>3]&(1<<(ITEM_SYNC_FLAG_BANDSTATUS&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    bandstatus = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_GUID>>3]&(1<<(ITEM_SYNC_FLAG_GUID&0x7))) {  
    if (8 > buffersize)
        throw DecodeError();
    guid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_OVERLAP>>3]&(1<<(ITEM_SYNC_FLAG_OVERLAP&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    overlap = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_TIMEOUT>>3]&(1<<(ITEM_SYNC_FLAG_TIMEOUT&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    timeout = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_SOLID>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_SOLID&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    equipsolidlevel = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_GRADE>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_GRADE&0x7))) {  
    if (2 > buffersize)
        throw DecodeError();
    equipgradelevel = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_LVL_GRADE>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_LVL_GRADE&0x7))) {  
    if (4 > buffersize)
        throw DecodeError();
    equipgradespirit = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_SIGNATTR>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_SIGNATTR&0x7))) {  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&equipsignattrs, 0, sizeof(stEquipSignAttrData)*MAX_LEN_SMALL);
    equipsignattrs_arraylen = 0;
    if (arraysize > MAX_LEN_SMALL) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        equipsignattrs[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    equipsignattrs_arraylen = arraysize;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_SKILL_STATUS>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_SKILL_STATUS&0x7))) {    if (1 > buffersize)
        throw DecodeError();
    equipskillstatus = *p;
    --buffersize;
    ++p;
	}

	if (dirtyflag[ITEM_SYNC_FLAG_EQUIP_ONOFF_INFO>>3]&(1<<(ITEM_SYNC_FLAG_EQUIP_ONOFF_INFO&0x7))) {  
    arraysize = buffersize;
    equiponoffinfo.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}
}

stContainerGridData::stContainerGridData()
{
    SetDefault();
}
void stContainerGridData::SetDefault()
{
    dirtyflag_arraylen = 0;
    equipsignattrs_arraylen = 0;

}


/* body */
void XJCMD_SC_USERBAG_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = version;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridcntitem);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = griddatasitem_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<griddatasitem_arraylen; ++i) {
        arraysize = leftsize;
        griddatasitem[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
  
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, gridcntequip);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = griddatasequip_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<griddatasequip_arraylen; ++i) {
        arraysize = leftsize;
        griddatasequip[i].Encode(p, arraysize);
        buffersize += arraysize;
        p += arraysize;
        leftsize -= arraysize;
    }
}

void XJCMD_SC_USERBAG_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

        if (1 > buffersize)
        throw DecodeError();
    version = *p;
    --buffersize;
    ++p;
  
    if (2 > buffersize)
        throw DecodeError();
    gridcntitem = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&griddatasitem, 0, sizeof(stContainerGridData)*255);
    griddatasitem_arraylen = 0;
    if (arraysize > 255) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        griddatasitem[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    griddatasitem_arraylen = arraysize;
  
    if (2 > buffersize)
        throw DecodeError();
    gridcntequip = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&griddatasequip, 0, sizeof(stContainerGridData)*255);
    griddatasequip_arraylen = 0;
    if (arraysize > 255) {
       throw DecodeError();
    }
  
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        griddatasequip[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
    griddatasequip_arraylen = arraysize;
}

int XJCMD_SC_USERBAG_SYNSC::CommandID()
{
    return XJCMD_SC_USERBAG_SYN;
}
int XJCMD_SC_USERBAG_SYNSC::GetCommandID()
{
    return XJCMD_SC_USERBAG_SYN;
}

XJCMD_SC_USERBAG_SYNSC::XJCMD_SC_USERBAG_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_USERBAG_SYNSC::SetDefault()
{
    griddatasitem_arraylen = 0;
    griddatasequip_arraylen = 0;

}

void XJCMD_SC_ITEMS_STATIC_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, versiontableitem);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = tableitemdatadelta;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, tableitemdata_arraylen);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < MAX_LEN_TABLE) 
        throw EncodeError();
    memcpy(p, &tableitemdata[0], tableitemdata_arraylen);
    buffersize += tableitemdata_arraylen;
    p += tableitemdata_arraylen;
    leftsize-= tableitemdata_arraylen;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, versiontableequip);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = tableequipdatadelta;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, tableequipdata_arraylen);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize < MAX_LEN_TABLE) 
        throw EncodeError();
    memcpy(p, &tableequipdata[0], tableequipdata_arraylen);
    buffersize += tableequipdata_arraylen;
    p += tableequipdata_arraylen;
    leftsize-= tableequipdata_arraylen;
}

void XJCMD_SC_ITEMS_STATIC_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (4 > buffersize)
        throw DecodeError();
    versiontableitem = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    tableitemdatadelta = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    //memset(&tableitemdata, 0, sizeof(char)*MAX_LEN_TABLE);
    tableitemdata_arraylen = 0;
    if (arraysize > MAX_LEN_TABLE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&tableitemdata, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    tableitemdata_arraylen = arraysize;
  
    if (4 > buffersize)
        throw DecodeError();
    versiontableequip = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    tableequipdatadelta = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    //memset(&tableequipdata, 0, sizeof(char)*MAX_LEN_TABLE);
    tableequipdata_arraylen = 0;
    if (arraysize > MAX_LEN_TABLE) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&tableequipdata, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    tableequipdata_arraylen = arraysize;
}

int XJCMD_SC_ITEMS_STATIC_SYNSC::CommandID()
{
    return XJCMD_SC_ITEMS_STATIC_SYN;
}
int XJCMD_SC_ITEMS_STATIC_SYNSC::GetCommandID()
{
    return XJCMD_SC_ITEMS_STATIC_SYN;
}

XJCMD_SC_ITEMS_STATIC_SYNSC::XJCMD_SC_ITEMS_STATIC_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_ITEMS_STATIC_SYNSC::SetDefault()
{
    tableitemdata_arraylen = 0;
    tableequipdata_arraylen = 0;

}

void XJCMD_SC_EQUIPS_DISCARD_SYNSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, equipdiscard_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (4 * MAX_USEEQUIP_NUM > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i<equipdiscard_arraylen; ++i) {
        CProto::h2n_32(p, equipdiscard[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }
}

void XJCMD_SC_EQUIPS_DISCARD_SYNSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&equipdiscard, 0, sizeof(int)*MAX_USEEQUIP_NUM);
    equipdiscard_arraylen = 0;
    if (arraysize > MAX_USEEQUIP_NUM) {
        throw DecodeError();
    }
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        equipdiscard[i] = CProto::n2h_32(p);
        buffersize -= 4;
        p += 4;
    }
    equipdiscard_arraylen = arraysize;
}

int XJCMD_SC_EQUIPS_DISCARD_SYNSC::CommandID()
{
    return XJCMD_SC_EQUIPS_DISCARD_SYN;
}
int XJCMD_SC_EQUIPS_DISCARD_SYNSC::GetCommandID()
{
    return XJCMD_SC_EQUIPS_DISCARD_SYN;
}

XJCMD_SC_EQUIPS_DISCARD_SYNSC::XJCMD_SC_EQUIPS_DISCARD_SYNSC()
{
    SetDefault();
}
void XJCMD_SC_EQUIPS_DISCARD_SYNSC::SetDefault()
{
    equipdiscard_arraylen = 0;

}

void XJCMD_CSC_ITEM_DETAILCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, ownerguid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, itemguid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, itemid);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
}

void XJCMD_CSC_ITEM_DETAILCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    ownerguid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (8 > buffersize)
        throw DecodeError();
    itemguid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
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
  
    if (4 > buffersize)
        throw DecodeError();
    itemid = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
}

int XJCMD_CSC_ITEM_DETAILCS::CommandID()
{
    return XJCMD_CSC_ITEM_DETAIL;
}
int XJCMD_CSC_ITEM_DETAILCS::GetCommandID()
{
    return XJCMD_CSC_ITEM_DETAIL;
}

XJCMD_CSC_ITEM_DETAILCS::XJCMD_CSC_ITEM_DETAILCS()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_DETAILCS::SetDefault()
{

}

void XJCMD_CSC_ITEM_DETAILSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, ownerguid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
    if (8 > leftsize)
        throw EncodeError();
    CProto::h2n_64(p, itemguid);
    buffersize += 8;
    p += 8;
    leftsize -= 8;
  
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
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, itemid);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (leftsize == 0)
        throw EncodeError();
    *p = status;
    ++buffersize;
    ++p;
    --leftsize;

	if (status==0) {  
    arraysize = leftsize;
    itemdata.Encode(p, arraysize);
    buffersize += arraysize;
    p += arraysize;
    leftsize -= arraysize;
	}
}

void XJCMD_CSC_ITEM_DETAILSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (8 > buffersize)
        throw DecodeError();
    ownerguid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
  
    if (8 > buffersize)
        throw DecodeError();
    itemguid = CProto::n2h_64(p);
    buffersize -= 8;
    p += 8;
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
  
    if (4 > buffersize)
        throw DecodeError();
    itemid = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
    if (1 > buffersize)
        throw DecodeError();
    status = *p;
    --buffersize;
    ++p;

	if (status==0) {  
    arraysize = buffersize;
    itemdata.Decode(p, arraysize);
    p += (buffersize-arraysize);
    buffersize = arraysize;
	}
}

int XJCMD_CSC_ITEM_DETAILSC::CommandID()
{
    return XJCMD_CSC_ITEM_DETAIL;
}
int XJCMD_CSC_ITEM_DETAILSC::GetCommandID()
{
    return XJCMD_CSC_ITEM_DETAIL;
}

XJCMD_CSC_ITEM_DETAILSC::XJCMD_CSC_ITEM_DETAILSC()
{
    SetDefault();
}
void XJCMD_CSC_ITEM_DETAILSC::SetDefault()
{

}

};

