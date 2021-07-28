class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        // line sweep
        // line sweep says increment the value at start
        // and decrement the value at end
        map<long long,long long>ump;
        for(auto x:segments){
            ump[x[0]]+=x[2];
            ump[x[1]]-=x[2];
        }
        long long color = 0;
        int prev = -1;
        vector<vector<long long>>res;
        for(auto x:ump){
            if(prev!=-1 and color!=0){
                res.push_back({prev,x.first,color});
            }
            prev = x.first;
            color+=x.second;
        }
        // O(n) time complexity
        return res;
    }
    
};
