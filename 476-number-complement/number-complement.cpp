class Solution {
public:
    int findComplement(int n) {
        
        int temp = n;
        int mask = 0;
        while(temp) {
            mask = ((mask << 1) | 1);
            temp = temp >> 1;
        }

        return (mask ^ n);
    }
};