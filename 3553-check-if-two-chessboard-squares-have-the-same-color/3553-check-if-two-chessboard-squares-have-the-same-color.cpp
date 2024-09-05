class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
    
        int x=abs(coordinate1[0]-coordinate2[0]);
        int y=abs(coordinate1[1]-coordinate2[1]);
        if(x%2==y%2)
        {
            return true;
        }
        return false;
    }
};