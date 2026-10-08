class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        char op = '+';

        for (int i = 0; i < s.length(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // Process when we find an operator or reach the end
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {

                if (op == '+') {
                    st.push(num);
                }
                else if (op == '-') {
                    st.push(-num);
                }
                else if (op == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                }
                else if (op == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};