#include <iostream>
#include "proj3-MyString.h"

using namespace std;

int main() {
    MyString a("Hello");
    MyString b("World");
    MyString c;
    MyString d("Hello");
    MyString g;

    //test cout and a and b
    cout << a << endl;
    cout << b << endl;

    //a + b test
    c = a + b;
    cout << c << endl;

    //test ==
    if(a == d){
        cout << "works" << endl;
    }
    else{
        cout << "doesnt work" << endl;
    }

    //testing []
    cout << a[2] << endl;

    //test +=
    d += " Worlds";
    cout << d << endl;
    

    c.getline(cin, '\n');
    cout << c << endl;
    


    return 0;
}
