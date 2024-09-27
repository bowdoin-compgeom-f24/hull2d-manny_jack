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
  double area = 0.5 * ((a.x * (b.y - c.y)) + (b.x * (c.y - a.y)) + (c.x *(a.y - b.y)));
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

int lowest_point(vector<point2d>& pts) {
    // printf("Checking Pts before looking for lowest pt\n");
    // print_points(pts); // get rid of this later
    
    int minY;
    int lowestIdx = 0;

    if (pts.size() > 0) {
      minY = pts[0].y;
      printf("REFERENCE before check: %d\n", minY);
      
      for (int i=1; i < pts.size(); i++) {
        point2d currPoint = pts[i];
        // printf("Current Point: (%d, %d)\n", currPoint.x, currPoint.y);
        // printf("Current Min: %d\n", minY);
        if (currPoint.y < minY){
          minY = pts[i].y;
          lowestIdx = i;
        }
      }
    }
    printf("reference: %d\n", pts[lowestIdx].y);
    return lowestIdx;
}

// create a compare function and use the qsort function

bool compare_angle(const point2d& reference, const point2d& a, const point2d& b ) {
  // check the angles wrt reference
  // use signed area function
  int result = signed_area2D(reference, a, b);

  //if points colinear
  if (result == 0) {
    // comparing squared distance to see who is closer to "reference" point
    int distanceA = pow((reference.x - a.x), 2) + pow((reference.y - a.y), 2);
    int distanceB = pow((reference.x - b.x), 2) + pow((reference.y - b.y), 2);
    return distanceA < distanceB;
  }

  // if 'a' has smallest angle wtr to p then result should be positive meaning:
  // b is left of vector Referance_a
  return (result > 0) ? 1 : 0;
}




/* return 1 if c is left of ab or on ab; 0 otherwise */
int left_on(point2d& a, const point2d& b, const point2d& c) {
    int cross_product = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross_product >= 0) {
      return 1;
    } else {
      return 0;
    }
  }

// TODO: figure out why hull is incorrect when n < 960 
// compute the convex hull of pts, and store the points on the hull in hull
void graham_scan(vector<point2d>& pts, vector<point2d>& hull ) {

  hull.clear(); //should be empty, but clear it to be safe

  //calculates the point with the minimum Y value (reference point) and make first in vector
  int referenceIndex = lowest_point(pts);
  point2d referencePoint = pts[referenceIndex];
  std::swap(pts[referenceIndex], pts[0]);

  // passed a lambda function that uses compare func that compares radially
  sort(pts.begin(), pts.end(), [referencePoint](const point2d& a, const point2d& b) {
    return compare_angle(referencePoint, a, b);
  });

  hull.push_back(pts[0]);
  hull.push_back(pts[1]);

  printf("hull size %lu \n", hull.size());

  for (int i = 2; i < pts.size(); i++) {

    point2d currPoint = pts[i];
    point2d currHullPoint = hull[hull.size()-1];
    point2d prevHullPoint = hull[hull.size()-2];

    while (hull.size() > 1 && left_strictly(prevHullPoint, currHullPoint, currPoint) == 0){
      hull.pop_back();
      currHullPoint = hull[hull.size()-1];
      prevHullPoint = hull[hull.size()-2];
    }
    hull.push_back(pts[i]);
  }

  printf("hull size %lu", hull.size());
  printf("hull2d (graham scan): end\n"); 
  return; 
}


  //print statements for testing:
      // printf("(%d, %d) point:", pts[0].x, pts[0].y);
      // printf("(%d, %d) point:", pts[5].x, pts[5].y);
      // printf("(%d, %d) point:", pts[2].x, pts[2].y);

      // printf("(%d)", left_on(pts[0], pts[5], pts[2]));
      // printf("(%d)", collinear (pts[0], pts[5], pts[2]));
      // printf("(%d)", signed_area2D (pts[0], pts[5], pts[2]));
      //   printf("original start point: %d %d", startPoint.x, startPoint.y);
      // printf("x: %d %d", pts[0].x, pts[0].y);
      //  printf("new start point: %d %d", startPoint.x, startPoint.y);
  //    printf("new x: %d %d", pts[0].x, pts[0].y);
  
  
  
  
  // OG SORTING
  // sort the remainding points in order of their ccw angle with respect to startPoint
  // for (int i=1; i< pts.size() - 1; i++) {
  //   for (int j=1; j< pts.size() - i; j++) {
  //     double angle1 = atan2(pts[j].y - pts[0].y, pts[j].x - pts[0].x);
  //     double angle2 = atan2(pts[j + 1].y - pts[0].y, pts[j + 1].x - pts[0].x);

  //     if (angle1 > angle2) {
  //         std::swap(pts[j], pts[j + 1]);
  //     }
  //   }
  // }
  
  // OG HULL MOD - CAN REMOVE
  // This section of graham scan is not necessary and we can just pop if next point is valid
  // and just add if the point is valid
  //     if (left_strictly(hull[hull.size()-1], hull[hull.size()-2], pts[i]) == 1){
  //       hull.push_back(pts[i]);
  //     } 
  //     else {}