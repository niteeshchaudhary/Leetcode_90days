class Solution {
public:
    double binsearch(vector<int>& nums1, vector<int>& nums2,int l1,int r1,int& sz,int& odd){
        if(r1==-1){
            if(odd){
                return nums2[sz];
            } 
            else{
                return (nums2[sz]+nums2[sz-1])/2.0;
            }
        }
        int mid=(l1+r1)/2;
        if(l1>r1){
            return -1;
        }
        int otm=sz-mid-1;
        if(nums1[mid]<nums2[otm]){
            if(mid+1>=nums1.size() || (mid+1<nums1.size() && nums2[otm]<=nums1[mid+1])){
                if(odd)
                    return nums2[otm];
                else{
                    if(otm-1>-1){
                        return (max(nums1[mid],nums2[otm-1])+nums2[otm])/2.0;
                    }
                    else{
                        return (nums1[mid]+nums2[otm])/2.0;
                    }
                }  
            }
            else{
                return binsearch(nums1,  nums2,mid+1,r1,sz,odd);
            }
        }
        else if(nums1[mid]>nums2[otm]){
            if(otm+1>=nums2.size() || (otm+1<nums2.size() && nums2[otm+1]>=nums1[mid])){
                if(odd)
                    return nums1[mid];
                else{
                    if(mid-1>-1){
                        return (nums1[mid]+ max(nums1[mid-1],nums2[otm]))/2.0;
                    }
                    else{
                        return (nums1[mid]+nums2[otm])/2.0;
                    }
                }
            }
            else{
                return binsearch(nums1, nums2,l1,mid-1,sz,odd);
            } 
        }
        else{
            return nums1[mid];
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int total=n1+n2,temp=total/2,odd=total%2;
        if(n1<=n2)
            return binsearch(nums1,nums2,0,n1-1,temp,odd);
        else
            return binsearch(nums2,nums1,0,n2-1,temp,odd);
    }
};