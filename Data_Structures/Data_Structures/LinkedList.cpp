#include "LinkedList.h"

/* Initialize the instance with NULL, will get value by demand */
LinkedList* LinkedList::m_linked_list_instance = NULL;

/* Static method to return the instance of the class */
LinkedList* LinkedList::get_linked_list_instance()
{
	if (!m_linked_list_instance)
		m_linked_list_instance = new LinkedList();
	return m_linked_list_instance;
}

/* Constructor to initialize a few ListNode objects we can use later */
LinkedList::LinkedList()
{
	/* Create the list: 1->2->3->4 */
	ListNode n1(1);
	n1.next = new ListNode(2);
	(n1.next)->next = new ListNode(3);
	(n1.next)->next->next = new ListNode(4);

	/* Create the list: 5->6->7 */
	ListNode n2(5);
	n2.next = new ListNode(6);
	(n2.next)->next = new ListNode(7);

	/* Store the lists in the public member array variable */
	m_list_node_arr[0] = n1;
	m_list_node_arr[1] = n2;

}

/* return an address of ListNode object according to the given index */
LinkedList::ListNode* LinkedList::get_list_node_element(int index)
{
	return &m_list_node_arr[index];
}

void LinkedList::print_list(LinkedList::ListNode* ln)
{
	LinkedList::ListNode* tmp = ln;
	while (tmp)
	{
		std::cout << tmp->val;
		tmp = tmp->next;
		if (tmp)
			std::cout << "->";
	}

}
/* default d'tor */
LinkedList::~LinkedList()
{
}

/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/*
Time complexity : O(max(m,n)). Assume that m and n represents the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.
Space complexity : O(max(m,n)). The length of the new list is at most + max(m,n)+1.
*/
LinkedList::ListNode* LinkedList::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* sum_res = new ListNode(0);
	ListNode* l1_tmp = l1;
	ListNode* l2_tmp = l2;
	ListNode* curr = sum_res;
	int       carry = 0;

	while (l1_tmp || l2_tmp)
	{
		int l1_val = (l1_tmp != NULL) ? l1_tmp->val : 0;
		int l2_val = (l2_tmp != NULL) ? l2_tmp->val : 0;
		int sum = l1_val + l2_val + carry;
		carry = sum / 10;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		if (l1_tmp)
			l1_tmp = l1_tmp->next;
		if (l2_tmp)
			l2_tmp = l2_tmp->next;
	}
	if (carry > 0)
		curr->next = new ListNode(carry);

	return sum_res->next;
}