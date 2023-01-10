#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<string.h>

using namespace std;

class employee{

        char name[30];
        int id;
        char desig[10];
        int age;
        int ctc;
        int expr;
        float sal;
        float grosssal;
        float hra;
        float da;
        float ta;
        float pf;


        void waitForEnter(){
            cout<<"\n\n\n\t Press the enter key to go back \n\n";
            cin.get();
            cin.get();
        }


        void Employees_List(){
            system("cls");
            FILE *file;
            file= fopen("data.txt", "r");
            cout<<"\n\t      List of Employees is as follows\n";
            cout<<"\n----------------------------------------------";
            cout<<"\n NAME        |     ID     |     designation\n";
            cout<<"----------------------------------------------";
            while(fscanf(file, "%s %d %s %d %d %d %f %f ", name, &id, desig, &age, &ctc, &expr, &sal, &grosssal)!= EOF)
                cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<desig;
            fclose(file);
            waitForEnter();
        }

        void Show_Details(){
            system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF)
                if(checkId==id){
                    cout<<"\n-----------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n------------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n------------------------";
                    cout<<"\ndesignation: "<<desig;
                    cout<<"\n-----------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n-----------------------";
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nexperience: "<<expr;
                    cout<<"\n---------------------";
                    cout<<"\nBasic Salary: "<<sal;
                    cout<<"\n---------------------";
                    cout<<"\nGross Salary: "<<grosssal;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void Edit_Existing(){
            system("cls");
            int checkId;
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newdesig[10];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newdesig;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f\n", name, id, newdesig, age, newCtc, expr, sal, grosssal );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, desig, age, ctc, expr, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);

          remove("data.txt");
          rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void Add_New_Employee(){

        	system("cls");
            FILE *file;
            int newid=101;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF)
            {
            	newid=id+1;
			}
            fclose(file);

            cout<<"\n----------------------------------------";
            cout<<"\n Enter First Name of the Employee: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter designation of the Employee: ";
            cin>>desig;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Age of Employee: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Experience: ";
            cin>>expr;
            cout<<"\n Enter Employee Basic Salary: ";
            cin>>sal;
            cout<<"\n----------------------------------------";

			hra = sal * (0.10);
        	da  = sal * (0.15);
        	ta  = sal * (0.20);
        	pf  = sal * (0.25);
        	grosssal = sal + hra + da + ta + pf;


            char ch;
            cout<<"\n\t\t\t\tEnter 'y' to save above information\n";
            cin>>ch;
            if(ch=='y'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %d %s %d %d %d %f %f \n", name, newid, desig, age, ctc, expr, sal, grosssal );
                fclose(file);
                cout<<"\n\t\t\t\tNew Employee has been added to database\n";
            }
            else
                Add_New_Employee();
            waitForEnter();
        }

        void Delete_Employee_Details(){
            system("cls");
            int checkId;
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\n\t\t\t\tCONFIRMATION\n\n\t\t\t\tEnter 'y' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='y'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF)
                    if(checkId!=id)
                        fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, desig, age, ctc, expr, sal, grosssal );
                fclose(file);
                fclose(tempfile);
               remove("data.txt");
               rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                Delete_Employee_Details();
        }

        void Add_Overtime(){

        	system("cls");
            FILE *file;
            int checkId,over;
			float newgross;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            cout<<"\n\nEnter the overtime (number of hours) : ";
            cin>>over;

            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF)
                if(checkId==id){
		        	newgross = grosssal + over*1000;
                }
            fclose(file);

            cout<<"\n\nOvertime amount "<<over*100<<" added to the Gross Salary\n\n";


            FILE *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF){
                if(checkId==id)
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, desig, age, ctc, expr, sal, newgross );
                else
                    fprintf(tempfile, "%s %d %s %d %d %d %f %f \n", name, id, desig, age, ctc, expr, sal, grosssal );
            }
            fclose(file);
            fclose(tempfile);
           remove("data.txt");
           rename("temp.txt", "data.txt");
            waitForEnter();


		}
		void generate_Payslip(){
			system("cls");
            FILE *file;
            int checkId;
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %d %s %d %d %d %f %f", &name[0], &id , &desig[0], &age, &ctc, &expr, &sal, &grosssal)!=EOF)
                if(checkId==id){
                        int leav;
                cout<<"\n Enter Leaves taken:";
                cin>>leav;
                	cout<<"\n\n-----------------------------";
		            cout<<"\n\tPAYSLIP\n";
		            cout<<"-----------------------------";
		            cout<<"\nLeaves taken\t:\t"<<leav;
		            cout<<"\nBasic salary\t:\t"<<sal;
		            cout<<"\nhra\t\t:\t"<<sal*(.10);
		            cout<<"\nda\t\t:\t"<<sal*(.15);
		            cout<<"\nta\t\t:\t"<<sal*(.20);
		            cout<<"\npf\t\t:\t"<<sal*(.25);
		            cout<<"\nGross Salary\t:\t"<<grosssal-(leav*150);
                }
            fclose(file);
            waitForEnter();
		}


    public:

        void options(){ //menu
        int login(); //login declaration
                login();//login screen
            while(true){
                system("cls");


                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM  <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   6:   To Add Overtime";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   7:   To Generate PaySlip";
                cout<<"\n\t\t\t------------------------------------------------";
				cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";


                int choice;
                cin>>choice;

                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\n Thank You  \n\n ";
                        Sleep(10);
                        return;
                    case 1:
                        Employees_List();
                        break;
                    case 2:
                        Show_Details();
                        break;
                    case 3:
                        Edit_Existing();
                        break;
                    case 4:
                        Add_New_Employee();
                        break;
                    case 5:
                        Delete_Employee_Details();
                        break;
                    case 6:
                        Add_Overtime();
                        break;
                    case 7:
                        generate_Payslip();
                        break;
                    default:
                        cout<<"\n\t\t\t\t Sorry..!! INVALID..ENTER CORRECT OPTION!! \n";
                        Sleep(800);
                        break;
                }

            }
        }

};

int main(){

    employee e;
    e.options();
    return 0;
}

int login(){

   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<8;a++)
	{
		Sleep(500);
		cout << "...";
	}
      cout << "\n\n\n\t\t\t\t\t\tACCESS GRANTED..!! \n\n\n";

      system("PAUSE");
      system("CLS");
   }else{
      cout << "\n\n\t\t\t\t\tWRONG PASSWORD...TRY AGAIN!!\n";
      Sleep(1000);
      system("CLS");


      login();
   }
}
