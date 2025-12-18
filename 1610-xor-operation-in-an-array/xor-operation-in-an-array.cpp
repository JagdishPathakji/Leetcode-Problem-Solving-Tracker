class Solution {
public:
    int xorOperation(int n, int start) {
        
        int count = 0;
        int Xor = 0;
        for(int i=0; i<n; i++) {
            Xor = (Xor ^ (start+(2*count)));
            count++;
        }
        return Xor;
    }
};