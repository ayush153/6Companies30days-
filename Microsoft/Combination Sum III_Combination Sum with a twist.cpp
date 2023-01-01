class Solution {
public:
    void helper(int k, int n, vector<vector<int>> &ans, vector<int> v, int idx)
    {
        if (k <= 0){
            if (n == 0) ans.push_back(v);
            return;
        }
        for (int i = idx; i <= 9; i++)
        {
            v.push_back(i);
            helper(k - 1, n - i, ans, v, i + 1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> v;
        helper(k,n,ans,v,1);
        return ans;
    }
};