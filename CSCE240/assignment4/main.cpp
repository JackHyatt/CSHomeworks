#include "Array.h"
//#include "Array.cpp" 
#include <iostream>

using namespace std;

int main()
{
    int size = 0;

    cout << "Enter size: ";
    cin >> size;

    double *arr = new double[size];

    init(arr,size);
    print(arr,size);

    insert(arr,size,2,764);
    print(arr,size);

    remove(arr,size,1);
    print(arr,size);

    set(arr,size,3,100);
    print(arr,size);

    cout << find(arr,size,100)<< endl;

    cout << get(arr,size,3) << endl;
    
    double *arr2 = new double[size];

    cout << "Are the two arrays equal? " << (equals(arr,size,arr2,size)? "Yes" : "No") << endl;

    clear(arr,size);
    print(arr,size);

    cout << "Are the two arrays equal? " << (equals(arr,size,arr2,size)? "Yes" : "No") << endl;
}