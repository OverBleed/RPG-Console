#include <iostream>
#include "characters.h"

using namespace std;

#define GET_VARIABLE_NAME(Variable) (#Variable)

Character player1("John");

void combat(Character &player) {
	cout << player.getName() << " : What do you want to do?" << endl;
}

int main() {
	combat(player1);
}