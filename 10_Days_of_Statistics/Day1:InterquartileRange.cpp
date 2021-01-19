#include <iostream>
#include <vector>
#include <algorithm> // sort, copy
#include <numeric> // accumulate
#include <cmath> // floor
#include <iomanip> // setprecision
using namespace std;

/*
The first line contains an integer, n, denoting the number of elements in arrays X and F. 
The second line contains n space-separated integers describing the respective elements of array X. 
The third line contains n space-separated integers describing the respective elements of array F.
F represents the respectice frequency of X's elements.
*/

double median(std::vector<int> myvector) {
  sort(myvector.begin(), myvector.end());
  if (myvector.size()%2 == 1) {
    int point = std::floor(myvector.size() / 2);
    double it = myvector[point];
    return it;
  } else {
    int point = myvector.size() / 2;
    double it1 = myvector[point - 1];
    double it2 = myvector[point];
    return (it1 + it2) / 2.0;
  }
}


vector<double> getQuartiles(vector<int> myvector) {
  vector<double> quartiles(3);
  quartiles[1] = median(myvector);
  if (myvector.size()%2 == 1) {
    vector<int> myvector_copy(myvector.begin(), myvector.begin() + (myvector.size() / 2));
    quartiles[0] = median(myvector_copy);
    myvector_copy.clear();
    for (vector<int>::iterator i = myvector.begin() + (myvector.size() / 2) + 1; i != myvector.end(); i++) {
      myvector_copy.push_back(*i);
    }
    quartiles[2] = median(myvector_copy);
  } else {
    vector<int> myvector_copy(myvector.begin(), myvector.begin() + (myvector.size() / 2));
    quartiles[0] = median(myvector_copy);
    myvector_copy.clear();
    for (vector<int>::iterator i = myvector.begin() + (myvector.size() / 2); i != myvector.end(); i++) {
      myvector_copy.push_back(*i);
    }
    quartiles[2] = median(myvector_copy);
  }
  return quartiles;
}


double interquartile_range(vector<int> myvector, vector<int> myfrequency) {
  vector<int> expanded_vector{};

  for (unsigned long i{}; i < myfrequency.size(); i++) { 
    for (int j{}; j < myfrequency[i]; j++) {
      expanded_vector.push_back(myvector[i]);
    }
  }

  vector<double> quartiles{getQuartiles(expanded_vector)};
  return (quartiles[2] - quartiles[0]);
}

int main() {
/*
  int N{0};
  cin >> N;
  vector<int> myvector(N);
  for (int i{}; i < N; i++) {
    cin >> myvector[i];
  }
  vector<int> myfrequency(N);
  for (int i{}; i < N; i++) {
    cin >> myvector[i];
  }
*/

  vector<int> myvector {6, 12, 8, 10, 20, 16};
  vector<int> myfrequency {5, 4, 3, 2, 1, 5};
  cout << fixed << setprecision(1);
  cout << interquartile_range(myvector, myfrequency) << '\n';

  return 0;
}
