#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/* DECLARATION OF FUNCTIONS TO BE USED */

void emp(void);
void menu(void);
void pat(void);
void inv(void);
void about(void);

/* DECLARATION OF STRUCTURES TO BE USED */

struct address
{
                int hno;
                char street[40];
                char city[40];
                char state[40];
};

struct patient
{
                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender;
                char regn[10];
                struct address a;
                char ph[10];
                char disease[60];
                char doc_name[40];
                char history[200];
                char date[10];
                char treatment[40];
                char med[40];
};

struct staff
{
                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char gender;
                char uid[10];
                struct address b;
                char ph[10];
                double salary;
                char desig[40];
};

/* MAIN MENU FUNCTION */

void menu()
{

                char choice;
                printf("\n\t\t*************************************************");
                printf("\n\t\t  *** WELCOME TO HOSPITAL MANAGEMENT SYSTEM ***");
                printf("\n\t\t*************************************************");
                printf("\n\n\n\n\n\n\n");
                printf("\t\t1.PATIENT");
                printf("\n\t\t2.STAFF");
                printf("\n\t\t3.ABOUT PROGRAM");
                printf("\n\t\t0.EXIT");
                printf("\n\n\tEnter your choice: ");
                fflush(stdin);
                choice=getche();

                switch(choice)
                {
                                case '1':
                                                pat();
                                                break;
                                case '2':
                                                emp();
                                                break;
                                case '3':
                                                about();
                                                break;
                                case '0':
                                                exit(1);
                }
}


/* MAIN FUNCTION*/

int main()
{
                menu();
}

/* MODULE  1 */
/* PATIENT */

void pat()
{
                FILE *fp,*ft;
                char another,ch;
                char reg[20],pname[40];
                int iF=0;
                long int recsize;
                struct patient p;

                fp=fopen("D:\\writefile.txt","rb+");
                if(fp==NULL)
                {
                                fp=fopen("D:\\writefile.txt","wb+");
                                if(fp==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsize=sizeof(p);
                while(1)
                {

/* DISPLAY OF OPTIONS */

                                printf("\n\n\t\t\tPATIENT");
                                printf("\n\t\t1.Enter a New Entry");
                                printf("\n\t\t2.Modify Existing");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.Listing of records");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                fflush(stdin);
                                ch=getche();

                                switch(ch)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                                fseek(fp,0,SEEK_END);
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                w:
                                                                printf("\n\n\nEnter Registration Number: ");
                                                                scanf("%s",reg);
                                                                rewind(fp);

/* CHECKING FOR REGISTRATION NUMBER */

                                                                while(fread(&p,recsize,1,fp)==1)
                                                                {

                                                                                if(strcmp(p.regn,reg)==0)
                                                                                {
                                                                                                iF=1;
printf("\n\t\tTHIS REGISTRATION NUMBER ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto w;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&p,recsize,1,fp)==0)
                                                                {
                                                                                fseek (fp,0,SEEK_END);
                                                                                strcpy(p.regn,reg);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the name of the patient: ");
                                                                                gets(p.name);
                                                                                printf("\nEnter the name of the Guardian: ");
                                                                                gets(p.fname);
                                                                                printf("\nEnter the gender of the patient(M.male or F.female): ");
                                                                                scanf("%c",&p.gender);
                                                                                printf("\nEnter the Blood group of the patient: ");
                                                                                scanf("%s",p.bg);
                                                                                printf("\nEnter the age of the patient: ");
                                                                                scanf("%d",&p.age);
                                                                                printf("\nEnter the address of the patient:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                scanf("%d",&p.a.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",p.a.street);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",p.a.city);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",p.a.state);
                                                                                printf("\nEnter the phone number of the patient: ");
                                                                                scanf("%s",p.ph);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Disease or problem for which he/she wants treatment: ");
                                                                                gets(p.disease);
                                                                                printf("\nEnter the name of the Doctor to which he/she being referred: ");
                                                                                gets(p.doc_name);
                                                                                printf("\nEnter the history, if any, related to treatment of the patient(otherwise write NOT AVAILABLE): ");
                                                                                gets(p.history);

                                                                                fwrite(&p,recsize,1,fp);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Patient(Y/N): ");
                                                                                fflush(stdin);
                                                                                another=getche();
                                                                }
                                                }
                                                                break;

/* MODIFICATION OF EXISTING RECORDS */

                                                case '2':
                                                      {
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                                printf("\nEnter the Registration number of the patient to modify: ");
                                                                                scanf("%s",reg);
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)==0)
                                                                                                {
                                                                                                                fflush(stdin);
                                                                                                                printf("\nEnter the new name of the patient: ");
                                                                                                                gets(p.name);
                                                                                                                printf("\nEnter the new name of the Guardian: ");
                                                                                                                gets(p.fname);
                                                                                                                printf("\nEnter the new Blood group of the patient: ");
                                                                                                                scanf("%s",p.bg);
                                                                                                                printf("\nEnter the new age of the patient: ");
                                                                                                                scanf("%d",&p.age);
                                                                                                                printf("\nEnter the new address of the patient:\n");
                                                                                                                printf("\n\tEnter the house number: ");
                                                                                                                scanf("%d",&p.a.hno);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the street/colony: ");
                                                                                                                scanf("%s",p.a.street);
                                                                                                                printf("\n\tEnter the city: ");
                                                                                                                scanf("%s",p.a.city);
                                                                                                                printf("\n\tEnter the state: ");
                                                                                                                scanf("%s",p.a.state);
                                                                                                                printf("\nEnter the new phone number of the patient: ");
                                                                                                                scanf("%s",p.ph);
                                                                                                                fflush(stdin);
                                                                                                                printf("enter the date of treatment given: ");
                                                                                                                gets(p.date);
                                                                                                                printf("\nEnter the detail of treatment given: ");
                                                                                                                gets(p.treatment);
                                                                                                                printf("\nEnter the medicines prescribed: ");
                                                                                                                gets(p.med);

                                                                                                                fseek(fp,-recsize,SEEK_CUR);
                                                                                                                fwrite(&p,recsize,1,fp);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 another=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY (BY NAME) */

                                                case '3':
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                                printf("\nEnter name to search: ");
                                                                                gets(pname);
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.name,pname)==0)
                                                                                                {
                                                                                                                printf("\nRegistration Number of the Patient : ");
                                                                                                                puts(p.regn);
                                                                                                                printf("\nName of the Patient : ");
                                                                                                                puts(p.name);
                                                                                                                printf("\nName of the Guardian : ");
                                                                                                                puts(p.fname);
                                                                                                                printf("\nAge : %d",p.age);
                                                                                                                printf("\nGender : %c",p.gender);
                                                                                                                printf("\nBlood group: %s",p.bg);
                                                                                                                printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                                                printf("\nDisease : %s",p.disease);
                                                                                                                printf("\nEarlier History : ");
                                                                                                                puts(p.history);
                                                                                                                printf("\nDetails of treatment given and medicine prescribed:");
                                                                                                                printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
                                                                                                                printf("%s\t\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                                                printf("\nName of the Doctor : ");
                                                                                                                puts(p.doc_name);

                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 another=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */

                                                case '4':
                                                                rewind(fp);
                                                                while(fread(&p,recsize,1,fp)==1)
                                                                {
                                                                                printf("\nRegistration Number of the Patient : ");
                                                                                puts(p.regn);
                                                                                printf("\nName of the Patient : ");
                                                                                puts(p.name);
                                                                                printf("\nName of the Guardian : ");
                                                                                puts(p.fname);
                                                                                printf("\nAge : %d",p.age);
                                                                                printf("\nGender : %c",p.gender);
                                                                                printf("\nBlood group: %s",p.bg);
                                                                                printf("\nAddress  : %d,%s,%s,%s",p.a.hno,p.a.street,p.a.city,p.a.state);
                                                                                printf("\nphone number : +91-%s",p.ph);
                                                                                printf("\nDisease : %s",p.disease);
                                                                                printf("\nEarlier History : ");
                                                                                puts(p.history);
                                                                                printf("\nDetails of treatment given and medicine prescribed:");
                                                                                printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                                                                                printf("%s\t %s\t\t %s\n",p.date,p.treatment,p.med);
                                                                                printf("\nName of the Doctor : ");
                                                                                puts(p.doc_name);

                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                                                                getch();
                                                                break;

/* DELETION OF RECORD */

                                case '5':
                                                                another='Y';
                                                                while(another=='Y'||another=='y')
                                                                {
                                                                                printf("\nEnter the Registration number of the Patient to be deleted: ");
                                                                                scanf("%s",reg);
                                                                                ft=fopen("D:\\secondfile.txt","wb+");
                                                                                rewind(fp);
                                                                                while(fread(&p,recsize,1,fp)==1)
                                                                                {
                                                                                                if(strcmp(p.regn,reg)!=0)
                                                                                                fwrite(&p,recsize,1,ft);
                                                                                                else
                                                                                printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fp);
                                                                                fclose(ft);
                                                                                remove("D:\\writefile.txt");
                                                                                rename("D:\\secondfile.txt","D:\\writefile.txt");
                                                                                fp=fopen("D:\\writefile.txt","rb+");

                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                another=getche();
                                                                }
                                                 break;

                case '6':
                                {
                                fclose(fp);
                                menu();
                                }
                                break;
                  }
                }
}
}
/* MODULE  2 */
/* EMPLOYEE */

void emp()
{
                FILE *fs,*fx;
                char more,c;
                char id[20],s_name[40];
                int iF=0;
                long int recsize1;
                struct staff s;

                fs=fopen("D:\\empfile.txt","rb+");
                if(fs==NULL)
                {
                                fs=fopen("D:\\empfile.txt","wb+");
                                if(fs==NULL)
                                {
                                                puts("\nSorry!! Cannot open file");
                                                exit(1);
                                }
                }
                recsize1=sizeof(s);
                while(1)
                {

/* DISPLAY OF OPTIONS */

                                printf("\n\t\t\tEMPLOYEE");
                                printf("\n\t\t1.Add an Entry");
                                printf("\n\t\t2.Modify Existing One");
                                printf("\n\t\t3.Search an Entry");
                                printf("\n\t\t4.Listing of all records");
                                printf("\n\t\t5.Delete an Entry");
                                printf("\n\t\t6.Main Menu");
                                printf("\n\n\t\tEnter your choice here: ");
                                fflush(stdin);
                                c=getche();

                                switch(c)
                                {

/* ADDITION OF RECORDS */

                                                case '1':
                                                        {
                                                                fseek(fs,0,SEEK_END);
                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                u:
                                                                printf("\n\n\nEnter the UID of the Employee: ");
                                                                scanf("%s",id);
                                                                rewind(fs);

/* CHECKING FOR UNIQUE ID */

                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                {

                                                                                if(strcmp(s.uid,id)==0)
                                                                                {
                                                                                                iF=1;
                                                                                printf("\n\t\tTHIS UID ALREADY EXISTS. ENTER ANOTHER ONE");
                                                                                                goto u;
                                                                                }
                                                                }
                                                                if(iF==0||fread(&s,recsize1,1,fs)==0)
                                                                {
                                                                                fseek (fs,0,SEEK_END);
                                                                                strcpy(s.uid,id);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the name of the Employee: ");
                                                                                gets(s.name);
                                                                                printf("\nEnter post of Employee: ");
                                                                                gets(s.fname);
                                                                                printf("\nEnter the gender of the Employee(M.male or F.female): ");
                                                                                scanf("%c",&s.gender);
                                                                                printf("\nEnter the Working time of the Employee: ");
                                                                                scanf("%s",s.bg);
                                                                                printf("\nEnter the age of the Employee: ");
                                                                                scanf("%d",&s.age);
                                                                                printf("\nEnter the Salary of the Employee: ");
                                                                                scanf("%lf",&s.salary);
                                                                                printf("\nEnter the address of the Employee:\n");
                                                                                printf("\n\tEnter the house number: ");
                                                                                scanf("%d",&s.b.hno);
                                                                                fflush(stdin);
                                                                                printf("\n\tEnter the street/colony: ");
                                                                                scanf("%s",s.b.street);
                                                                                printf("\n\tEnter the city: ");
                                                                                scanf("%s",s.b.city);
                                                                                printf("\n\tEnter the state: ");
                                                                                scanf("%s",s.b.state);
                                                                                printf("\nEnter the phone number of the Employee: ");
                                                                                scanf("%s",s.ph);
                                                                                fflush(stdin);
                                                                                printf("\nEnter the Designation: ");
                                                                                gets(s.desig);

                                                                                fwrite(&s,recsize1,1,fs);
                                                                                printf("\n----------------------------------------------------");
                                                                                printf("\nWant to add entry of the another Employee(Y/N): ");
                                                                                fflush(stdin);
                                                                                more=getche();
                                                                }
                                                }
                                                                break;

/* MODIFICATION OF EXISTING RECORDS */
                                                  }
                                                case '2':
                                                    {

                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter the UID of the patient to modify: ");
                                                                                scanf("%s",id);
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.uid,id)==0)
                                                                                                {
                                                                                                                fflush(stdin);
                                                                                                                printf("\nEnter the new name of the Employee: ");
                                                                                                                gets(s.name);
                                                                                                                printf("\nEnter the New Post of the Employee ");
                                                                                                                gets(s.fname);
                                                                                                                printf("\nEnter the new Working hours of the Employee: ");
                                                                                                                scanf("%s",s.bg);
                                                                                                                printf("\nEnter the new age of the Employee: ");
                                                                                                                scanf("%d",&s.age);
                                                                                                                printf("\nEnter the new Salary of the Employee: ");
                                                                                                                scanf("%lf",&s.salary);
                                                                                                                printf("\nEnter the new address of the Employee:\n");
                                                                                                                printf("\n\tEnter the house number: ");
                                                                                                                scanf("%d",&s.b.hno);
                                                                                                                fflush(stdin);
                                                                                                                printf("\n\tEnter the street/colony: ");
                                                                                                                scanf("%s",s.b.street);
                                                                                                                printf("\n\tEnter the city: ");
                                                                                                                scanf("%s",s.b.city);
                                                                                                                printf("\n\tEnter the state: ");
                                                                                                                scanf("%s",s.b.state);
                                                                                                                printf("\nEnter the new phone number of the Employee: ");
                                                                                                                scanf("%s",s.ph);

                                                                                                                fseek(fs,-recsize1,SEEK_CUR);
                                                                                                                fwrite(&s,recsize1,1,fs);
                                                                                                                break;
                                                                                                }
                                                                                }
                                                                                 printf("\n----------------------------------------------------");
                                                                                 printf("\nModify another Record(Y/N): ");
                                                                                 fflush(stdin);
                                                                                 more=getche();
                                                                }
                                                                break;

/*SEARCHING A PARTICULAR ENTRY BY NAME*/                   }

                                                case '3':
                                                	{

                                                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter name to search: ");
                                                                                gets(s_name);
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.name,s_name)==0)
                                                                                                {
                                                                                                                printf("\nUID of the Employee : ");
                                                                                                                puts(s.uid);
                                                                                                                printf("\nName of the Employee : ");
                                                                                                                puts(s.name);
                                                                                                                printf("\nPost of the Employee : ");
                                                                                                                puts(s.fname);
                                                                                                                printf("\nAge : %d",s.age);
                                                                                                                printf("\nSalary: %lf",s.salary);
                                                                                                                printf("\nGender : %c",s.gender);
                                                                                                                printf("\nWorking hours %s",s.bg);
                                                                                                                printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                                                                                                printf("\nphone number : +91-%s",s.ph);
                                                                                                                printf("\nDesignation : %s",s.desig);
                                                                                                }
                                                                                }
                                                                 printf("\n----------------------------------------------------");
                                                                 printf("\nSearch another Entry(Y/N): ");
                                                                 fflush(stdin);
                                                                 more=getche();
                                                                }
                                                                break;

/* LISTING OF ALL RECORDS */                            }

                                                case '4':
                                                       {

                                                                rewind(fs);
                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                {
                                                                                printf("\nUID of the Employee : ");
                                                                                puts(s.uid);
                                                                                printf("\nName of the Employee : ");
                                                                                puts(s.name);
                                                                                printf("\nPost of the Employee : ");
                                                                                puts(s.fname);
                                                                                printf("\nAge : %d",s.age);
                                                                                printf("\nSalary: %lf",s.salary);
                                                                                printf("\nGender : %c",s.gender);
                                                                                printf("\nWorking Hours: %s",s.bg);
                                                                                printf("\nAddress  : %d,%s,%s,%s",s.b.hno,s.b.street,s.b.city,s.b.state);
                                                                                printf("\nphone number : +91-%s",s.ph);
                                                                                printf("\nDesignation : %s",s.desig);

                                                                                printf("\n----------------------------------------------------\n");

                                                                }
                                                                getch();
                                                                break;
                                                    }
/* DELETION OF RECORD */

                                case '5':
                                {
                                more='Y';
                                                                while(more=='Y'||more=='y')
                                                                {
                                                                                printf("\nEnter the UID of the Employee to be deleted: ");
                                                                                scanf("%s",id);
                                                                                fx=fopen("D:\\delfile.txt","wb+");
                                                                                rewind(fs);
                                                                                while(fread(&s,recsize1,1,fs)==1)
                                                                                {
                                                                                                if(strcmp(s.uid,id)!=0)
                                                                                                fwrite(&s,recsize1,1,fx);
                                                                                                else
                                                                                printf("\nThe Record has been Deleted Successfully.");
                                                                                }

                                                                                fclose(fs);
                                                                                fclose(fx);
                                                                                remove("D:\\empfile.txt");
                                                                                rename("D:\\delfile.txt","D:\\empfile.txt");
                                                                                fs=fopen("D:\\empfile.txt","rb+");
                                                                                printf("\nDelete another record?(Y/N): ");
                                                                                fflush(stdin);
                                                                                more=getche();
                                                                }
                                                }

                case '6':
                                {
                                fclose(fs);
                                menu();
                                }
                                break;
                  }
                }
}

void about()
{
                char n;
                printf("This program is developed to maintain records of Patients, Doctors");
                printf("Employees and Inventory items in a hospital.");
                printf("Developed  By:");
                printf("Malaika Khalid 1346-2017");
                printf("Press any key: ");
                n=getche();
                menu();
}



/* END OF THE PROGRAM */
