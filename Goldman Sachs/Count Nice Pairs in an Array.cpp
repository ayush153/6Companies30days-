class Solution {
public:
     int reverse(int num)
     {
        int ans=0;
        while(num) 
        {
            int x = num%10;
            num = num/10;
            ans = ans*10+x;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        int mod =  1e9+7;;
        int cnt = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++) 
        {
            cnt=(cnt + mp[nums[i] - reverse(nums[i])]++) % mod;
        }
        return cnt;
    }
};