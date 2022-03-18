// C++ program for library management system

#include <bits/stdc++.h>//This header file includes all standard library.

#include <conio.h>// it is non standared header file. it is for getch()

#include <fstream>//it is for input/output file from  disk 

using namespace std;// it is common name for function defined in namespace 

#define ADMINUSER "le"//macro define password and username constant

#define ADMINPASSWORD "12"

#define USER "st"

#define USERPASSWORD "34"
int  fun1();// function declaration
int fun2();
// Book class
class Book {
private:
    int bookid;//integer datatype
    char title[20];//array of character
    char author[34];// author in array of character
    int shelf;//shelf of book in int data type
  
public:
    // Default Constructor for  accssing private access specifier
    Book()
    {
        bookid = 0;
        strcpy(title, "null");//intializing attribute or variable
        strcpy(author,"null");
        shelf=0;
    }
  
    //member Function for taking book data
    void getBookData()
    {
		cout<<"\nenter the book  title : "; 
             
       cin.ignore();
        
        cin.getline(title, 19);
        
        cout << "\nenter the book book id in number : ";
		
        cin >>bookid;
        
        cout<<"\nenter the  author  name of book : ";
        cin.ignore();
        cin.getline(author,34);
        
        cout<<"\nenter the shelf number of book store : ";
        
        cin>>shelf;
    }
    // Function for showing book data
    void showBookData()
    {
    	
    	cout <<title<<setw(16)<<author<<setw(16)<<bookid<<setw(16)<<shelf<<setw(16)<<endl;
             
    }
  
    int storeBook();
    void viewAllBooks();
    void searchBook(char*);//function declaration within a class
    void deleteBook(char*);
    void updateBook(char*);
};
  
    //student class
     class student  {
private:
    char sex;//char datatype
    char btitle[20];//array of character for storing book borrowed to student
    char sdtname[34];//  book author in array of character
    char dept[56];//for storing department of student who take the book
  
public:
    // Default Constructor for  accssing private access specifier
    student()
    {
        
        strcpy(btitle, "null");//intializing attribute
        strcpy(sdtname,"null");
        strcpy(dept,"null");
        sex;
    }
  
    // Function for taking book data
    void sdtData()
    {
		cout<<"\nenter the title of book which given to student : "; 
             
        cin.ignore();
        
        cin.getline(btitle, 19);
        
        cout << "\nenter the  student name who take the book : ";
		
		cin.ignore();
		
        cin.getline(sdtname,34);
        
        cout<<"\nenter student department : ";
        
        cin.ignore();
        
        cin.getline(dept,34);
        
        cout<<"\nenter sex f or m of student : ";
        
        cin>>sex;
    }
	
	void  issueBook();
    void  borrowBook();// function declaration within a class
    void  returnBook();
	
  };
  
 // Function to implement the store of
// all the books
int Book::storeBook()
{
    
        ofstream fout;
  
        // In the below line open function
        // used to open files. If the file
        // does not exist then it will
        // create the file "myfile3.txt"
        
        fout.open("myfile3.txt", ios::app);
        
        if(!fout)
		{
			cout<<"\ncan not open the file";
		}
        
        else
		{
			getBookData();
			
			// Write function is used for
        // data to write in the file
        
			 fout.write((char*)this, sizeof(*this));
        
		}
          
          
        fout.close();
        
        return (1);
    }
  
  // Function to view all recorded Book
void Book::viewAllBooks()
{
    ifstream fin;
  
    // Open function open file named
    // myfile.txt
    fin.open("myfile3.txt", ios::in);
    
    if (!fin)
	{
		
	cout << "File not found";
    
	}	
  
    else {
        
		fin.read((char*)this, sizeof(*this));
  
  	  cout<<setw(16)<<"book title"<<setw(16)<<"bookid"<<setw(16)<<"book price"<<setw(16)<<"bookshelf"<<setw(16)<<endl;
       
	    // Until end of file is
        // not reached
        while (!fin.eof()) {
            
			showBookData();
  
            // read is object of ifstream
            // class which is used for
            // read data of file
           
		    fin.read((char*)this, sizeof(*this));
        }
        
		fin.close();
    }
}
  
  // Function to search the Book
void Book::searchBook(char* t)
{
    int counter = 0;
    
	ifstream fin;
    
	fin.open("myfile3.txt", ios::in );
  
    // If file is not found
    if (!fin)
	{
		cout << "File not found";
		
    }
		
    else {
        fin.read((char*)this, sizeof(*this));
        
  	  
        // Until end of file is not reached
        while (!fin.eof()) {
           
		    if (!strcmp(t, title)) {
               	
		       cout<<setw(16)<<"book title"<<setw(16)<<"bookid"<<setw(16)<<"book price"<<setw(16)<<"bookshelf"<<setw(16)<<endl;
			   
			   showBookData();
               
			    counter++;
            }
           
		    fin.read((char*)this, sizeof(*this));
        }
        
		if (counter == 0)
           
		    cout << "No record found";
       
	 fin.close();
    }
}
  
  // Function for update book data
void Book:: updateBook(char* t)
{
    fstream file;
  
    // Open the file in the same directory as .cpp file for handling data
    file.open("myfile3.txt",
              ios::in | ios::out | ios::ate);
    
		  file.seekg(0);
    
	  file.read((char*)this, sizeof(*this));
  
    // Read the file
    while (!file.eof()) {
       
	    if (!strcmp(t, title))
		 {
            getBookData();
  
           file.seekp(file.tellp() - sizeof(*this));
            
			file.write((char*)this, sizeof(*this));
        }
       
	    file.read((char*)this, sizeof(*this));
    }
  
         // Close the file
          file.close();
}
  
// Function for delete book data recorded in the previous

void Book::deleteBook(char* t)
{
    ifstream fin;
   
    ofstream fout;
   
    fin.open("myfile3.txt", ios::app );// opening file
    
    if (!fin)
	{ 
	 cout << "\n File not found";
    }
 else {
        fout.open("tempfile.txt", ios::app);
        
        fin.read((char*)this, sizeof(*this));
  
        // Until end of file is not reached
        while (!fin.eof()) 
		{
            if (strcmp(title, t))
            {	
                fout.write((char*)this, sizeof(*this));
	     	}
            
                fin.read((char*)this, sizeof(*this));
        }
             fin.close();
        
		     fout.close();
             
			 remove("myfile3.txt");
            
			 rename("tempfile.txt", "myfile3.txt");
             
			 cout<<"deleted succssfully"<<endl;
  
  	     }

	   }
	   
	 
	   //function for implementing borrow book
	   //borrow function to record given books to student  
	   
void student ::borrowBook()
  {
	//creating fout object
	
        ofstream fout;
  
        // In the below line open function
        // used to open files. If the file
        // does not exist then it will
        // create the file "zemero.txt"
        
        fout.open("zemero.txt", ios::app);//we used app flag
        
        if(!fout)
		{
			cout<<"file not found"<<endl;
		}
		
		else
		{
		
        sdtData();
        // Write function is used for
        // data to write in the file
        
        fout.write((char*)this, sizeof(*this));
        
		}
        fout.close();
        
        cout<<"\nend.........................";
        
        getch();
        
   }
  
    // issue book to view books which are given to students and also
    //to view who take them
void student::issueBook()
{
      ifstream fin;
  
    // Open function open file named
    // zemero.txt
    fin.open("zemero.txt", ios::in);
    
    if (!fin)
    	
	cout << "File not found";
    	
    else 
	{
        fin.read((char*)this, sizeof(*this));
  
  	  cout<<setw(16)<<"book title"<<setw(16)<<"student name"<<setw(16)<<"student sex"<<setw(16)<<"student department"<<setw(16)<<endl;
       
	   
	    // Until end of file is
        // not reached
        while (!fin.eof()) {
            
            cout <<setw(16)<<btitle<<setw(16)<<sdtname<<setw(16)<<sex<<setw(16)<<dept<<setw(16)<<endl;
             
            // read is object of ifstream
            // class which is used for
            // read data of file
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        
        cout<<"\nthe borrowed book it is";
    }
}
    
    
    
   // Function for deleting borrowed
   // book in the previous
void student::returnBook(){
      
	   char name[45];
       
	   cout<<"enter student name"<<endl;
       
	   cin.ignore();
      
	   cin.getline(name,34);
       
	   ifstream fin;
      
	   ofstream fout;
      
	   fin.open("zemero.txt", ios::app );// opening file
    
    if (!fin)
	{
    	 cout << "\n File not found";
    }
    
    else {
        
		fout.open("tempfile.txt", ios::app);// opening temporry file for coping
        
        fin.read((char*)this, sizeof(*this));
  
        // Until end of file is not reached
        while (!fin.eof()) 
		{
            
        if (strcmp(sdtname, name))
		{     
        fout.write((char*)this, sizeof(*this));
		}
            
		fin.read((char*)this, sizeof(*this));
        
		}
       
	    fin.close();// closing file inorderd not to leak memory
        
		fout.close();
        
		remove("zemero.txt");
        
		rename("tempfile.txt", "zemero.txt");// renaming
        
		cout<<"deleted succssfully"<<endl;
   
     }

 }
  
 
	// function which used to make structured our program   
  
  int  fun1()
  {
      char adminUser[10];

        char adminPassword[10];


        system ("cls");

        cout << "\n ---------- librarian Login -------";

        cout << "\n\n Please enter your username: ";

        cin >> adminUser;//                entering identification

        cout << "\n Please enter your password:";

        cin >> adminPassword;

        if ((strcmp (adminUser, ADMINUSER) == 0) &&
        (strcmp (adminPassword, ADMINPASSWORD) == 0)){
        
		system ("cls");

        int choice= 0;

        while (choice != 9)
		{
	   	cout << "\nwellcome librarian to this l. Management system\n";
       
	    cout << "\n1.View all book record";
        
		cout << "\n2.Search book record";
       
	    cout << "\n3.Insert book record";
        
		cout << "\n4.Delete book record";
        
		cout << "\n5.Update book record";
        
		cout << "\n6.issue book";
        
		cout << "\n7.record borrowed book"<<endl;
       
	    cout << "\n8.returnbook"<<endl;
	    
	    cout << "\n9.exit";
        
		cout << "\n\nEnter your choice : ";
        
		cin >> (choice);
        
		return (choice);

          }	
	
       }
}

int fun2(){
	char studentUser[10];// it is for those who choose choose 2 i.e student

        char studentPassword[10];

        system ("cls");

        cout << "\n ---------- Student Login -------";

        cout << "\n\n Please enter your username: ";

        cin >> studentUser;

         cout << "\n Please enter your password:";

        cin >> studentPassword;

		
        if ((strcmp (studentUser, USER) == 0) &&
            (strcmp (studentPassword, USERPASSWORD) == 0)){
            int choice = 0;

            while (choice != 9){
   	        
            system("cls");
            
            cout << "\nlibrary Management";
    
            cout << "\n1.View all book record";
            
			cout << "\n2.Search book record";
   
            cout << "\n3.Exit";
            
			cout << "\n\nEnter your choice : ";
            
			cin >> (choice);
            
			return (choice);
				
        
		    }	
        }
       
     }

  	 
  	 
  	 
// Function to display the menuu of the
// current menuu-driver
int menuu()
{
	int num=0;
	while(num!=9){
		
		system ("cls");
		
		cout<<"welcome to library management system"<<endl;
	
		cout<<"\n1.librarian";
     	
        cout << "\n2. Student";
       
	    cout << "\n9. Exit";
	
		cout << "\n\nEnter your choice : ";

        cin >> num;
        
       if (num == 1)
		{
		
		return fun1();
		
       }	

        else if (num == 2)
		{
        	return fun2();
	
		}
		
         else
		 {
		 		cout<<"\ninvalid input";	 
		 }
	}
}

 	 // Driver Code
int main()
{
	//object of class student
    
	student b2;
  
    // Object of the class Book
    
	Book b1;
    
	char title[20];
 
    system("color 4f") ;
    
	while (1) 
	{
        system("cls");
       
	    switch (menuu()) {
        
		case 1:
            b1.viewAllBooks();
            break;
        	
        	case 2:
        		
            cout << "\nEnter title of "
                 << "book to search : ";
            cin.ignore();
            
			cin.getline(title, 19);
            
			b1.searchBook(title);
            break;	
		case 3:
            
			b1.storeBook();
            
			cout << "\nRecord inserted";
            
			break;
  
        
            case 4:
            cout << "\nEnter book title "
                 << "for delete record : ";
            cin.ignore();
            cin.getline(title, 19);
            b1.deleteBook(title);
            break;
  
        case 5:
            cout << "\nEnter book title "
                 << "to update record : ";
            cin.ignore();
            cin.getline(title, 19);
            b1.updateBook(title);
            break;
  
        case 6:
        	
			b2.issueBook();
            
			cout << "\n Thanks for using";
            
			cout << "\n Press any key to exit";
            
			getch();
            
			break;
        case 7:
  	
	        b2.borrowBook();
 	        
			 break;
  	    case 8:
  	    	
            b2.returnBook();
           
		    break;
        case 9:
        	
          break;
        default:
           
		    cout << "Invalid input";
        }
        getch();
    }
}


