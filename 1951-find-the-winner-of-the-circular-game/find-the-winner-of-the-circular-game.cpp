class Solution {
public:
    int findTheWinner(int n, int k) {
        
        int i = 0;
        vector<bool> visited(n,false);
        int count = 0;

        while(count != n-1) {

            while(visited[i]) {
                i = (i + 1) % n;
            }

            int step = 0;
            while(step < k) {
                if(!visited[i]) {
                    step++;
                }
                if(step == k) break;
                i = (i + 1) % n;
            }
            
            visited[i] = true;
            i = (i + 1) % n;
            count++;
        }

        for(int i=0; i<n; i++) {
            if(!visited[i])
            return i+1;
        }

        return -1;
    }
};