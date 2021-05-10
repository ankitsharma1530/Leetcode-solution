class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int>s;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                s.push(0);
            }
            else
            {
                if(s.top()==0)
                {
                    s.pop();
                    s.push(1);
                }
                else
                {
                    int temp = 0;
                    while(!s.empty() && s.top()!=0)
                    {
                        temp+=s.top();
                        s.pop();
                    }
                    if(!s.empty() && s.top()==0)
                    {
                        s.pop();
                        temp=temp*2;
                    }
                    s.push(temp);
                }
            }
        }
        int ans = 0;
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
