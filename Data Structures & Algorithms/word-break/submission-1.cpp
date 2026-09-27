class Solution {
public:
    unordered_set<string> dict;
    vector<int> dp;

    bool solve(string& s, int i) {
        if (i == s.size())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for (int j = i; j < s.size(); j++) {
            string word = s.substr(i, j - i + 1);

            if (dict.count(word) && solve(s, j + 1))
                return dp[i] = 1;
        }

        return dp[i] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict)
            dict.insert(word);

        dp.assign(s.size(), -1);
        return solve(s, 0);
    }
};