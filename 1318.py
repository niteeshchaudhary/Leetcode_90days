class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        ba=format(a, '032b')
        bb=format(b, '032b')
        bc=format(c, '032b')
        cnt=0
        for i,j,k in zip(ba,bb,bc):
            if k=='0':
                if i=='1':
                    cnt+=1
                if j=='1':
                    cnt+=1
            elif k=='1':
                if i=='1' or j=='1':
                    continue
                else:
                    cnt+=1    

        return cnt
        