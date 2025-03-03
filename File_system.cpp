#include<iostream>
using namespace std;
class File{
    public:
        string F_name;
        int F_size;
        string extension;
         void getinfo()
   		{
        cout<<"Enter name of file : ";
        cin>>F_name;
        cout<<"Enter size of file in KB : ";
        cin>>F_size;
        cout<<"Enter extension of file : ";
        cin>>extension;
    	}
    };

class Folder{
    private:
        int size=0;
        int capacity=1;
    public:
        string name;
        File* file;
    Folder()
    {
        file=new File[capacity];
    }
    void add()
    {
        if(size==capacity)
            {
                capacity*=2;
                File *temp=new File[capacity];
                for(int i=0;i<size;i++)
                {
                    temp[i]=file[i];
                }
                delete[] file;
                file=temp;
            }
    }
    void call()
    {
    	file[size].getinfo();
    	size++;
	}
	void print()
	{
		cout<<"\nFolder name : "<<name;
		cout<<"\n\nFiles : \n";
		for(int i=0;i<size;i++)
		{
			if(file[i].F_size!=-1)
			{
			cout<<"File name : "<<file[i].F_name+file[i].extension<<endl;
			cout<<"File size (KB) : "<<file[i].F_size<<endl;
			cout<<"Extension : "<<file[i].extension<<endl<<endl<<endl;
			}
		}
	}
	void remove(string temp)
	{
		bool flag;
		for(int i=0;i<size;i++)
		{
			if(temp==file[i].F_name)
			{
				file[i].F_size=-1;
				flag=1;
				
			}
		}
		if(flag==0)
		cout<<"\nFile not found \n";
		else
		cout<<"\nFile successfully removed \n";
	}
	
	~Folder(){
	delete[] file;
	}

};
void Run()
{
    cout<<"-----------------------------Welcome to File System--------------------------------- ";
    Folder f1;
    cout<<"\nEnter Folder name : ";
    cin>>f1.name;
    while(true)
    {
        int ask=0;
        cout<<"\nDo you want to make a file : (1 for yes and 0 for exit )\nPress 5 to remove a file : ";
        cin>>ask;
        if(ask==1)
            {
                f1.add();
                f1.call();
            }
        else if(ask==5)
        {
        	string temp;
        	cout<<"\nEnter file name to remove : ";
        	cin>>temp;
        	f1.remove(temp);
		}
        else 
            break;
    }
    f1.print();


}
int main()
{
    Run();
}
