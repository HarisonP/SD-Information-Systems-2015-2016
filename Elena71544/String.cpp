#include <iostream>
#include <string>
using namespace std;
//swap two different sections of a string 

void swap(string &s, int firstIndex, int secondIndex){ //swap two char elements of a string
	if (!s.size())
		return;

	char tmp = s[firstIndex];
	s[firstIndex] = s[secondIndex];
	s[secondIndex] = tmp;
}

void swapEqualSections(string &s, int firstStart, int secondStart, int size){ 

	if (firstStart > secondStart || !s.size() || s.size() < size * 2)
		return;

	for (size_t i = 0; i < size; i++)
	{
		swap(s, firstStart + i, secondStart + i);
	}
}

void swapSections(string &s, int start, int middle, int end){
	if (!s.size() || s.size() < end)
		return;
	if (start > middle || middle > end || start > end || start < 0 || middle < 0 || end<0)
		return;



	int firstSize = middle - start;
	int secondSize = end - middle;

	while (firstSize != secondSize){
		if (firstSize > secondSize){
			swapEqualSections(s, middle - firstSize, middle, secondSize);
			firstSize -= secondSize;
		}
		else {
			swapEqualSections(s, middle - firstSize, middle + (secondSize - firstSize), firstSize);
			secondSize -= firstSize;
		}

	}
	swapEqualSections(s, middle - firstSize, middle, firstSize);
}


int main(){
	string myString = "Abcdefghijklmn";
	cout << myString << endl;

	swapSections(myString, 3, 6, 10);
	cout << myString << endl;

	return 0;
}