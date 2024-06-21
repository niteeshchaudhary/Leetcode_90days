class Solution:
    def eraseOverlapIntervals(self, intervals):
        intervals.sort()
        cnt=0
        mx=intervals[0][0]
        for s,e in intervals:
            if(s<mx):
                cnt+=1
                mx=min(e,mx)
            else:
                mx=e
        return cnt

        