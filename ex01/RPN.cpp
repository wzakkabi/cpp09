#include "RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(const RPN &tmp)
{
    this->number = tmp.number;
    this->expression = tmp.expression;
}
RPN &RPN::operator=(const RPN &tmp)
{
    if(this != &tmp)
    {
        this->number = tmp.number;
        this->expression = tmp.expression;
    }
    return *this;
}
RPN::~RPN()
{

}
void RPN::add(const std::string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            this->number.push((s[i] - '0'));
        else if(s[i] == ' ' || s[i] == '\t')
            continue;
        else
            this->expression.push(s[i]);
    }
}

int rs(int first, char ex, int end)
{
    if(ex == '*')
        return (first * end);
    else if(ex == '/')
        return (first / end);
    else if(ex == '+')
        return (first + end);
    else
        return (first - end);
}
void RPN::result()
{
    int res, tmp1, tmp2;
    if(number.size())
    {
        res = number.front();
        number.pop();
    }
    while(number.size() && expression.size())
    {
        std::cout << "result = "<< res << " " << expression.front() << " " << number.front() << std::endl; 
        res = rs(res, expression.front(), number.front());
        number.pop();
        expression.pop();
    }
    // if(number.size() != 0 || expression.size() != 0)
    // {
    //     std::cerr << "error number or expression not equal!" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // else
        std::cout << res << std::endl;
    number.empty();
    expression.empty();
}