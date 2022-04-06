// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 109 + 7.

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans += mp[target-arr[i]-arr[j]];
            }
            ans =ans%1000000007;
            mp[arr[i]]++;
        }
        return ans%1000000007;
    }
};
