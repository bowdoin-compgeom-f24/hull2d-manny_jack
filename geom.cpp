#include "geom.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath> 
#include <vector>

using namespace std; 

/* **************************************** */
/* returns the signed area of triangle abc. The area is positive if c
   is to the left of ab, and negative if c is to the right of ab
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



/* return 1 if c is left of ab or on ab; 0 otherwise */
int left_on(point2d a, point2d b, point2d c) {
    int cross_product = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross_product >= 0) {
      return 1;
    } else {
      return 0;
    }
  }


// compute the convex hull of pts, and store the points on the hull in hull
void graham_scan(vector<point2d>& pts, vector<point2d>& hull ) {

  printf("hull2d (graham scan): start\n"); 
  hull.clear(); //should be empty, but clear it to be safe

  //calculates the point with the minimum Y value (starting point) 
  int minY;
  point2d startPoint;
  if (pts.size() > 0) {
    // x1 = x2 = pts[0].x;
    minY = pts[0].y;
    
    for (int i=1; i< pts.size(); i++) {
      if (pts[i].y < minY){ 
        minY = pts[i].y;
        startPoint = pts[i];
      }
    }
  }
  std::swap(startPoint, pts[0]);
  // sort the remainding points in order of their ccw angle with respect to startPoint
  for (int i=1; i< pts.size() - 1; i++) {
    for (int j=1; j< pts.size() - i; j++) {
      double angle1 = atan2(pts[j].y - pts[0].y, pts[j].x - pts[0].x);
      double angle2 = atan2(pts[j + 1].y - pts[0].y, pts[j + 1].x - pts[0].x);

      if (angle1 > angle2) {
          std::swap(pts[j], pts[j + 1]);
      }
    }
  }
  hull.push_back(pts[0]);
  hull.push_back(pts[1]);

  printf("hull size %lu", hull.size());

  for (int i = 2; i < pts.size(); i++) {
      if (left_strictly(hull[hull.size()-1], hull[hull.size()-2], pts[i]) == 1){
        hull.push_back(pts[i]);
      } 
      else {
        while (hull.size() > 1 && left_strictly(hull[hull.size()-1], hull[hull.size()-2], pts[i]) == 0){
          hull.pop_back();
        }
        hull.push_back(pts[i]);
      }
  }


  //Initialize stack

  //for i=3 to n-1:
      // while pi is to the right of (second(S), first(S))
          //pop S
      //push pi to S
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