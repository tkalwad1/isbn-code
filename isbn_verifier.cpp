#include "isbn_verifier.h"
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

namespace isbn_verifier {
#include "isbn_verifier.h"
#include <string>
#include <iostream>

using namespace std;

namespace isbn_verifier {
    bool is_valid(string isbn) {
        // check validity of string
        // check for length
        int size = isbn.size();
        if (!(size ==10 || size == 13)) {
            return false;
        }

        // check for non-allowed-characters
        
        for(int i = 0; i<size; i++) {
            if (!((isbn[i] >= '0' && isbn[i] <= '9') || isbn[i] == 'X' || isbn[i] == '-')) {
                return false;
            }
        }

        // apply formula for each character of string and return true/false
        int multiplier = 10;
        int value = 0;
        for (int i=0; i<size; i++) {
            if (isbn[i] == '-') {
                continue; // ignore dashes
            }

            if (isbn[i] == 'X') {
                value = value + 10;
            } else {
                value = value + (isbn[i] - '0') * multiplier;
            }
            multiplier = multiplier - 1;
        }

        return (value % 11 == 0);
    }
}  // namespace isbn_verifier
