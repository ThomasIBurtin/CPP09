#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return(0);
    }

    std::map<std::string, float> data_dictionaire;

    try
    {
        parse_data(data_dictionaire);
        input(data_dictionaire, argv[1]);
    }
    catch (const std::exception & e)
    {
		std::cout << e.what() << std::endl;
    }
}