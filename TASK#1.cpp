#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void save_Book_data()
{
    ifstream Bookfile("file.txt");
    ofstream save_file("save.txt");
    if(!Bookfile)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    while(getline(Bookfile, line))
    {
        save_file<<line<<endl;
    }
    }
    Bookfile.close();
    save_file.close();
    cout<<"\nData saved successfully.\n"<<endl;
}
void delete_data_file()
{
    cout<<"\n\t\t\t\t\t\"How do you want to delete the data.\"\n"<<endl;
    cout<<" 1 : Delete the data by Book ID\n";
    cout<<" 2 : Delete the data by Book Title\n"<<endl;
    cout<<"Enter the choice.\n";
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        int ID;
        cout<<"Enter the Book ID you want to delete:  "<<endl;
        cin>>ID;
        cout<<endl;
        ifstream Bookfile("file.txt");
        ofstream Tempfile("temp.txt");
        string line;
        bool found = false;
        while(getline(Bookfile, line))
        {
            if(line.find(to_string(ID)) == string::npos)
            {
                Tempfile<<line<<endl;
            }
            else
            {
                found = true;
            }
        }
        Bookfile.close();
        Tempfile.close();
        remove("file.txt");
        rename("temp.txt", "file.txt");
        if(found)
        {
            cout<<"Book deleted successfully.\n";
        }
        else
        {
            cout<<"Sorry Data Not Found\n";
        }
    }
    else if(choice == 2)
    {
        string book_nam;
        cout<<"Enter the Book Title you want to delete:  "<<endl;
        cin.ignore();
        getline(cin, book_nam);
        ifstream Bookfile("file.txt");
        ofstream Tempfile("temp.txt");
        string line;
        bool found = false;
        while(getline(Bookfile, line))
        {
            if(line.find(book_nam) == string::npos)
            {
                Tempfile<<line<<endl;
            }
            else
            {
                found = true;
            }
        }
        Bookfile.close();
        Tempfile.close();
        remove("file.txt");
        rename("temp.txt", "file.txt");
        if(found)
        {
            cout<<"Book deleted successfully.\n";
        }
        else
        {
            cout<<"Sorry Data Not Found\n";
        }
    }
    else
    {
        cout<<"Invalid choice\n";
    }
}

void Display_Books()
{
    ifstream Bookfile("file.txt");
    string line;
    cout<<"Book_ID||Book_Title||Book_Author||Book_Price||Book_Quantity\n" << endl;
    cout<<"===============================================================================================\n";
    cout<<"The Available Books are :\n"; 
    while(getline(Bookfile, line))
    {
        cout<<endl;
        cout<<line<<endl;
    }
    Bookfile.close();
}
struct add_Book
{
    int bok_id, price,quant;
    string bok_name,author;
};
void Add_Book()
{
    add_Book bk[10];
    for(int i = 0; i<1; i++)
    { 
        int bok_id,price,quant;
        string bok_name,author;
        cout<<"\nEnter the New Book Details: \n";
        cout<<endl;
        cout<<"============================================================================================================\n";
        cout<<"Enter the New Book id:";
        cin>>bk[i].bok_id;
        cout<<"Enter the New Book Price:";
        cin>>bk[i].price;
        cin.ignore(); 
        cout<<"Enter the New Book author:";
        getline(cin, bk[i].author);
        cout<<"Enter the Book title:";
        getline(cin, bk[i].bok_name);
        cout<<"Enter the New Book Quantity:";
        cin>>bk[i].quant;
        cout<<endl;
        }
        ofstream Bookfile("file.txt", ios::app);
        for(int i = 0; i<1; i++)
        {
        cout<<"The new Book is :\n";
        cout<<"============================================================================================================\n";
        cout<<"Book_ID||Book_Tittle||Book_Author||Book_Price||Book_Quantity\n";
        cout<<"===================================================\n";
        Bookfile<<bk[i].bok_id<<"    \t "<<bk[i].bok_name<<"    \t "<<bk[i].author<<" \t  "<<bk[i].price<<"\t  "<<bk[i].quant<<endl;
        cout<<bk[i].bok_id<<"\t"<<bk[i].bok_name<<"\t"<<bk[i].author<<"\t"<<bk[i].price<<"\t"<<bk[i].quant<<endl;
        }
       Bookfile.close();
}

void Search_Books()
{
    int choice;
    cout<<"\n\t\t\"From which way you want to search the Book in Library Management\" \n";
    cout<<endl;
    cout<<"1 : \t\t\t\tSearch a Book by Book Id\n";
    cout<<"2 : \t\t\t\tSearch a Book by Book Title\n";
    cout<<endl;
    cout<<"Please Enter the Choice:   "<<endl;
    cin>>choice;
    cin.ignore(); // To ignore the newline character left in the buffer
    if (choice == 1)
    {
        int ID;
        cout<<"Enter the Book Id No: ";
        cin>>ID;
        bool found = false;
        ifstream Bookfile("file.txt");
        string line;
        while(getline(Bookfile, line))
        {
            if (line.find(to_string(ID)) != string::npos)
            {
                cout<<"Book_ID||Book_Title||Book_Author||Book_Price||Book_Quantity\n" << endl;
                cout<<"======_____________________________________________________________________________======\n";
                cout<<line<<endl;
                found = true;
                break;
            }
        }
        Bookfile.close();
        if(!found)
        {
            cout<<"Sorry Data Not Found\n";
        }
    else if(choice == 2)
    {
        string title;
        cout<<"Enter the Book Title: ";
        getline(cin, title);
        bool found = false;
        ifstream Bookfile("file.txt");
        string line;
        while(getline(Bookfile, line))
        {
            if(line.find(title) != string::npos)
            {
                cout<<"Book_ID||Book_Title||Book_Author||Book_Price||Book_Quantity\n"<<endl;
                cout<<"|||---=================================^^^|||^^^======================================---|||\n";
                cout<<line<<endl;
                found = true;
                break;
            }
        }
        Bookfile.close();
        if(!found)
        {
            cout<<"Sorry Data Not Found\n";
        }
    }
    else
    {
        cout<<"Invalid choice\n";
    }
}
}
struct Book_detail
{
    string Book_Author,Book_Tittle;
    int Book_ID,Book_Price,Book_Quantity;
};
void Store_Books_detail()
{
    Book_detail bk[10];
    for(int i = 0; i<1; i++)
    {
        ofstream Bookfile("file.txt", ios::app);
        cout<<"Enter the Book Details: \n";
        cout<<"\n----------============================---||||||---||||||---==============================---------------\n"<<endl;
        cout<<"Enter the Book ID: ";
        cin>>bk[i].Book_ID;
        cin.ignore();
        cout<<"Enter the Book Tittle: ";
        getline(cin, bk[i].Book_Tittle);
        //cin>>bk[i].Book_Tittle;
        cout<<"Enter the Book Author: ";
        getline(cin, bk[i].Book_Author);
        //1cin>>bk[i].Book_Author;
        cout<<"Enter the Book Price: ";
        cin>>bk[i].Book_Price;
        cout<<"Enter the Book Quantity: ";
        cin>>bk[i].Book_Quantity;
        cout<<endl;
        cout<<endl;
        Bookfile<<"Book_ID||Book_Tittle||Book_Author||Book_Price||Book_Quantity"<<endl;
        Bookfile<<bk[i].Book_ID<< "      \t   " <<bk[i].Book_Tittle<< "    \t   " <<bk[i].Book_Author<< "     \t    " <<bk[i].Book_Price<< "    \t   " <<bk[i].Book_Quantity<<endl;
        Bookfile.close();
    }
}

int main()
{
    int choic;
    do{
    cout<<"\n\n\t\t\t\t~|:= \" Welcome To Library Management System \" =:|~ \n"<<endl;
    cout<<"      \t\t \t\t ~|:= \" What do You Want \" =:|~ \n";
    cout<<"\n========================================================================================================================\n"<<endl;
    cout<<"Store the Book details||Add a new Books||Display all available Books||Search a Book||Save the Data|| Delete the data|| Exit \n"<<endl;
    cout<<"------------1------------------2---------------------3----------------------4---------------5----------------6-------------7-------\n";
    cout<<"=============================================================================================================================\n\n"<<endl;
    cin>>choic;
    cout<<"\n\t\t\t\tYou have selected the choice:   "<<choic<<endl;
    switch (choic)
    {
    case 1:
        Store_Books_detail();
        break;
    case 2:
        Add_Book();
        break;
    case 3:
        Display_Books();
        break;
    case 4:
        Search_Books();
        break;
    case 5:
        save_Book_data();
        break;
    case 6:
        delete_data_file();
        break;
    default:
        break;
    }
    } while(choic != 7);
    cout<<"\n\t\t\t\tYou have selected to Exit.\n";
    return 0;
}