class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> seen;
        
	    for (int k = 1; k <= text.size() / 2; k++) 
	    { 
	          int cnt = 0;
	          for (int l = 0, r = k; r < text.size(); l++, r++)
	          {
	                if (text[l] == text[r])
	                    cnt++;
	                else
	                    cnt = 0;
	                if (cnt == k)
	                {
	                  seen.insert(text.substr(l - k + 1, k));
	                  cnt--;
	                }
	        }
	    }
	
	    return seen.size();
        
    }
};
