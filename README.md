#### Introduction
This is the first and second assignment for the "Algorithms" course at NSYSU.

#### Assignment 1: Implement Exhaustive Search
- Try all possible solutions, trying all combinations of taking or not taking all items.
- Assume there are two items A and B:
  - Check for:
    - Having both A and B
    - Having A but not B
    - Having B but not A
- All datasets should output the best solution within 1 minute.
  - It is reasonable that ds3 cannot explore all solutions within the time limit. Please automatically output the specified file after the program runs for 1 minute.
 
#### Assignment 2: Implement Greedy Algorithm
- Prioritize the selection based on the CP value, selecting items in descending order of CP value.
- Assuming there are two items A, B, C with
  - a maximum capacity of 3
  - Values are: 10, 20, 30
  - Weights are: 2, 1, 3
- CP values from high to low: B, C, A
- Final selection: B, (skip C as it exceeds the maximum capacity when added), A
