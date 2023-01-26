class Solution {
public:
    vector<int> v;
    Solution(vector<int>& w) {
       v.push_back(w[0]);
       for(int i = 1 ; i < w.size() ;i++) 
           v.push_back(v.back()+w[i]);
}
    
    int pickIndex() {
        int num = rand() % (v.back());
        return upper_bound(v.begin(),v.end(),num) - v.begin();
    }
};