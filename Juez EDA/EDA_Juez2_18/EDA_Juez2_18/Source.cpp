#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

std::istream & operator >> (std::istream & in, std::map<std::string,int> & m) {
	std::string line, key, aux;
	int val;
	std::getline(in, line);

	std::istringstream iss(line);

	iss >> key >> aux;
	while (iss) {
		val = std::stoi(aux);
		m[key] = val;
		iss >> key >> aux;
	}

	return in;
}

void compare(const std::map<std::string, int> &m1, const std::map<std::string, int> &m2
	, std::vector<std::string> & added, std::vector<std::string> &removed
	, std::vector<std::string> &modified) {

	for (auto it = m1.begin(); it != m1.end(); ++it) {
		if (m2.count(it->first) == 1) {
			if (it->second != m2.at(it->first)) {
				//MODIFIED
				modified.push_back(it->first);
			}
		}
		else {
			//REMOVED
			removed.push_back(it->first);
		}
	}

	for (auto it = m2.begin(); it != m2.end(); ++it) {
		if (m1.count(it->first) == 0) {
			//ADDED
			added.push_back(it->first);
		}
	}
}

void resolver() {
	std::vector <std::string> added, removed, modified;
	std::map<std::string, int> dict1, dict2;

	//WE READ THE TWO
	std::cin >> dict1 >> dict2;

	//NOW WE COMPARE
	compare(dict1, dict2, added, removed, modified);

	//+
	if (added.size() != 0)
	{
		std::cout << '+';
		for (int i = 0; i < (int)added.size(); ++i) {
			std::cout << ' ' << added[i];
		}
		std::cout << '\n';
	}
	//-
	if (removed.size() != 0) {
		std::cout << '-';
		for (int i = 0; i < (int)removed.size(); ++i) {
			std::cout << ' ' << removed[i];
		}
		std::cout << '\n';
	}
	//*
	if (modified.size() != 0) {
		std::cout << '*';
		for (int i = 0; i < (int)modified.size(); ++i) {
			std::cout << ' ' << modified[i];
		}
		std::cout << '\n';
	}

	if (modified.size() == 0 && added.size() == 0 && removed.size() == 0) {	
		std::cout << "Sin cambios\n";
	}
	std::cout << "----\n";
}

int main() {
	int n;
	std::cin >> n;
	std::cin.get();
	for (int i = 0; i < n; ++i) {
		resolver();
	}
}