// Programmer:  Jason Disher
// Student Number: c3185333
// LinkedList Class
// Last modified:  26/9/2017

//using namespace piidish_node;
namespace piidish_assignment2
{
		//Create empty linked list
	template <typename Object>
	LinkedList<Object>::LinkedList()
	{
		head_ptr=NULL;
		tail_ptr=NULL;
		current_ptr=NULL;
		list_length=0;
	}
		//Create linked list with data
	template <typename Object>
	LinkedList<Object>::LinkedList(Object& data)
	{
		head_ptr = new node<Object>(data);
		tail_ptr=head_ptr;
		current_ptr=head_ptr;
		list_length=1;
	}
		//Destructor
		//Destroys ALL nodes from the heap when Linked List is deleted
	template <typename Object>
	LinkedList<Object>::~LinkedList()
	{
		list_clear();
		head_ptr=NULL;
		tail_ptr=NULL;
		current_ptr=NULL;
	}
		//Clear empty list
	template <typename Object>
	void LinkedList<Object>::list_clear()
	{
		current_ptr=head_ptr;	//I have no pre or post condition comments please fix
		while(head_ptr!=NULL)
			remove_node();
	}
		//Add a new node
	template <typename Object>
	void LinkedList<Object>::insert(Object& data)
	{	
			//Add node to empty list
		if(list_length==0)
		{
			head_ptr= new node<Object>(data);
			tail_ptr=head_ptr;
			current_ptr=head_ptr;
			list_length=1;
		}
		else if(list_length==1)
		{
				//Create a new node on the heap
			node<Object>* current_insert = new node<Object>(data);
			tail_ptr->set_next(current_insert);
			current_insert->set_previous(tail_ptr);
				//Set tail ptr from list to the new node
			current_ptr=current_insert;
			tail_ptr=current_ptr;
				//Increment list
			list_length++;
				//Set this node to NULL -- GOOD PRACTICE!!!
			current_insert=NULL;
		}
		else
		{
			//Create a new node on the heap
			node<Object>* current_insert = new node<Object>(data);
				//If current_ptr is tail_ptr
			if(current_ptr!=tail_ptr)
					//Setting current next node previous to new insert
				current_ptr->get_next()->set_previous(current_insert);	
			if(current_ptr==tail_ptr)
				tail_ptr=current_insert;
				//Setting insert previous to current ptr
			current_insert->set_previous(current_ptr);
				//Setting insert next from current next
			current_insert->set_next(current_ptr->get_next());	
				//Setting current ptr next to insert
			current_ptr->set_next(current_insert);					
				//Move ptr to currents previous
			current_ptr=current_insert;
				//Increment list
			list_length++;
		}
	}
		//Destroy current
	template <typename Object>
	void LinkedList<Object>::remove_node()
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
		if(current_ptr==head_ptr)
		{
				//Make temp head ptr and set it as the CURRENT head ptr
			node<Object>* temp_head_ptr = head_ptr;
				//Rearrange head ptr to the list
			head_ptr=temp_head_ptr->get_next();
				//Destroy temp_head_ptr -- MEMORY MANAGEMENT
			delete temp_head_ptr;
				//Make current ptr point to head
			current_ptr=head_ptr;
				//Decrement list length
			list_length--;
				//Set this node to NULL -- Even though its destroyed
			temp_head_ptr=NULL;
			
			return;
		}
		else if(current_ptr==tail_ptr)
		{	
			//Make temp tail ptr and set it as the CURRENT head ptr
			node<Object>* temp_tail_ptr = tail_ptr;
				//Rearrange tail ptr to the list
			tail_ptr=temp_tail_ptr->get_previous();
			tail_ptr->set_next(NULL);	//Segmentation fault without setting tail ptr net to NULL
				//Destroy temp_tail_ptr -- MEMORY MANAGEMENT
			delete temp_tail_ptr;
				//Make current ptr piont to tail
			current_ptr=tail_ptr;
				//Decrement list length
			list_length--;
				//Set this node to NULL -- Even though its destroyed
			temp_tail_ptr=NULL;
			
			return;
		}
		else
		{
			node<Object>* temp_current_ptr;
				//Rearrange ptrs
			temp_current_ptr=current_ptr->get_previous();
			temp_current_ptr->set_next(current_ptr->get_next());
			temp_current_ptr=current_ptr->get_next();
			temp_current_ptr->set_previous(current_ptr->get_previous());
			
			delete current_ptr;
			current_ptr=temp_current_ptr;
			
			list_length--;
			temp_current_ptr=NULL;
		}
		
	}
		//Move forward in the list
	template <typename Object>
	void LinkedList<Object>::forward()
	{
			//Get next node address
		current_ptr=current_ptr->get_next();
	}
		//Move back in the list
	template <typename Object>
	void LinkedList<Object>::back()
	{
			//Get previous node address
		current_ptr=current_ptr->get_previous();
	}
		//Move to the head of the list
	template <typename Object>
	void LinkedList<Object>::move_to_head()
	{
		current_ptr=head_ptr;
	}
		//Move to the tail of the list
	template <typename Object>
	void LinkedList<Object>::move_to_tail()
	{
		current_ptr=tail_ptr;
	}
		//Get data from current node
	template <typename Object>
	Object LinkedList<Object>::get_current_data() const
	{
		return current_ptr->get_data();
	}
		//Get size of the list
	template <typename Object>
	std::size_t LinkedList<Object>::size()
	{
		return list_length;
	}
		//Get current ptr
	template <typename Object>
	const node<Object>* LinkedList<Object>::get_current_ptr() const
	{
		return current_ptr;
	}
	template <typename Object>
	node<Object>* LinkedList<Object>::get_current_ptr()
	{
		return current_ptr;
	}
		//Get head ptr
	template <typename Object>
	const node<Object>* LinkedList<Object>::get_head_ptr() const
	{
		return head_ptr;
	}
	template <typename Object>
	node<Object>* LinkedList<Object>::get_head_ptr()
	{
		return head_ptr;
	}
		//Get tail ptr
	/*const node* LinkedList::get_tail_ptr_value() const
	{
		return tail_ptr;
	}*/
			//Seeach for occurence of Object
	template <typename Object>
	bool LinkedList<Object>::list_search(const Object& data_value)
	{
		for(current_ptr=head_ptr; current_ptr!=NULL; forward())
			if(data_value==get_current_data())
				return true;
		return false;
	}
			//Serearch and return the count of data occurences
	template <typename Object>
	int LinkedList<Object>::list_search_count(const Object& data_value)
	{
		int count=0;
		
		for(current_ptr=head_ptr; current_ptr!=NULL; forward())
		{
			if(data_value==get_current_data())
				count++;
		}
		return count;
	}
	template <typename Object>
	void LinkedList<Object>::list_copy(LinkedList<Object>& source)
	{
		Object temp;
		list_clear();	//Avoid memory leaks
			//Deal with empty list
		if(source.head_ptr==NULL)
			return; 
			//Set up head node for the new list
		source.move_to_head();
		temp=source.get_current_data();
		insert(temp);
		tail_ptr=head_ptr;
		current_ptr=tail_ptr;
		source.forward();
			//Copy remaining data
		while(source.current_ptr!=NULL)
		{
			temp=source.get_current_data();
			insert(temp);
			source.forward();
		}
	}
		//Reversing list
	template <typename Object>
	void LinkedList<Object>::list_reverse()
	{
		if(list_length==0)
			return;
		
		LinkedList temp_list;
		Object temp_data;

		move_to_tail();
		while(current_ptr!=NULL)
		{
			temp_data=get_current_data();
			temp_list.insert(temp_data);
			back();
		}
		list_clear();
		temp_list.move_to_head();
		while(temp_list.current_ptr!=NULL)
		{
			temp_data=temp_list.get_current_data();
			insert(temp_data);
			temp_list.forward();
		}
		temp_list.list_clear();
	}
	//----------------------------------------------------------------------------------------------
	//	Overloaded operations
	//----------------------------------------------------------------------------------------------
	template <typename Object>
	std::ostream& operator <<(std::ostream& output, const LinkedList<Object>& source)
	{
		//source.move_to_head();
		const node<Object>* current = source.get_head_ptr();
		
		while(current!=NULL)
		{
			output<<current->get_data()<<" ";
			current=current->get_next();
		}

		return output;
	}
	template <typename Object>
	std::istream& operator >>(std::istream& input, LinkedList<Object>& target)
	{
		//char space = ' ';
		
		std::string temp;//, add; 
		Object add;
		
		std::getline(input, temp);
		std::stringstream ss(temp);
		//ss<<input;
		target.move_to_tail();
		while(ss)
		{
			ss>>add;
			target.insert(add);
		}
		target.remove_node();
		
		/*for(size_t p=0, q=0; p!=temp.npos; p=q)
		{
			add=temp.substr(p+(p!=0), (q=temp.find(space, p+1))-p-(p!=0));
			//ss<<add;
			target.insert(add);
		}*/
		return input;
	}
		//Overloaded = operator
	template <typename Object>
	void LinkedList<Object>::operator =(LinkedList<Object>& source)
	{
		if(this == &source)
			return;
		list_copy(source);
	}
		//Overloaded + operator
	template <typename Object>
	LinkedList<Object>* operator +(const LinkedList<Object>& list1, const LinkedList<Object>& list2)
	{
		LinkedList<Object>* temp_linklist = new LinkedList<Object>();
		//temp_linklist.concat_lists(list1, list2);
		Object data_temp;
		//temp_linklist=list1;
		//temp_linklist->concat_lists(list1, list2);
		/*while(list1.current_ptr!=NULL)
		{
			data_temp=list1.get_current_data();
			temp_linklist->add_to_tail(data_temp);
			list1.forward();
		}*/
		
		return temp_linklist;
	}
	template <typename Object>
	void operator +=(LinkedList<Object>& list1, LinkedList<Object>& list2)
	{
		//LinkedList temp_list;
		//temp_list.list_copy(list2);
		Object temp;
		list2.move_to_head();
		list1.move_to_tail();
		
		for(int i=0; i<list2.size(); i++)
		{
			temp=list2.get_current_data();
			list1.insert(temp);
			list2.forward();
		}
	}
}