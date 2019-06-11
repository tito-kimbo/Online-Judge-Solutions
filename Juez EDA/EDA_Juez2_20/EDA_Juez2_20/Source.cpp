#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
using namespace std;

struct sportData {
	string name;
	set<string> people;
	int val;
};

void assignVal(sportData & d, const unordered_map<string, int> & mult) {
	d.val = 0;
	for (auto it=d.people.begin(); it!=d.people.end(); it++) {
		if (mult.at(*it) == 1) {
			d.val++;
		}
	}
}

bool operator<(const sportData &d1, const sportData &d2) {
	return d1.val > d2.val || (d1.val == d2.val && d1.name < d2.name) ;
}

bool isMayus(const string & s) {
	for (int i = 0; i < s.size(); ++i) {
		if (!isupper(s[i])) {
			return false;
		}
	}

	return true;
}

bool resolver(){
	unordered_map<string,int> multiple;
	vector<sportData> v;
	string key = "", name = "";

	getline(cin,key);
	if (!cin) return false;

	while (key != "_FIN_") {
		sportData aux;
		aux.name = key;
		getline(cin,name);
		while (name != "_FIN_" && !isMayus(name)) {
			if (aux.people.count(name) == 0) {
				multiple[name]++;
				aux.people.insert(name);
			}
			getline(cin, name);
		}
		v.push_back(aux);
		key = name;
	}

	for (int i = 0; i < v.size(); ++i) {
		assignVal(v[i], multiple);
	}
	sort(v.begin(), v.end());

	//OUTPUT
	for (int i = 0; i<v.size(); ++i) {
		cout << v[i].name << ' ' << v[i].val << '\n';
	}
	cout << "***\n";

	return true;
}

int main() {
	while (resolver());
}