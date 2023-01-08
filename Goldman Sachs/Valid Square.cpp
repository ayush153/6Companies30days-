class Solution {
public:
     double distance(vector<int> &x, vector<int> &y)
    {
        return (pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         vector<double> v;
        v.push_back(distance(p1,p2)); 
        v.push_back(distance(p1,p3));
        v.push_back(distance(p1,p4));
        v.push_back(distance(p2,p3));
        v.push_back(distance(p2,p4));
        v.push_back(distance(p3,p4));
         sort(v.begin(), v.end());
        if(v[0] > 0 && v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && 
           v[4] == v[5] && 2*v[2] == v[4] ) 
        {
            return true;
        }
        return false;
    }
};