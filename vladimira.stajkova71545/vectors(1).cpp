#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string word1,word2;
	cin >> word1;
	cin >> word2;
	string word = word1 + word2;
	int start_word2 = word1.size();
	vector<char> myvector(word.begin(), word.end());
	reverse(myvector.begin(), myvector.begin() + start_word2);
	reverse(myvector.begin() + start_word2, myvector.end());
	reverse(myvector.begin(), myvector.end());

	for(int i = 0; i < myvector.size(); i++)
	{
		cout << myvector[i] ;
	}

	system("pause");
	return 0;



}


