class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    	int miny = INT_MAX;
        for(auto it:right)
        {
            miny = min(miny,it);
        }
        int maxy = INT_MIN;
        for(auto it:left)
        {
            maxy = max(maxy,it);
        }
        return max(n-miny, maxy);
    }
};
