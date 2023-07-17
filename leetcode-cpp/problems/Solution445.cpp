/**
 * Add Two Numbers II - Leetcode445
 * -----------------
 * category: list (리스트)
 *           stack (스택)
 * -----------------
 * Input 1
 * l1 = [7,2,4,3], l2 = [5,6,4]
 *
 * Output 1
 * [7,8,0,7]
 * -----------------
 * Input 2
 * l1 = [2,4,3], l2 = [5,6,4]
 *
 * Output 2
 * [8,0,7]
 * -----------------
 * Input 3
 * l1 = [0], l2 = [0]
 *
 * Output 3
 * [0]
 * -----------------
 * Input 4
 * l1 = [5], l2 = [5]
 *
 * Output 4
 * [1, 0]
 * -----------------
 */


/* Include headers */
#include "Solution445.h"

/* Using alias */
using Solution445 = Problems::Solution445;

/* Variables */
ListNode* l1 = nullptr;
ListNode* l2 = nullptr;
ListNode* result = nullptr;
std::stack<int>* stack1 = nullptr;
std::stack<int>* stack2 = nullptr;
std::stack<int>* resultStack = nullptr;


/* Method declaration */
void Solution445::input(int testCase)
{
	switch (testCase)
	{
	case 1:
	{
		l1 = new ListNode(7);
		l2 = new ListNode(5);

		auto l1Tmp = l1;
		l1Tmp = l1Tmp->next = new ListNode(2);
		l1Tmp = l1Tmp->next = new ListNode(4);
		l1Tmp = l1Tmp->next = new ListNode(3);

		auto l2Tmp = l2;
		l2Tmp = l2Tmp->next = new ListNode(6);
		l2Tmp = l2Tmp->next = new ListNode(4);
	} break;
	case 2:
	{
		l1 = new ListNode(2);
		l2 = new ListNode(5);

		auto l1Tmp = l1;
		l1Tmp = l1Tmp->next = new ListNode(4);
		l1Tmp = l1Tmp->next = new ListNode(3);

		auto l2Tmp = l2;
		l2Tmp = l2Tmp->next = new ListNode(6);
		l2Tmp = l2Tmp->next = new ListNode(4);
	} break;
	case 3:
	{
		l1 = new ListNode(0);
		l2 = new ListNode(0);
	}break;

	case 4:
	{
		l1 = new ListNode(5);
		l2 = new ListNode(5);
	}break;
	default:
	{
		l1 = new ListNode(5);
		l2 = new ListNode(5);
	}break;
	}
}

void Solution445::logic()
{
	stack1 = _addListToStack(l1);
	stack2 = _addListToStack(l2);
	resultStack = new std::stack<int>();

	bool flag = false;

	while (true)
	{
		if (stack1->empty() && stack2->empty())
		{
			break;
		}

		int sum = 0;
		if (!stack1->empty())
		{
			sum += stack1->top();
			stack1->pop();
		}

		if (!stack2->empty())
		{
			sum += stack2->top();
			stack2->pop();
		}

		if (flag)
		{
			sum += 1;
		}

		if (sum >= 10)
		{
			sum -= 10;
			flag = true;
		}
		else
		{
			flag = false;
		}

		resultStack->push(sum);
	}

	if (flag)
	{
		resultStack->push(1);
	}
}

void Solution445::output()
{
	result = new ListNode(resultStack->top());
	resultStack->pop();

	ListNode* tmp = result;

	while (!resultStack->empty())
	{
		tmp = tmp->next = new ListNode(resultStack->top());
		resultStack->pop();
	}

	// print result
	_listToString(result);

	// free list
	_listCleaner(l1);
	_listCleaner(l2);
	_listCleaner(result);

	// free stack
	delete stack1;
	delete stack2;
	delete resultStack;
}


std::stack<int>* Solution445::_addListToStack(ListNode* list)
{
	std::stack<int>* result = new std::stack<int>();
	while (list != nullptr)
	{
		result->push(list->val);
		list = list->next;
	}

	return result;
}

void Solution445::_listCleaner(ListNode* list)
{
	while (list != nullptr)
	{
		ListNode* nxt = nullptr;
		if (list->next != nullptr)
		{
			nxt = list->next;
		}

		delete list;
		list = nxt;
	}

	list = nullptr;
}


void Solution445::_listToString(ListNode* list)
{
	std::cout << "[";

	while (true)
	{
		if (list != nullptr)
		{
			std::cout << list->val;
		}

		if (list->next != nullptr)
		{
			std::cout << ", ";
			list = list->next;
		}
		else
		{
			break;
		}
	}

	std::cout << "]\n";
}