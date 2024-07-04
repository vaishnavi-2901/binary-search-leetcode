/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        vector<int> res;
        set<int> s;
        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i] == nums2[j]){
                s.insert(nums1[i]);
                i++, j++;
            }else if(nums1[i]>nums2[j]){
                j++;
            }else{
                i++;
            }
        }

        for(auto e : s){
            res.push_back(e);
        }
        return res;
    }
};
