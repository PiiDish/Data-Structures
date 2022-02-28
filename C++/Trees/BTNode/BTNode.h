// Programmer:  Jason Disher
// Student Number: c3185333
// Assignment 3
// Last modified:  30/10/2017

		// Precondition:  NIL
		// Postcondition:  Creates an instance of BTNode and populates it with data
		//	BTNode(const Item& init_data = Item(),BTNode* init_left=NULL, BTNode* init_right=NULL)
		
			//Destructor
		// Precondition:  Be a BTNode
		// Postcondition:  NIL
		//	~BTNode()
		
				//Mutators
		// Precondition:  Be a BTNode
		// Postcondition:  Sets the data of the node
		//	void set_data(const Item&);
		
		// Precondition:  NOT IMPLEMENTED
		// Postcondition:  
		//	void set_parent(BTNode*);
		
		// Precondition:  Be a valid BTNode 
		// Postcondition:  Set the LEFT sub tree pointer address
		//	void set_left(BTNode*);
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Set the RIGHT sub tree pointer address
		//	void set_right(BTNode*);
		
				//Query
		// Precondition:  Be a valid BTNode 
		// Postcondition:  Returns the CONSTANT data containe in BTNode
		//	Item& get_data() const;
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns the data containe in BTNode
		//	Item& get_data();
		
		// Precondition:  NOT IMPLEMENTED
		// Postcondition:  
		//	const BTNode* get_parent() const;
		
		// Precondition:  NOT IMPLEMENTED
		// Postcondition:  
		//	BTNode* get_parent();
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns the CONSTANT LEFT sub tree pointer address
		//	const BTNode* get_left() const;
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns the LEFTT sub tree pointer address
		//	BTNode* get_left();
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns the CONSTANT RIGHT sub tree pointer address
		//	const BTNode* get_right() const;
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns the RIGHT sub tree pointer address
		//	BTNode* get_right();
		
		// Precondition:  Be a valid BTNode
		// Postcondition:  Returns true id BTNode is a leaf node> Returns false if not
		//	bool is_leaf() const;
		
#ifndef PIIDISH_BTNODE
#define PIIDISH_BTNODE
#include <cstdlib>
#include <iostream>

namespace piidish_assignment3
{
	template <typename Item>
	class BTNode
	{
		public:
				//Constructors
			BTNode();
			BTNode(const Item& init_data = Item(),BTNode* init_left=NULL, BTNode* init_right=NULL);
				//Destructor
			~BTNode();
				//Mutators
			void set_data(const Item&);
			void set_parent(BTNode*);
			void set_left(BTNode*);
			void set_right(BTNode*);
				//Query
			Item& get_data() const;
			Item& get_data();
			const BTNode* get_parent() const;
			BTNode* get_parent();
			const BTNode* get_left() const;
			BTNode* get_left();
			const BTNode* get_right() const;
			BTNode* get_right();
			bool is_leaf() const;
		private:
			Item data;
			BTNode* parent;
			BTNode* left;
			BTNode* right;
	};
	//----------------------------------------------------------------------------------------------
	//		Overloaded operators
	//----------------------------------------------------------------------------------------------
	template <typename Item>
	std::ostream& operator <<(std::ostream& output, BTNode<Item>& source);
}
#include "BTNode.template"
#endif