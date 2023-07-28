//Amanda Manea
//10/30/22 22:58
//front-end for String Class

#include <iostream>
#include "String.cpp"
using namespace std;

int main(int argc, char **argv) {
    char m1[] = "Hello World";
    char m2[] = "Append";
    char m3[] = "INSERT";

    const String str1(m2, sizeof(m2)-1);
    String str2(m1, sizeof(m1)-1);
    String str3(m1, sizeof(m1)-1);
    String str4;
    const String substr(m2, sizeof(m2)-1);
    const String substr2(m3, sizeof(m2)-1);

    cout << endl << "Test of constructors, print, and length" << endl;
    cout << "str1 has length: " << str1.length() << endl;
    str1.print();
    cout << "str2 has length: " << str2.length() << endl;
    str2.print();
    cout << "str3 has length: " << str3.length() << endl;
    str3.print();
    cout << "str4 has length: " << str4.length() << endl;
    str4.print();

    cout << endl << "Test of ==" << endl;
    if(str2 == str1) { cout << "str2 == str1" << endl; } else { cout << "str2 != str1" << endl;}
    if(str2 == str3) { cout << "str2 == str3" << endl; } else { cout << "str2 != str3" << endl;}

    cout << endl << "Test of clear" << endl;
    str2.clear();
    cout << "str2:";
    str2.print();
    cout << "str2 length: " << str2.length() << endl;

    cout << endl << "Test of empty" << endl;
    if(str2.empty()) { cout << "str2 is emplty" << endl; } else { cout << "empty does not work" << endl;}
    if(str3.empty()) { cout << "str3 is emplty" << endl; } else { cout << "str3 is not empty" << endl;}

    cout << endl << "Test of operator=" << endl;
    str4 = str3;
    cout << "str4 length: " << str4.length() << endl;
    cout << "str4: "; 
    str4.print();

    cout << endl << "Test of cascaded operator=" << endl;
    str4 = str2 = str3;
    cout << "str2 length: " << str2.length() << endl;
    cout << "str2: "; 
    str2.print();
    cout << "str4 length: " << str4.length() << endl;
    cout << "str4: "; 
    str4.print();
    
    cout << endl << "Test of cascaded append" << endl;
    str4 = str3 + substr;
    cout << "Length of str4: " << str4.length() << endl;
    cout << "str4: ";
    str4.print();

    cout << endl << "Test of = []" << endl;
    cout << "str4[4] = " << str4[4] << endl;
    cout << "Length of str4: " << str4.length() << endl;
    cout << "str4: ";
    str4.print();

    cout << endl << "Test of [] =" << endl;
    str4[4] = '*';
    cout << "Length of str4: " << str4.length() << endl;
    cout << "str4: ";
    str4.print();


    cout << endl << "Test of +=" << endl;
    str3 += substr2;
    cout << "Length of str3: " << str3.length() << endl;
    cout << "str3: ";
    str3.print();

    cout << endl << "Test of ++Object" << endl;
    ++str3;
    cout << "Length of str3: " << str3.length() << endl;
    cout << "str3: ";
    str3.print();

    cout << endl << "Test of Object++" << endl;
    String s5 = str3++;
    cout << "Length of s5: " << s5.length() << endl;
    cout << "str3: ";
    s5.print();

    return 0;
}
