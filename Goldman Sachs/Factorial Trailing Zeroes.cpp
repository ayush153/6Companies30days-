class Solution {
public:
    int trailingZeroes(int n) {
    	 int ans = 0;
        for(int i = 5; i <= n; i*=5) 
        {
            ans = ans + (n/i);
        }
        return ans;
//        if(n < 5) return 0;
//        else
//            return n/5 + trailingZeroes(n/5);
    }
};
