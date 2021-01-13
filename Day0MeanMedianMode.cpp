#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <numeric> //accumulate
#include <iomanip> //setprecision
#include <cmath> //floor
#include <unordered_map>

double mean(std::vector<int> &myvector) {
  return (double) (accumulate(myvector.begin(), myvector.end(), 0) / (double) myvector.size());
}

double median(std::vector<int> &myvector) {
  if (myvector.size()%2 == 1) {
    int point = std::floor(myvector.size() / 2);
    std::vector<int>::const_iterator it = myvector.begin() + point;
    return (*it);
  } else {
    int point = myvector.size() / 2;
    std::vector<int>::iterator it1 = myvector.begin() + point - 1;
    std::vector<int>::iterator it2 = myvector.begin() + point;
    return ((*it1 + *it2) / 2.0);
  }
}

int mode(const std::vector<int> &myvector) { 
  std::unordered_map<int, int> mymap{};
  for (auto i : myvector) {
    ++mymap[i];
  }

  std::pair<int, int> MaxValue = std::make_pair (0, 0);
  std::unordered_map<int, int>::iterator it;
  for (it = mymap.begin(); it != mymap.end(); it++) {
      if (it -> second >= MaxValue.second) {
          MaxValue = std::make_pair (it -> first, it -> second);
      }
  }
  // check if all the values occured just once in the vector
  if (MaxValue.second == 1) { 
    MaxValue.first = myvector[0];
  }
  return MaxValue.first;
}

int main() {
  //std::vector<int> myvector {64630, 11735, 14216, 99233, 14470, 4978, 73429, 38120, 51135, 67060};
  
  std::vector<int> myvector {};
  int N{}, readValue{};
  std::cout << "number of elements: " << '\n';
  std::cin >> N;
  std::cout << "elemenets are: " << '\n';
  for (int i{}; i < N; i++) {
      std::cin >> readValue;
      myvector.push_back(readValue);
  }

  sort(myvector.begin(), myvector.end());
  std::cout << std::fixed << std::setprecision(1);
  std::cout << mean(myvector) << '\n';
  std::cout << median(myvector) << '\n';
  std::cout << mode(myvector) << '\n';

  return 0;
}



