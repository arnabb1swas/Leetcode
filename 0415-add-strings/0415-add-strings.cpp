class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.length()-1;
        int len2=num2.length()-1;
        string ans="";
        int carry=0;
        while(len1>=0 || len2>=0 || carry){
            
            int n1=len1>=0 ?num1[len1]-'0':0;
            int n2=len2>=0 ?num2[len2]-'0':0;
            int result=n1+n2+carry;
            int temp=result%10;
            carry=result/10;
            ans+=temp+'0';
            len1--;
            len2--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};