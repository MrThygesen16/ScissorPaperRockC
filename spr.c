#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// struct for holding # moves, the name of the game, what moves, etc.
typedef struct{
    int index; // position in the array of game-structs
    int numMoves; // how many moves in the game (e.g. Scissor paper rock has 3 moves)
    char name[50]; // name of the game being played
    char *moveList[5]; // allow players to choose from the list of moves
    char combinationList[5][5]; // for holding the win/loss/draw combinations
} GameTypes;


// method for extracting user selections (i.e. numbers that corrleate to some option)
int userSelection(char *str){
    printf("%s", str);

    char out[10];
    fgets(out, 10, stdin);

    // if the input contains a decimal point -- we return -1 (not valid)
    if(strstr(out, ".") != NULL || strlen(out) > 2 ) {
        return -1;
    }
    
    // convert the input to ascii value (aka decimal)
    int temp = (int)(out[0]);

    // limit the range of possible numbers... to ascii values 49 & 59
    // 49 in ascii is the number 0, 59 in ascii is the number 7
    if (temp >= 49 && temp <= 59){
       int num = atoi(out);
       return num;
    } 

    // if the input falls out of this range, return -1 because it is invalid
    return -1;
}

void numWins(int winner){
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    // 0th is player wins, 1st is computer wins...
    int results[2];

    // first we read data from the text file and put it into the results array
    fp = fopen("wins.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        results[i] = atoi(line);
        i++;
    }
    fclose(fp);

    // if the input is 1, the player won, add 1 to their score
    // else it's -1 and computer won, so we add 1 to the computer score
    if (winner == 1){
        results[0] += 1;
    } else {
        results[1] += 1;
    }

    // once we read and update the scores in that array, we rewrite these values back to the text file
    // overwriting the scores
    fp = fopen("wins.txt", "w");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < 2; i++){
        fprintf(fp, "%d\n", results[i]);
    }
    fclose(fp);
    if (line){
        free(line);
    }

    // once we have read, updated, and overwrote the # wins and losses
    // we display them to the screen
    printf("\n\nPlayer Wins: %d\n\n", results[0]);
    printf("\n\nComputer Wins: %d\n\n", results[1]);

    // program ends
    exit(EXIT_SUCCESS);
}


// programs starts here
int main(){

    char name[50];
    int pWin = 0;
    int cpuWin = 0;
    int numTies = 0;
    
    int gameRun = 1;

    // ASCII ART DO NO CHANGE!
    char *asciiArt[5] = {

        "_       ,/'  \n(_).  ,/'  \n_   :: \n(_)'  `\\.  \n        `\\." ,
        

        "   ________\n   /       /,\n  / PAPER //   \n /_______//  \n(_______(/", 
        
        "      \n________________________  \n|                  - (  |  \n,'-.                . `-| \n(____'.     ,-.    '   || \n|          /\\,-\\   ,-.  | \n|      ,-./     \\ /'.-\\ | \n|     /-.,\\      /     \\| \n|    /     \\    ,-.     \\ \n|___/_______\\__/___\\_____\\ ", 
        
       "  __  ,\n  (' \\ \\ \n   \\ \\/ \n '\\/\\ \\ \n     \\ \\/\\, \n      \\ \\ \n      /\\ \\ \n      \\ `\\\\ \n      '   `\\ \n            \\ \n             \\ \n              \\ \n              `---'",
        
        "   ___-___  o==o======   .   .   .   .   . \n =========== ||// \n         \\ \\ |//__ \n          #_______/"


    };

    GameTypes games[2] = { 
        //      index #-moves   name of game       move-set                         # combinations for W/L
                  {0, 3, {"Scissor paper rock"}, {"Scissor", "Paper", "Rock"}, { {'T', 'L', 'W'} } }, 
                  {1, 5, {"Scissor paper rock lizard spock"}, {"Scissor", "Paper", "Rock", "Lizard", "Spock"}, { {'T', 'L', 'W', 'L', 'W'} }  },
    };

    // should only ever be deckared once in main...
    srand(time(NULL));

    printf("What is your name: ");
    fgets(name, 10, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("\nHello, %s! Welcome to Scissor Paper Rock.\n===================\n\n", name);

    int numGameTypes = 2;
    int gameChoice = 0;

    // while loop for allowing the user to pick which game-mode they want to play
    int gameSelected = -1;
    while (gameSelected == -1){
        gameChoice = userSelection("Would you like to play: \n1. Classic SPR \n2. SPR + Lizard & Spock\n\nChoice: ");


        if (gameChoice >= 1 && gameChoice <= numGameTypes){
            // the games struct has it that all game-types have a value associated with it's index
            gameChoice = games[gameChoice-1].index;
            gameSelected = 1;
        } else {
            printf("\nInvalid Selection!\n\n");
        }
    }

    printf("Playing: %s\n\n", games[gameChoice].name);

    // initialise diaganols (0,0), (1,1) etc. as ties
    for (int i = 1; i < games[gameChoice].numMoves; i++){
        games[gameChoice].combinationList[i][i] = 'T';
    }
        
    // fill out combinations table based on initial values... & what game type is chosen
    // start at row = 1, since row at 0 is already initialised ...
    // while we get space cost of storing the games, we only have to calculate the cells for the game chosen by the user... O(n^2)
    for (int i = 1; i < games[gameChoice].numMoves; i++){
        for (int j = 0; j < games[gameChoice].numMoves; j++){
           
            // if the current cell is not a tie cell, we check what to put as the value of this cell, 
            // based on the cell above...
            if (games[gameChoice].combinationList[i][j] != 'T'){
                    // if cell above is a tie, current cell is a win
                if (games[gameChoice].combinationList[i-1][j] == 'T'){
                    games[gameChoice].combinationList[i][j] = 'W';
                
                // if cell above is a win, current cell is a loss
                } else if (games[gameChoice].combinationList[i-1][j] == 'W'){
                    games[gameChoice].combinationList[i][j] = 'L';

                // all other cases, i.e. cell above is a loss, then current cell is a win
                } else {
                    games[gameChoice].combinationList[i][j] = 'W';
                }
            }
        }
    }

    // use struct to determine # of moves for a game
    int possibleMoves = games[gameChoice].numMoves;

    // game is now running...
    while (gameRun == 1){



        // holds whether the user has selected their move or not
        int selected = 0;

        while (selected == 0){


            printf("Please choose from the following: \n");

            for (int i = 0; i < possibleMoves; i++){
                printf("%d. %s\n", i+1,games[gameChoice].moveList[i]);
            }

            int choice = userSelection("\n\nChoice: ");

            if (choice >= 1 && choice <= possibleMoves){

                int cpuChoice = (rand() % possibleMoves) + 1; 
                
                printf("\n%s Chose: %s\n", name, games[gameChoice].moveList[choice-1]);
                printf("Computer Chose: %s\n\n", games[gameChoice].moveList[cpuChoice-1]);


                printf("\n\n %s \n\n vs. \n\n %s \n\n", asciiArt[choice-1], asciiArt[cpuChoice-1]);

                // use look up table for reference 
                char res = games[gameChoice].combinationList[cpuChoice-1][choice-1];

                //char res = combinations[cpuChoice-1][choice-1];

                // check for win, loss, else draw
                // W = win, L = loss, T = Tie (no need to check for ties)
                if (res == 'W'){
                    pWin = pWin + 1;
                    printf("%s won that round!\n", name);
                } else if (res == 'L'){
                    cpuWin = cpuWin + 1;
                    printf("%s lost that round :(\n", name);
                } else {
                    numTies = numTies + 1;
                    printf("Round was a tie\n");
                }
          
                selected = 1;

            } else {
                
                printf("\nInvalid choice, please choose again!\n\n");

            }

           
        }

        printf("\n===================");
        printf("\n%s wins: %d\n", name,pWin);
        printf("Number of ties: %d\n", numTies);
        printf("Computer wins: %d\n", cpuWin);
        printf("===================\n\n");

        if (pWin >= 2 || cpuWin >= 2){
            gameRun = 0;
        }

    }

    int won = 0;
   // check who won after # rounds
    if (pWin > cpuWin){
        printf("\n%s is the Winner!\n\n", name);
        won = 1;
    } else if (pWin < cpuWin){
        printf("\n%s lost... :( \n\n", name);
        won = -1;
    }

    numWins(won);

    return 0;
}