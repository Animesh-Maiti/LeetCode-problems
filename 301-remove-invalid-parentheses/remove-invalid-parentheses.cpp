class Solution {
public:
    bool isValid(string s) {
        int count = 0;

        for (char c : s) {
            if (c == '(') {
                count++;
            }
            else if (c == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (isValid(current)) {
                ans.push_back(current);
                found = true;
            }

            // If a valid string is found at this level,
            // don't generate strings with more removals.
            if (found)
                continue;

            for (int i = 0; i < current.size(); i++) {
                // Only remove parentheses
                if (current[i] != '(' && current[i] != ')')
                    continue;

                string next = current.substr(0, i) + current.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};