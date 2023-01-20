class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> pq;
        if(barcodes.size() == 0 || barcodes.size() == 1) 
        {
            return barcodes;
        }
        unordered_map<int,int> mp;
        for(auto it:barcodes) 
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }

        vector<int> ans;
        while(!pq.empty()) 
        {
            auto b = pq.top();
            pq.pop();
            ans.push_back(b.second);
            if(pq.empty()) break;
            auto c = pq.top();
            pq.pop();
            ans.push_back(c.second);
            if(b.first-1 != 0)
                pq.push({b.first-1,b.second});
            if(c.first-1 != 0)
                pq.push({c.first-1,c.second});
        }
        return ans;
    }
};
