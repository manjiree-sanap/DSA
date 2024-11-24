// Store data of students using hashing function for roll number and implement linear probing. Implement direct access file for any Database and perform following operations on it i)
//Create Database ii) Display Database iii) Search a record.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int TABLE_SIZE = 10;

// Structure to store student data
struct Student {
    int rollNo;
    string name;
    int age;
    
    // Constructor for initializing Student data
    Student(int r = -1, string n = "", int a = 0) : rollNo(r), name(n), age(a) {}
};

// Hash function for roll number
int hashFunction(int rollNo) {
    return rollNo % TABLE_SIZE;
}

// Class to handle student database using hash table with linear probing
class StudentDatabase {
    vector<Student> hashTable;
    
public:
    // Constructor to initialize the hash table
    StudentDatabase() {
        hashTable.resize(TABLE_SIZE, Student());
    }
    
    // Function to add a student to the database using linear probing
    void addStudent(Student student) {
        int index = hashFunction(student.rollNo);
        int startIdx = index;
        
        // Linear probing
        while (hashTable[index].rollNo != -1 && hashTable[index].rollNo != student.rollNo) {
            index = (index + 1) % TABLE_SIZE;
            if (index == startIdx) {
                cout << "Hash table is full, cannot insert more students." << endl;
                return;
            }
        }
        
        hashTable[index] = student;
        cout << "Student added successfully at index " << index << endl;
    }
    
    // Function to display the database
    void displayDatabase() {
        cout << "\nStudent Database:\n";
        cout << "Index\tRoll No\tName\tAge\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i].rollNo != -1) {
                cout << i << "\t" << hashTable[i].rollNo << "\t" 
                     << hashTable[i].name << "\t" << hashTable[i].age << endl;
            } else {
                cout << i << "\t---\t---\t---\n";
            }
        }
    }
    
    // Function to search for a student by roll number
    void searchStudent(int rollNo) {
        int index = hashFunction(rollNo);
        int startIdx = index;
        
        // Linear probing for searching
        while (hashTable[index].rollNo != -1) {
            if (hashTable[index].rollNo == rollNo) {
                cout << "Student found at index " << index << ":\n";
                cout << "Roll No: " << hashTable[index].rollNo << endl;
                cout << "Name: " << hashTable[index].name << endl;
                cout << "Age: " << hashTable[index].age << endl;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == startIdx) {
                break;
            }
        }
        
        cout << "Student with roll number " << rollNo << " not found.\n";
    }
    
    // Function to save database to file
    void saveToFile() {
        ofstream file("student_database.txt");
        if (file.is_open()) {
            for (const auto& student : hashTable) {
                file << student.rollNo << " " << student.name << " " << student.age << endl;
            }
            file.close();
            cout << "Database saved to file successfully.\n";
        } else {
            cout << "Failed to open file for writing.\n";
        }
    }
    
    // Function to load database from file
    void loadFromFile() {
        ifstream file("student_database.txt");
        if (file.is_open()) {
            Student student;
            while (file >> student.rollNo >> student.name >> student.age) {
                addStudent(student);
            }
            file.close();
            cout << "Database loaded from file successfully.\n";
        } else {
            cout << "Failed to open file for reading.\n";
        }
    }
};

int main() {
    StudentDatabase db;
    int choice, rollNo, age;
    string name;
    
    while (true) {
        cout << "\nMenu:\n1. Add Student\n2. Display Database\n3. Search Student\n4. Save to File\n5. Load from File\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                db.addStudent(Student(rollNo, name, age));
                break;
            case 2:
                db.displayDatabase();
                break;
            case 3:
                cout << "Enter Roll No to search: ";
                cin >> rollNo;
                db.searchStudent(rollNo);
                break;
            case 4:
                db.saveToFile();
                break;
            case 5:
                db.loadFromFile();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

