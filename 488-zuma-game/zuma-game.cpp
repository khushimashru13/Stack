#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    unordered_map<string, int> memo;

    // Helper function to remove consecutive groups of 3 or more identical balls
    string clean(string s) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < (int)s.length(); ) {
                int j = i;
                while (j < (int)s.length() && s[j] == s[i]) {
                    j++;
                }
                if (j - i >= 3) {
                    s = s.substr(0, i) + s.substr(j);
                    changed = true;
                    break;
                }
                i = j;
            }
        }
        return s;
    }

    int dfs(string board, string hand) {
        board = clean(board);
        if (board.empty()) return 0;
        if (hand.empty()) return INT_MAX;

        string stateKey = board + "#" + hand;
        if (memo.count(stateKey)) return memo[stateKey];

        int minSteps = INT_MAX;

        for (int i = 0; i <= (int)board.length(); ++i) {
            for (int j = 0; j < (int)hand.length(); ++j) {
                // Skip duplicate consecutive hand characters to avoid redundant states
                if (j > 0 && hand[j] == hand[j - 1]) continue;

                char c = hand[j];

                // Pruning heuristic: Only insert if it matches the current ball
                // or sits between two different adjacent balls
                bool shouldInsert = false;
                if (i < (int)board.length() && board[i] == c) {
                    shouldInsert = true;
                } else if (i > 0 && i < (int)board.length() && board[i - 1] == board[i] && board[i] != c) {
                    shouldInsert = true;
                }

                if (!shouldInsert) continue;

                string nextBoard = board.substr(0, i) + c + board.substr(i);
                string nextHand = hand.substr(0, j) + hand.substr(j + 1);

                int res = dfs(nextBoard, nextHand);
                if (res != INT_MAX) {
                    minSteps = min(minSteps, 1 + res);
                }
            }
        }

        return memo[stateKey] = minSteps;
    }

public:
    int findMinStep(string board, string hand) {
        // Sort hand so identical characters are adjacent for easier deduplication
        sort(hand.begin(), hand.end());
        int ans = dfs(board, hand);
        return ans == INT_MAX ? -1 : ans;
    }
};