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



//
//
//#include<iostream>
//#include<fstream>
//#include<iomanip>
//#include<cstdlib>
//#include<string>
//using namespace std;
//
//const string DATA_FILE = "customers.txt";
//const string DELETE_FILE = "deleted_customers.txt";
//
//bool login() {
//    string email, password;
//    cout<<"Enter email: ";
//    cin>>email;
//    cout<<"Enter password: ";
//    cin>>password;
//    return (email=="admin@gmail.com" && password=="1234");
//}
//
//void bookRoom() {
//    string name, cnic, phone, room;
//    int days;
//    float price, bill;
//    float* pBill = &bill;
//
//    cout<<"Enter Name: ";
//    cin>>name;
//    cout<<"Enter CNIC: ";
//    cin>>cnic;
//    cout<<"Enter Phone: ";
//    cin>>phone;
//    cout<<"Enter Room Type (Standard/Deluxe): ";
//    cin>>room;
//    cout<<"Enter Days of Stay: ";
//    cin>>days;
//
//    if(room == "Deluxe") price = 4000;
//    else if(room == "Standard") price = 3000;
//    else price = 3500;
//
//    *pBill = days * price;
//
//ofstream out("customers.txt", ios::app);  // Direct file name (as const char*)
//
//    if(!out) {
//        cout<<"Error opening file!"<<endl;
//        return;
//    }
//
//    out<<left<<setw(20)<<name
//       <<setw(15)<<cnic
//       <<setw(15)<<phone
//       <<setw(10)<<room
//       <<setw(5)<<days
//       <<setw(10)<<*pBill<<endl;
//
//    out.close();
//    cout<<"\nRoom booked successfully. Bill = Rs."<<*pBill<<endl;
//}
//
//void findCustomer() {
//    string searchCNIC, name, cnic, phone, room;
//    int days;
//    float bill;
//    bool found = false;
//
//    cout<<"Enter CNIC to search: ";
//    cin>>searchCNIC;
//
//ifstream in("customers.txt");
//
//    if(!in) {
//        cout<<"customers.txt not found.\n";
//        return;
//    }
//
//    while(in>>name>>cnic>>phone>>room>>days>>bill) {
//        if(cnic == searchCNIC) {
//            found = true;
//            cout<<"Name: "<<name
//                <<" CNIC: "<<cnic
//                <<" Phone: "<<phone
//                <<" Room: "<<room
//                <<" Days: "<<days
//                <<" Bill: Rs."<<bill<<endl;
//            break;
//        }
//    }
//
//    in.close();
//    if(!found) cout<<"Customer not found.\n";
//}
//
//void deleteCustomer() {
//    string delCNIC, name, cnic, phone, room;
//    int days;
//    float bill;
//    bool found = false;
//
//    cout<<"Enter CNIC to delete: ";
//    cin>>delCNIC;
//
//ifstream in("customers.txt");
//    if(!in) {
//        cout<<"customers.txt not found.\n";
//        return;
//    }
//
//    ofstream temp("temp.txt");
//ofstream out("customers.txt", ios::app);  // For appending
//
//if (!out) {
//    cout << "Error opening file for writing!" << endl;
//    return;
//}
//
//    while(in>>name>>cnic>>phone>>room>>days>>bill) {
//        if(cnic == delCNIC) {
//            found = true;
//            out<<left<<setw(20)<<name
//                      <<setw(15)<<cnic
//                      <<setw(15)<<phone
//                      <<setw(10)<<room
//                      <<setw(5)<<days
//                      <<setw(10)<<bill<<endl;
//        } else {
//            temp<<left<<setw(20)<<name
//                <<setw(15)<<cnic
//                <<setw(15)<<phone
//                <<setw(10)<<room
//                <<setw(5)<<days
//                <<setw(10)<<bill<<endl;
//        }
//    }
//
//    in.close();
//    temp.close();
//    out.close();
//
//    remove(DATA_FILE.c_str());
//    rename("temp.txt", DATA_FILE.c_str());
//
//    if(found) cout<<"Customer deleted and archived successfully.\n";
//    else cout<<"Customer not found.\n";
//}
//
//void showDeleteHistory() {
//    string name, cnic, phone, room;
//    int days;
//    float bill;
//
//    ifstream in("customers.txt");
//    if(!in) {
//        cout<<"No deleted customers found.\n";
//        return;
//    }
//
//    cout<<"\nDeleted Customer History:\n";
//    cout<<left<<setw(20)<<"Name"
//        <<setw(15)<<"CNIC"
//        <<setw(15)<<"Phone"
//        <<setw(10)<<"Room"
//        <<setw(5)<<"Days"
//        <<setw(10)<<"Bill"<<endl;
//    cout<<string(75, '-')<<endl;
//
//    while(in>>name>>cnic>>phone>>room>>days>>bill) {
//        cout<<left<<setw(20)<<name
//            <<setw(15)<<cnic
//            <<setw(15)<<phone
//            <<setw(10)<<room
//            <<setw(5)<<days
//            <<setw(10)<<bill<<endl;
//    }
//
//    in.close();
//}
//
//void eventBooking() {
//    string type, date;
//    int guests;
//
//    cout<<"Enter Event Type (Wedding/Party/Meeting): ";
//    cin>>type;
//    cout<<"Enter Event Date (DD-MM-YYYY): ";
//    cin>>date;
//    cout<<"Enter Number of Guests: ";
//    cin>>guests;
//
//    ofstream out("events.txt", ios::app);
//    if(!out) {
//        cout<<"Error opening events file.\n";
//        return;
//    }
//
//    out<<type<<"\t"<<date<<"\t"<<guests<<endl;
//    out.close();
//
//    cout<<"Event booked successfully.\n";
//}
//
//int main() {
//    if(!login()) {
//        cout<<"Invalid login. Exiting...\n";
//        return 0;
//    }
//
//    int choice;
//    do {
//        cout<<"\n--- Hotel Management Menu ---\n";
//        cout<<"1. Book Room\n";
//        cout<<"2. Find Customer\n";
//        cout<<"3. Delete Customer\n";
//        cout<<"4. Show Delete History\n";
//        cout<<"5. Book Event\n";
//        cout<<"6. Exit\n";
//        cout<<"Enter your choice: ";
//        cin>>choice;
//
//        switch(choice) {
//            case 1: bookRoom(); break;
//            case 2: findCustomer(); break;
//            case 3: deleteCustomer(); break;
//            case 4: showDeleteHistory(); break;
//            case 5: eventBooking(); break;
//            case 6: cout<<"Exiting...\n"; break;
//            default: cout<<"Invalid choice.\n";
//        }
//    } while(choice != 6);
//
//    return 0;
//}
