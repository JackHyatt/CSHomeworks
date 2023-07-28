/**
 * @file String.h
 * @author Jack Hyatt
 * @brief Header file for my homemade String class
 * @date 2022-10-30
 */

#ifndef STRING_H
#define STRING_H

class String
{
    public:
        String();
        String(char str[],int siz);
        String(const String &str);
        ~String();
        int length() const;
        void clear();
        bool empty()const;
        int find(String substr, int startIndex)const;
        void print()const;
        void append(String rhs);
        void insert(int i, String rhs);
        const String equal(const String& rhs);
        bool equalequal(String rhs)const;
        char operator[](int) const;//rhs
        char & operator[](int);//lhs and rhs too?
        const String operator=(const String&);
        const String operator+(const String&)const;
        String operator+=(const String&);
        bool operator==(const String&)const;
        String& operator++(); //prefix
        String operator++(int); //postfix
        

    private:
        int size;
        char* str;
        bool destructed;
        void dealoc();
};


#endif // !STRING_H
