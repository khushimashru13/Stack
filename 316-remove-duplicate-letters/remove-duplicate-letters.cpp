class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        vector<int> freq(26, 0);
        vector<bool> used(26, false);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : s) {
            freq[c - 'a']--;

            // If already present in stack, skip it
            if (used[c - 'a'])
                continue;

            // Remove bigger characters if they appear again later
            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {
                
                used[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            used[c - 'a'] = true;
        }

        // Convert stack to string
        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};