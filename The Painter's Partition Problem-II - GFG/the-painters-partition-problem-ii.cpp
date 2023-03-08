//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool isPossibleSoln(int arr[], int n, int k, long long sol){
        long long totalTimeSum = 0;
        int painterCount = 1;
        for(int i = 0;i < n; i++){
            if(arr[i] > sol) {
                return false;
            }
            if(arr[i] + totalTimeSum > sol){
                painterCount++;
                totalTimeSum = arr[i];
                if(painterCount>k) {
                    return false;
                }
            }else{
                totalTimeSum += arr[i];
            }
        }
        return true;
    }
    
    long long minTime(int arr[], int n, int k)
    {
        // if(n<k) { no need to add this becuase it's not mention that every painter should get a board.
        //     return -1;
        // }
        
        long long start = 0, end = 0, ans = -1;
        for(int i=0; i< n; i++){
            end += arr[i];
        }
        
        while(start<=end){
            long long mid = start + (end - start) / 2;
            if(isPossibleSoln(arr, n, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends