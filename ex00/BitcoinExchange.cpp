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
void    btc::print_data()
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

bool check_Alfa(const char *str)
{
    for(int i = 0; str[i];)
    {
        if(str[i] == ' ' || str[i] == '-' || (str[i] >= '0'  && str[i] <= '9') || str[i] == '|' || str[i] == '.')
            i++;
        else
        {
            std::cerr << "Error : bad input => " << str << std::endl;
            return false;
        }
    }
    return true;
}

bool    check_date(const char *s, data &err)
{
    err.date[0] = atoi(s);
    err.date[1] = atoi(s + 5);
    err.date[2] = atoi(s + 8);
    const char *p = strstr(s, "|");
    if(!p)
    {
        std::cerr << "Error: bad input => " << s << std::endl;
        return false;
    }
    err.value = atof(p + 1);
    if(err.date[0] < 2008 || err.date[1] < 0 || err.date[1] > 12 || err.date[2] < 0 || err.date[2] > 31)
    {
        std::cout << "Error: bad input date => " << s << std::endl;
        return false;
    }
    if(err.value < 0 || err.value > 999999999.0f)
    {
        if(err.value > 999999999.0f)
            std::cerr << "Error: too large a number.\n";
        else
            std::cerr << "Error: not a positive number.\n";
        return false;
    }
    else if(err.date[0] > 2009)
        for(int i = 0; i < 3; i++){
            std::cout << std::setw(2) << std::setfill('0') << err.date[i] << "";
            if(i<2)
                std::cout << "-";
        }
    std::cout << " => " << err.value;
    return true;
}

int dateToInt(int year, int month, int day) {
    return year * 10000 + month * 100 + day;
}

float btc::Return_last_update(data dt)
{
    std::list<data>::iterator it;
    int org, Final; 
    for(it = dv.begin(); it != dv.end(); it++)
    {
        if(dt.date[0] < 2010 && dt.date[1] < 8 && dt.date[2] < 17)
            return 0;
        else if(dt.date[0] > 2022 && dt.date[1] > 3 && dt.date[2] > 29)
            return dt.value * it->value;
        org = dateToInt(dt.date[0], dt.date[1], dt.date[2]);
        Final =  dateToInt(it->date[0], it->date[1], it->date[2]);
        if(org == Final)
        {
            return dt.value * it->value;
        }
        else if(org < Final)
        {
            it--;
            break;
        }
    }
    return dt.value * it->value;
}

void    btc::check_File_input(std::ifstream &F_N)
{
    std::string line;
    data date;
    if(F_N.is_open())
    {
       std::getline(F_N, line);
       if(line != "date | value")
       {
            std::cerr << "Error input File not correct\n";
            F_N.close();
            exit(EXIT_FAILURE);
       }
       while (F_N.is_open() && std::getline(F_N, line))
       {
            if(check_Alfa(line.c_str()))
            {
                bool a = check_date(line.c_str(), date);
                if(a == true)
                    std::cout << " = " << Return_last_update(date) <<std::endl;
            }
      }
       
    }
    else
        std::cerr << "File not open xD\n";
}