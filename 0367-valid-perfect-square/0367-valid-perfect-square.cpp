class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
            return true;
        
        for(double i=2;i<=num/i;i++)
        {
            if(i*i==num)
            return true;
        }
        return false;
    }
};