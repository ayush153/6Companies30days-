class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, double>>>mp;
public:
    double knightProbability(int n, int k, int row, int column) 
    {
        if(mp.count(row) && mp[row].count(column) && mp[row][column].count(k)) 
                return mp[row][column][k];
        if(row < 0 || row >= n || column < 0 || column >= n) 
            return 0;
        if(k == 0) 
            return 1;
        double total = knightProbability(n, k - 1, row - 1, column - 2) + knightProbability(n, k - 1, row - 2, column - 1) 
                     + knightProbability(n, k - 1, row - 1, column + 2) + knightProbability(n, k - 1, row - 2, column + 1) 
                     + knightProbability(n, k - 1, row + 1, column + 2) + knightProbability(n, k - 1, row + 2, column + 1) 
                     + knightProbability(n, k - 1, row + 1, column - 2) + knightProbability(n, k - 1, row + 2, column - 1);
        double ans = total / 8;
        mp[row][column][k] = ans;
        return ans;
    }
};