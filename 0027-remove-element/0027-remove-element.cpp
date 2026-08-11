class Solution{
    public:
    int removeElement(vector<int>&num,int val){
        int x =0;
        for(int i =0;i<num.size();i++){
            if(num[i]!=val){
                num[x]=num[i];
                x++;
            }
       
        }
        return x;
    }
 };

