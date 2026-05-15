class Solution {
public:
    int findMin(vector<int>& nums) {

        long long n = nums.size();
        long long low = 0;
        long long high = n - 1;
        long long mid = -1;
    
        if(n == 1)
        {
            return nums[0];
        }

        while(low <= high)
        {
            mid = low + (high - low)/2;

            //Base case condition first.mid reaches at either of the corners.
            
            if(mid == 0 && nums[mid] < nums[mid+1])
            {
                return nums[mid];//nums[0]
            }

            else if(mid == n-1 && nums[mid-1] > nums[mid])
            {
                return nums[mid];//nums[n-1]
            }   

            //At any intermediate position.         

            else if(mid -1 >=0  && mid + 1  <= n-1 && nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
            {
                return nums[mid];
            }

            else if(nums[mid] < nums[high])
            {
                high = mid - 1;
            }

            else 
            {
                low  = mid + 1;
            }

        }

        return -1;   
        
        //TC:O(logn)
    }
};