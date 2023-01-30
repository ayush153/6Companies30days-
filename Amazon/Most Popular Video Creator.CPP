class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, long long> m;
        unordered_map<string, pair<int, string>> mp;
        long long maxy = INT_MIN;
        for(int i = 0; i < creators.size(); i++)
        {
            long long v = views[i];
            if(m.find(creators[i]) == m.end())
                m[creators[i]] = v; 
            else 
                m[creators[i]] += v;
            
            if(maxy < m[creators[i]])
                maxy = m[creators[i]];
            
            if(mp.find(creators[i]) == mp.end())   
                mp[creators[i]] = {views[i], ids[i]};
            else
            {                                                                       
			    //Evaluate max view for each creator
                if( mp[creators[i]].first < views[i])                                    
					  mp[creators[i]] = {views[i], ids[i]};
                else if(mp[creators[i]].first == views[i] && mp[creators[i]].second > ids[i])
                {
                    mp[creators[i]] = {views[i], ids[i]};
                }
            }
        }
        
        vector<vector<string>> ans;
        for(auto i: m)
        {   
            //scan for the creators equal to max
            if(maxy == i.second)
            {
                ans.push_back({i.first, mp[i.first].second});
            }
        }
        return ans;
    }
};
