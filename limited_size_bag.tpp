//Does this function operate as an implementation file? 
#include "limited_size_bag.hpp"

//template implementation - can I do this? 

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const {
	return size;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const {
	bool empty = 1;
	for(int i = 0; i < size; i++) {
		if(Bag_array[i] != 0) {
			empty = 0;
			break;
		}
	}
	return empty;
}

template<typename T>
std::size_t LimitedSizeBag<T>::fillNum() const {
		return Numfilled;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T & item) {
	//checking to see if if Numfilled == size and if the next place to add an item is empty. If not, false is returned 
	//if so, fill the array with the input and return true
	bool tf = 0;
	if(Bag_array[fillNum() + 1] == 0 && fillNum() !=  getCurrentSize()) {
		tf = 1;
		Bag_array[fillNum() + 1] = item;
	};
	Numfilled++;

	//returning true or false to say whether the value was stored or not
	return tf;	
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T & item) {
//declaring boolean var to store status of remove function
bool tf = 0;
	//iterating through the array seaching for value
	for(int i = 0; i < Numfilled; i++) {
		if(Bag_array[i] == item && i < size) {

			//if input = element in array annd iterator is less than total size of the  array
			//decrease the number filled by 1 and shift all elemnts forward one slot + alter bool var to true
			Numfilled--;
			for(int j = i; j < Numfilled; j++) {
				Bag_array[i] = Bag_array[j + 1];
				tf = 1;
			}
		};
	}
	//returning status of the remove function
	return tf;
}

template<typename T>
void LimitedSizeBag<T>::clear() {
	//iterating through the array and setting all elements to 0
	for(int i = 0; i < size; i++) {
	Bag_array[i] = 0;
	}
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const {
	//declaring int to store freq
	std::size_t freq;

	//iterating through the array and checkigeach member against the input.
	//if true, iterate freq var and continue, if false, nothing.
	for(int i = 0; i< Numfilled; i++) {
		if(item == Bag_array[i] ) {
		freq++;
		}
	}
	//returning frequency variable
	return freq;
};

template<class T>
bool LimitedSizeBag<T>::contains(const T & item ) const {
	//declaring bolean var to store status of whether the bag contains the input element
	bool contain = 0;
	for(int i = 0; i<Numfilled; i++) {
		if(Bag_array[i] == item) {
		contain = 1;
								}
	}
	//returning contain bool var 
	return contain;
};

template<class T>
vector<T> LimitedSizeBag<T>::toVector() const {
	//initializing vector of size 0 and will use push back to store each value
	vector<T> returnvec(0);
	//iterating through array and storing each value using push back. Going through bag backwards to place in properly 
	for(int i = size-1; i >= 0; i--) {
		returnvec.push_back(Bag_array[i]); 
	}
	//returning vector
	return returnvec;
};

