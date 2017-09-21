//
// POJA SHAD SOLUTION
//
#include <vector>
#include <sstream>

using namespace std;

#include "morse.h"

char alpha[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
string morselist[]= {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

string Morse::getAsMorse() {
    morseOut = "";
    // CHECK FOR STRING SIZE MORE THEN 3 CHARACTERS
    if(input_string.size()> 3) {
        for (int i = 0; i <= input_string.length(); i++) {
            if (input_string[i] == NULL) {
                morseOut += "";
            } else if (input_string[i] == '\n') {
                morseOut += "\n";

            } else if (input_string[i] == ' ') {
                morseOut += "/";
                if (morseOut.length() > 2) {
                    morseOut += " ";
                }
            } else if (input_string[i] == '\n') {
                {
                    morseOut += "/\n";
                }
            } else if (input_string[i] == '\n ') {
                morseOut += "\n/";
            } else {
                // SEARCHING THE ALPHABET, WHEN RIGHT ALPHABET IS FOUND
                // USE THE INDEX TO FIND MORSE
                for (int j = 0; j <= sizeof(alpha); j++) {
                    temp = tolower(input_string[i]);
                    if (temp == alpha[j]) {
                        morseOut += morselist[j];
                        morseOut += " ";
                    }
                }
            }
        }
        // CUTTING THE STRING WHERE THE SPACE IS AND PUTTING THE STRING BACK TOGETHER
        for (int k = 0; k < morseOut.length() ; k++) {
            if(morseOut[k] == '\n'){
                string lower = morseOut.substr(0, k-1);
                string higher = morseOut.substr(k, morseOut.length());
                morseOut = lower +higher;
            }

        }
    } else {
        if(input_string == "\n"){
            morseOut+= "\n";
        } else if(input_string == " "){
            morseOut += "/";
        } else if(input_string == " \n"){
            morseOut += "/\n";
        } else if (input_string == "\n ") {
            morseOut += "\n/ ";
        }else{
            morseOut+= "";
        }
    }
    if(morseOut.length() > 2){
        morseOut.pop_back();
    }
    return morseOut;
}
string Morse::getAsString() {
    englishOut="";


    istringstream iss(input_string);
    string token;
    // String parser, makes token from characters between spaces
    while (getline(iss, token, ' ')) {
        // CHECK FOR EDGE CASES
        if(token.length() < 1){
            englishOut+= "";
        } else if(token == "\n"){
            englishOut += "\n";
        } else if( token == "/"){
            englishOut += " ";
        } else if (token == "/\n"){
            englishOut += " \n";
        } else if (token == "\n/"){
            englishOut += "\n ";
        } else { // WHEN EDGE CASES CLEARED, CONVERT FROM MORSE TO ENGLISH BY GETING THE INDEX FROM MORSE
            // AND GETTING THE LETTER FROM THE SAME INDEX IN ALPHABET LIST
        for (int j = 0; j <= sizeof(morselist); j++) {
                if(token == morselist[j])
                englishOut += toupper(alpha[j]); // CONVERT TO UPPERCASER += to string
            }
        }
    }
    //ERASE SPACES THAT IS NOT NEEDED
    if(englishOut.length()>2){
    for (int i = 0; i < englishOut.length() ; ++i) {
        if((englishOut[englishOut.length()] == ' ')){
            englishOut.pop_back();
            }
        }
    }
    return englishOut;
}



