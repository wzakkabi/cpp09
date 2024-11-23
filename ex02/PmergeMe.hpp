#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>

class PmergeMe
{
    private:
    std::list<int> list;
    std::queue<int> q_list;

    public:
    PmergeMe();
    PmergeMe(const PmergeMe &tmp);
    PmergeMe &operator=(const PmergeMe &tmp);
    std::vector<unsigned int>   sort(std::vector<unsigned int> &list);

    // void    sort(std::queue<int> &list);
    ~PmergeMe();
};