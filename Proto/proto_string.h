#ifndef __CPROTO_PROTO_STRING_H__
#define __CPROTO_PROTO_STRING_H__

template<int maxlen> 
class proto_string
{
public:
    proto_string() {CleanUp();}
    void CleanUp() {m_BuffLen = 0;}

    void Encode(unsigned char *buffer,unsigned int &buffersize) throw (EncodeError)
    {
        unsigned int leftsize = buffersize;
        unsigned char * p = buffer;
        buffersize = 0;

        if( m_BuffLen <= 0x7f ) //0 *** **** 
        {
            if( leftsize < 1 ) throw EncodeError();
            *p = m_BuffLen;
            p += 1;
            buffersize += 1;
            leftsize -= 1;
        }
        else if( m_BuffLen <= 0x3fff ) //10 **  ****
        {
            if( leftsize < 2 ) throw EncodeError();
            CProto::h2n_16(p,static_cast<unsigned short>(m_BuffLen)|0x8000);
            buffersize += 2;
            p += 2;
            leftsize -= 2;
        }
        else //110* ****
        {
            if( leftsize < 4 ) throw EncodeError();
            CProto::h2n_32(p,m_BuffLen|0xc0000000 );
            buffersize += 4;
            p += 4;
            leftsize -= 4;
        }

        if( leftsize < m_BuffLen ) throw EncodeError();
        memcpy( p , m_Buff, m_BuffLen );
        buffersize += m_BuffLen;
        p += m_BuffLen;
        leftsize -= m_BuffLen;
    }
    void Decode( const unsigned char *buffer,unsigned int &buffersize) throw (DecodeError )
    {
        const unsigned char * p = buffer;
        if( buffersize < 1 ) throw DecodeError();
        unsigned char flag = *p;
        if( (flag & 0x80 ) == 0 ) // 0*** ****
        {
            m_BuffLen = flag;
            buffersize -= 1;
            p += 1;
        }
        else if( (flag & 0xc0 ) == 0x80 ) //10** ****
        {
            if( buffersize < 2 ) throw DecodeError();
            m_BuffLen = CProto::n2h_16(p) & 0x3fff;
            buffersize -= 2;
            p += 2;
        }
        else if( (flag & 0xe0) == 0xc0 ) //110* ****
        {
            if( buffersize < 4 ) throw DecodeError();
            m_BuffLen = CProto::n2h_32(p) & 0x1fffffff;
            buffersize -= 4;
            p += 4;
        }
        else throw DecodeError();

        if( m_BuffLen >= maxlen ) throw DecodeError();
        if( buffersize < m_BuffLen ) throw DecodeError();
        memcpy( m_Buff, p, m_BuffLen );
        m_Buff[m_BuffLen] = 0;
        buffersize -= m_BuffLen;
        p += m_BuffLen;
    }

public:
    proto_string & set(const char *buffer,int buflen )
    {
        m_BuffLen = buflen >= maxlen ? maxlen : buflen;
        memcpy( m_Buff,buffer, m_BuffLen );
        m_Buff[m_BuffLen] = 0;
        return *this;
    }

    proto_string & operator=(const char * buffer ){return this->set(buffer,strlen(buffer));}

    proto_string & operator=(const std::string & str ){return this->set(str.data(),str.size());}

    template<int m>
    proto_string & operator=(const proto_string<m> & ps )
    {
        ps.get(m_Buff,m_BuffLen);
        return *this;
    }
public:
    const char *c_str()const{return m_Buff;}
    size_t  size()const{return m_BuffLen;}
    operator const std::string()const{return std::string(m_Buff,m_BuffLen);}
    enum{max_size = maxlen};
private:
    char m_Buff[maxlen+1];
    unsigned int m_BuffLen;
};

template<>
class proto_string<0>
{
public:
    proto_string() {CleanUp();}
    void CleanUp() {m_buff.clear();}

    void Encode(unsigned char *buffer,unsigned int &buffersize) throw (EncodeError)
    {
        unsigned int leftsize = buffersize;
        unsigned char * p = buffer;
        buffersize = 0;

		unsigned int buffLen = m_buff.size();
        if( buffLen <= 0x7f ) //0 *** **** 
        {
            if( leftsize < 1 ) throw EncodeError();
            *p = buffLen;
            p += 1;
            buffersize += 1;
            leftsize -= 1;
        }
        else if( buffLen <= 0x3fff ) //10 **  ****
        {
            if( leftsize < 2 ) throw EncodeError();
            CProto::h2n_16(p,static_cast<unsigned short>(buffLen)|0x8000);
            buffersize += 2;
            p += 2;
            leftsize -= 2;
        }
        else //110* ****
        {
            if( leftsize < 4 ) throw EncodeError();
            CProto::h2n_32(p,buffLen|0xc0000000 );
            buffersize += 4;
            p += 4;
            leftsize -= 4;
        }

        if( leftsize < buffLen ) throw EncodeError();
        memcpy( p , m_buff.c_str(), buffLen );
        buffersize += buffLen;
        p += buffLen;
        leftsize -= buffLen;
    }
    void Decode( const unsigned char *buffer,unsigned int &buffersize) throw (DecodeError )
    {
        const unsigned char * p = buffer;
        if( buffersize < 1 ) throw DecodeError();
        unsigned char flag = *p;
		unsigned int buffLen = 0;
        if( (flag & 0x80 ) == 0 ) // 0*** ****
        {
            buffLen = flag;
            buffersize -= 1;
            p += 1;
        }
        else if( (flag & 0xc0 ) == 0x80 ) //10** ****
        {
            if( buffersize < 2 ) throw DecodeError();
            buffLen = CProto::n2h_16(p) & 0x3fff;
            buffersize -= 2;
            p += 2;
        }
        else if( (flag & 0xe0) == 0xc0 ) //110* ****
        {
            if( buffersize < 4 ) throw DecodeError();
            buffLen = CProto::n2h_32(p) & 0x1fffffff;
            buffersize -= 4;
            p += 4;
        }
        else throw DecodeError();

        if( buffersize < buffLen ) throw DecodeError();
		set((const char*)p, buffLen);
        buffersize -= buffLen;
        p += buffLen;
    }

public:
    proto_string & set(const char *buffer,int buflen )
    {
		m_buff.assign(buffer, buflen);
        return *this;
    }
    proto_string & operator=(const char * buffer ){return this->set(buffer,strlen(buffer));}
    proto_string & operator=(const std::string & str ){m_buff = str; return *this;}

public:
    const char *c_str()const{return m_buff.c_str();}
    size_t  size()const{return m_buff.size();}
    operator const std::string()const{return m_buff;}
private:
	std::string m_buff;
};

typedef proto_string<0> dynamic_string;

#endif
