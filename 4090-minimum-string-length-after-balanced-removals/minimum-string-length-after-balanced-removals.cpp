#include <string>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int minLengthAfterRemovals(std::string s) {
        int count_a = 0;
        int count_b = 0;

        for (char c : s) {
            if (c == 'a') {
                count_a++;
            } else {
                count_b++;
            }
        }

        return std::abs(count_a - count_b);
    }
};