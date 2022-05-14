#include "BinSort.hpp"

using namespace std;

void bSort(vector<Film>& movies, vector<vector<Film>>& movieByRate,
           uint64_t number) {
  for (uint64_t movie = 0; movie < number; ++movie) {
    movieByRate[static_cast<int>(movies[movie].getRating()) - 1].push_back(
        movies[movie]);
  }
}

void binSort(std::vector<Film> movies, uint64_t number, Data* records) {
  std::vector<Film> tmp = {movies.begin(), movies.begin() + number};
  std::vector<Film> sorted;
  vector<vector<Film>> movieByRate(10);

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  bSort(tmp, movieByRate, tmp.size());
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;

  for (auto& movies : movieByRate) {
    for (auto& element : movies) {
      sorted.emplace_back(element);
    }
  }
  records->checkSort(sorted);
  if (!records->getIfSorted()) {
    std::cout << "Movies were sorted incorrectly!" << std::endl;
    return;
  }

  records->setMedian(sorted, number);
  records->setAverage(sorted, number);
  records->setTime(elapsed_seconds.count());

  records->saveOrPrint(sorted, "BSorted.txt");
}