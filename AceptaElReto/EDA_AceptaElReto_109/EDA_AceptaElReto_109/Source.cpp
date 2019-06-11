#include <iostream>
#include <map>
#include <string>

struct pair {
	int points = 0, played = 0;
};

bool resolver() {
	bool draw = false;
	std::string team1, team2, winner, category;
	int r1, r2;
	std::map<std::string, pair> m;

	std::cin >> category;
	if (category == "FIN") return false;

	std::cin >> team1;
	winner = team1;
	while (team1 != "FIN") {
		std::cin >> r1 >> team2 >> r2;

		m[team1].played++;
		m[team2].played++;
		if (r1 > r2) {
			m[team1].points += 2;
			m[team2].points++;
		}else { //r2 > r1
			m[team1].points++;
			m[team2].points += 2;
		}

		std::cin >> team1;
	}

	r1 = 0;
	for (auto it = m.begin(); it != m.end(); it++) {

		if (it->second.points > m[winner].points) {
			winner = it->first;
			draw = false;
		}
		else if (it->second.points == m[winner].points && it->first != winner) {
			draw = true;
		}

		r1 += (2 * (m.size() - 1)) - it->second.played;
	}

	r1 /= 2;
	if (draw) {
		std::cout << "EMPATE " << r1 << '\n';
	}
	else {
		std::cout << winner << ' ' << r1 << '\n';
	}

	return true;
}

int main() {
	while (resolver());
}