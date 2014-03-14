
//#include "stdafx.h"


#include "ProtoTest.h"

#include "CProto_Command.h"
#include "ProtoPack_Package.h"
/* Implement */
namespace CProto {
void stTestStruct::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (leftsize == 0)
        throw EncodeError();
    *p = 10;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 > leftsize)
        throw EncodeError();
    CProto::h2n_32(p, Test);
    buffersize += 4;
    p += 4;
    leftsize -= 4;
  
    if (1 > leftsize)
        throw EncodeError();
    *p = TestCArray_arraylen;
    ++buffersize;
    ++p;
    --leftsize;
  
    if (2 * 10 > leftsize)
       throw EncodeError();
    for (unsigned int i=0; i<TestCArray_arraylen; ++i) {
        CProto::h2n_16(p, TestCArray[i]);
        buffersize += 2;
        p += 2;
        leftsize -= 2;
    }
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = TestArray.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    if (4 * TestArray.size() > leftsize)
        throw EncodeError();
    for (unsigned int i=0; i< TestArray.size(); ++i) {
        CProto::h2n_32(p, TestArray[i]);
        buffersize += 4;
        p += 4;
        leftsize -= 4;
    }

	buffer[0] = buffersize;
}

void stTestStruct::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    SetDefault();

        int oldsize = buffersize; 
    int skiplen = 0;
    if (1 > buffersize)
        throw DecodeError();
    skiplen = *p;
    --buffersize;
    ++p;
  
    if (4 > buffersize)
        throw DecodeError();
    Test = CProto::n2h_32(p);
    buffersize -= 4;
    p += 4;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    //memset(&TestCArray, 0, sizeof(short)*10);
    TestCArray_arraylen = 0;
    if (arraysize > 10) {
       throw DecodeError();
    }
  
    if (2*arraysize > buffersize)
        throw DecodeError();
    for (unsigned int i=0; i<arraysize; ++i) {
        TestCArray[i] = CProto::n2h_16(p);
        buffersize-=2; p+=2;
    }
    TestCArray_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    TestArray.clear();
  
    if (4 * arraysize > buffersize)
        throw DecodeError();
    TestArray.resize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        TestArray.push_back(CProto::n2h_32(p));
        buffersize -= 4;
        p += 4;
    }

    skiplen = skiplen - (oldsize - buffersize);
    if (skiplen>buffersize || skiplen < 0) throw DecodeError();
        else if (skiplen>0) {
            p += skiplen;
            buffersize -= skiplen;
        }
}

stTestStruct::stTestStruct()
{
    SetDefault();
}
void stTestStruct::SetDefault()
{
    Test = 0;
    TestCArray_arraylen = 0;
    TestArray.clear();

}


/* body */
void XJCMD_SC_TESTCS::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, test_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &test[0], test_arraylen);
    buffersize += test_arraylen;
    p += test_arraylen;
    leftsize-= test_arraylen;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = stTest.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<stTest.size(); ++i) {
        arraysize = leftsize;
        stTest[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_SC_TESTCS::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&test, 0, sizeof(char)*MAX_NAME_LEN);
    test_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&test, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    test_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    stTest.clear();
  
    stTest.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        stTest[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_SC_TESTCS::CommandID()
{
    return XJCMD_SC_TEST;
}
int XJCMD_SC_TESTCS::GetCommandID()
{
    return XJCMD_SC_TEST;
}

XJCMD_SC_TESTCS::XJCMD_SC_TESTCS()
{
    SetDefault();
}
void XJCMD_SC_TESTCS::SetDefault()
{
    test_arraylen = 0;
    stTest.clear();

}

void XJCMD_SC_TESTSC::Encode(unsigned char *buffer, unsigned int& buffersize) throw (EncodeError) 
{
    unsigned int leftsize;
    leftsize = buffersize;
    unsigned char *p;
    p = buffer;
    buffersize = 0;
      
    if (2 > leftsize)
        throw EncodeError();
    CProto::h2n_16(p, test_arraylen);
    buffersize += 2;
    p += 2;
    leftsize -= 2;
  
    if (leftsize < MAX_NAME_LEN) 
        throw EncodeError();
    memcpy(p, &test[0], test_arraylen);
    buffersize += test_arraylen;
    p += test_arraylen;
    leftsize-= test_arraylen;
   
    if (1 > leftsize) 
        throw EncodeError();
    *p = stTest.size();
    ++buffersize;
    ++p;
    --leftsize;
  
    for (unsigned int i=0; i<stTest.size(); ++i) {
        arraysize = leftsize;
        stTest[i].Encode(p, arraysize);
        buffersize+=arraysize;
        p+=arraysize;
        leftsize-=arraysize;
    }
}

void XJCMD_SC_TESTSC::Decode(const unsigned char *buffer,unsigned int& buffersize) throw (DecodeError)
{
    const unsigned char *p;
    p = buffer;
    

      
    if (2 > buffersize)
        throw DecodeError();
    arraysize = CProto::n2h_16(p);
    buffersize -= 2;
    p += 2;
    //memset(&test, 0, sizeof(char)*MAX_NAME_LEN);
    test_arraylen = 0;
    if (arraysize > MAX_NAME_LEN) {
        throw DecodeError();
    }
  
    if (arraysize > buffersize)
        throw DecodeError();
    memcpy(&test, p, arraysize*sizeof(char));
    buffersize -= arraysize;
    p += arraysize;
    test_arraylen = arraysize;
  
    if (1 > buffersize)
        throw DecodeError();
    arraysize = *p;
    --buffersize;
    ++p;
    stTest.clear();
  
    stTest.setsize(arraysize);
    for (unsigned int i=0; i<arraysize; ++i) {
        unsigned int buffersize2 = buffersize;
        stTest[i].Decode(p, buffersize2);
        p += (buffersize - buffersize2);
        buffersize = buffersize2;
    }
}

int XJCMD_SC_TESTSC::CommandID()
{
    return XJCMD_SC_TEST;
}
int XJCMD_SC_TESTSC::GetCommandID()
{
    return XJCMD_SC_TEST;
}

XJCMD_SC_TESTSC::XJCMD_SC_TESTSC()
{
    SetDefault();
}
void XJCMD_SC_TESTSC::SetDefault()
{
    test_arraylen = 0;
    stTest.clear();

}

};

