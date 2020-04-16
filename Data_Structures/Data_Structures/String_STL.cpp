#include "String_STL.h"



String_STL::String_STL()
{
}


String_STL::~String_STL()
{
}

/*
3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
/*
Algorithm explanation:
By using HashSet as a sliding window, checking if a character in the current can be done in O(1).
A sliding window is an abstract concept commonly used in array/string problems.
A window is a range of elements in the array/string which usually defined by the start and end indices, i.e. [i, j) (left-closed, right-open).
A sliding window is a window "slides" its two boundaries to the certain direction. For example, if we slide [i, j) to the right by 1 element,
then it becomes [i+1, j+1) (left-closed, right-open).

Back to our problem. We use Set to store the characters in current window [i, j) (j = i initially). 
Then we slide the index j to the right. If it is not in the Set, we slide j further. Doing so until s[j] is already in the HashSet.
At this point, we found the maximum size of substrings without duplicate characters start with index i. If we do this for all i, we get our answer.
*/
/*
Complexity Analysis
Time complexity : O(2n) = O(n). In the worst case each character will be visited twice by i and j.
Space complexity : O(min(m, n)). We need O(k) space for the sliding window, where k is the size of the Set. 
The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.
*/
int String_STL::lengthOfLongestSubstring(std::string s) {
	int s_len = s.size();
	std::unordered_set<char> chars;
	int i = 0;
	int j = 0;
	int longest_substr = 0;
	while (i < s_len && j < s_len)
	{
		if (chars.find(s[j]) == chars.end())
		{
			chars.insert(s[j++]);
			longest_substr = (longest_substr > j - i) ? longest_substr : j - i;
		}
		else
			chars.erase(s[i++]);
	}
	return longest_substr;
}
/*
Optimized algorithm:
The above solution requires at most 2n steps. In fact, it could be optimized to require only n steps.
Instead of using a set to tell if a character exists or not, we could define a mapping of the characters to its index.
Then we can skip the characters immediately when we found a repeated character.
The reason is that if s[j] have a duplicate in the range [i, j) with index j', we don't need to increase i little by little.
We can skip all the elements in the range [i, j'] and let i to be j' + 1 directly.
*/
int String_STL::lengthOfLongestSubstring_OPT(std::string s) 
{
	int s_len = s.size();
	std::unordered_map<char, int> char_index;
	int longest_substr = 0;
	for (int i = 0, j = 0; j < s_len; ++j)
	{
		if (char_index.find(s[j]) != char_index.end())
			i = (char_index[s[j]] > i) ? char_index[s[j]] : i; /* for cases that left window has already been moved right, make sure that the current repeated char will not move the window to the left!
															      example: consider "abcdefeb" - up to f, i=0. next char e has already seen, so window move to point f.
															      now j points to b, so according to the map, i needs to point to c which cause the window move left ! */
		longest_substr = (longest_substr > j - i + 1) ? longest_substr : j - i + 1;   
		char_index[s[j]] = j + 1;
	}
	return longest_substr;
}

	