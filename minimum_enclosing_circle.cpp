/*
Based on Welzl's Randomized algorithm with expected O(n) running time
Refer PDF with same name or this link
http://www.sunshine2k.de/coding/java/Welzl/Welzl.html
*/

#include <cstdio>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>
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
 * Value of equation of circle at point p
 */
double equation_of_circle(point p, circle gola)
{
    point c = gola.center;
    double r = gola.radius;
    return (p.x-c.x)*(p.x-c.x) + (p.y-c.y)*(p.y-c.y) - r*r;
    /* if this value < 0 => p is inside circle
                     = 0 => p is on the circle
                     > 0 => p is outside the circle
    */
}

/**
 * Checks wheter point p lies inside(and boundary) or outside the circle
 * @param  p    point 
 * @param  gola circle
 * @return      True if point is inside or on the boundary False otherwise
 */
bool isInside(point p, circle gola)
{
    double value = equation_of_circle(p, gola);
    if(equation_of_circle(p,gola) - 0.0 <= 0.0000000001)
        return true;
    return false;
}


/**
 * Returns a circle passing through 0,1,2 or 3 given points
 * @param  R list of points upto 3 points
 * @return circle passing through all 3 points
 */
circle get_circle_directly(vector<point> R)
{
	/**
	 * If no point return a circle at center origin and radius 0 (base case)
	 */
    if(R.size()==0)
    {
        circle D;
        D.center.x=0; D.center.y=0; D.radius=0;
    }
    /**
     * if only one point then that itself is the circle with 0 radius
     */
    else if(R.size()==1)
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
    /**
     * if three points
     * only one circle passes through every unique triplet of points. and its center lies on the perpendicular bisector
     * of the chords.
     */
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


/**
 * Recursive function to find the minimum enclosing circle
 * @param  P set of points to be enclosed
 * @param  R points on the boundary of mec (initially empty)
 * @return the smallest/minimum enclosing circle
 */
circle mec(vector<point> P, vector<point> R)
{
	/**
	 * if no point left to enclose or the number of points
	 * boundary is 3 (a unique circle through every three points)
	 */
    if(P.empty() || R.size()==3)
        return get_circle_directly(R);
    else
    {
        srand(time(NULL));
        /* Choose a random index in P. */
        int index = rand() % P.size(); 
        
        /*p is the point at the random index*/
        point p = P[index]; 
        
        /* remove this point from list*/ 
        P.erase(P.begin()+index);
        
        /*Find the smallest enclosing circle say D for the rest of the points*/
        circle D = mec(P, R);

        /** if the removed point p does not lies inside D then we need a bigger circle
         *  smallest bigger circle will have the point p just on its boundary and rest on its inside
         */
        if(!isInside(p,D))
        {
        	/* push p in the list of boundary points */
            R.push_back(p); 
            /* find the smallest enclosing circle for rest of the points with 'p' on the boundary of that circle */
            circle D = mec(P,R); 
            return D; 
        }

        /** if the removed point lies inside then this is the smallest enclosing circle */
        return D;
    }
}   

int main()
{
    int n;
    vector<point> P;
    vector<point> R;
    point p;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf",&p.x,&p.y);
        P.push_back(p);
    }

    printf("%0.2lf\n",mec(P,R).radius * 2);
}