class Solution {
public:
    int gcd(int a, int b) 
    {
        
        if(b > a)
        {
            gcd(b,a);
        }
        while (b != 0) 
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int lcm(int a, int b) 
    {
        return ((a * b) / gcd(a, b));
    }
    int lcmofd(vector<int>&numbers) 
    {
        int result = numbers[0];
        for (int i = 1; i < numbers.size(); i++) 
        {
            result = lcm(result, numbers[i]);
        }
        return result;
    }
    int make_num(string s)
    {
        reverse(s.begin(),s.end());
        int num = 0;
        int product = 1;
        for(int i = 0 ; i < s.size() ; i++ )
        {
            num += (int(s[i]-48)*product);
            product *= 10;
        }
        return num;
    }
    
    
    
    string fractionAddition(string expression) 
    {
        vector<int>n;
        vector<int>d;  //={12, 15, 20, 25, 30};
        vector<int>op; // 0 --> '+'  ||  1 --> '-'
        
        if(expression[0] != '-')
        {
            expression = '+'+expression;
        }
        
        int flag = 0;
        string c_num = "";
    
        for(int i = 0 ; i < expression.size() ; i++)
        {
            if(expression[i] == '+' || expression[i] == '-' )
            {
                if(expression[i] == '+')
                {
                    op.emplace_back(0);
                }
                else
                {
                    op.emplace_back(1);
                }
                if(flag == 1)
                {
                    d.emplace_back(make_num(c_num));
                    c_num ="";
                }
            }
            else if(expression[i] == '/')
            {
                n.emplace_back(make_num(c_num));
                c_num = "";
            }
            else
            {
                c_num += expression[i];
                flag = 1;
            }
        }
        d.emplace_back(make_num(c_num));
        
        // for(int i = 0 ; i < d.size();i++)
        // {
        //     cout<<op[i]<<" "<<n[i]<<" "<<d[i]<<" "<<endl;
        // }
        
        int lcm_d = lcmofd(d);
        int fn = 0;
        for(int i = 0 ; i < d.size() ; i++)
        {
            if(op[i] == 0)
            {
                fn += ( n[i] * (lcm_d / d[i]));
            }
            else
            {
                fn -= ( n[i] * (lcm_d / d[i])); 
            }
        }
        
        string temp = "";
        if(fn == 0)
        {
            lcm_d = 1;
        }
        if(fn < 0)
        {
            temp += '-';
            fn *= -1;
        }
        int t = gcd(fn,lcm_d);
        fn /= t;
        lcm_d /= t;
        string ans = temp + to_string(fn) + '/' + to_string(lcm_d);
        return ans;
    }
};