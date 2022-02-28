// Programmer:  Jason Disher
// Student Number: c3185333
// Linked List Class
// Last modified:  19/9/2017

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
        // 	LinkedList(Object& data)
		
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
		//	void add_to_head(Object& data)
		
        // Precondition:	Must have a value type to add to node
        // Postcondition:	LinkedList has a node added to the tail and lenght is incremented
		//	void add_to_tail(Object& data)

		// Precondition:	Must have a value type to add to node and be ponting to a position in LinkedList
        // Postcondition:	LinkedList has a node added to the current position of the pointer and lenght is incremented
		//	void add_to_current(Object& data)
		
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
		
		// Precondition:	Input Object from <<operator
        // Postcondition:	Populates the list with the Object. New node created for each occurence of Object 
		//	void add_string(Object& input_string)
		
		//------------------------------------------------------------------------------------------
        //				Members that query data
		//------------------------------------------------------------------------------------------
		
        // Precondition:	Must be pointing at a vaild node in the LinkedList
        // Postcondition:	Returns the Object stored in the nodes data
		//	Object get_current_data()

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
		
		//Precondition:	Instance of Object 
		//Postcondition:	Returns to cout of the occurences of Object in the LinkedList 
		//	int count_data_occurence(Object& data_value)
		
		//Precondition:	Instance of Object in the LinkedList to be removed
		//Postcondition:	Removes every node that equals Object in the LinkList and decrements length by nodes removed
		//	void remove_entry()
		
		//------------------------------------------------------------------------------------------
		//					Overloaded operators
		//------------------------------------------------------------------------------------------
		
		//Precondition:	LinkedList to be outputed
		//Postcondition:	Overloads << to display the list fit for printing
		//	std::ostream& operator <<(std::ostream& output, LinkedList& target)
		
		//Precondition:	Input stream of Object
		//Postcondition:	Overloads >> to populates the LinkList
		//	std::ostream& operator >>(std::ostream& input, LinkedList& source)
		
		//Precondition:	Two vaild LinkedLists
		//Postcondition:	Returns one LinkedList popuated with both LinkedLists
		//	void operator +=(LinkedList& list1, LinkedList& list2)
		
#ifndef PIIDISH_LINKEDLIST
#define PIIDISH_LINKEDLIST
#include <cstdlib>
#include <iostream>
#include "node.h"

//using namespace piidish_node;
namespace piidish_assignment2
{
    template <typename Object>
		class LinkedList
		{
			public:
						//Typedef
				//typedef std::string Object;
						//Constructor
				LinkedList();
				LinkedList(Object& data);
						//Destructuctor
				~LinkedList();
				void list_clear();// No comments Please fix
						//Member functions
				void insert(Object& data);
				void remove_node();
				void forward();
				void back();
				void move_to_head();
				void move_to_tail();
				void add_data(Object& input_data);
					//copy a list
				void list_copy(LinkedList& source);
				void list_reverse();
						//Query functions
				Object get_current_data() const;
				std::size_t size();
				bool list_search(const Object& data_value);
				int list_search_count(const Object& data_value);
				const node<Object>* get_current_ptr() const;
				node<Object>* get_current_ptr();
				const node<Object>* get_head_ptr() const;
				node<Object>* get_head_ptr();
				//const node* get_tail_ptr_value() const;
				
					//Member overloaded operators
				void operator =(LinkedList& source);
				//template <typename Output>
				//friend std::ostream& operator<< < >(std::ostream&, const LinkedList<Object>&);
			private:
				node<Object>* head_ptr;
				node<Object>* tail_ptr;
				node<Object>* current_ptr;
				std::size_t list_length;

    };
	//----------------------------------------------------------------------------------------------
	//		Overloaded operators
	//----------------------------------------------------------------------------------------------
	template <typename Object>
	std::ostream& operator<< (std::ostream& output, const LinkedList<Object>& target);
	template <typename Object>
	std::istream& operator >>(std::istream& input, LinkedList<Object>& source);
	template <typename Object>
	void operator +=(LinkedList<Object>& list1, LinkedList<Object>& list2);
	template <typename Object>
	LinkedList<Object>* operator +(const LinkedList<Object>& list1, const LinkedList<Object>& list2);
}
#include "LinkedList.template"
#endif
