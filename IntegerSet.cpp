#include <iostream>
using namespace std;
class IntegerSet
{
private:
    bool arr[100];

public:
    IntegerSet()
    {
        for (int i = 0; i < 100; i++)
        {
            arr[i] = false;
        }
    }
    void insertElement(int a)
    {
        if (a < 100 && a >= 0)
        {
            arr[a] = true;
        }
    }
    void deleteElement(int a)
    {
        if (a < 100 && a >= 0)
        {
            arr[a] = false;
        }
    }
    void printSet()
    {
        for (int i = 0; i < 100; i++)
        {
            if (arr[i])
                cout << i << " ";
        }
        cout << endl;
    }
    IntegerSet Union(IntegerSet &obj)
    {
        IntegerSet ans;
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] || obj.arr[i])
                ans.arr[i] = true;
        }
        return ans;
    }
    IntegerSet Intersection(IntegerSet &obj)
    {
        IntegerSet ans;
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] && obj.arr[i])
                ans.arr[i] = true;
        }
        return ans;
    }
};
int main()
{
    IntegerSet set1, set2;

    set1.insertElement(2);
    set1.insertElement(5);
    set1.insertElement(70);

    set2.insertElement(5);
    set2.insertElement(70);
    set2.insertElement(99);

    cout << "Set 1: ";
    set1.printSet();

    cout << "Set 2: ";
    set2.printSet();

    IntegerSet unionSet = set1.Union(set2);
    cout << "Union of Set 1 and Set 2: ";
    unionSet.printSet();

    IntegerSet intersectionSet = set1.Intersection(set2);
    cout << "Intersection of Set 1 and Set 2: ";
    intersectionSet.printSet();

    set1.deleteElement(70);
    cout << "Set 1 after deleting 70: ";
    set1.printSet();

    return 0;
}