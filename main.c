//
//  main.c
//  alphabetical order
//
//  Created by Ahmed Almansor on 4/4/17.
//  Copyright © 2017. All rights reserved.
//
#include <stdio.h>     // I/O library
#include <string.h>   //string library
#include <stdbool.h>  //boolean library
#include <ctype.h>  // C library
#include <stdio.h>

char* AlphaOrder(char s[]){
    //This function will get a string as an input and resort the letters of each word alphabetically and return a new
    // string with new order.
    // Steps used to solve the problem:1-Split the word in the string 2-Compare letters 3- resort alphabetically
    char temp;   // To store the letter that is going to be replaced.
    int LCount;   // To count how many letters in the word in order to split the string.
    int tempPos = 0;   // To hold the temp position after finding the word to start searching for Letters.
    int SSize = strlen(s)-1; // To store the size of the inputted string to illustrate through.
    int c = 0;   // This will be used as the position of the next letter of the word to be compared to the previous letter.
    
    for (int i=0; i <= SSize; i++){   // Main for-loop to illustrate through orignal string
        if (isspace(s[i])){             // This condition statment is to stop when there is a space, Whole word found!
            tempPos = (i-LCount);     // Temp Position that will hold the position of the first letter in the word, so it make it easy to illustrate the word found.
            for (int j = 0; j < LCount; j++){ // illustrate through the word.
                c = tempPos;                   // to be used as the position to the next letter.
                while (true){                  // while loop used as tool to make it easy to check all letters in the word with each letter respectively.
                    // 2 conditions: one for Upper case letter, The other is for lower case letter.
                    if ((s[tempPos] < 97)){  // This block is used if a upper letter case is inputted. (97 is 'a', smallest value of lower case letter).
                        char tc = s[tempPos]+32; // hold the letter in temp char.
                        if (tc > s[c]){  // check if it is bigger than the next letter then do the swap if true.
                            temp = s[c];
                            s[c] = s[tempPos];
                            s[tempPos] = temp;
                        }
                    }
                    else{     			 // This condition is if the letter is lower case.
                        if (s[tempPos] > s[c]){
                            temp = s[c];
                            s[c] = s[tempPos];
                            s[tempPos] = temp;}
                        
                    }                   //if the comparing is done move to the next letter and break the loop.
                    if (c == (i-1)){
                        tempPos++;
                        break;}
                    else{c++;}  // else move to the next letter to be compared.
                }
            }
            LCount = 0;    //  to zero out the word count for  a new word.
        }
        else {     // This is the second condition if for loop is going through the letters in the loop.
            if (i == SSize){   // This condition is for safty reason: if there is no space at the end of the string.
                // this block code will illustrate through the word and do the swapping.
                tempPos = (i-LCount);
                for (int j = 0; j < LCount; j++){
                    c = tempPos;
                    while (true){
                        if ((s[tempPos] < 97)){
                            char tc = s[tempPos]+32;
                            if (tc > s[c]){
                                temp = s[c];
                                s[c] = s[tempPos];
                                s[tempPos] = temp;
                            }
                        }
                        else{
                            if (s[tempPos] > s[c]){
                                temp = s[c];
                                s[c] = s[tempPos];
                                s[tempPos] = temp;}
                        }
                        if (c == (i)){
                            tempPos++;
                            break;}
                        else{c++;}
                    }
                }
            }
            else{LCount++;}  // Else count letters
        }
    }
    return s; // return the string.
}

    int main(){
        char   c[512]; 					//a string to store string inputted
        
        printf("Write the desired sentence: \n");   // Statment will be displayed for the user asking for prompt.
        gets(c);                           // get string from the terminal until user hit "Enter".
        
        
        printf("%s <- Alphabatically Sorted \n", AlphaOrder(c));     // print funtion for Alphabatically Ordered String
        
        return 0;
}
