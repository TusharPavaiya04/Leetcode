class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=0;
        int el2=1;
        int cnt1=0;
        int cnt2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){            
            if(nums[i]==el1){
                cnt1++;
            }else if(el2==nums[i]){
                cnt2++;
            }else if(el1!=el2&&cnt1==0){
                cnt1=1;
                el1=nums[i];
            }else if(el2!=el1&&cnt2==0){
                cnt2=1;
                el2=nums[i];
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
           for(int i=0;i<nums.size();i++){
            if(nums[i]==el1){
                cnt1++;
            }else if(nums[i]==el2){
                cnt2++;
            }
           }
           if(cnt1>nums.size()/3){
            ans.push_back(el1);
           }
           if(cnt2>nums.size()/3){
            ans.push_back(el2);
           }
           return ans;
    }
};