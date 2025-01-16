#include <iostream>
#include<fstream>
#include<string>
using namespace std; 

void retrieve_data()
{
    ifstream MyfileHosp("fileNameHosp.txt");
    if(!MyfileHosp)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    cout<<"Patient_ID||Patient_Name||Patient_Disease||Patient_Age||Patient_Room\n"<<endl;
    cout<<"----------------=======-------------------------========--------------------========---------------------\n";
    cout<<endl;
    cout<<"\n \t === \"The Admitted Patients are:\" === :\n";
    while(getline(MyfileHosp, line))
    {
        cout<<endl;
        cout<<line<<endl;
    }
    }
    MyfileHosp.close();
}
void save_patient_data()
{
    ifstream MyfileHosp("fileNameHosp.txt");
    ofstream save_file("save.txt");
    if(!MyfileHosp)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    while(getline(MyfileHosp, line))
    {
        save_file<<line<<endl;
    }
    }
    MyfileHosp.close();
    save_file.close();
    cout<<"Data saved successfully.\n";
}

void delete_data_file()
{
    int choice;
    cout<<"\nDelete data by \"ID\"  enter the :  1\nDelete data by \"Name\" enter the : 2\n";
    cin>>choice;
    ifstream MyfileHosp("fileNameHosp.txt");
    ofstream delt_File("delte.txt");
    bool found = false;
    if(!MyfileHosp)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    string search_data;
    if(choice == 1)
    {
        int ID;
        cout<<"Enter the Patient ID you want to delete:  "<<endl;
        cin>>ID;
        cout<<endl;
        search_data = to_string(ID);
    }
    else if(choice == 2)
    {
        cout<<"Enter the Patient Name you want to delete:  "<<endl;
        cin.ignore();
        getline(cin, search_data);
    }
    while(getline(MyfileHosp, line))
    {
        if(line.find(search_data) == string::npos)
        {
            delt_File<<line<<endl;
        }
        else
        {
            found = true;
        }
    }
    }
    MyfileHosp.close();
    delt_File.close();
    if(found)
    {
        rename("delete.txt", "fileNameHosp.txt");
        remove("fileNameHosp.txt");
        rename("delte.txt", "fileNameHosp.txt");
        cout<<"\nData deleted successfully.\n";
    }
    else
    {
        remove("delte.txt");
        cout<<"Data not found.\n";
    }
}
void Display_allAdmit_Patients()
{
    ifstream MyfileHosp("fileNameHosp.txt");
    string line;
    cout<<"Patient_ID||Patient_Name||Patient_Disease||Patient_Age||Patient_Room\n"<<endl;
    cout<<"----------------=======-------------------------========--------------------========---------------------\n";
    cout<<endl;
    cout<<"\n \t === \"The Admitted Patients are:\" === :\n";
    while(getline(MyfileHosp, line))
    {
        cout<<endl;
        cout<<line<<endl;
    }
    MyfileHosp.close();
}
struct NewPatient
{
    string name,disease;
    int id,age,room;
};
void add_newPatient()
{
    NewPatient ad[10];
    for(int i = 0; i < 2; ++i)
    {
        cout<<"Enter the Patient ID: ";
        cin>>ad[i].id;
        cin.ignore();
        cout<<"Enter the Name: ";
        getline(cin, ad[i].name);
        cout<<"Enter the Patient Disease: ";
        getline(cin, ad[i].disease);

        cout<<"Enter the Patient Age: ";
        cin>>ad[i].age;
        cout<<"Enter the Patient Room: ";
        cin>>ad[i].room;
        cout<<endl;
    }
    ofstream MyfileHosp("fileNameHosp.txt" , ios::app);
    for(int i = 0; i < 2; ++i)
    {
        MyfileHosp<<ad[i].id << "   \t   " << ad[i].name << "      \t    " << ad[i].disease << "       \t      " << ad[i].age << "        \t    " << ad[i].room<<endl;
    }
    MyfileHosp.close();
    cout<<"Data Added Successfully\n";
}
void Search_Patient()
{
    int ID;
    cout<<"Enter the Patient Id No: ";
    cin>>ID;
    cout<<endl;
    bool found = false;
    ifstream MyfileHosp("fileNameHosp.txt");
    string line;
    while(getline(MyfileHosp, line))
    {
        if(line.find(to_string(ID)) != string::npos)
        {
            cout<<"Patient_ID" << "||" << "Patient_Name" << "||" << "Patient_Disease" << "||" << "Patient_Age" << "||" << "Patient_Room \n"<<endl;
            cout<<"=================^^^^^^=================^^^^^^^^===============^^^^^^================^^^^^^=================^^^^^^================\n";
            cout<<line<<endl;
            found = true;
            break;
        }
    }
    MyfileHosp.close();
    if(!found)
    {
        cout<<"Sorry Data Not Found\n";
    }
}
struct Patient_detail
{
    string Patient_Name,Patient_Disease;
    int Patient_ID,Patient_Age,Patient_Room;
};
void Patient_Detail()
{
    Patient_detail pd[10];
     ofstream MyfileHosp("fileNameHosp.txt" ,ios::app);
     for(int i = 0; i<2; ++i)
     {
        cout<<"Enter the Patient Details: \n";
        cout<<"\n----------============================------------------==============================---------------\n";
        cout<<"\nEnter the Patient ID: ";
        cin>>pd[i].Patient_ID;
        cin.ignore();
        cout<<"Enter the Name: ";
        getline(cin, pd[i].Patient_Name);
        cout<<"Enter the Ptient Disease: ";
        getline(cin, pd[i].Patient_Disease);  
        cout<<"Enter the Patient Age: ";
        cin>>pd[i].Patient_Age;
        cout<<"Enter the Patient Room: ";
        cin>>pd[i].Patient_Room;
        cout<<"\nThe data has been stored successfully.";
        cout<<endl;
        cout<<endl;
        MyfileHosp<<"Patient_ID||Patient_Name||Patient_Disease||Patient_Age||Patient_Room"<<endl;
        MyfileHosp<<pd[i].Patient_ID<<"   \t\t  "<<pd[i].Patient_Name<<"   \t     "<<pd[i].Patient_Disease<<"     \t     "<<pd[i].Patient_Age<<"        \t  "<<pd[i].Patient_Room<<endl;
        MyfileHosp.close();
    }
}
int main()
{  
    int choic;
do
{
    cout<<"\n \n \t\t~|:= \" Welcome To Hospital Patient Management System \" =:|~ \n";
    cout<<"     \n   \n \t\t\t ~|:= \" What do You Want \" =:|~ \n \n";
    cout<<"\n---======||=====||=====||======||=======||========||========||=====---\n";
    cout<<endl;
    cout<<"\nStore the Patient details||Add New Patient||Display all admitted Patients||Search a Patient|Retrieve the Data||Save the Data||Delete the data||You want to Exit\n"<<endl;
    cout<<endl;
    cout<<"-----------1-----------------------2------------------------3--------------------------4---------------5----------------6---------------7----------------8----------\n";
    cout<<"\n---===========||=============||==============||==============||==============||==============||=============||==============||==============||==================---\n\n"<<endl;
    cin>>choic;
    cout<<"\n\t\t\tYou have selected Choice: "<<choic<<endl;
    switch (choic)
    {
    case 1 :
    Patient_Detail();
        break;
    case 2 :
        add_newPatient();
        break;
    case 3 :
        Display_allAdmit_Patients();
        break;
    case 4 :
       Search_Patient();
        break;
    case 5 :
       retrieve_data();
        break;
    case 6 :
        save_patient_data();
        break;
    case 7 :
        delete_data_file();
        break;
    case 8 :
    cout<<"\n\n\t\t\t\t\t\"You have selected to Exit from the System.\"\n";
    exit(0);
        break;
    default:
        cout<<"Invalid Choice.\n";
        break;
    }
    }while(choic != 8);

    return 0;
}

