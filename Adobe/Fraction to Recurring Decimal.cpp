class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
         if (!numerator)
            return "0";
		string str = numerator < 0 ^ denominator < 0 ? "-" : "";
        numerator = abs(numerator);
        denominator = abs(denominator);
        str += to_string(numerator / denominator);
        long long remainder = numerator % denominator;
        if (!remainder)
            return str;
		str += '.';
        unordered_map<int, int> mp;
		int n = str.size();
        while (remainder && mp.find(remainder) == mp.end())
        {
            mp[remainder] = n++;
            str += '0' + remainder * 10 / denominator;
            remainder = remainder * 10 % denominator;
        }
        if (remainder) {
            str += ')';
            str.insert(str.begin() + mp[remainder], '(');
        }
        return str;
    }
};