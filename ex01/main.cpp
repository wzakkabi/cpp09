#include "RPN.hpp"

void check_error(const std::string &s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i] >= '0' && s[i] <= '9') || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == ' ' || s[i] == '\t')
            continue;
        else
        {
            std::cerr << "Input Error" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}


int main(int c, char *ac[])
{
    // if(c == 2)
    // {
    //     check_error(ac[1]);
    //     RPN r;
    //     r.result(ac[1]);
    // }
    // else
    //     return EXIT_FAILURE;
    std::string s = "1a45 4";
    std::cout << isdigit(s[1]);
    return 0;
}