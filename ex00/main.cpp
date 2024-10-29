#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    if(ac == 2)
    {
        std::ifstream File("data.csv");
        std::ifstream input(av[1]);
        if(!File)
        {
            std::cerr << "Error Data File not fond\n";
            exit(1);
        }
        if(!input)
        {
            std::cerr << "Error input File not fond\n";
            exit(EXIT_FAILURE);
        }
        std::string line;
        if(File.is_open())
        {
            std::getline(File, line);
            if(line != "date,exchange_rate")
            {
                std::cerr << "data not correct\n";
                File.close();
                exit(EXIT_FAILURE);
            }
            std::list<data> dv;
            while(File.is_open() && std::getline(File,line))
            {
                try{
                    data d1 = {{atoi(line.c_str()), atoi(line.c_str() + 5), atoi(line.c_str() + 8)} ,atof(line.c_str() + 11)};
                    dv.push_back(d1);
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << "Invalid input form a data" << std::endl;
                }
            }
            if(File.is_open())
                File.close();
            std::list<data>::iterator it;
            btc my_btc(dv);
            my_btc.check_File_input(input);
            if(input.is_open())
                input.close();
        }

    }
    else
        std::cout << "Error: could not open file.\n";
    return 0;
}