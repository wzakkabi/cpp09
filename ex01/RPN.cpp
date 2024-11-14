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
bool expression(const char &c)
{
    if(c == '/' || c == '*' || c == '-' || c == '+')
        return true;
    return false;
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
void RPN::result(const std::string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        while(s[i] && s[i] == ' ')
            i++;
        if(expression(s[i]))
        {
            if(_stack.size() <= 1)
            {
                std::cerr << "Error invalid input" << std::endl;
                exit(EXIT_FAILURE);
            }
            else
            {
                int tmp = _stack.top();
                _stack.pop();
                int tmp1 = _stack.top();
                _stack.pop();
                int sum = rs(tmp, s[i], tmp1);
                _stack.push(sum);
            }
        }
        else
        {
            _stack.push(atoi(s.c_str() + i));
            while(s[i] && isdigit(s[i]))
                i++;
        }
    }
}