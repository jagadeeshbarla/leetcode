class Solution {
public:
    string pushDominoes(string d) 
    {
        vector<int>templ(d.length(),0);
        vector<int>tempr(d.length(),0);
        
        for(int i = 0 ; i < d.size() ; i++)
        {
            if(d[i] == 'R')
            {
                int index = i ;
                int mark = 1;
                tempr[index++] = mark++;
                while(index < d.size() && d[index] == '.')
                {
                    tempr[index++] = mark++;
                }
            }
            else if(d[i] == 'L')
            {
                int index = i ;
                int mark = -1;
                templ[index--] = mark--;
                while(index >= 0 && d[index] == '.')
                {
                    templ[index--] = mark--;
                }
            }
        }
        string ans;
        for(int i = 0 ; i < templ.size() ; i++ )
        {
            //cout<<i<<"  "<<templ[i]<<" "<<tempr[i]<<" ";
            if(tempr[i] > 0 && templ[i] == 0)
            {
                ans += 'R';
            }
            else if(templ[i] < 0 && tempr[i] == 0)
            {
                ans += 'L';
            }
            else if (tempr[i] + templ[i] == 0)
            {
                ans += '.';
            }
            
            else if(tempr[i]  > abs(templ[i]) )
            {
                ans += 'L';
            }
            else if(tempr[i] < abs(templ[i]) )
            {
                ans += 'R';
            }
            else if(templ[i] == 0 && tempr[i] == 0)
            {
                ans += '.' ;
            }
            else
            {
                cout<<"never";
                ans+='j';
            }
            //cout<<ans<<endl;
        }
        //cout<<endl;
        return ans;
    }
};