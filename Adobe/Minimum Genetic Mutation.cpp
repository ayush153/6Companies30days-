class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
         int cnt = 0;
        set <string> s;
        queue<string>q;
        q.push(startGene);
        s.insert(startGene);
        while(q.empty() == NULL)
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                string node = q.front();
                q.pop();
                
                if(node == endGene)
                    return cnt;
                
                for(char ch : "ACGT")
                {
                    for(int j = 0; j < node.size(); j++)
                    {
                        string adjacentNode = node;
                        adjacentNode[j] = ch;
                        if(s.count(adjacentNode) == NULL && find(bank.begin(), bank.end(), adjacentNode) != bank.end())
                        {
                            q.push(adjacentNode);
                            s.insert(adjacentNode);
                        }
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};