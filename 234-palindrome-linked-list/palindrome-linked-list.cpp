class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For odd length, skip the middle node
        if (fast != nullptr)
            slow = slow->next;

        // Reverse second half
        ListNode* prev = nullptr;

        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Compare first half and reversed second half
        ListNode* left = head;
        ListNode* right = prev;

        while (right != nullptr) {
            if (left->val != right->val)
                return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};
