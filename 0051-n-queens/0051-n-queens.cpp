class Solution {
    bool flag = true;
    vector<vector<string>>ans;
public:
    void addDots(vector<string>&s,int row , int col)
    {
        if(s[row][col] =='.')
        {
            flag = false;
            return;
        }
        
        for(int i = 0 ; i < s[0].size(); i++)
        {
            s[row][i] ='.';
        }
        for(int i = 0 ; i < s.size(); i++)
        {
            s[i][col] = '.';
        }
        int i = 0;
        while(1)
        {
            if(row+i < s.size() && col+i < s.size())
            {
                s[row+i][col+i]='.';
                i++;
            }
            else
            {
                break;
            }
        }
        i = 0;
        while(1)
        {
            if(row+i < s.size() && col-i >= 0)
            {
                s[row+i][col-i]='.';
                i++;
            }
            else
            {
                break;
            }
        }
        s[row][col] = 'Q';
    }
    
    void solve(vector<string>temp , int row)
    {
        if(row == temp.size())
        {
            ans.emplace_back(temp);
            return;
        }
        
        for(int i = 0 ; i < temp.size() ; i++)
        {
            if( temp[row][i] =='a')
            {
                vector<string>temp_1(temp.begin(),temp.end());
                flag = true;
                addDots(temp_1,row,i);
                if(flag == true)
                {
                    solve(temp_1,row+1);
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        for(int i = 0 ; i < n ; i++)
        {
            string s(n,'a');
            vector<string>temp(n,s);
            addDots(temp,0,i);
            solve(temp,1);
        }
        return ans;
    }
};