#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib> 
using namespace std;

void adminfunction();
void adddata();
void updatedata();
void studentmenu();
int mainmenu();
int adminverification();
int studentLogin();

//***************Main Function*************************
int main(){
    mainmenu();
    cout<<"\n\n\tThank you for visiting the system.\n\tSTAY BLESSED!";
    return 0;
}

//*******************MainMenu*******************************
int mainmenu(){
    int choice;
    while(true){
        system("cls");
        cout<<"\n\n\t\t--------------- Campus Core --------------------------\n\n";
        cout<<"1. Admin\n";
        cout<<"2. Student\n";
        cout<<"0. Exit\n\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                if(adminverification()){
                    adminfunction();
                } else {
                    cout<<"\nInvalid credentials! Please try again.\n";
                    system("pause");
                }
                break;

            case 2:
                if(studentLogin()){
                    studentmenu();
                } else {
                    cout<<"\nInvalid credentials! Please try again.\n";
                    system("pause");
                }
                break;

            case 0:
                cout<<"\nExiting the program. Goodbye!\n";
                return 0;

            default:
                cout<<"\nInvalid choice. Please try again.\n";
                system("pause");
        }
    }
}

//*******************adminverification*********************
int adminverification(){
    system("cls");
    cout<<"\n--------------- Admin Login -------------------------\n\n";
    string username, password;

    cout<<"Enter admin username: ";
    cin>>username;
    cout<<"Enter admin password: ";
    cin>>password;

    string validAdmin="admin";
    string validAdminPass="admin123";

    if(username == validAdmin && password == validAdminPass){
        cout<<"Your Admin Login is successful. Welcome!\n";
        return 1;
    }
    return 0;
}


//****************Student Login Function*******************
int studentLogin(){
    system("cls");
    cout<<"\n--------------- Student Login -------------------------\n\n";
    string username, password;

    string validStudent = "student";
    string validStudentPass = "student123";

    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    if(username == validStudent && password == validStudentPass){
        cout<<"Your Student Login is successful. Welcome!\n";
        return 1;
    }
    return 0;
}


//****************************Admin Function *************************
void adminfunction(){
    int choice;
    while(true){
        system("cls");
        cout<<"\n\t\t\t | Login As Admin | \n\n";
        cout<<"1. Add Student Data\n";
        cout<<"2. Update Record\n";
        cout<<"3. Exit to Main Menu\n";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                adddata();
                break;
            case 2:
                updatedata();
                break;
            case 3:
                return; // Exit to main menu
            default:
                cout<<"\nInvalid Option! Try again.\n";
                system("pause");
        }
    }
}


// ************************* ddd data Function ****************************
void adddata(){
    system("cls");
    string name;
    int rollno;
    string attendance, marks;
    int numStudents;

    cout<<"\nEnter the number of students: ";
    cin>>numStudents;

    // File handling to store student data
    ofstream datafile("data.txt", ios::app); // Append mode
    if(!datafile){
        cout<<"\nFailed to open file.\n";
        return;
    } else {
        datafile<<left<<setw(20)<<"Name"
                <<setw(15)<<"Roll Number"<<setw(10)<<"Marks"<<setw(5)<<"Attendance"<<"\n";
        datafile<<string(50, '-')<<"\n";

        for(int i=1; i<=numStudents; i++){
            cin.ignore();
            cout<<"\nEnter the name of Student "<<i<<": ";
            getline(cin, name);
            cout<<"Enter the Roll No of Student "<<i<<": ";
            cin>>rollno;
            cout<<"Enter the Marks of Student "<<i<<": ";
            cin>>marks;
            cout<<"Mark the Attendance of Student "<<i<<" (P/A): ";
            cin>>attendance;

            datafile<<left<<setw(20)<<name<<setw(15)<<rollno
                    <<setw(10)<<marks<<setw(5)<<attendance<<"\n";
        }

        cout<<"\nStudent data has been saved!\n";
        datafile.close();
        system("pause");
    }
}


//******************Update Data ************************
void updatedata(){
    system("cls");
    string oldData, newData;
    cout<<"\nEnter the old data: ";
    cin.ignore();
    getline(cin, oldData);
    cout<<"Enter the new data: ";
    getline(cin, newData);

    ifstream file("data.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile){
        cout << "Unable to open the file.\n";
        return;
    }

    string line;
    bool updated = false;

    while (getline(file, line)){
        if (line.find(oldData)!=string::npos){
            tempFile<<newData<<endl;
            updated = true;
        } else {
            tempFile<<line<<endl;
        }
    }

    file.close();
    tempFile.close();

    if (updated) {
        remove("data.txt");
        rename("temp.txt", "data.txt");
        cout<<"\nRecord updated successfully!\n";
    } else {
        cout<<"\nNo matching record found.\n";
    }

    system("pause");
}


//******************Student menu **********************
void studentmenu(){
    system("cls");
    cout<<"\n\t\t\t | Student Record | \n\n";

    ifstream datafile("data.txt");
    if(!datafile){
        cout<<"\nNo data found or file failed to open.\n";
        system("pause");
        return;
    }

    string line;
    while(getline(datafile, line)){
        cout<<line<<endl;
    }

    datafile.close();
    system("pause");
}



//============================================================================= THE END =====================================================================
