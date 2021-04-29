class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        int res_len = 0;
        for(int i=0;i<d.size();i++)
        {
            string temp = d[i];
            int x =0;
            int y=0;
            int c = 0;
            while(x<temp.length() && y<s.length())
            {
                if(temp[x]==s[y])
                {
                    x++;
                    c++; // count
                }
                y++;
            }
            if(c==temp.length())
            {
                if(temp.length()>res_len)
                {
                    res = temp;
                    res_len = temp.length();
                }
                else if(temp.length()==res_len)
                {
                    bool flag = true;
                    for(int ii=0;ii<temp.length();ii++)
                    {
                        if(temp[ii]==res[ii])
                        {
                            continue;
                        }
                        else if(temp[ii]>res[ii])
                        {
                            break;
                        }
                        else if(temp[ii]<res[ii])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        res = temp;
                    }
                }
            }
            
        }
        return res;
    }
};
