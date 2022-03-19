#include "Packets.hpp"

template <>
Packets<uint32_t>::Packets(uint32_t _packetNo) : packetNo(_packetNo) {
  for (uint32_t i = 0; i < packetNo; ++i) {
    packetTab.push_back(
        std::make_pair(i + 1, packetNo - i));  // iterator of messages
  }
  shuffle();
}

template <>
Packets<std::string>::Packets() {
  std::string tmpFirst, tmpSecond;
  std::cout << "Enter a file name (with *.txt): ";
  std::string fileName;
  std::cin >> fileName;
  std::size_t found = fileName.find(".txt");
  if (found == std::string::npos)
    throw std::invalid_argument(
        "There is no file extension or extension is not \".txt\" in " +
        fileName + "!");
  std::fstream file;
  file.open(fileName, std::ios::in);
  if (file.good()) {
    while (!file.eof()) {
      if (file >> tmpFirst) {
        if (getline(file, tmpSecond))
          packetTab.push_back(
              std::make_pair(std::stoul(tmpFirst, nullptr, 0), tmpSecond));
      }
    }
  } else
    throw std::invalid_argument("The file " + fileName +
                                "was not opened properly or the " + fileName +
                                "does not exist!");
}

template <typename message>
void Packets<message>::shuffle() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine rng(seed);
  std::shuffle(packetTab.begin(), packetTab.end(), rng);
}

template class Packets<uint32_t>;