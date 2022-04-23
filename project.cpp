#include<iostream.h>
 #include<conio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<fstream.h>
 #include<stdio.h>
 #include<iomanip.h>

 class placement
 {
 char name[20];
 int rn;
 int batch;
 char branch[10];
 char gender;
 char comp[10];
 int package;

 public:
 void getdata();
 void putdata();
 void adddata();
 void displaydata();
 void searchdata();
 void updatedata();
 void deletedata();
 }s;

 fstream obj,obj1;

 void placement::getdata()
 {
 cout<<"\n\nENTER STUDENTS DETAIL....\n";
 cout<<"\nEnter Student Name            :";
 cin.ignore();
 cin.getline(name,20);
 cout<<"\nEnter the University Roll No. :";
 cin>>rn;
 cout<<"\nEnter the Batch               :";
 cin>>batch;
 cout<<"\nEnter the branch              :";
 cin.ignore();
 cin.getline(branch,10);
// cout<<"\nEnter Gender(M/F)             :";
// cin>>gender;
 cout<<"\nEnter the name of company     :";
 cin.ignore();
 cin.getline(comp,10);
 cout<<"\nEnter the Package             :";
 cin>>package;
 }

 void placement::putdata()
 {
/* cout<<"\n\n..........STUDENTS DETAIL..............\n";
 cout<<"\nStudent Name               :"<<name ;
 cout<<"\nUniversity Roll No.        :"<<rn;
 cout<<"\nBranch                     :"<<branch;
 cout<<"\nBatch                      :"<<batch;
 cout<<"\nGender                     :"<<gender;
 cout<<"\nCompany Name               :"<<comp;
 cout<<"\nPackage                    :"<<package;

 cout<<endl;*/


 cout<<setw(10)<<name<<setw(20)<<rn<<setw(10)<<branch<<setw(15)<<batch<<setw(10)<<comp<<setw(15)<<package<<endl;
 }


 void placement::adddata()
 {
 obj.open("new.dat",ios::out|ios::app);
 s.getdata();
 obj.write((char*)&s,sizeof(s));
 obj.close();
 cout<<"\n\n  DATA SUCCESSFULLY SAVED IN FILE......\n";
 }

 void placement::displaydata()
 {
 obj.open("new.dat",ios::in);
 while(obj.read((char*)&s,sizeof(s)))
 {
 s.putdata();
 }
 obj.clear();
 obj.close();
 }

 void placement::searchdata()
 {
 int n,flag=0;
 cout<<"Enter The Roll Number Whose data you want to search:";
 cin>>n ;
 obj.open("new.dat",ios::in);
 while(obj.read((char*)&s,sizeof(s)))
 {
 if(s.rn==n)
 {

 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"RECORD NOT FOUND";
 }
 else
 {
 clrscr();
 s.putdata();
 }
 obj.clear();
 obj.close();
 }

 void placement::updatedata()
 {
 int n,flag=0;
 cout<<"Enter the Roll NO. you want to update ";
 cin>>n;
 obj.open("new.dat",ios::in|ios::out);
 while(obj.read((char*)&s,sizeof(s)))
 {

 if(n==s.rn)
 {
 cout<<"The following Admission No. will be modified with new data:\n";
 s.putdata();
 cout<<"\n\nEnter New Details...\n";
 s.getdata();
 obj.seekg(obj.tellg()-sizeof(s));
 obj.write((char*)&s,sizeof(s));
 flag++;
 }
 }
 obj.clear();
 obj.close();

 if(flag==0)
 {
 cout<<"Incorrect University Roll NO.";
 }
 }

 void placement::deletedata()
 {
 int n,count,flag=0;
 cout<<"Enter the Roll No. to delete:";
 cin>>n;
 obj.open("new.dat",ios::in);
 count=obj.tellp()/sizeof(s);
 obj1.open("temp.dat",ios::out|ios::app);
 obj.seekg(0);
 while(obj.read((char*)&s,sizeof(s)))
 {
 if(s.rn!=n)
 {
 obj1.write((char*)&s,sizeof(s));
 flag++;
 }
 }
 obj.clear();
 obj.close();
 obj1.close();
 if(flag==count)
 {
 cout<<"\n\tNothing to Delete...";
 }
 else
 {
 remove("new.dat");
 rename("temp.dat","new.dat");
 cout<<"\n\t Record has been deleted";
 }
 }









 void main(){
 clrscr();
 int ch;
 do
 {
 clrscr();
 cout<<"\t\t\n PLACEMENT PLACEMENT RECORD \n\n";
 cout<<"\t\tEnter 1 for add data"<<endl;
 cout<<"\t\tEnter 2 for display data "<<endl;
 cout<<"\t\tEnter 3 for search data "<<endl;
 cout<<"\t\tEnter 4 for update data "<<endl;
 cout<<"\t\tEnter 5 for delete data"<<endl;
 cout<<"\t\tEnter 6 for exit"<<endl;
 cout<<"\t\tEnter Your choice:";
 cin>>ch;
 switch(ch)
 {
 case 1:
 clrscr();
 s.adddata();
 getch();
 break;
 case 2:
 clrscr();
 cout<<"\n\n";
 cout<<setw(10)<<"NAME"<<setw(20)<<"ROLL NO."<<setw(10)<<"BRANCH"<<setw(15)<<"BATCH"<<setw(10)<<"COMPANY"<<setw(15)<<"PACKAGE"<<endl;
 s.displaydata();
 getch();
 break;
 case 3:
 clrscr();
 s.searchdata();
 getch();
 break;
 case 4:
 clrscr();
 s.updatedata();
 getch();
 break;
 case 5:
 clrscr();
 s.deletedata();
 getch();
 break;
 case 6:
 clrscr();
 exit(0);
 break;
 default:
 cout<<"Wrong Choice";
 }
 }
 while(ch!=6);



 getch();