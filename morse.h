//
// Created by Mark Dixon on 2017-09-03.
//

#ifndef MORSECODEOUTPUT_MORSE_H
#define MORSECODEOUTPUT_MORSE_H

#include <string>
using namespace std;

class Morse {
public:
    Morse() { input_string = ""; }

    void setInputString( string is ) { input_string = is; }

    string getAsMorse();    // Konvertera en vanlig (engelsk) string till en morse string
    string getAsString();   // Konvertera en morse string till en vanlig string (engelsk)

private:
    string input_string;
    string morseOut;
    char temp;
    string englishOut;


};


#endif //MORSECODEOUTPUT_MORSE_H
