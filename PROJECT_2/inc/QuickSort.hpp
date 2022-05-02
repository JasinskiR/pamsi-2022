#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <fstream>
#include <iostream>

#include "Data.hpp"

void quickSort(std::vector<Film> movies);
void saveToFile(std::vector<Film> movies);
#endif