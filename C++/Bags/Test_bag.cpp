//Jason Disher
//Bag Class Test
//Last Modified: 14/12/2017
#include <cassert>
#include <iostream>
#include "bag.h"
using namespace std;
using namespace piidish_bag;
int main()
{
	bag* b = new bag();
	b->insert(24);
	b->insert(19);
	for(int i=0;i<28; i++)
		b->insert(i);
	cout<<b->size()<<endl<<*b<<endl;
	assert(b->erase_one(0)==true);
	cout<<"Removal was successful"<<endl;
	cout<<b->size()<<endl<<*b<<endl;
	assert(b->erase_one(245)==false);
	cout<<"Removal was successful"<<endl;
	cout<<b->size()<<endl<<*b<<endl;
	cout<<b->count(24)<<endl;
	
	bag b1(*bag);
	cout<<b1.size()<<endl<<b1<<endl;
	
	
	
	return EXIT_SUCCESS;
}