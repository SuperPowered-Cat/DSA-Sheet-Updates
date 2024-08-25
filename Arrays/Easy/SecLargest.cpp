// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int n = arr.size();
        if (n<2) return -1;
        int large = INT_MIN;
        int secLarge = INT_MIN;
        for (int i = 0; i<n; i++) {
            if (arr[i] > large){
                secLarge = large;
                large = arr[i];
            }
            else if (arr[i] >= secLarge && arr[i] != large) secLarge = arr[i];
        }
        if (secLarge == INT_MIN) return -1;
        return secLarge;
        
    }
};
