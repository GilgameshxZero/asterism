#include <cmath>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <fstream>
#include <cstring>

class MyString {
 

    private:

        char * data; //so that we can allocate the value of the character array as we go //a pointer to the address of "data"
        int length;

    public:

        //the operator << is a standalone function, so it needs the friend keyword to access private members
        //"It will define the function as a non-member function of the namespace surrounding the class it appears in" 
        //so could you write friend in private technically?
        friend std::ostream & operator << ( std::ostream & out, const MyString & rhs); 
        //use friend keyword to let the class and function know that whenever this function is used it is allowed to access the private members of this class
        
        //these operator [] is a method, thus they don't need the friend keyword to access private members
        char operator [](int index) const; //indexing into a string, so the return type will be a character //righthand side -->check notes for explanation
        char & operator [](int index ); //lefthand side -->check notes for explanation 

        MyString(); //the default constructor
        MyString( const char * ); //another constructor whose paramater is a char array
        MyString( const MyString & varToCopy ); //syntax for a copy constructor //have not written the function yet
        
        int getLength() { return length }; //an accessor function that gets the length and spits it out 
        //you can't just do MyVector.length outside of the class because that would be acting on a the PRIVATE data member length
        //thus you must make a public member function that can point to the private member and display it

        //int getData() { };
        

};

//to overload the operator <<
std::ostream & operator << ( std::ostream & out, const MyString & rhs);
{
    //option for what to write if default constructor had data = nullptr;
    //if ( rhs.data == nullptr){
    //std::cout << "null" << std::endl;
    //}
    //better to not initialize a pointer to null

    out << rhs.data; //friend keyword in the declaration of this function in class MyString allows access to any private member variables within this function, when it is called

    return out; //out is the same variable type as the function //std::ostream & takes any type of stream and sends the data out to it
    //look up intrinsically what a stream is

}

//to overload the "operator" []
//for the righthand side -->check notes for explanation
char MyString::char operator[] ( int index ) const 
{
    return data[index]; 
}

//to overload the "operator" []
//for the lefthand side -->check notes for explanation
 char & MyString::char operator[] ( int index )
{
    return data[index]; 
}

MyString::MyString() 
{ 

    data = new char[1]; //tells it to allocate one "spot" on the heap for storing the values of char array data (char * data)
    data[0] = 0; //tells it that the char array data indexed at zero is null as 0 is the null terminating character 
    //reads 0 as a char, and on the ascii table, dec 0 is NULL //whereas dec 48 is the number 0
    length = 0;
}

MyString::MyString( const char* words )
{


    length = strlen( words );
    data = new char [length ];

    for( int i = 0; i < length; i++){
        data[i] = words[i]; //now the data is copied into the char array (string) "words"
    }

    // delete [] data; //use [] to indicate we are deleting an array
    // data = nullptr;


}

MyString::MyString( const MyString & varToCopy )
{
    //write code to make this copy constructor
}

MyString::~MyString()
{

    delete [] data; //use [] to indicate we are deleting an array
    data = nullptr;
}

int main ( int argc, char *argv[]) {

    MyString s1( "Hello ");

    std::cout << s1.getLength() << std::endl; //getLength is a public member function that allows us to "get" (access) the value of the private member variable length

    std::cout << s1 << std::endl; //cout is a stream and when the compiler runs the operator << on a stream, it looks for the parameter it reads "out"
    ofstream myFile( "someFile.txt");



} //here is where s1 goes out of scope
//when a block ends, the variables within go out of scope, thus the desconstructor for a class would be activated
//not very useful to deconstruct at the end of main, so store the class variables/any called functions in a block of code within main()
//