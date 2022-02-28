// Programmer:  Jason Disher
// Student Number: c3185333
// Assignment 1
// Last modified:  3/9/2017

// Members that are externally visible

        // These are member functions
		
		//------------------------------------------------------------------------------------------
        // 					Constructors
		//------------------------------------------------------------------------------------------

        // Precondition	Nil
        // Postcondition:  A new instance of LinkedList is created
        // 	LinkedList()
		
		// Precondition	Nil
        // Postcondition:  A new instance of LinkedList is created with data
        // 	LinkedList(value_type& data)
		
		//------------------------------------------------------------------------------------------
		// 				Destructuctor
		//------------------------------------------------------------------------------------------
		
		// Precondition	Must have an instance to destroy
        // Postcondition:  	The LinkList is Destroyed and released from memory
        // 	~LinkedList()
		
        //------------------------------------------------------------------------------------------
		// 				Members that mutate data
		//------------------------------------------------------------------------------------------

        // Precondition:	Must have a value type to add to node
        // Postcondition:	LinkedList has a node added to the head and lenght is incremented
		//	void add_to_head(value_type& data)
		
        // Precondition:	Must have a value type to add to node
        // Postcondition:	LinkedList has a node added to the tail and lenght is incremented
		//	void add_to_tail(value_type& data)

		// Precondition:	Must have a value type to add to node and be ponting to a position in LinkedList
        // Postcondition:	LinkedList has a node added to the current position of the pointer and lenght is incremented
		//	void add_to_current(value_type& data)
		
		// Precondition:	Must be a valid head node in the LinkedList
        // Postcondition:	Removes head node and makes the next node head node
		//	void remove_from_head()
		
		// Precondition:	Must be a valid tail node in the LinkedList
        // Postcondition:	Removes tail node and makes the previous node tail node
		//	void remove_from_tail()
		
		// Precondition:	Must be a valid node in the LinkedList
        // Postcondition:	Removes current node and makes the previous node tail node if tail node or if head makes next node head node
		//	void remove_current()
		
		// Precondition:	Must be at a vaild node in the LinkedList
        // Postcondition:	Moves the curent pointer position forward in the LinkedList towards the tail
		//	void forward()
		
		// Precondition:	Must be at a vaild node in the LinkedList
        // Postcondition:	Moves the curent pointer position backward in the LinkedList towards the head
		//	void back()
		
		// Precondition:	Must be at a vaild node in the LinkedList
        // Postcondition:	Moves the curent pointer position to the head in the LinkedList 
		//	void move_to_head()
		
		// Precondition:	Must be at a vaild node in the LinkedList
        // Postcondition:	Moves the curent pointer position to the tail in the LinkedList 
		//	void move_to_tail()
		
		// Precondition:	Input value_type from <<operator
        // Postcondition:	Populates the list with the value_type. New node created for each occurence of value_type 
		//	void add_string(value_type& input_string)
		
		//------------------------------------------------------------------------------------------
        //				Members that query data
		//------------------------------------------------------------------------------------------
		
        // Precondition:	Must be pointing at a vaild node in the LinkedList
        // Postcondition:	Returns the value_type stored in the nodes data
		//	value_type get_current_data()

        // Precondition:	Must be a valid LinkList. Required access to standard libary fuctions 
        // Postcondition:	Returns the size of the list. 
		//	std::size_t size()

        //Precondition:	Must be pointing to a valid node in the LinkedList
        //Postcondition:	Returns the address  of the current node being pointed at
		//	const node* get_current_ptr_value() const
		
		//Precondition:	Must be pointing to a valid head node in the LinkedList
        //Postcondition:	Returns the address  of the head node in the LinkedList
		//	const node* get_head_ptr_value() const
		
		//Precondition:	Must be pointing to a valid tail node in the LinkedList
        //Postcondition:	Returns the address  of the tail node in the LinkedList
		//	const node* get_tail_ptr_value() const
		
		//Precondition:	Instance of value_type 
		//Postcondition:	Returns to cout of the occurences of value_type in the LinkedList 
		//	int count_data_occurence(value_type& data_value)
		
		//Precondition:	Instance of value_type in the LinkedList to be removed
		//Postcondition:	Removes every node that equals value_type in the LinkList and decrements length by nodes removed
		//	void remove_entry()
		
		//------------------------------------------------------------------------------------------
		//					Overloaded operators
		//------------------------------------------------------------------------------------------
		
		//Precondition:	LinkedList to be outputed
		//Postcondition:	Overloads << to display the list fit for printing
		//	std::ostream& operator <<(std::ostream& output, LinkedList& target)
		
		//Precondition:	Input stream of value_type
		//Postcondition:	Overloads >> to populates the LinkList
		//	std::ostream& operator >>(std::ostream& input, LinkedList& source)
		
		//Precondition:	Two vaild LinkedLists
		//Postcondition:	Returns one LinkedList popuated with both LinkedLists
		//	void operator +=(LinkedList& list1, LinkedList& list2)
		
#ifndef PIIDISH_LINKEDLIST
#define PIIDISH_LINKEDLIST
#include <cstdlib>
#include <string>
#include "node.h"

namespace piidish_assignment1
{
    class LinkedList
    {
		public:
					//Typedef
			typedef std::string value_type;
					//Constructor
			LinkedList();
			LinkedList(value_type& data);
					//Destructuctor
			~LinkedList();
					//Member functions
			void add_to_head(value_type& data);
			void add_to_tail(value_type& data);
			void add_to_current(value_type& data);
			void remove_from_head();
			void remove_from_tail();
			void remove_current();
			void forward();
			void back();
			void move_to_head();
			void move_to_tail();
			void add_string(value_type& input_string);
					//Query functions
			value_type get_current_data();
			std::size_t size();
			const node* get_current_ptr_value() const;
			const node* get_head_ptr_value() const;
			const node* get_tail_ptr_value() const;
			int count_data_occurence(value_type& data_value);
			
			void concat_lists(LinkedList& listA, LinkedList& listB);//This isnt working yet
			void remove_entry();
			
		private:
			node* head_ptr;
			node* tail_ptr;
			node* current_ptr;
			std::size_t list_length;

    };
	//----------------------------------------------------------------------------------------------
	//		Overloaded operators
	//----------------------------------------------------------------------------------------------
	std::ostream& operator <<(std::ostream& output, LinkedList& target);
	std::istream& operator >>(std::istream& input, LinkedList& source);
	LinkedList* operator +(LinkedList& list1, LinkedList& list2);// Not working yet
	void operator +=(LinkedList& list1, LinkedList& list2);
}

#endif
