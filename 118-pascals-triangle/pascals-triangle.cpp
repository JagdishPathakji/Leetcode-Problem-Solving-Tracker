class Solution {
public:
    vector<vector<int>> generate(int N) {

        vector<vector<int>> v(N);

        for(int i=0; i<N; i++) {
            for(int j=0; j<=i; j++) {
                int i1 = i-1;
                int i2 = i-1;

                int j1 = j;
                int j2 = j-1;

                int sum = 0;

                if(i1 >= 0 && i1 < N && j1 >= 0 && j1 < v[i1].size()) {
                    sum += v[i1][j1];
                } 

                if(i2 >= 0 && i2 < N && j2 >= 0 && j2 < v[i2].size()) {
                    sum += v[i2][j2];
                }

                if(sum == 0)
                sum = 1;
                v[i].push_back(sum);
            }
	    }

        return v;
    }
};