class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;

        stringstream ss(preorder);
        string node;

        while (getline(ss, node, ',')) {
            // No slot available for this node
            if (slots == 0)
                return false;

            if (node == "#") {
                // Null node uses one slot
                slots--;
            }
            else {
                // Non-null node uses one slot
                // and creates two new slots
                slots = slots - 1 + 2;
            }
        }

        return slots == 0;
    }
};


