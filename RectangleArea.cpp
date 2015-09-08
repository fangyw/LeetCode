// Source : https://leetcode.com/problems/rectangle-area/
// Author : Yuwei Fang
// Date   : 2015-08-31

/********************************************************************************** 
 * 
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 * Each rectangle is defined by its bottom left corner and top right corner as shown in 
 * the figure.
 * 
 * Assume that the total area is never beyond the maximum possible value of int.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem, creating the above 
 * image and all test cases.
 *               
 **********************************************************************************/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C-A)*(D-B);
        int area2 = (G-E)*(H-F);
        int width = 0;
        int height = 0;
        
        if (min(C,G) > max(A,E))
            width = min(C,G) - max(A,E);
        if (min(D,H) > max(B,F))
            height = min(D,H) - max(B,F);
        return area1 + area2 - width * height;
    }
};

