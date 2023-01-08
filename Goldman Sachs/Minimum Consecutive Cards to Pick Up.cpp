class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mp;
        int n = cards.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
             if (mp[cards[i]])
            {
                ans = min(i - mp[cards[i]] + 2, ans);
            }
            
            mp[cards[i]] = i + 1;
        }
        if(ans !=INT_MAX)
            return ans;
        else
            return -1;
    }
};