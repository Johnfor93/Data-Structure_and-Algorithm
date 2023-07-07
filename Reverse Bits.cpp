class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverseInt=0;
        for(int i=1; i<=32; i++){
            reverseInt <<= 1;
            reverseInt ^= (n&1);
            n>>=1;
        }
        return reverseInt;
    }
};