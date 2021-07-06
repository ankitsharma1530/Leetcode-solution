class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        vector<pair<int,int> > sol;
        int n = A.size();
        
        for(int i=0;i<n;i++){
            sol.push_back({A[i],i});
        }
        sort(sol.begin(),sol.end());
        
        int i=0;
        int j =1;
        int ans =0;
        
        while(j<n){
            if(sol[j].second>sol[i].second){
                ans = max(ans,sol[j].second-sol[i].second);
                j++;
            }
            else{
                i++;
            }
            if(i==j){
                j++;
            }
        }
        return ans;
    }
};
