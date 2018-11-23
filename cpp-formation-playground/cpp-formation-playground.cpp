#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <iterator>

using namespace std;

void exercise2(const vector<string> &words) {
	for_each(words.cbegin(), words.cend(), [](const string &word) {cout << word << endl; });
}

template<typename T>
void exercise3(const vector<T>& words) {
	for (const T &word : words) 
		cout << word << endl;
}

unsigned int exercise4(const vector<string> &words, const unsigned int size) {
	return words.end() - find_if(words.cbegin(), words.cend(), [size](const string &word) {return word.size() > size; });
}

unsigned int exercise5(const vector<string> &words, const unsigned int size) {
	return count_if(words.cbegin(), words.cend(), [size](const string &word) {return word.size() > size; });
}

bool testSize(const string &word, unsigned int size) {
	return word.size() > size;
}

unsigned int exercise6(const vector<string> &words, unsigned int size) {
	
	return count_if(words.cbegin(), words.cend(), bind(testSize, placeholders::_1, size));
}

//print to a stream the words that are bigger than size
void exercise7(const vector<string> &words, unsigned int size, ostream &os) {
	for_each(words.begin(), words.end(), [size,&os](const string &word) { if (word.size() > size) os << word << endl; });
}

//return an iterator with the absolute values of the vector taken
 void exercise8(vector<int> &numbers) {
	 cout << "Write a list of numbers separated by whitespaces, I'll give you back the list in absolute values. Write a non numeric caracther to terminate" << endl;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(numbers));
	transform(numbers.begin(), numbers.end(), numbers.begin(), [](int i) {return i < 0 ? -i : i; });
}

int main()
{
	vector<string> words{ "ola","salut","ciao","hey","osu" };
	stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });

	exercise2(words);
	exercise3(words);
	cout << exercise4(words, 2) << endl;
	cout << exercise5(words, 3) << endl;
	cout << exercise6(words, 4) << endl;
	exercise7(words, 3, cout);
	vector <int> numbers;
	exercise8(numbers);
	exercise3(numbers);
	return 0;
}
