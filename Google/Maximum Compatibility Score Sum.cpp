class Solution {
public:
    int helper(int Idx, int m, int n, vector<bool> &taken, vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        int maxy = 0;
        for (int i = 0; i < m; i++)
        {
            if (taken[i] == true)
                continue;
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (students[Idx][j] == mentors[i][j])
                    cnt++;
            }
            taken[i] = true;
            cnt = cnt + helper(Idx + 1, m, n, taken, students, mentors);
            taken[i] = false;
            maxy = max(maxy, cnt);
        }
        return maxy;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = mentors.size();
        int n = students[0].size();
        vector<bool> taken(m, false);
        return helper(0, m, n, taken, students, mentors); 
    }
};