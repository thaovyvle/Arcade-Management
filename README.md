# Arcade Management
Programming Language: C

Given a list of people entering and leaving the arcade, determine at certain (specified) moments the most valuable player. Use of linked lists and stacks

# Story
You opened a retro arcade using the capital obtained from your handle generator venture. It’s pretty popular among the denizens of Gameland. Most people in Gameland have never seen an arcade before woah. You have decided to list the most valuable player (in this case the person in your store that entered with the most amount of money).

The problem you are having is that your system only records two events: 1) the name and the amount of money held by the player entering or 2) if someone is leaving (the system does not say who). Luckily, people like your arcade so much that they refuse to leave before everyone that arrived AFTER them has already left. It makes it very easy to determine who exits when someone leaves.

# Input
Each line of input will start with a non-negative integer, t (0 ≤ t ≤ 3), representing the type of line to process. If t is 0, then the day is over and the program should terminate. If t is 1, then the program should read in the following player information that is entering the arcade. The player’s information is composed of two values separated by a space, an integer, M, and string, S (1 ≤ M ≤ 109, 1 ≤ |S| ≤ 20), representing the amount of money in tokens and the name of the player entering. If t is 2, then the program should process a player leaving. No further information is provided when t is 2. If t is 3, then your program should output the most valuable player in the arcade.

# Output
Output should contain 1 line for each 3 entered. Each line will contain the name of the most valuable player at the time of the request. If two players entered with the same amount of money, print the most recent one (they have probably spent less money than the other one).

## Sample Input: #1
```text
  1 5 Eric
  1 10 John
  1 2 Kate
  3
  1 30 Ash
  3
  2
  2
  3
  2
  3
  0
```

## Sample Output: #1
```text
  John
  Ash
  John
  Eric
```

Explanation:

<img width="479" alt="Screenshot 2024-02-22 at 6 17 54 PM" src="https://github.com/thaovyvle/Arcade-Management/assets/122627050/9625745a-0bbd-4638-ae6b-82e6bd904ae1">

## Sample Input: #2
```text
  1 3 Josh
  1 4 Grace
  3
  1 5 isASoreLoser
  3
  1 6 RealFunnyJosh
  3
  3
  2
  2
  2
  3
  2
  0
```

## Sample Output: #2
```text
  Grace
  isASoreLoser
  RealFunnyJosh
  RealFunnyJosh
  Josh
```

Explanation: 

<img width="373" alt="Screenshot 2024-02-22 at 6 21 22 PM" src="https://github.com/thaovyvle/Arcade-Management/assets/122627050/0699c783-ce46-4049-a022-25bef9211173">

