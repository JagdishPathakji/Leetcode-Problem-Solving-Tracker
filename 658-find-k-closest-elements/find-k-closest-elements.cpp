class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<arr.size(); i++) {
            if(pq.size() < k) {
                pq.push({abs(arr[i]-x),arr[i]});
            }
            else {
                if(pq.top().first > abs(arr[i]-x)) {
                    pq.pop();
                    pq.push({abs(arr[i]-x),arr[i]});
                }
                else if(pq.top().first == abs(arr[i]-x)) {
                    if(arr[i] < pq.top().second) {
                        pq.pop();
                        pq.push({abs(arr[i]-x),arr[i]});
                    }
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};