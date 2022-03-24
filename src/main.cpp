#include <iostream>

#include "Heap.hpp"
#include "Packets.hpp"
#include "Tree.hpp"
#include "string"
using namespace std;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while (std::cin.get() != '\n');
}

int main() {
  bool status = true;
  while (status) {
    system("clear");
    cout << "Choose the type of input data: \n";
    cout << "1. uint32_t - type of data drawn from algorithm \n";
    cout << "2. string - type of data read from file \n";
    cout << "3. Exit the program \n";
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
        uint32_t packetNo;
        cout << "Enter the number of packets : ";
        cin >> packetNo;
        Packets<uint32_t> packets(packetNo);
        Heap<uint32_t> heap(packets.packetTab);
        heap.print();
        status = false;
        break;
      }
      case 2: {
        Packets<string> packets;
        Heap<string> heap(packets.packetTab);
        heap.print();
        status = false;
        break;
      }
      case 3: {
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
