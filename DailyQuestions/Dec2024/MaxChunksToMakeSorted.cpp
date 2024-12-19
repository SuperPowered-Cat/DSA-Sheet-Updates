// leetcode 769

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // all elements of the array are unique
        // so in sorted array a[i] = i i.e. we know all elements of the array

        // now we can create a prefix sum arrayy for the same
        vector<int> psum(arr.size(), 0);
        psum[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) psum[i] = arr[i] + psum[i-1];

        // sum of upto n natural numbers is n*(n+1)/2 
        // so for the prefix sum if for any index i sum = i*(i+1)/2 
        // then it is the last element so now we take a partition

        // total partitions = number of times psum[i] = i*(i+1)/2

        int maxchunk = 0;
        for (int i = 0; i < psum.size(); i++) if(psum[i] == i*(i+1)/2) maxchunk++;

        return maxchunk;
    }
};
