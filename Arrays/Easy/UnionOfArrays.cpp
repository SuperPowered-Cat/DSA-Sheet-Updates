class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        map <int, int> freq;
        vector <int> un;
        
        for (int i = 0; i < n; i++) freq[arr1[i]]++;
        for (int i = 0; i < m; i++) freq[arr2[i]]++;
        
        for (auto it = freq.begin(); it!=freq.end(); ++it) un.push_back(it->first);
        return un;
        
    }
};
