#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


string swapStrings(string originalWord, int indexStartFirst, int indexEndFirst, int indexEndSecond);


int main() {
	string result = swapStrings("HarryStudents", 0, 4, 12);
	
	cout << result << endl;
	
	return 0;

}


string swapStrings(string originalWord, int indexStartFirst, int indexEndFirst, int indexEndSecond) {
	vector<char> word(originalWord.begin(), originalWord.end());

	reverse(word.begin() + indexStartFirst, word.begin() + indexEndFirst + 1);
	reverse(word.begin() + indexEndFirst + 1, word.begin() + indexEndSecond + 1);
	reverse(word.begin() + indexStartFirst, word.begin() + indexEndSecond + 1);

	string result = "";
	for (int i = 0; i < word.size(); i++) {
		result += word[i];
	}

	return result;
}