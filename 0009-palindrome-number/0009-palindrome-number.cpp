class Solution {
public:

    int reverse(int n){
    long long revNum = 0;

    while( n != 0 ){
        int digit = n % 10;
    if( revNum > INT_MAX || revNum < INT_MIN){
        return 0;
    }
    revNum = revNum * 10 + digit;
    n = n/10;
    }
    return revNum;
   }   
   

    bool isPalindrome(int n) {

        if(n < 0){
            return false;
        }

        int revNum = reverse(n);
        return n == revNum;
          
    }
};