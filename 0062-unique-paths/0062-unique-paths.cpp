class Solution {
public:
    int uniquePaths(int m, int n) {
        int t[n][m];
        t[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    continue;
                t[i][j]=0;
                if(i>0)
                    t[i][j]+=t[i-1][j];    
                if(j>0)
                    t[i][j]+=t[i][j-1];               
            }
        }
        return t[n-1][m-1];
    }
};