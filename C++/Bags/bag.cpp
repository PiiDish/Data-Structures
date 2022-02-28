//	Jason Disher
//	Bag Class Implementation File
//	Last Modified: 14/12/2017
#include <algorithm>	//Povides a c++ copy function
#include <cassert>		//Provides c++ assert functions
#include "bag.h"

using namespace std;
namespace piidish_bag
{
		//Repeat static member constant within class definition
	const bag::size_type bag::CAPACITY;
	
	bag::bag()
	{
		used=0;
	}
	bag::size_type bag::erase_all(const Item& target)
	{
		size_type index=0;
		size_type removed=0;
		
		while(index<used)
		{
			if(data[index]==target)
			{
				--used;
				data[index]=data[used];
				++removed;
			}
			else
				++index;
		}
		return removed;
	}
	bool bag::erase_one(const Item& target)
	{
			//Will hold the location of  target data in the array
		size_type index;
			//Set index to array start
		index=0;
		
		while((index<used) && (data[index]!=target))
			++index;
		if(index==size())
			return false;
		
		--used;
		data[index]=data[used];
		
		return true;
	}
	void bag::insert(const Item& entry)
	{
		assert(used<CAPACITY);
		
		data[used]=entry;
		used++;
	}
	void bag::operator +=(const bag& addend)
	{
		assert(size()+addend.size()<=CAPACITY);
		
		copy(addend.data, addend.data+addend.used, data+used);
		used+=addend.used;
	}
	bag::size_type bag::size() const
	{
		return used;
	}
	bag::size_type bag::count(const Item& target) const
	{
		size_type answer;
		size_type i;
		
		answer=0;
		for(i=0; i<used; ++i)
			if(target==data[i])
				++answer;
			
		return answer;
	}
	bag::Item bag::get_data(bag::size_type index) const
	{
		return data[index];
	}
	bag operator +(const bag& b1, const bag& b2)
	{
		assert(b1.size()+b2.size()<=bag::CAPACITY);
		
		bag ret_bag;
		ret_bag+=b1;
		ret_bag+=b2;
		
		return ret_bag;
	}
	std::ostream& operator <<(std::ostream& output, const bag& source)
	{
		output<<"{";
		for(bag::size_type i=0; i<source.size(); i++)
		{
			if(i<source.size()-1)
				output<<source.get_data(i)<<", ";
			else
				output<<source.get_data(i);
		}
		output<<"}"<<endl;
		
		return output;
	}	
}
