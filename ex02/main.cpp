#include "PmergeMe.hpp"

void    checkIsDijit(std::string s)
{
    for(unsigned long i = 0; i < s.length() ; i++)
    {
        if(!isdigit(s[i]) && s[i] != '+')
        {
         std::cerr << "Error in input\n";
         exit(EXIT_FAILURE);
        }
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
            number.push_back(test);
        }
        std::cout << "Before : ";
        for(unsigned int i = 0; i < number.size(); ++i)
        {
            std::cout << number[i] << " ";
        }
        std::cout << std::endl;
        PmergeMe t;
        std::vector<unsigned int> after;
        after = t.sort(number);
        std::cout << "Afrer : ";
        for(unsigned int i = 0; i < after.size(); ++i)
        {
            std::cout << after[i] << " ";
        }
        std::cout << std::endl;
        //to be sure its sort we gonna check it one by one
        // test = 0;
        // after[24] = 0;
        // for(unsigned int i = 0; i < after.size(); ++i)
        // {
            // if(test > after[i]) {
                // std::cout << "not sort\n";
                // return 2;
            // }
            // test = after[i];
        // }
    }
    return EXIT_SUCCESS;
}