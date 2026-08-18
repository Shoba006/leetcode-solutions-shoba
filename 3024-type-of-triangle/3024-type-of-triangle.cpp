class Solution {
public:
    string triangleType(vector<int>& n) {

        if(n[0]+n[1]<=n[2] ||
           n[1]+n[2]<=n[0] ||
           n[0]+n[2]<=n[1]){
            return "none";
        }
        else if(n[0]==n[1] && n[1]==n[2]){
            return "equilateral";
        }
        else if(n[0]==n[1] && n[1]!=n[2] ||
        n[0]==n[2] && n[2]!=n[1] || 
        n[1]==n[2] && n[2]!=n[0]){
            return "isosceles";
        }
        else{
            return "scalene";
        }

    }
};