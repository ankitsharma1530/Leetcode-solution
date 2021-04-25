class Solution {
public:
    vector<int> partitionLabels(string S) {
        // count the occurence of each number
        unordered_map<char,int>ump;
        for(int i=0;i<S.length();i++)
        {
            ump[S[i]]=i;
        }
        int n = S.length();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int start = i;
            //last most occurence of the ith character
            int end = ump[S[i]];
            while(i<end && end<n)
            {
                end = max(end,ump[S[i]]);
                i++;
            }
            res.push_back(i-start+1);
        }
        return res;
    }
};
