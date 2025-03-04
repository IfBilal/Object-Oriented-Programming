	//Sometimes when program stops, wait due to sleep function or Enter again due to presence of cin.ignore()


#include<iostream>
#include<windows.h>
#include<iomanip>
using namespace std;

class Patient{
	public:
	string name;
	string disease;
	int age;
};

class Doctor{
	public:
	int size = 0;
	int capacity=1;
	string name;
	string dept;
	Patient* P;
	int age;
	Doctor()
	{
		P = new Patient[capacity];
	}
    ~Doctor(){
    	delete[] P;
	}

Doctor &operator=(const Doctor &other)
{
    if (this != &other)
    {
        delete[] P; 

        name = other.name;
        dept = other.dept;
        age = other.age;
        size = other.size;
        capacity = other.capacity;

        P = new Patient[capacity]; 
        for (int i = 0; i < size; i++)
        {
            P[i] = other.P[i];
        }
    }
    return *this;
 }
};


class Hospital{
	public:
		int size=0;
int capacity=1;
Doctor* D= new Doctor [capacity];

~Hospital() {
    for (int i = 0; i < size; i++) {
        delete[] D[i].P;  
    }
    delete[] D; 
}

	void add()
	{
		if(size==capacity)
		{
			capacity*=2;
			Doctor* temp = new Doctor[capacity];
			for(int i=0;i<size;i++)
			{
				temp[i]=D[i];
			}
			delete[] D;
			D=temp;
		}
		getinfo();
	}
	void getinfo()
	{
		cin.ignore();
		cout<<"Enter name of Doctor : ";
		getline(cin,D[size].name);
		cout<<"Enter department of doctor : ";
		getline(cin,D[size].dept);
		cout<<"Enter age of doctor : ";
		cin>>D[size].age;
		while(D[size].age<=0)
		{
			cout<<"\nInvalid\nEnter age of doctor : ";
			cin>>D[size].age;
		}
		size++;
	}
	void remove()
	{
		string name,dept;
		bool flag=0;
		cin.ignore();
		cout<<"Enter doctor name to remove : ";
		getline(cin,name);
		cout<<"Enter department of doctor : ";
		getline(cin,dept);
		for(int i=0;i<size;i++)
		{
	
			if(name==D[i].name && dept==D[i].dept)
			{
				delete[] D[i].P; 
				 if (i != size - 1) { 
                D[i].name = D[size - 1].name;
                D[i].dept = D[size - 1].dept;
                D[i].age = D[size - 1].age;
                D[i].size = D[size - 1].size;
                D[i].capacity = D[size - 1].capacity;
                D[i].P = new Patient[D[i].capacity]; 
                for (int j = 0; j < D[i].size; j++) {
                    D[i].P[j] = D[size - 1].P[j];
                }

                delete[] D[size - 1].P;  
            }
            size--; 
            flag = true;
            break;
			}
		}
		if(flag==1)
		cout<<"Doctor removed ";
		else
		cout<<"Doctor not found ";
	}
	
	
		void addP(int i)
	{
		if(D[i].size==D[i].capacity)
		{
			D[i].capacity*=2;
			Patient* temp = new Patient[D[i].capacity];
			for(int j=0;j<D[i].size;j++)
			{
				temp[j]=D[i].P[j];
			}
			delete[] D[i].P;
			D[i].P=temp;
		}
		cin.ignore();
		cout<<"Enter name of patient : ";
		getline(cin,D[i].P[D[i].size].name);
		cout<<"Enter disease of patient : ";
		getline(cin,D[i].P[D[i].size].disease);
		cout<<"Enter age of patient : ";
		cin>>D[i].P[D[i].size].age;
		while(D[i].P[D[i].size].age<=0)
		{
		cout<<"\nInvalid\nEnter age of patient : ";
		cin>>D[i].P[D[i].size].age;	
		}
		D[i].size++;
	}
	
	void getinfoP()
	{
		bool check=0;
		string str,dpo;
		cout<<"Enter name of doctor for patient : ";
		cin.ignore();
		getline(cin,str);
		cout<<"Enter department of doctor for patient : ";
		getline(cin,dpo);
		for(int i=0;i<size;i++)
		{
			if(str==D[i].name)
			{
				if(dpo==D[i].dept)
				{
					check=1;
					addP(i);
					break;
				}
			}
		}
		if(check==0)
		cout<<"\nDoctor not found";
	}
	
	void Display()
	{
		cout<<endl<<endl;
		for(int i=0;i<size;i++)
		{
			cout<<"Doctor name : "<<D[i].name<<endl;
			cout<<"Doctor department : "<<D[i].dept<<endl;
			cout<<"Doctor age : "<<D[i].age<<endl;
			cout<<"Doctor patients : \n\n";
				cout<<setw(25)<<left<<"Patient's name";
				cout<<setw(25)<<left<<"Patient's disease";
				cout<<setw(25)<<left<<"Patient's age";
				cout<<endl;
			for(int j=0;j<D[i].size;j++)
			{
				cout<<setw(25)<<left<<D[i].P[j].name;
				cout<<setw(25)<<left<<D[i].P[j].disease;
				cout<<setw(25)<<left<<D[i].P[j].age<<endl;
			}
			cout<<endl<<endl;
		}
		Sleep(5000);
	}
	void removeP()
	{
		string str,dpo;
		bool flag1=0,flag2=0;
		cin.ignore();
		cout<<"Enter doctor name to remove : ";
		getline(cin,str);
		cout<<"Enter department of doctor : ";
		getline(cin,dpo);
		for(int i=0;i<size;i++)
		{
			if(str==D[i].name && dpo==D[i].dept)
			{
				flag1=1;
				string temp,dis;
				cin.ignore();
				cout<<"Enter name of patient : ";
				getline(cin,temp);
				cout<<"Enter disease of patient : ";
				getline(cin,dis);
				for(int j=0; j < D[i].size;j++)
				{
						if(temp==D[i].P[j].name && dis==D[i].P[j].disease)
					{
						flag2=1;
						if(j!=D[i].size-1)
						{
						D[i].P[j].age=D[i].P[D[i].size-1].age;	
						D[i].P[j].name=D[i].P[D[i].size-1].name;
						D[i].P[j].disease=D[i].P[D[i].size-1].disease;		
						}			
						D[i].size--;	
					}
				}
			}
		}
		if(flag1==0)
	cout<<"\nDoctor not found ";
	if(flag1==1)
	if(flag2==0)
	cout<<"\nPatient not found ";
	else
	cout<<"\nPatient removed ";

	}
	
};


void Run()
{
	Hospital H;
	while(true)
	{
		int choice;
		Sleep(1500);
		system("CLS");
		cout<<"===== HOSPITAL MANAGEMENT SYSTEM =====\n\nOptions:\n1. Add Doctor\n2. Add Patient to Doctor\n3. Remove Doctor\n4. Remove Patient from Doctor\n5. Display Doctors & Patients\n6. Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		while(choice<=0 || choice >6)
		{
			cout<<"Invalid\nEnter your choice again : ";
			cin>>choice;
		}
		if(choice==1)
		{
			H.add();
		}
		if(choice==2)
		{
			H.getinfoP();
		}
		if(choice==3)
		{
			
			H.remove();	
		}
		if(choice==4)
		{
			H.removeP();
		}
		if(choice==5)
		{
			H.Display();
		}
		if(choice==6)
		{
			system("CLS");
			cout<<"Thanks for the using Hospital management system";
			exit(0);
		}
	}
}

int main()
{
Run();
return 0;
}

