#include "LinkedList.h"
#include "Vector.h"
#include "String_STL.h"
int main()
{
#if 0
	LinkedList* linked_list_instance = LinkedList::get_linked_list_instance();
	LinkedList::ListNode* ln = linked_list_instance->addTwoNumbers(linked_list_instance->get_list_node_element(0),
																   linked_list_instance->get_list_node_element(1));
	linked_list_instance->print_list(ln);
#endif
#if 0
	int arr_to_vec[] = { 1,2,3,4,5 };
	std::vector<int> v(arr_to_vec, arr_to_vec + sizeof(arr_to_vec) / sizeof(int));
	Vector* vec_instance = Vector::get_vector_instance();
	std::vector<int> res = vec_instance->twoSum(v, 6);
	for (int i = 0; i < res.size(); i++)
		std::cout << res[i] << " ";
#endif
	String_STL s;
	std::cout<<s.lengthOfLongestSubstring("pwwkew");
	std::cout << s.lengthOfLongestSubstring_OPT("pwwkew");
	return 0;
}