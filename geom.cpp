#include "geom.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 
#include <vector>
#include <algorithm>

using namespace std; 

/* **************************************** */
/* returns the signed area of triangle abc. The area is positive if c
   is to the left of ab, negative if c is to the right of ab, and zero if points are colinear
 */
int signed_area2D(point2d a, point2d b, point2d c) {
  int area = ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x *(a.y - b.y)));
  return area; 
}


/* **************************************** */
/* return 1 if p,q,r collinear, and 0 otherwise */
int collinear(point2d p, point2d q, point2d r) {
  int cross_product = (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
  if (cross_product == 0) {
    return 1;
  } else {
    return 0;
  }
}


/* **************************************** */
/* return 1 if c is  strictly left of ab; 0 otherwise */
int left_strictly(point2d a, point2d b, point2d c) {
    int cross_product = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross_product > 0) {
      return 1;
    } else {
      return 0;
    }
  }


void print_points(vector<point2d>& pts) {
  for (int i = 0; i < pts.size(); i++) {
      point2d currPoint = pts[i];
      printf("Point %d: (%d, %d) \n", i, currPoint.x, currPoint.y);
  }
}


/* **************************************** */
/* returns the index of the point with the minimum Y coordinate*/
int lowest_point(vector<point2d>& pts) {
    point2d min;
    int lowestIdx = 0;

    if (pts.size() > 0) {
      min = pts[0];
      printf("REFERENCE before check: %d\n", min.y);
      
      for (int i=1; i < pts.size(); i++) {
        point2d currPoint = pts[i];
        if (currPoint.y < min.y || (currPoint.y == min.y && currPoint.x < min.x)){
          min = pts[i];
          lowestIdx = i;
        }
      }
    }
    printf("reference: %d\n", pts[lowestIdx].y);
    return lowestIdx;
}


/* **************************************** */
/* return 1 if a has a smaller angle wtr to reference point than b*/
bool compare_angle(const point2d& reference, const point2d& a, const point2d& b ) {
  // check the angles wrt reference
  // use signed area function
  int result = signed_area2D(reference, a, b);

  //if points colinear
  if (result == 0) {
    // comparing squared distance to see who is closer to "reference" point
    int distanceA = pow((a.x - reference.x), 2) + pow((a.y - reference.y), 2);
    int distanceB = pow((b.x - reference.x), 2) + pow((b.y - reference.y), 2);
    return distanceA < distanceB;
  }
  // if 'a' has smallest angle wtr to p then result should be positive meaning:
  // b is left of vector Referance_a
  return (result > 0) ? 1 : 0;
}


/* **************************************** */
/* return 1 if c is left of ab or on ab; 0 otherwise */
int left_on(point2d& a, const point2d& b, const point2d& c) {
    int cross_product = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross_product >= 0) {
      return 1;
    } else {
      return 0;
    }
  }
  

/* **************************************** */
/* computes the convex hull of a set of points, ensuring only the extreme points are included */
void graham_scan(vector<point2d>& pts, vector<point2d>& hull) {
    hull.clear();  // Clear the hull to be safe

    // Swap startPoint with the first element
    int referenceIndex = lowest_point(pts);
    point2d referencePoint = pts[referenceIndex];
    std::swap(pts[referenceIndex], pts[0]);

    // // Sort the remaining points by their CCW angle with respect to startPoint
      // passed a lambda function that uses compare func that compares radially
    stable_sort(pts.begin(), pts.end(), [referencePoint](const point2d& a, const point2d& b) {
    return compare_angle(referencePoint, a, b);
  });

    // Construct the convex hull
    hull.push_back(pts[0]);
    hull.push_back(pts[1]);
    hull.push_back(pts[2]);

    for (int i = 3; i < pts.size(); i++) {
        while (hull.size() > 1 && !left_strictly(hull[hull.size() - 2], hull[hull.size() - 1], pts[i])) {
            hull.pop_back();  // Remove point if it's not a left turn (including if the point is colinear)
        }
        hull.push_back(pts[i]);
    }
}
  
  
