class Solution {
public:
    bool judgeSquareSum(int c) {
        long int i = 0, j = (int)sqrt(c);
        if(c<0){
            return false;
        }
        while(i<=j){
            long int sum = i*i + j*j;
            if(sum == c){
                return true;
            }
            else if(sum<c){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};