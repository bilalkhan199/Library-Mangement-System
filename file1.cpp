#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Library{
	public:
	void login();
};


class Student:public Library{
	public:
	void login();
/*	void issue_book();
	void re_issue_book();  
	void view_book() ;  // view all books in database
	void demand_book() ;  //demand a book from a library person (reserving a book is also possible)
	void return_book() ;  //returning a book
	void return_deadline();   //check the deadline when to return a book
*/};
void Student::login()
{
	ifstream fout;
	fout.open("studentpassword.txt");
	string str , pass;
	string id,idd;
	cout<<"YOUR ROLL NO";
	cin>> idd;
	cout<<"YOUR PASSWORD: ";
	cin>>pass;
	
	
	if(fout.is_open())
	{
	while(fout >> id >> str)
	{
		if(id == idd && str == pass)
		{
			cout<<"done"<<endl;
		}
	}
	}
	
}


class Librarian{
	public:
	void login();
/*	void add_book() ;  //adding a book in a library database
	void delete_book() ;  //delete a book from a library
	void fine_student() ; //fining a student
	void update_book_in_lib() ;  //quantity update
*/};
	
void Librarian::login()
{	char ab;
	
	cout<<"1 for student id creation, 2 for librarian signup , 3 for librarian signin: ";
	cin>>ab;
	
	if (ab == '1')
	{
	string a ;
	string b ;
	cout << "enter Roll number: " ;
	cin >> a ;
	cout << "enter your passwords : " ;
	cin>> b ;
	
	ofstream fout;
	fout.open("studentpassword.txt" ,ios::app) ;
	fout<<endl;
	fout<< a <<" "<<b <<endl;
		
	}
	
	if (ab == '2')
	{
	string ab;
	string bc;
	cout << "welcome to librarian signup" <<endl;
	cout << "Enter your ID : " ;
	cin >> ab ;
	cout << "Enter your password : " ;
	cin>>bc ;
	
	ofstream fout1;
	fout1.open("librarian_passwords.txt" , ios::app) ;
	fout1<<ab<<" "<<bc <<endl;
	}
	
	if (ab=='3')
	{
	ifstream fout;
	fout.open("librarian_passwords.txt");
	string str , pass;
	string id,idd;
	cout<<"id,password : ";
	cin>>idd>>pass;
	
	if(fout.is_open())
	{
	while(fout >> id >> str)
	{
		if(id == idd && str == pass)
		{
			cout<<"done\n";
		}
	}
}
}
}

int main()
{
	string a;
	cout<< "ARE YOU A STUDENT OR A LIBRARIAN? " ;
	cin>>a;
	if (a=="student")
	{
	Student s1;
	s1.login();
	}
	else{
		Librarian L1;
		L1.login();
	}
}

