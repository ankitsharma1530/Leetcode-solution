class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>>res;
        int n = f.size();
        int m = s.size();
        int i=0;
        int j=0;
        while(i<n && j<m)
        {
            int start = max(f[i][0],s[j][0]);
            int end = min(f[i][1],s[j][1]);
            // if and only if our starting point is less than the ending point
            if(start<=end)
            {
                res.push_back({start,end});
            }
            if(f[i][1]>s[j][1])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};
