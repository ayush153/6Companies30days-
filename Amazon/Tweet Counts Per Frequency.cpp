class TweetCounts {
public:
    unordered_map<string, map<int, int>>mp;
    
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
          mp[tweetName][time]++; 
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
	 {
		int chunkSize = freq == "minute" ? 60 : freq == "hour" ? 3600 : 86400;
	    vector<int> counts((endTime - startTime) / chunkSize + 1);
	    map<int, int>& timeCount = mp[tweetName];
	    auto lo = timeCount.lower_bound(startTime);
        auto hi = timeCount.upper_bound(endTime);

	    for (auto it = lo; it != hi; it++)
	    {
	      int index = (it->first - startTime) / chunkSize;
	      counts[index] += it->second;
	    }

    return counts; 
    }
};
