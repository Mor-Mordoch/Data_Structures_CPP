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