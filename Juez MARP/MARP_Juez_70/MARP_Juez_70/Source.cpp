#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;

struct song {
	int length, score;
};

bool operator<(const song &s1, const song &s2) {
	return (s1.score/(double)s1.length) > (s2.score/(double)s2.length);
}

struct node{
	vector<bool> assigned;
	int k, score, scoreEst;
	int weightFirstSide, weightSecondSide;
};

bool operator<(const node &n1, const node &n2) {
	return n1.scoreEst < n2.scoreEst;
}

void estimate(node &n, const vector<song> &v, const int &D, int k, int &best) {
	int spaceFirstSide, spaceSecondSide, j, pes;
	spaceFirstSide = D - n.weightFirstSide;
	spaceSecondSide = D - n.weightSecondSide;
	j = k+1; //Check
	n.scoreEst = n.score;

	while (j < v.size() && (v[j].length <= max(spaceSecondSide, spaceFirstSide))) {
		if (v[j].length <= spaceFirstSide) spaceFirstSide -= v[j].length;
		else spaceSecondSide -= v[j].length;
		n.scoreEst += v[j].score;
		j = j + 1;
	}
	pes = n.scoreEst;
	//We fraction and extend to a solution
	if (j < v.size()) {
		n.scoreEst += v[j].score*ceil((spaceFirstSide + spaceSecondSide) / (double)v[j].length);
		++j;
		while (j < v.size()) {
			if (v[j].length <= spaceFirstSide) {
				spaceFirstSide -= v[j].length;
				pes += v[j].score;
			}
			else if (v[j].length <= spaceSecondSide) {
				spaceSecondSide -= v[j].length;
				pes += v[j].score;
			}
			++j;
		}
	}
	best = max(best, pes);
}

bool solve() {
	int N,D;
	cin >> N;
	if (N == 0) return false;

	cin >> D;
	vector<song> v(N);
	song aux;
	for (int i = 0; i < N; ++i) {
		cin >> aux.length >> aux.score;
		v[i] = aux;
	}

	int best = 0;
	priority_queue<node> pq;
	node X, Y;
	//Preprocessing
	sort(v.begin(), v.end());
	X.assigned = vector<bool>(N,false);
	X.k = X.score = X.weightFirstSide = X.weightSecondSide = 0;
	estimate(X, v, D, -1, best);


	pq.push(X);
	//Processing data from the PQ
	int i = 0;
	while (!pq.empty() && pq.top().scoreEst > best) {
		//We try the 3 options: first side, second side, and none
		X = pq.top();
		pq.pop();
		Y.assigned = X.assigned;
		Y.k = X.k+1;

		//First side
		if (v[X.k].length <= D-X.weightFirstSide) {
			Y.assigned[X.k] = true;
			Y.score = X.score + v[X.k].score;
			Y.weightFirstSide = X.weightFirstSide + v[X.k].length;
			Y.weightSecondSide = X.weightSecondSide;
			Y.scoreEst = X.scoreEst;

			if (Y.k == N) best = max(best, Y.score);
			else if (Y.scoreEst > best) pq.push(Y);
		}
		//Second side
		if (X.weightFirstSide != X.weightSecondSide && v[X.k].length <= D-X.weightSecondSide) {
			Y.assigned[X.k] = true;
			Y.score = X.score + v[X.k].score;
			Y.weightFirstSide = X.weightFirstSide;
			Y.weightSecondSide = X.weightSecondSide + v[X.k].length;
			if (v[X.k].length <= D - X.weightFirstSide) estimate(Y, v, D, X.k, best);
			else Y.scoreEst = X.scoreEst;
			
			if (Y.k == N) best = max(best, Y.score);
			else if(Y.scoreEst > best) pq.push(Y);
		}
		//None
		Y.assigned[X.k] = false;
		Y.score = X.score;
		Y.weightFirstSide = X.weightFirstSide;
		Y.weightSecondSide = X.weightSecondSide;
		estimate(Y, v, D, X.k, best);

		if (Y.k == N) best = max(best, Y.score);
		else if(Y.scoreEst > best) pq.push(Y);

		/*if (i % 10000 == 0) {
			cout << "MEJOR: " << best << '\n';
			cout << "PQ: " << pq.size() << '\n';
		}
		++i;*/
	}
	cout << best << '\n';
	return true;
}

int main() {
	while (solve());
}