class Solution {
  public:
    void printloop(int N) {
        if (N>0)
        {
            printloop(N-1);
            cout << "DSA ";
        }
    }
};
