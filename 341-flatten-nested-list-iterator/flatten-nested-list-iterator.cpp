class NestedIterator {
public:
    stack<NestedInteger> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int value = st.top().getInteger();
        st.pop();
        return value;
    }

    bool hasNext() {
        while (!st.empty()) {

            if (st.top().isInteger()) {
                return true;
            }

            vector<NestedInteger> list = st.top().getList();
            st.pop();

            // Push in reverse order
            for (int i = list.size() - 1; i >= 0; i--) {
                st.push(list[i]);
            }
        }

        return false;
    }
};