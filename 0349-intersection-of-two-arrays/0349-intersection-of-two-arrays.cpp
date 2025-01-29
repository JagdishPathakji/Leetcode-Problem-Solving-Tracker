class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v1(1001,0);
        vector<int> v2(1001,0);

        for(int i=0; i<nums1.size(); i++) {
            v1[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++) {
            v2[nums2[i]]++;
        }

        vector<int> v;
        for(int i=0; i<1001; i++) {
            if(v1[i] > 0 and v2[i] > 0) {
                v.push_back(i);
            }
        }

        return v;
    }
};