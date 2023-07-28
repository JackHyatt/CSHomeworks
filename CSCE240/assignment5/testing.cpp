#include "String.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    char mychar[] = {'A','m','a','z','i','n','g'};
    char *ptr = mychar;
    String myString = String(ptr,7);

    myString.print();

    char mychar2[] = {'z','i','n','g'};
    char *ptr2 = mychar2;
    String myString2 = String(ptr2,4);

    myString2.print();

    std::cout<< myString.find(myString2) <<std::endl;


    myString.print();

    std::cout<<std::endl;
    return 0;
}