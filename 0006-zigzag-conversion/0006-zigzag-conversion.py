class Solution(object):
    def convert(self, s, numRows):
        if numRows==1:
            return s
        i=0
        l=[]
        k=""    
        while i<numRows:
            l.append(k)
            i+=1
        poi=0
        for j in s:
            l[poi]+=j
            if poi==numRows-1:
                jj=-1
            elif poi==0:
                jj=1
            poi=poi+(1*jj)
        ans=""
        for k in l:
            for m in k:
                ans+=str(m)
        return ans