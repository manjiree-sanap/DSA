//Write a program to implement optimal storage tape using a greedy approach.
#include <iostream>
#include <algorithm>

using namespace std;

void optimalStorageOnTapesMagnetic(int random[], int size, int individualRetriveralTime[], float &meanRetriveralTime) {
    
    individualRetriveralTime[0] = random[0];
    for (int i = 1; i < size; i++) {
        individualRetriveralTime[i] = random[i] + individualRetriveralTime[i - 1];
    }

    meanRetriveralTime = individualRetriveralTime[size - 1] / size;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int random[] = {7, 3, 4, 9, 6, 12};
    int size = sizeof(random) / sizeof(random[0]);
    int individualRetriveralTime[size];
    float meanRetriveralTime;

    sort(random, random + size);

    optimalStorageOnTapesMagnetic(random, size, individualRetriveralTime, meanRetriveralTime);

    cout << "Sorted Program Lengths: ";
    printArray(random, size);

    cout << "Individual Retrieval Times: ";
    printArray(individualRetriveralTime, size);

    cout << "Mean Retrieval Time: " << meanRetriveralTime << endl;

    return 0;
}
