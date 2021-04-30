class Solution {
public:
    string pushDominoes(string d) {
        // 0 0 0 
        int n =  d.length();
        int forces[n] ;
        int force = 0;
        cout<<n<<endl;
        // loop from left to right
        // so we will count only the right forces
        for(int i=0;i<n;i++)
        {
            if(d[i]=='R')
            {
                force = n;
            }
            else if(d[i]=='L')
            {
                force = 0;
            }
            else
            {
                force = max(force-1,0);
            }
            forces[i]=force;
        }
        for(int i=0;i<n;i++)
        {
            cout<<forces[i]<<" ";
        }
        force = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(d[i]=='L')
            {
                force = n;
            }
            else if(d[i]=='R')
            {
                force = 0;
            }
            else
            {
                force = max(force-1,0);
            }
            forces[i]-=force;
        }
        for(int i=0;i<n;i++)
        {
            cout<<forces[i]<<" ";
        }
        string res;
        for(int i=0;i<n;i++)
        {
            if(forces[i]>0)
            {
                res.push_back('R');
            }
            else if(forces[i]<0)
            {
                res.push_back('L');
            }
            else
            {
                res.push_back('.');
            }
        }
        return res;
    }
};
