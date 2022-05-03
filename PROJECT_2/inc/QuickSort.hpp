#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP
#include <fstream>
#include <iostream>

#include "Data.hpp"

Film magic5(std::vector<Film> movieList, int low, int high);
void qSort(std::vector<Film>& movieList, int low, int high);
void quickSort(std::vector<Film> movies);
void saveToFile(std::vector<Film> movies);
#endif