#include "BitcoinExchange.hpp"

void parse_data(std::map<std::string, float> &data_dictionaire)
{
    std::ifstream data("data.csv");
    if(!data.is_open())
        throw std::runtime_error("ImpossibleFile");
        
    std::string line;
    while (std::getline(data, line))
    {
        std::string key;
        std::string value_str;
        
        int comma_pos = line.find(',');
        key = line.substr(0, comma_pos);
        value_str = line.substr(comma_pos + 1);
        
        float value = std::atof(value_str.c_str());
        data_dictionaire[key] = value;
    }
    data.close();
}

std::string trim(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    
    if (start == std::string::npos)
        return "";
    
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    
    return str.substr(start, end - start + 1);
}

void check_key(std::string &key)
{   
    if (key.length() != 10 || key[4] != '-' || key[7] != '-')
        throw std::runtime_error("respect format");

    for (std::size_t i = 0; i < 10; ++i)
    {
        if (i != 4 && i != 7 && !std::isdigit(key[i]))
            throw std::runtime_error("respect format");
    }

    int year = std::atoi(key.substr(0, 4).c_str());
    int month = std::atoi(key.substr(5, 2).c_str());
    int day = std::atoi(key.substr(8, 2).c_str());

    if (year > 2024 || month > 12 || day > 31)
        throw std::runtime_error("respect format");
}

void check_value(float value)
{
    if(value < 0)
        throw std::runtime_error("Error: not a positive number.");
    if(value >= static_cast<float>(INT_MAX))
        throw std::runtime_error("Error: too large a number.");
}

std::map<std::string, float>::iterator find_key(std::map<std::string, float> &data_dictionaire, std::string& key)
{
    int year = atoi(key.substr(0, 4).c_str());
    int month = atoi(key.substr(5, 2).c_str());
    int day = atoi(key.substr(8, 2).c_str());

    std::map<std::string, float>::iterator it = data_dictionaire.find(key);
    if (it != data_dictionaire.end())
        return it;

    while (year >= 0)
    {
        while (month >= 1)
        {
            while (day >= 1)
            {
                std::ostringstream ss;
                ss << std::setw(4) << std::setfill('0') << year << '-'
                   << std::setw(2) << std::setfill('0') << month << '-'
                   << std::setw(2) << std::setfill('0') << day;

                std::string current_key = ss.str();
                it = data_dictionaire.find(current_key);
                if (it != data_dictionaire.end())
                    return it;

                day--;
            }
            day = 31;
            month--;
        }
        month = 12;
        year--;
    }
    return data_dictionaire.end();
}


void input(std::map<std::string, float> &data_dictionaire, char *input_file)
{
    std::ifstream input(input_file);
    if(!input.is_open())
        throw std::runtime_error("ImpossibleFile");

    std::string line;
    while (std::getline(input, line))
    {
        try
        {
            size_t pipe_pos = line.find('|');
            if (pipe_pos == std::string::npos)
                throw std::runtime_error("Error: bad input => " + line);


            std::string key = trim(line.substr(0, pipe_pos));
            std::string v = line.substr(pipe_pos + 1);
            float value = atof(v.c_str());
            check_key(key);
            check_value(value);

            std::map<std::string, float>::iterator it = find_key(data_dictionaire, key);
            std::cout << key << " => " << value << " = " << value * it->second << std::endl;
        }
        catch (const std::exception & e)
        {
		    std::cout << e.what() << std::endl;
	    }
    }
    input.close();
}