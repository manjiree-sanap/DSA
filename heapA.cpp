//The internship is offered to students based on rank obtained in the second year of graduation. Create a suitable non-linear data structure to identify the next topper student for internship. (Create max-heap).
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Student {
    string name;
    int grade;
};

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

void heapify(Student arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].grade > arr[largest].grade)
        largest = left;

    if (right < n && arr[right].grade > arr[largest].grade)
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void insertMaxHeap(Student arr[], int& n, Student newStudent) {
    n++;
    int i = n - 1;
    arr[i] = newStudent;

    while (i != 0 && arr[(i - 1) / 2].grade < arr[i].grade) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Student extractMax(Student arr[], int& n) {
    if (n <= 0)
        return {"", -1};

    if (n == 1) {
        n--;
        return arr[0];
    }

    Student root = arr[0];
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);

    return root;
}

void printNextTopper(Student arr[], int& n) {
    Student topper = extractMax(arr, n);
    if (topper.grade != -1) {
        cout << "Next topper: " << topper.name << " with grade: " << topper.grade << endl;
    } else {
        cout << "No students left!" << endl;
    }
}

int main() {
    Student heap[MAX];
    int n = 0;

    Student students[] = {{"Alice", 85}, {"Bob", 90}, {"Charlie", 95}, {"David", 80}};
    
    for (int i = 0; i < 4; i++) {
        insertMaxHeap(heap, n, students[i]);
    }

    printNextTopper(heap, n);
    printNextTopper(heap, n);

    return 0;
}