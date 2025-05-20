//M.Bilal Tahir
//24i-3166
//SE-B

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;

void setColor(int bgColor, int textColor = 7)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}
class Histogram
{
private:
    vector<double> bin;
    vector<double> data;
    int lowerBound; //keep count of data less than lowest bound
    int upperBound;//keep count of data greater than highest bound
    int colorNum;

public:
    Histogram(vector<double> temp)
    {

        bin = temp;
        colorNum = 1;
        lowerBound = 0;
        upperBound = 0;
    }
    Histogram(const Histogram &H)
    {
        bin = H.bin;
        data = H.data;
        lowerBound = H.lowerBound;
        upperBound = H.upperBound;
        colorNum = H.colorNum;
    }
    Histogram &operator=(const Histogram &H)
    {
        bin = H.bin;
        data = H.data;
        lowerBound = H.lowerBound;
        upperBound = H.upperBound;
        colorNum = H.colorNum;
        return *this;
    }
    Histogram(Histogram &&H)//move constructor
    {
        bin = H.bin;
        data = H.data;
        lowerBound = H.lowerBound;
        upperBound = H.upperBound;
        colorNum = H.colorNum;
        H.bin.clear();
        H.data.clear();
        H.colorNum = 1;
        H.lowerBound = 0;
        H.upperBound = 0;
    }
    Histogram &operator=(Histogram &&H) //move assignment operator
    {
        bin = H.bin;
        data = H.data;
        lowerBound = H.lowerBound;
        upperBound = H.upperBound;
        colorNum = H.colorNum;
        H.bin.clear();
        H.data.clear();
        H.colorNum = 1;
        H.lowerBound = 0;
        H.upperBound = 0;
        return *this;
    }
    void clearData() //reset data
    {
        lowerBound = 0;
        upperBound = 0;
        data.clear();
    }
    void AddData(double i)  //add the data to vector 
    {
        if (i < bin[0])
            lowerBound++; 
        else if (i >= bin[bin.size() - 1])
            upperBound++;

        data.push_back(i);
    }
    void displayStatistics()
    {
        cout << "The data is  : ";
        for (int i = 0; i < data.size(); i++)
        {
            cout << data[i] << "  ";
        }
        cout << endl;
    }
    void showGraph()
    {
        for (int i = 0; i < bin.size() - 1; i++)
        {
            cout << bin[i] << "-" << bin[i + 1] << " : ";
            for (int j = 0; j < data.size(); j++)
            {
                setColor(colorNum);
                if (data[j] >= bin[i] && data[j] < bin[i + 1])
                {
                    cout << " ";
                }
            }
            if (i == 0)
            {
                for (int k = 0; k < lowerBound; k++)  //show lower bounded values in first interval 
                {
                    cout << " ";
                }
            }
            if (i == bin.size() - 2) //show upper bounded values in last interval
            {
                for (int k = 0; k < upperBound; k++)
                {
                    cout << " ";
                }
            }
            setColor(0);
            colorNum++; //change color after each interval graph
            if (colorNum > 16) //reset color when it reaches 16 
                colorNum = 1;
            cout << endl;
        }
    }
    ~Histogram()
    {
    }
};
bool checkIncrease(vector<double> temp)  //check if vector bins are valid or not
{
    for (int i = 0; i < temp.size() - 1; i++)
    {
        if (temp[i] > temp[i + 1])
            return false;
    }
    return true;
}
int main()
{
    vector<double> bin;
    while (true)
    {
        int bins;
        cout << "Enter no of bins u want : ";
        cin >> bins;
        if (bins <= 0)
        {
            cout << "Invalid\nEnter again : ";
            cin >> bins;
        }
        for (int i = 0; i < bins + 1; i++)
        {
            double temp;
            cout << "Enter values in bin : ";
            cin >> temp;
            bin.push_back(temp);
        }
        bool check = checkIncrease(bin);
        if (check == 0)
        {
            cout << "Wrong bins \n";
            bin.clear();
            continue;
        }
        else
            break;
    }

    Histogram H(bin);
    int option;
    while (true)
    {
        cout << "\nEnter your option :\n1.Add Data\n2.Clear Data\n3.Show Data\n4.Show Graph\n5.Exit\n";
        cin >> option;
        while (option <= 0 || option > 5)
        {
            cout << "\nInvalid\nEnter your choice again : ";
            cin >> option;
        }
        switch (option)
        {
        case 1:
            double temp;
            cout << "Enter value to be added : ";
            cin >> temp;
            H.AddData(temp);
            break;
        case 2:
            H.clearData();
            break;
        case 3:
            H.displayStatistics();
            break;
        case 4:
            H.showGraph();
            break;
        case 5:
            system("CLS");
            cout << "Thanks for using the system ";
            return 0;
            break;
        }
    }
}