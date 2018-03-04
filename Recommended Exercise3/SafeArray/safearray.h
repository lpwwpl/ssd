//: safearray.h linpeiwen
#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T> 
class safearray {

  private:
    T *storage;
    int capacity;
  
  public:

    safearray() : storage(NULL), capacity(0) {} // default constructor
    safearray(int); // single param constructor
    ~safearray(void); // destructor
    T& operator[] (int) throw(out_of_range); 
};

/*
 * Single-parameter constructor allocates an array and persists its starting memory address 
 * in pointer storage. 
 * The parameter indicates the number of elements that the instance of the safearray needs to store. 
 *
 */
template <class T>
safearray<T>::safearray(int initCapacity) {	
	capacity = 	initCapacity;
	T* array = new T[capacity];
	storage = array;
}

/*
 * The destructor implements deallocate the memory block.
 *
 */
template <class T>
safearray<T>::~safearray() {
	delete []storage;	  
}

/*
 * overloading operator ([]) to provide random element access.
 * throw an out_of_range exception if an attempt is made to access an index outside 
 * the valid range.
 */
template <class T>
T& safearray<T>::operator[] (int index) throw(out_of_range) {
	if(index < 0 || index >= capacity) {
		throw out_of_range("OUT_OF_RANGE!\n");
	}
	return storage[index];
}

#endif
