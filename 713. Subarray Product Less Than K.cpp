class Solution {
public:
    // time complexity -> o(N)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        // logic we will use the concept of sliding window
        // see if a subarray [1,2,3] product is less than k=7;
        // hence total subarray are -> [1],[1,2],[2],[1,2,3],[3],[2,3] total(7 subarray)
        
        // we just iterate from first to last and and take a product variable
        // if this variable is greater than k then we slide from first i.e 'i'
        int p = 1;
        int i=0;
        int j=0;
        int res = 0;
        while(j<nums.size()){
            p = p*nums[j];
            if(p>=k){
                while(p>=k){
                    p=p/nums[i];
                    i++;
                }
            }
            res+=(j-i)+1;
            j++;
        }
        return res;
    }
};
