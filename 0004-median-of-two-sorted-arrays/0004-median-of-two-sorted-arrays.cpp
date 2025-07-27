class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int>sorted_array;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<nums2[j]){
                sorted_array.push_back(nums1[i]);
                i++;
            }
            else{
                sorted_array.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size())sorted_array.push_back(nums1[i++]);
        while(j<nums2.size())sorted_array.push_back(nums2[j++]);
        int n=sorted_array.size();
        if(n%2!=0){
            return sorted_array[n/2];
        }
        return (sorted_array[n/2 - 1] + sorted_array[n/2]) / 2.0;    }
};