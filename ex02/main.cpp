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
        {// vector part
            PmergeMe test;
            clock_t start1 = clock();
            std::vector< unsigned int> number;
            for( int i = 1, test; i < c; i++)
            {
                checkIsDijit(p[i]);
                test = atoi(p[i]);
                number.push_back(test);
            }
            std::vector<unsigned int> after = test.sort(number);
            clock_t end1 = clock();
            std::cout << "Before : ";
            for(unsigned int i = 0; i < number.size(); ++i)
            {
                std::cout << number[i] << " ";
            }
            std::cout << std::endl;
            std::cout << "Afrer : ";
            for(unsigned int i = 0; i < after.size(); ++i)
            {
                std::cout << after[i] << " ";
            }
            std::cout << std::endl;
            double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
            std::cout << "Time to process a range of " << after.size() <<" elements with std::vector " << std::fixed << std::setprecision(5) << time1 << std::endl;
            // to be sure its sort we gonna check it one by one
            // unsigned int value = 0;
            // // after[24] = 0;
            // for(unsigned int i = 0; i < after.size(); ++i)
            // {
            //     if(value > after[i]) {
            //         std::cout << "not sort\n";
            //         return 2;
            //     }
                // value = after[i];
            // }
        }
        {//deque
            PmergeMe test;
            clock_t start1 = clock();
            std::deque< unsigned int> number;
            for( int i = 1, test; i < c; i++)
            {
                checkIsDijit(p[i]);
                test = atoi(p[i]);
                number.push_back(test);
            }
            std::deque<unsigned int> after = test.sort(number);
            clock_t end1 = clock();
            // std::cout << "Before : ";
            // for(unsigned int i = 0; i < number.size(); ++i)
            // {
            //     std::cout << number[i] << " ";
            // }
            // std::cout << std::endl;
            // std::cout << std::endl;
            // std::cout << "Afrer : ";
            // for(unsigned int i = 0; i < after.size(); ++i)
            // {
            //     std::cout << after[i] << " ";
            // }
            // std::cout << std::endl;
            double time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
            std::cout << "Time to process a range of " << after.size() <<" elements with std::deque " << std::fixed << std::setprecision(5) << time1 << std::endl;   
            // to be sure its sort we gonna check it one by one
            // unsigned int value = 0;
            // // after[24] = 0;
            // for(unsigned int i = 0; i < after.size(); ++i)
            // {
            //     if(value > after[i]) {
            //         std::cout << "not sort\n";
            //         return 2;
            //     }
            //     value = after[i];
            // }
        }
    }
    return EXIT_SUCCESS;
}