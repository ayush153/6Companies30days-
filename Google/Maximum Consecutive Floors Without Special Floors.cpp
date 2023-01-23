class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxy = max(special[0] - bottom,top-special.back());
        for(int i = 1; i < special.size(); i++) 
        {
            maxy = max(maxy, special[i] - special[i-1] - 1);
        }
        return maxy;
    }
};