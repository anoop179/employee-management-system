#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
#include<cctype>
#include<algorithm>
using namespace std;

#define AdminUsername "Admin"
#define AdminPassword "Admin123"
#define defaultPassword "newemp"
#define FILENAME "Employeerecords.txt"
#define TEMPFILE "temp.txt"
#define HRA 0.1
#define PF 0.12
//#define DA 0.05
#define ESI 158.00
#define Conveyence 1600.00
#define Pro 0.0
#define Medical 1250.00
void press()
{
	char cont;
	cout<<"\n\n\t\tPress any character to continue: ";
	scanf(" %c",&cont);
	system("cls");
}

void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}

bool checkdate(int m, int d, int y)
{
 
  if (! (2021>= y )  )
     return false;
  if (! (1<= m && m<=12) )
     return false;
  if (! (1<= d && d<=31) )
     return false;
  if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
     return false;
  if ( (d==30) && (m==2) )
     return false;
  if ( (m==2) && (d==29) && (y%4!=0) )
     return false;
  if ( (m==2) && (d==29) && (y%400==0) )
     return true;
  if ( (m==2) && (d==29) && (y%100==0) )
     return false;
  if ( (m==2) && (d==29) && (y%4==0)  )
     return true;
 
  return true;
}

class User
{
    public:

    char username[20];
    char password[10];
    int empId,workdays,desigid,LOP;
    int dd,mm,yyyy;
    char empname[25],empAddress[50],empDesig[20],empMail[30],empPhn[11],empBank[20];
    float basic,total,allowance;
    char role;
    

};
vector <User> myuser;
class Manager : public User
{
    public:
    void addEmployee();
    void searchEmployee(int);
    void displayAll();
    void modifyEmployee();
    void deleteEmployee();
};
void Manager::addEmployee()
{
    bool check;
    int valid;
    system("cls");
    User u;
    fstream file;
   
    file.open(FILENAME,ios::out );
    cout<<"\n\nEnter Employee Id : ";
    scanf("%d",&u.empId);
    scanf("%c", (char *) stdin);

    cout<<"\n\nEnter employee name : ";
    fgets(u.empname,25,stdin);

     cout<<"\n\nEnter employee Address : ";
     fgets(u.empAddress,50,stdin);

     do
    {
       check=true;
      cout<<"\n\nEnter Date of Joining in format dd/mm/yyyy : ";
      scanf("%d/%d/%d",&u.dd,&u.mm,&u.yyyy);
      check=checkdate(u.mm,u.dd,u.yyyy);
       if(check==false)
      {
          cout<<"\n\n please enter valid date ";
      }
    }while(check==false);
    scanf("%c", (char *) stdin);

    cout<<"\n\n enter the email address : ";
    cin>>u.empMail;
    //fgets(u.empMail,20,stdin);
    //scanf("%c", (char *) stdin);

    cout<<"\n\n Enter phone number : ";
    //fgets(u.empPhn,11,stdin);
    cin>>u.empPhn;

    cout<<"\n\n Enter employee bank A/c number : ";
    //fgets(u.empBank,15,stdin);
    cin>>u.empBank;

    do
    {
    int valid=0;
	cout<<"\n\n\t1. Manager 2. Senior Executive 3. Junior Executive 4. Trainee 5. Accountant ";
	cout<<"\n\t\tEnter Designation code: ";
    scanf("%d",&u.desigid);
    switch(u.desigid) //adding designation and basic pay corresponding to id
                {
                        case 1: strcpy(u.empDesig,"Manager");
                                u.basic=30000;
                    		    u.role='a';
                                break;
                        case 2: strcpy(u.empDesig,"Senior Executive");
                                u.basic=25000;
                    		    u.role='n';
                                break;
                        case 3: strcpy(u.empDesig,"Junior Executive");
                                u.basic=20000;
                    		    u.role='n';
                                break;
                        case 4: strcpy(u.empDesig,"Trainee");
                                u.basic=15000;
                    		    u.role='n';
                                break;
            		    case 5: strcpy(u.empDesig,"Accountant");
                    	    	u.basic=20000;
                    		    u.role='c';
                    		    break;
                       default: {cout<<"\n\n\t invalid choice ";
                     		    valid=1;}
                }

        }while(valid==1);
    scanf("%c", (char *) stdin);
    
    /*cout<<"\n\n Enter other allowances : ";
    scanf("%f",&u.allowance);
    scanf("%c", (char *) stdin);*/

    cout<<"\n\n the default user name is set up as your empid and default password is set up as newemp \n please change it after login ";
    sprintf(u.username,"%d",u.empId);
    strcpy(u.password,defaultPassword);
    //cout<<u.username<<"  "<<u.password;
    myuser.push_back(u);
    file.write((char*)&myuser,sizeof(myuser));
    file.close();
    press();

}
void Manager::modifyEmployee()
{

    bool check;
    int valid;
    int tempid;
    system("cls");
    User u;
    fstream file;
    file.open(FILENAME,ios::in | ios::out);
    file.read((char*)&myuser,sizeof(myuser));


    cout<<"\n\nEnter Employee Id to modify : ";
    scanf("%d",&tempid);
    scanf("%c", (char *) stdin);
    //vector <User>::iterator it;

   // auto it = find_if(myuser.begin(), myuser.end(), it->empId==tempid);
    auto it = find_if(myuser.begin(), myuser.end(),[&tempid](const User& u) {return u.empId == tempid;});
    if(it != myuser.end())
    {
    cout<<"\n\n Employee found the employee id cannot be changed ";  
    cout<<"\n\nEnter employee name : ";
    fgets(it->empname,25,stdin);

     cout<<"\n\nEnter employee Address : ";
     fgets(it->empAddress,50,stdin);

     do
    {
       check=true;
      cout<<"\n\nEnter Date of Joining in format dd/mm/yyyy : ";
      scanf("%d/%d/%d",&it->dd,&it->mm,&it->yyyy);
      check=checkdate(it->mm,it->dd,it->yyyy);
       if(check==false)
      {
          cout<<"\n\n please enter valid date ";
      }
    }while(check==false);
    scanf("%c", (char *) stdin);

    cout<<"\n\n enter the email address : ";
    cin>>it->empMail;
    //fgets(u.empMail,20,stdin);
    //scanf("%c", (char *) stdin);

    cout<<"\n\n Enter phone number : ";
    //fgets(u.empPhn,11,stdin);
    cin>>it->empPhn;

    cout<<"\n\n Enter employee bank A/c number : ";
    //fgets(u.empBank,15,stdin);
    cin>>it->empBank;
    do
    {
    int valid=0;
	cout<<"\n\n\t1. Manager 2. Senior Executive 3. Junior Executive 4. Trainee 5. Accountant ";
	cout<<"\n\t\tEnter Designation code: ";
    scanf("%d",&it->desigid);
    switch(it->desigid) //adding designation and basic pay corresponding to id
                {
                        case 1: strcpy(it->empDesig,"Manager");
                                it->basic=30000;
                    		    it->role='a';
                                break;
                        case 2: strcpy(it->empDesig,"Senior Executive");
                                it->basic=25000;
                    		    it->role='n';
                                break;
                        case 3: strcpy(it->empDesig,"Junior Executive");
                                it->basic=20000;
                    		    it->role='n';
                                break;
                        case 4: strcpy(it->empDesig,"Trainee");
                                it->basic=15000;
                    		    it->role='n';
                                break;
            		    case 5: strcpy(it->empDesig,"Accountant");
                    	    	it->basic=20000;
                    		    it->role='c';
                    		    break;
                       default: {cout<<"\n\n\t invalid choice ";
                     		    valid=1;}
                }

        }while(valid==1);
    scanf("%c", (char *) stdin);
    
    /*cout<<"\n\n Enter other allowances : ";
    scanf("%f",&it->allowance);
    scanf("%c", (char *) stdin);*/
    file.write((char*)&myuser,sizeof(myuser));
    }
    else{
        cout<<"\n\n The employee is not found in records ";
    }
    file.close();
    press();

}
void Manager::deleteEmployee()
{

    int tempid;
    system("cls");
    User u;
    fstream file;
    file.open(FILENAME,ios::in | ios::out);
    file.read((char*)&myuser,sizeof(myuser));


    cout<<"\n\nEnter Employee Id to modify : ";
    scanf("%d",&tempid);
    scanf("%c", (char *) stdin);
    //vector <User>::iterator it;

    //it = find(myuser.begin(), myuser.end(), it->empId=tempid);
    auto it = find_if(myuser.begin(), myuser.end(),[&tempid](const User& u) {return u.empId == tempid;});
    if(it != myuser.end())
    {
        it=myuser.erase(it);
        cout<<"\n\n Employee Deleted ";

    }
    else
    {
        cout<<"\n\n the employee was not found in records ";
    }
    file.write((char*)&myuser,sizeof(myuser));
    file.close();
    press();

}

void Manager::searchEmployee(int tempid)
{

    system("cls");
    User u;
    fstream file;
    file.open(FILENAME,ios::out);
    file.read((char*)&myuser,sizeof(myuser));
    
   /* cout<<"\n\nEnter Employee Id to search : ";
    scanf("%d",&tempid);
    scanf("%c", (char *) stdin);
    */
    //vector <User>::iterator it;

    //it = find(myuser.begin(), myuser.end(), it->empId=tempid);
    auto it = find_if(myuser.begin(), myuser.end(),[&tempid](const User& u) {return u.empId == tempid;});
    if(it != myuser.end())
    {
        cout<<"\n\nEmployee found ";
        cout<<"\n-----------------------------------------------------------------------------------"<<endl;
        cout<<"Employee id       : "<<it->empId<<endl;
        cout<<"Employee name     : "<<it->empname<<endl;
        cout<<"Address           : "<<it->empAddress<<endl;
        cout<<"Contact No        : "<<it->empPhn<<endl;
        cout<<"Designation       : "<<it->empDesig<<endl;
        cout<<"Bank A/c No       : "<<it->empBank<<endl;
        cout<<"Email id          : "<<it->empMail<<endl;
        cout<<"Basic Salary      : "<<it->basic<<endl;
        cout<<"DoJ               : "<<it->dd<<"/"<<it->mm<<"/"<<it->yyyy<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl; 

    }
    else
    {
        cout<<"\n\n the employee was not found in records ";
    }
    file.close();
    press();


}
void Manager::displayAll()
{
    
    system("cls");
    User u;
    fstream file;
    file.open(FILENAME,ios::out);
    file.read((char*)&myuser,sizeof(myuser));
    if(myuser.empty())
    {
        cout<<"\n\n no records found !!";
    }
    else
    {
    
    vector <User>::iterator it;
    for (it = myuser.begin(); it != myuser.end(); ++it) 
    {
        cout<<"\n\nEmployee found ";
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"Employee id       : "<<it->empId<<endl;
        cout<<"Employee name     : "<<it->empname<<endl;
        cout<<"Address           : "<<it->empAddress<<endl;
        cout<<"Contact No        : "<<it->empPhn<<endl;
        cout<<"Designation       : "<<it->empDesig<<endl;
        cout<<"Bank A/c No       : "<<it->empBank<<endl;
        cout<<"Email id          : "<<it->empMail<<endl;
        cout<<"Basic Salary      : "<<it->basic<<endl;
        cout<<"DoJ               : "<<it->dd<<"/"<<it->mm<<"/"<<it->yyyy<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl; 
    }
    }
    file.close();
    press();

}

class Accountant : public User
{
    public:
    void calculateSalary(int);
    void PrintSalary(int);

};
void Accountant::calculateSalary(int tempid)
{

    
    system("cls");
    User u;
    float hra,pf,da,other;
    fstream file;
    file.open(FILENAME,ios::in | ios::out);
    file.read((char*)&myuser,sizeof(myuser));
    auto it = find_if(myuser.begin(), myuser.end(),[&tempid](const User& u) {return u.empId == tempid;});
    if(it != myuser.end())
    {
        cout<<"\n-------------------------------------------------------------------------";
        cout<<"\n\n\t\tEMPLOYEE ID       : "<<it->empId;
        cout<<"\n\n\t\tNAME              : "<<it->empname;
        cout<<"\n\n\t\tDESIGNATION       : "<<it->empDesig;
        cout<<"\n\n\t\tEnter other allowance for this employee(%) : ";
        cin>>it->allowance;
        cout<<"\n\n\t\t Enter no of leave taken by this employee  : ";
        cin>>it->LOP;
        pf=0.12*it->basic;
        hra=0.1*it->basic;
        da=0.05*it->basic;
        other=it->basic*it->allowance/100;
        it->total=it->basic+hra+da+other-pf;
        cout<<"\n\n\t\tSalary for Employee for this month = "<<it->total;
        cout<<"\n-------------------------------------------------------------------------";
       

    }
    else
    {
        cout<<"\n\n the employee was not found in records ";
    }
    file.write((char*)&myuser,sizeof(myuser));
    file.close();
    press();



}
void Accountant::PrintSalary(int tempid)
{
    
    system("cls");
    User u;
    float hra,pf,da,other;
    fstream file;
    file.open(FILENAME,ios::in | ios::out);
    file.read((char*)&myuser,sizeof(myuser));
    auto it = find_if(myuser.begin(), myuser.end(),[&tempid](const User& u) {return u.empId == tempid;});
    if(it != myuser.end())
    {
        system("cls");
        gotoxy(5,5);
	    cout<<"\n\t--------------------------------------------------------------------------------------------------------------------------------------------------";
        gotoxy(70,10);
        cout<<"----PAYSLIP----";
        gotoxy(10,12);
        cout<<"\tEMPLOYEE ID                : "<<it->empId;
        gotoxy(100,12);
        cout<<"\tNAME                       : "<<it->empname;
        gotoxy(10,13);
        cout<<"\tDoJ                        : "<<it->dd<<"/"<<it->mm<<"/"<<it->yyyy;
        gotoxy(100,13);
        cout<<"\tBANK A/c NO                : "<<it->empBank;
        gotoxy(10,14);
        cout<<"\tDesignation                : "<<it->empDesig;
        gotoxy(100,14);
        cout<<"\tTotal Working Days         : "<<30;
        gotoxy(10,15);
        cout<<"\tEmail id                   : "<<it->empMail;
        gotoxy(100,15);
        cout<<"\tLOP Days                   : "<<it->LOP;
        gotoxy(10,16);
        cout<<"\tContact No                 : "<<it->empPhn;
        gotoxy(100,16);
        cout<<"\tPaid Days                  : "<<30-it->LOP;
        gotoxy(20,18);
        cout<<"\tEarnings ";
        gotoxy(110,18);
        cout<<"\tDeductions";
        gotoxy(10,19);
        cout<<"\tBASIC                     : Rs."<<it->basic;
        gotoxy(100,19);
        cout<<"\tEPF                       : Rs."<<it->basic*PF;
        gotoxy(10,20);
        cout<<"\tHRA                       : Rs."<<it->basic*HRA;
        gotoxy(100,20);
        cout<<"\tESI                       : Rs."<<ESI;
        gotoxy(10,21);
        cout<<"\tConveyence Allowance      : Rs."<<Conveyence;
        gotoxy(10,22);
        cout<<"\tMedical Allowances        : Rs."<<Medical;
        gotoxy(10,23);
        cout<<"\tOther Allowances          : Rs."<<(it->basic*it->allowance/100);
        gotoxy(10,25);
        cout<<"\tTotal Earnings            : Rs."<<(it->basic*(30-it->LOP)/30+HRA*it->basic+(it->basic*it->allowance/100)+Conveyence+Medical);
        gotoxy(100,25);
        cout<<"\tTotal Deductions          : Rs."<<(PF*it->basic+ESI);
	    cout<<"\n\t--------------------------------------------------------------------------------------------------------------------------------------------------";
	    cout<<"\n\t--------------------------------------------------------------------------------------------------------------------------------------------------";          
	    gotoxy(70,28);      
	    cout<<"Net Salary - \tRs."<<it->total;        
        cout<<"\n\n\t--------------------------------------------------------------------------------------------------------------------------------------------------";

    }
    else
    {
        cout<<"\n\n the employee was not found in records ";
    }
    file.write((char*)&myuser,sizeof(myuser));
    file.close();
    press();

}

class menu : public User
{
	/*private:
		int choice;
		char usernm[10],passwd[10];
		char user[10]={"Admin"};
		char pass[10]={"Admin123"};
		char empuser[10]={"Employee"};
		char emppass[10]={"Emp123"};
		char accuser[10]={"Account"};
		char accpass[10]={"Acc123"};*/
	public:
    Manager M;
    Accountant A;
    
		void welcome();
		void login();
        void updateCredentials();
		void adminMenu();
		void employeeMenu(int);
		void accountantMenu();
};

void menu::welcome()
{
    system("cls");
	char option;
	gotoxy(30,5);
	cout<<"____________________________________________________________________"<<endl;
	gotoxy(30,6);		
	cout<<"|                                                                  |"<<endl;
	gotoxy(30,7);		
	cout<<"|             WELCOME TO EXCALIBUR ENTERPRISES PVT LTD             |"<<endl;//13 spaces		
	gotoxy(30,9);		
	cout<<"|__________________________________________________________________|"<<endl;		
	gotoxy(35,10);		
	cout<<"Enter"<<endl;
	gotoxy(40,12);                
	cout<<"L for Login"<<endl;
	gotoxy(40,14);
	cout<<"U to update credentials"<<endl;
	gotoxy(40,16);
	cout<<"E for exit "<<endl;
	gotoxy(35,18);
    cout<<"Enter your choice : ";	
    cin>>option;
    switch(option)
    {
		case 'L':login(); break;
		case 'E':exit(0); break;
        case 'U':updateCredentials();
		default: {cout<<"\nWrong choice"<<endl;
                    welcome();
                    }
	}
}
void menu::updateCredentials()
{
    
	system("cls");
	char usernm[20],passwd1[10],passwd2[10],passwd3[10];
    char choice;
    int valid,check;
    gotoxy(40,10);
    cout<<"Enter your User Name\t: ";
    //cin.ignore();
    //gets(usernm);
	cin>>usernm;
	gotoxy(40,12);
    cout<<"Enter your password\t: ";
    //cin.ignore();
    //gets(passwd);
	cin>>passwd1;
    User u;
    fstream file;
    file.open(FILENAME,ios::out);
    file.read((char*)&myuser,sizeof(myuser));
        
    auto it = find_if(myuser.begin(), myuser.end(),[usernm](const User& u) {return !(strcmp(u.username,usernm));});
    auto it2= find_if(myuser.begin(), myuser.end(),[passwd1](const User& u) {return !(strcmp(u.password,passwd1));} );
    if(it != myuser.end() && it2 != myuser.end())
    {
        system("cls");
    gotoxy(40,12);
    cout<<"Enter new User Name\t: ";
    //cin.ignore();
    //gets(usernm);
	cin>>usernm;
	gotoxy(40,14);
    cout<<"\nEnter new password\t: ";
    //cin.ignore();
    //gets(passwd);
	cin>>passwd2;
    gotoxy(40,15);
    cout<<"\nEnter new password again to confirm \t: ";
    //cin.ignore();
    //gets(passwd);
	cin>>passwd3;
    if(strcmp(passwd2,passwd3)==0)
    {
        check=0;
        strcpy(it->username,usernm);
        strcpy(it->password,passwd2);
        cout<<"\n\n\npassword changed successfully ";
        press();
        welcome();
    }
    else if(check!=0)
    {
        cout<<"\n\n password mismatch";
        updateCredentials();
    }
    
    }
    else
    {
        cout<<"wrong password or username please try again ";
        welcome();

    }
    file.write((char*)&myuser,sizeof(myuser));
    file.close();
    press();

}

void menu::login()
{

	system("cls");
	char usernm[20],passwd[10];
    char choice;
    int valid,check;
    gotoxy(40,10);
    cout<<"Enter your User Name\t: ";
    //cin.ignore();
    //gets(usernm);
	cin>>usernm;
	gotoxy(40,12);
    cout<<"Enter your password\t: ";
    //cin.ignore();
    //gets(passwd);
	cin>>passwd;
	if( (strcmp(usernm,AdminUsername) == 0) && (strcmp(passwd,AdminPassword) == 0) )
    {
       	adminMenu();
    }
    else
    {
        User u;
        fstream file;
        file.open(FILENAME,ios::out);
        file.read((char*)&myuser,sizeof(myuser));
        
        auto it = find_if(myuser.begin(), myuser.end(),[usernm](const User& u) {return !(strcmp(u.username,usernm));});
        auto it2= find_if(myuser.begin(), myuser.end(),[passwd](const User& u) {return !(strcmp(u.password,passwd));} );
        if(it != myuser.end() && it2 != myuser.end())
        {
            switch(it->role)
                    	{
                        	case 'a':cout<<"\nYou have admin Privileges!";
                    			 adminMenu();
                    			 break;
                        	case 'n': employeeMenu(it->empId);
                    			 break;
                        	case 'c':accountantMenu();
                    			 break;
            			    default: cout<<"\nUNEXPECTED ERROR";
                    	}
           
        }
        else
        {
            do
            {
      
            check=0;
            cout<<"\n\nyou have entered wrong user name or password ";
            cout<<"\n press L to return to Login or press M to return to main menu ";
            cin>>choice;
            switch (choice)
            {
            case 'L':login();
                break;
            case 'M':welcome();
                break;
            default:{cout<<"\n\n Wrong choice ";
                     check=1;
                     system("cls");}
                      break;
            }
            }while(check==1);

        }

        file.close();

    }
  
}

void menu::adminMenu()
{
    int valid=0,choice,tempid;
    while(1)
    {   valid=0;
	system("cls");     
	gotoxy(50,5);
    cout<<"ADMIN MENU "<<endl;
    gotoxy(40,10);
    cout<<"1. Add Employee"<<endl;
    gotoxy(40,12);
    cout<<"2. Delete Employee"<<endl;
    gotoxy(40,14);
    cout<<"3. Modify Employee"<<endl;
    gotoxy(40,16);
    cout<<"4. Display Employee List"<<endl;
    gotoxy(40,18);
    cout<<"5. Search Record"<<endl;
    gotoxy(40,20);
    cout<<"6. Back to Login"<<endl;
    gotoxy(40,22);
    cout<<"0. EXIT"<<endl;
    gotoxy(40,26);
    cout<<"Enter Your Option :--> ";
    cin>>choice;
    switch(choice)
    {
        case 0: exit(0);
        break;
        case 1: M.addEmployee();
        break;
        case 2: M.deleteEmployee();
        break;
        case 3: M.modifyEmployee();
        break;
        case 4: M.displayAll();
        break;
        case 5:{cout<<"\n\n enter Employee id to search ";
                   scanf("%d",&tempid);
                   scanf("%c", (char *) stdin);
                   M.searchEmployee(tempid);}
        break;
        case 6: login();
        break;
        default: {valid=1;
        cout<<"\n\nwrong choice please try again ";
        }
    }

    }

}

void menu::employeeMenu(int tempid)
{
	int choice,valid=0;
    while(1)
    {
  
    valid=0;
	system("cls");
	gotoxy(50,5);
	cout<<"EMPLOYEE MENU"<<endl;
	gotoxy(50,8);
	cout<<"Welcome Employee"<<endl;
	gotoxy(40,10);
    cout<<"1. View Profile"<<endl;
   /* gotoxy(40,12);
    cout<<"2. View Salary"<<endl;*/
    gotoxy(40,14);
    cout<<"3. Return to Login"<<endl;
    gotoxy(40,18);
    cout<<"0. EXIT"<<endl;
    gotoxy(40,20);
    cout<<"Enter Your Option :--> ";
    cin>>choice;
    switch(choice)
    {
        case 0:exit(0);
        break;
        case 1: M.searchEmployee(tempid);
        break;
        case 3: login();
        break;
        default:cout<<"\n\n Wrong choice ";
    }
    }
}

void menu::accountantMenu()
{
	int choice,tempid;
    while(1)
    {
	system("cls");
    gotoxy(50,5);
	cout<<"ACCOUNTANT MENU"<<endl;
	gotoxy(40,10);
	cout<<"1. Calculate Salary"<<endl;
	gotoxy(40,12);
	cout<<"2. Print Salary"<<endl;
	gotoxy(40,14);
	cout<<"3. Back to Login"<<endl;
	gotoxy(40,18);
    cout<<"0. EXIT"<<endl;
    gotoxy(40,20);
    cout<<"Enter Your Option :--> ";
    cin>>choice;
    switch(choice)
    {
        case 0:exit(0);
        break;
        case 1:{cout<<"\n\n enter the employee Id to calculate salary ";
                scanf("%d",&tempid);
                scanf("%c", (char *) stdin);
                A.calculateSalary(tempid);
                break;
                }
        case 2:{cout<<"\n\n enter the employee Id to calculate salary ";
                scanf("%d",&tempid);
                scanf("%c", (char *) stdin);
                A.PrintSalary(tempid);
                break;
                }
        case 3:login();
                break;
        default:cout<<"\n\n wrong choice ";
    }

    }
}

int main()
{
    
	menu m;
	m.welcome();

}
