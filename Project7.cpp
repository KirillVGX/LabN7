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
                cout << "Студента " << name << " видалено." << endl;
                return;
            }
        }
        cout << "Студента з ім'ям " << name << " не знайдено." << endl;
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
            cout << "Список студентів порожній." << endl;
            return;
        }
        cout << "Список студентів:" << endl;
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
        cout << "Меню:" << endl;
        cout << "1. Додати студента" << endl;
        cout << "2. Видалити студента" << endl;
        cout << "3. Вивести середній бал" << endl;
        cout << "4. Вивести список студентів" << endl;
        cout << "5. Вихід" << endl;
        cout << "Введіть ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введіть ім'я студента: ";
            cin >> name;
            cout << "Введіть оцінку студента: ";
            cin >> grade;
            studentList.addStudent(name, grade);
            break;

        case 2:
            cout << "Введіть ім'я студента, якого потрібно видалити: ";
            cin >> name;
            studentList.removeStudent(name);
            break;

        case 3:
            cout << "Середній бал: " << studentList.calculateAverageGrade() << endl;
            break;

        case 4:
            studentList.showStudents();
            break;

        case 5:
            cout << "Завершення програми." << endl;
            return 0;

        default:
            cout << "Некоректне значення варiанта!" << endl;
        }
    }
    return 0;
}