class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        int cnt = 0;
        long long int sum =0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int m  = matrix[i][j];
                ans = min(ans,abs(m));
                if(m < 0)
                    cnt++;
                sum += abs(m);
            }
        }
        if(cnt % 2 == 0)
            return sum;
        else
            return sum-2*ans;
    }
};