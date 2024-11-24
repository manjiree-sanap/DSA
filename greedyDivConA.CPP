#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find min and max using Divide and Conquer
void findMinAndMax(const vector<int>& arr, int low, int high, int& min, int& max) {
    // If the array contains only one element
    if (low == high) {
        if (min > arr[low]) min = arr[low];
        if (max < arr[low]) max = arr[low];
        return;
    }

    // If the array contains two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            if (min > arr[low]) min = arr[low];
            if (max < arr[high]) max = arr[high];
        } else {
            if (min > arr[high]) min = arr[high];
            if (max < arr[low]) max = arr[low];
        }
        return;
    }

    // If the array contains more than two elements
    int mid = (low + high) / 2;

    // Recursively find min and max in left and right halves
    findMinAndMax(arr, low, mid, min, max);
    findMinAndMax(arr, mid + 1, high, min, max);
}

int main() {
    vector<int> arr = {7, 2, 8, 5, 1, 10, 3, 6};
    int n = arr.size();

    // Initialize min and max
    int min = INT_MAX;
    int max = INT_MIN;

    // Call the function
    findMinAndMax(arr, 0, n - 1, min, max);

    // Print the results
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
