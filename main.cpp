#include <iostream>
#include <string>
#include <thread>
int factorial(const int& i) {
	int l = 1;
	for (int p = i; p != 1; --p){
		l *= p;
	}
	return l;
}

bool test() {
	return factorial(10) == 3628800 ? 0 : 1;
}

int main() {
	bool b = test();
	std::cout << std::boolalpha << b;
	return b;
}