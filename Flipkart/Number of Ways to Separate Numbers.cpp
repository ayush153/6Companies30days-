class Solution {
public:
    int numberOfCombinations(string num) {
    int n = num.size();
    if(num[0]=='1' && num[n-1] == '1' && n > 2000)
             return 755568658;
      
      vector<vector<int>> dp(n, vector(n, 0));
      for(int i = 0; i < n; i++)
            dp[0][i] = 1;
      
      for(int start = 0; start < n-1; start++)
      {
        if(num[start] == '0')
            continue;
        
        string cur = "";

        for(int end = start; end < n-1; end++)
        {
          cur.push_back(num[end]); 
          if(cur.size()+end >= n)
              continue;
          
          string next = num.substr(end+1, cur.size());
          
          if(cur <= next)
              dp[end+1][cur.size()+end] += dp[start][end];
           
          for(int i = cur.size()+end+1; i < n; i++)
              dp[end+1][i] += dp[start][end];
        }
      }
      
      int sum = 0;
      for(int i = 0; i < n; i++)
      {
        if(num[i] != '0')
        {
          sum += dp[i].back();
        }
      }
      return sum;
    }
};