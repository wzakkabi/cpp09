#include <PmergeMe.hpp>

void    checkIsDijit(std::string s)
{
    for(int i = 0; i < s.length(); i++)
        if(!isdigit(s[i]) && s[i] != '+')
        {
         std::cerr << "Error in input\n";
         exit(EXIT_FAILURE);
        }
}

int main(int c, char *p[])
{
    if(c <= 2)
    {
        std::cerr << "Nothing to sort\n";
        return EXIT_FAILURE;
    }
    else
    {
        std::vector<unsigned int> number;
        long int test;
        for(int i = 1; i < c; i++)
        {
            checkIsDijit(p[i]);
            test = atoi(p[i]);
            number.
        }
    }
    return EXIT_SUCCESS;
}