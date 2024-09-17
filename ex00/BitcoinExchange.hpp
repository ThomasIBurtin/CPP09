#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <limits.h>
#include <cstdlib>
#include <iomanip>

void parse_data(std::map<std::string, float> &data_dictionaire);
void input(std::map<std::string, float> &data_dictionaire, char *input_file);
std::string trim(const std::string& str);
void check_key(const std::string& key);
void check_value(float value);
std::map<std::string, float>::iterator find_key(std::map<std::string, float> &data_dictionaire, std::string& key);

#endif