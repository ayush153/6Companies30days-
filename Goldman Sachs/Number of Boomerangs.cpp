class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for (auto &p : points) 
        {
            unordered_map<double, int> mp(points.size());
            for (auto &q : points)
                ans += 2 * mp[hypot(p[0] - q[0], p[1] - q[1])]++;
        }
        return ans;
    }
};
