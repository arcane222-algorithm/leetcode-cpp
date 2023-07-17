#pragma once

#include <iostream>
#include <memory>

#include "problems/Solution445.h";

int main()
{
	std::unique_ptr<Base::SolutionBase> problemPtr = std::make_unique<Problems::Solution445>();

	for (int i = 1; i <= 4; i++)
	{
		problemPtr->solve(i);
	}
}