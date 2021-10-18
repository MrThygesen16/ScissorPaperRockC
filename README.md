# Scissor Paper Rock C



Simple project in C that can play two versions of Scissor Paper Rock:

1. Original
2. Scissor Paper Rock Lizard Spock



Furthermore, there is a text file `wins.txt` for keeping track of wins for the player and the computer...

The top number is number of player/person wins.
The bottom number is the number of wins for the computer.

```
8
4
```



**Example of Game Running**

```
What is your name: Mike

Hello, Mike! Welcome to Scissor Paper Rock.
===================

Would you like to play:
1. Classic SPR
2. SPR + Lizard & Spock

Choice: 2
Playing: Scissor paper rock lizard spock

Please choose from the following:
1. Scissor
2. Paper
3. Rock
4. Lizard
5. Spock


Choice: 5

Mike Chose: Spock
Computer Chose: Spock



    ___-___  o==o======   .   .   .   .   .
 =========== ||//
         \ \ |//__
          #_______/

 vs.

    ___-___  o==o======   .   .   .   .   .
 =========== ||//
         \ \ |//__
          #_______/

Round was a tie

===================
Mike wins: 0
Number of ties: 1
Computer wins: 0
===================

Please choose from the following:
1. Scissor
2. Paper
3. Rock
4. Lizard
5. Spock


Choice: 4

Mike Chose: Lizard
Computer Chose: Spock



   __  ,
  (' \ \
   \ \/
 '\/\ \
     \ \/\,
      \ \
      /\ \
      \ `\\
      '   `\
            \
             \
              \
              `---'

 vs.

    ___-___  o==o======   .   .   .   .   .
 =========== ||//
         \ \ |//__
          #_______/

Mike won that round!

===================
Mike wins: 1
Number of ties: 1
Computer wins: 0
===================

Please choose from the following:
1. Scissor
2. Paper
3. Rock
4. Lizard
5. Spock


Choice: 1

Mike Chose: Scissor
Computer Chose: Scissor



 _       ,/'
(_).  ,/'
_   ::
(_)'  `\.
        `\.

 vs.

 _       ,/'
(_).  ,/'
_   ::
(_)'  `\.
        `\.

Round was a tie

===================
Mike wins: 1
Number of ties: 2
Computer wins: 0
===================

Please choose from the following:
1. Scissor
2. Paper
3. Rock
4. Lizard
5. Spock


Choice: 2

Mike Chose: Paper
Computer Chose: Rock



    ________
   /       /,
  / PAPER //
 /_______//
(_______(/

 vs.


________________________
|                  - (  |
,'-.                . `-|
(____'.     ,-.    '   ||
|          /\,-\   ,-.  |
|      ,-./     \ /'.-\ |
|     /-.,\      /     \|
|    /     \    ,-.     \
|___/_______\__/___\_____\

Mike won that round!

===================
Mike wins: 2
Number of ties: 2
Computer wins: 0
===================


Mike is the Winner!



Player Wins: 11



Computer Wins: 4
```



The above shows what the game might look like when playing.



**Scissor Paper Rock Ascii Art**

```
 _       ,/'
(_).  ,/'
_   ::
(_)'  `\.
        `\.
        
        
    ________
   /       /,
  / PAPER //
 /_______//
(_______(/


________________________
|                  - (  |
,'-.                . `-|
(____'.     ,-.    '   ||
|          /\,-\   ,-.  |
|      ,-./     \ /'.-\ |
|     /-.,\      /     \|
|    /     \    ,-.     \
|___/_______\__/___\_____\
```



**Lizard and Spock Ascii Art**

```
       __  ,
  (' \ \
   \ \/
 '\/\ \
     \ \/\,
      \ \
      /\ \
      \ `\\
      '   `\
            \
             \
              \
              `---'
    
    
    ___-___  o==o======   .   .   .   .   .
 =========== ||//
         \ \ |//__
          #_______/

```







NB: All ascii art was found online; none of them belong to, or were created by me.
