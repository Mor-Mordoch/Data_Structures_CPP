#pragma once
#include <iostream>
#include <unordered_set>
#include <unordered_map>

class String_STL
{
public:
	String_STL();
	~String_STL();

	int lengthOfLongestSubstring(std::string s);
	int lengthOfLongestSubstring_OPT(std::string s);
};

