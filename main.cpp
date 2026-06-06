#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "     CAMPUS ANALYTICS ENGINE\n";
        cout << "=================================\n";
        cout << "1. Student Management\n";
        cout << "2. Course Management\n";
        cout << "3. Attendance\n";
        cout << "4. Grades\n";
        cout << "5. Fee Tracker\n";
        cout << "6. Reports\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int studentChoice;

                cout << "\n===== STUDENT MANAGEMENT =====\n";
                cout << "1. Add Student\n";
                cout << "2. Search Student\n";
                cout << "3. Update Student\n";
                cout << "4. Delete Student\n";
                cout << "0. Back\n";

                cout << "Enter Choice: ";
                cin >> studentChoice;

                if(studentChoice == 1)
                {
                    string roll;
                    string name;
                    string department;
                    float cgpa;

                    cout << "\nEnter Roll Number: ";
                    cin >> roll;

                    cout << "Enter Name: ";
                    cin >> name;

                    cout << "Enter Department: ";
                    cin >> department;

                    cout << "Enter CGPA: ";
                    cin >> cgpa;

                    ofstream file("students.txt", ios::app);

                    file << roll << ","
                         << name << ","
                         << department << ","
                         << cgpa << ",active\n";

                    file.close();

                    cout << "\nStudent Added Successfully!\n";
                }
                else if(studentChoice == 2)
                {
                    cout << "\nSearch Student Option Selected\n";
                }
                else if(studentChoice == 3)
                {
                    cout << "\nUpdate Student Option Selected\n";
                }
                else if(studentChoice == 4)
                {
                    cout << "\nDelete Student Option Selected\n";
                }

                break;
            }

            case 2:
                cout << "\nCourse Management Selected\n";
                break;

            case 3:
                cout << "\nAttendance Selected\n";
                break;

            case 4:
                cout << "\nGrades Selected\n";
                break;

            case 5:
                cout << "\nFee Tracker Selected\n";
                break;

            case 6:
                cout << "\nReports Selected\n";
                break;

            case 0:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 0);

    return 0;
}