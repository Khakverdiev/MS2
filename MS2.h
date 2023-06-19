#pragma once
#include <iostream>
#include <string>
using namespace std;
class MyString
{
private:
    char* str;
    int size;
    int capacity;
public:
    MyString();

    MyString(const char* str);

    MyString(const string str);

    MyString(const MyString& other);

    MyString(MyString&& other);

    MyString& operator=(const MyString& other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }

        size = strlen(other.str);
        this->str = new char[size + 1];

        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[size] = '\0';

        return *this;
    }

    MyString operator+(const MyString& other);

    MyString& operator+=(const MyString& other);

    bool operator==(const MyString& other);

    bool operator!=(const MyString& other);

    bool operator<(const MyString& other);

    bool operator>(const MyString& other);

    bool operator<=(const MyString& other);

    bool operator>=(const MyString& other);

    friend ostream& operator<<(ostream& output, const MyString& other)
    {
        return output << other.str;
    }

    friend istream& operator>>(istream& input, MyString& other)
    {
        other.size = 256;
        other.str = new char[other.size];
        input >> other.str;
        return input;
    }

    char& operator[](int index)
    {
        return this->str[index];
    }

    ~MyString();

    void info();

    int Size();

    void pop();

    void insert(char element);

    void insert(int index, char element);

    void insert(int index, char element, size_t count);

    void insert(int index, const char* substr);

    void insert(int index, const string substr);

    int Capacity();

    void clear();

    void at(int index);

    size_t find(const string substr, char symb);

    size_t rfind(const string substr, char symb);
};