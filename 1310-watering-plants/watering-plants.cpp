class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int n = plants.size();
        int cc = capacity;

        int steps = 0;
        for(int i=0; i<n; i++) {

            if(cc < plants[i]) {
                steps += (2*i)+1;
                cc = capacity;
            }
            else {
                steps++;
            }

            cc -= plants[i];
        }

        return steps;
    }
};