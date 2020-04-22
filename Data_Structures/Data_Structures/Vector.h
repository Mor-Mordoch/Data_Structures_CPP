#pragma once
#include <iostream>
#include <vector>
#include <map>
class Vector
{
private:
	static Vector* m_vector_instance;
	Vector();
public:
	static Vector* get_vector_instance();
	~Vector();

	std::vector<int> twoSum(std::vector<int>& nums, int target);
	int maxArea(std::vector<int>& height);
};

/* -------------------------------------------------------------------------------------------------------------- */ 
/* Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted */
/* or deleted, with their storage being handled automatically by the container.                                   */
/* Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.   */
/* -------------------------------------------------------------------------------------------------------------- */