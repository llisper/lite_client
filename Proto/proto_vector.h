#ifndef _PROTO_VECTOR_H_
#define _PROTO_VECTOR_H_

template<typename T>
class proto_vector
{
public:
    typedef proto_vector<T> self;

    proto_vector()
    {
	_size = 0;
	_capacity = 0;
	_vector = NULL;
    }

    ~proto_vector()
    {
	if (_vector)
	{
	    delete[] _vector;
	}
    }

    proto_vector(const self& _my)
    {
	*this = _my;		
    }

    self& operator=(const self& _my)
    {
	do 
	{
	    if (_capacity < _my._capacity)
	    {
		if(!resize(_my._capacity))
		    break;
	    }
	    _size = 0;
	    for(size_t i=0;i<_my._size;++i)
	    {
		push_back(_my._vector[i]);
	    }
	} while (0);

	return *this;
    }

    bool resize(int size = -1)
    {
	T* tmp = NULL;
	size_t new_size = size>0?size:8;
	if (_capacity == 0)
	{
	    //tmp = (T*)malloc(new_size*sizeof(T));
	    try
	    {
		tmp = new T[new_size];
	    }
	    catch(...)
	    {
		tmp = NULL;
	    }
	}
	else
	{
	    if (size == -1)
	    {
		new_size = (_capacity<<1);
	    }
	    try
	    {
		tmp = new T[new_size];
	    }
	    catch(...)
	    {
		tmp = NULL;
	    }
	    //tmp = (T*)realloc(_vector,new_size*sizeof(T));
	}
	if (tmp)
	{
	    if (_size > 0)
	    {
		if(_size > new_size)
		{
		    _size = new_size;
		}
		for (size_t i=0;i<_size;++i)
		{
		    tmp[i]  = _vector[i];
		}
	    }
	    if (_vector)
	    {
		delete[] _vector;
	    }
	    _vector = tmp;
	    _capacity = new_size;

	    return true;
	}
	return false;

    }

    void push_back(const T& _val)
    {
	    if (_size >= _capacity)
	    {
			if(!resize())
			{
				return;
			}
	    }

	    _vector[_size++] = _val;
    }

    T& operator[](int _index)
    {
	return _vector[_index];
    }

    T*	get_empty_slot()
    {
	do 
	{
	    if (_size >= _capacity)
	    {
		if(!resize())
		    break;
	    }
	    return &_vector[_size++];
	} while (0);

	return NULL;
    }

    size_t size()
    {
	return _size;
    }

    void setsize(int size)
	{
		if (size > _capacity)
		{
			if(!resize(size))
			{
				return;
			}
		}
		_size = size;
	}

    void clear()
    {
	_size=0;
    }

private:
    T*		_vector;
    size_t	_size;
    size_t	_capacity;
};

#endif//_PROTO_VECTOR_H_
