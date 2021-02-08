#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
on time -> fine = 0
same month -> 15(number of days late)
same year -> 500(number of months late)
else -> 10,000
*/

int FineCalculate(vector<int> a, vector<int> b) {
  int fine{};

  if (a[2] == b[2]) {
    if (a[1] == b[1]) {
      if (a[0] <= b[0]) {
        fine = 0;
      } else {
        fine = 15 * (a[0]-b[0]);
      }
    } else if (a[1] > b[1]) {
      fine = 500 * (a[1]-b[1]);
    }
  } else if (a[2] > b[2]) {
    fine = 10000;
  }

  return fine;
}

int main() {
  vector<int> return_date{};
  vector<int> due_date{};

  int input{};
  for (int i{}; i < 3; i++) {
    cin >> input;
    return_date.push_back(input);
  }
  for (int i{}; i < 3; i++) {
    cin >> input;
    due_date.push_back(input);
  }

  cout << FineCalculate(return_date, due_date) << '\n';

  return 0;
}



