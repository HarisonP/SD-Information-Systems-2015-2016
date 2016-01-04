#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
string firstWord = "hary";
 string secondWord = "students";
 string wordConcat = firstWord + secondWord;
 vector<char> word(wordConcat.begin(), wordConcat.end());
 int startSecondWord = firstWord.size();

 reverse(word.begin(), word.begin() + startSecondWord);
 reverse(word.begin() + startSecondWord, word.end());
 reverse(word.begin(), word.end());

 for (int i = 0; i < word.size(); i++)
 {
  cout << word[i];
 }
 cout << endl;


 return 0;
}
