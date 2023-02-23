class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        while(start<=end){
            int mid = start + (end - start) / 2;
            int val = guess(mid);
            if(val == 0)
                return mid;
            else if(val == -1)
                end = mid-1;  
            else if(val == 1)
                start = mid+1;
        }
        return 0;
    }
};