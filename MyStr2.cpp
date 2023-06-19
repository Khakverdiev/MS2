#include "MS2.h"

MyString::MyString()
{
    str = nullptr;
    size = 0;
    capacity = 15;
}

MyString::MyString(const char* str)
{
    
    size = strlen(str);
    this->str = new char[size + 1];
    
    for (size_t i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }
    
    this->str[size] = '\0';

}

MyString::MyString(const string str)
{
    size = str.size();
    this->str = new char[size + 1];

    for (size_t i = 0; i < size; i++)
    {
        this->str[i] = str[i];
    }

    this->str[size] = '\0';
}

MyString::MyString(const MyString& other)
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
}

bool MyString::operator==(const MyString& other)
{
    if (this->size != other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] != other.str[i])
        {
            return false;
        }
    }

    return true;
}

bool MyString::operator!=(const MyString& other)
{
    if (this->size == other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] == other.str[i])
        {
            return false;
        }
    }

    return true;
}

bool MyString::operator<(const MyString& other)
{
    if (this->size > other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] > other.str[i])
        {
            return false;
        }
    }

    return true;
}

bool MyString::operator>(const MyString& other)
{
    if (this->size < other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] < other.str[i])
        {
            return false;
        }
    }

    return true;
}

bool MyString::operator<=(const MyString& other)
{
    if (this->size >= other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] >= other.str[i])
        {
            return false;
        }
    }

    return true;
}

bool MyString::operator>=(const MyString& other)
{
    if (this->size <= other.size)
    {
        return false;
    }

    for (size_t i = 0; i < this->size; i++)
    {
        if (this->str[i] <= other.str[i])
        {
            return false;
        }
    }

    return true;
}

MyString::MyString(MyString&& other)
{
    this->size = other.size;
    this->str = other.str;

    other.str = nullptr;
}

MyString::~MyString()
{
    delete[] this->str;
}

void MyString::info()
{
    cout << str;
}

int MyString::Capacity()
{
    if (size > capacity)
    {
      size += size;
      int* new_str = new int[capacity + 16] {};

      for (int i = 0; i < size; ++i)
      {
          size = new_str[i];
      }

      capacity += 16;
      delete[] new_str;
    }

    return capacity;
}

MyString MyString::operator+(const MyString& other)
{
    MyString newstr;

    int size2 = strlen(this->str);
    int size3 = strlen(other.str);

    newstr.size = size2 + size3;

    newstr.str = new char[size2 + size3 + 1];

    size_t i = 0;

    for (; i < size2; i++)
    {
        newstr.str[i] = this->str[i];
    }

    for (size_t j = 0; j < size3; j++, i++)
    {
        newstr.str[i] = other.str[j];
    }

    newstr.str[size2 + size3] = '\0';

    return newstr;
}

MyString& MyString::operator+=(const MyString& other)
{
    size += other.size;
    return *this;
}

int MyString::Size()
{
    return size;
}

void MyString::insert(char element)
{
 
    char* new_arr = new char[size + 2];

    for (size_t i = 0; i < size; ++i)
    {
        new_arr[i] = str[i];
    }

    new_arr[size] = element;
    
    new_arr[size + 1] = '\0';

    delete[] str;

    str = new_arr;

    ++size;
}

void MyString::insert(int index, char element)
{
    char* new_arr = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = str[i];
    }

    new_arr[index] = element;
    
    for (size_t i = index; i < size; i++)
    {
        str[i] = new_arr[i];
    }

    new_arr[size] = '\0';

    delete[] str;

    str = new_arr;

    ++size;
}

void MyString::insert(int index, char element, size_t count)
{
    char* new_arr = new char[size + 2];

    for (size_t i = 0; i < count; ++i)
    {
        if (i == index)
        {
            str[i] = new_arr[i + 1];
        }
        new_arr[index++] = element;
    }

    new_arr[count++] = '\0';

    delete[] str;

    str = new_arr;

    ++size;
}

void MyString::insert(int index, const char* substr)
{
    char* new_arr = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = str[i];
    }

    for (size_t i = 0; i < size; i++)
    {
        new_arr[index] = substr[i];
    }

    for (size_t i = index; i < size; i++)
    {
        str[i] = new_arr[i];
    }

    new_arr[size] = '\0';

    delete[] str;

    str = new_arr;

    ++size;
}

void MyString::insert(int index, const string substr)
{
    size = substr.size();
    char* new_arr = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = str[i];
    }
    
    for (size_t i = 0; i < size; i++)
    {
        new_arr[i] = substr[i];
    }

    for (size_t i = index; i < size; i++)
    {
        str[i] = new_arr[i];
    }

    new_arr[size] = '\0';

    delete[] str;

    str = new_arr;

    ++size;
}

void MyString::pop()
{
    char* arr = new char[size + 1]{};
    --size;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = str[i];
    }
    arr[size + 1] = '\0';
    delete[] str;
    str = arr;
}

void MyString::clear()
{
    size = 0;
}

void MyString::at(int index)
{
    size = strlen(str);

    for (size_t i = 0; i < size; i++)
    {
        if (i == index) 
        {
            cout << str[index];
        }
    }
}

size_t MyString::find(const string substr, char symb)
{
    size_t index{};

    for (size_t i = 0; substr[i] != '\0'; i++)
    {
        if (substr[i] == symb)
        {
            index = i;
        }
    }
    return index;
}

size_t MyString::rfind(const string substr, char symb)
{
    size_t index = -1;

    for (size_t i = 0; substr[i] != '\0'; i++)
    {
        if (substr[i] == symb)
        {
            index = i;
        }
    }
    return index;
}