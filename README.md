# hull2d-startup

### Authors: Manuel Santiago, Jack Kinsella 
FROM TOMA:
____________________________
2d convex hull startup code.  
Should compile as is.
To do: Fill in the graham_scan function and create some initializers. 
____________________________

 
Figure out the details of graham_scan and handle degeneracies in input

## TODO:
- Create 2 sets of Points to compute hull
    - At least one set with colinear points
- Write initializer function and post to #projects channel (NOT GENERAL)
- Include 5 classmates test cases in code


1. what sort of inputs constitute degeneracies for the algorithm and how you handled these degeneracies

2. pictures of the two initializers you created & pictures of the other initializers you used


- Creator: Mannny
    - ![alt text](<Screenshot 2024-10-01 at 9.11.23 PM.png>)
    - n = 2000 
    - hull: [187, 141] [312, 141] [375, 250] [312, 358] [187, 358] [125, 250]
    
- Creator Ziyou
    - ![alt text](<Screenshot 2024-10-01 at 9.22.33 PM.png>)
    - n = 2000
    hull: [125,  75] [250,  75] [250, 424] [125, 424]

- Creator Tom
    - ![alt text](<Screenshot 2024-10-01 at 9.28.00 PM.png>)
    - n = 2000
    - hull: [125, 50] [374, 50] [274, 423] [261, 424] [225, 421] [220, 418] [183, 381] [180, 376]
    [178, 372]

- Creator Tom
    - ![alt text](<Screenshot 2024-10-01 at 9.29.53 PM.png>) 
    - n = 2000
    - hull: [151, 75] [368, 75] [388, 76] [395, 88] [398, 337] [398, 346] [397, 364] [374, 419]
    [369, 426] [357, 438] [336, 455] [323, 462] [311, 467] [289, 473] [244, 473] [234, 471] 
    [215, 466] [202, 461] [175, 447] [151, 422] [143, 411] [132, 381] [126, 359] [126, 335] 
    [128, 84] [129, 83] [138, 76] 

- Creator Max and Abhi
    - ![alt text](<Screenshot 2024-10-01 at 9.37.47 PM.png>)
    - n = 1000
    - hull: [250, 0] [499, 250] [250, 499] [0, 250] 

- Creator Zelia
    -![alt text](<Screenshot 2024-10-01 at 9.57.22 PM.png>)
    - n = 2000
    - hull: [125, 125] [375, 125] [375, 375] [125, 375] 

3. pictures of the convex hulls computed for each initial configuration of points — for all these 
choose a reasonable value of n
4. if your code does not work in all cases, explain
- It does(remove this entire point later)

5. any extra features. 
- In order to have O(nlgn), we used sort() which could take a custom compare function. We passed 
this custom comparison as a lambda funciton which only exists in C++ 11 forward. This required us to
update the Makefile in for the file to compile correctly.
- For the Hexagon Initializer, I have a function that makes sure points stay on or within a 
hexaponal boundry. Assuring degenerate cases while also maintaing the hexagon shape.

6. Time you spent in: Thinking; Programming; Testing; Documenting; Total

Jack - Thinking: 1hour Programming: 30mins Testing: 30mins Documenting: 
Total:

Manny - Thinking: 1hr  Programming: 3 hrs Testing: 30mins  Documenting: Did while prgraming  
Total: 4.5

  stress.

## Brief Description:
7. Brief reflection prompts (you don’t need to address all): how challenging did you find this 
project? what did you learn by doing this project? What did you wish you did differently? If you
 worked as a team, how did that go? What would you like to explore further?

 Manny: This lab was not too challenging but getting used to C++ is what definitely slowed me down.
  For instance, I coudn't figure out why my code wouldn't compile and eventually realized it was
  because I needed to use a newer version of C++. I find the objective of this lab very interesting
  and its cool to see the algorithm produce an interesting graphic. I think me and Jack worked well
  this project and we definitely we able to work off of each others work. We were able to identify 
  each others mistakes especially when were stuck. This makes the process enoyable and relieves 

## How to Run:
To run the program all that needs to be done is:
1. Make
2. Enter "./hull2d n" where n is some positive number
3. To test algoirthm against other initializers, go into viewhull.cpp main() and swap out 
initialize_points_random for any other initializer in the file.


