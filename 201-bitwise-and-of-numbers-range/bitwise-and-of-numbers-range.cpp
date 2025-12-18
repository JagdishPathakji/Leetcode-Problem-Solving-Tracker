class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       
        // O(n) but TLE    
        // long long int ans = 0;

        // for(int i=0; i<64; i++) {
        //     bool zerofound = false;
        //     for(long long int j=left; j<=right; j++) {
        //         long long int num = j;
        //         long long int bit = (num >> i) & 1;

        //         if(bit == 0) {
        //             zerofound = true;
        //             break;
        //         }
        //     }

        //     if(!zerofound) {
        //         ans = ans | (1 << i);
        //     }
        // }

        // return ans;

        int shift = 0;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            shift++;
        }

        return left << shift;
        // or right << shift;
    }
};