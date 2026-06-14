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
                        string searchRoll;
                        string roll, name, department, status;
                         float cgpa;

                        cout << "\nEnter Roll Number to Search: ";
                         cin >> searchRoll;

                        ifstream file("students.txt");

                        bool found = false;

                         while(file >> roll)
                     {
                        if(roll == searchRoll)
                        {
                            found = true;

                            cout << "\nStudent Found!\n";
                            cout << "Roll Number: " << roll << endl;
                            break;
                            }
                        }

                            file.close();
                        
                            if(!found)
                            {
                                cout << "\nStudent Not Found!\n";
                            }
                }
                else if(studentChoice == 3)
                {
                   string searchRoll;
                    string roll, name, department;
                    float cgpa;
                
                    cout << "\nEnter Roll Number to Update: ";
                    cin >> searchRoll;
                
                    ifstream file("students.txt");
                    ofstream temp("temp.txt");
                
                    bool found = false;
                
                    while(file >> roll >> name >> department >> cgpa)
                    {
                        if(roll == searchRoll)
                        {
                            found = true;
                
                            cout << "\nEnter New Name: ";
                            cin >> name;
                
                            cout << "Enter New Department: ";
                            cin >> department;
                
                            cout << "Enter New CGPA: ";
                            cin >> cgpa;
                
                            temp << roll << " "
                                 << name << " "
                                 << department << " "
                                 << cgpa << endl;
                        }
                        else
                        {
                            temp << roll << " "
                                 << name << " "
                                 << department << " "
                                 << cgpa << endl;
                        }
                    }
                
                    file.close();
                    temp.close();
                
                    remove("students.txt");
                    rename("temp.txt", "students.txt");
                
                    if(found)
                        cout << "\nStudent Updated Successfully!\n";
                    else
                        cout << "\nStudent Not Found!\n";
                }
                else if(studentChoice == 4)
                {
                    string searchRoll;
                    string roll, name, department;
                    float cgpa;
                
                    cout << "\nEnter Roll Number to Delete: ";
                    cin >> searchRoll;
                
                    ifstream file("students.txt");
                    ofstream temp("temp.txt");
                
                    bool found = false;
                
                    while(file >> roll >> name >> department >> cgpa)
                    {
                        if(roll == searchRoll)
                        {
                            found = true;
                            continue;
                        }
                
                        temp << roll << " "
                             << name << " "
                             << department << " "
                             << cgpa << endl;
                    }
                
                    file.close();
                    temp.close();
                
                    remove("students.txt");
                    rename("temp.txt", "students.txt");
                
                    if(found)
                        cout << "\nStudent Deleted Successfully!\n";
                    else
                        cout << "\nStudent Not Found!\n";
                                }
                
                                break;
            }

             case 2:
                    {
                       int courseChoice;
                        
                            cout << "\n===== COURSE MANAGEMENT =====\n";
                            cout << "1. Add Course\n";
                            cout << "2. Search Course\n";
                            cout << "3. Update Course\n";
                            cout << "4. Delete Course\n";
                            cout << "0. Back\n";
                        
                            cout << "Enter Choice: ";
                            cin >> courseChoice;
                        
                            if(courseChoice == 1)
                            {
                                string code, name;
                                int creditHours;
                        
                                cout << "\nEnter Course Code: ";
                                cin >> code;
                        
                                cout << "Enter Course Name: ";
                                cin >> name;
                        
                                cout << "Enter Credit Hours: ";
                                cin >> creditHours;
                        
                                ofstream file("courses.txt", ios::app);
                        
                                file << code << " "
                                     << name << " "
                                     << creditHours << endl;
                        
                                file.close();
                        
                                cout << "\nCourse Added Successfully!\n";
                            }
                        
                            else if(courseChoice == 2)
                            {
                                    string searchCode;
                                    string code, name;
                                    int creditHours;
                                    bool found = false;
                                
                                    cout << "\nEnter Course Code to Search: ";
                                    cin >> searchCode;
                                
                                    ifstream file("courses.txt");
                                
                                    while(file >> code >> name >> creditHours)
                                    {
                                        if(code == searchCode)
                                        {
                                            found = true;
                                
                                            cout << "\n===== COURSE FOUND =====\n";
                                            cout << "Course Code : " << code << endl;
                                            cout << "Course Name : " << name << endl;
                                            cout << "Credit Hours: " << creditHours << endl;
                                
                                            break;
                                        }
                                    }
                                
                                    file.close();
                                
                                    if(!found)
                                    {
                                        cout << "\nCourse Not Found!\n";
                                    }
                            }
                        
                            else if(courseChoice == 3)
                            { 
                                string searchCode;
                                string code, name;
                                int creditHours;
                            
                                cout << "\nEnter Course Code to Update: ";
                                cin >> searchCode;
                            
                                ifstream file("courses.txt");
                                ofstream temp("temp.txt");
                            
                                bool found = false;
                            
                                while(file >> code >> name >> creditHours)
                                {
                                    if(code == searchCode)
                                    {
                                        found = true;
                            
                                        cout << "\nEnter New Course Name: ";
                                        cin >> name;
                            
                                        cout << "Enter New Credit Hours: ";
                                        cin >> creditHours;
                            
                                        temp << code << " "
                                             << name << " "
                                             << creditHours << endl;
                                    }
                                    else
                                    {
                                        temp << code << " "
                                             << name << " "
                                             << creditHours << endl;
                                    }
                                }
                            
                                file.close();
                                temp.close();
                            
                                remove("courses.txt");
                                rename("temp.txt", "courses.txt");
                            
                                if(found)
                                    cout << "\nCourse Updated Successfully!\n";
                                else
                                    cout << "\nCourse Not Found!\n";
                            }
                        
                            else if(courseChoice == 4)
                            {
                                cout << "\nDelete Course Coming Soon...\n";
                            }
                        
                            break;
                    }
               

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
