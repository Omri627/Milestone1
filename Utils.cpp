//
// Created by omri on 19/12/18.
//

#include "Utils.h"

string Utils::reverseStr(string str) {
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }

    return str;
}