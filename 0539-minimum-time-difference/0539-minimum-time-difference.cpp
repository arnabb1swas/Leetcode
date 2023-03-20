class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        //step 1 time->min
        for(int i=0;i<timePoints.size();i++)
        {
            string cur=timePoints[i];
            int hr=stoi(cur.substr(0,2));
            int minute=stoi(cur.substr(3,2));
            int tot=hr*60+minute;
            minutes.push_back(tot);
        }

        //step 2 sort
        sort(minutes.begin(),minutes.end());

        //step 3 difference min
        int mini=INT_MAX;
        for(int i=0;i<minutes.size()-1;i++){
            int diff=minutes[i+1]-minutes[i];
            mini=min(diff,mini);
        }
        int last1=(minutes[0]+1440)-minutes[minutes.size()-1];
        mini=min(mini,last1);

        return mini;
    }
};