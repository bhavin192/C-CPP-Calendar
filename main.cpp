/*
<CALENDAR-Tool To Perform Calendar Related Functions.>
    Copyright (C) <2011-12>  <SHIVAM MATHUR--shivam_jpr@hotmail.com>

    This program is free software: you can redistribute it and/or modify
    the software until it is not mentioned in the source,
    under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


*The terms and conditions given below or in the licence.txt(https://sourceforge.net/projects/c-cpp-calender/files/licence.txt) follow to every part of the program until and unless explictly mentioned
 these terms and conditons might change without your prior information and in any case the licence terms as
 mentioned in the latest version of -(https://sourceforge.net/projects/c-cpp-calender/files/licence.txt)
 would be valid and applicable.
*The redistributors are expected to use the screenshots provided with the APP than rather than creating their own.
*The icon of Calendar must not be changed and in any case the icon provided with the APP must be used.

****___NOTE_____**** :- to compile add "-lshlwapi" when calling the linker.

The following program perform the functions for which a calendar is used
MADE BY SHIVAM MATHUR
:)
*/
#include "func.cpp"			//Contains all the User-Defined functions accessed in the program


int main() 					//Main function
{
/***********************************************************Password roadblock***************************************************************/    

/*setting console screen*/	
	const string tile="CALENDAR "+ver+" - By SHIVAM";	
	SetConsoleTitle(tile.c_str());	//DOS-function to give title to a console windowe- *takes char as parameters 								
/*......*/

	ri=79;		bt=29;				//initial dimensions of screen
	cal.setscr();					//Resetting the screen size
/*creating local calendar directory*/	
	TCHAR pthc[MAX_PATH];			//variable to store file name
	SHGetFolderPath(NULL,CSIDL_LOCAL_APPDATA|CSIDL_FLAG_CREATE,NULL, 0,pthc); /*function to find local application directory*/				
	PathAppend(pthc, TEXT("Calendar"));	//function to edit stored path
	CreateDirectory(pthc,NULL);
/*......*/	
	do{														
		ket=0;met=0;	
		cal.roadblock();		
/*making panic screen when login failure*/		
		if (a==1)						//confirms if password or username do not match
    		{

				cal.setclr(12);					//Function to change the colour of output handle in the console		
				cal.logcal('l');				//logging login-failure
				cal.gotoxy(0,6);		cout<<"________________________________________________________________________________";
				cal.gotoxy(0,20);		cout<<"________________________________________________________________________________"; 
				for(int yt=0;yt<16;yt++)
				{
					cal.gotoxy(39,6+yt);	cout<<"\xB3"; //xB3 is ascii hex for vertical bar character
				}				
				cal.setclr(15);
				cal.gotoxy(15,6);		cout<<"Sign-up";
				cal.gotoxy(56,6);		cout<<"Sign-in";
				cal.setclr(15);	
				cal.clrline();		
				cal.gotoxy(5,22);		cout<<"The PASSWORD or USERNAME is not correct\n\n\n";
   				cal.gotoxy(5,23);		cout<<"\t1. Press 'y/Y' to Enter Again\n";
   				cal.gotoxy(5,24);		cout<<"\t2. Press any other key to EXIT\n";
				cal.setclr(2);	
				cal.gotoxy(5,25);		cout<<"Enter : ";
				cal.setclr(15);	
				cal.gotoxy(15,25);		cin>>pchoice;
				if(pchoice!='y' && pchoice!='Y')
					{
						cal.docls();
						cal.setclr(14);
						cal.gotoxy(50,25); cout<<"Calendar "<<ver<<" By Shivam";
						cal.gotoxy(29,10); cout<<"You chose to EXIT";					
						cal.gotoxy(33,11); cout<<"Good BYE";
						cal.gotoxy(29,12); cout<<"Press any key to EXIT";
      					cal.GetCh();
      					exit(0); 							 //Exiting the program as per users choice
					}
				else 	ket=2;
			}
/*......*/
		if(a!=1)	//login successful
			{
				met=2;
				cal.logcal('s');	//logging login successful
			}		
		
	}	while(ket==2 && met!=2);
/***************************************************************************************************************************************/
do
{

  	cal.docls();		//Cleares the screen
	ri=79;	bt=29;		//sizes for console screen
	cal.setscr();		//resizing the console screen

/********************************************************CREDITS************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////			This code (from 2 above lines to 20 lines under this line) must be there with every distribution					   //
///				Removing this part to the code is not allowed in any case,the doing so would directly mean without 			  	      ///
//				any argument the violation of the free license provided and a case of copyright infringement.						 ////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*setting up options menu*/
	cal.setclr(7);	
	cal.gotoxy( 0,15); 	cout<<"CREDITS\n";
	cal.setclr(8);	
	cal.gotoxy( 5,17); 	cout<<"           88           88                                             \n";
	cal.gotoxy( 5,18); 	cout<<"           88           88                                             \n";
	cal.gotoxy( 5,19);	cout<<"           88                                                          \n";
	cal.gotoxy( 5,20); 	cout<<",adPPYba,  88,dPPYba,   88  8b       d8  ,adPPYYba,  8 ,dPYba,,adPYba, \n";
	cal.gotoxy( 5,21); 	cout<<"SSS    sa  88P'     8a  88  `8b     d8'  aa     `Y8  88P'    88     8as\n";
	cal.gotoxy( 5,22); 	cout<<"   S8ba    88       88  88   `8b   d8'   ,adPPPPP88  88      88      88\n";
	cal.gotoxy( 5,23); 	cout<<"aa    DSD  88       88  88    `8b,d8'    88,    ,88  88      88      88\n";
	cal.gotoxy( 5,24); 	cout<<"SaYbbdPa'  88       88  88      s8s      `s8bbdPsY8  88      88      88\n";
	cal.gotoxy( 0, 0);
/***************************************************************************************************************************************/
	

	cal.setclr(12);	
	cal.gotoxy( 0,13);		cout<<"________________________________________________________________________________";
	cal.gotoxy( 0, 0);		cout<<"________________________________________________________________________________";	//welcome
	cal.gotoxy( 0,26);		cout<<"________________________________________________________________________________";
	cal.setclr(15);	
	cal.gotoxy(73-strlen(usrn)-4,13);		cout<<"Welcome "<<usrn;
	cal.gotoxy(28, 0);		cout<<"Welcome to the Calendar";	
	cal.gotoxy(70, 0);		cout<<"VER "<< ver;
	cout<<"\n\n";
	cal.setclr(7);	
	cout<<"OPTIONS";
	cal.gotoxy( 0, 4);
	cal.setclr(15);			
	cout<<"\t1. Know day of any date\n";					//Options of the program
	cout<<"\n\t2. Get calendar of any month\n";
	cout<<"\n\t3. Get calendar of any year\n";
	cout<<"\n\t4. Know dates in a month on which a day occurs\n";
	cout<<"\n\t5. To-Do\n\n\t";
    cal.setclr(10);	
    cal.gotoxy(65,28); cout<<"ESC : EXIT";				//Provodomg button for exit	
    cal.gotoxy(5,28); cout<<"F10 : ABOUT";				//Provodomg button for about		
	
	cal.calmenu();

/*......*/	
	
/***************************************************************************************************************************************/

	if (kvt==1)			//Prints the day
		{
			cal.logcal('d');
     		do{	
				cal.docls();
         	fla=0;
   			if(again==1)
         	{
				cal.setclr(10);	
				cal.gotoxy(29, 4);		cout<<"!!! ENTER AGAIN !!!";
            }
            again=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"______________________";
			cal.gotoxy(28,20);   	cout<<"______________________\n";
			cal.setclr(15);	
			cal.gotoxy(34, 7);   	cout<<"DAY-FINDER";
			cal.gotoxy(28, 9);		cout<<"Enter the date(DD)\n";
			cal.gotoxy(28,10);		cal.infl('d'); if (again==1) continue;
			cal.gotoxy(28,12);		cout<<"Enter the month\n";
			cal.gotoxy(28,13);		cal.infl('m'); 
			cal.gotoxy(28,15);		cout<<"Enter the year(YYYY)\n";
			cal.gotoxy(28,16);		cal.infl('y'); if (again==1) continue;
			cal.chkdate();
			}while(again==1);
			x=cal.dayno();
			if(flag==0)
				{
					cal.gotoxy(28,18);		cout<<"The day was : ";
				}
			else if(flag==1)
				{
					cal.gotoxy(28,18);		cout<<"The day will be : ";
				}
			else if(flag==2)
				{
					cal.gotoxy(28,18);		cout<<"Today is a : ";
				}
			cal.setclr(12);	
			cout<<week[x]<<"\n";
		}
/***************************************************************************************************************************************/
	if (kvt==2)				//prints the calendar of the month
		{
			cal.logcal('m');
			do{
			cal.docls();
   			if(again==1)
         	{
				cal.setclr(10);	
         		cal.gotoxy(28, 4);	cout<<"!!! ENTER AGAIN !!!";
            }
            again=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"____________________";
			cal.gotoxy(28,15);   	cout<<"____________________\n";
			cal.setclr(15);	
			cal.gotoxy(31, 7);   	cout<<"MONTH-CALENDAR";
			cal.gotoxy(28, 9); 		cout<<"Enter the month\n";
			cal.gotoxy(28,10); 		cal.infl('m'); 
			cal.gotoxy(28,12);		cout<<"Enter the year{YYYY}\n";
			cal.gotoxy(28,13);		cal.infl('y'); if (again==1) continue;
			date=1;
         	counter = mon;
		 	cal.chkdate();
			}while(again==1);
			cal.docls();
			cal.monthcal();
		}
/***************************************************************************************************************************************/
	if (kvt==3)			//prints the calendar of the year
		{
			cal.logcal('y');	
 			do{
			cal.docls();
   			if(again == 1)
  				{
					cal.setclr(10);	
         			cal.gotoxy(33, 4);	cout<<"!!! ENTER AGAIN !!!";
				}
			again=0;
			cal.setclr(2);	
			cal.gotoxy(26, 7);   	cout<<"______________________________";
			cal.gotoxy(26,18);   	cout<<"______________________________\n";
			cal.setclr(15);	
			cal.gotoxy(35, 7);   	cout<<"YEARLY-CALENDAR";
			cal.gotoxy(26, 9);		cout<<"Enter the year(YYYY)\n";
			cal.gotoxy(26,10);		cal.infl('y'); if (again==1) continue;
			cal.gotoxy(26,12);		cout<<"Want to generate a text file";
			cal.gotoxy(26,13);	    scanf("%s",fl);
			if (!strncmp(fl,"y",1) || !strncmp(fl,"Y",1))
			{
				
				cal.gotoxy(26,15);  cout<< "Enter your desired filename";
  				cal.gotoxy(26,16);  scanf("%s",name);				
			if((ket = strlen(name)) > 3 && strcmp(name + ket - 4, ".txt")) strcat(name,".txt")	;
			else if ((ket = strlen(name)) < 3) strcat(name,".txt")	;
		  	cal.logcal('f');
			}					  
		
			date=1;			mon=1;
			cal.chkdate();
			}while(again==1);
      		cal.docls();
							
				for (counter = 1; counter <= 12; counter++)
 				{
					cal.printAll();
				if (!strncmp(fl,"y",1) || !strncmp(fl,"Y",1))					
					cal.printcaltofile();
 				}		
			
		}
/***************************************************************************************************************************************/
	if (kvt==4)			//prints the dates on which a day lies in a month
		{
			cal.logcal('t');
			do{
			cal.docls();
   			if(again == 1)
         		{
					cal.setclr(10);	
         			cal.gotoxy(29, 4);	cout<<"!!! ENTER AGAIN !!!";
				}
			again=0;
			strno='\0';
			fla=0;
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"________________________";
			cal.gotoxy(28,18);   	cout<<"________________________\n";
			cal.setclr(15);	
			cal.gotoxy(35, 7);   	cout<<"DATE-FINDER";
			cal.gotoxy(28, 9);		cout<<"Enter the day\n";
			cal.gotoxy(28,10);		cal.infl('f'); if (again==1) continue;
			cal.gotoxy(28,12); 		cout<<"Enter the month\n";
			cal.gotoxy(28,13);		cal.infl('m');
			cal.gotoxy(28,15);		cout<<"Enter the year\n";
			cal.gotoxy(28,16);		cal.infl('y'); if (again==1) continue;
			cout<<"\n";			cout<<"\n";
			date=1;
			cal.chkdate();
			}while(again==1);
			cal.docls();
			if(daynum==7)		daynum=0;
			cal.day2date ();
		}
/***************************************************************************************************************************************/
	if (kvt==5)				//todo section
		{
			cal.docls();
			cal.setclr(2);	
			cal.gotoxy(28, 7);   	cout<<"________________________";
			cal.gotoxy(28,18);   	cout<<"________________________\n";
			cal.setclr(15);	
			cal.gotoxy(35, 7);   	cout<<"TO-DO";
		}
/***************************************************************************************************************************************/
	if (kvt==6)
		{
			cal.showinfo();
		}
/***************************************************************************************************************************************/

		cal.repeat(kvt);

}while(ch1=='y');	
    
return 0;						//end of main statement

}
//end of code
//made by shivam mathur
