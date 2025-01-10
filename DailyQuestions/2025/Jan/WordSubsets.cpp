// leetcode 916
// https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char, int> maxfreq;

        // storing maxfrequency of all characters of words2 bucket
        for(auto str : words2) {
            map<char, int> tempmap;
            for (int i = 0; i < str.size(); i++) {
                tempmap[str[i]]++;
                if(maxfreq.find(str[i]) == maxfreq.end()) maxfreq[str[i]]++;
                else maxfreq[str[i]] = max(maxfreq[str[i]], tempmap[str[i]]);
            }
            
        }

        vector<string> ans;
        
        // now checking for each buckets individual element, whether 
        // the max frequency is fulfilled
        for (auto str: words1) {
            map<char, int> indivmap;

            // first setting an individual frequency map
            for(int i = 0; i < str.size(); i++) {
                indivmap[str[i]]++;
            }
            
            bool valid = true;
            for (auto [key, value] : maxfreq) {
                if (valid == false) break;
                if (indivmap.find(key) != indivmap.end()) {
                    if(indivmap[key]>=maxfreq[key]) valid = true;
                    else valid = false;
                }
                else valid = false;
            }
            if (valid == true) ans.push_back(str);
        }
        return ans;
    }
};
