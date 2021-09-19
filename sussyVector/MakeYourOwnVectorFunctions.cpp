//
//  MakeYourOwnVectorFunctions.cpp
//  MakeYourOwnVector
//
//  Created by Anna Thomas on 9/13/21.
//

#include "MakeYourOwnVectorFunctions.hpp"

// int main() {
// 	int x = 0;
// 	x = -1;

// 	size_t y = 0;
// 	y = -1; // makes y ~18 billion billion

// }

// template <typename T>
// vectorStruct<T>::vectorStruct(int newCapacity) {
// 	// int *x;	 // declare my pointer
// 	// x = new int;	// reserves an address
// 	// *x = 0;	 // then sets whatever is at the address already (could be
// 	// previously
// 	// 				 // deallocated memory, we don't know) to zero so that there is no
// 	// 				 // potentially anomalies

// 	// int *x = new int(0);
// 	//
// 	// int *x = new int; //reserved an address
// 	// points at the first element of allocated heap space //go to heap and
// 	// reserve 4 (sizeof(int)) bytes (since int is 4 bytes usually)
// 	addressArray = new T[newCapacity];
// 	// the type inside new T[] is type "size_t"
// 	// the size of the capacity able to be allocated is the same as the range of
// 	// whatever size_t can store size_t is the type that stores any size of any
// 	// allocatable array size_t specifies how big something is, unsigned look it up
// 	capacity = newCapacity;
// 	arraySize = 0;
// }

// template <typename T>
// vectorStruct<T>::vectorStruct(const vectorStruct<T> &myVector) {
// 	this->arraySize = myVector.arraySize;
// 	this->capacity = myVector.capacity;
// 	addressArray = new T[myVector.capacity];
// 	// if [10], reserve 10 * sizeof(T) bytes in a row
// 	// want to copy myVector, so make the amount of consecutive reserved space on
// 	// the heap the same

// 	for (int a = 0; a < this->arraySize; a++) {
// 		// cycles through every index of data

// 		// need to reserve an address to avoid the issues detailed below
// 		this->addressArray[a] = myVector.addressArray[a];
// 		// dangerous because addressArray has NOT been allocated. This could be
// 		// overwritting anything. Common backdoor for hacking if you can predict an
// 		// address, then you can modify unreserved memory
// 	}
// }

// template <typename T>
// vectorStruct<T>::~vectorStruct() {
// 	// when I write "delete nameofmyClass", it
// 	// will call the destructor and destroy that
// 	// variable of type nameofmyClass

// 	// avoids memory leaks by deallocating memory //unreserving memory
// 	// must deallocate because every time you use "new" you are allocating memory
// 	delete[] this->addressArray;

// 	// after the destructor is used, the object cannot be accessed anymore
// 	// these steps aren't necessary

// 	// stored in memory somewhere, but not on the heap
// 	// because they aren't manually allocated, the compiler will free them for me
// 	// so when the lifetime of a class object type vectorStruct ends, the computer
// 	// knows where these are allocated and will destroy them itself thus I only
// 	// need to account for what memory I personally allocated with "new"

// 	// this-> addressArray = nullptr;
// 	// this-> capacity = 0;
// 	// this-> arraySize = 0;
// }

// template <typename T>
// T *vectorStruct<T>::getAddressArray() {
// 	// was --> int
// 	// vectorStruct<T>::getAddressArray(){

// 	return addressArray;
// }

// /*

// int x, y, z;

// y = z = 1;
// // equivalent to z = 1, y = (reference to z)


// std::string s1, &s2, s3;

// s1 = s2 = s3 = "hi"; //if I wanted to be able to change s1 without affecting s3,
// but also am okay with s2 being tied to s3 (if I changed either, the other would
// change, but they are still not "equivalent" because one is a reference (s2) and
// the other is itself (s3))

// */

// // #include <vector>
// // #include <string>
// // std::vector<std::string> v1, v2{"hi", "my", "name", "is", "anna"};
// // //this = is already overloaded bc some bad binch did it in the class vector
// // so i don't have to, #nice v1 = v2; // calls copy assignment operator function
// // //aka "=" v1 = std::move(v2); // calls move assignment operator //aka
// // "vector& operator=( vector&& other )" //std::move returns an r value
// // reference
// // // https://en.cppreference.com/w/cpp/utility/move

// template <typename T>
// vectorStruct<T> &vectorStruct<T>::operator=(vectorStruct<T> const &otherVector)
// // https://en.cppreference.com/w/cpp/container/vector/operator%3D
// // r value reference aka move reference --> //vector& operator=( vector&& other
// // ); syntax moves all the stuff from otherVector to this-> otherVector is in a
// // valid but unspecified state afterwards, so it could be in any state except a
// // destructed one because using the destructor would make it invalid
// {
// 	// Guard against self assignment
// 	if (this == &otherVector) {
// 		//"this" in this context is a pointer that points
// 		//// at what the unary, overloaded operator "="
// 		// is // being used on //what's on the lefthand
// 		// side

// 		return *this;
// 		// dereference "this" and return it
// 	}

// 	delete[] addressArray;
// 	// need to deallocate first to avoid memory leaks

// 	this->addressArray = new int[otherVector.capacity];
// 	this->capacity = otherVector.capacity;
// 	// need to keep track of all elements of this->

// 	this->arraySize = otherVector.arraySize;
// 	// don't need to use get functions here because I
// 	// can access the private members of my class so
// 	// long as I am working within that class. If I were
// 	// in main and wanted the arraySize, i would need to
// 	// use getSize because that is outside of the class

// 	for (int a = 0; a < this->arraySize; a++) {
// 		// cycles through every index of data

// 		this->addressArray[a] = otherVector.addressArray[a];
// 		// ok so I can do otherVector.addressArray here
// 		// because i'm not trying to access the private
// 		// member addressArray, but am accessing the value
// 		// stored at index "a" of that address. swag!
// 	}

// 	return *this;
// 	// can only allocate a pointer into a reference //return a
// 	// dereferenced pointer to "this" , which is variable type vectorStruct&
// 	//*this will always return the "first element" in the heap it points at, but
// 	// because the only element in this heap space is of type vectoryStruct<T>, it
// 	// will return that.
// }

// // for the righthand side -->check notes for explanation
// template <typename T>
// T const &vectorStruct<T>::operator[](int index) const {
// 	return this->addressArray[index];
// }

// // for the lefthand side -->check notes for explanation
// template <typename T>
// T &vectorStruct<T>::operator[](int index) {
// 	return this->addressArray[index];
// 	// if I'm wanting to return a reference to an int,
// 	// why do i not need to write *this ->
// 	// addressArray[index] //inherint misunderstanding
// }

// template <typename T>
// void vectorStruct<T>::growVector() {
// 	int *temp = new int[2 * capacity];
// 	// just want a temp pointer to a new address so that we can increase the
// 	// capacity

// 	for (int i = 0; i < arraySize; i++) {
// 		temp[i] = addressArray[i];
// 	}

// 	delete[] addressArray;
// 	// get rid of the original address of the array( aka
// 	// my bootleg vector)

// 	capacity = capacity * 2;
// 	addressArray = temp;
// 	// make addressArray point at the same place(s) on the
// 	// heap that temp pointed to
// }

// template <typename T>
// void vectorStruct<T>::pushBack(T const &newValue) {
// 	if (arraySize == capacity) {
// 		growVector();
// 		// now vector has doubled its capacity
// 	}

// 	addressArray[arraySize] = newValue;
// 	arraySize++;
// }

// template <typename T>
// void vectorStruct<T>::popBack() {
// 	arraySize--;
// }

// template <typename T>
// T &vectorStruct<T>::get(int index) {
// 	int got = 0;

// 	if (index < arraySize && index >= 0) {
// 		got = addressArray[index];
// 	} else {
// 		throw std::runtime_error(
// 			"Error! Value at index nonexistant. Please assign more values to "
// 			"accomodate desired index.\n");
// 		// this formatting is okay because it concatenates char* arrays
// 		// automatically
// 	}

// 	return got;
// }

// //#include <bits/stdc++.h> //a very inclusive header that some compilers can use
// // vectorStruct<int> v;
// // int x;

// // https://en.cppreference.com/w/cpp/error/exception
// // throw {
// // 	x = v.get(-1);
// // } catch(std::exception const &e) {
// // 	std::cout << e.what();
// // }

// template <typename T>
// void vectorStruct<T>::set(int index, T const &newValue) {
// 	//   if (index > arraySize - 1) {
// 	// 	arraySize++;
// 	// }
// 	if (index >= arraySize || index < 0) {
// 		throw std::runtime_error(
// 			"Error! Value at index nonexistant. Die now!\n");
// 	}

// 	addressArray[index] = newValue;
// }

// template <typename T>
// int vectorStruct<T>::getSize() const {
// 	return arraySize;
// }

// template <typename T>
// int vectorStruct<T>::getCapacity() const {
// 	return capacity;
// }
