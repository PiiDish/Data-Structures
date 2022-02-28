//Jason Disher
//ABTree Class Implementation File
//Last Modified: 14/12/2017
#include <cassert>
#include <cstdlib>

namespace piidish_ABTree
{
		//Create Empty Tree
	template<typename Item>
	ABTree<Item>::ABTree()
	{
		array_based_tree = new Item[40];
		tree_size=0;
	}
		//Create a tree with ONE item
	template<typename Item>
	ABTree<Item>::ABTree(const Item& data)
	{
		array_based_tree = new Item[40];
		array_based_tree[1]=data;
		tree_size=1;
	}
		//Destructor
	template<typename Item>
	ABTree<Item>::~ABTree()
	{
		array_based_tree=NULL;
		tree_size=0;
	}
		//ADD Items
	template<typename Item>
	void ABTree<Item>::add(const Item& data)
	{
			//If ABTree is empty add first element
		if(tree_size==0)
		{
			array_based_tree[1]=data;
			tree_size=1;
			return;
		}
		else
		{
			ABTreeAdd(1, data);
			tree_size++;
		}
	}
		//ADD Items Recursive function
	template<typename Item>
	void ABTree<Item>::ABTreeAdd(int index, const Item& data)
	{
		assert(index<40);
		
			//If RIGHT side of tree
		if(array_based_tree[index]<data)
		{
			if(array_based_tree[index*2+1]==NULL)
			{
				array_based_tree[index*2+1]=data;
				return;
			}
			else
				return ABTreeAdd(index*2+1, data);
		}
			//If LEFT side of tree
		else
		{
			if(array_based_tree[index*2]==NULL)
			{
				array_based_tree[index*2]=data;
				return;
			}
			else
				return ABTreeAdd(index*2, data);
		}
	}
		//Searching
	template<typename Item>
	int ABTree<Item>::search(const Item& data)
	{
		return ABTreeSearch(1, data);
	}
		//Searching Recursive function
	template<typename Item>
	int ABTree<Item>::ABTreeSearch(int index, const Item& data)
	{
		if(index<40)
		{
				//Found Item
			if(array_based_tree[index]==data)
				return index;
			else
			{
					//RIGHT side
				if(array_based_tree[index*2+1]<data)
					return ABTreeSearch(index*2+1, data);
				else
					return ABTreeSearch(index*2, data);
			}
		}
		else
			return -1;		//Item NOT FOUND
	}
		//Get Size
	template<typename Item>
	std::size_t ABTree<Item>::size()
	{
		return tree_size;
	}
}