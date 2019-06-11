#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<string>ananagrams,words;
unordered_map<string,int> dict;

string tolower(const string &s) {
	string aux = "";

	for(int i=0;i<s.size();++i){
		aux += tolower(s[i]);
	}
	return aux;
}

bool solve() {
	string aux,sorted;

	getline(cin, aux);
	if (aux == "#")return false;

	istringstream iss(aux);

	iss >> aux;
	while(iss){
		sorted = tolower(aux);
		sort(sorted.begin(), sorted.end());
		words.push_back(aux);
		dict[sorted]++;
		iss >> aux;
	}

	return true;
}

int main() {
	while (solve()) {}
	string sorted;
	for (int i = 0; i < words.size();++i) {
		sorted = tolower(words[i]);
		sort(sorted.begin(), sorted.end());
		if (dict[sorted] == 1) ananagrams.push_back(words[i]);
	}
	sort(ananagrams.begin(), ananagrams.end());
	for (int i = 0; i < ananagrams.size(); ++i) {
		cout << ananagrams[i] << '\n';
	}
	//system("pause");
}