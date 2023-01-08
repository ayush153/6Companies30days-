class Solution {
public:
     int helper(int n)
     {
        return n*(n-1);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
         int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<int,int>mp;
            for(int j = 0; j < n; j++)
            {
                int dist = pow(points[i][0]-points[j][0],2) + pow(points[i][1]-points[j]                    [1],2);
                mp[dist]++;
            }
            for(auto it:mp) 
                ans += helper(it.second); 
        }
        return ans;
    }
};