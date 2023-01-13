class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32), dp0(32), dp1(32);
        dp0[0] = dp[0] = 1;
        for (int i = 1; i < 32; i++)
        {
            dp1[i] = dp0[i-1];
            dp0[i] = dp0[i-1] + dp1[i-1];
            dp[i] = dp0[i] + dp1[i];
        }
        int ans = 0, lastBit = -1;
        for (int j = 30; j >= 0; j--)
        {
            int bit = (n >> j) & 1;
            if (bit == 1) 
            {
                ans += dp[j];
                if (lastBit == 1) 
                    return ans; 
            }
            lastBit = bit;
        }
        return ans + 1; 
    }
};