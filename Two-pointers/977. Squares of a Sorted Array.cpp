class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int ind = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                ind = i;
                break;
            }
        }
        int n = nums.size();
        vector<int>res;
        int l = (ind==-1)?n-1:ind-1;
        int r = (ind==-1)?n:ind;
        // cout<<l<<" "<<r<<endl;
        while(l>=0 || r<n)
        {
            if(l>-1 && r!=n)
            {
                // cout<<nums[l]*nums[l]<<endl;
                if(abs(nums[l]*nums[l])>abs(nums[r]*nums[r]))
                {
                    res.push_back(nums[r]*nums[r]);
                    // cout<<'a'<<" ";
                    r++;
                }
                else
                {
                    res.push_back(abs(nums[l]*nums[l]));
                    // cout<<'b'<<" ";
                    l--;
                }
                
            }
            else if(l>-1)
            {
                res.push_back(abs(nums[l]*nums[l]));
                l--;
                // cout<<'c'<<" ";
            }
            else if(r!=n)
            {
                res.push_back(nums[r]*nums[r]);
                r++;
                // cout<<'d'<<" ";
            }
        }
        return res;
    }
};
