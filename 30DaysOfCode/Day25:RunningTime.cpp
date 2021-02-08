#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

std::string isPrime (long long int n) {
  if (n <= 1) {
    return "Not prime";
  } else if (n == 2 || n == 3 || n == 5) {
    return "Prime";
  } else if (n%2 == 0 || n%3 == 0 || n%5 == 0) {
    return "Not prime";
  }

  long  long int x = pow(n, 0.5);
  long long int check = x / 5;
  for (long long int i{1}; i <= check; i++) {
    if (n%(6*i - 1) == 0 || n%(6*i + 1) == 0) {
      return "Not prime";
    }
  }

  return "Prime";
}

int main() {

    long long int numCases{};
    cin >> numCases;
    int j{};
    vector<long long int> n{};
    for (long long int i{}; i < numCases; i++) {
      cin >> j;
      n.push_back(j);
    }
    for (long long int i{}; i < numCases; i++) {
      cout <<  isPrime(n[i]) << '\n';
    }

  return 0;
}