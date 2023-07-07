/*
    Using XOR operation for every bit.
    Using AND operation for save the carry bit.
    
    Iterate until the carry is 0
    For testcase like 7+1
    Iteration 0:
    carry   000
    a       111
    b       001

    Iteration 1:
    carry   001
    a       110
    b       010

    Iteration 2:
    carry   010
    a       100
    b       100

    Iteration 3:
    carry   0100
    a       0000
    b       1000

    Iteration 4:
    carry   0000
    a       1000
    b       0000

    a is the result;
*/


class Solution {
public:
    int getSum(int a, int b) {
        // need to be unsigned because negative value store as 2s complement representation of the positive
        // Source https://www.geeksforgeeks.org/how-the-negative-numbers-are-stored-in-memory/
        // 1 = 000...001 (with 32 bit/ 64 bit)
        // -1 = 111...111
        unsigned int carry;
        do{
            carry=(a&b);
            a^=b;
            b=carry<<1;
        }while(carry != 0);
        return a;
    }
};