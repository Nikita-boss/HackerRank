#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> T;

// Ascending order
// Return total number of swaps - numSwaps
int bubble_sort(int n, T& a) {
    int numSwaps {0};
    for (int i = 0; i < n-1; i++) { 
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                numSwaps++;
                numberOfSwaps++;
            }
        }

        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0) {
            break;
        }
    }

    return numSwaps;
}

int main(int argc, char** argv) {
    int a, b;
    cin >> a;
    T v{};
    for (int i{}; i < a; i++) {
        cin >> b;
        v.push_back(b);
    }

    int numSwaps = bubble_sort(a, v);
    cout << "Array is sorted in " << numSwaps << " swaps." << '\n';
    cout << "First Element: " << *v.begin() << '\n';
    cout << "Last Element: " << *(v.end()-1) << '\n';

    return 0;
}