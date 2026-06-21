class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while (columnNumber > 0) {
            columnNumber--;
            int offset = columnNumber % 26;
            res = (char)('A' + offset) + res;
            columnNumber /= 26;
        }
        ;
        return res;
    }
};