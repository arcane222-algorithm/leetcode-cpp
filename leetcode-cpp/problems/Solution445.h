#pragma once

#include "../base/SolutionBase.h";

using SolutionBase = Base::SolutionBase;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr)
	{
	}
	ListNode(int x) : val(x), next(nullptr)
	{
	}
	ListNode(int x, ListNode* next) : val(x), next(next)
	{
	}
};

namespace Problems
{
class Solution445 : public SolutionBase
{
protected:
	void input(int testCase) override;
	void logic() override;
	void output() override;

private:
	std::stack<int>* _addListToStack(ListNode* list);
	void _listCleaner(ListNode* list);
	void _listToString(ListNode* list);
};
}

