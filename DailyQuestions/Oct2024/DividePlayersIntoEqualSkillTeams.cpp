// leetcode 1491

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long target = skill[0] + skill[skill.size()-1];
        int i = 0;
        int j = skill.size()-1; 
        long long ans = 0;
        while (i<j) {
            long temp = skill[i] + skill[j];
            if (temp != target) return -1;
            else {
                ans= ans + (skill[i]*skill[j]);
                j--;
                i++;
            }
        }
        return ans;

    }
};
