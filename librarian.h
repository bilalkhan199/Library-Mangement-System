int librarianloginflag=0;
void mainlibrarian();

class Librarian:public Library{
	public:
	int login();					// (done)
	void blankspace();
	void issuebook();   			// (done)
	void add_book();				// adding a book in a library database  (done)
	void book_delete_function();	// delete a book from a library  
	void update_book_in_lib();		// quantity update  
	void issued_book_data();
	void viewbooks();
	void header();
	
};

void Librarian::header(){
		HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	SetConsoleTextAttribute(hConsole, 48);       //Yellow Color Code=480
    gotoxy(18,0);
	cout<<"  LIBRARY MANAGMENT LIBRARIAN PORTAL "<<endl; 
    SetConsoleTextAttribute(hConsole, 14);
    
	
}
int Librarian::login()
{	
	Librarian::header();
	char ab;
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
    gotoxy(20,6);
	cout<<"1 for student id Creation, 2 for Librarian Sign-up , 3 for librarian Sign-in: ";
	cin>>ab;
/*	
	if (ab == '1')
	{
	string a;
	string b;
	gotoxy(20,7);
	cout << "Enter Roll number: " ;
	cin >> a;
	gotoxy(20,8);
	cout << "Enter your password: " ;
	cin>> b;
	
	ofstream fout;
	fout.open("studentpassword.txt" ,ios::app) ;
	fout<<endl;
	fout<< a <<" "<<b <<endl;
		
	}
	
	if (ab == '2')
	{
	string ab;
	string bc;
	cout << ".........Create your librarian Account..............\n" <<endl;
	cout << "Enter your ID : " ;
	cin >> ab ;
	cout << "Enter your password : " ;
	cin>>bc ;
	
	cout<<"\nCreated account Successfully\n"<<endl;
	ofstream fout1;
	fout1.open("librarian_passwords.txt" , ios::app) ;
	fout1<<ab<<" "<<bc <<endl;
	}
*/
	if (ab=='3')
	{
	ifstream fout("librarian_passwords.txt");
	string str , pass;
	string id,idd;
	SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
    gotoxy(35,7);
	cout<<"id: ";
	cin>>idd;
	SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
    gotoxy(35,8);
	cout<<"password:";
	cin>>pass;
	
	if(fout.is_open())
	{
	while(fout >> id >> str)
	{
		if(id == idd && str == pass)
		{
			SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
            gotoxy(35,9);
			cout<<"Logged in Successfully\n"<<endl;
			librarianloginflag=1;
			return 0;	
		}
        else{
			continue;
		     }
			
	}
	if(librarianloginflag==0)
	{
			SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
            gotoxy(35,9);
			cout<<"USERNAME OR PASSWORD INCORRECT"<<endl;
			Sleep(1500);
			system("cls");
			Librarian::login();
	}
}
}
}

void Librarian::blankspace()
{
	string s=" ";
	string input;
	ofstream temp("temp.txt");
	ifstream database("database.txt");
	
	while(database)
	{
		getline(database,input);
		if (input.find(s)!=-1)
		{
			//cout<<"temp"<<input<<endl;
			temp<<input<<endl;
		}
		else{
			//cout<<"matched"<<endl<<endl;
			continue;
		}
	}
	temp.close();
	database.close();
	
	remove ("database.txt");
	rename("temp.txt","database.txt");
}


void Librarian::issuebook()
{
    int update_flag=0;
	string input,input1,input_date,count,count1,count2,rollno;
	int update_size;
	
	system("cls");
	Librarian::header();
	gotoxy(20,6);
	cout<<"Enter the roll no: ";
	istream& ignore (streamsize n = 1, int delim = EOF);
	cin.ignore();
	getline(cin,rollno);
	gotoxy(20,7);
	cout<<"Enter the name of book you want to issue:";
	//cin.ignore();
	getline(cin,input);
	gotoxy(20,8);
	cout<<"What's the return data,(DD/MM/YY): ";
	//cin.ignore();
	getline(cin,input_date);

	ofstream temp("books_issued.txt",ios::app);
	ifstream database("database.txt");
	 int x =0;
	//cout<<"rollno"<<rollno<<input_date<<input<<endl<<endl;
	while(database)
	{
		getline(database,input1);
		//cout<<"input"<<input<<endl;
		
		if (input1.find(input)!=-1)
		{
			gotoxy(20,9);
			cout<<"book available in database"<<endl;
			gotoxy(20,10);
			cout<<"Book issued successfully";
			temp<<"Rollno: "<<rollno<<" "<<"Book: "<<input<<" Deadline: "<<" "<<input_date<<endl;

			update_size=input1.size();
			
			    count=input1[update_size-2];
  			    count1=input1[update_size-1];
    			    count2=count+count1;

			stringstream geek(count2); 
   			 
  			  geek >> x;
  			  x=x-1;
              update_flag=1;
       }
		
		
	}
	temp.close();
	database.close();

    if(update_flag==1)
    {
	ifstream bk("database.txt");
	ofstream hk("temp0.txt");
	string qq;
	while (getline(bk,qq))
	{
		if(qq.find(input)!=-1)
		{	
			hk<<"Bookname: "<<input<<" "<<"Quantity: "<<x<<endl;
			continue;
		}
		else{
			
			hk<<qq<<endl;
		}
		
	}
	bk.close();
	hk.close();
	remove("database.txt");
	rename("temp0.txt","database.txt");

	Librarian::blankspace();
	Sleep(1000);
	mainlibrarian();
    }
    
    if (update_flag==0)
    {
    	gotoxy(20,6);
        cout<<"Sorry book not found in database"<<endl;
        Sleep(1000);
        Librarian::issuebook();
    }
}

void Librarian::add_book()
{
	system("cls");
	Librarian::header();
	string add_book;
	int quan_add_books;
	ofstream fout("database.txt",ios::app);
	istream& ignore (streamsize n = 1, int delim = EOF);
	cin.ignore();
	gotoxy(20,6);
	cout<<"KINDLY ENTER A BOOK NAME YOU WANT TO ENTER IN DATA BASE: ";
	getline(cin,add_book);
	gotoxy(20,7);
	cout<<"WHAT IS QUANTITY FOR THE BOOKS? ";
	cin >>quan_add_books;
	
//	cout<<"add"<<add_book<<" "<<quan_add_books<<endl;
	fout<<"Bookname: "<<add_book<<" "<<"Quantity: "<<quan_add_books<<endl;
	gotoxy(20,8);
	cout<<"books successfully added in database"<<endl;
	Sleep(1000);
	fout.close();
	Librarian::blankspace();
	mainlibrarian();
}

void Librarian::book_delete_function()
{
    string line12,ak12;
    string delete_line1;
    system ("cls");
    Librarian::header();
    ifstream fin12("database.txt");
    ofstream temp12("temp.txt");
    gotoxy(20,6);
    cout << "which book do you want to remove? ";
    cin.ignore();    // idhar galti thi !
    getline(cin,delete_line1);
    istream& ignore (streamsize n = 1, int delim = EOF);
    
    while (fin12)
    {
        getline(fin12,ak12);
	//cout<<"ak12: "<<ak12<<endl;
   
        if(ak12.find(delete_line1)!=-1)
        {
        gotoxy(20,7);
		cout<<"Book matched and Deleted"<<endl;
		//cout<<ak12<<" abc "<<delete_line1<<endl;
        	continue;
    }
        else{
        	temp12<<ak12<<endl;
		}
    }
    Sleep(1000);
    temp12.close();
    fin12.close();
    remove("database.txt");
    rename("temp.txt","database.txt");
    Librarian::blankspace();
    mainlibrarian();
}

void Librarian::update_book_in_lib()
{
	system("cls");
	Librarian::header();
	string book_update,book_update_input;
	int x=0;
	int update_book_flag=0;
	string a[2];
	gotoxy(20,6);
	cout<<"Type the name of the book of which you want to edit:";
	cin.ignore();
	getline(cin,book_update);
	istream& ignore (streamsize n = 1, int delim = EOF);
	gotoxy(20,7);
	cout<<"what's updated Quantity of books:";
	cin>>x;
	ifstream fin12("database.txt");
	ofstream fiq12("temp.txt");
	
    while (fin12)
    {
        getline(fin12,book_update_input);
        if(book_update_input.find(book_update) != -1)
        {
        	update_book_flag=1;
			continue;
        }
        else{
        	fiq12<<book_update_input<<endl;
	    }
    }
 
 	if (update_book_flag==1)
 	{
   // cout << "Value of x :" << x; 
    fiq12<<"Bookname: "<<book_update<<" "<<"Quantity: "<<x<<endl;

    fiq12.close();
    fin12.close();
    remove("database.txt");
    rename("temp.txt","database.txt");
    
    Librarian::blankspace();
    gotoxy(20,8);
    cout<<"Updated book's quantity"<<endl;
    Sleep(1000);
    mainlibrarian();
	}
	if(update_book_flag==0)
	{
	//	cout<<"updatebookflag==0"<<endl;
	    gotoxy(20,7);
		cout <<"Book is not available in database "<<endl;
		Sleep(1000);
		Librarian::update_book_in_lib();	
	}
}

void Librarian::issued_book_data()
{
	system("cls");
	Librarian::header();
	string rollno;
	gotoxy(20,6);
	cout<<"Enter the Roll no to show you that roll no issued book: ";
	cin>>rollno;
	//cout<<"\n"<<endl;
	string q;
	int notfind=0;
	ifstream book_issued("books_issued.txt");
	
	while (getline(book_issued,q))
	{
		
		size_t found= q.find(rollno); 
		gotoxy(20,7);
        if (found != string::npos) 
        {	
             cout<<q<<endl;
             notfind=1;
    	}
    	else
    	{
    		continue;
		}
    
	}
	if(notfind==0)
	{
		gotoxy(20,8);
		cout<<"Not found this Roll-No. in Books-issued\n"<<endl;
		gotoxy(20,8);
		cout<<"try it again"<<endl;
		
		Librarian::issued_book_data();
		return ;
	}
		Sleep(4000);
		mainlibrarian();
}
void Librarian::viewbooks()
{
	int ii=6;
	string book;
	system("cls");
		Librarian::header();
	int count=0;
	ifstream books("database.txt");
	
	while (books)
	{
		gotoxy(20,ii);
		
		getline(books,book);
		count=book.size()-2;
	
		for (int i=0;i<count;i++)
		{
			cout<<book[i];
		}
			
		for(int k=0;k<1;k++)
		{
			cout<<book[book.size()-2]<<book[book.size()-1];
			ii++;	
		}
	}
	Sleep(2500);
    books.close();
    mainlibrarian();
}
void mainlibrarian()
{
		HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	SetConsoleTextAttribute(hConsole, 48);       //Yellow Color Code=480
    gotoxy(18,0);
	cout<<"  LIBRARY MANAGMENT LIBRARIAN PORTAL "<<endl; 
    SetConsoleTextAttribute(hConsole, 14);

	Librarian L1;
	if(librarianloginflag==0)
		L1.login();
		
	int ask_user;
	system("cls");
	//SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
    gotoxy(20,6);
    cout<<"1-For addition a book"<<endl;
	gotoxy(20,7);
	cout<<"2-Deleting a book"<<endl;
	gotoxy(20,8);
	cout<<"3-Update book in library"<<endl;
	gotoxy(20,9);
	cout<<"4 for issue book"<<endl;
	gotoxy(20,10);
	cout<<"5-Checking issue book data"<<endl;
	gotoxy(20,11);
	cout<<"6-View all books in database"<<endl;
	gotoxy(20,12);
	
	cin>>ask_user;
	if (ask_user== 1)
	{
		L1.add_book();
	}
	
	if (ask_user ==2)
	{
		L1.book_delete_function();
		L1.blankspace();
	}
	if (ask_user==3)
	{
		L1.update_book_in_lib();
	//	cout<<"blankspace"<<endl<<endl;
		L1.blankspace();
	
	}
	if (ask_user==4)
	{
		L1.issuebook();
	}
	if (ask_user==5)
	{
		L1.issued_book_data();
	}
	if(ask_user==6)
	{
		L1.viewbooks();
	}	
}


