class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9+7;
        vector<long> ans(n+1,1);    
        ans[0] = 0;  
        for(int i = 1; i <= n; i++)
        {
            for(int j = delay; j < forget; j++) 
            {
                if(i-j >= 0)
                {
                    ans[i] = (ans[i] + ans[i-j]) % mod; 
                }
            }
        }
        return (ans[n] - ans[n-forget] + mod) % mod; 
    }
};