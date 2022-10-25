//необходимо написать объединение двух кэшей
#include "18.h"

int main()
{
	LFU a(5);

	a.find_and_add("a");
	a.find_and_add("b");
	a.find_and_add("c");

	a.print();
	cout<<endl;


	a.find("a");
	//a.find("b");
    a.find("c");
    a.find("c");
    a.find_and_add("d");



	a.print();
	cout<<endl;


	cout << "The minimum = ";
	cout<<a.get_min();
	cout<<endl;


	a.print_address("a");


	return 0;
}
