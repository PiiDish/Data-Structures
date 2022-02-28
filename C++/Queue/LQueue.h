//LQueue Class
//Programmer: Jason Disher
//Student: c3185333
//Last modified 1/10/2017

		//------------------------------------------------------------------------------------------
        // 					Constructors
		//------------------------------------------------------------------------------------------

        // Precondition	Nil
        // Postcondition:  A new instance of node is created
        // 	LQueue()
		
		// Precondition	Object to add
        // Postcondition:  A new instance of queue is created with Object
		//	LQueue(Object& data)
		
		//------------------------------------------------------------------------------------------
        // 					Destructors
		//------------------------------------------------------------------------------------------

        // Precondition	Instance of queue to destroy
        // Postcondition:  The queue estroyed and released from memory
        // 	~LQueue()
		
		// Precondition:	Must be a valid instance of queue
        // Postcondition:	Clears the Queue and releases from memory
		//	void queue_clear()
		
		//------------------------------------------------------------------------------------------
		// 				Members that mutate data
		//------------------------------------------------------------------------------------------
		
		// Precondition:	Must be a valid instance of queue and Object to add
        // Postcondition:	Adds the Object to the rear of the queue
		//	void enqueue(Object& data)
		
		// Precondition:	Quemust not be empty
        // Postcondition:	Returns the Object and removes it from the front of the queue
		//	Object dequeue();
		
		//------------------------------------------------------------------------------------------
        //				Members that query data
		//------------------------------------------------------------------------------------------
		
		// Precondition:	Queue that is valid and not empty 
        // Postcondition:	Returns the constant size of the queue
		//	std::size_t size() const
		
        // Precondition:	Queue that is vaild and not empty 
        // Postcondition:	Returns the constant Object stored at front of the queue
		//	Object query_front()
		
		// Precondition:	Queue that is vaild
        // Postcondition:	Returns true if the queue is empty. False if not
		//	bool is_empty() const
		
		// Precondition:	Queue that is vaild and not empty 
        // Postcondition:	Returns true is the queue Objects are in order
		//	bool is_ordered() const
		
#ifndef PIIDISH_LQUEUE
#define PIIDISH_LQUEUE
#include <cstdlib>
#include "LinkedList.h"

namespace piidish_assignment2
{
	template <typename Object>
		class LQueue
		{
			public:
				//typedef string::value_type value_type;
					//Constructor
				LQueue();
				LQueue(Object& data);
					//Destructor
				~LQueue();
					//Mutators
				void queue_clear();
				void enqueue(Object& data);
				Object dequeue();
					//Member Query fuctions
				std::size_t size() const;
				Object query_front();
				bool is_empty() const;
				bool is_ordered() const;
				void queue_copy(LQueue& source);
				LinkedList<Object>* get_list() const;
				
			private:
				LinkedList<Object>* list;
		};
	//----------------------------------------------------------------------------------------------
	//		Overloaded operators
	//----------------------------------------------------------------------------------------------
	template <typename Object>
	std::ostream& operator<< (std::ostream& output, const LQueue<Object>& source);
	template <typename Object>
	std::istream& operator >>(std::istream& input, LQueue<Object>& target);
	template <typename Object>
	bool maxim(Object& a, Object& b);
}
#include "LQueue.hpp"
#endif