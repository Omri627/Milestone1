#include "Utils.h"
//static function


string Utils::reverseStr(string str) {
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }

    return str;
}
//todo:: delete class?
//todo:: i cant take this desicion