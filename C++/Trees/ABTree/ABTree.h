//Jason Disher
//ABTree Class Header File
//Last Modified: 14/12/2017
#ifndef PIIDISH_ABTREE
#define PIIDISH_ABTREE
#include <cstdlib>

namespace piidish_ABTree
{
	template<typename Item>
	class ABTree
	{
		public:
				//Constructors
			ABTree();
			ABTree(const Item& data);
				//Destructor
			~ABTree();
				//Member Functions
			void add(const Item& data);
			int search(const Item& data);
			std::size_t size();
		
		private:
			std::size_t tree_size;
			Item* array_based_tree;
			
			void ABTreeAdd(int index, const Item& data);
			int ABTreeSearch(int index, const Item& data);
		
	};
}
#include "ABTree.cpp"
#endif