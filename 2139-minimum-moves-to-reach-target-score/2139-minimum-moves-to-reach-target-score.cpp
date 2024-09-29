class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(target == 1){
            return 0;
        }
        if(target % 2 == 1){
            return 1 + minMoves(target - 1 , maxDoubles);
        }
        if(maxDoubles <= 0){
            return target - 1;
        }
        if(maxDoubles >= 2 && target % 4 == 0){
            return 2 + minMoves(target / 4 , maxDoubles - 2);
        }
        return 1 + minMoves(target / 2 , maxDoubles-1);
    }
};