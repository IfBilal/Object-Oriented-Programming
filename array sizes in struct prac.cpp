#include <iostream>
using namespace std;

struct Data {
     static const int size = 5;  // ? Compile-time initialization
    int arr[size];  // ? Works because `size` is known at compile time
};

int main() {
    cout << "Size: " << Data::size << endl;  // ? Already initialized
    return 0;
}

