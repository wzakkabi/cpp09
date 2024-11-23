#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &tmp)
{
    if(this != &tmp)
    {
        *this = tmp;
    }
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &tmp)
{
    *this = tmp;
}

std::vector<unsigned int>   PmergeMe::sort(std::vector<unsigned int> &list)
{
    unsigned int n = list.size();
    
    if(n < 3)
    {
        std::sort(list.begin(), list.end());
        return list;
    }

    std::vector<std::pair<int, int>> pair;
    std::vector<unsigned int> pending;
    std::vector<unsigned int>::iterator it = list.begin();
    for(int i = 0; i + 1 < n; i += 2)
    {
       pair.push_back(std::make_pair(it[i], it[i + 1]));
    }
    if(n % 2 == 1)
        pending.push_back(list.back());
    for(int i = 0; pair.size(); i++) {
        if(pair[i].first < pair[i].second)
            std::swap(pair[i].first , pair[i].second);
    }
    //now im gonna take the large number and pushit to pending and use the Recursively
    std::vector<int> main_chain;
    main_chain.push_back(pair[0].first);
    for(int i = 0; i < pair.size(); ++i)
    {
        main_chain.push_back(pair[i].second;
    }

}

//void    sort(std::queue<int> &vector);

PmergeMe::~PmergeMe()
{
}