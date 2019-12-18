#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <cstdlib>              // Header Files 
#include <graphics.h> 
#include <stdio.h>
#include<conio.h>               // for getch() function               
#include<windows.h>
#include<dos.h>

using namespace std;
void callfunction();

                 ///////////////////////////////////////      MOUSE HANDLING         /////////////////////////////

void gotoxy (int x, int y)
{
         COORD coordinates;     // coordinates is declared as COORD
         coordinates.X = x;     // defining x-axis
         coordinates.Y = y;     //defining  y-axis
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
}

void mouseinput()
{
		HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
        bool EXITGAME = false;
        int buttonX=0, buttonY=1;


        
    while( !EXITGAME )
    {
        ReadConsoleInput(hin, &InputRecord, 1, &Events);
        switch ( InputRecord.EventType ){
                case KEY_EVENT: // keyboard input 
               
                case MOUSE_EVENT: // mouse input 

                    if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                    {
                        coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                        coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                        SetConsoleCursorPosition(hout,coord);
                        SetConsoleTextAttribute(hout,rand() %7+9);
						
                        if ( (InputRecord.Event.MouseEvent.dwMousePosition.X == buttonX ) && 
                            ( InputRecord.Event.MouseEvent.dwMousePosition.Y == buttonY) ){

                           
                 
                           
                        }

                      //  cout<<"Hello Iam here! "<< InputRecord.Event.MouseEvent.dwMousePosition.X <<" x "<< InputRecord.Event.MouseEvent.dwMousePosition.Y<<" ";
					if(InputRecord.Event.MouseEvent.dwMousePosition.Y == 20 and  InputRecord.Event.MouseEvent.dwMousePosition.X==34 || InputRecord.Event.MouseEvent.dwMousePosition.Y == 19 and  InputRecord.Event.MouseEvent.dwMousePosition.X==5  || InputRecord.Event.MouseEvent.dwMousePosition.Y == 20 and  InputRecord.Event.MouseEvent.dwMousePosition.X==5)
					{
					//cout<<"MY HELP ==="<<           InputRecord.Event.MouseEvent.dwMousePosition.Y<<endl;
					system("cls");
					callfunction(); 
					}
                    }// mouse 

                    break; 
		}
}
}	
            ///////////////////////////////////////      WELCOME SCREEN         /////////////////////////////
void welcomescreen(){
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            system("cls");
            SetConsoleTextAttribute(hConsole, 480);        //Yellow Color Code=480
            gotoxy(7,0);
            cout<<"   NATIONAL  UNIVERSITY  OF  COMPUTER  AND  EMERGING  SCIENCES   "<<endl; 
            SetConsoleTextAttribute(hConsole, 47);     //Green & White Color Code=47
            gotoxy(19,1);
            cout<<"      Library Managment System       "; 
            SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            for (int i=6; i<14; i++) {
                gotoxy(38,i);
                cout<<'\xB3';
            }
            gotoxy(28,3);
            SetConsoleTextAttribute(hConsole, 27);             //Blue Color Code=27
            cout<<"  Object Oriented Programming Semester Project  ";
           
            
            SetConsoleTextAttribute(hConsole, 3);           //Dark Blue-Green Color Code=3
            gotoxy(4,6);
            cout<<"Made By Haris, Salman, Bilal";
            //SetConsoleTextAttribute(hConsole, 6);            //Dark Yellow Color Code=6
            //gotoxy(27,8);
            //SetConsoleTextAttribute(hConsole, 15);            //White Color Code=15
            //gotoxy(47,8);
            //SetConsoleTextAttribute(hConsole, 3);              //Dark Blue Color Code=3
            //gotoxy(8,10);
            //SetConsoleTextAttribute(hConsole, 6);            //Dark Yellow Color Code=6
            //gotoxy(27,10);
            
            SetConsoleTextAttribute(hConsole, 8);            //Dark Yellow Color Code=8
            for (int i=0; i<38; i++) {
                gotoxy(i,14);
                cout<<'\xC4';
            }
            SetConsoleTextAttribute(hConsole, 8);            //Dark Yellow Color Code=8
            for (int i=0; i<38; i++) {
                gotoxy(i,5);
                cout<<'\xC4';
            }
            gotoxy(38,14);
            cout<<'\xC1';
            gotoxy(38,5);
            cout<<'\xC2';
            
            SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            gotoxy(3,18);
            cout<<'\xDA'<<'\xC4';
            for (int i=0; i<29; i++)
                cout<<'\xC4';
            cout<<'\xBF';
            gotoxy(3,19);
            cout<<'\xB3';
            gotoxy(3,20);
            cout<<'\xC0'<<'\xC4';
            for (int i=0; i<29; i++)
                cout<<'\xC4';
            cout<<'\xD9';
            SetConsoleTextAttribute(hConsole, 15);             //White Color Code=12
	  gotoxy(5,19);
            cout<<"Note: ";
            SetConsoleTextAttribute(hConsole, 10);             //Green Color Code=10
            cout<<"Click here to Start    ";
            SetConsoleTextAttribute(hConsole, 8);             //Gray Color Code=8
            cout<<'\xB3';
            SetConsoleTextAttribute(hConsole, 15);             //White Color Code=15
            gotoxy(2,19);
                   
            gotoxy(5,22);
            
            SetConsoleTextAttribute(hConsole, 7);             //Light White Color Code=7
            
}


class Library{
	public:
	int login();
};
#include "student.h"
#include "librarian.h"




int main()
{
	
	welcomescreen();
	mouseinput();

	Sleep(4500);
	system ("cls");
	 
}  



void callfunction()
{
	
		 HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		
	    	SetConsoleTextAttribute(hConsole, 9);             //Pink Color Code=13
			gotoxy(35,4);
            cout<<"< WELCOME TO LIBRARY MANAGMENT SYSTEM >";
           // SetConsoleTextAttribute(hConsole, 15);             //White Color Code=15
            //gotoxy(35,5);
           // cout<<"1 for Librarian ";
            SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
            gotoxy(35,5);
            cout<<"1 for Student";
            SetConsoleTextAttribute(hConsole, 14);             //White Color Code=15
            gotoxy(35,6);
            SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
            gotoxy(35,6);
            cout<<"2 For Librarian";
			cout<<endl<<endl<<endl;
			gotoxy(35,8);
			cout<<"Input-";
			string a;
			cin>>a;
			system("cls");
			if (a=="1")
			{
				mainstudent();
				SetConsoleTextAttribute(hConsole, 14);             //blue-Green Color Code=3
            	gotoxy(35,6);
			}
			if (a=="2"){
				mainlibrarian();
}
}





