#include <stdio.h>
#include <string.h>
#include <time.h>
#include "logo.h"
#include "hangman_word.h"

int main()
{
    //print logo for the game
    print_logo();


    char rand_word[100];
    char guess_word[100];
    int lives = 6, end_game = 0;


    //take a random word from header file
    strcpy(rand_word , word_list());
    printf("%s", rand_word);

    //count the length of random word
    int len = strlen(rand_word);

    //start the game
    printf("\n\nYou have six lives to guess the correct word or you are hanged.\n");

    while(end_game != 1)
    {
        //ask user for a latter
        printf("\nGuess a latter: ");


        int correct = 0, space = 0;
        char ch;


        //read a latter
        scanf("%c", &ch);
        fflush(stdin);
        printf("\n");


        //check if user is correct
        for(int i = 0; i < len; i++)
        {
            //if user is guess this word already
            if(ch == guess_word[i]){
                printf("You've already guessed %c.\n", ch);
                correct++;
                break;
            }
            //if user is not guess this word already
            if(ch == rand_word[i] && ch != guess_word[i])
            {
                guess_word[i] = ch;
                correct++;
            }
        }

        //if user is not correct
        if(correct == 0)
        {
            //lose a life
            lives--;
            if(lives != 0)
            {
                printf("You guess %c, that's not in the word. You lose a life.\n", ch);
                printf("You have %d life\n", lives);
            }

            //when life is equal to 0
            else
            {
                printf("You guess %c, that's not in the word. You lose a life.\n", ch);
                printf("You lose. You are hanged.\n\n");
                //end the game
                end_game = 1;
            }
        }


        //display how many latter they correct
        for(int i = 0; i < len; i++)
        {
            if(guess_word[i] == rand_word[i])
            {
                printf("%c ", guess_word[i]);
            }
            else
            {
                printf("_ ");
                space++;
            }
        }


        //check if they guess the correct word
        if(space == 0)
        {
            printf("\nYou won.\n");
            //end the game
            end_game = 1;
        }

    }


    return 0;
}
