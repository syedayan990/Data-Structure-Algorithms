class Solution {
public:
    int maxArea(vector<int>& height) {
        // max water question with brute force approch   time compelxity = 0(n^2) for appropriate
        // int maxArea = 0;

        // for(int i=0; i<height.size(); i++){
        //     for(int j=i+1; j<height.size(); j++){
        //        int widht = j-i;
        //        int ht = min(height[i] , height[j]);
        //         int Area = widht*ht;
        //         maxArea = max(maxArea , Area);
        //     }
        // }
        // return maxArea;

        int lp =0;
        int n=height.size();
        int rp = n-1;
      
        int maxArea=0;
        while(lp < rp){
            int widht = rp-lp;
            int ht = min(height[lp] , height[rp]);
            int Area=widht*ht;
            maxArea=max(maxArea,Area);
            height[lp] < height[rp] ? lp++ : rp-- ;

        }
        return maxArea;
    }
};