#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "BinSort.hpp"
#include "Data.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"

using namespace std;
void wait4key();

int main() {
  Data records;
  bool status = true;
  bool statusAlg = true;
  while (status) {
    // system("clear");
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
        records.readFile();
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        wait4key();
        break;
      }
      case 2: {
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
          switch (algorithm) {
            case 1: {
              statusAlg = false;
              quickSort(records.getMovies());
              break;
            }
            case 2: {
              statusAlg = false;
              binSort(records.getMovies());
              break;
            }
            case 3: {
              statusAlg = false;
              mergeSort(records.getMovies());
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