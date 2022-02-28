// Programmer:  Jason Disher
// Student Number: c3185333
// Assignment 3
// Last modified:  30/10/2017
#include <cstdlib>
#include <iostream>

namespace piidish_assignment3
{
			//Constructor
	template <typename Item>
	BTNode<Item>::BTNode()
	{
		data=NULL;
		//parent=NULL;
		left=NULL;
		right=NULL;
	}
	template <typename Item>
	BTNode<Item>::BTNode(const Item& init_data, BTNode* init_left, BTNode* init_right)
	{
		data=init_data;
		//parent=init_parent;
		left=init_left;
		right=init_right;
	}
	template <typename Item>
	BTNode<Item>::~BTNode()
	{
		//left=NULL;
		//right=NULL;
	}
			//Mutators
	template <typename Item>
	void BTNode<Item>::set_data(const Item& new_data)
	{
		data=new_data;
	}
	template <typename Item>
	void BTNode<Item>::set_parent(BTNode* new_parent)
	{
		parent=new_parent;
	}
	template <typename Item>
	void BTNode<Item>::set_left(BTNode* left_child)
	{
		left=left_child;
	}
	template <typename Item>
	void BTNode<Item>::set_right(BTNode* right_child)
	{
		right=right_child;
	}
			//Query
	template <typename Item>
	Item& BTNode<Item>::get_data() const
	{
		return data;
	}
	template <typename Item>
	Item& BTNode<Item>::get_data()
	{
		return data;
	}
	template <typename Item>
	const BTNode<Item>* BTNode<Item>::get_parent() const
	{
		return parent;
	}
	template <typename Item>
	BTNode<Item>* BTNode<Item>::get_parent()
	{
		return parent;
	}
	template <typename Item>
	const BTNode<Item>* BTNode<Item>::get_left() const
	{
		return left;
	}
	template <typename Item>
	BTNode<Item>* BTNode<Item>::get_left()
	{
		return left;
	}
	template <typename Item>
	const BTNode<Item>* BTNode<Item>::get_right() const
	{
		return right;
	}
	template <typename Item>
	BTNode<Item>* BTNode<Item>::get_right()
	{
		return right;
	}
	template <typename Item>
	bool BTNode<Item>::is_leaf() const
	{
		return (left==NULL) && (right=NULL);
	}
	//----------------------------------------------------------------------------------------------
	//		Overloaded operators
	//----------------------------------------------------------------------------------------------
	template <typename Item>
	std::ostream& operator <<(std::ostream& output, BTNode<Item>& source)
	{
		output<<source.get_data();
	}
}