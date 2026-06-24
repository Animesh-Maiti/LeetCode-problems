class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=0,maxsum=nums[0];
        for(int val: nums){
            currentsum+=val;
            maxsum=max(currentsum,maxsum);
            if(currentsum<0){
                currentsum = 0;
            }

        }
        return maxsum;
        
    }
};