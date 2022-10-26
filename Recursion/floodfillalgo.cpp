#include<iostream>
#include <vector>
using namespace std;

/*
   - An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
   - You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel
     image[sr][sc].
   - To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting
     pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels
     (also with the same color), and so on.
   - return the new image.
*/



void flood(int i,int j,vector<vector<int>>& image,int oldColor,int newColor,int n,int m){
        if(i<0 || j<0||i==n||j==m|| image[i][j]!=oldColor) return;
        image[i][j] = newColor;
        flood(i+1,j,image,oldColor,newColor,n,m);
        flood(i-1,j,image,oldColor,newColor,n,m);
        flood(i,j+1,image,oldColor,newColor,n,m);
        flood(i,j-1,image,oldColor,newColor,n,m);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        int n = image.size(),m = image[0].size();
        flood(sr,sc,image,oldColor,color,n,m);
        return image;

}
