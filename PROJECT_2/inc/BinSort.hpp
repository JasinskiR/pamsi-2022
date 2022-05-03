#ifndef BINSORT_HPP
#define BINSORT_HPP
#include <fstream>
#include <iostream>

#include "Data.hpp"
void bSort(std::vector<Film>& movies,
           std::vector<std::vector<Film>>& movieByRate);
void binSort(std::vector<Film> movies);
void saveToFile(std::vector<std::vector<Film>>& movies);
#endif