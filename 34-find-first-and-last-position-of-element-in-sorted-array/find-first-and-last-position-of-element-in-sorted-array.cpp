class Solution {
    private:
    int upperBound(vector<int>&nums,int target){
        int ans=nums.size();
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>target){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
    }
    return ans;
    }

    int lowerBound(vector<int>&nums,int target){
        int ans=nums.size();
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=target){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums.size()==0)return {-1,-1};
        int lb=lowerBound(nums,target);
        int ub=upperBound(nums,target);
        if(lb==n||nums[lb]!=target) return {-1,-1};
        return {lb,ub-1};
    }
};
