//Jason Disher
//ABTree Class Test
//Last Modified: 14/12/2017
#include <iostream>
#include <cstdlib>
#include "ABTree.h"

using namespace std;
using namespace piidish_ABTree;
int main()
{
	ABTree<int>* int_tree = new ABTree<int>;
	
	int_tree->add(5);
	int_tree->add(4);
	int_tree->add(3);
	int_tree->add(7);
	int_tree->add(1);
	int_tree->add(2);
	int_tree->add(12);
	int_tree->add(9);
	int_tree->add(8);
	int_tree->add(11);
	
	cout<<"Item 6 is at index "<<int_tree->search(6)<<endl;
	cout<<"Item 5 is at index "<<int_tree->search(5)<<endl;
	cout<<"Item 12 is at index "<<int_tree->search(12)<<endl;
	cout<<"Item 7 is at index "<<int_tree->search(7)<<endl;
	cout<<"Item 11 is at index "<<int_tree->search(11)<<endl;
	cout<<"Item 1 is at index "<<int_tree->search(1)<<endl;
	cout<<"Item 17 is at index "<<int_tree->search(17)<<endl;
	
	cout<<"Size"<<int_tree->size()<<endl;
	
	return EXIT_SUCCESS;
} 