class Solution {
public:
//     string addStrings(string num1, string num2) {
//         int len1=num1.length()-1;
//         int len2=num2.length()-1;
//         string ans="";
//         int carry=0;
//         while(len1>=0 || len2>=0 || carry){
            
//             int n1=len1>=0 ?num1[len1]-'0':0;
//             int n2=len2>=0 ?num2[len2]-'0':0;
//             int result=n1+n2+carry;
//             int temp=result%10;
//             carry=result/10;
//             ans+=temp+'0';
//             len1--;
//             len2--;
//         }
        
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
    
        
    // using recursion
    void addStringUsingRecursion(string& num1, int p1, string& num2, int p2, int carry, string& ans){
        if(p1<0 && p2<0){
            if(carry !=0 ){
                ans.push_back( carry + '0' );
            }
            return;
        }
    
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int sum = n1 + n2 + carry;
        ans.push_back( sum % 10 + '0' );
        
        addStringUsingRecursion(num1, --p1, num2, --p2, sum/10, ans);
    }
    
    string addStrings(string num1, string num2) {
        string ans = "";
        addStringUsingRecursion(num1, num1.size()-1, num2, num2.size()-1, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};