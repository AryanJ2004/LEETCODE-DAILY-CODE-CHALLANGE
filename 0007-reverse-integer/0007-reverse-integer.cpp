class Solution {
public:
    int reverse(int x) {
       int rev=0;
       int max=numeric_limits<int>::max();
       int min=numeric_limits<int>::min();
       while(x!=0)
       {
       
       int pop=x%10;
       x/=10;
       if(rev>max/10 || rev<min/10)
       return 0;
       else
       rev=rev*10+pop;
       }
        return rev;
    }
    
};