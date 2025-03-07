class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> v;

        if(left == 1 and right == 1)
        return {-1,-1};

        while (left <= right) {
            bool check = true;
            if (left == 1) {  // 1 is not prime, skip it
                left++;
                continue;
            }

            for (int i = 2; i * i <= left; i++) {  // Fixed condition
                if (left % i == 0) {
                    check = false;
                    break;  // Stop early if not prime
                }
            }
            if (check) v.push_back(left);
            left++;
        }

        if(v.size() == 0) return {-1,-1};
        
        int a = -1, b = -1;
        int ans = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            if (ans > v[i + 1] - v[i]) {
                ans = v[i + 1] - v[i];
                a = v[i];
                b = v[i + 1];
            }
        }

        return {a, b};
    }

};