#include "Heap.hpp"
#include "climits"
#include "cstdio"
#include "fstream"

template <typename message>
Heap<message>::Heap(std::vector<std::pair<uint32_t, message>> _pack) {
  addPackets(_pack);
}

template <typename message>
void Heap<message>::addPackets(
    std::vector<std::pair<uint32_t, message>> _pack) {
  packetArr = new std::pair<uint32_t, message>[2];
  sizeOfTab = 2;
  for (auto const &packet : _pack) {
    insertKey(packet);
  }
}

template <typename message>
void Heap<message>::heapify(uint32_t node) {
  // node in that function is an element which we have added
  if (node == 1 || packetArr[node / 2] < packetArr[node]) return;
  swap(packetArr[node / 2], packetArr[node]);
  heapify(node / 2);
}

template <typename message>
std::pair<uint32_t, message> Heap<message>::minValue() {
  return packetArr[1];
}

template <typename message>
void Heap<message>::pushDown(uint32_t node) {
  if (node * 2 > size) return;
  if (node * 2 + 1 > size) {
    if (packetArr[node * 2] < packetArr[node]) {
      swap(packetArr[node], packetArr[node * 2]);
      this->pushDown(node * 2);
    }
    return;
  }
  if (packetArr[node * 2] < packetArr[node * 2 + 1]) {
    if (packetArr[node * 2] < packetArr[node]) {
      swap(packetArr[node], packetArr[node * 2]);
      this->pushDown(node * 2);
    }
    return;
  }
  if (packetArr[node * 2 + 1] < packetArr[node]) {
    swap(packetArr[node], packetArr[node * 2 + 1]);
    this->pushDown(node * 2 + 1);
  }
}

template <typename message>
void Heap<message>::pop() {
  swap(packetArr[1], packetArr[size]);
  packetArr[size--] = std::make_pair(NULL, NULL);
  this->pushDown(1);
}

template <typename message>
void Heap<message>::insertKey(std::pair<uint32_t, message> element) {
  if (size + 1 >= sizeOfTab) {
    sizeOfTab *= 2;
    resize();
  }
  packetArr[++size] = element;
  heapify(size);
}

template <typename message>
void Heap<message>::resize() {
  std::pair<uint32_t, message> *tmp =
      new std::pair<uint32_t, message>[sizeOfTab];
  for (uint32_t i = 0; i <= size; ++i) {
    tmp[i] = packetArr[i];
  }
  delete[] packetArr;
  packetArr = tmp;
}

template <typename message>
uint32_t Heap<message>::getSize() {
  return size;
}

template <typename message>
void Heap<message>::print() {
  bool status = true;
  while (status) {
    std::cout << "\nThe message has " << size
              << "lines.\nIt can be printed out or saved to file."
              << std::endl;
    std::cout << "P - print the message out\n";
    std::cout << "S - save message to file\n";
    std::cout << "Your choice: ";
    char choice;
    while (true) {
      std::cin >> choice;
      if (!std::cin.good()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Option selection error. Try again: " << std::endl;
        continue;
      } else
        break;
    }
    switch (choice) {
      case 'p':
      case 'P': {
        std::cout << "Sorted message: \n";
        std::cout << "Ordinal no.: Massage: \n";
        while (getSize() > 0) {
          std::pair<uint32_t, message> tmp;
          tmp = minValue();
          pop();
          std::cout << tmp.first << "\t" << tmp.second << std::endl;
        }
        status = false;
        break;
      }
      case 's':
      case 'S': {
        std::cout << "It will be send to \"Sorted.txt\" file" << std::endl;
        std::ofstream newFile;
        std::string fileName = "Sorted.txt";
        newFile.open(fileName);
        if (newFile.good()) {
          newFile << "Sorted message: \n";
          newFile << "Ordinal no.: Massage: \n";
          while (getSize() > 0) {
            std::pair<uint32_t, message> tmp;
            tmp = minValue();
            pop();
            newFile << tmp.first << " " << tmp.second << std::endl;
          }
          std::cout << "File has been created or has been overwritten!"
                    << std::endl;
        } else
          throw std::runtime_error("The file " + fileName +
                                   " could not be created!");
        status = false;
        break;
      }
      default: {
        std::cout << "Unrecognized option !" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
      }
    }
  }
}
