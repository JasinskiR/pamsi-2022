#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "BinSort.hpp"
#include "Data.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

using namespace std;
void wait4key();

int main() {
  Data lines;
  bool status = true;
  bool statusAlg = true;
  bool dataRead = false;
  uint64_t number = lines.getNumber();
  while (status) {
    system("clear");
    cout << "MENU" << endl;
    cout << "1. Choose file" << endl;
    cout << "2. Sort" << endl;
    cout << "0. Exit an app" << endl;
    cout << "Enter the number of the option: ";
    int choice;
    while (true) {
      cin >> choice;
      if (!cin.good()) {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Option selection error. Try again: " << endl;
        continue;
      } else
        break;
    }
    switch (choice) {
      case 1: {
        lines.readFile();
        dataRead = true;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
        break;
      }
      case 2: {
        if (!dataRead) {
          cout << "\n Data were not read from file. Nothing can be sort!"
               << endl;
          wait4key();
          break;
        }
        while (statusAlg) {
          cout << "Choose sorting algorithm" << endl;
          cout << "1. Quick Sort" << endl;
          cout << "2. Bin/Bucket Sort" << endl;
          cout << "3. Merge Sort" << endl;
          cout << "Enter the number of the option: ";
          int algorithm;
          while (true) {
            cin >> algorithm;
            if (!cin.good()) {
              cin.clear();
              cin.ignore(std::numeric_limits<int>::max(), '\n');
              cout << "Option selection error. Try again: " << endl;
              continue;
            } else
              break;
          }

          cout << "Number of movies: " << lines.getAllMovies() << endl;
          cout << "Enter the amount of movies to sort: ";
          while (true) {
            cin >> number;
            if (!cin.good() || number <= 0 || number > lines.getAllMovies()) {
              cin.clear();
              cin.ignore(std::numeric_limits<int>::max(), '\n');
              cout << "Input number error. Try again: " << endl;
              continue;
            } else
              break;
          }
          switch (algorithm) {
            case 1: {
              statusAlg = false;
              quickSort(lines.getMovies(), number, &lines);
              break;
            }
            case 2: {
              statusAlg = false;
              binSort(lines.getMovies(), number, &lines);
              break;
            }
            case 3: {
              statusAlg = false;
              mergeSort(lines.getMovies(), number, &lines);
              break;
            }

            default: {
              cout << "Unrecognized option !" << endl;
              cin.clear();
              cin.ignore(std::numeric_limits<int>::max(), '\n');
              wait4key();
            }
          }
          cout << std::setprecision(1) << std::fixed;
          cout << "\nAverage of rating: " << lines.getAverageRating() << endl;
          cout << "Median of rating: " << lines.getMedian() << endl;
          cout << std::setprecision(10) << std::fixed;
          cout << "Time of sorting: " << lines.getTime() << endl;
        }
        statusAlg = true;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
        break;
      }
      case 0: {
        status = false;
        break;
      }
      default: {
        cout << "Unrecognized option !" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
      }
    }
  }
  cout << "Quitting the program..." << endl;
}

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}