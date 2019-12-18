string student_roll_no;
int student_roll_no_flag=0;
int tempflag=0;
void mainstudent();

class Student:public Library{
	public:
    int login();
	void re_issue_book();         // DONE
	void returnbook();
	void viewbooks();     // view all books in database
	void blankspace();
	void blankspace1();
	void header();
};
void Student::header()
{
	HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   	SetConsoleTextAttribute(hConsole, 48);       //Yellow Color Code=480
    gotoxy(18,0);
	cout<<"  LIBRARY MANAGMENT STUDENT PORTAL "<<endl; 
    SetConsoleTextAttribute(hConsole, 14);	
}

int Student::login()
{
	system("cls");
	Student::header();
	ifstream fout;
	fout.open("studentpassword.txt");
	string str , pass;
	string id,idd;
	gotoxy(20,6);
	cout<<"Enter YOUR ROLL NO:";
	cin>> idd;
	gotoxy(20,7);
	cout<<"Enter YOUR PASSWORD: ";
	cin>>pass;
	
	
	if(fout.is_open())
	{
	while(fout >> id >> str)
	{
		if(id == idd && str == pass)
		{
			gotoxy(20,8);
			cout<<"Successfully Login!"<<endl;
			Sleep(1000);
			student_roll_no=idd;
			tempflag=1;
			return 0;
		}
		else{
			continue;
		}
	}
		
		if(tempflag==0){
			gotoxy(20,6);
			cout<<"Username or Password incorrect"<<endl;
			gotoxy(20,7);
			cout<<"Kindly login again"<<endl;
			Sleep(1000);
			system("cls");
			Student::login();
		    }
	}
	Sleep (1500);
}
void Student::blankspace()
{
	string s=" ";
	string input;
	ofstream temp("temp.txt");
	ifstream database("books_issued.txt");
	
	while(database)
	{
		getline(database,input);
		//cout<<"input"<<input<<endl;
		
		if (input.find(s)!=-1)
		{
		//	cout<<"temp"<<input<<endl;
			temp<<input<<endl;
		}
		else{
		//	cout<<"matched";
			continue;
		}
	}
	temp.close();
	database.close();
	
	remove ("books_issued.txt");
	rename("temp.txt","books_issued.txt");
}

void Student::blankspace1()
{
	string s=" ";
	string input;
	ofstream temp("temper.txt");
	ifstream database("database.txt");
	
	while(database)
	{
		getline(database,input);
		//cout<<"input"<<input<<endl;
		
		if (input.find(s)!=-1)
		{
			//cout<<"temp"<<input<<endl;
			temp<<input<<endl;
		}
		else{
			//cout<<"matched";
			continue;
		}
	}
	temp.close();
	database.close();
	
	remove ("database.txt");
	rename("temper.txt","database.txt");
}


void Student::viewbooks()
{
	system("cls");
	Student::header();
	int qq=6;
	string book;
	int count=0;
	ifstream books("database.txt");
	while (books)
	{
		gotoxy(20,qq);
		getline(books,book);
		count=book.size()-2;
		
		for (int i=0;i<count;i++)
		{
			cout<<book[i];
		}
		
		for(int k=0;k<1;k++)
		{
			cout<<book[book.size()-2]<<book[book.size()-1];
			qq++;
		}
	//	cout<<endl;
	}
    books.close();
    Sleep(5000);
     mainstudent();
}

void Student::re_issue_book()
{
	system("cls");
	Student::header();
	string rollno=student_roll_no;   //replace it by login function string data.

	string input,newinput;
	int flag1c=0;
	gotoxy(20,5);
	cout<<"Enter the name of book you had issued : ";
	cin.ignore();
	getline(cin,input);
	ifstream data("books_issued.txt");
	ofstream output_reissue_book("temp1.txt");
	string q;
	
	while (getline(data,q))
	{
		if (q.find(rollno)!=-1 && q.find(input)!=-1)
		{
			gotoxy(20,6);
			cout<<"Found this issued book in issued book data"<<endl;
			gotoxy(20,7);
			cout<<"Enter the new deadline: ";
			cin>>newinput;
			flag1c=1;
			continue;
		}
		else{
			//cout<<"q"<<q<<endl;
			output_reissue_book<<q<<endl;
		}
	}
		if (flag1c==1)
		{
			//cout<<"in flag==1"<<endl;
			//cout<<"newinp---"<<newinput<<endl;
			output_reissue_book<<"Rollno: "<<rollno<<" "<<"Book: "<<input<<" "<<"Deadline: "<<newinput<<endl;
			gotoxy(20,9);
			cout<<"Book's deadline has been changed sucessfully";
			flag1c=0;
		}
		
	
	data.close();
	output_reissue_book.close();

	remove("books_issued.txt");
	rename("temp1.txt","books_issued.txt");
	
	Student::blankspace();
	Sleep(1000);
	mainstudent();
}

void Student::returnbook()
{
	system("cls");
	Student::header();
	string input,input1,input_date,count,count1,count2,rollno;
	int update_size;
	int cflag=0;
	string alpha;


	gotoxy(20,6);
	cout<<"Enter the name of book you want to return:";
	cin.ignore();
	getline(cin,input);

	ifstream database("books_issued.txt");
	while(database)
	{
		getline(database,input1);
		
		
		if (input1.find(student_roll_no_flag) && input1.find(input)!=-1)
		{
			//cout<<"input1"<<input1<<endl<<endl;
			gotoxy(20,7);
			cout<<"Found the book in issued book data "<<endl;
			cflag=1;
			database.close();
		}
	}
		if (cflag==1)
		{
			ifstream tempq("database.txt");
			ofstream temq("temperor.txt");
			
			
			while(tempq)
			{
					getline(tempq,alpha);
			
			if(alpha.find(input)!=-1)
			{
				update_size=alpha.size();
			//cout<<"update_size"<<update_size<<endl;	

			    count=alpha[update_size-2];
  			    count1=alpha[update_size-1];
    			count2=count+count1;

				stringstream geek(count2); 
    			int x =0; 
    			geek >> x;
    			x=x+1;
			//	cout << "Value of x :" << x<<endl;
    			cout<<input<<endl;
    			temq<<"Bookname: "<<input<<" Quantity: "<<x<<endl;
			}
				else{
					temq<<alpha<<endl;
			}
		}
		//	cout<<"here"<<endl;	
			tempq.close();
			temq.close();
//	}
			
				remove("database.txt");
				rename("temperor.txt","database.txt");

				//NOW REMOVING THE BOOK FROM BOOKS_ISSUED.TXT

				ifstream file("books_issued.txt");
				ofstream file1("temp2.txt");
				string y;
				while(file)
				{
					getline(file,y);
					if (y.find(input)!=-1)
					{
						continue;
					}
					else{
						file1<<y<<endl;
						}
					}	
				file1.close();
				file.close();	
	
				remove("books_issued.txt");
				rename("temp2.txt","books_issued.txt");
		}
		
		if (cflag==0)
		{
			gotoxy(20,7);
			cout<<"No book found with this roll no"<<endl;
			gotoxy(20,8);
			cout<<"TRY AGAIN";
			Sleep(1500);
			Student::returnbook();
		}
		Student::blankspace();
		Student::blankspace1();
		Sleep(2000);
		mainstudent();

}

void mainstudent()
{
	Student s1;
	if (tempflag!=1)
	{
		s1.login();
	}
	int g=0;
	system("cls");
	
	gotoxy(20,6);
	cout<<"1 for viewbooks";
	gotoxy(20,7);
	cout<<"2 for re-issue book";
	gotoxy(20,8);
	cout<<"3 for returning book";
	cin>>g;	
	if (g==1)
		s1.viewbooks();
	if (g==2)
		s1.re_issue_book();
	if (g==3)
		s1.returnbook();
	
}
