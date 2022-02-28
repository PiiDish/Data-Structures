//	Jason Disher
//	Bag Class Header File
//	Last Modified: 14/12/2017
#ifndef PIIDISH_BAG
#define PIIDISH_BAG
#include <cstdlib>	//Provides size_type
#include <iostream>	//Provides cout 

namespace piidish_bag
{
	class bag
	{
		public:
				//Typedef' declarations
			typedef int Item;
			typedef std::size_t size_type;
				//Member Constants
			static const size_type CAPACITY=30;
				//Constructors
			bag();
				//Member Mutator Functions
			size_type erase_all(const Item& target);
			bool erase_one(const Item& target);
			void insert(const Item& entry);
			void operator +=(const bag& addend);
				//Member Constant Functions
			size_type size() const;
			size_type count(const Item& target) const;
			Item get_data(size_type index) const;
			
		private:
			Item data[CAPACITY];
			size_type used;
	};
	bag operator +(const bag& b1, const bag& b2);
	std::ostream& operator <<(std::ostream& output, const bag& source);
}
#endif