# hull2d-startup
### Authors: Manuel Santiago, Jack Kinsella s
Figure out the details of graham_scan and handle degeneracies in input

## Report:

1. what sort of inputs constitute degeneracies for the algorithm and how you handled these degeneracies?

The main type of inputs that constitute degeneracies are those which contain colinear points, such as points in a horizontal or vertical line, or many points along the sides of a shape. In order to handle these and ensure that the hull only contains the extreme points on the hull, we use the left_strictly function. Because the function returns a 0 for any right turns or colinear points, we pop the previous point if the result of that function is not 1. This will continue adding and popping points to the hull until we reach the final point which will be added, ensuring that the hull only contains extreme points. 

2. pictures of the two initializers you created & pictures of the other initializers you used

- Creator: Mannny
    - ![alt text](<Screenshot 2024-10-01 at 9.11.23 PM.png>)
    - n = 2000 
    - hull: [187, 141] [312, 141] [375, 250] [312, 358] [187, 358] [125, 250]

- Creator: Jack
    - ![alt text](<Screenshot 2024-10-02 at 10.56.08 am.png>)
    - n = 2000 
    - hull: hull: [ 46, 150] [488, 150] [490, 154] [492, 162] [493, 167] [494, 173] [495, 180] [497, 196] [499, 214] [459, 344] [457, 348] [456, 349] [ 15, 349] [ 14, 348] [ 13, 346] [ 12, 343] [ 11, 339] [ 10, 334] [  9, 328] [  7, 314] [  6, 306] [  3, 279] [  0, 250] [ 44, 154] 
    
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
- Our code works in all cases

5. any extra features. 
- In order to have O(nlgn), we used sort() which could take a custom compare function. We passed 
this custom comparison as a lambda funciton which only exists in C++ 11 forward. This required us to
update the Makefile in for the file to compile correctly.
- For the Hexagon Initializer, I have a function that makes sure points stay on or within a 
hexaponal boundry. Assuring degenerate cases while also maintaing the hexagon shape.

6. Time you spent in: Thinking; Programming; Testing; Documenting; Total

Jack - Thinking: 1hour Programming: 2hrs 30mins Testing: 1hr 30 mins Documenting: Did while programming
Total: 5

Manny - Thinking: 1hr  Programming: 3 hrs Testing: 30mins  Documenting: Did while programming  
Total: 4.5

## Brief Description:
7. Brief reflection prompts (you don’t need to address all): how challenging did you find this project? what did you learn by doing this project? What did you wish you did differently? If you worked as a team, how did that go? What would you like to explore further?

 Manny: This lab was not too challenging but getting used to C++ is what definitely slowed me down.
  For instance, I coudn't figure out why my code wouldn't compile and eventually realized it was
  because I needed to use a newer version of C++. I find the objective of this lab very interesting
  and its cool to see the algorithm produce an interesting graphic. I think me and Jack worked well
  this project and we definitely we able to work off of each others work. We were able to identify 
  each others mistakes especially when were stuck. This makes the process enoyable and relieves stress.

Jack: I agree with Manny that the lab was not too challenging. We were able to plan out our functions and overall 
    program well and that definetely made the coding process easier. The one aspect that I did find more challenging was 
    developing my initializer. It may have just been me but it took me a while to get my points to get into the right shape I
    wanted. However, it was very rewarding to get it working and I enjoyed the visual aspect of the project. One thing I wish we could have done differently was testing our code more frequently while we were coding. There were two instances where we had made a small error in a function but spent a while debugging the whole program because we weren't sure what caused the issue. That being said, Manny and I did work well with each other and being able to go over the code with someone else did make it much easier to spot those mistakes. 

## How to Run:
To run the program all that needs to be done is:
1. Make
2. Enter "./hull2d n" where n is some positive number
3. To test algoirthm against other initializers, press i and it will cycle through the 10 different initializers we have


