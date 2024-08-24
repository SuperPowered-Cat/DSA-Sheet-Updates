class Solution {
public:
int evenlyDivides(int N){
        int count = 0;
        int temp = N;
        while (temp!= 0) {
            int dig = temp%10;
            temp=temp/10;
            if (dig != 0 && N%dig) count ++;
        }
        return count;
    }
};
