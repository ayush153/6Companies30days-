class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = words.size();
        unordered_map<char,vector<int>> mp;
        int cnt = 0;
        int idx = 0;
        
        for( auto i : s)
            mp[i].push_back(idx++);      
        
        for(int i = 0; i < n; i++)
        {
            string knock = words[i];
            int a = -1;   
            for(int j = 0; j < knock.size(); j++)
            {
                auto it =  upper_bound(mp[knock[j]].begin(),mp[knock[j]].end(),a);
                if(it == mp[knock[j]].end())
                    break;
                a = *it;    
                if(j == knock.size() - 1)   
                    cnt++;
            }
        }
        return cnt;
    }
};