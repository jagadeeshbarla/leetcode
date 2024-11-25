class Solution {
public:
    bool check_board(vector<vector<int>>& board){
        if(board[0][0] != 1 || board[0][1] != 2 || board[0][2] != 3)
        {
            return false;
        }
        if(board[1][0] != 4 || board[1][1] != 5 || board[1][2] != 0){
            return false;
        }
        return true;
    }
    // void print(vector<vector<int>> &b){
    //     for(int i = 0 ; i < b.size() ; i++){
    //         for(int j = 0 ; j < b[0].size() ; j++){
    //             cout<<b[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        
        queue<vector< vector<vector<int>> > > q;
        vector< vector<vector<int>> > temp ;
        temp.emplace_back(board);
        q.push(temp);
        set<vector<vector<int>>>state;
        int curr = 0;
        while(!q.empty()){
            
            vector< vector<vector<int>> > qt1 = q.front();
            q.pop();
            vector< vector<vector<int>> > qt2;
            for(int i = 0 ; i < qt1.size() ; i++){
                //check if reaches final state;
                if(check_board(qt1[i])){
                    return curr;
                }  
                //finding 0's index
                int x,y;
                state.insert(qt1[i]);
                for(int k = 0 ; k < qt1[i].size() ; k++){
                    for(int j = 0 ; j < qt1[i][k].size() ; j++){
                        if(qt1[i][k][j] == 0){
                            x = k;
                            y = j;
                            break;
                        }
                    }
                }
                
                //Now try the state change
                if( (x-1) >= 0){
                    int temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x-1][y];
                    qt1[i][x-1][y] = temp;
                    
                    if(state.find(qt1[i]) == state.end()){
                        qt2.emplace_back(qt1[i]);
                    }
                    temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x-1][y];
                    qt1[i][x-1][y] = temp;
                }
                if( (x+1) < qt1[i].size()){
                    int temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x+1][y];
                    qt1[i][x+1][y] = temp;
                    
                    if(state.find(qt1[i]) == state.end()){
                        qt2.emplace_back(qt1[i]);
                    }
                    temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x+1][y];
                    qt1[i][x+1][y] = temp;
                }
                if( (y-1) >= 0){
                    int temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x][y-1];
                    qt1[i][x][y-1] = temp;
                    
                    if(state.find(qt1[i]) == state.end()){
                        qt2.emplace_back(qt1[i]);
                    }
                    temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x][y-1];
                    qt1[i][x][y-1] = temp;
                }
                if( (y+1) < qt1[i][0].size()){
                    int temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x][y+1];
                    qt1[i][x][y+1] = temp;
                    
                    if(state.find(qt1[i]) == state.end()){
                        qt2.emplace_back(qt1[i]);
                    }
                    temp =  qt1[i][x][y];
                    qt1[i][x][y] = qt1[i][x][y+1];
                    qt1[i][x][y+1] = temp;
                }
                
            }
            if(qt2.size() > 0){
                curr++;
                q.push(qt2);
            }
        }
        return -1;        
    }
};