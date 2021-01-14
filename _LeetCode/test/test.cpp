#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main(int argc, char const *argv[]){
	
	vector<int> nums1 = {}, nums2 = {5};
	// nums1 = [1,3], nums2 = [2];
	// nums1 = [1,2], nums2 = [3,4];
	// nums1 = [0,0], nums2 = [0,0];
	// nums1 = [], nums2 = [1];
	// nums1 = [2], nums2 = [];

	cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

//分别遍历 O(m+n)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
	int m = nums1.size(), n = nums2.size();
	bool odd = (m+n)%2==0?true:false;
	int ptr1 = 0, ptr2 = 0, index = 0, medium = (m+n)/2+1;
	int tmp = 0;
	double res = 0.0;

	while(ptr1 < m && ptr2 < n && index < medium){
		 	
		index++;
		if (index==medium){
			if (odd){
				res = ((double)(tmp + min(nums1[ptr1], nums2[ptr2]))/2.0);
			}else{
				res = (double)min(nums1[ptr1], nums2[ptr2]);
			}
			break;
		}
		tmp = min(nums1[ptr1], nums2[ptr2]);
		if (nums1[ptr1] <= nums2[ptr2]){
			ptr1++;
		}else{
			ptr2++;
		}
	}
	if (ptr1 < m && index < medium){
		while (index < medium){
			index ++;
			if (index==medium){
				if (odd){
					res = ((double)(tmp + nums1[ptr1])/2.0);
				}else{
					res = (double)nums1[ptr1];
				}
				break;
			}
			tmp = nums1[ptr1];
			ptr1++;
		}
	}else if (ptr2 < n && index < medium){
		while (index < medium){
			index ++;
			if (index==medium){
				if (odd){
					res = ((double)(tmp + nums2[ptr2])/2.0);
				}else{
					res = (double)nums2[ptr2];
				}
				break;
			}
			tmp = nums2[ptr2];
			ptr2++;
		}
	}
	return res;
}







