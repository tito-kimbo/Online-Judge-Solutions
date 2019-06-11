#include <iostream>
#include <vector>
#include <stack>

class Card {
public:
	int  number;
	char suit;

	Card(int n, char s) {
		number = n;
		suit = s;
	}

	int next() {
		if (number == 7) {
			return 10;
		}
		else {
			return number + 1;
		}
	}
};

//Vector de Stacks -> 1 por cada palo
bool resolver(int n)
{
	std::stack<Card> oros, copas, espadas, bastos, visible, nonVisible, *transfer = nullptr;
	int numb, count;
	char suit;
	bool gana, end, canPlace;

	gana = false;
	count = 0;
	for (int i = 0; i < 10 * n; i++) {
		std::cin >> numb >> suit;
		Card c = Card(numb, suit);
		visible.push(c);
	}

	for (int i = 0; i < 10 * n; i++) {
		nonVisible.push(visible.top());
		visible.pop();
	}

	//HERE WE EMULATE THE GAME (note the visible/nonVisible stacks always have an even number of cards)
	end = false;
	while (!end) {
		int i = 0;
		while (i < 2 && !nonVisible.empty()) {
			visible.push(nonVisible.top());
			nonVisible.pop();
			i++;
		}

		canPlace = true;
		while (canPlace && !visible.empty()) {
			Card c = visible.top();

			if (c.suit == 'O') {
				transfer = &oros;
			}
			else if (c.suit == 'C') {
				transfer = &copas;
			}
			else if (c.suit == 'B') {
				transfer = &bastos;
			}
			else if (c.suit == 'E') {
				transfer = &espadas;
			}

			if ((transfer->empty() && c.number == 1) || (!transfer->empty() && c.number == transfer->top().next())) {
				transfer->push(visible.top());
				visible.pop();
				count = 0;
			}
			else {
				canPlace = false;
			}
		}

		if (nonVisible.empty()) {
			while (!visible.empty()) {
				nonVisible.push(visible.top());
				visible.pop();
			}
			count++;
		}

		if (count >= 2) { end = true; }
	}

	if (visible.empty() && nonVisible.empty()) {
		gana = true;
	}

	return gana;
}

int main() {
	int n;

	std::cin >> n;
	while (n != 0)
	{
		if (resolver(n))
		{
			std::cout << "GANA\n";
		}
		else
		{
			std::cout << "PIERDE\n";
		}
		std::cin >> n;
	}
}