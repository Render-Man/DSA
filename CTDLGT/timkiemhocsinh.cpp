#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    int dob;
    float avgScore;
};

void inputStudents(Student students[], int &n) {
    cout << "Nhap so luong hoc sinh (0 < n < 100): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hoc sinh thu " << i + 1 << ":\n";
        cout << "Ma hoc sinh: ";
        cin >> students[i].id;
        cout << "Ho va ten: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Ngay sinh: ";
        cin >> students[i].dob;
        cout << "Diem trung binh: ";
        cin >> students[i].avgScore;
    }
}

void displayStudents(const Student students[], int n) {
    cout << "\nDanh sach hoc sinh:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma hoc sinh: " << students[i].id << ", Ho va ten: " << students[i].name
             << ", Ngay sinh: " << students[i].dob << ", Diem trung binh: " << students[i].avgScore << endl;
    }
}

int searchStudentByName(const Student students[], int n, const string &name) {
    for (int i = 0; i < n; i++) {
        if (students[i].name == name) {
            return i;
        }
    }
    return -1;
}

int main() {
    Student students[100];
    int n;
    inputStudents(students, n);
    displayStudents(students, n);

    string searchName;
    cout << "\nNhap ho ten hoc sinh can tim: ";
    cin.ignore();
    getline(cin, searchName);
    int pos = searchStudentByName(students, n, searchName);
    if (pos == -1) {
        cout << "Khong tim thay hoc sinh co ten " << searchName << endl;
    } else {
        cout << "Thong tin hoc sinh:\n";
        cout << "Ma hoc sinh: " << students[pos].id << ", Ho va ten: " << students[pos].name
             << ", Ngay sinh: " << students[pos].dob << ", Diem trung binh: " << students[pos].avgScore << endl;
    }

    return 0;
}
