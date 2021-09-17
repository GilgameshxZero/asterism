#include <iostream>

template<typename T> //tells stack that we are about to work with a template
class Stack {

    public:

        Stack(); //stack default constructor
        //~Stack(); if you wanted a destructor //we won't need one for this code
        void push( int i ); //adds to the top of the stack
        int pop(); //returns the top of the stack
        bool isEmpty(); //tells if stack is empty or not
        int size() { return pos + 1; } //don't need a semi-colon when writing a function in a class
        //why don't need one? we put them for pop and push. 
        //because you don't use one after writing a function, only when declaring
        //ok, look up why we need a semi colon for a declaration

    private:

        int data[100]; //hardcoded for now, to only take a 100 entries, just for simplicity's sake
        int pos; //the position of the top of the stack

};

template<typename T>
Stack<T>::Stack(){

    pos = -1; //it's -1 because there is nothing on this stack //doesn't have to be -1
}

template<typename T>
bool Stack<T>::isEmpty(){

    return pos == -1; //if pos == -1, return true
}

template<typename T>
void Stack<T>::push( int i ){

    pos++; //position is -1, now it's 0
    data[pos] = i; //so now the data goes at pos, or index "0"
}

template<typename T>
T Stack<T>::pop(){ //returns the top of the stack

    //need a buffer in order to be able to return the top of the stack AND to down-size position  
    int tempPos = pos;
    pos--;
    return data[ tempPos ];
}

int main(){

    Stack<int> myStack; //template<typename T> means there is no longer a standard form of "myStack", so we must specifiy what data type we want myStack to be
    for( int i = 10; i < 20; i+=2){

        myStack.push(i);

    }

    std::cout << "myStack size: " << myStack.size() << "\n";

    while( !myStack.isEmpty() ){ //same as ( myStack.size() != 1 )

        int value = myStack.pop();
        std::cout << "Stack had: " << value << "\n";

    }

}