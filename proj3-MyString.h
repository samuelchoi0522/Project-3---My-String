#ifndef proj3_mystring_h
#define proj3_mystring_h

#include <string>

class MyString {
private:
    int size;
    int capacity;
    char *data;

public:
    // Default Constructor
    MyString();

    // Constructor with an initialization character string
    MyString(const char *str);

    // Destructor
    ~MyString();

    // Copy constructor
    MyString(const MyString &other);

    // Overloaded assignment operator
    MyString& operator=(const MyString &other);

    // Overloaded equivalence relational operator
    bool operator==(const MyString &other) const;

    // Overloaded [] should return a char by reference
    char& operator[](int index);

    // Overloaded += operator, use to concatenate two MyStrings
    void operator+=(const MyString &other);

    // Create a new MyString object that is the concatenation of two MyString objects
    MyString operator+(const MyString &other) const;

    // Reads an entire line from an istream. Lines are terminated with delimit which is newline ‘\n’ by default
    void getline(std::istream &is, char delimit);

    // Return the length of the string
    int length() const;

    // Overloaded insertion operator
    friend std::ostream& operator<<(std::ostream &os, const MyString &ms);

};

#endif
