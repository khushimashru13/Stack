#include <vector>
#include <stack>

class Solution {
public:
    long long countGoodSubarrays(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left_bound(n), right_bound(n);
        std::stack<int> st;

        // Step 1: Find left boundary for each element as maximum
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            left_bound[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Step 2: Find right boundary for each element as maximum (handling duplicates)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            right_bound[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        // Step 3: Find first invalid index to the left that isn't a submask of nums[i]
        std::vector<int> prev_invalid(n);
        for (int i = 0; i < n; ++i) {
            int prev = i - 1;
            while (prev >= 0 && (nums[prev] | nums[i]) == nums[i]) {
                prev = prev_invalid[prev];
            }
            prev_invalid[i] = prev;
        }

        // Step 4: Find first invalid index to the right that isn't a submask of nums[i]
        std::vector<int> next_invalid(n);
        for (int i = n - 1; i >= 0; --i) {
            int next = i + 1;
            while (next < n && (nums[next] | nums[i]) == nums[i]) {
                next = next_invalid[next];
            }
            next_invalid[i] = next;
        }

        // Step 5: Count good subarrays
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            int L = std::max(left_bound[i], prev_invalid[i] + 1);
            int R = std::min(right_bound[i], next_invalid[i] - 1);

            if (L <= i && i <= R) {
                total += 1LL * (i - L + 1) * (R - i + 1);
            }
        }

        return total;
    }
};