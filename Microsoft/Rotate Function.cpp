class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int sum = 0;
       int ans = 0;
       int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            ans += i*nums[i];
        }
        
        int maxy = ans;
       
        for(int i = n-1; i >= 0; i--)
        {
            ans += sum -(nums[i]*n);
            maxy = max(maxy,ans);
        }
        return maxy;
    }
};
