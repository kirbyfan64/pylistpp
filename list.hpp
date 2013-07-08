#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>

#ifndef __LIST_HPP_INCLUDED
#define __LIST_HPP_INCLUDED

class list_error: public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return errstr;
	}
protected:
	const char* errstr = "";
};

class list_notfound: public list_error
{
protected:
	const char* errstr = "The specified element could not be found";
};

template <typename T>
class list
{
public:
	list() {};
	~list() {}
	list operator=(T rhs[])
	{
		vect.insert(vect.being(), rhs, sizeof(rhs) / sizeof(*rhs) ); return *this;
	}
	T operator[] (int pos) const
	{
		return vect[pos];
	}
	T get(int pos)
	{
		return vect.at(pos);
	}
	T& operator[](int pos)
	{
		return vect[pos];
	}
	void append(T item)
	{
		vect.push_back(item);
	}
	void insert(int position, T item)
	{
		vect.insert(vect.begin() + position, item);
	}
	int count(T item)
	{
		int total = 0;
		typename std::vector<T>::const_iterator iter;
		for (iter = vect.begin(); iter != vect.end(); ++iter)
		{
			if (*iter == item)
			{
				total++;
			}
		}
		return total;
	}
	void reverse()
	{
		std::reverse(vect.begin(), vect.end());
	}
	T pop(int element=-1)
	{
		int pos;
		if (element == -1)
		{
			pos = vect.size() - 1;
		}
		else
		{
			pos = element;
		}
		T &ret = vect.at(pos);
		vect.erase(vect.begin()+pos);
		return ret;
	}
	int index(T item)
	{
		typename std::vector<T>::iterator iter;
		T ret;
		for (iter = vect.begin(); iter != vect.end(); ++iter)
		{
			if (*iter == item)
			{
				ret = *iter;
			}
		}
		return ret;
	}
private:
	std::vector<T> vect;
};
#endif