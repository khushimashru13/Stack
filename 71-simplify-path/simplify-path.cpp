class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string current = "";

        for (int i = 0; i <= path.length(); i++) {

            // Process directory when '/' or end is reached
            if (i == path.length() || path[i] == '/') {

                if (current == "..") {
                    // Go to parent directory
                    if (!stack.empty()) {
                        stack.pop_back();
                    }
                }
                else if (!current.empty() && current != ".") {
                    // Valid directory name
                    stack.push_back(current);
                }

                // Reset current directory name
                current = "";
            }
            else {
                current += path[i];
            }
        }

        // Build the simplified path
        string result = "";

        for (string dir : stack) {
            result += "/" + dir;
        }

        // If root directory
        if (result.empty()) {
            return "/";
        }

        return result;
    }
};