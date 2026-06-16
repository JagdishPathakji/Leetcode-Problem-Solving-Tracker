class Solution {
public:
    bool canAliceWin(vector<int>& v) {
        
        int one = 0;
        int two = 0;
        int n = v.size();

        for(int i=0; i<n; i++) {
            if(v[i] < 10) {
                one += v[i];
            }
            else {
                two += v[i];
            }
        }

        return one != two;
  
    }
};