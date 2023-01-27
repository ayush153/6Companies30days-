class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> qR;
        queue<int> qD;

        for (int i = 0; i < n; i++)
          if (senate[i] == 'R')
            qR.push(i);
          else
            qD.push(i);

        while (!qR.empty() && !qD.empty()) 
        {
           int indexR = qR.front();
           qR.pop();
           int indexD = qD.front();
           qD.pop();
            
          if (indexR < indexD)
            qR.push(indexR + n);
          else
            qD.push(indexD + n);
        }
        
        if(qR.empty())
             return "Dire";
        else
            return "Radiant";
    }
};