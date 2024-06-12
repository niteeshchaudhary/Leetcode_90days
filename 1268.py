class Solution:
    def suggestedProducts(self, products, searchWord):
        ind=0
        fltr=sorted(products)
        ans=[]
        for i in searchWord:
            fltr=list(filter(lambda x: len(x)>ind and x[ind]==i,fltr))
            print(list(fltr))
            ind+=1
            if len(fltr)>3:
                ans.append(fltr[:3])
            else:
                ans.append(fltr)
        return ans


        