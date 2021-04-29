class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>res;
        int prev = -1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==c)
            {
                res.push_back(0);
                prev = i;
            }
            else
            {
                if(prev ==-1)
                {
                    res.push_back(INT_MAX);
                }
                else
                {
                    res.push_back(abs(i-prev));
                }
            }
        }
        prev = -1;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                res[i] = 0;
                prev = i;
            }
            else
            {
                if(prev ==-1)
                {
                    res[i] = min(res[i],INT_MAX);
                }
                else
                {
                    res[i] = min(abs(i-prev),res[i]);
                }
            }
        }
        return res;
    }
};
