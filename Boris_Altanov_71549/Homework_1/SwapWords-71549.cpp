#include <iostream>
#include <string>
using namespace std;

void reverseWord(string& s, int start, int end) {
	int size = end - start;
	for (int i = start, j = end - 1; i < start + (size/2); i++, j--) {
		char tempLetter = s[i];
		s[i] = s[j];
		s[j] = tempLetter;
	}
}

void swapWords(string& s, int lengthOfFirstWord) {
	int size = s.size();
	reverseWord(s, 0, lengthOfFirstWord);
	reverseWord(s, lengthOfFirstWord, size);
	reverseWord(s, 0, size);
}


int main() {
	string s = "HariStudent";
	swapWords(s, 4);
	cout << s << endl;

	return 0;
}