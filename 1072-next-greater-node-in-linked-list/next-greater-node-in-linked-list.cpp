/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // Step 1: Convert the linked list into a vector for easy indexed access
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> ans(n, 0);
        stack<int> st; // Stores indices of nodes

        // Step 2: Iterate through the values using a monotonic stack
        for (int i = 0; i < n; ++i) {
            // While current value is strictly greater than the value at stack's top index
            while (!st.empty() && values[i] > values[st.top()]) {
                ans[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};