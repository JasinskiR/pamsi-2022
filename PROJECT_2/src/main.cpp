#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "Data.hpp"
#include "QuickSort.hpp"

using namespace std;
void wait4key();

int main() {
  Data records;
  bool status = true;
  while (status) {
    //system("clear");
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
        quickSort(records.getMovies());
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