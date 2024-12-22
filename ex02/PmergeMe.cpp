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

        if(list.size() == 2 && list[0] > list[1])
            std::swap(list[0], list[1]);
        return list;
    }
    std::vector<std::pair<unsigned int, unsigned int> > pair;
    std::vector<unsigned int> pending;
    for(unsigned int i = 0; i + 1 < n; i += 2)
    {
       pair.push_back(std::make_pair(list[i], list[i + 1]));
    }
    
    if(n % 2 == 1)
        pending.push_back(list.back());
    
    for(unsigned int i = 0; i < pair.size(); ++i) {
        if(pair[i].first > pair[i].second)
            std::swap(pair[i].first , pair[i].second);
    }

    //now im gonna take the large number and pushit to pending and use the Recursively
    std::vector<unsigned int> main_chain;
    main_chain.push_back(pair[0].first);
    for(unsigned long i = 0; i < pair.size(); ++i)
    {
        main_chain.push_back(pair[i].second);
    }
    main_chain = sort(main_chain);
    for(unsigned long i = 1; i < pair.size(); ++i)
    {
        pending.push_back(pair[i].first);
    }
    for(unsigned long i = 0; i < pending.size(); ++i)
    {
        std::vector<unsigned int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending[i]);
        main_chain.insert(pos, pending[i]);
    }
    return main_chain;
}


std::deque<unsigned int>   PmergeMe::sort(std::deque<unsigned int> &list)
{
    unsigned int n = list.size();
    
    if(n < 3)
    {
        if(list.size() == 2 && list[0] > list[1])
            std::swap(list[0], list[1]);
        return list;
    }
    std::deque<std::pair<unsigned int, unsigned int> > pair;
    std::deque<unsigned int> pending;
    for(unsigned int i = 0; i + 1 < n; i += 2)
    {
       pair.push_back(std::make_pair(list[i], list[i + 1]));
    }
    
    if(n % 2 == 1)
        pending.push_back(list.back());
    
    for(unsigned int i = 0; i < pair.size(); ++i) {
        if(pair[i].first > pair[i].second)
            std::swap(pair[i].first , pair[i].second);
    }

    //now im gonna take the large number and pushit to pending and use the Recursively
    std::deque<unsigned int> main_chain;
    main_chain.push_back(pair[0].first);
    for(unsigned long i = 0; i < pair.size(); ++i)
    {
        main_chain.push_back(pair[i].second);
    }
    main_chain = sort(main_chain);
    for(unsigned long i = 1; i < pair.size(); ++i)
    {
        pending.push_back(pair[i].first);
    }
    for(unsigned long i = 0; i < pending.size(); ++i)
    {
        std::deque<unsigned int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), pending[i]);
        main_chain.insert(pos, pending[i]);
    }
    return main_chain;
}

PmergeMe::~PmergeMe()
{
}