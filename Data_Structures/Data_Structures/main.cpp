#include "LinkedList.h"

int main()
{
	LinkedList* linked_list_instance = LinkedList::get_linked_list_instance();
	LinkedList::ListNode* ln = linked_list_instance->addTwoNumbers(linked_list_instance->get_list_node_element(0),
		linked_list_instance->get_list_node_element(1));
	linked_list_instance->print_list(ln);

	return 0;
}