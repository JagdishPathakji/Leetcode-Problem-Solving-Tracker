class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int n = fruits.size();
        vector<bool> marked(n,false);
        vector<bool> fruitsplaced(n,false);
        
        for(int i=0; i<fruits.size(); i++) {
            
            int index = 0;
            while(marked[index] == true) {
                index++;
            }
            for(int j=index; j<fruits.size(); j++) {
                if(baskets[j] >= fruits[i] and marked[j] == false) {
                    marked[j] = true;
                    fruitsplaced[i] = true;
                    break;
                }
            }
        }

        int count = 0;
        
        for(int i=0; i<n; i++) {
            if(fruitsplaced[i] == false)
                count++;
        }

        return count;
    }
};