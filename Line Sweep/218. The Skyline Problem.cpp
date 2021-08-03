class Solution {
public:
    // time complexoty -> O(nlogn)
    bool static cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>arr; // for line sweep
        vector<vector<int>>res;
        
        for(auto x:buildings){
            arr.push_back({x[0],x[2]}); // starting point
            arr.push_back({x[1],0-x[2]}); // ending point
        }
        sort(arr.begin(),arr.end(),cmp);
        
        // now we have to trace the heights of building who are alive for current time x
        multiset<int>height;
        height.insert(0); // as we had to attend this case also - > [12,0]
        int prev = 0;
        for(auto x:arr){
            if(x.second>0){
                // starting of new building
                height.insert(x.second);
            }
            else{
                // end of the existing building
                height.erase(height.find(0-x.second));
            }
            
            if(!height.empty() and *height.rbegin()!=prev){
                // *height.rbegin()!=prev -> this means there is a change either the                     // height drop or increase hence we had to consider these cases
                prev = *height.rbegin();
                res.push_back({x.first,prev});
            }
        }
        return res;
    }
    
};
