int main ( int argc, char *argv[]) {

string inFileName = "simulator/factorial.c"
ifstream inFile( inFileName );

if(inFile.fail()){

    std::cout << "Failed to open: " << inFileName << std::endl;
}

stringstream splitter (line );
{
std::cout << "Got line: " << line << "\n";

std::cout << "Done \n";
return 0;
}

uint8_t getOpcode = getOpcode ( opcodeName);
{
    if( opcode == "read" ){
        return: 0x7; //0111 in binary, 0x7 in hex //determined by the values in the table wer got
    }
    else if ( opcode == "addi"){
        return 0x1; //0001 is 1 in binary, 0x1 in hex
    }
//.... other else if statements
//write if statements for all the opcodes
//table available in the assignment file
    else {
        std::cout << "Received BAD opcode\n";
    }
}

uint16_t splitUpParameters ( const string &opcodeName, stringstream &splitter){

    if( opcodeName == "addi" ){
        std::string r1;
        std::string r2;
        std::string imm; //immediate
        splitter >> r1 >> r2 >> imm; //splitter reads in space by space, so they are split up according to space placement
        std::cout << r1 << ", " << r2 << ", " << imm << std::endl;

    }


}

std:: cout << "Got opcode name: "  << opcodeName << std::endl;
std::cout << "The opcode is: 0x" << std::hex << +theOpcode << "\n";

//need the plus in front of theOpcode so that it doesn't read it out as a char //since it's uint8_t aka 8 bits aka a char is 8 bits and the computer will always assume/try to read 8 bits as a char (?)
//now it will read it out as a hex, and we hard-coded 0x so that we
//...can remember the displayed value is in hex

uint*_t theOpcode = getOpcode ( opcodeName );
uint16_t instruction  = theOpcode << 12; //to put the opcode in the correct location of the 2-byte integer


}

