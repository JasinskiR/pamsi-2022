#ifndef MERGESORT_HPP
#define MERGESORT_HPP
#include <fstream>
#include <iostream>

#include "Data.hpp"

void mergeSort(std::vector<Film> movies);
void mSort(std::vector<Film>& movieList, std::vector<Film>& tmp, int low, int high);
void saveToFile(std::vector<Film> tmp);
#endif