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
        int length();
        void clear();
        bool empty();
        int find(String substr, int startIndex);
        void print();
        void append(String rhs);
        void insert(int i, String rhs);
        void equal(String rhs);
        bool equalequal(String rhs);
    private:
        int size;
        char* str;
};


#endif // !STRING_H
