#include "RPN.hpp"

void check_error(const std::string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == ' ' || s[i] == '\t')
            continue;
        else
        {
            std::cout << "===== " << s[i] << std::endl;
            std::cerr << "Input Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}


int main(int c, char *ac[])
{
    if(c < 2)
        return EXIT_FAILURE;
    for(int i = 1; i < c; i++)
        check_error(ac[i]);
    RPN r;
    for(int i = 1; i < c; i++)
        r.add(ac[i]);
    r.result();
    return 0;
}