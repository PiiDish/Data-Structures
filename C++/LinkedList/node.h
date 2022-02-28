// Programmer: Jason Disher
 // Student Number: c3185333
// Node Class
// Last modified:  26 /9/2017

		//------------------------------------------------------------------------------------------
        // 					Constructors
		//------------------------------------------------------------------------------------------

        // Precondition	Nil
        // Postcondition:  A new instance of node is created
        // 	node()
		
		//------------------------------------------------------------------------------------------
        // 					Destructors
		//------------------------------------------------------------------------------------------

        // Precondition	Instance of node to destroy
        // Postcondition:  The node estroyed and released from memory
        // 	~node()
		
		//------------------------------------------------------------------------------------------
		// 				Members that mutate data
		//------------------------------------------------------------------------------------------

        // Precondition:	Must be a valid instance of node
        // Postcondition:	Sets the data value_type of the node
		//	void set_data(const value_type& new_data)
		
		// Precondition:	Must be a valid instance of node
        // Postcondition:	Sets the pointer to the next node
		//	void set_next(node* next_link)
		
		// Precondition:	Must be a valid instance of node
        // Postcondition:	Sets the pointer to the previous node
		//	void set_next(node* previous_link)
		
		//------------------------------------------------------------------------------------------
        //				Members that query data
		//------------------------------------------------------------------------------------------
		
        // Precondition:	Must be pointing at a vaild node 
        // Postcondition:	Returns the constant value_type stored in the nodes data
		//	value_type get_data() const
	
#ifndef PIIDISH_NODE
#define PIIDISH_NODE
#include <cstdlib>

namespace piidish_assignment2
{
	template <typename Object>
		class node
		{
			public:
					// Typedef
					//typedef std::string Object;
						// Constructor
				node(const Object& init_data = Object(), node* init_next=NULL,
					node* init_previous=NULL);
				
						//Destructor
				~node();
						// Mutators
				void set_data(const Object& new_data);	
				void set_next(node* next_link);				
				void set_previous(node* previous_link);		
					//Constant query functions
				Object get_data() const;			
			
				//In general you should provide TWO versions of member functions
				//that return a pointer to a node.
				//	A const version that returns a const node*
				//	Also a version that returns an ordinary node pointer
				//The compiler will work out which instance to use based on whether
				//the fuction activation was using a constant OR ordinary pointer.
				const node* get_next() const;			
				node* get_next();
				const node* get_previous() const;	
				node* get_previous();	
			private:
				Object data;
				node* next;
				node* previous;
		};
}
#include "node.template"
#endif  