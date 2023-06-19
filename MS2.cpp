#include <iostream>
#include <string>
#include "MS2.h"

int main()
{
	MyString lol = "Hello";
	MyString lol2 = "Mir";

	cout << lol << '\n';
	cout << lol2 << '\n';

	cout << (lol + lol2) << '\n';
	cout << (lol < lol2) << '\n';

	MyString lol3 = "Lol";

	lol3.at(1);
}

