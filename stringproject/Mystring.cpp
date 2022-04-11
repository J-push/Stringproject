#include "Mystring.h"
#include <cstring>

my::string::string() : str(nullptr), len(0) 
{
}

my::string::string(const char* arr)
{
	len = strlen(arr) + 1;
	str = new char[len];
	strcpy_s(str, len, arr);
}

my::string::string(const string& arr)
{
	len = arr.len;
	str = new char[len];
	strcpy_s(str, len, arr.str);
}

my::string& my::string::operator=(const string& arr)
{
	if (str != "\0")
	{
		delete[] str;
	}
	len = arr.len;
	str = new char[len];
	strcpy_s(str, len, arr.str);
	return *this;
}

my::string& my::string::operator+=(const string& arr)
{
	len += (arr.len - 1);
	char* temp = new char[len];
	strcpy_s(temp, len, str);
	strcat_s(temp, len, arr.str);

	if (str != nullptr)
	{
		delete[] str;
	}

	str = temp;
	
	return *this;
}


my::string my::string::operator+(const string& arr)
{
	char* tempstr = new char[len + arr.len - 1];
	strcpy_s(tempstr, len + arr.len - 1, str);
	strcat_s(tempstr, len + arr.len - 1,arr.str);

	string tempstring = tempstr;
	delete[] tempstr;
	return tempstring;
}

bool my::string::operator==(const string& arr)
{
	if (strcmp(str, arr.str) != 0)
		return false;
	else
		return true;
}

std::ostream& my::operator<<(std::ostream& os, const string& arr)
{
	os << arr.str;
	return os;
}

std::istream& my::operator>>(std::istream& is, string& arr)
{
	char str[100];
	is >> str;
	arr = string(str);
	return is;
}

my::string::~string()
{
	if (str != "\0")
	{
		delete[] str;
	}
}


