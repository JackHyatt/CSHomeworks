/**
 * @file myStatLib.cpp
 * @author Jack Hyatt
 * @brief The functions declarations for myStatLib
 * @date 2022-09-13
 */

#include <iostream>
#include "./myStatLib.h"

/**
 * @brief Returns the min value of a given array
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 * @return double: the min value of array
 */
double min(double arr[], int arrSize) {
    double min = arr[0];
    for(int i=1;i<arrSize;i++) {
        if(arr[i]<min)
            min = arr[i];
    }
    return min;
}

/**
 * @brief Returns the max value of a given array
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 * @return double: the max value of array
 */
double max(double arr[], int arrSize) {
    double max = arr[0];
    for(int i=1;i<arrSize;i++) {
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

/**
 * @brief Returns the mean value of a given array
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 * @return double: the mean value of array
 */
double mean(double arr[], int arrSize) {
    double total = 0;
    for(int i=0;i<arrSize;i++) {
        total += arr[i];
    }
    return total/arrSize;
}

/**
 * @brief Returns the median value of a given array
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 * @return double: the median value of array
 */
double median(double arr[], int arrSize) {
    sort(arr,arrSize);
    if(arrSize%2==0)
        return (arr[arrSize/2]+arr[arrSize/2-1])/2.0;
    else
        return arr[arrSize/2];
}

/**
 * @brief Sorts the given array from least to greatest
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 */
void sort(double arr[], int arrSize) {
    int i = 1;
    while(i<arrSize) {
        int j=i;
        while (j>0 && arr[j-1]>arr[j]) {
            double temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        i++;
    }
}

/**
 * @brief Reads in doubles to populate the array given
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 */
void readArray(double arr[], int arrSize) {
    std::cout << "Time to populate an array." << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cout << "Enter the element in position " << i << ": ";
        std::cin >> arr[i];
    }
}

/**
 * @brief Prints the array given
 * 
 * @param arr Array of double type
 * @param arrSize Size of the array
 */
void printArray(double arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}