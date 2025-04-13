#include<iostream>
#include<fstream>
#include<string.h>
class Logging{
	private:
	Logging(){}
	public:
	static Logging& getinstance()
	{
		static Logging L;
		return L;
	}
	Logging& operator=(const Logging& L)=delete;
	Logging(const Logging& L)=delete;
	
	 void AddMessage(std::string text)
	 {
	 	std::ofstream File("messages.txt", std::ios::app);
	 	if(File)
	 	{
	 		File<<text<<std::endl;
		}
		File.close();
	 }
	 
	 void showMessage()
	 {
	 	std::ifstream File("messages.txt");
	 	std::string line;
	 	while(getline(File,line))
	 	{
		std::cout<<line<<std::endl;	
		}
		File.close();
		std::cout<<std::endl;
	 }
};
int main()
{
	Logging& L=Logging::getinstance();
	Logging& L2=Logging::getinstance();
	L.AddMessage("Hello");
	L2.AddMessage("Bruh");
	L.showMessage();
	L2.showMessage();
	
}