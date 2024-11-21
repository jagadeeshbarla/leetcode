class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = 0,b = 0,c = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == 'a'){
                a++;
            }
            else if(s[i] == 'b'){
                b++;
            }
            else{
                c++;
            }
        }
        if(a < k || b < k || c < k){
            return -1;
        }
        int window_size = k*3;
        while(true){
            int a_count = 0 , b_count = 0 , c_count = 0 ;
            for(int i = 0 ; i < window_size ; i++){
                if(s[i] == 'a'){
                    a_count++;
                }
                else if(s[i] == 'b'){
                    b_count++;
                }
                else{
                    c_count++;
                }
            }
            if(a_count >= k && b_count >= k && c_count >= k){
                return window_size;
            }   
            int pointer = window_size - 1;
            int marker = 1;
            while(pointer >= 0){
                if(s[pointer] == 'a'){
                    a_count--;
                }
                else if(s[pointer] == 'b'){
                    b_count--;
                }
                else{
                    c_count--;
                }
                
                if(s[s.size()-marker] == 'a'){
                    a_count++;
                }
                else if(s[s.size()-marker] == 'b'){
                    b_count++;
                }
                else{
                    c_count++;
                }
                
                if(a_count >= k && b_count >= k && c_count >= k){
                    return window_size;
                }
                
                marker++;
                pointer--;
            }
            window_size++;
            }
        return s.size();
        
    }
};