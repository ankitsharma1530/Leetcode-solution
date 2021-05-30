int solve(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int ans = INT_MAX;
    int i=0;
    int j = nums.size()-1;
    while(i<j){
        int curr = nums[i]+nums[j];
        if(curr>target)
        {
            ans = min(ans,curr);
            j--;
        }
        else{
            i++;
        }
    }
    return ans;
}
