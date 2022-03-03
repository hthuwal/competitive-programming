/*
Based on Welzl's Randomized algorithm with expected O(n) running time
*/

#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

/**
 * Point in 2D space
 * x = x coordinate
 * y = y coordinate
 */
typedef struct point{
    double x;
    double y;
} point;

/**
 * Circle in 2D space
 * center : Point denoting the center of the circle
 * radius : radius of the circle
 */
typedef struct circle{
    point center;
    double radius;
} circle;

/**
 * Returns a smallest circle passing through 0,1,2 or 3 given points
 * @param  R list of points upto 3 points
 * @return circle passing through all 3 points
 */
circle get_circle_directly(vector<point> R)
{
    /**
     * if only one point then that itself is the circle with 0 radius
     */
    if(R.size()==1)
    {
        circle D = {R[0],0};
        return D;
    }
    /**
     * if two points
     * then smallest circle is the one with these points as diameter
     */
    else if(R.size()==2)
    {
        point center = { (R[0].x+R[1].x)/2.0 , (R[0].y+R[1].y)/2.0}; // center is the mid point of the two given points
        double radius = sqrt( (R[1].x - R[0].x)*(R[1].x - R[0].x) + (R[1].y - R[0].y)*(R[1].y - R[0].y) ) / 2.0; 
        // radius is half the distance between them
        circle D = {center, radius};
        return D;
    }
    else
    {
        point mid1 = { (R[0].x+R[1].x)/2.0 , (R[0].y+R[1].y)/2.0}; //midpoint of R0 and R1
        double m1 = (R[1].y-R[0].y)/(R[1].x-R[0].x);  // slope of line R0R1

        point mid2 = { (R[1].x+R[2].x)/2.0 , (R[1].y+R[2].y)/2.0}; //midpoint of R1 and R2
        double m2 = (R[2].y-R[1].y)/(R[2].x-R[1].x); // slope of line R1R2
        
        point center;
        // point of intersection of perpendicular bisectors of the chords R0R1 and R1R2 is the center
        center.x = (m1*mid2.x- m2*mid1.x + m1*m2*(mid2.y-mid1.y)) / (m1-m2);  
        center.y = (mid1.x-center.x)/m1 + mid1.y;

        double radius = sqrt((center.x - R[0].x)*(center.x - R[0].x) + (center.y - R[0].y)*(center.y - R[0].y));
        circle D = {center, radius};
        return D;
    }
}

// circle mec(vector<point> P, vector<point> R)
// {
//     if(P.empty() || R.size()<=3)

// }

int main()
{
    vector<point> R;
    point p = {48,49};
    point q = {54,57};
    point r = {3,5};
    R.push_back(p);
    R.push_back(q);
    R.push_back(r);
    circle D = get_circle_directly(R);
    cout<< D.center.x <<" "<<D.center.y<<" "<<D.radius;
}