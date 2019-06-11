#include <iostream> 
#include <vector>

std::istream & operator>>(std::istream & in, std::vector<int> & v) {
	int aux;

	in >> aux;
	while (aux != -1) {
		v.push_back(aux);
		in >> aux;
	}

	return in;
}

//BUILDING A TREE SHOULD BE EXTREMELY SIMILAR
void createPostOrder(std::vector<int> const& pre, std::vector<int> const& in, int & index, bool & first) {
	int i = 0;

	++index;
	while (in[i] != pre[index]) {
		++i;
	} //THIS WILL ALWAYS OCCUR AND i < limSup

	//When to go left?
	createPostOrder(pre, in, index, first); //LEFT

	//When to go right?
	createPostOrder(pre, in, index, first); //RIGHT
	if (!first) std::cout << ' ';
	std::cout << in[i];
	first = false;
}

bool resolver() {
	bool f = true;
	std::vector<int> preOrder, inOrder;
	int index = -1;
	std::cin >> preOrder;

	if (preOrder.size() != 0) {
		std::cin >> inOrder;
		createPostOrder(preOrder, inOrder, index, f);
		std::cout << '\n';
		return true;
	}
	return false;
}

int main() {
	while (resolver());
}