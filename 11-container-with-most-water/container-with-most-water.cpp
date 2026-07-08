class Solution {
public:
    int maxArea(vector<int>& height) {
        int st=0,ed=height.size()-1;
        int maxarea=0;
        while(st<ed){
            int width=ed-st;
            int len=min(height.at(st),height.at(ed));
            maxarea = max(maxarea,width*len);
            if(height[st]<height[ed]){
                st++;
            }
            else{
                ed--;
            }

        }
        return maxarea;

        
    }
};