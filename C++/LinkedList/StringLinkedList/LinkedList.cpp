// Programmer:  Jason Disher
// Student Number: c3185333
// Assignment 1
// Last modified:  3/9/2017
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include "node.h"
using namespace std;
namespace piidish_assignment1
{
		//Create empty linked list
	LinkedList::LinkedList()
	{
		head_ptr=NULL;
		tail_ptr=NULL;
		current_ptr=NULL;
		list_length=0;
	}
		//Create linked list with data
	LinkedList::LinkedList(value_type& data)
	{
		head_ptr = new node(data);
		tail_ptr=head_ptr;
		current_ptr=head_ptr;
		list_length=1;
	}
		//Destructor
		//Destroys ALL nodes from the heap when Linked List is deleted
	LinkedList::~LinkedList()
	{
		while(head_ptr!=NULL)
			remove_from_head();
		tail_ptr=NULL;
	}
		//Add node to head
	void LinkedList::add_to_head(value_type& data)
	{
			//Add node to empty list
		if(list_length==0)
		{
			head_ptr = new node(data);
			tail_ptr=head_ptr;
			current_ptr=head_ptr;
			list_length=1;
		}
			//Insert new node at head 
		else
		{
				//Create a new node on the heap
			node* head_insert = new node(data);
				//Set the heads previous ptr to the new head and set the next ptr
				// to the node at the current head
			head_ptr->set_previous(head_insert);
			head_insert->set_next(head_ptr);
				//Set head ptr from list to the new node
			head_ptr=head_insert;
			current_ptr=head_ptr;
				//Increment list
			list_length++;
				//Set this node to NULL -- GOOD PRACTICE!!!
			head_insert=NULL;
		}
	}
		//Add a node to the tail
	void LinkedList::add_to_tail(value_type& data)
	{
			//Add node to empty list
		if(list_length==0)
		{
			head_ptr = new node(data);
			tail_ptr=head_ptr;
			current_ptr=tail_ptr;
			list_length=1;
		}
			//Insert new node at head 
		else
		{
				//Create a new node on the heap
			node* tail_insert = new node(data);
				//Set the tails previous ptr to the new tail and set the next ptr
				// to the node at the current tail
			tail_ptr->set_next(tail_insert);
			tail_insert->set_previous(tail_ptr);
				//Set tail ptr from list to the new node
			tail_ptr=tail_insert;
			current_ptr=tail_ptr;
				//Increment list
			list_length++;
				//Set this node to NULL -- GOOD PRACTICE!!!
			tail_insert=NULL;
			//current_ptr=tail_ptr;
		}
	}
		//Add a new node at current
	void LinkedList::add_to_current(value_type& data)
	{
			//Create a new node on the heap
		node* current_insert = new node(data);
		if(current_ptr==head_ptr)
			//head_ptr=current_insert;
			//Get and Set next and previous ptrs
		current_ptr->get_next()->set_previous(current_insert);
		current_insert->set_previous(current_ptr);
		current_insert->set_next(current_ptr->get_next());
		current_ptr->set_next(current_insert);
			//Move ptr to currents previous
		current_ptr=current_insert;
		//current_ptr->set_next(current_insert);
			//Increment list
		list_length++;	
	}
		//Remove node from the head
	void LinkedList::remove_from_head()
	{
			//Do nothing if list is empty
		if(list_length==0)
			return;
			//Remove final node if only one node in the list
		else if(list_length==1)
		{
			delete head_ptr;
			head_ptr=NULL;
			tail_ptr=NULL;
			current_ptr=NULL;
			list_length--;
			return;
		}
		else
		{
				//Make temp head ptr and set it as the CURRENT head ptr
			node* temp_head_ptr = head_ptr;
				//Rearrange head ptr to the list
			head_ptr=temp_head_ptr->get_next();
				//Destroy temp_head_ptr -- MEMORY MANAGEMENT
			delete temp_head_ptr;
				//Decrement list length
			list_length--;
				//Set this node to NULL -- Even though its destroyed
			temp_head_ptr=NULL;
		}
	}
		//Remove from tail
	void LinkedList::remove_from_tail()
	{
			//Do nothing if list is empty
		if(list_length==0)
			return;
			//Remove final node if only one node in the list
		else if(list_length==1)
		{
			delete head_ptr;
			head_ptr=NULL;
			tail_ptr=NULL;
			current_ptr=NULL;
			list_length--;
			return;
		}
		else
		{
				//Make temp head ptr and set it as the CURRENT head ptr
			node* temp_tail_ptr = tail_ptr;
				//Rearrange head ptr to the list
			tail_ptr=temp_tail_ptr->get_previous();
				//Destroy temp_head_ptr -- MEMORY MANAGEMENT
			delete temp_tail_ptr;
				//Decrement list length
			list_length--;
				//Set this node to NULL -- Even though its destroyed
			temp_tail_ptr=NULL;
		}
	}
		//Destroy current
	void LinkedList::remove_current()//node& temp_current_ptr)
	{
		node* temp_current_ptr = current_ptr;
		if(current_ptr==tail_ptr)
			tail_ptr=current_ptr->get_previous();
		if(current_ptr==head_ptr)
		{
			head_ptr=current_ptr->get_next();
			current_ptr=head_ptr;
			current_ptr->set_previous(NULL);
		}
		else
		{
			current_ptr=temp_current_ptr->get_previous();
			current_ptr->set_next(temp_current_ptr->get_next());
		}
		delete temp_current_ptr;
		list_length--;
		temp_current_ptr=NULL;
		//Must do something about if at head of LIST!!!!!!!!!!!!
	}
		//Move forward in the list
	void LinkedList::forward()
	{
			//Get next node address
		current_ptr=current_ptr->get_next();
	}
		//Move back in the list
	void LinkedList::back()
	{
			//Get previous node address
		current_ptr=current_ptr->get_previous();
	}
		//Move to the head of the list
	void LinkedList::move_to_head()
	{
		current_ptr=head_ptr;
	}
		//Move to the tail of the list
	void LinkedList::move_to_tail()
	{
		current_ptr=tail_ptr;
	}
		//Add string to list
	void LinkedList::add_string(value_type& input_string)
	{
		value_type temp;
		char space = ' ';

		for(size_t p=0, q=0; p!=input_string.npos; p=q)
		{
			temp=input_string.substr(p+(p!=0), (q=input_string.find(space, p+1))-p-(p!=0));
			this->add_to_tail(temp);
		}
	}
		//Get data from current node
	LinkedList::value_type LinkedList::get_current_data()
	{
		return current_ptr->get_data();
	}
		//Get size of the list
	std::size_t LinkedList::size()
	{
		return list_length;
	}
		//Get current ptr
	const node* LinkedList::get_current_ptr_value() const
	{
		return current_ptr;
	}
		//Get head ptr
	const node* LinkedList::get_head_ptr_value() const
	{
		return head_ptr;
	}
		//Get tail ptr
	const node* LinkedList::get_tail_ptr_value() const
	{
		return tail_ptr;
	}
		//Serearch and return the count of data occurences
	int LinkedList::count_data_occurence(value_type& data_value)
	{
		int count=0;
		
		for(this->move_to_head(); this->get_current_ptr_value()!=NULL; this->forward())
		{
			if(this->get_current_data()==data_value)
				count++;
		}
		return count;
	}
	void LinkedList::concat_lists(LinkedList& listA, LinkedList& listB)
	{
		LinkedList concat_list;// = new LinkedList();
		value_type data_temp;
		concat_list=listA;
		while(listB.get_current_ptr_value()!=NULL)//; list2.forward())
		{
			data_temp=listB.get_current_data();
			concat_list.add_to_tail(data_temp);
			listB.forward();
		}
	}
	void LinkedList::remove_entry()
	{
		value_type remove_value;
		cin>>remove_value;
		for(this->move_to_head();this->get_current_ptr_value()!=NULL; this->forward())
		{
			if(remove_value==this->get_current_data())
				this->remove_current();
		}	
	}
	//----------------------------------------------------------------------------------------------
	//	Overloaded operations
	//----------------------------------------------------------------------------------------------
	std::ostream& operator <<(std::ostream& output, LinkedList& target)
	{
		target.move_to_head();
		for(int i=0; i<int(target.size()); i++)
		{
			output<<target.get_current_data()<<" ";
			target.forward();
		}
		return output;
	}
	std::istream& operator >>(std::istream& input, LinkedList& source)
	{
		LinkedList::value_type temp;
		std::getline(input, temp);
		source.add_string(temp);
		return input;
	}
		//Overload + operator
	LinkedList* operator +(LinkedList& list1, LinkedList& list2)
	{
		LinkedList* temp_linklist = new LinkedList();
		//temp_linklist.concat_lists(list1, list2);
		LinkedList::value_type data_temp;
		//temp_linklist=list1;
		//temp_linklist->concat_lists(list1, list2);
		while(list1.get_current_ptr_value()!=NULL)
		{
			data_temp=list1.get_current_data();
			temp_linklist->add_to_tail(data_temp);
			list1.forward();
		}
		
		return temp_linklist;
	}
	void operator +=(LinkedList& list1, LinkedList& list2)
	{
		//list1=list1+list2;
		LinkedList::value_type temp;
		for(list2.move_to_head(); list2.get_current_ptr_value()!=NULL; list2.forward())
		{
			temp=list2.get_current_data();
			list1.add_to_tail(temp);
		}
	}
}