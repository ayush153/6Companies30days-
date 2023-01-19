class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        vector<int> cnt(128);

        for (const char c : s)
          cnt[c]++;

        for (const char c : order)
        {
          while (cnt[c]-- > 0)
          {
            ans += c;
          }
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
          while (cnt[c]-- > 0)
          {
            ans += c;
          }
        }

        return ans;
    }
};