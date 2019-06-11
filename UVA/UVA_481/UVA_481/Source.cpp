#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
//Longest Increasing Subsequence with DP O(n^2)
vector<int> LIS(vector<int> &v) {
	vector<vector<int>> lis(v.size(), vector<int>()); //memo table
	int longest, size;

	for (int i = 0; i < v.size(); ++i) {
		lis[i].push_back(v[i]); //Initialize longest subsequence ending in v[i]
		for (int j = 0; j < i; ++j) { //Find actual longest subsequence ending in v[i]
			if (v[i] > v[j] && lis[j].size() >= lis[i].size()) {
				lis[i] = lis[j];
				lis[i].push_back(v[i]);
			}
		}
	}
	longest = 0;
	size = lis[0].size();

	for (int i = 1; i < lis.size(); ++i) { //Find last maximum subsequence
		if (lis[i].size() >= size) {
			size = lis[i].size();
			longest = i;
		}
	}

	return lis[longest];
}

Verdict: TLE
*/


void printPath(int elem, int size, vector<int> &previousInPath, vector<int> &v) {
	if (size > 1) {
		printPath(previousInPath[elem], size-1, previousInPath, v);
	}
	cout << v[elem] << '\n';
}

//O(nlogn) LIS solution
int LIS(int &size, vector<int> &v, vector<int> &smallest, vector<int> &smallestIndex, vector<int> &previousInPath) {
	int current, longestEnd, insert;

	longestEnd = current = 1;
	smallest[0] = v[0];
	smallestIndex[0] = 0;
	previousInPath[0] = -1;
	for (int i = 1; i < v.size(); ++i) {
		//Look for proper insert position for new element
		insert = lower_bound(smallest.begin(), smallest.begin()+ current, v[i]) - smallest.begin();
		
		smallest[insert] = v[i];
		//True index in v of the element
		smallestIndex[insert] = i;
		if (insert) {
			previousInPath[i] = smallestIndex[insert - 1]; //previous element for that path
		}
		else {
			previousInPath[i] = -1; //None
		}
		if (insert == current) {
			current++;
		}
		if (insert == current - 1) longestEnd = i;
	}

	cout << current << '\n';
	size = current;
	return longestEnd;
}

int main() {
	int aux = 0;
	vector<int> v;
	
	cin >> aux;
	while (cin) {
		v.push_back(aux);
		cin >> aux;
	}

	vector<int> smallest(v.size(), 0);
	vector<int> smallestIndex(v.size(), 0);
	vector<int> previousInPath(v.size(), 0);

	int l = LIS(aux, v, smallest, smallestIndex, previousInPath);
	cout << "-\n";
	printPath(l, aux, previousInPath, v);
}