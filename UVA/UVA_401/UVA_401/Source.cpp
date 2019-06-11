#include <iostream>
#include <string>
using namespace std;

char getReverse(const char &c) {
	switch (c) {
		case 'A':return 'A';
		case 'E':return '3';
		case 'H':return 'H';
		case 'I':return 'I';
		case 'J':return 'L';
		case 'L':return 'J';
		case 'M':return 'M';
		case 'O':return 'O';
		case 'S':return '2';
		case 'T':return 'T';
		case 'U':return 'U';
		case 'V':return 'V';
		case 'W':return 'W';
		case 'X':return 'X';
		case 'Y':return 'Y';
		case 'Z':return '5';
		case '1':return '1';
		case '2':return 'S';
		case '3':return 'E';
		case '5':return 'Z';
		case '8':return '8';
	}
	return ' ';
}

string reverse(const string &s) {
	string aux="";
	for (int i = s.size() - 1; i >= 0; --i) {
		aux += s[i];
	}
	//cout << "REVERSED: " << aux << '\n';
	return aux;
}

string mirror(const string &s) {
	string aux = "";
	for (int i = 0; i < s.size(); ++i) {
		aux += getReverse(s[i]);
	}
	//cout << "MIRRORED: " << aux << '\n';
	return aux;
}

bool isMirrored(string &s) {
	return s == reverse(mirror(s));
}

bool isPalindrome(string &s) {
	return s == reverse(s);
}

bool solve() {
	string s;

	cin >> s;
	if (!cin) return false;

	bool mirror, palindrome;

	mirror = isMirrored(s);
	palindrome = isPalindrome(s);

	cout << s << " -- is ";
	if (mirror) {
		if (palindrome) {
			cout << "a mirrored palindrome.";
		}
		else {
			cout << "a mirrored string.";
		}
	}
	else {
		if (palindrome) {
			cout << "a regular palindrome.";
		}
		else {
			cout << "not a palindrome.";
		}
	}
	cout << '\n' << '\n';

	return true;
}

int main() {
	while (solve()) {}
}