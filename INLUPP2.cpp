/// TESTER

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#include "morse.h"

bool testStringToMorse() {
	cout << endl << "Testing Morse::getAsMorse()" << endl;
	Morse morse;

	vector<pair<string, string>> input_data = {
		/* edge cases - empty or nearly empty input: */
		{ "", "" },      // empty string gives empty string
		{ "\n", "\n" },  // newline preserved
		{ " ", "/" },    // spaces give /
		{ " \n", "/\n" }, // combined space and newline
		{ "\n ", "\n/" }, // combined space and newline
						  /* simple cases - plain input, one or two words: */
		{ "Hello", ".... . .-.. .-.. ---" },
		{ "Hello World", ".... . .-.. .-.. --- / .-- --- .-. .-.. -.." },
		{ "Pizza please", ".--. .. --.. --.. .- / .--. .-.. . .- ... ." },
		/* complete alphabet  */
		{ "AbCdEfGhIjKlMnOpQrStUvWxYz", ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --.." },
		/* adding non morse characters - they should be ignored */
		{ "Hello World!", ".... . .-.. .-.. --- / .-- --- .-. .-.. -.." },
		{ "Pizza, please", ".--. .. --.. --.. .- / .--. .-.. . .- ... ." },
		/* trickier non morse characters */
		{ "Pizza plea$e", ".--. .. --.. --.. .- / .--. .-.. . .- ." },
		{ "%&/(a)=!#", ".-" },
		/* non morse characters, spaces and newlines */
		{ "Hello\nCruel World!", ".... . .-.. .-.. ---\n-.-. .-. ..- . .-.. / .-- --- .-. .-.. -.." },
		{ "Pizza\n \nplease", ".--. .. --.. --.. .-\n/\n.--. .-.. . .- ... ." },
	};


	int pass_count = 0;
	int fail_count = 0;
	for (vector<pair<string, string>>::iterator it = input_data.begin();
		it != input_data.end(); it++) {
		morse.setInputString(it->first);
		string result = morse.getAsMorse();
		if (result == it->second) {
			cout << "Test " << (it - input_data.begin() + 1) << ": succeeded!" << endl;
			pass_count++;
		}
		else {
			cout << "Test " << (it - input_data.begin() + 1) << ": FAILED :(" << endl;
			cout << "  expected: '" << it->second << "'" << endl;
			cout << "  got:      '" << result << "'" << endl;
			fail_count++;
		}
	}
	cout << "---- Test Results: ----" << endl;
	if (pass_count > 0)
		cout << "Passed " << pass_count << " tests (of " << input_data.size() << ")" << endl;
	if (fail_count > 0) {
		cout << "Failed " << fail_count << " tests" << endl;
		cout << "Please try again" << endl;
	}
	else {
		cout << "Congratulations! So far so good.." << endl;
		return true;
	}
	return false;
}


bool testMorseToString() {
	cout << endl << "Testing Morse::getAsString()" << endl;
	Morse morse;

	vector<pair<string, string>> input_data = {
		/* edge cases - empty or nearly empty input: */
		{ "", "" },       // empty string gives empty string
		{ "\n", "\n" },   // newline preserved
		{ "/", " " },     // / gives space
		{ "/\n", " \n" },  // combined space and newline
		{ "\n/", "\n " }, // combined space and newline
						  /* simple cases - plain input, one or two words: */
		{ ".... . .-.. .-.. ---", "HELLO" },
		{ ".... . .-.. .-.. --- / .-- --- .-. .-.. -..", "HELLO WORLD", },
		/* complete alphabet */
		{ ".- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..", "ABCDEFGHIJKLMNOPQRSTUVWXYZ" },
	};

	int pass_count = 0;
	int fail_count = 0;
	for (vector<pair<string, string>>::iterator it = input_data.begin();
		it != input_data.end(); it++) {
		morse.setInputString(it->first);
		string result = morse.getAsString();
		if (result == it->second) {
			cout << "Test " << (it - input_data.begin() + 16) << ": succeeded!" << endl;
			pass_count++;
		}
		else {
			cout << "Test " << (it - input_data.begin() + 16) << ": FAILED :(" << endl;
			cout << "  expected: '" << it->second << "'" << endl;
			cout << "  got:      '" << result << "'" << endl;
			fail_count++;
		}
	}
	cout << "---- Test Results: ----" << endl;
	if (pass_count > 0)
		cout << "Passed " << pass_count << " tests (of " << input_data.size() << ")" << endl;
	if (fail_count > 0) {
		cout << "Failed " << fail_count << " tests" << endl;
		cout << "Please try again" << endl;
	}
	else {
		cout << "Congratulations! Looks like you are finished.." << endl;
		return true;
	}
	return false;
}



int main() {

	if ( !testStringToMorse() ) {
		char ch = getc(stdin);
		return 1;
	}
	if ( !testMorseToString() ) {
		char ch = getc(stdin);
		return 1;
	}
	char ch = getc(stdin);
	return 0;
}

