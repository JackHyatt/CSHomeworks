/**
 * @file Array.cpp
 * @author Jack Hyatt
 * @brief Functions to make arrays act more like ArrayLists
 * @date 2022-10-06
 */

#include "Array.h"

/**
 * @brief Inserts a double into the index provided, resizing the array
 * 
 * @param arr: Address of the pointer of the array
 * @param size: Address of the size of the array
 * @param index: Index to insert number
 * @param num: Number to insert
 */
void insert(double *&arr, int &size, int index, double num)
{
    if(index > size)
    {
        std::cout << "You input an index outside of the array length." << std::endl;
        return;
    }
    std::cout << "Inserting " << num << " at the index " << index << "..." << std::endl;
    size++;
    double *temp = new double [size];
    for(int i=0,j=0; i<size;i++,j++)
    {
        if(j!=index)
            temp[j] = arr[i];
        else
        {
            temp[j]=num;
            i--;
            
        }
    }
    delete arr;
    arr = temp;
}

/**
 * @brief Removes the number at the index provided, resizing the array.
 * 
 * @param arr: Address of the pointer of the array
 * @param size: Address of the size of the array
 * @param index: Index to remove 
 */
void remove(double *&arr, int &size, int index)
{
    if(index > size)
    {
        std::cout << "You input an index outside of the bounds of the array." << std::endl;
        return;
    }
    std::cout << "Removing the number at index " << index << "..." << std::endl;
    size--;
    double *temp = new double [size];
    for(int i=0,j=0; j<size;i++,j++)
    {
        if(i!=index)
            temp[j]=arr[i];
        else
            j--;
    }
    delete arr;
    arr = temp;
}



/**
 * @brief Gets the double of array at the given index.
 * 
 * @param arr: Pointer to the array
 * @param size: Size of the array
 * @param index: Index to get
 * @return double
 */
double get(double *arr, int size, int index)
{
    if(index>=size)
    {
        std::cout<< "You input an index outside of the bounds of the array."<<std::endl;
        exit(1);
    }
    std::cout << "Getting the element at index " << index << "..." << std::endl;
    return arr[index];
}

/**
 * @brief Sets the element of the array at the given index to a given double.
 * 
 * @param arr: Pointer of the array
 * @param size: Size of the array
 * @param index: Index of element to change
 * @param num: Number to change element to
 */
void set(double *arr, int size, int index, double num)
{
    if(index>=size)
    {
        std::cout<< "You input an index outside of the bounds of the array."<<std::endl;
        return;
    }
    std::cout << "Setting the element at index " << index << " to " << num << "..." << std::endl;
    arr[index] = num;
}

/**
 * @brief Deallocates the array specified and sets the size of array to 0.
 * 
 * @param arr: Address of the pointer of the array
 * @param size: Address of the size of the array
 */
void clear(double *&arr, int &size)
{
    std::cout << "Deallocating the array..." << std::endl;
    delete arr;
    size = 0;
}

/**
 * @brief Returns the index of the first occurence of the provided number or -1 if it wasnt in the array.
 * 
 * @param arr: Pointer of the array
 * @param size: Size of the array
 * @param num: Number to find in array
 * @return int 
 */
int find(double *arr, int size, double num)
{
    std::cout << "Finding the first occurance of " << num << " in the array..." << std::endl;
    for(int i=0;i<size;i++)
    {
        if(arr[i] == num)
            return i;
    }
    return -1;
}
/**
 * @brief Evaluates whether the two given arrays are the same or not (order does matter).
 * 
 * @param arr1: Pointer of first array
 * @param size1: Size of first array
 * @param arr2: Pointer of second array
 * @param size2: Size of second array
 * @return bool
 */
bool equals(double *arr1, int size1, double *arr2, int size2)
{
    if(size1!=size2)
        return false;
    for(int i=0; i<size1;i++)
    {
        if(arr1[i]!=arr2[i])
            return false;
    }
    return true;
}

/**
 * @brief Populates the elements in the array with standard input
 * 
 * @param arr: Pointer of the array
 * @param size: Size of the array
 */
void init(double *arr, int size)
{
    std::cout<<"Enter in the elements of the array of size " << size << ": ";
    for(int i=0;i<size;i++)
        std::cin>> arr[i];
}

/**
 * @brief Prints the array
 * 
 * @param arr: Pointer of the array
 * @param size: Size of the array
 */
void print(double *arr, int size)
{
    std::cout << "The array is: ";
    for(int i=0; i<size;i++)
        std::cout << i[arr] << " ";
    std::cout << std::endl;
}