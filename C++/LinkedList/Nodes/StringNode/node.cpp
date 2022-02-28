// Programmer:  Jason Disher
// Student Number: c3185333
// Assignment 1
// Last modified:  24/8/2017

#include "node.h"

namespace piidish_assignment1
{
			// Typedef
			typedef std::string value_type;
					// Constructor
			node::node(const value_type& init_data, node* init_next, node* init_previous)
				{
					data=init_data;
					next=init_next;
					previous=init_previous;
				}
					//Destructor
			node::~node()
			{
				next=NULL;
				previous=NULL;
			}
					// Mutators
			void node::set_data(const value_type& new_data)
			{
				data=new_data;
			}
			void node::set_next(node* next_link)	
			{
				next=next_link;
			}
			void node::set_previous(node* previous_link)
			{
				previous=previous_link;
			}
					//Constant query functions
			value_type node::get_data() const	
			{
				return data;
			}
			
			const node* node::get_next() const
			{
				return next;
			}
			node* node::get_next()
			{
				return next;
			}
			const node* node::get_previous() const
			{
				return previous;
			}
			node* node::get_previous()
			{
				return previous;
			}

}
