class Solution {
    private:
    int sumOfKthMost(vector<int>&nums,int goal){
         int sum=0;
        int left=0;
        int right=0;
        int cnt=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal&&left<=right){
                sum-=nums[left];
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return sumOfKthMost(nums,goal)-sumOfKthMost(nums,goal-1);
    }
};