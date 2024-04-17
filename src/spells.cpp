#include <string>
#include <iostream>
#include <cmath>
#include "../include/spells.h"
#include "../include/characters.h"


void healing(Character &user) {
    user.receiveDamage(-floor(user.getMaxHealth() * 0.1));
    user.useSpell(floor(user.getMaxMana() * 0.1));
}