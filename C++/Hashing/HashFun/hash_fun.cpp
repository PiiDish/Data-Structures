#include <iostream>
#include <cstdlib>

using namespace std;
static const int CAPACITY=20;
int hash_fun(int value)
{
	return (value*987783)%CAPACITY;
}
void to_screen(const int source[])
{
	cout<<"{";
	for(int i=0; i<CAPACITY-1; i++)
	{
		cout<<source[i]<<", ";
	}
	cout<<source[CAPACITY]<<"}"<<endl;
}
int main()
{
	int hash_array[CAPACITY];
	hash_array[hash_fun(10)]=10;
	hash_array[hash_fun(37)]=37;
	hash_array[hash_fun(15)]=15;
	hash_array[hash_fun(12)]=12;
	hash_array[hash_fun(342)]=342;
	hash_array[hash_fun(5)]=5;
	hash_array[hash_fun(9)]=9;
	hash_array[hash_fun(7)]=7;
	hash_array[hash_fun(300)]=300;
	hash_array[hash_fun(13)]=13;
	to_screen(hash_array);
	
cout<<hash_fun(13)<<endl;
	
	return EXIT_SUCCESS;
}