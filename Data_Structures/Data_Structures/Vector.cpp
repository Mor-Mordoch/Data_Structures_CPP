#include "Vector.h"

Vector* Vector::m_vector_instance = NULL;

Vector* Vector::get_vector_instance()
{
	if (!m_vector_instance)
		m_vector_instance = new Vector();
	return m_vector_instance;
}

Vector::Vector()
{
}

Vector::~Vector()
{
}

/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/
/*
Complexity Analysis:
Time complexity : O(n). We traverse the list containing nn elements only once. Each look up in the table costs only O(1) time.
Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores at most n elements.
*/
std::vector<int> Vector::twoSum(std::vector<int>& nums, int target)
{
	std::map<int, int> val_idx;
	std::vector<int> res(2, -1);
	std::vector<int>::iterator nums_begin = nums.begin();
	for (std::vector<int>::iterator it = nums_begin; it != nums.end(); ++it)
	{
		if (val_idx.find(target - *it) != val_idx.end())
		{
			res[0] = val_idx[target - *it];
			res[1] = it - nums_begin;
			break;
		}
		/* could have inserted a key-value pair to the map in the following syntax as well:
		   val_idx.insert(std::pair<int,int>(*it, it - nums_begin));
		*/
		val_idx[*it] = (it - nums_begin);
	}
	return res;
}

/*
11. Container With Most Water
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.
Example:
Input: [1,8,6,2,5,4,8,3,7]
Output: 49
The rectangle is created with index 1 and 8
*/
/*
Algo1:
Brute force - consider the area for every possible pair of the lines and find out the maximum area out of those.
Algo2:
The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line. 
Further, the farther the lines, the more will be the area obtained.
We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines.
Further, we maintain a variable maxarea to store the maximum area obtained till now. 
At every step, we find out the area formed between them, update maxarea and move the pointer pointing to the shorter line towards the other end by one step.
How this approach works?
Initially we consider the area constituting the exterior most lines. Now, to maximize the area, we need to consider
the area between the lines of larger lengths.
If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it is limited
by the shorter line. But moving the shorter line's pointer could turn out to be beneficial, as per the same argument, despite the reduction in the width. 
This is done since a relatively longer line obtained by moving the shorter line's pointer might overcome the reduction in area caused by the width reduction.

*/
/*
Complexity Analysis
Time complexity : O(n). Single pass.
Space complexity : O(1). Constant space is used.
*/
int Vector::maxArea(std::vector<int>& height) {
	int max_container = 0;
	int l = 0;
	int r = height.size() - 1;
	int min_vertical_len = 0;
	while (l < r)
	{
		min_vertical_len = (height[l] < height[r]) ? height[l] : height[r];
		max_container = ((r - l) * min_vertical_len > max_container)
			? (r - l) * min_vertical_len : max_container;
		if (height[l] < height[r])
			l++;
		else
			r--;
	}
	return max_container;
}