// **Q: To check if 2 chessboard boxes have the same colour or not**

// You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.

// Return true if these two squares have the same color and false otherwise.

// The coordinate will always represent a valid chessboard square. The coordinate will always have the letter 
// first (indicating its column), and the number second (indicating its row).

// Example 1:
// Input: coordinate1 = "a1", coordinate2 = "c3"
// Output: true
// Explanation:
// Both squares are black.

// Example 2:
// Input: coordinate1 = "a1", coordinate2 = "h3"
// Output: false
// Explanation:
// Square "a1" is black and "h3" is white.

// Constraints:
// coordinate1.length == coordinate2.length == 2
// 'a' <= coordinate1[0], coordinate2[0] <= 'h'
// '1' <= coordinate1[1], coordinate2[1] <= '8'

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        coordinate1[0] = trans(coordinate1[0]);
        coordinate2[0] = trans(coordinate2[0]);

        int cord1sum = (coordinate1[0]-'0') + (coordinate1[1] - '0');
        int cord2sum = (coordinate2[0]-'0') + (coordinate2[1] - '0');

        int check1 = cord1sum%2;
        int check2 = cord2sum%2;
        if (check1 == check2) return true;
        return false;
    }

    char trans(char x) {
        if (x == 'a') return '1';
        else if (x == 'b') return '2';
        else if (x == 'c') return '3';
        else if (x == 'd') return '4';
        else if (x == 'e') return '5';
        else if (x == 'f') return '6';
        else if (x == 'g') return '7';
        else return '8';
    }
};
