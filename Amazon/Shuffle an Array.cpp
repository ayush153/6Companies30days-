class Solution {
public:
    vector<int> ans;
    int n;
    Solution(vector<int>& nums) {
        ans = nums;
        n = ans.size();
    }
    
    vector<int> reset() {
        return ans;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = ans;
        int leftsize = n;
        for (int i = n - 1; i >= 0; i--)
        {
            int j = rand() % leftsize;
            swap(shuffled[i], shuffled[j]);
            leftsize--;
        }
        return shuffled;
    }
};