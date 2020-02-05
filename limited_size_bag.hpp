#ifndef LIMITED_SIZE_BAG_HPP
#define LIMITED_SIZE_BAG_HPP

#include "abstract_bag.hpp"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//template declaration
template<typename T> class LimitedSizeBag {
private:
	//supposed to be a private pointer variable to be initialized in the constructors with both its type and size 
	T* Bag_array = NULL;
	std::size_t size; 
	std::size_t Numfilled;
public:
	//default constructor
	//initializes to an array of size 10 and fills with 0's
	LimitedSizeBag() {
		Bag_array = new T[10];
		for(int i = 0; i < 10; i++) {
			Bag_array[i] = 0;
									}
			size = 10;
			Numfilled  = 0;
						}

	//contructor that acccepts an int
	LimitedSizeBag(int inputSize) {
		Bag_array = new T[inputSize];
		for(int i = 0; i < inputSize; i++) {
			Bag_array[i] = 0;
											}
			size = inputSize;
			Numfilled = 0;
								}

	// add an item to the bag
  bool add(const T & item);
  
  // remove an item
  bool remove(const T & item);

  // check is the bag is empty
  bool isEmpty() const;

  // get number of items in the bag
  std::size_t getCurrentSize() const;

  // clear the bag contents
  void clear();

  // count how many time item occurs in bag
  std::size_t getFrequencyOf(const T & item) const;

  // check if item is in the bag
  bool contains(const T& item) const;

  std::size_t fillNum() const;

  vector<T> toVector() const;
};

#endif

