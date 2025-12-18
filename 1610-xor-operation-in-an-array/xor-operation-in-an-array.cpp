class Solution {
public:
    int xorOperation(int n, int start) {
        
        int Xor = 0;
        for(int i=0; i<n; i++) {
            Xor = (Xor ^ (start+(2*i)));
        }
        return Xor;
    }
};