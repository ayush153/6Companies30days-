class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
         vector<string> ans;
        vector<vector<string>> v;
        for (int i = 0; i < transactions.size(); i++)
        {
            string s = "";
            vector<string> vs;
            for (auto it : transactions[i])
            {
                if (it != ',')
                {
                    s += it;
                }
                else
                {
                    vs.push_back(s);
                    s = "";
                }
            }
            vs.push_back(s);
            v.push_back(vs);
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (stoi(v[i][2]) > 1000)
            {
                ans.push_back(transactions[i]);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[i][0] == v[j][0] && v[i][3] != v[j][3])
                {
                    if (abs(stoi(v[i][1]) - stoi(v[j][1])) <= 60 && stoi(v[i][2]) <= 1000)
                    {
                        ans.push_back(transactions[i]);
                        break;
                    }
                }
            }
        }

        return ans;
    }
};