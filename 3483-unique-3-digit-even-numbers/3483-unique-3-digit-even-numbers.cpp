class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        unordered_set<int> s;
        for(int i=0; i<digits.size(); i++) {
            for(int j=0; j<digits.size(); j++) {
                for(int k=0; k<digits.size(); k++) {
 
                    if(i == j || j == k || k == i) continue;

                    if(digits[k]%2 == 0) {
                        int num = digits[i] * 100 + digits[j]*10 + digits[k];
                        s.insert(num);
                    }
                }
            }
        }

        return s.size();
    }
};