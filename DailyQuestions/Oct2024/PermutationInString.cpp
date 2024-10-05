class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int p = s1.size();
        int q = s2.size();
        if (p>q) return 0;
        vector<int> s1Freq(26, 0);
        vector<int> window(26, 0);
        for (auto& x : s1) s1Freq[x-'a']++; // initialise frequency of the s1 array
        for (int i = 0; i < p; i++) window[s2[i] - 'a']++; //first p elements in window
        for (int i = 0; i < q-p; i++) {
            if (s1Freq == window) return true;
            if (i + p < q){
                window[s2[i]-'a']--;
                window[s2[i + p] - 'a']++;
            }
        }
        return s1Freq == window;
    }
};
