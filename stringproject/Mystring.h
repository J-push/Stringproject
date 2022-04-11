#pragma once
#include <iostream>

namespace my
{
	class string
	{
	private:
		int len;
		char* str;
	public:
		string();
		string(const char* arr);
		string(const string& arr);
		string& operator=(const string& arr);
		string& operator+=(const string& arr);
		string operator+(const string& arr);
		bool operator==(const string& arr);
		friend std::ostream& operator<<(std::ostream& os, const string& arr);
		friend std::istream& operator>>(std::istream & is, string& arr);

		~string();
	};
}
