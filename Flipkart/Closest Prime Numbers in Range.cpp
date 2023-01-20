class Solution {
public:
    vector<int> primeNum(int left,int n){
    vector<bool> prime(n+1,1);
        prime[0] = 0 ;
        prime[1] = 0;
        for(int i = 2 ; i*i <= n ; i++) 
        {
            if(prime[i]) 
            {
                for(int j = i*i ; j <= n ; j+=i) 
                {
                    prime[j] = 0;
                }
            }
        }
        
        vector<int> ans;
        for(int i = left ; i <= n ; i++) 
        {
            if(prime[i])
                ans.push_back(i);
        }
        return ans;   
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = primeNum(left,right) ;
        int miny = INT_MAX;
        vector<int> res(2);
        if(ans.size() < 2 )
        {
            return {-1,-1};
        }
        for(int i = 0 ; i < ans.size()-1 ;i++)
        {
            if((ans[i+1] - ans[i]) < miny) 
            {
                res[0] = ans[i];
                res[1] = ans[i+1];
                miny = ans[i+1] - ans[i];
            }
        }
        return res;
    }
};