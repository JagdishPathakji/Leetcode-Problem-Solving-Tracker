class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int Xor = (start ^ goal);
        int count = 0;
        while(Xor != 0) {
            Xor = (Xor & (Xor-1));
            count++;
        }

        return count;
    }
};