class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        int max_over_all=nums[0];
        int max_end_here=nums[0],min_end_here=nums[0];
        for(int i=1;i<nums.size();i++)
        {   int temp=max_end_here;
            max_end_here=max({nums[i],nums[i]*max_end_here,min_end_here*nums[i]});
            min_end_here=min({nums[i],nums[i]*temp,min_end_here*nums[i]});
            max_over_all=max(max_over_all,max_end_here);
        }
        return max_over_all;
    }
};
