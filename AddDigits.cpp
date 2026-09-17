class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        int temp = 0;
        while(num>0)
        {
            temp+=num%10;
            num/=10;
        }
        sum = temp;
        while(sum>=10)
        {
            temp = 0;
            while(sum>0)
            {
                temp += sum%10;
                sum /= 10;
            }
            sum = temp;
        }
        return sum;
    }
};