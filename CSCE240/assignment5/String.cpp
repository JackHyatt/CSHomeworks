/**
 * @file String.cpp
 * @author Jack Hyatt
 * @brief The methods for the String Class handmade
 * @date 2022-10-30
 */

#include "String.h"
#include <iostream>

/**
 * @brief Default constructer for String object
 */
String::String(){
    this->size = 0;
    this->str = new char[this->size];
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param str the char array pointer to use
 * @param size the length of string
 */
String::String(char* str,int size){
    this->size = size;
    this->str = new char[size];
    for (int i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }
}

/**
 * @brief Copy Construct a new String:: String object
 * 
 * @param str the char array pointer to use
 * @param size the length of string
 */
String::String(const String &str){
    this->size = str.size;
    this->str = new char[size];
    for (int i = 0; i < size; i++)
    {
        this->str[i] = str.str[i];
    }
}

/**
 * @brief Destroy the String:: String object
 * 
 */
String::~String(){
    if(!this->empty())
        delete [] this->str;
}

/**
 * @brief returns the length of the string
 * 
 * @return int legnth of string
 */
int String::length(){
    return this->size;
}

/**
 * @brief clears the string by making the array empty and setting size to 0.
 */
void String::clear(){
    delete [] this->str;
    this->size = 0;
}

/**
 * @brief checks to see if the string is empty
 * 
 * @return true if string is empty
 * @return false if string is nonempty
 */
bool String::empty(){
    return size==0;
}

/**
 * @brief Finds the first occurance of specified substring in the string,
 * starting at the specified starting index.
 * 
 * @param substr the String to find inside the current string
 * @param startIndex the starting index to look at, defaulted to 0
 * @return int the starting index of the substring.
 */
int String::find(String substr, int startIndex=0){
    for (int i = startIndex; i < this->size; i++)
    {   
        if(i+substr.size>this->size)
            return -1;
        if(this->str[i]!=substr.str[0])
            continue;
        bool flag = true;
        for (int j = 0; j < substr.size; j++)
        {
            if(this->str[i+j]!=substr.str[j])
            {
                flag = false;
                break;
            }
        }
        if(flag)
            return i;
    }
    return -1;
    
}


/**
 * @brief prints the string to standard output
 */
void String::print(){
    for (int i = 0; i < this->size; i++)
    {
        std::cout << this->str[i];
    }
    std::cout << std::endl;
}

/**
 * @brief Append the String arguement to the end of current string.
 * 
 * @param rhs the string the append at the end
 */
void String::append(String rhs){
    this->insert(this->size,rhs);
}

/**
 * @brief Inserts a string into the calling string, starting at the index.
 * 
 * @param index the index to start the inserted string at 
 * @param rhs the string to insert
 */
void String::insert(int index, String rhs){
    if(index>this->size)
        return;
    
    char *temp = new char [this->size + rhs.size];
    
    for (int i = 0; i < this->size + rhs.size; i++)
    {
        if(i<index)
            temp[i] = this->str[i];
        else if (i>=index+rhs.size)
            temp[i] = this->str[i-rhs.size];
        else
            temp[i]=rhs.str[i-index];
    }

    delete [] this->str;
    this->str = temp;
    this->size += rhs.size;
}

/**
 * @brief Sets the calling string to the arguement string
 * 
 * @param rhs the string to set the calling string to
 */
void String::equal(String rhs){
    delete [] this->str;
    this->str = new char[rhs.size];
    this->size = rhs.size;
    for (int i = 0; i < this->size; i++)
    {
        this->str[i] =  rhs.str[i];
    }
}

/**
 * @brief Sees if the calling string is equal to content wise to the arguement
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool String::equalequal(String rhs){
    if(this->size!=rhs.size)
        return false;
    for (int i = 0; i < this->size; i++)
    {
        if(this->str[i]!=rhs.str[i])
            return false;
    }
    return true;
}
