class Solution {
    private:
    int subWithKMost(vector<int>&nums,int k){
         int cnt=0;
        int left=0;
        int right=0;
        unordered_map<int,int>mpp;
        while(right<nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()>k&&left<=right){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
            return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return subWithKMost(nums,k)-subWithKMost(nums,k-1);
    }
};