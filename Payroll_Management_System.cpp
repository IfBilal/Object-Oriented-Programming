//M.Bilal tahir
//24i-3166

#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
struct BankDetails{
	long long int account_number;
	string bank_name;
	string ifsc_code;
};
struct Employee{
	int id;
	string name;
	string designation;
	float basic_salary;
	float allowances;
	float deductions;
	float net_salary;
	BankDetails bank_details;
	
	void Add_Emp()
	{
		cout<<"Enter Employee ID : ";
		cin>>id;
		while(id<0)
		{
		cout<<"\nInvalid\nEnter Employee ID : ";
		cin>>id;	
		}
		cout<<"Enter Name : ";
		cin.ignore();
		getline(cin,name);
		cout<<"Enter Designation : ";
		getline(cin,designation);
		cout<<"Enter Basic Salary : ";
		cin>>basic_salary;
		while(basic_salary<0)
		{
		cout<<"\nInvalid\nEnter Basic Salary : ";
		cin>>basic_salary;	
		}
		cout<<"Enter Allowances : ";
		cin>>allowances;
		while(allowances<0)
		{
		cout<<"\nInvalid\nEnter Allowances : ";
		cin>>allowances;	
		}
		cout<<"Enter Deductions : ";
		cin>>deductions;
		while(deductions<0)
		{
		cout<<"\nInvalid\nEnter Deductions : ";
		cin>>deductions;	
		}
		cout<<"\nEnter Bank Account number : ";
		cin>>bank_details.account_number;
		while(bank_details.account_number<0)
		{
		cout<<"\nInvalid\nEnter Bank Account number : ";
		cin>>bank_details.account_number;	
		}
		cin.ignore();
		cout<<"Enter Bank Name : ";
		getline(cin,bank_details.bank_name);
		cout<<"Enter IFSC code : ";
		getline(cin,bank_details.ifsc_code);
		while(bank_details.ifsc_code[0]=='-')
		{
		cout<<"\nInvalid\nEnter IFSC code : ";
		getline(cin,bank_details.ifsc_code);	
		}
		cout<<"\nEmployee Added Successfully \n";
	}
};

void ProcessPayroll(Employee* E,int count)
{
	for(int i=0;i<count;i++)
	{
		if(E[i].net_salary!=(E[i].basic_salary+(E[i].allowances-E[i].deductions)))
		{
		E[i].net_salary=E[i].basic_salary+((E[i].allowances)-(E[i].deductions));
		}
		cout<<"Payroll Processed For "<<E[i].name<<" : ";
		cout<<"Net Salary : "<<E[i].net_salary<<endl;	
	}
}

void UpdateEmpSalary(Employee* E,int count)
{
	int tempID,num;
	bool check=0;
	cout<<"Enter Employee ID to update salary : ";
	cin>>tempID;
	while(tempID<0)
	{
	cout<<"\nInvalid\nEnter Employee ID to update salary : ";
	cin>>tempID;	
	}
	for(int i=0;i<count;i++)
	{
		if(E[i].id==tempID)
		{
		check=1;
		num=i;
		}
	}
	if(check==0)
	{
		cout<<"Employee not found!";
		return;
	}
	cout<<"Enter new Basic Salary : ";
	cin>>E[num].basic_salary;
	while(E[num].basic_salary<0)
	{
	cout<<"\nInvalid\nEnter new Basic Salary : ";
	cin>>E[num].basic_salary;	
	}
	cout<<"Enter new Allowances : ";
	cin>>E[num].allowances;
	while(E[num].allowances<0)
	{
	cout<<"\nInvalid\nEnter new Allowances : ";
	cin>>E[num].allowances;	
	}
	cout<<"Enter new deductions : ";
	cin>>E[num].deductions;
	while(E[num].deductions<0)
	{
	cout<<"\nInvalid\nEnter new deductions : ";
	cin>>E[num].deductions;
	}
}

void ViewDetails(Employee* E,int count)
{
	int tempID,num;
	bool check=0;
	cout<<"Enter Employee ID to view details : ";
	cin>>tempID;
	while(tempID<0)
	{
	cout<<"\nInvalid\nEnter Employee ID to view details : ";
	cin>>tempID;	
	}
		for(int i=0;i<count;i++)
	{
		if(E[i].id==tempID)
		{
		check=1;
		num=i;
		}
	}
	if(check==0)
	{
		cout<<"Employee not found!";
		return;
	}
	cout<<"\n-----------Employee Details----------\n";
	cout<<"\nID : "<<E[num].name<<endl;
	cout<<"Name : "<<E[num].name<<endl;
	cout<<"Designation : "<<E[num].designation<<endl;
	cout<<"Basic Salary : "<<E[num].basic_salary<<endl;
	cout<<"Allowances : "<<E[num].allowances<<endl;
	cout<<"Deductions : "<<E[num].deductions<<endl;
	cout<<"Bank Account : "<<E[num].bank_details.account_number<<endl;
	cout<<"Bank Name : "<<E[num].bank_details.bank_name<<endl;
	cout<<"IFSC Code : "<<E[num].bank_details.ifsc_code<<endl;
}
void UpdateBank(Employee* E,int count)
{
	int tempID,num;
	bool check=0;
	cout<<"Enter Employee ID to Update Bank Details : ";
	cin>>tempID;
	while(tempID<0)
	{
	cout<<"\nInvalid\nEnter Employee ID to Update Bank details : ";
	cin>>tempID;	
	}
		for(int i=0;i<count;i++)
	{
		if(E[i].id==tempID)
		{
		check=1;
		num=i;
		}
	}
	if(check==0)
	{
		cout<<"Employee not found!";
		return;
	}
	cout<<"\nEnter new Bank account_number : ";
	cin>>E[num].bank_details.account_number;
	while(E[num].bank_details.account_number<0)
	{
	cout<<"\nInvalid\nEnter new Bank account_number : ";
	cin>>E[num].bank_details.account_number;		
	}
	cout<<"Enter new Bank Name : ";
	cin.ignore();
	getline(cin,E[num].bank_details.bank_name);
	cout<<"Enter new bank IFSC Code : ";
	getline(cin,E[num].bank_details.ifsc_code);
}
void ViewBank(Employee* E,int count)
{
	int tempID,num;
	bool check=0;
	cout<<"Enter Employee ID to view Bank details : ";
	cin>>tempID;
	while(tempID<0)
	{
	cout<<"\nInvalid\nEnter Employee ID to view Bank details : ";
	cin>>tempID;	
	}
		for(int i=0;i<count;i++)
	{
		if(E[i].id==tempID)
		{
		check=1;
		num=i;
		}
	}
	if(check==0)
	{
		cout<<"Employee not found!";
		return;
	}
	cout<<"\nBank account number : "<<E[num].bank_details.account_number<<endl;
	cout<<"Bank Name : "<<E[num].bank_details.bank_name<<endl;
	cout<<"IFSC Code : "<<E[num].bank_details.ifsc_code<<endl;
}
int main()
{
	int Emp_num=0;
	Employee *E=new Employee[10]; 
while(true)
	{
		Sleep(2000);
		system("CLS");
		int choice;
	cout<<"\n================Payroll Management System====================="<<endl;
	cout<<"1. Add New Employee"<<endl;
	cout<<"2. Process Payroll"<<endl;	
	cout<<"3. Update Employee Salary"<<endl;
	cout<<"4. View Employee Details"<<endl;
	cout<<"5. Delete Employee Record"<<endl;
	cout<<"6. Update Bank Records"<<endl;
	cout<<"7. View Bank Details"<<endl;
	cout<<"Enter your Choice : ";
	cin>>choice;
		while(choice<1 || choice>7)
		{
			cout<<"\nInvalid\nEnter your choice again : ";
			cin>>choice;
		}
	if(choice==1)
	{
			if(Emp_num==10)
			{
				cout<<"Employees Full ";
			}
			else
			{
			E[Emp_num].Add_Emp();
			Emp_num++;
			}
	}
	if(choice==2)
	{
		ProcessPayroll(E,Emp_num);
	}
	if(choice==3)
	{
		UpdateEmpSalary(E,Emp_num);
	}
	if(choice==4)
	{
		ViewDetails(E,Emp_num);
	}
	if(choice==5)
	{
		delete[] E;
		cout<<"Thanks for using the System!";
		break;
	}
	if(choice==6)
	{
		UpdateBank(E,Emp_num);
	}
	if(choice==7)
	{
		ViewBank(E,Emp_num);
	}
	
}
return 0;
}

