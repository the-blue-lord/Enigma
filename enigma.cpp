#include <iostream>
#include <string>

#ifndef ENIGMA_H
#include "enigma.h"
#endif

#ifndef  UTILIS_H
#include "utilis.h"
#endif

using namespace std;

// Define constants for the number of rotors used and for the maximum lenght of the message //
#define ROT_USED 3
#define MAX_LEN 32768

int main(int argc, char *argv[]) {
    // If one of the command arguments is -h dsiplay help message and return 1 //
    for(int i = 0; i < argc; i++) if(!strcmp(argv[i], "-h")) return sendHelpMessage();

    // Create two variables to store the machine setup //
    char rotorsOrder[] = "123";
    char rotorsPosition[] = "AAA";

    // Create a variable where to store the string to transform //
    char message[MAX_LEN];

    // Get the machine setup //
    cout << "\n";
    get_rotorsOrder(rotorsOrder);
    get_rotorsPosition(rotorsPosition);

    // Get text to transform //
    cout << "\nInsert the text here:\n";
    cin.ignore();
    cin.getline(message, MAX_LEN);

    // Transform text //
    EnigmaMachine Enigma(rotorsOrder, rotorsPosition);
    Enigma.encode(message);

    // Output the transoformed text
    cout << "Transformed text:\n" << message;

    return 0;
}