class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        vector<vector<int>>dpr(matrix.size() , vector<int>(matrix[0].size(),0));
        vector<vector<int>>dpb(matrix.size() , vector<int>(matrix[0].size(),0));
        
        //contrustion of right
        for(int i = 0 ; i < dpr.size() ; i++){
            if(matrix[i][dpr[0].size()-1] == '1'){
                dpr[i][dpr[0].size()-1] = 1;
            }
            for(int j = dpr[0].size()-2 ; j>= 0 ; j--){
                if(matrix[i][j] == '1'){
                    if(matrix[i][j+1] == '0'){
                        dpr[i][j] = 1;                        
                    }
                    else{
                        dpr[i][j] = dpr[i][j+1]+1;
                    }
                    
                }
            }
        }
        
        //construction of bottom
        for(int i = 0 ; i < dpb[0].size() ; i++){
            if(matrix[dpb.size()-1][i] == '1'){
                dpb[dpb.size()-1][i] = 1;                
            }
            for(int j = dpb.size()-2; j >= 0 ; j--){
                if(matrix[j][i] == '1'){
                    if(matrix[j+1][i] == '0'){
                        dpb[j][i] = 1;                        
                    }
                    else{
                        dpb[j][i] = dpb[j+1][i]+1;
                    }
                    
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '1'){
                    int min_rc = min(dpr[i][j] , dpb[i][j]);
                    for(int k = 0; k < min_rc ; k++){
                        if(dpr[i+k][j] >= (k+1) && dpb[i][j+k] >= (k+1) ){
                            ans = max(ans,((k+1)*(k+1)));                            
                        }                                
                        else{
                            break;
                        }
                    }
                }
            }
        }
        
        //printing both the matrix
        for(int i = 0 ; i < dpr.size() ; i++){
            for(int j = 0 ; j < dpr[0].size(); j++){
                cout<<dpr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i = 0 ; i < dpb.size() ; i++){
            for(int j = 0 ; j < dpb[0].size(); j++){
                cout<<dpb[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};

// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// [["0","1"],["1","0"]]
// [["0"]]
// [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// [["0","1"],["1","0"]]
// [["0"]]
// [["1","0","1","1","0"],["1","0","1","1","1"],["1","1","1","1","1"],["0","1","1","1","0"]]
// [["1"]]
// [["0","0","0"],["0","0","0"],["0","0","0"]]
// [["1","1","1"],["1","1","1"],["1","1","1"]]
// [["1","0","1","0"],["1","1","1","0"],["0","1","1","1"]]
// [["1"],["1"],["0"],["1"]]
// [["0","1","1","0","1"],["1","1","1","1","0"],["1","1","1","1","1"],["0","1","1","1","0"]]
