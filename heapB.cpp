//Sort the student data in ascending order of grades.
#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    string name;
    int grade;
};

int compareByGradeAsc(const void* a, const void* b) {
    return ((Student*)a)->grade - ((Student*)b)->grade;
}

int main() {
    Student students[4] = {{"Alice", 85}, {"Bob", 90}, {"Charlie", 95}, {"David", 80}};

    qsort(students, 4, sizeof(Student), compareByGradeAsc);

    cout << "Students sorted by grades (ascending):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << students[i].name << ": " << students[i].grade << endl;
    }

    return 0;
}
