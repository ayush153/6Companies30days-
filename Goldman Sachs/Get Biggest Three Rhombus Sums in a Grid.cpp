class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         set<int> s;
        
        
        for (int i = 1; i <= min(m, n); i += 2)
        {
            for (int j = 0; j + i <= n; j ++)
            {
                for (int k = 0; k + i <= m; k ++)
                {
                    int d = i / 2;
                    if (d == 0)
                    {
                        s.insert(grid[j][k]);
                    }
                    else 
                    {
                        int x = j;
                        int y = k + d;
                        long long sum = 0;
                        for (int w = 0; w < d; w ++)
                            sum += grid[x++][y++];
                       for (int w = 0; w < d; w ++)
                            sum += grid[x++][y--];
                      for (int w = 0; w < d; w ++)
                            sum += grid[x--][y--];
                        for (int w = 0; w < d; w ++)
                            sum += grid[x--][y++];
                        s.insert(sum);
                    }
                }
            }
        }
        
        if (s.size() < 3)
            return vector<int>(s.rbegin(), s.rend());
        
        return vector<int>(s.rbegin(), next(s.rbegin(), 3));
    }
};