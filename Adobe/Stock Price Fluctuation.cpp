class StockPrice {
public:
    map<int, int> mp;
    multiset<int> s;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
         if (mp.find(timestamp) != mp.end())
         {
            s.erase(s.find(mp[timestamp]));
         }
        mp[timestamp] = price;
        s.insert(price);
    }
    
    int current() {
        return mp.rbegin()->second;
    }
    
    int maximum() {
        return *s.rbegin();
    }
    
    int minimum() {
        return *s.begin();
    }
};
