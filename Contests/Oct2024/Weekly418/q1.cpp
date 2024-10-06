class Solution {
public:
    static bool custom(const string& a, const string& b) {
        return a + b > b + a;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector <string> strNum;
        for (int x : nums) {
            string bin = bitset<7>(x).to_string();
            strNum.push_back(bin.substr(bin.find('1')));
        }

        sort(strNum.begin(), strNum.end(), custom);

        string ansStr = "";
        for (const auto& str : strNum) 
            ansStr+=str.substr(str.find('1'));
        
        long long ans = stoll(ansStr, 0, 2);
        return ans;
    }
};
