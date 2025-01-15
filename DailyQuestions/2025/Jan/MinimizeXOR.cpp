// leetcode 2429
// https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // using builtin function to find out set bits
        int setbit1 = __builtin_popcount(num1); // setbits of num1
        int setbit2 =  __builtin_popcount(num2); // setbits of num2
        
        // case 1: set bits are the same
        if (setbit1 == setbit2) return num1;

        // otherwise, converting num1 to num1b for binary changing
        string num1b = bitset<32>(num1).to_string(); // num1 binary str

        // case 2: setbit2 is more : need to increase setbit1 bits
        if (setbit2 > setbit1) {
            int diff = setbit2-setbit1;
            for (int i = 31; i >= 0 && diff>0; i--) { // moving  R to L
            // this is because right side are least significant bits
            // making them 1 will not increase the value by a lot
            // thus making minimum xor
                if (num1b[i] == '0') { // if 0 found conver to 1 
                    num1b[i] = '1';
                    diff--; // dicrementing diff to keep tab of how much
                }
            }
        }

        // case 3: setbit1 is more: vice versa, decreasing setbits1
        else {
            int diff = setbit1-setbit2;
            for (int i = 31; i >= 0 && diff>0; i--) {
                if (num1b[i] == '1') { // moving from R to L
                // by increasing from  right, increase wont be as much
                // same logic as the last loop
                    num1b[i] = '0';
                    diff--;
                }
            }
        }

        return stoi(num1b, nullptr, 2); // returning stoi (string to int)
        // stoi func has parameters string, size_t* pos, and base
        // so keep 2nd parameter as null, and base as 2 to convert to int
    }

    
};
