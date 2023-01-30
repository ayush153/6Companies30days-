class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(),asteroids.end());
        
        for(int i = 0; i < asteroids.size(); i++)
        {
            long long astMass = asteroids[i];
            
            if(astMass > mass) 
                return false; 
            mass += astMass;
            if(mass < 0) 
                return true;     
        }
        return true;
    }
};