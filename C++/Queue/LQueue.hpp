//Queue Class
//Programmer: Jason Disher
//Student: c3185333 
//Last modified 1/10/2017

#include <cstdlib>
#include <sstream>

namespace piidish_assignment2
{
		//Constructor
	template <typename Object>
	LQueue<Object>::LQueue()
	{
			//Create an empty list
		list = new LinkedList<Object>();		
	}
		//Create a list with data
	template <typename Object>
	LQueue<Object>::LQueue(Object& data)
	{
		list= new LinkedList<Object>(data);	
	}
		//Destroy Queue
	template <typename Object>
	LQueue<Object>::~LQueue()
	{
		list->list_clear();
	}
		//Clear Queue
	template <typename Object>
	void LQueue<Object>::queue_clear()
	{
		list->list_clear();
	}
		//Add to tail of the list
	template <typename Object>
	void LQueue<Object>::enqueue(Object& data)
	{
		list->move_to_tail();
		list->insert(data);
	}
		//Remove from head of the list
	template <typename Object>
	Object LQueue<Object>::dequeue()
	{
		Object obj;
		list->move_to_head();
		obj=list->get_current_data();
		list->remove_node();
		return obj;
	}
		//Returns true if list is empty
	template <typename Object>
	bool LQueue<Object>::is_empty() const
	{
		return list->size()==0;
	}
		//Returns size of the list
	template <typename Object>
	size_t LQueue<Object>::size() const
	{
		return list->size();
	}
		//Returns data from head of the list
	template <typename Object>
	Object LQueue<Object>::query_front()
	{
		list->move_to_head();
		return list->get_current_data();
	}
		//Copy a queue
	template <typename Object>
	void LQueue<Object>::queue_copy(LQueue& source)
	{
		LinkedList<Object>* copy_list = source.get_list();
		std::cout<<*copy_list;
		list = copy_list;
	}
		//Returns a copy of the list of the list of the queue
	template <typename Object>
	LinkedList<Object>* LQueue<Object>::get_list() const
	{
		return list;
	}
		//Returns true if queue is ordered false if not
	template <typename Object>
	bool LQueue<Object>::is_ordered() const
	{
		if(is_empty())
			return false;
		Object a, b;
		
		list->move_to_head();
		a=list->get_current_data();
		list->forward();
		
		while(list->get_current_ptr()!=NULL)
		{
			b=list->get_current_data();
			if(maxim(a,b))
				return false;
			list->forward();
			a=b;
		}
		return true;
	}
		//Returns true if Object 1 is greater than object 2
	template <typename Object>
	bool maxim(Object& a, Object& b)
	{
		return a>b;
	}
//--------------------------------------------------------------------------------------------------
//		Overloaded operators
//--------------------------------------------------------------------------------------------------	
	template <typename Object>
	std::ostream& operator<< (std::ostream& output, const LQueue<Object>& source)
	{
		LinkedList<Object>* listout = source.get_list();
		output<<*listout;
		return output;
	}
	template <typename Object>
	std::istream& operator >>(std::istream& input, LQueue<Object>& target)
	{
		LinkedList<Object>* list_in = target.get_list();
		std::string temp;
		Object add;
		
		std::getline(input, temp);
		std::stringstream ss(temp);
	
		while(ss)
		{
			ss>>add;
			list_in->insert(add);
		}
		list_in->remove_node();
		
		return input;
	}
}