#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
    int id;
    string name;
    
public:
    Employee() {
        id = 0;
        name = "";
    }
    
    Employee(int _id, string _name) {
        id = _id;
        name = _name;
    }
    
    void setData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
    }
    
    void writeDataToFile() {
        ofstream outFile;
        outFile.open("employees.txt", ios::app);
        outFile << id << " " << name << endl;
        outFile.close();
    }
    
    void searchEmployee(int _id) {
        ifstream inFile;
        inFile.open("employees.txt", ios::in);
        bool found = false;
        int tempId;
        string tempName;
        while (inFile >> tempId >> tempName) {
            if (tempId == _id) {
                found = true;
                cout << "Employee ID: " << tempId << endl;
                cout << "Employee Name: " << tempName << endl;
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Employee not found." << endl;
        }
    }
    
    void editEmployee(int _id) {
        ifstream inFile("employees.txt");
        ofstream outFile("temp.txt", ios::out);
        int id;
        string name;
        bool found = false;
        while (inFile >> id >> name) {
            if (id == _id) {
                found = true;
                cout << "Enter new id and name: ";
                cin >> id >> name;
                outFile << id << " " << name << endl;
            } else {
                outFile << id << " " << name << endl;
            }
        }
        inFile.close();
        outFile.close();
        if (found) {
            remove("employees.txt");
            rename("temp.txt", "employees.txt");
            cout << "Employee record updated successfully." << endl;
        } else {
            cout << "Employee with ID " << _id << " not found." << endl;
        }
    }
    
    void deleteEmployee(int _id) {
        ifstream inFile;
        inFile.open("employees.txt", ios::in);
        ofstream outFile;
        outFile.open("temp.txt", ios::out);
        bool found = false;
        int tempId;
        string tempName;
        while (inFile >> tempId >> tempName) {
            if (tempId != _id) {
                outFile << tempId << " " << tempName << endl;
            } else {
                found = true;
            }
        }
        inFile.close();
        outFile.close();
        if (!found) {
            cout << "Employee not found." << endl;
        } else {
            remove("employees.txt");
            rename("temp.txt", "employees.txt");
            cout << "Employee deleted successfully." << endl;
        }
    }
    
    void displayAllEmployees() {
        ifstream inFile;
        inFile.open("employees.txt", ios::in);
        int tempId;
        string tempName;
        while (inFile >> tempId >> tempName) {
            cout << "Employee ID: " << tempId << endl;
            cout << "Employee Name: " << tempName << endl;
        }
        inFile.close();
    }
};

int main() {
    Employee emp;
    emp.setData();
    emp.writeDataToFile();
    emp.searchEmployee(201);
    emp.editEmployee(201);
    emp.deleteEmployee(202);
    emp.displayAllEmployees();
    return 0;
}
