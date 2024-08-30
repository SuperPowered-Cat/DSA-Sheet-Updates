class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> leader;
        
        // bruteforce approach - comparing two times
        // for (int i = 0; i < n; i++) {
        //     int test = 0;
        //     for (int j = i+1; j<n; j++) {
        //         if (arr[i] < arr[j]) test++;
        //     }
        //     if (test == 0) leader.push_back(arr[i]);
        // }
        
        // optimal approach, continuing from the right
        int max = arr[n-1];
        leader.push_back(max);
        for (int i = n-2; i >=0; i--) {
            if (arr[i] >= max) {
                max = arr[i];
                leader.push_back(arr[i]);
                
            }
        }
        reverse(leader.begin(), leader.end()); //output wants desc. order
        return leader;
    }
};
