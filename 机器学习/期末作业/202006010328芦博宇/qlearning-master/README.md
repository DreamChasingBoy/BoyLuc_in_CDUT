# qlearning
Matlab tutorial for qlearning

for details type 
##### help qlearning 
in the working directory 

Q learning

Two input: R and gamma

immediate reward matrix; 
   
row(depart) and column(target) = states; -Inf = no door between room
   
The goal room is F, so the doors that lead immediately to the goal have instant reward of 100 

|   | A |B  | C | D | E | F |
|---|:-:|--:|--:|--:|--:|--:|
| A |   |   |   |   | 1 |   |
| B |   |   |   | 1 |   | 1 |
| C |   |   |   | 1 |   |   |
| D |   | 1 | 1 |   | 1 |   |
| E | 1 |   |   | 1 |   | 1 |
| F |   | 1 |   |   | 1 | 1 |
