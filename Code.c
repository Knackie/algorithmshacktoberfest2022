#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int RandNumber_generator(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int Winning_comparison(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    else if (c1 == 'R' && c2 == 'S')
    {
        return 1;
    }
    else if (c2 == 'R' && c1 == 'S')
    {
        return 0;
    }
    else if (c1 == 'P' && c2 == 'R')
    {
        return 1;
    }
    else if (c2 == 'P' && c1 == 'R')
    {
        return 0;
    }

    else if (c1 == 'S' && c2 == 'P')
    {
        return 1;
    }
    else if (c2 == 'S' && c1 == 'P')
    {
        return 0;
    }
}
int main()
{
    int yourScore = 0, compScore = 0, yourinput;
    char yourChar, compChar;
    char options[] = {'R', 'P', 'S'};
    printf("\t                      Welcome to the Rock Paper Scissors\n");
    printf("\t                      ----------------------------------\n\n");


        printf("||Press 1 for Rock||\n||Press 2 for Paper||\n||Press 3 for Scissors||\n\n");
        printf("Your's turn: ");
        scanf("%d", &yourinput);
        getchar();
        
        if(yourinput==1||yourinput==2||yourinput==3)
        {
        yourChar = options[yourinput - 1];
       
        printf("                                        |||You choose: %c|||   \n", yourChar);
      

      
        printf("Computer's turn\n");
        yourinput = RandNumber_generator(3) + 1;
        compChar = options[yourinput - 1];
      
        printf("                                       ||| Computer choose: %c||| \n", compChar);
      
printf("======================================================================\n\n");
      
        if ( Winning_comparison(compChar, yourChar) == 1)
        {
            compScore++;
            printf("\t\t||COMPUTER WON||\n\n");
        }
        else if ( Winning_comparison(compChar, yourChar) == -1)
        {
            compScore++;
            yourScore++;
            printf("\t\t||DRAW||\n\n");
        }
        else
        {
            yourScore++;
            printf("\t\t||YOU WON||\n\n");
        }
        }
        else{
               printf("\t\t||INVALID INPUT||\n\n");
        }


    return 0;
}