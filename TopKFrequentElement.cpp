// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>v;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x: mp){
            pq.push({x.second, x.first}); // Adding frequency, number in the max-heap, so that if we extract top we will get most occuring number
        }
        while(k--){
            
            v.emplace_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
