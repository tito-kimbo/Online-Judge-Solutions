#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct myTime {
	int hour, minute;
};

struct task {
	myTime start;
	int duration; //in minutes

	task() {}
	task(myTime s, int d) {
		start = s;
		duration = d;
	}

	myTime end() {
		myTime e = start;
		e.hour += duration / 60;
		e.minute += duration % 60;
		if(e.minute >= 60) {
			e.hour++;
			e.minute -= 60;
		}
		return e;
	}
};

bool operator<(myTime t1, myTime t2) {
	return t1.hour < t2.hour || (t1.hour == t2.hour && t1.minute < t2.minute);
}

bool operator<=(myTime t1, myTime t2) {
	return t1.hour < t2.hour || (t1.hour == t2.hour && t1.minute <= t2.minute);
}

bool operator<(task t1, task t2) {
	return t1.start < t2.start;
}

//m < 60
void addTo(myTime &t, int m) {
	t.minute += m;
	if (t.minute > 60) {
		t.hour++;
		t.minute -= 60;
	}
}


istream & operator >> (istream &in, myTime &t) {
	in >> t.hour;
	in.get();
	in >> t.minute;
	return in;
}

bool solve() {
	int N;
	cin >> N;
	if (N == 0) return false;

	vector<task> v(N);
	myTime start;
	int duration;
	for (int i = 0; i < N; ++i) {
		cin >> start >> duration;
		v[i] = task(start,duration);
	}

	sort(v.begin(), v.end());
	int films = 0;
	myTime available, end;
	available.hour = available.minute = 0;
	int i = 0;
	while(i < N) {
		//PICK THE ONE THAT ENDS THE EARLIEST (if there is overlap)
		if (available <= v[i].start) {
			++films;
			end = v[i].end();
			++i;
			//We need to advance until we either end the candidates or find
			//a better one
			while(i < N && v[i].start < end){
				if (v[i].end() < end) {
					end = v[i].end();
				}
				++i;
			}
			available = end;
			addTo(available, 10);
		}
		else { //discard
			++i;
		}
		
	}
	cout << films << '\n';
	return true;
}

int main() {
	while (solve());
}