#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

struct Student {
    string name;
    double grade;
};

class StudentList {
private:
    Student* students;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        Student* new_students = new Student[capacity];
        for (int i = 0; i < count; i++) {
            new_students[i] = students[i];
        }
        delete[] students;
        students = new_students;
    }

public:
    StudentList(int initial_capacity = 2) {
        capacity = initial_capacity;
        students = new Student[capacity];
        count = 0;
    }

    ~StudentList() {
        delete[] students;
    }

    void addStudent(const string& name, double grade) {
        if (count == capacity) {
            resize();
        }
        students[count].name = name;
        students[count].grade = grade;
        count++;
    }

    void removeStudent(const string& name) {
        for (int i = 0; i < count; i++) {
            if (students[i].name == name) {
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << "�������� " << name << " ��������." << endl;
                return;
            }
        }
        cout << "�������� � ��'�� " << name << " �� ��������." << endl;
    }

    double calculateAverageGrade() const {
        if (count == 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < count; i++) {
            sum += students[i].grade;
        }
        return sum / count;
    }

    void showStudents() {
        if (count == 0) {
            cout << "������ �������� �������." << endl;
            return;
        }
        cout << "������ ��������:" << endl;
        for (int i = 0; i < count; i++) {
            cout << students[i].name << ": " << students[i].grade << endl;
        }
    }
};

int main() {
    StudentList studentList;

    int choice;
    string name;
    double grade;

    while (true) {
        cout << "����:" << endl;
        cout << "1. ������ ��������" << endl;
        cout << "2. �������� ��������" << endl;
        cout << "3. ������� ������� ���" << endl;
        cout << "4. ������� ������ ��������" << endl;
        cout << "5. �����" << endl;
        cout << "������ ��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������ ��'� ��������: ";
            cin >> name;
            cout << "������ ������ ��������: ";
            cin >> grade;
            studentList.addStudent(name, grade);
            break;

        case 2:
            cout << "������ ��'� ��������, ����� ������� ��������: ";
            cin >> name;
            studentList.removeStudent(name);
            break;

        case 3:
            cout << "������� ���: " << studentList.calculateAverageGrade() << endl;
            break;

        case 4:
            studentList.showStudents();
            break;

        case 5:
            cout << "���������� ��������." << endl;
            return 0;

        default:
            cout << "���������� �������� ���i����!" << endl;
        }
    }
    return 0;
}