#include <cmath>
//#include <string> don't include, only need cstring, which takes char * as parameters
//because i'm writting a class for strings, I won't use a library that can't take char * as parameteres

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <fstream>
#include <cstring> //aka <string.h>

class MyString {
 

    private:

        char * data; //so that we can allocate the value of the character array as we go //a pointer to the address of "data"
        int length;

    public:

        //the operator << is a standalone function, so it needs the friend keyword to access private members
        //"It will define the function as a non-member function of the namespace surrounding the class it appears in" 
        //so could you write friend in private technically? //idk experiment u sussy
        friend std::ostream & operator << ( std::ostream & out, const MyString & rhs); 
        //use friend keyword to let the class and function know that whenever this function is used it is allowed to access the private members of this class
        
        //the operator [] is a method, thus they don't need the friend keyword to access private members
        char operator [](int index) const; //indexing into a string, so the return type will be a character //righthand side -->check notes for explanation
        char & operator [](int index ); //lefthand side -->check notes for explanation 

        //the operator = is a unary operator, meaning it takes in one parameter 
        //unary operator take one argument/parameter //you can use argument/parameter interechangeably 
        MyString operator= (const MyString& aString);

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

MyString& MyString::operator= (const MyString& otherString) //can return something that is a reference to a type
{
    // Guard against self assignment
    if (this == &otherString){ //"this" in this context is a pointer that points at what the unary, overloaded operator "=" is being used on //what's on the lefthand side
        return *this; //dereference "this" and return it

    }

        this-> data = new char[otherString.getLength()]; //the pointer of the char* temp is now pointing at "otherString.length's value" "spot" on the heap /* can have it point at any number of spots on the heap, if you do, these spots will be consecutive and avoid memory fragmentation */
        //did this in preparation of allocating appropriate space for this-> data to store otherString.data since the unary operator = assigns the value of something on the righthand side to the variable on the lefthandside
        //temp is my buffer //A buffer is temporary storage of data that is on its way to other media or storage of data
        //the buffer will not have the same address (on the heap //because I used new, it will be the heap's address) as otherString, since we don't want to change otherString (it's a constant)
        //thus we give it a different spot on the heap

        //temp.getLength() = otherString.getLength(); //make the buffer's length match that of otherString //doesn't work because i can't assign a variable to a temporary
        
        this-> length = otherString.getLength(); //beause otherString is outside my class MyString::, i can't access its private members directly, hence usage of getLength()
        
        for(int a = 0; a < this-> length; a++){ //cycles through every index of data

            this-> data[a] = otherString.getData(a); //assign all the values at temp[a] the values of otherString[a]
            //these are private though so write a get for obtaining the value of something at index a 

        }   

     //a buffer is useful when doing a swap of some sort, otherwise it's extraneous
     //Since I overloaded the operator = to also copy, I don't need a buffer. 
     //my copy constructor can just simply use this overloaded operator in it if I want to replace the original object of type MyString with another object of type MyString
     //or I can call this whever I want to copy an object of type MyString that replaces the original object of type MyString
     //I can make a copy constructor that uses this overloaded operator in it, and that also preserves the original object of type MyString    
 
    }

    return *this; //can only allocate a pointer into a reference //look up
    //return a dereferenced pointer to "this" , which is variable type MyString& 
}


//default constructor
MyString::MyString() 
{ 

    data = new char[1]; //tells it to allocate one "spot" on the heap for storing the values of char array data (char * data)
    data[0] = 0; //tells it that the char array data indexed at zero is null as 0 is the "null terminating" character 
    //reads 0 as a char since the type of data is char *, and on the ascii table, dec 0 is "NULL" //whereas dec 48 is the number 0

    length = 0; //initialize length to 0 //not read as a char because length is type int
}

MyString::MyString( const char* words )
{

    //Defined in header <cstring> //std::size_t strlen( const char* str );
    //length() can only take in a string as a parameter, but strlen can take in a const char* aka char array as a parameter
    length = strlen( words ); // "Returns the length of the given byte string, that is, the number of characters in a character array whose first element is pointed to by str up to and not including the first null character." 
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