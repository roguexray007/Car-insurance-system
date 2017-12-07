		
		
													/*		COMPUTER SCIENCE MINI PROJECT		*/
				
														/*		CAR INSURANCE SYSTEM		*/
		
													/* This program was run and compiled in Dev C++ */
		
						/*This project is made by :-
										NAME :- AASHISH BHOLE	ROLL NO :- 150002012	BRANCH :- EE	BATCH :- 1
			
										NAME :- KUNAL SIKRI		ROLL NO :- 150001016	BRANCH :- CSE	BATCH :- 1
						*/ 


#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string.h>
#include<cstdio>
#include<time.h>
#include<dos.h>
#include<windows.h>
#include<fstream>
#define DELAY 20
using namespace std;
char password[30];
/******************************************* GOTOXY FUNCTION *************************************************/
void gotoxy(int x,int y)						//Moving cursor to (x,y) coordinates
{
	static HANDLE h=NULL;
	if(!h)
	{
		h=GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c={x,y};
	SetConsoleCursorPosition(h,c);
}
/******************************************* DELAY FUNCTION *************************************************/
void delay(unsigned int mseconds)				//To bring a time gap before printing the next line, character etc.
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
/******************************************* TIME AND DATE FUNCTION*************************************************/
int t(void) 									//For displaying current date and time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));
return 0 ;
}
/******************************************* INTEGER INPUT CHECK ********************************************************************/
int iscan()													//Scan function for input of only non-negative integers
{							
	string ch;												//Taking inital input through string
	int i,v;
	do{
		v=1;
		cin>>ch;
		for(i=0;i<ch.size();i++)							//Checking each character is digit
		{	
			if(!isdigit(ch[i]))
			{
				cout<<"Wrong entry. Try again."<<endl;
				cout<<"Enter the required data : ";
				v=0;
				break;
			}
		}	
	}
	while(!v);
	return atoi(ch.c_str());								//Converting string back to integer
}
/******************************************* FLOAT INPUT CHECK ***********************************************************************/
float fscan()													//Scan function for input of only non-negative floating point numbers
{							
	string ch;													//Taking inital input through string
	int i,v;
	do{
		v=1;
		cin>>ch;
		for(i=0;i<ch.size();i++)								//Checking each character is digit or a decimal point
		{	
			if(!isdigit(ch[i]) && ch[i]!='.')
			{
				cout<<"Wrong entry. Try again."<<endl;
				cout<<"Enter the required data : ";
				v=0;
				break;
			}
		}	
	}
	while(!v);
	return atof(ch.c_str());									//Coverting string back to float
}
/******************************************* STRING INPUT CHECK ****************************************************/
void sscan(char* n)												//Scan function for input of only string literals
{							
	int i,v;
	do{
		v=1;
		cin>>n;
		for(i=0;i<strlen(n);i++)								//Checking each character is digit
		{	
			if(!isalpha(n[i]))
			{
				cout<<"Wrong entry. Try again."<<endl;
				cout<<"Enter the required data : ";
				v=0;
				break;
			}
		}	
	}
	while(!v);
}
/******************************************* CLASS CLIENT *************************************************/

class client																		/*Declaration of client class. 
																					It saves the information of client like his name, gender, 
																					address, age etc*/ 
{
    private :																		//Declaration of private data members
	int age;
	int policy_no;
    char first_name[20],last_name[20];
    char gender;
    char address[80];
    public :																		//Declaration of public member functions and constructors
        client();
        void input();
        void display();
        void set_policy_no(int p)													//To set the policy number of insurance
        {
        	policy_no=p;
		}
		int get_policy_no()															//To get the value of policy number of insurance
		{
			return policy_no;
		}
		char* get_first_name()														//To get the first name of owner
		{ return first_name; }
		char* get_last_name()														//To get the last name of owner
		{ return last_name; }
};

/******************************************* CLASS MOTORVEHICLE *************************************************/
class motorvehicle																	/*Declaration of motorvehicle class.
																					  It saves information about the vehicle like its 
																					  make, model, unique ID number etc*/
{
    private:																		//Declaration of private data members
        char model[20],make[20],license_num[15],fuel_type[20],car_plate_no[15];
        int year,day,month;
        int sy, sd, sm;
        int ey, ed, em;
        int ry, rd, rm;
        int install_no, validity;
        float estimated_value, insure_value, premium;
        char qu1, type;
    public:																			//Declaration of public member functions and constructors
        motorvehicle();
        void input_vehicle();
        void display();
        void set_renew_date();
        char* get_car_plate_no()													//To get the Car Unique ID
        { return car_plate_no; }
		char* get_model()															//To get the Car Model
        { return model; }	
		char* get_make()															//To get the Car Make
        { return make; }
		int get_premium()															//To get the premium of insurance
		{ return premium; }
};
/******************************************* MOTORVEHICLE CONSTRUCTOR *************************************************/
motorvehicle::motorvehicle()												//Definition of constructor
{
    year=0,day=0,month=0;													//Initializing member variables
    sy=0,sd=0,sm=0;
    ey=0,ed=0,em=0;
    ry=0,rd=0,rm=0;
    install_no=0, validity=0;
    estimated_value=0.0; premium=0.0; insure_value=0.0;
    strcpy(model,"");
    strcpy(make,"");
    strcpy(car_plate_no,"");
	strcpy(license_num,"");
    strcpy(fuel_type,"");
    qu1='n';
    type='n';
}
/******************************************* MOTORVEHICLE SET RENEWAL DATE ************************************************************************/
void mainmenu();
int v=0;
void motorvehicle::set_renew_date()											//Function to set the renewal date of policy
{
	char c;
	cout<<"Insurance expires on : "<<ed<<"/"<<em<<"/"<<ey<<endl;			//Displaying the expiry date
	cout<<"Do you want to renew your insurance? (y/n) : ";					//Asking the user whether he would like to renew his insurance policy  
	while(1)																//To check for correct input
	{
		cin>>c;
		if(c=='y' || c=='n' || c=='Y' || c=='N')
		{
			break;
		}
		else
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
	}
	if(c=='y' || c=='Y')
	{v=1;
	cout<<"Enter the renewal date of the insurance (DD MM YYYY) : ";		//Asking the renewal date of insurance
	while(1)																//Ensuring the correct input of date
	{
		rd=iscan();rm=iscan();ry=iscan();
		if(rd>31 || rm>12 || ry<ey)
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
		else
		break;
	}
	}
	else if(c=='n' || c=='N')
	{
		v=0;
	}
}
/******************************************* MOTORVEHICLE INPUT *****************************************************************/

void motorvehicle::input_vehicle()									//Function to get the values of the member variables of motorvehicle class
{
    cout<<"Enter Car Make : ";
    sscan(make);
    cout<<"Enter Car Model : ";
    cin>>model;
    cout<<"Enter License Number : ";
    int v;																	//To check whether license number is integer with the help of flags
	do
	{
		v=1;
		int i;
		cin>>license_num;
		for(i=0;i<strlen(license_num);i++)									//Checking each character for a digit
		{
			if(!isdigit(license_num[i]))
			{
				cout<<"Wrong entry. Try again."<<endl;
				cout<<"Enter the required data : ";
				v=0;
				break;
			}
		}
	}while(!v);
    cout<<"Enter Fuel Type : ";
    sscan(fuel_type);
    cout<<"Enter Date of Purchase (DD MM YYYY) : ";
    while(1)																//Ensuring correct input of date
	{
		day=iscan();month=iscan();year=iscan();
		if(day>31 || month>12 || year>2015)
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
		else
		break;
	}
    cout<<"Enter Estimated Price : ";
    estimated_value=fscan();
	cout<<"Enter Car Unique ID : ";
	cin>>car_plate_no;
	cout<<"Enter the starting date of the insurance (DD MM YYYY) : ";
	while(1)																//Ensuring correct input of date
	{
		sd=iscan();sm=iscan();sy=iscan();
		if(sd>31 || sm>12 || sy>2015)
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
		else
		break;
	}
	cout<<"Enter the number of years for which insurance is valid : ";
	validity=iscan();
	cout<<"Enter the insured amount : ";
	insure_value=fscan();
	cout<<"Enter the number of installments : ";
	install_no=iscan();
	cout<<"Enter the type of insurance fully covered or not (f/n) : ";
	while(1)																			//To check for correct input
	{
		cin>>type;
		if(type=='f' || type=='n' || type=='F' || type=='N')
		{
			break;
		}
		else
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
	}
	cout<<"Was the vehicle involved in an accident during the last year ? (y/n) : ";
	while(1)																			//To check for correct input
	{
		cin>>qu1;
		if(qu1=='y' || qu1=='n' || qu1=='Y' || qu1=='N')
		{
			break;
		}
		else
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
	}
	ed=sd; em=sm; ey=sy+validity;														//Setting values of expiration date
	premium=float(insure_value/install_no);												//Calcuting the premium of insurance
}
/******************************************* CLIENT CONSTRUCTOR *************************************************/
client::client()															//Defintion of constructor
{
    age=0;																	//Initializng member variables
    strcpy(first_name,"");
    strcpy(last_name,"");
    gender=' ';
    strcpy(address,"\0");
}
/******************************************* CLENT INPUT ***********************************************************************/
void client::input()												//Function to get the values of member variables of client class
{
    cout<<"Enter First Name : ";
    sscan(first_name);
    cout<<"Enter Last name 	: ";
    sscan(last_name);
    cout<<"Enter Age 		: ";
    while(1)														//Checking whether age is an integer and less than 100		
	{
		age=iscan();
		if(age>99)
		{
			cout<<"Insurance cannot be given if age is 100 and above. Try again."<<endl;
			cout<<"Enter data 		: ";
		}
		else
		break;
	}
    cout<<"Enter Gender(m/f) : ";
    while(1)														//To check for correct input
	{
		cin>>gender;
		if(gender=='m' || gender=='f' || gender=='M' || gender=='F')
		{
			break;
		}
		else
		{
			cout<<"Wrong entry. Try again."<<endl;
			cout<<"Enter the required data : ";
		}
	}
    cin.ignore();
    cout<<"Enter Address"<<endl;
    gets(address);
}
/******************************************* CLIENT DISPLAY ****************************************************************************/
void client::display()												//Function to display the details of the client i.e. his name, address etc.
{
	cout<<"First name       			: "<<first_name<<endl;
	cout<<"Last name        			: "<<last_name<<endl;
	cout<<"Age              			: "<<age<<endl;
	cout<<"Gender           			: "<<gender<<endl;
	cout<<"Address          			: "<<address<<endl;
}
/******************************************* MOTORVEHICLE DISPLAY *********************************************************************/
void motorvehicle::display()									/*Function to display the details of the motorvehicle which is insured
																  like make, model, insurance start date, expiry date and renewed date*/
{
	cout<<"Car Make            			: "<<make<<endl;
	cout<<"Car Model           			: "<<model<<endl;
	cout<<"License Number      			: "<<license_num<<endl;
	cout<<"Fuel Type        			: "<<fuel_type<<endl;
	cout<<"Date of Purchase			: "<<day<<"/"<<month<<"/"<<year<<endl;
	cout<<"Estimated Price  			: "<<estimated_value<<endl;
	cout<<"Car Unique ID    			: "<<car_plate_no<<endl;
	cout<<"Insurance starting date      		: "<<sd<<"/"<<sm<<"/"<<sy<<endl;
	cout<<"Insurance expiry date 			: "<<ed<<"/"<<em<<"/"<<ey<<endl;
	cout<<"Premiun 				: "<<premium<<endl;
	if(type=='f' || type=='F')													//To check which type of insurance
	{
		cout<<"You have a fully covered insurance policy"<<endl;
	}
	else
	{
		cout<<"You don't have a fully covered insurance policy"<<endl;
	}
	if(rd==0 || ry==0 || rm==0)													//To check if policy is renewed before or not
	{
		cout<<"The policy has not be renewed yet."<<endl;
	}
	else
	{
		cout<<"Your insurance has been renewed on : "<<rd<<"/"<<rm<<"/"<<ry<<endl;
	}
}
/******************************************* PASSWORD FUNCTION *****************************************************************************/
void Password()													//Function which gives administrator access by asking for password and verifying
{
	char ch;
	int i=0, j=0;
	string pass=" Password Protected ";
	system("cls");
	gotoxy(10,4);
	for(j=0;j<20;j++)											//To notify that the database is secured		
	{
		delay(DELAY);
		cout<<"*";
	}
	for(j=0;j<20;j++)
	{
		delay(DELAY);
		cout<<pass[j];
	}
	for(j=0;j<20;j++)
	{
		delay(DELAY);
		cout<<"*";
	}
	gotoxy(10,6);
	cout<<"Enter password : ";									//Asking for password to gain administrator access
	while(ch!=13)												//To convert each character to '*' i.e. encoding
	{
		ch=getch();
		if(ch!=13)
		{
			if(ch!='\b')
			{
				putch('*');
				password[i] = ch;
				i++;
			}
			else
			{
				if(i)
				{
					cout<<"\b \b";
					i--;
				}
			}
		}
   }
   password[i] = '\0';
   if(strcmp("admin123",password)==0)				//Comparing the password entered with the set password. If matched then admin access allowed.
   {

	gotoxy(15,9);
	cout<<"\nPassword match";
	gotoxy(17,10);
	cout<<"\nPress any key to countinue.....";
	getch();
	}
	else
	{
		gotoxy(15,16);
		cout<<"\n\nWarning Incorrect Password"<<endl;
		getch();
		Password();
	}
}
/******************************************* MAIN MENU *******************************************************/
client a;													//Declaration of global variables of classes for further use.
motorvehicle mv;
int flag=0;													//Declaration of flag. It checks if policy is found or not.
void Write();												//Declaration of global functions for further use and implementation of features
void Read();
void Read_name();
void Read_model();
void Read_unique();
void Sort();
void Sort_car_id();
void Sort_car_name();
void Renew();
void mainmenu()							//Function which designs the menu for the user or admin to gain access to the features available.
{
	int n,n1,position=0;				//Declaration of variables


    system ("color 0a");				//Setting the system colour
    do{						//Loop which creates the user-friendly menu and asks the user for his choice and on wrong input runs again for better experience
    	system("cls");
    	cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Autocare Insurance Company \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    	cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 1.Admin";
    	cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 2.User";
    	cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 3.exit\n";
    	cout<<"\nEnter your choice : ";
		cin>>n1;
		switch(n1)
		{
		case 1:                        //***************************************admin part**********************************************
			Password();
			if(strcmp(password,"admin123")==0)			//If the password matches then show the administrator menu
			{
				lab :
				do				//Tells the admin which features are available for use and runs until the admin exits
				{
				system("cls");
				cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Autocare Insurance Company \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 1. Create a new insurance policy";
    			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 2. Sort Records";
    			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 3. Search an insurance policy";
    			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 4. Exit\n"<<endl;
    			t();
    			cout<<"\nEnter your choice :-\t";								//Asking admin for his choice
    			cin>>n;
    			switch(n)
   				{
    				case 1:										//Creates a new insurance policy, gives the policy number and writes to a file
            			system("cls");
            			a.input();
            			mv.input_vehicle();
            			Write();
						cout<<"\n\n********** DETAILS OF CUSTOMER HAVE BEEN SAVED SUCCESSFULLY **********"<<endl;
       					cout<<"\n Your Policy Number is : "<<a.get_policy_no()<<"\n\nUse this policy number for further refernce to your insurance policy "<<endl;
						break;
    				case 2:										//Provides the admin with the advanced features of sorting the data stored in files
    					system("cls");
    					int k;
    					do									//Notifying the advanced features available and runs until the admin wants to return back
    					{
    						system("cls");
							cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Autocare Insurance Company \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
 				   			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 1.Sort by customer name ";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 2.Sort by car name ";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 3.Sort by car unique id ";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 4.Move back to previous menu\n"<<endl;
    						t();
    						cout<<"\nEnter your choice :-\t";				//Asking for choice
    						cin>>k;
							switch(k)
							{
								case 1:										//Sorts the records by the customer's name in lexographic order
									Sort();
									break;
								case 2:										//Sorts the record by the car's model name in lexographic order
									Sort_car_name();
									break;
								case 3:
									Sort_car_id();							//Sorts the records by the car's unique ID number
									break;
								case 4:										//Option to return to previous menu
									goto lab;
									break;
							}
							system("pause");
						}while(1);
        			break;
    				case 3:										//Provides the admin with the advanced features of searching the data stored in files
    					system("cls");
    					int l;
						do									//Notifying the advanced features available and runs until the admin wants to return back
    					{
    						system("cls");
							cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Autocare Insurance Company \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
 				   			cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 1.Search by customer name (Full Name)";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 2.Search by policy number ";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 3.Search by car unique id ";
    						cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 4.Search by car model ";
							cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 5.Move back to previous menu\n"<<endl;
    						t();
    						cout<<"\nEnter your choice :-\t";    //Asking for choice
    						cin>>l;
							switch(l)
							{
								case 1:								//Searches the records by the customer name
									Read_name();
									break;
								case 2:								//Searches the records by the policy number
									Read();
                			        if(flag==1)					//Flag used to check whether record found or not and used to display details if found
                        			{
                        				a.display();
                        				cout<<"**************************************************"<<endl;
										mv.display();
										cout<<"\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
										flag=0;	
									}
                        			else
                       				cout<<"Policy not found."<<endl;
									break;
								case 3:								//Searches the records by the unique car ID
									Read_unique();
									break;
								case 4:								//Searches the records with the help of car's model name
									Read_model();
									break;
								case 5:								//Option to return to previous menu
									goto lab;
									break;
							}
							system("pause");
						}while(1);
        			break;
    				case 4: exit(0);								//Option to exit the project for admin
           			default: cout<<"WRONG CHOICE!!!!! PLEASE TRY AGAIN";
    			}
				cout<<"\nPress any key to continue"<<endl;		//Gets executed if wrong choice is given and takes back to menu on pressing any key
    			getch();
    			}while(1);
				break;
			}
			else
			break;

		case 2:                            //********************************user part***********************************
			do			// No password required for entering the user menu and shows the features available to user. Runs until the user exits the project
			{
			system("cls");
			cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Autocare Insurance Company \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"<<endl;
    		cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 1. Create a new insurance policy";
    		cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 2. Renew an existing insurance policy";
    		cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 3. View your existing insurance policy";
    		cout<<"\n\n\xDB\xDB\xDB\xDB\xB2 4. Exit\n"<<endl;
    		t();
    		cout<<"\nEnter your choice :-\t";				//Asking for user's choice
    		cin>>n;
			switch(n)
			{
				case 1:										//Creates a new insurance policy, gives the policy number and writes to a file
            			{
							system("cls");
            				a.input();
            				mv.input_vehicle();
            				Write();
                        	cout<<"\n*********** YOUR DETAILS HAVE BEEN SAVED SUCCESSFULLY ***********"<<endl;
							cout<<"\n Your Policy Number is : "<<a.get_policy_no()<<"\n\nUse this policy number for further reference to your insurance policy "<<endl;
					    	break;
                        }
    			case 2: Renew();							//Allows the user to renew his existing insurance policy
						if(flag==1)
                        {
                        	flag=0;	
						}
                        else
                        cout<<"Policy not found."<<endl;
						break;
				case 3: Read();								//Allows the user to view his policy details by looking up his policy number
                        if(flag==1)
                        {
                        	a.display();
                        	cout<<"**************************************************"<<endl;
							mv.display();
							cout<<"\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
							flag=0;	
						}
                        else
                        cout<<"Policy not found."<<endl;
                        break;
				case 4: 									//Option to exit the project for user
				exit(0);
				default:
				cout<<"Wrong choice.Please try again"<<endl;
			}
			cout<<"\nPress any key to continue"<<endl;		//Gets printed if wrong choice is entered and returns to menu on any key press
    		getch();
			}while(1);
			break;
		case 3:												//Option to exit the project for anyone at start of project
			exit(1);
		default:
		cout<<"Wrong choice.Please try again"<<endl;
		break;
	}
	cout<<"\nPress any key to continue"<<endl;				//Gets printed if wrong choice is entered and returns to menu on any key press
    	getch();
	}while(1);
}
/******************************************* RENEW EXISTING POLICY *************************************************/
void Renew()				//Function to renew the insurance policy of the user by looking up his policy number
{
	int policy;
	ifstream fin("P2.dat",ios::binary);		//File where the client info is stored is opened in read mode to access the records to look up for policy number
    ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	ofstream fout("M3.dat",ios::binary);	//A temporary file is created and opened in write mode to store the new edited info
	if(!fin)								//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		delay(50);
		exit(1);
    }
   	if(!fin1)								//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		delay(50);
		exit(1);
    }
	cout<<"Enter your policy number :- ";	//Asks for policy number
    cin>>policy;
    while(!fin.eof())								//To match the policy number and read the info stored in files to classes
    {
        fin.read(reinterpret_cast <char *>(&a),sizeof(client));
        fin1.read(reinterpret_cast <char *>(&mv),sizeof(motorvehicle));
		if(fin.eof())
		break;
		if(a.get_policy_no()==policy)		//If policy found then renew policy and write to temporary file
        {
            cout<<"Policy found"<<endl;
            flag=1;
			mv.set_renew_date();
			if(v==1)
			{
				cout<<"Your Policy Has Been Renewed\n";
				fout.write(reinterpret_cast <const char *>(&mv),sizeof(motorvehicle));
				v=0;
			}
			else
			{
				fout.write(reinterpret_cast <const char *>(&mv),sizeof(motorvehicle));	
			}
        }
        else								//If not found then write as it is
        {
        	fout.write(reinterpret_cast <const char *>(&mv),sizeof(motorvehicle));
		}
    }
    fin.close();							//Closing all opened files
    fin1.close();
    fout.close();
    remove("M2.dat");						//Deleting the old file containing the renewal dates
    rename("M3.dat","M2.dat");				//Renaming the temporary file with the original file name
}
/******************************************* WRITING RECORD TO FILE *************************************************/
void Write()					//Function used to write a new record to a file
{
    ofstream fout("P2.dat",ios::app|ios::binary);	//File where the client info is stored is opened in append mode to write the new record into the file
    ofstream fout1("M2.dat",ios::app|ios::binary);	//File where motorvehicle info is stored is opened in append mode to write the new record into the file
	if(!fout)									//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
    }
    int pos;								//To get the number of records stored in the file in a variable so as to generate a policy number for new record
    fout.seekp(0,ios::end);
    pos=fout.tellp()/sizeof(client);
    a.set_policy_no(pos+1);
	fout.write(reinterpret_cast <const char *>(&a),sizeof(client));			//Writing the client class to file P2.dat
	fout1.write(reinterpret_cast <const char *>(&mv),sizeof(motorvehicle));	//Writing the motorvehicle class to file M2.dat
	fout.close();								//Closing all opened files
	fout1.close();
}
/******************************************* SEARCH BY POLICY NUMBER *************************************************/
void Read()								//Function used to find a record by looking up its policy number
{
    system("cls");
	int policy;							//To store policy number
    ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
    ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	if(!fin)							//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
    }
	cout<<"Enter your policy number :- ";	//Asks for policy number to check in records
    cin>>policy;
    while(fin)				//This loop runs till end of file is reached or till policy number is found
    {
        fin.read(reinterpret_cast <char *>(&a),sizeof(client));				//Reads the contents of files in classes to find a match
        fin1.read(reinterpret_cast <char *>(&mv),sizeof(motorvehicle));
		if(a.get_policy_no()==policy)
        {
            cout<<"Policy found"<<endl;
            flag=1;
            break;
        }
    }
    fin.close();							//Closing all the opened files
    fin1.close();
}
/******************************************* SEARCH CUSTOMER BY NAME *************************************************/
void Read_name()							//Function used to find a record by looking up the customer's name
{
	system("cls");
	ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
	if(!fin)								//Checks if the file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	if(!fin1)								//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	char ns[40],temp[40],fla=0;				//Declaration of character arrays and flags to store the customer's name and keep track of record match
	cout<<"Enter Customer's full name to search : ";		//Asking the customer's name
	cin.ignore();
	gets(ns);
	while(fin)				//This loop runs till the end of file is reached or the customer's name is found in records
	{
		fin.read(reinterpret_cast <char *>(&a),sizeof(client));				//Reading the contents of files in classes to look for a match
		fin1.read(reinterpret_cast <char *>(&mv),sizeof(motorvehicle));
		if(fin.eof())
		break;
		strcpy(temp,a.get_first_name());		//Storing the full name of the customer in one array for comparison
		strcat(temp," ");
		strcat(temp,a.get_last_name());
		if(strcmpi(ns,temp)==0)					//If names match then display info else notify record doesn't exist
		{
			a.display();
			cout<<"**************************************************"<<endl;
			mv.display();
			cout<<"\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
			fla=1;
		}
	}
	if(fla==0)
	{
		cout<<"Record doesn't exist"<<endl;
	}
	fin.close();								//Closing all opened files
	fin1.close();
}
/******************************************* SEARCH BY CAR MODEL NUMBER *************************************************/
void Read_model()							//Function used to search a record by looking up the car's model
{
	system("cls");
	ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
	ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	if(!fin)								//Checks if the file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	if(!fin1)								//Checks if the file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	char mo[20];							//Declaration of character array to store model name and flag to keep track of record match
	int fla=0;
	cout<<"Enter Car's Model to search : "; 		//Asking for car's model
	cin>>mo;
	while(!fin.eof())				//This loop runs till end of file is reached
	{
		fin.read(reinterpret_cast <char*>(&a),sizeof(client));			//Reading the contents of the file in classes to look for a match
		fin1.read(reinterpret_cast <char*>(&mv),sizeof(motorvehicle));
		if(fin.eof())
		break;		
		if(strcmpi(mo,mv.get_model())==0)						//To display all the insurances with the model's name if exists
		{
			fla=1;
			a.display();
			cout<<"**************************************************"<<endl;
			mv.display();
			cout<<"\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
		}
	}
	if(fla==0)
	cout<<"Record doesn't exist";
	fin.close();											//Closing all the opened files
	fin1.close();
}
/******************************************* SEARCH BY CAR UNIQUE NUMBER *************************************************/
void Read_unique()							//Function used to search a record by looking up the car's Unique ID number
{
	system("cls");
	ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
	ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	if(!fin)								//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	if(!fin1)								//Checks if file exists or not
	{
		cout<<"File doesn't exist";
		exit(1);
	}
	char cp[15];							//Declaration of character to store the car's Unique ID number and flag to keep track of recordd match
	int fla=0;
	cout<<"Enter car's Unique ID number to be searched : ";		//Asking for the car's Unique ID
	cin>>cp;
	while(!fin.eof())			//This loop runs till end of ile is reached or the car's Unique ID is found in records
	{
		fin.read(reinterpret_cast <char*>(&a),sizeof(client));			//Reading the contents of the file in classes to look for a match
		fin1.read(reinterpret_cast <char*>(&mv),sizeof(motorvehicle));
		if(fin.eof())
		break;
		if(strcmpi(cp,mv.get_car_plate_no())==0)	//If car's Unique ID is matched then show the details else notify that record doesn't exists
		{
			fla=1;
			a.display();
			cout<<"**************************************************"<<endl;
			mv.display();
			cout<<"\n\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n\n";
		}
	}
	if(fla==0)
	cout<<"Record doesn't exist"<<endl;
	fin.close();									//Closing all openeed files
	fin1.close();
}
/******************************************* SORT CUSTOMER NAME *************************************************/
void Sort()							//Function to sort the records by the customer's names
{
	system("cls");
	ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
	if(!fin)								//Checks if file exists or not
	{
		cout<<"File doesn't exist"<<endl;
		exit(1);
	}
	fin.seekg(0,ios::end);					//File pointer is moved to end of file
	int num,i=0,j=0;						
	num=fin.tellg()/sizeof(client);			//Getting the number of records available in the file
	char names[num][40],temp[40];			//Declaration of character arrays to store the names of the customers
	fin.close();							//Closing the opened file							
	fin.open("P2.dat",ios::binary);			//File where client info is stored is again opened in read mode to access the records
	while(!fin.eof())					//This loop runs till end of file is reached and used store all the customers name in a 2-D array
	{
		fin.read(reinterpret_cast <char *>(&a),sizeof(client));		//Reading contents of file in class to store the names
		if(fin.eof())
		break;
		strcpy(temp,a.get_first_name());				//Storing the full name of the customer in 2-D array
		strcat(temp," ");
		strcat(temp,a.get_last_name());
		strcpy(names[i],temp);
		i++;
	}
	for(i=0;i<num;i++)							//This loop is used to sort the 2-D array of customer's names in lexographic order
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmpi(names[i],names[j])>0)
			{
				strcpy(temp,names[i]);
				strcpy(names[i],names[j]);
				strcpy(names[j],temp);
			}
		}
	}
	int po[num];						//Declaration of integer array to store policy numbers
	fin.close();						//Closing the opened file
	j=0;
	for(i=0;i<num;i++)					//This loop is used to match the arranged customer's names with their corresponding policy numbers
	{
		fin.open("P2.dat",ios::binary);		//File where client info is stored is again opened in read mode to access the records
		while(!fin.eof())				//This loop runs till end of file is reached and stores the corresponding policy number in the array
		{
			fin.read(reinterpret_cast <char*>(&a),sizeof(client));  //Reading contents of file in class
			if(fin.eof())
			break;
			strcpy(temp,a.get_first_name());			//Storing the customers full name in a temporary character array
			strcat(temp," ");
			strcat(temp,a.get_last_name());
			if(strcmpi(names[i],temp)==0)				//If the names match store the policy number
			{
				po[j]=a.get_policy_no();
				j++;
			}
		}
		fin.close();							//Closing the opened file
	}
	gotoxy(3,3);								//Displaying the sorted records by customer's name in a tabular form
	cout<<"Names";
	gotoxy(45,3);
	cout<<"Policy Number";
	for(i=0;i<num;i++)
	{
		gotoxy(1,3+(2*i+1));
		cout<<i+1<<".";
		gotoxy(3,3+(2*i+1));
		cout<<names[i];
		gotoxy(45,3+(2*i+1));
		cout<<po[i];
		gotoxy(2,3+(2*i+2));
		cout<<"-------------------------------------------------------"<<endl;
	}
	fin.close();							//Closing the opened files
}
/******************************************* SORT CAR UNIQUE ID *************************************************/
void Sort_car_id()					//Function to sort the records by the car's Unique ID
{
	system("cls");
	ifstream fin1("M2.dat",ios::binary);	//File where motorvehicle info is stored is opened in read mode to access the records
	ifstream fin("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
	if(!fin1)								//Checks if file exists or not
	{
		cout<<"File doesn't exist"<<endl;
		exit(0);
	}
	int num,i=0,j=0;
	fin1.seekg(0,ios::end);					//File pointer moved to file's end
	num=fin1.tellg()/sizeof(motorvehicle);	//Getting the number of records available in a file
	char car[num][15],temp[15];				//Declaration of character array to store the Unique IDs of the customers
	int po[num];							//Declaration of integer array to store the policy number of the customers
	char name[num][40],temp1[40];			//Declaration of character array to store the name of the customers
	fin1.close();							//Closing the opened file
	fin1.open("M2.dat",ios::binary);		//File where motorvehicle info is stored is again opened in read mode to access the records
	while(!fin1.eof())				//This loop runs till end of file is reached and stores the car Unique IDs in the 2-D array
	{
		fin1.read(reinterpret_cast <char *>(&mv),sizeof(motorvehicle));		//Reading contents of file in a class
		if(fin1.eof())
		break;
		strcpy(car[i],mv.get_car_plate_no());
		i++;
	}
	for(i=0;i<num;i++)				//This loop is used to sort the 2-D array containing the car Unique IDs in lexographic order
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmpi(car[i],car[j])>0)
			{
				strcpy(temp,car[i]);
				strcpy(car[i],car[j]);
				strcpy(car[j],temp);
			}
		}
	}
	fin1.close();					//Closing all the opened files
	fin.close();
	j=0;
	for(i=0;i<num;i++)						//This loop is used to match the arranged car Unique IDs with their corresponding policy numbers
	{
		fin1.open("M2.dat",ios::binary);	//File where motorvehicle info is stored is again opened in read mode to access the records
		fin.open("P2.dat",ios::binary);		//File where client info is stored is again opened in read mode to access the records
		while(!fin1.eof())			//This loop runs till end of file is reached and stores the corresponding policy number and customer's name in 2-D arrays
		{
			fin1.read(reinterpret_cast<char*>(&mv),sizeof(motorvehicle));	//Reading the contents of the files in classes
			fin.read(reinterpret_cast<char*>(&a),sizeof(client));
			strcpy(temp,mv.get_car_plate_no());
			if(fin.eof())
			break;
			if(strcmpi(car[i],temp)==0)
			{
				po[j]=a.get_policy_no();
				strcpy(temp1,a.get_first_name());
				strcat(temp1," ");
				strcat(temp1,a.get_last_name());
				strcpy(name[j],temp1);
				j++;
			}
		}
		fin.close();						//Closing all the opened files
		fin1.close();
	}
	gotoxy(3,0);							//Displaying the sorted records by car Unique IDs in a tabular form
	cout<<"Car ID";
	gotoxy(20,0);
	cout<<"Name";
	gotoxy(50,0);
	cout<<"Policy number";
	for(i=0;i<num;i++)
	{
		gotoxy(1,0+(2*i+1));
		cout<<i+1<<".";
		gotoxy(3,0+(2*i+1));
		cout<<car[i];
		gotoxy(20,0+(2*i+1));
		cout<<name[i];
		gotoxy(50,0+(2*i+1));
		cout<<po[i];
		gotoxy(3,0+(2*i+2));
		cout<<"----------------------------------------------------------------------"<<endl;
	}
	fin1.close();
}
/******************************************* SORT CAR NAME *************************************************/
void Sort_car_name()							//Function to sort the records by car's names
{
	system("cls");
	ifstream fin1("M2.dat",ios::binary);		//File where motorvehicle info is stored is opened in read mode to access the records
	ifstream fin;
	if(!fin1)									//Checks if the file exists or not
	{
		cout<<"File doesn't exist"<<endl;
		exit(0);
	}
	int num,i=0,j;
	fin1.seekg(0,ios::end);						//File pointer is moved to file's end
	num=fin1.tellg()/sizeof(motorvehicle);		//Getting the number of records available in the file
	fin1.close();								//Closing the opened file
	char ca[num][40];							//Declaration of character arrays to store the car's names
	char temp[40];
	fin1.open("M2.dat",ios::binary);			//File where motorvehicle info is stored is again opened in read mode to access the records
	while(!fin1.eof())					//This loop runs till end of file is reached and stores the car's name in 2-D array
	{
		fin1.read(reinterpret_cast <char*>(&mv),sizeof(motorvehicle));		//Reading contents of file in class
		if(fin1.eof())
		break;
		strcpy(temp,mv.get_make());
		strcat(temp," ");
		strcat(temp,mv.get_model());
		strcpy(ca[i],temp);
		i++;
	}
	for(i=0;i<num;i++)					//This loop is used to sort the car's name stored in the 2-D array in lexographic order
	{
		for(j=i+1;j<num;j++)
		{
			if(strcmpi(ca[i],ca[j])>0)
			{
				strcpy(temp,ca[i]);
				strcpy(ca[i],ca[j]);
				strcpy(ca[j],temp);
			}
		}
	}
	fin1.close();					//Closing the opened file
	j=0;
	char temp1[40],name[num][40];	//Declaration of character array to store customer's names and integer array to store policy numbers
	int po[num];
	
	for(i=0;i<num;i++)				//This loop is used to match the arranged car's names with their corresponding policy numbers
	{
		fin1.open("M2.dat",ios::binary);	//File where motorvehicle info is stored is again opened in read mode to access the records
		fin.open("P2.dat",ios::binary);		//File where client info is stored is opened in read mode to access the records
		while(!fin1.eof())			//This loop runs till end of file is reached and stores the corresponding policy number and customer's names in 2-D arrays
		{
			fin1.read(reinterpret_cast<char*>(&mv),sizeof(motorvehicle));		//Reading the contents of the files in classes
			fin.read(reinterpret_cast<char*>(&a),sizeof(client));
			strcpy(temp,mv.get_make());
			strcat(temp," ");
			strcat(temp,mv.get_model());
			if(fin.eof())
			break;
			if(strcmp(ca[i],temp)==0)
			{
				po[j]=a.get_policy_no();
				strcpy(temp1,a.get_first_name());
				strcat(temp1," ");
				strcat(temp1,a.get_last_name());
				strcpy(name[j],temp1);
				j++;
			}
		}
		fin.close();						//Closing all the opened files
		fin1.close();
	}
	system("cls");
	gotoxy(3,0);							//Displaying the sorted records by car's name in a tabular form
	cout<<"Car name";
	gotoxy(30,0);
	cout<<"Name";
	gotoxy(60,0);
	cout<<"Policy number";
	for(i=0;i<num;i++)
	{
		gotoxy(1,0+(2*i+1));
		cout<<i+1<<".";
		gotoxy(3,0+(2*i+1));
		cout<<ca[i];
		gotoxy(30,0+(2*i+1));
		cout<<name[i];
		gotoxy(60,0+(2*i+1));
		cout<<po[i];
		gotoxy(3,0+(2*i+2));
		cout<<"-----------------------------------------------------------------------------"<<endl;
	}
	fin1.close();				//Closing the opened file
}
/******************************************* MAIN FUNCTION ***************************************1**********/
int main()																	//The main function. Is called first
{
    int m;														//Declaration of loop counter
    system("color 0a");											//Setting system colour
    string banana="Programmed by :- ";							//Displaying the names of developer of the project
	string apple="Kunal Sikri - 150001016 (CSE)";
	string pineapple="Aashish Bhole - 150002012 (EE)";
    gotoxy(10,6);
	for(m=0;m<17;m++)											//Displays the string "Programmed by :- " with slight delay
    {
    	delay(50);
    	cout<<"*";
	}
    cout<<" ";
    for(m=0;m<17;m++)
    {
		delay(50);
		cout<<banana[m];
	}
	cout<<" ";
	for(m=0;m<16;m++)
	{
		delay(50);
		cout<<"*";
	}
	gotoxy(10,9);
	for(m=0;m<10;m++)											//Display the string "Kunal Sikri - 150001016 (CSE)" with slight delay
    {
    	delay(50);
    	cout<<"*";
	}
    cout<<" ";
    for(m=0;m<29;m++)
    {
		delay(50);
		cout<<apple[m];
	}
	cout<<" ";
	for(m=0;m<11;m++)
	{
		delay(50);
		cout<<"*";
	}
	gotoxy(10,12);
	for(m=0;m<10;m++)											//Display the string "Aashish Bhole - 150002012 (EE)" with slight delay
    {
    	delay(50);
    	cout<<"*";
	}
    cout<<" ";
    for(m=0;m<30;m++)
    {
		delay(50);
		cout<<pineapple[m];
	}
	cout<<" ";
	for(m=0;m<10;m++)
	{
		delay(50);
		cout<<"*";
	}
	gotoxy(10,15);
	cout<<"Project is loading ";								//Informs that project is loading
	for(m=0;m<10;m++)
	{
		delay(300);
		cout<<".";
	}
	delay(100);
    system("cls");
	mainmenu();													//Take the control to the main menu designed after loading of project
	return 0;
}
