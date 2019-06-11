#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct range {
	int first, to;
};

ostream & operator<<(ostream &out, range const &r) {
	out << '0' << r.first;
	if (r.to != -1) out << '-' << r.to;

	return out;
}

//Gets range from deque and flushes data
range getRange(deque<int> &d) {
	range r;
	
	r.first = d.front();
	if (d.size() == 1) {
		r.to = -1;
	}
	else {
			//Calculate r.to
			int factor = 10;
			int modFirst, modLast, auxFirst, auxLast;
			int highestDiff;

			auxFirst = d.front();
			auxLast = d.back();
			modFirst = auxFirst % factor;
			modLast = auxLast % factor;
			//cout << modFirst << " - " << modLast << '\n';
			if (modFirst != modLast) highestDiff = modLast;
			
			while (factor <= d.front()) {
				auxFirst -= modFirst;
				auxLast -= modLast;
				factor *= 10;

				modFirst = auxFirst % factor;
				modLast = auxLast % factor;
				//cout << modFirst << " - " << modLast << '\n';
				if (modFirst != modLast) highestDiff = d.back() % factor;
			}
			r.to = highestDiff;
			
	}

	d.clear();
	return r;
}

bool solve(int &i) {
	int n;

	cin >> n;
	if (n == 0) return false;

	deque<int> groups;
	vector<range> output;
	int last, aux;

	cin >> aux;
	last = aux;
	groups.push_back(aux);

	for (int i = 1; i < n; ++i) {
		cin >> aux;

		if(aux != last+1) output.push_back(getRange(groups));

		last = aux;
		groups.push_back(aux);
	}
	//groups always non-empty
	output.push_back(getRange(groups));

	cout << "Case " << i << ":\n";
	for (int i = 0; i < output.size(); ++i) {
		cout << output[i] << '\n';
	}
	cout << '\n';

	return true;
}

int main() {
	int i = 1;

	while (solve(i)) {
		++i;
	}
}