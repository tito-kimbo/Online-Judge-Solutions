#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

/*
NAIVE
int longestCommonSubstring(std::string s1, std::string s2, int max1, int max2) {

	if (max1 == 0 || max2 == 0) {
		return 0;
	}
	else if (s1[max1] == s2[max2]) {
		return 1 + longestCommonSubstring(s1, s2, max1 - 1, max2 - 1);
	}
	else {
		return std::max(longestCommonSubstring(s1,s2,max1-1,max2),
						longestCommonSubstring(s1,s2,max1,max2-1));
	}
}*/

//BOTTOM UP APPROACH
int solveDP(std::string & word1, std::string & word2, int size1, int size2) {
	std::vector<std::vector<int>> v;

	for (int i = 0; i < size1+1; ++i) {
		std::vector<int> aux;
		for (int j = 0; j < size2+1; ++j) {
			aux.push_back(0);
		}
		v.push_back(aux);
	}

	//<= is required to consider empty case
	for (int i = 0; i <= size1; ++i) {
		for (int j = 0; j <= size2; ++j) {
			if (i == 0 || j == 0) {
				v[i][j] = 0;
			}else if (word1[i-1] == word2[j-1]) {
				v[i][j] = 1 + v[i - 1][j - 1];
			} else {
				v[i][j] = std::max(v[i][j-1], v[i-1][j]);
			}
		}
	}

	return v[size1][size2];
}

bool resolver() {
	std::string word1, word2;

	std::cin >> word1 >> word2;
	if (!std::cin) return false;
	
	std::cout << solveDP(word1, word2, word1.size(), word2.size()) << '\n';
	
	return true;
}

int main() {
	while (resolver());
}