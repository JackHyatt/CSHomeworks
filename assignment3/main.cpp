#include <iostream>
#include "./myStatLib.h"
#include "./myStatLib.cpp"

int main() {
    int arrSize = 0;
    std::cout << "Please enter the size of the array this program will look at: ";
    std::cin >> arrSize;

    double arr[arrSize];

    readArray(arr, arrSize);

    std::cout << "The elements of the array are:" << std::endl;
    printArray(arr,arrSize);

    std::cout << "The elements of the array in sorted order are:" << std::endl;
    sort(arr,arrSize);
    printArray(arr,arrSize);

    std::cout << "The max of the array is: " << max(arr,arrSize) << std::endl;
    std::cout << "The min of the array is: " << min(arr,arrSize) << std::endl;
    std::cout << "The mean of the array is: " << mean(arr,arrSize) << std::endl;
    std::cout << "The median of the array is: " << median(arr,arrSize) << std::endl;

    return 0;
}
