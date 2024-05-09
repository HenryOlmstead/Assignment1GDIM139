// AssignmentWrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include "Assignment2StudentImpl.h"
#include "Assignment2Tests.h"

int RunAssignment2()
{
    Assignment2StudentImpl testObject;
    return RunAssignment2Tests(testObject);
}

int main()
{
    int failedTestCount = RunAssignment2();
    if (failedTestCount)
        printf("Failed %d tests", failedTestCount);
    else
        printf("Passed all tests");

    return failedTestCount;
}
