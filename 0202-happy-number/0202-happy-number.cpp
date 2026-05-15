class Solution {
public:

int nextNum(int n){
int sum=0;
while(n>0){
    int digit=n%10;
    sum=sum+digit*digit;
    n=n/10;
}
return sum;
}
    bool isHappy(int n) {
        int slow =n;
        int fast =n;
        while(true){
            slow=nextNum(slow);
            fast=nextNum(nextNum(fast));
            if(fast==1){
                return true;
            }
            if (slow==fast){
                return false;
            }
            
        }
    }
};