#pragma once
#include <vector>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>// for std::swap
#include <iomanip> // for std::setpe..
#include <ctime> // for clock time

class PmergeMe
{
    private:
    
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &tmp);
    PmergeMe &operator=(const PmergeMe &tmp);
    
    std::vector<unsigned int>   sort(std::vector<unsigned int> &list);
    std::deque<unsigned int>   sort(std::deque<unsigned int> &list);
    ~PmergeMe();
};