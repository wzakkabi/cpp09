#include "RPN.hpp"

RPN::RPN()
{
}
RPN::RPN(const RPN &tmp)
{
    this->_stack = tmp._stack;
}
RPN &RPN::operator=(const RPN &tmp)
{
    if(this != &tmp)
    {
        this->_stack = tmp._stack;
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
    for(int i = 0; i < s.length();i++)
    {
        while(s[i] && s[i] == ' ')
            i++;
        if(expression(s[i]) && !(s[i] == '-' && s[i + 1] && isdigit(s[i + 1])))
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
                int sum = rs(tmp1, s[i], tmp);
                _stack.push(sum);
            }
        }
        else
        {
            int ss = atoi(s.c_str() + i);
            std::cout << ss << " ======\n"; 
            _stack.push(ss);
            if(s[i] == '-')
                i++;
            while(s[i] && isdigit(s[i]))
                i++;
        }
    }
    if(_stack.size() > 1)
    {
        std::cout << _stack.size();
        std::cerr << "Error\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << _stack.top() << std::endl;
        _stack.pop();
    }
}