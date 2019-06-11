#ifndef UTIL_H
#define UTIL_H
#include <list>
#include <string>
#include <vector>
#include <stdexcept>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

typedef string artista;
typedef string cancion;

class iPud {
private:
	int currentDuration;
	unordered_map<cancion, pair<artista, int>> canciones;

	unordered_map<cancion, list<cancion>::iterator> refs;
	list<cancion> playList;

	unordered_map<cancion, list<cancion>::iterator> played_refs;
	list<cancion> playedList;

public:

	iPud() {
		currentDuration = 0;
	}

	//O(1)
	void addSong(const cancion & s, const artista & a, int d) {
		if (canciones.count(s) == 1) {
			throw invalid_argument("La cancion ya existe");
		}
		else {
			canciones[s] = {a,d};
		}
	}
	
	//O(1)
	void addToPlaylist(const cancion & s) {
		if (canciones.count(s) == 0) {
			throw domain_error("Cancion no existente");
		}
		else if (refs.count(s) == 0) {
			list<cancion>::iterator it; 
			playList.push_back(s);
			it = playList.end();
			it--;
			refs[s] = it;
			currentDuration += canciones[s].second;
		}
	}

	//O(1)
	cancion current() {
		if (playList.empty()) throw domain_error("Lista de reproduccion vacia");
		return playList.front();
	}

	//O(1)
	void play() {
		if (!playList.empty()) {
			currentDuration -= canciones[playList.front()].second;

			if (played_refs.count(playList.front()) == 1) {
				playedList.erase(played_refs[playList.front()]);
			}
			playedList.push_front(playList.front());
			played_refs[playList.front()] = playedList.begin();

			refs.erase(playList.front());
			playList.pop_front();
		}
	}

	//O(1)
	int totalTime() {
		return currentDuration;
	}

	//O(n)
	vector<cancion> recent(int n) {
		vector<cancion> lastN;
		auto it = playedList.begin();

		for (int i = 0; i < playedList.size() && i < n; ++i) {
			lastN.push_back(*it);
			it++;
		}
		return lastN;
	}

	//O(1)
	void deleteSong(cancion s) {
		if (refs.count(s) == 1) {
			currentDuration -= canciones[s].second;
			playList.erase(refs[s]);
			refs.erase(s);
		}
		
		if (played_refs.count(s) == 1){
			playedList.erase(played_refs[s]);
			played_refs.erase(s);
		}
		canciones.erase(s);
	}
};

#endif
