#include <ncurses.h>
#include <iostream>

#include "feCharacter.h"
#include "feClass.h"
#include "feUtils.h"

int main() {

	feClass c;
	feCharacter test("Ma", "Marth", true, 'p', 'l', c);
	feUtils utils;

	// test character initialization
	if (test.printInfo() == "mMarthmalep") {
		std::cout << ("1");
	}
	else std::cout << (test.printInfo());

	// test RNG functionality
	// not easy to test randomness, but we can check if we're creating numbers
	std::vector<int> test_vector;
	int a;
	for(int i = 0; i < 10000; ++i) {
		a = utils.feRNG();
		if(a >= 0 && a <= 99) test_vector.push_back(a);
	}
	if (test_vector.size() == 10000) std::cout << ("1");
	else std::cout << ("0");

	std::cout << std::endl;

	return 0;
}
