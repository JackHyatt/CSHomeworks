#ifndef HEADERFILE_H
#define HEADERFILE_H

#include<iostream>

void insert(double *&arr, int &size, int index, double num);
void remove(double *&arry, int &size, int index);
double get(double *arr, int size, int index);
void set(double *arr, int size, int index, double num);
void clear(double *&arr, int &size);
int find(double *arr, int size, double num);
bool equals(double *arr1, int size1, double *arr2, int size2);
void init(double *arr, int size);
void print(double *arr, int size);

#endif // !HEADERFILE_H