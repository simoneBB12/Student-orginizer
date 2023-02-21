#include <iostream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void myIntro();

struct Student{
int id;
string firstName;
string lastName;
int exam1;
int exam2;
int exam3;
float avg;
};
enum Options{display =1, addStu, updStu, avgExam, avgMin, avgMax, endP};

int main(int argc,char* argv[])
{
    myIntro();
    Student student[20];
    int stuInd = 0;
    int userChoice;
    do{
        //menu options
        cout << "1. Display list of students' information"<<endl;
        cout << "2. Add new student "<<endl;
        cout << "3. Update existing student "<<endl;
        cout << "4. Compute mean of the exams"<<endl;
        cout << "5. Compute minimum of the mean of the exams"<<endl;
        cout << "6. Compute maximum of the mean of the exams"<<endl;
        cout << "7. Exit program."<<endl;

        cout<<"use corresponding number for input"<<endl;
        cin >> userChoice;
        system("clear");

            switch (userChoice)
            {
            case 1:
            if(stuInd == 0)
            {cout<<"No student data: "<<endl;
           }
            else{
                for(int i =0;i<stuInd;i++)
                {
                    cout<<"ID: "<<student[i].id<<"  ";
                    cout<<"First name: "<<student[i].firstName << " ";
                    cout<<"Last name: "<<student[i].lastName << "   ";
                    cout<<"Exam 1: "<<student[i].exam1 << " ";
                    cout<<"Exam 2: "<<student[i].exam2 << "    ";
                    cout<<"Exam 3: "<<student[i].exam3 << " ";
                    cout<<endl;
                }
            }
                break;
            case 2:
                
                cout << "Enter student ID: ";
                cin >> student[stuInd].id;

                cout << "Enter student first name: ";
                cin >> student[stuInd].firstName;
                cout << "Enter student last name: ";
                cin >> student[stuInd].lastName;

                cout << "enter student exam 1: ";
                cin >> student[stuInd].exam1;

                cout << "Enter student exam 2: ";
                cin >> student[stuInd].exam2;

                cout << "Enter student exam 3: ";
                cin >> student[stuInd].exam3;

                stuInd++;
                if (stuInd>= 21)
                {
                   exit(1);
                }
                
                break;
            case 3:
                int updInp;
                cout<<"enter ID of student for update"<<endl;
                cin >> updInp;
                for(int i =0;i<stuInd;i++)
                {
                    if(updInp ==student[i].id)
                    {
                         cout << "Enter new student ID: ";
                        cin >> student[i].id;
                        cout << "Enter new student first name: ";
                        cin >> student[i].firstName;
                        cout << "Enter new student last name: ";
                        cin >> student[i].lastName;
                        cout << "enter new student exam 1: ";
                        cin >> student[i].exam1;
                        cout << "Enter new student exam 2: ";
                        cin >> student[i].exam2;
                        cout << "Enter new student exam 3: ";
                        cin >> student[i].exam3;
                    }
                }
                break;
            case 4:
                int total;
                for(int i =0;i<stuInd;i++)
                    { total = student[i].exam1+student[i].exam2+student[i].exam3;
                   student[i].avg =total/3;
                    cout << "Student ID:"<<student[i].id <<" Exam average:" << student[i].avg<<endl;
                    }
                break;
            case 5:
            int min;
            int i;
            int Id;
            min = student[0].avg;
                for(i = 0; i <stuInd;i++)
                {
                    if(student[i].avg < min)
                    {
                        min =student[i].avg;
                       
                    }
                   Id = student[i].id;
                }
                cout<<"Student ID: "<< Id <<" Student exam average: " <<min << endl;
                break;
            case 6:
            int max;
            int j;
            int ID;
            max = student[0].avg;
                for(j = 0; j < stuInd;j++)
                {
                    if(student[j].avg > max)
                    {
                        max = student[j].avg;
                       
                    }
                   ID = student[j].id;
                }
                cout<<"Student ID: "<< ID <<" Student exam average: " <<max << endl;              
                break;
            case 7:
                system("clear");
                cout<< "ending program goodbye!"<<endl;
                break;
            
            default:
            system("clear");
            cout<<"no valid output try again"<<endl;
            sleep(1);
                break;
            }


    }while(userChoice != 7);


 

    return 0;
}
void myIntro()
{
    cout <<"\tComputer Science"<<endl;
    cout<<"\tCSCE 1040.003 - Computer Science II" <<endl;
    cout <<"Simone Brewington\tsb1452\tsimonebrewington@my.unt.edu"<<endl;
}
