class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int k=0;
        for(int i=0;i<chars.size();){
            int j=i+1;
            while(j<chars.size()){
                if(chars[j]==chars[i]){
                    j++;
                }
                else{
                    break;
                }
            }
            if(j-i>1){
                chars[k]=chars[i];
                string str=to_string(j-i);
                for( auto ch:str)
                    chars[++k]=ch;
                k++;
            }
            else{
                chars[k]=chars[i];
                k++;
            }
            i=j;
        }
        return k;
        
    }
};