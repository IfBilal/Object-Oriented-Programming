#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

class Plant{
	private:
	int number;
	string type;
	public:
	void PlantGet()
	{
		cout<<"Enter type of Plant : ";
		cin>>type;
		cout<<"Enter number of Plants : ";
		cin>>number;
		while(number<=0)
		{
		cout<<"\nInvalid\nEnter number of Plants : ";
		cin>>number;	
		}
	}
	void PlantinfoP()
	{
		cout<<"Plant's type : "<<type<<endl;
		cout<<"Number of Plants : "<<number<<endl;
	}
};
class Garden{
	private:
	int size=0;
	int capacity=1;		
	double length;
	double width;
	Plant* P=new Plant [capacity];
	public:
	
	Garden& operator=(const Garden& other) {
        if (this != &other)
		 {  
            delete[] P;  
            size = other.size;
            capacity = other.capacity;
            length = other.length;
            width = other.width;    
            P = new Plant[capacity];
            for (int i = 0; i < size; i++)
			{
                P[i] = other.P[i];
            }
        }
        return *this;
    }	
	void AddGarden()
	{
		cout<<"Enter length of Garden : ";
		cin>>length;
		while(length<0)
		{
		cout<<"\nInvalid\nEnter length of Garden : ";
		cin>>length;
		}
		cout<<"Enter width of Garden : ";
		cin>>width;
		while(width<0)
		{
		cout<<"\nInvalid\nEnter width of Garden : ";
		cin>>width;
		}
		while(true)
		{
			int ask;
			cout<<"Do You want to add a plant ( 1 for yes or 0 for no ) : ";
			cin>>ask;
			
			while(ask!=1 && ask!=0)
			{
				cout<<"\nInvalid\nDo You want to add a plant ( 1 for yes or 0 for no ) : ";
				cin>>ask;
			}
			if(ask==1)
				{
					if(size==capacity)
					{
					capacity*=2;
					Plant* temp=new Plant [capacity];
					for(int i=0;i<size;i++)
					{
						temp[i]=P[i];
					}
					delete[] P;
					P=temp;
				}
				P[size].PlantGet();
				size++;
			}
		else
		break;
		}
	}
	
	void PrintInfoG()
	{
		cout<<"Length of Garden : "<<length<<endl;
		cout<<"Width of Garden : "<<width<<endl;
		for(int i=0;i<size;i++)
		{
		cout<<"\nPlant no. "<<i+1<<endl;
		P[i].PlantinfoP();
		}
	}
	
	~Garden()
	{
		delete[] P;
	}
};
class System{
	private:
	int size=0;
	int capacity=1;
	Garden* G;
	public:
	System()
	{
	G=new Garden [capacity];	
	}
		
	  System& operator=(const System& other) {
        if (this != &other) 
		{ 
            delete[] G;  
            size = other.size;
            capacity = other.capacity;    
            G = new Garden[capacity];
            for (int i = 0; i < size; i++) {
                G[i] = other.G[i]; 
            }
        }
        return *this;
    }
    
    
	void AddGarden()
	{
		if(size==capacity)
			{
				capacity*=2;
				Garden* temp=new Garden [capacity];
				for(int i=0;i<size;i++)
				{
					temp[i]=G[i];
				}
				delete[] G;
				G=temp;
			}
			G[size].AddGarden();
			size++;
	}
	void Display()
	{
		for(int i=0;i<size;i++)
		{
			cout<<"\n\nGarden : "<<i+1<<endl;
			G[i].PrintInfoG();
		}
	}
	
	~System()
	{
		delete[] G;
	}
};
void Run()
{
	System S;
	while(true)
	{
		int choice;
		cout<<"\n================Garden System===============\n1. Add Garden \n2. Print Gardens Info \n3. Exit\nEnter Your Choice : ";
		cin>>choice;
		while(choice<=0 || choice>3)
		{
			cout<<"\nInvalid\nEnter Your choice again : ";
			cin>>choice;
		}
		if(choice==1)
		{
			S.AddGarden();
		}
		if(choice==2)
		{
		system("CLS");
		S.Display();
		Sleep(4000);	
		}
		if(choice==3)
		{
			system("CLS");
			cout<<"Thanks for using Garden System ";
			break;
			
		}
	}
}
int main()
{
	
	Run();
}
