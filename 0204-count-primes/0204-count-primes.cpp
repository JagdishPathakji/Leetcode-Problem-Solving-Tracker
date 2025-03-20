class Solution {
public:
    int countPrimes(int n) {
        
        vector<int> v(n+1,1);

        if(n == 0 or n == 1)
        return 0;

        v[0] = v[1] = 0;

        int count = 0;
        for(int i=2; i<n; i++) {
            if(v[i] == 1) {
                count = count + 1;
                for(int j=2*i; j<n; j+=i) {
                    v[j] = 0;
                }
            }
        }
        

        return count;
    }
};