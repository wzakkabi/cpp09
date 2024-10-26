#include "BitcoinExchange.hpp"


btc::btc()
{
}

btc::btc(std::list<data> &tmp)
{
    this->dv = tmp;
}

btc::btc(const btc &tmp)
{
    if(this != &tmp)
    {
        *this = tmp;
    }
}
void    btc::print()
{
    std::list<data>::iterator it;
    for(it = dv.begin(); it != dv.end(); it++)
    {
        for(int i = 0; i < 3; i++)
        std::cout << std::setw(2) << std::setfill('0') << it->date[i] << " ";
        std::cout << it->value << std::endl;
    }
}

btc &btc::operator=(const btc &tmp)
{
    if(this != &tmp)
    {
        this->dv.empty();
        this->dv = tmp.dv;
    }
    return *this;
}

void    btc::Add(data &tmp)
{
    this->dv.push_back(tmp);
}

btc::~btc()
{
    this->dv.empty();
}