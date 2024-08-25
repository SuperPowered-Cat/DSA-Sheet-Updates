//User function Template for C++

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        if (n<1) return 0;
        if (n<2) return arr[0];
        mergeSort(arr, 0, n-1);
        return arr.back();
    }
private:
    void mergeSort(vector <int> &A, int l, int r) {
        if (l<r) {
            int m = (l+r)/2;
            mergeSort(A, l, m);
            mergeSort(A, m+1, r);
            merge(A, l, m, r);
        }
    }
private:
    void merge(vector <int> &A, int l, int m, int r) {
        int n1 = m-l+1;
        int n2 = r - m;
        int L[n1+1];
        int R[n2+1];
        for (int i = 0; i<n1; i++)
            L[i] = A[l+i];
        for (int j = 0; j<n2; j++)
            R[j] = A[m+1+j];
        L[n1] = INT_MAX;
        R[n2] = INT_MAX;
        int i = 0, j = 0;
        for (int k = l; k<=r; k++) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            }
            else {
                A[k] = R[j];
                j++;
            }
        }
    }
};
