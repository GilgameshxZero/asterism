#ifndef MakeYourOwnVectorFunctions_hpp
#define MakeYourOwnVectorFunctions_hpp

#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

template<typename T> //tells stack that we are about to work with a template
class vectorStruct{
    
private:
    
    int* addressArray; //= new int[1]; //a pointer to the address of the array
    int arraySize; // = 0; //stores the size of the vector
    int capacity; // = 1; //stores the capacity of the vector

public:
    
    /*
     
     Add operator overloads for all the comparison operators (==, !=, <, <=, >=, >). These should compare vectors lexicographically (which means in dictionary order). Remember, only 2 of the comparison operators need "real code" in them - the others can use just those two.

     template<typename T> //tells stack that we are about to work with a template
     
     */
    
    //these are all forward declarations
    //don't need vectorStruct:: in front because these declarations are within the class vectorStruct::
    //could write all the functions here, within the class, but they are in a .cpp file because prof. Dave wanted us to learn them that way first
    
    T& operator= (vectorStruct& otherVector);
    T operator[] ( int index ) const;
    T& operator[] ( int index );
    
    vectorStruct(int newCapacity); //constructor, makes a vector of capacity size  "capacity"
    vectorStruct(const vectorStruct &myVector); //copy constructor
    ~vectorStruct();
    
    //void growVector(vectorStruct &myVector); //C version
    void growVector(); //in C, it was necessary to pass a reference to a copy of an object as an argument because classes didn't exist, but with a class in C++, "this" points to itself, so it doesn't need to pass ANY arguments. It points to itself and acts on itself
    void pushBack(T newValue);
    void popBack();
    T get(int index);
    void set(int index, T newValue);
    
    int getSize() const;
    int getCapacity() const;
    int getAddressArray();
};


#endif /* MakeYourOwnVectorFunctions_hpp */

#include "MakeYourOwnVectorFunctions.hpp"

template<typename T>
vectorStruct<T>::vectorStruct(int newCapacity){

    addressArray = new int [newCapacity];
    capacity = newCapacity;
    arraySize = 0;
    
}

template<typename T>
vectorStruct<T>::vectorStruct(const vectorStruct& myVector){
    
    this-> arraySize = myVector.arraySize;
    //this-> addressArray = myVector.addressArray;
    this-> capacity = myVector.capacity;
    
    for(int a = 0; a < this-> arraySize; a++){ //cycles through every index of data

        this-> addressArray[a] = myVector.addressArray[a];
    }
    
}

template<typename T>
vectorStruct<T>::~vectorStruct(){ //when I write "delete nameofmyClass", it will call the destructor and destroy that variable of type nameofmyClass
    
    delete[] this-> addressArray;
    this-> addressArray = nullptr;
    this-> capacity = 0; //set all the values to NULL or zero....
    this-> arraySize = 0;
}

template<typename T>
int vectorStruct<T>::getAddressArray(){ //was --> int vectorStruct<T>::getAddressArray(){
    
    //*this-> addressArray; //dereference addressArray
    
    return *this-> addressArray; //dereference addressArray
    
}

template<typename T>
T& vectorStruct<T>::operator= (vectorStruct& otherVector) //can return something that is a referenc to a type
//doesn't say const because my methods aren't const, so i need to change those first
{
    // Guard against self assignment
    if (this == &otherVector){ //"this" in this context is a pointer that points at what the unary, overloaded operator "=" is being used on //what's on the lefthand side
        return *this; //dereference "this" and return it

    }

        this-> addressArray = new int[otherVector.getAddressArray()];
        
        this-> arraySize = otherVector.getSize();
        
        for(int a = 0; a < this-> arraySize; a++){ //cycles through every index of data

            this-> addressArray[a] = otherVector.addressArray[a]; //ok so I can do otherVector.addressArray here because i'm not trying to access the private member addressArray, but am accessing the value stored at index "a" of that address. swag!
            
    
        }

    return *this; //can only allocate a pointer into a reference //return a dereferenced pointer to "this" , which is variable type vectorStruct&
}

//for the righthand side -->check notes for explanation
template<typename T>
T vectorStruct<T>::operator[] ( int index ) const
{
    return this-> addressArray[index];
}

//for the lefthand side -->check notes for explanation
template<typename T>
T& vectorStruct<T>::operator[] ( int index )
{
    return this-> addressArray[index]; //if I'm wanting to return a reference to an int, why do i not need to write *this -> addressArray[index] //inherint misunderstanding
}

template<typename T>
void vectorStruct<T>::growVector(){
    
    
            int* temp = new int[2 * capacity];
                //just want a temp pointer to a new address so that we can increase the capacity
    
            for (int i = 0; i < capacity; i++){ //can be changed to size, capacity was done to account for the case of having "dummy" values
                    temp[i] = addressArray[i]; //copy the values at each index i to each index i of temp
    
            }
    
                delete[] addressArray; //get rid of the original address of the array( aka my bootleg vector)
                capacity = capacity * 2;
                addressArray = temp; //make the address of the array the address of temp
    
}


template<typename T>
void vectorStruct<T>::pushBack(T newValue){
    
    if (arraySize == capacity){
        growVector(); //now vector has doubled its capacity

    }
    
    addressArray[arraySize] = newValue;
    arraySize++;
}

template<typename T>
void vectorStruct<T>::popBack(){
    
    addressArray[arraySize - 1] = 0; //since we index at zero //don't use NULL just in case you don't fully understand it yet lol
    arraySize--;
    //should...delete the last element
}

template<typename T>
T vectorStruct<T>::get(int index){
    
    int got = 0;

    if (index < (arraySize + 1)){ //arraySize is the number of ints currently being stored

        got = addressArray[index];
    }

    else if (index > arraySize){
        std::cout << "Error! Value at index nonexistant. Please assign more values to accomodate desired index.\n";
        return 1;
    }

    return got;
}

template<typename T>
void vectorStruct<T>::set(int index, T newValue){
    
    if( index > arraySize - 1){
        arraySize++;

    }
    
    addressArray[index] = newValue;
}

template<typename T>
int vectorStruct<T>::getSize() const{
    
    return arraySize;
}

template<typename T>
int vectorStruct<T>::getCapacity() const{
    
    return capacity;
}

#include "MakeYourOwnVectorFunctions.hpp"
#include <cassert>

int main(int argc, const char * argv[]) {
    
    //Write a set of tests that demonstrate that your functions work properly. The quality/thoroughness of your tests is an important part of this assignment.
    //uwu
    
    vectorStruct<int> myVec = vectorStruct<int>(2);
    assert( myVec.getCapacity() == 2); //capacity is set to the variable data
    assert( myVec.getSize() == 0);
    myVec.growVector();
    assert( myVec.getCapacity() == 4); //capacity is set to the variable data
    assert( myVec.getSize() == 0);
    myVec.set(0, 69);
    assert( myVec.get(0) == 69 );
    myVec.pushBack(71);
    assert( myVec.get(1) == 71 );
    myVec.popBack();
    assert( myVec.get(1) == 0 );
    //myVec.freeVector(myVec); //now is my destructor


    
    return 0;
}