class Solution {
    private:
    int countVal(vector<int>&nums,int l,int mid,int h){
          int right=mid+1;
          int cnt=0;
          for(int i=l;i<=mid;i++){
            while(right<=h&&(long long) nums[i]>2LL*nums[right]){
                right++;
            }
            cnt+=(right-(mid+1));
          }
          return cnt;
    }
    void merge(vector<int>&nums,int l,int mid,int h){
        int left=l;
        int right=mid+1;
        vector<int>temp;
        while(left<=mid&&right<=h){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
             temp.push_back(nums[left]);
                left++;
        }
        while(right<=h){
             temp.push_back(nums[right]);
                right++;
        }
        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
    }
    int mergeSort(vector<int>&nums,int l,int h){
        if(l>=h)return 0;
        int mid=l+(h-l)/2;
        int cnt=0;
        cnt+=mergeSort(nums,l,mid);
        cnt+=mergeSort(nums,mid+1,h);
        cnt+=countVal(nums,l,mid,h);
        merge(nums,l,mid,h);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int l=0;
        int h=nums.size()-1;
        int cnt=0;
        cnt+=mergeSort(nums,l,h);
        return cnt;
        
    }
};