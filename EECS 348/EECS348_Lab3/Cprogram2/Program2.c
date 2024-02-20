// Author: Joon Hee Ooten
// Date: 2/8/23
// C Program 2
#include <stdio.h>
#include <stdlib.h>

//function for user input
int getUserInput(int myNum){
        printf("\n\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d%*c", &myNum);
        return myNum;
}

//prints the score
void printScore(int *scores){
    char *score_Methods[] = {"TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety"};
    printf("%d %s %d %s %d %s %d %s %d %s\n", scores[4], score_Methods[0], scores[3], score_Methods[1], scores[2], score_Methods[2], scores[1], score_Methods[3], scores[0], score_Methods[4]);
}

//function for counting the score
int scoreCounter(int score_Points[], int n, int sum, int *scores, int scoreIncrease)
{
    if (scoreIncrease == 1)
    {scores[n-1] = scores[n-1] + 1;}

    if (sum < 0)    // Not a valid option 
    {
        scores[n-1] = 0; 
        return 0;
    }

    if (n <= 0)     // End of ways to score
    {
        scores[n-1] = 0;
        return 0;
    }

    if (sum == 0)   // One possible option of scoring
    {
        printScore(scores);
        for (int i; i < 5; i++)
            {scores[i] = 0;}
        return 1;
    }
   
        return scoreCounter(score_Points, n - 1, sum, scores, 0) + scoreCounter(score_Points, n, sum - score_Points[n - 1], scores, 1);
    
}

//main function
int main()
{
    int myNum = -1; //Used for the starting number
    while ((myNum!= 0) && (myNum != 1))
    {
        myNum = getUserInput(myNum);
        
        int scorePoints[] = {2, 3, 6, 7, 8};
        int scoreCount[5] = {0, 0, 0, 0, 0};

        scoreCounter(scorePoints, 5, myNum, scoreCount, 0);
    }
    return 0;
}
