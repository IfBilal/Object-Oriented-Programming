#include<iostream>
using namespace std;
struct Medical{
	string disease;
	string doctorAssigned;
	int roomNO;
};
struct Billing{
	int totalCost;
	int insuranceApplied;
};
struct Patient{
	string name;
	int age;
	char gender;
	int patientID;
	Medical* medicalInfo = new Medical;
	Billing* billingInfo= new Billing;
	
	Patient& operator=(const Patient& other)
	{
		if(this!=&other)
		{
			delete this->medicalInfo;
        	delete this->billingInfo;
			this->name=other.name;
			this->gender=other.gender;
			this->age=other.age;
			this->patientID=other.patientID;
			this->medicalInfo =new Medical(*(other.medicalInfo));
			this->billingInfo =new Billing(*(other.billingInfo));
		}
		return *this;
	}
	
	
	void addPatient()
	{
		cout<<"Enter name of Patient : " ;
		cin.ignore();
		getline(cin,name);
		cout<<"Enter age of Patient in Years : ";
		cin>>age;
		while(age<=0)
		{
			cout<<"\nInvalid\nEnter age of Patient : ";
			cin>>age;	
		}
		cout<<"Enter Gender (M/F) : ";
		cin>>gender;
		while(gender!='M' && gender!='F')
		{
		cout<<"\nInvalid\nEnter Gender (M/F) : ";
		cin>>gender;	
		}
		cout<<"Enter Patient ID : ";
		cin>>patientID;
		while(patientID<=0)
		{
			cout<<"\nInvalid\nEnter Patient ID : ";
			cin>>patientID;	
		}
		cin.ignore();
		cout<<"Enter Disease : ";
		getline(cin,medicalInfo->disease);
		cout<<"Enter Doctor Assigned : ";
		getline(cin,medicalInfo->doctorAssigned);
		cout<<"Enter Room NO. : ";
		cin>>medicalInfo->roomNO;
		while(medicalInfo->roomNO<0)
		{
		cout<<"\nInvalid\nEnter Room NO. : ";
		cin>>medicalInfo->roomNO;	
		}
		cout<<"Enter Total Cost : ";
		cin>>billingInfo->totalCost;
		while(billingInfo->totalCost<0)
		{
		cout<<"\nInvalid\nEnter Total Cost : ";
		cin>>billingInfo->totalCost;	
		}	
		cout<<"Is Insurance Applied (1 for yes, 0 for no) : ";
		cin>>billingInfo->insuranceApplied;
		while(billingInfo->insuranceApplied!=0 && billingInfo->insuranceApplied!=1)
		{
		cout<<"\nInvalid\nIs Insurance Applied (1 for yes, 0 for no) : ";
		cin>>billingInfo->insuranceApplied;	
		}
	}
~Patient()
{
	delete medicalInfo;
	delete billingInfo;
}
};
void displayPatients(Patient* patientList , int count)
	{
		system("CLS");
		for(int i=0;i<count;i++)
		{		
		cout<<"\n\n\nPatient ID : "<<patientList[i].patientID<<endl;
		cout<<" Name : "<<patientList[i].name<<" , ";
		cout<<" Age : "<<patientList[i].age<<" , ";
		cout<<" Gender : "<<((patientList[i].gender=='M')?" Male":" Female")<<endl;
		cout<<" Disease : "<<patientList[i].medicalInfo->disease<<" , ";
		cout<<" Doctor : "<<patientList[i].medicalInfo->doctorAssigned<<" , ";
		cout<<" Room NO : "<<patientList[i].medicalInfo->roomNO<<endl;
		cout<<" Total Cost : "<<patientList[i].billingInfo->totalCost<<" , ";
		cout<<" Insurance : "<<((patientList[i].billingInfo->insuranceApplied==1)?" Yes":" No");
		}
}
void releaseMemory(Patient* &patientList, int& patientCount)
{
	delete[] patientList;
}
int main()
{
	int size=0;
	int capacity=1;
	Patient* patientList= new Patient[capacity];
while(true)
{
	int choice;
	cout<<"\n\n1. Add Patient\n";
	cout<<"2. Display Patients\n";
	cout<<"3. Exit\n";
	cout<<"Enter your choice : ";
	cin>>choice;
	while(choice<=0 || choice>3)
	{
		cout<<"\nInvalid\n";
		cout<<"1. Add Patient\n";
		cout<<"2. Display Patients\n";
		cout<<"3. Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;	
	}
	if(choice==1)
	{
		if(size==capacity)
		{
			capacity*=2;
			Patient* temp=new Patient[capacity];
			for(int i=0;i<size;i++)
			{
				temp[i]=patientList[i];
			}
			delete[] patientList;
			patientList=temp;
		}
		patientList[size].addPatient();
		size++;
	}
	if(choice==2)
	{
		displayPatients(patientList,size);
	}
	if(choice==3)
	{
		system("CLS");
		cout<<"Thanks for using the program";
		break;
	}
}
releaseMemory(patientList,capacity);
}


