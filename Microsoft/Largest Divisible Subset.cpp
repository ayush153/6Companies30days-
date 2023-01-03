class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        sort(nums.begin(),nums.end());
         
        int ans = -1, lastIdx = -1;
        for(int i = 0; i < n; i++)
        {
            hash[i] = i;
            for(int j = 0; j < i; j++)
            { 
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i] > ans)
            {
                ans = dp[i];
                lastIdx = i;
            }
        }
        vector<int>path;
        while(hash[lastIdx] != lastIdx)
        {
            path.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        path.push_back(nums[lastIdx]);
        return path;
        
    }
};
