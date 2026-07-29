class Solution {
public:
    const long long LIMIT = 1000001;

    long long countPermutations(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ways = 1;
        int used = 0;

        for (int c : cnt) {
            for (int i = 1; i <= c; i++) {
                ways = ways * (used + i) / i;
                if (ways > LIMIT) ways = LIMIT;
            }
            used += c;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countPermutations(half) < k)
            return "";

        int len = s.size() / 2;
        string left;

        for (int pos = 0; pos < len; pos++) {
            for (int ch = 0; ch < 26; ch++) {
                if (half[ch] == 0) continue;

                half[ch]--;
                long long ways = countPermutations(half);

                if (ways >= k) {
                    left.push_back(char('a' + ch));
                    break;
                } else {
                    k -= ways;
                    half[ch]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};