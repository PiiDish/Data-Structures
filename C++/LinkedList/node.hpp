// Programmer:  Jason Disher
// Student Number: c3185333
// Node Class
// Last modified:  26/9/2017

namespace piidish_assignment2
{
			// Typedef
			//typedef std::string Object;
					// Constructor
			template <typename Object>
			node<Object>::node(const Object& init_data, node<Object>* init_next, node<Object>* init_previous)
				{
					data=init_data;
					next=init_next;
					previous=init_previous;
				}
					//Destructor
			template <typename Object>
			node<Object>::~node()
			{
				next=NULL;
				previous=NULL;
			}
					// Mutators
			template <typename Object>
			void node<Object>::set_data(const Object& new_data)
			{
				data=new_data;
			}
			template <typename Object>
			void node<Object>::set_next(node* next_link)	
			{
				next=next_link;
			}
			template <typename Object>
			void node<Object>::set_previous(node* previous_link)
			{
				previous=previous_link;
			}
					//Constant query functions
			template <typename Object>
			Object node<Object>::get_data() const	
			{
				return data;
			}
			template <typename Object>
			const node<Object>* node<Object>::get_next() const
			{
				return next;
			}
			template <typename Object>
			node<Object>* node<Object>::get_next()
			{
				return next;
			}
			template <typename Object>
			const node<Object>* node<Object>::get_previous() const
			{
				return previous;
			}
			template <typename Object>
			node<Object>* node<Object>::get_previous()
			{
				return previous;
			}

}
