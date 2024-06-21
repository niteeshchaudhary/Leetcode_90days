class Solution(object):
    def minSubArrayLen(self, target, nums):
        if len(nums)==0:
            return 0
        l=0
        r=0
        sm=nums[0]
        mn=len(nums)+1
        while True:
            if(l==r):
                if(r==len(nums)-1):
                    if(sm>=target):
                        mn=min(mn, r-l+1)
                    if mn==len(nums)+1:
                        return 0
                    return mn
                if(target<=sm):
                    return 1
                else:
                    r+=1
                    sm=sm+nums[r]
            if(r<len(nums)-1):
                if(sm>=target):
                    mn=min(mn, r-l+1)
                    if(l<r):
                        sm-=nums[l]
                        l+=1
                else:
                    r+=1
                    sm=sm+nums[r]
            else:
                if(sm>=target):
                    mn=min(mn, r-l+1)
                else:
                    if mn==len(nums)+1:
                        return 0
                    return mn

                sm-=nums[l]
                l+=1
