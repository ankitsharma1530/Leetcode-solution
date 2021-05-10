class Solution {
public:
    bool isValid(string s) {
       // abc
       // a + abc + bc => aabcbc
       // abccba;
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='c')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size()<2)
                {
                    return false;
                }
                else
                {
                    if(st.top()=='b')
                    {
                        st.pop();
                        if(st.top()=='a')
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
        
    }
};
