#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

namespace Base
{
class SolutionBase
{
public:
	virtual void solve(int testCase) final
	{
		// process input
		input(testCase);

		// make result
		logic();

		// print result
		output();
	}

protected:
	virtual void input(int testCase) = 0;
	virtual void logic() = 0;
	virtual void output() = 0;
};
}