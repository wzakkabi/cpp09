#pragma once
#include <queue>
#include <iostream>
#include <string>
#include <stack>
class RPN
{
    private:
    std::queue<int> number;
    std::queue<char> expression;
    public:
    RPN();
    RPN(const RPN &tmp);
    RPN &operator=(const RPN &tmp);
    ~RPN();
    void add(const std::string &s);
    void result();
};