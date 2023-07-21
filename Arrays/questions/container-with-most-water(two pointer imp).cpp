int maxArea(vector<int>& height) {
    int leftPillar = 0;
    int rightPillar = height.size()-1;
    int maxArea = INT_MIN;

    while(leftPillar<=rightPillar){
        int area = min(height[leftPillar],height[rightPillar]) * (rightPillar-leftPillar);

        maxArea = max(maxArea,area);

        if(height[leftPillar] < height[rightPillar]){
            leftPillar++;
        }else{
            rightPillar--;
        }
    }
    return maxArea;
}