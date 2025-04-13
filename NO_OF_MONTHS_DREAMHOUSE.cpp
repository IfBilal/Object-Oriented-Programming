#include <iostream>
using namespace std;

class HomeSavings
{
private:
    float annual_salary;
    float portion_saved;
    float total_cost;
    float current_savings;
    int months;

public:
    HomeSavings(float annual_salary, float portion_saved, float total_cost)
    {
        this->annual_salary = annual_salary;
        this->portion_saved = portion_saved;
        this->total_cost = total_cost;
        current_savings = 0;
        months = 0;
    }
    void setAnnualSalary(float S)
    {
        annual_salary = S;
    }
    float getAnnualSalary()
    {
        return annual_salary;
    }
    void setPortionSaved(float P)
    {
        portion_saved = P;
    }
    float gePortionSaved()
    {
        return portion_saved;
    }
    void setTotalCost(float C)
    {
        total_cost = C;
    }
    float getTotalCost()
    {
        return total_cost;
    }
    static double getPortionDownPayment()
    {
        return 0.25;
    }
    void calculateMonthsToSave()
    {
        double DownPayment, monthlySalary;
        DownPayment=total_cost*getPortionDownPayment();
        monthlySalary=annual_salary/12.0;
        while(DownPayment>current_savings)
        {
            current_savings+=(monthlySalary*portion_saved)+(current_savings*0.04)/12.0;
            months++;
        }
       
    }
    friend void MonthsRequired(const HomeSavings &H);

    ~HomeSavings()
    {
        cout << "Home object destroyed";
    }
};
void MonthsRequired(const HomeSavings &H)
{
    cout << "Months required are " << H.months << endl;
}
int main()
{
    double temp1, temp2, temp3;
    cout << "Enter your annual salary : ";
    cin >> temp1;
    cout << "Enter Percent of your salary to save : ";
    cin >> temp2;
    cout << "Enter Cost of your Dream Home  : ";
    cin >> temp3;
    HomeSavings H(temp1, temp2, temp3);
    H.calculateMonthsToSave();
    MonthsRequired(H);
}