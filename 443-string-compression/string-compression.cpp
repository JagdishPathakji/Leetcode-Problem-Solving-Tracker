class Solution {
public:
    int compress(vector<char>& v) {
        
    	char prev = v[0];
	    int count = 1;

        vector<char> ans;
        int n = v.size();
        for(int i=1; i<n; i++) {
            if(prev != v[i]) {
                if(count == 1) {
                    ans.push_back(prev);
                }
                else {
                    ans.push_back(prev);
                    vector<int> temp;
                    while(count) {
                        int p = count % 10;
                        count /= 10;
                        temp.push_back(p);
                    }
                    reverse(temp.begin(),temp.end());
                    for(int i=0; i<temp.size(); i++)
                    ans.push_back(temp[i]+'0');
                }

                count = 1;
                prev = v[i];
            }
            else {
                count++;
            }
        }

        if(count == 1) {
            ans.push_back(prev);
        }
        else {
            vector<int> temp;
            ans.push_back(prev);
            while(count) {
                int p = count % 10;
                count /= 10;
                temp.push_back(p);
            }
            reverse(temp.begin(),temp.end());
            for(int i=0; i<temp.size(); i++) {
                ans.push_back(temp[i]+'0');
            }
        }

        v = ans;

        return ans.size();

    }
};