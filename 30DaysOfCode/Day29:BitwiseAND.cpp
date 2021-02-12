#include <iostream>
#include <vector>
using namespace std;


int bitAND (int x, int check) {
  if (x == 1) {
    return 0;
  }

  vector<int> myvec1{};
  vector<int> myvec2 {};

  for (int i{1}; i <= x; i++) {
    myvec1.push_back(i);
  }

  for (int i{}; i < x-1; i++) {
    for (int j{i+1}; j < x; j++) {
      myvec2.push_back(myvec1[i] & myvec1[j]);
    }
  }

  vector<int> solution{};
  for_each(myvec2.begin(), myvec2.end(), [&check, &solution] (int i) {if (i < check) { 
                                                                    solution.push_back(i); } } );
  return *max_element(solution.begin(), solution.end());
}

              
int main() {
  int t{};
  int x{};
  int check{};
  cin >> t;

  for (int i{}; i<t; i++) {
    cin >> x;
    cin >> check;
    cout << bitAND(x, check) << '\n';

  }

  return 0;
}