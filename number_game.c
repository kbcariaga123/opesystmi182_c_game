#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int main(void) { 

 int player_num = 0; int number = 0; int player_input = 0;
 int guess = 0; char input; char str[15] = {0}; // size was increased to compensate for pass pass input
 int Player_1 = 1;
 int Player_2 = 2; int Pass_1 = 3; int Pass_2 = 3; int i = 1;
 int player_turn = 0; int turn = 0; int alternate=0;
 int player1Flag=0,player2Flag=0;

 int lastPlayer=0;

 srand(time(NULL));  
 player_num = 1 + rand() % 2; /* Random number is generated */
 lastPlayer = player_num;
 number = 0 + rand() % 100; /* Random number is generated */

  while(number != guess) {

      while (player_num != player_input)    {
           printf("\nIt's player's %d turn\n", player_num);
           printf("Player Number?\n");
           scanf("%d", &player_input);
           getchar();// to get rid of \n after the input

           if(player_input!=player_num){
               printf("You Have to wait your turn.\n");
           }

      }

      if (Player_1 != player_num) Player_2 = player_num;


      printf("Enter Your Guess, 0 - 100 or Pass: ");

      scanf("%s",str);

     if (strcmp(str, "pass") == 0){
        if (player_num == Player_1){
            player1Flag = player1Flag+1; // flag to detect if last input was a pass

            if(player1Flag>1){
                printf("Dude you passed in your last attempt .. dont be a pus*y\nEnter a guess : ");
                scanf("%s",&str);
                guess = atoi(str);
                if(guess < number){ /* if the guess is lower, output: the guess is too low */
                   printf("Your guess was to low.\n ");
                }else if(guess > number){ /* if the guess is higher, output: the guess is too high */
                   printf("Your guess was to high.\n ");
                }else{ /* if the guess is equal to the random number: Success!! */
                   printf("Yes!! you got it!\n");
                }
                player1Flag = 0; // reset the pass flag = 1 as this pass isn't counted
            }else{
                Pass_2 = Pass_2 -1;
                if(Pass_2<0){
                    printf("You have already passed Thrice\nEnter a guess: ");
                    scanf("%s",&str);
                    guess = atoi(str);
                    if(guess < number){ /* if the guess is lower, output: the guess is too low */
                       printf("Your guess was to low.\n ");
                    }else if(guess > number){ /* if the guess is higher, output: the guess is too high */
                       printf("Your guess was to high.\n ");
                    }else{ /* if the guess is equal to the random number: Success!! */
                       printf("Yes!! you got it!\n");
                    }
                }else{
                    printf("Player 1 has %d more 'Pass' left!\n", Pass_2);
                }
            }
        }   
        else{

            player2Flag = player2Flag + 1;

            if(player2Flag>1){
                printf("Dude you passed in your last attempt .. dont be a pus*y\nEnter a guess : ");
                scanf("%s",&str);
                guess = atoi(str);
                if(guess < number){ /* if the guess is lower, output: the guess is too low */
                   printf("Your guess was to low.\n ");
                }else if(guess > number){ /* if the guess is higher, output: the guess is too high */
                   printf("Your guess was to high.\n ");
                }else{ /* if the guess is equal to the random number: Success!! */
                   printf("Yes!! you got it!\n");
                }
                player2Flag=0;// reset the player2Flag = 1 as this pass isn't counted
            }else{
                Pass_1 = Pass_1 -1;
                if(Pass_2<0){
                    printf("You have already passed Thrice\nEnter a guess: ");
                    scanf("%s",&str);
                    guess = atoi(str);
                    if(guess < number){ /* if the guess is lower, output: the guess is too low */
                       printf("Your guess was to low.\n ");
                    }else if(guess > number){ /* if the guess is higher, output: the guess is too high */
                       printf("Your guess was to high.\n ");
                    }else{ /* if the guess is equal to the random number: Success!! */
                       printf("Yes!! you got it!\n");
                    }
                }else{
                    printf("Player 2 has %d more 'Pass' left!\n", Pass_2);
                }
            }
        }   

     }else {

        if (player_num == Player_1){
            player1Flag = 0;//reset pass flag as this player enetered a guess
        }else{
            player2Flag = 0;
        }

        guess = atoi(str);
    
