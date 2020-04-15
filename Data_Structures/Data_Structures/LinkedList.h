#pragma once
#include <iostream>

class LinkedList
{
public:
	/* Definition for singly-linked list */
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
	/* must initialize because there is no default c'tor to ListNode */
	ListNode m_list_node_arr[2]{ 0, 0 };
private:
	static LinkedList* m_linked_list_instance;
	LinkedList();
public:
	static LinkedList* get_linked_list_instance(void);

	/* Make sure these are unacceptable, to prevent copies of the singelton */
	LinkedList(const LinkedList&)     = delete;
	void operator=(const LinkedList&) = delete;

	ListNode* get_list_node_element(int index);
	void print_list(ListNode* ln);

	~LinkedList();

	/* ---------------------- */
	/* Linked List Algorithms */
	/* ---------------------- */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

