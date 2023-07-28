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
String::String()
{
    this->size = 0;
    this->destructed = true;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param str the char array pointer to use
 * @param size the length of string
 */
String::String(char* str,int size)
{
    this->size = size;
    this->str = new char[size];
    for (int i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }
    this->destructed = false;
}

/**
 * @brief Copy Construct a new String:: String object
 * 
 * @param str the char array pointer to use
 * @param size the length of string
 */
String::String(const String &str)
{
    this->destructed = str.destructed;
    this->size = str.size;
    if(!(this->destructed))
    {
        this->str = new char[size];
        for (int i = 0; i < size; i++)
        {
            this->str[i] = str.str[i];
        }   
    }
}

/**
 * @brief Destroy the String:: String object
 * 
 */
String::~String()
{
    this->dealoc();
}

/**
 * @brief returns the length of the string
 * 
 * @return int legnth of string
 */
int String::length()const
{
    return this->size;
}

/**
 * @brief clears the string by making the array empty and setting size to 0.
 */
void String::clear()
{
    this->dealoc();
    this->size = 0;
}

/**
 * @brief checks to see if the string is empty
 * 
 * @return true if string is empty
 * @return false if string is nonempty
 */
bool String::empty()const
{
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
int String::find(String substr, int startIndex=0)const
{
    for (int i = startIndex; i < this->size; i++)
    {   
        if(i+substr.size>this->size)
            return -1;

        if(this->str[i]==substr.str[0])
        {
            int j = 1;
            while(substr[j]==this->str[i+j] && j<substr.length())
                j++;
            if(j==substr.length())
                return i;
        }
    }
    return -1;
    
}


/**
 * @brief prints the string to standard output
 */
void String::print()const
{
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
void String::append(String rhs)
{
    this->insert(this->size,rhs);
}

/**
 * @brief Inserts a string into the calling string, starting at the index.
 * 
 * @param index the index to start the inserted string at 
 * @param rhs the string to insert
 */
void String::insert(int index, String rhs)
{
    if(index>this->size)
        return;
    int both = this->size+rhs.size;
    char *temp = new char [both];
    for (int i = 0; i < both; i++)
    {
        if(i<index)
            temp[i] = this->str[i];
        else if (i>=index+rhs.size)
            temp[i] = this->str[i-rhs.size];
        else
            temp[i] = rhs.str[i-index];
    }
    this->dealoc();
    this->str = temp;
    this->size = both;
}

/**
 * @brief Sets the calling string to the arguement string
 * 
 * @param rhs the string to set the calling string to
 */
const String String::equal(const String& rhs)
{
    this->dealoc();
    this->size = rhs.size;
    this->destructed = rhs.destructed;
    if(rhs.empty())
        return *this;
    this->str = new char[rhs.size];
    for (int i = 0; i < this->size; i++)
    {
        this->str[i] =  rhs.str[i];
    }
    return *this;
}

/**
 * @brief Sees if the calling string is equal to content wise to the arguement
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool String::equalequal(String rhs)const
{
    if(this->size!=rhs.size)
        return false;
    for (int i = 0; i < this->size; i++)
    {
        if(this->str[i]!=rhs.str[i])
            return false;
    }
    return true;
}

/**
 * @brief The operator for grabbing the character at an index
 * 
 * @param i: The integer index
 * @return char: The character at the index i.
 */
char String::operator[](int i)const
{
    if(this->empty())
    {
        std::cout << "The array was not initialized." << std::endl;
        exit(1);
    }
    if(i >= this->length())
    {
        std::cout << "Out of bounds error." << std::endl;
        exit(1);
    }
    return this->str[i];
}

/**
 * @brief The brackets for used for setting a chacter at an index
 * 
 * @param i: integer index 
 * @return char&: address of the character at index i.
 */
char& String::operator[](int i)
{
    if(this->empty())
    {
        std::cout << "The array was not initialized." << std::endl;
        exit(1);
    }
    if(i >= this->length())
    {
        std::cout << "Out of bounds error." << std::endl;
        exit(1);
    }
    return this->str[i];
}

/**
 * @brief Sets the left hand side to the right hand side
 * 
 * @param rhs: String to set to
 * @return const String: String to set
 */
const String String::operator=(const String& rhs)
{
    return this->equal(rhs);
}

/**
 * @brief Concatenates strings together
 * 
 * @param rhs: The string to add on the end
 * @return const String: The two strings added together
 */
const String String::operator+(const String& rhs) const
{
    int thisSize = this->length();
    int rhsSize = rhs.length();
    int newSize = thisSize + rhsSize;
    char* temp = new char[newSize];
    for(int i=0;i<thisSize;i++)
        temp[i] = (*this)[i];
    for(int i=0;i<rhsSize;i++)
        temp[i+thisSize] = rhs[i];
    String rtn = String(temp,newSize);
    delete [] temp;
    return rtn;
}

/**
 * @brief Adds the desired string to the current string at the end.
 * 
 * @param rhs: the desired string to add
 * @return String: the string of the current and desired added together.
 */
String String::operator+=(const String& rhs)
{
    return *this = *this + rhs;
}

/**
 * @brief Checks if the two strings are equivalent
 * 
 * @param rhs: the string checking against
 * @return true when the two are equivalent
 * @return false when the two are not equivalent
 */
bool String::operator==(const String& rhs)const
{
    return this->equalequal(rhs);
}

/**
 * @brief Pre fix operator
 * 
 * @return String& the adress of the current string incremented
 */
String& String::operator++()
{
    char space[] = " ";
    *this += String(space,1);
    return *this;
}

/**
 * @brief Post fix operator
 * 
 * @return String: the String before it was incremented
 */
String String::operator++(int)
{
    String temp = *this;
    char space[] = " ";
    *this += String(space,1);
    return temp;
}

void String::dealoc()
{
    if (!this->destructed)
        delete [] this->str;
    this->destructed = true;
}