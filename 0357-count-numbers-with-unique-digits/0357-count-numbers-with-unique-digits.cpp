class Solution {
public:
    
    vector<int>v {9,9,8,7,6,5,4,3,2,1,0};
    
    
    int countNumbersWithUniqueDigits(int n) {
        if( n==0 ){
            return 1;
        }
        if(n == 1)
        {
            return 10;
        }
        
        int p = 1;
        for(int i = 0 ; i < n ; i++)
        {
            p *= v[i];
        }
        return p+countNumbersWithUniqueDigits(n-1) ;
    }
};