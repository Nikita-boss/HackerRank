#include <iostream>
#include <numeric> // accumulate
#include <vector>
#include <iomanip> //setprecision
using namespace std;

double Weighted_mean(vector<int> a, vector<int> b) {
  double some_value{};
  for (unsigned long i{}; i < a.size(); i++) {
    some_value += a[i] * b[i];
  }
  return some_value / accumulate(b.begin(), b.end(), 0);
}

int main() {
  
  //vector<int> myvector {10, 40, 30, 50, 20};
  //vector<int> myweight {1, 2, 3, 4, 5};

  int N{0};
  cin >> N;
  vector<int> myvector(N);
  for (int i{}; i < N; i++) {
    cin >> myvector[i];
  }
  vector<int> myweight(N);
  for (int i{}; i < N; i++) {
    cin >> myweight[i];
  }

  cout << fixed << setprecision(1);
  cout << Weighted_mean(myvector, myweight) << '\n';
  return 0;
}
