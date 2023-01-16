class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        if (k > s.length())
            return false;

        for (int i = 0; i <= s.size()-k; i++)
        {
            st.insert(s.substr(i, k));
        }

        return st.size() == pow(2, k);
    }
};