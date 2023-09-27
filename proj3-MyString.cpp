#include "proj3-MyString.h"
#include <iostream>
#include <ostream>

using namespace std;


MyString::MyString(){
    size = 0;
    capacity = 10;
    data = new char[capacity];
    data[0] = '\0';
}

MyString::MyString(const char *str){
    size = 0;
    while(str[size] != '\0'){
        size++;
    }
    capacity = size + 1;
    
    data = new char[capacity];
    for(int i = 0; i < size; i++){
        data[i] = str[i];
    }
}

MyString::~MyString(){
    delete []data;
}

MyString::MyString(const MyString &other){
    size = other.size;
    capacity = other.capacity;
    
    data = new char[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

MyString& MyString::operator=(const MyString &other) {
    if(this != &other){
        delete []data;
        size = other.size;
        capacity = other.capacity;
        data = new char[capacity];
        for(int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
    return *this;
}

bool MyString::operator==(const MyString &other) const{
    if(size != other.size){
        return false;
    }
    for(int i = 0; i < size; i++){
        if(data[i] != other.data[i]){
            return false;
        }
    }
    return true;
}

char& MyString::operator[](int index){
    return data[index];
}

void MyString::operator+=(const MyString &other){
    int combSize = size + other.size;   //combined size
    char *comb = new char[combSize];
    int temp = 0;
    
    while(combSize >= capacity){        //make capacity bigger
        capacity *= 2;
    }
    
    while(combSize <= capacity){        //make capacity smaller
        capacity /= 2;
    }
    
    for(int i = 0; i < size; i++){
        comb[i] = data[i];
        temp++;
    }
    for(int i = 0; i < other.size; i++){
        comb[temp] = other.data[i];
        temp++;
    }
    size = combSize + 1;                //for null
    
    delete []data;                      //delete to set it to comb
    data = comb;
    data[combSize] = '\0';                  //set last index to null
}

MyString MyString::operator+(const MyString &other) const{
    MyString comb;
    int temp = 0;
    comb.size = size + other.size;
    comb.capacity = comb.size + 1;
    comb.data = new char[comb.capacity];
    
    for(int i = 0; i < size; i++){
        comb[i] = data[i];
        temp++;
    }
    for(int i = 0; i < other.size; i++){
        comb[temp] = other.data[i];
        temp++;
    }
    comb.data[comb.size] = '\0';
    return comb;
}

void MyString::getline(std::istream &is, char delimit) {
    char temp[1000];
    char ch;
    int i = 0;
    while (is.get(ch) && ch != delimit && i < sizeof(temp) - 1) {
        temp[i] = ch;
        i++;
    }
    temp[i] = '\0';
    delete[] data;
    size = i;
    capacity = size + 1; // +1 for the null terminator
    data = new char[capacity];
    for (int j = 0; j <= size; j++) {
        data[j] = temp[j];
    }
}

int MyString::length() const{
    return size;
}

ostream& operator<< (ostream& os, const MyString& ms){
    os.write(ms.data, ms.size);
    return os;
}
