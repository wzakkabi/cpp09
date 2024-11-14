#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <ctype.h>

class RPN
{
    private:
    std::stack<int> _stack;
    public:
    RPN();
    RPN(const RPN &tmp);
    RPN &operator=(const RPN &tmp);
    ~RPN();
    void result(const std::string &s);
};