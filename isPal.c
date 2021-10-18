#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isAPal(char *str){
    
    // hold where we are in the string
    int j = strlen(str)-1;
    int i = 0;

    // once i > j, we have crossed over to characters we have already checked
    while (i <= j){

        // these are essentially "pointers"
        // we are using the ascii values 
        int p1 = str[i];
        int p2 = str[j];

        // ascii chars start at 65 'A', and end at 90 'Z'
        // if add 32 to it to make it lower case
        // e.g. 65 + 32 = 97 (97 in ascii is 'a')
        // we do same thing for the second "pointer"
        if (p1 >= 65 && p1 <= 90){
            p1 = p1 + 32;
        }

        if (p2 >= 65 && p2 <= 90){
            p2 = p2 + 32;
        }

        // we know that if the current values don't align
        // then we are not dealing with a palindrome
        // so we return false
        if (p1 != p2){
            return false;
        }

        i++;
        j--;
    }

    return true;

}


int main(){

    //
    char word[100];

    printf("This determines whether or not given input is a palindrome or not...\n0 = not a pal\n1 = is a pal\n\n");

    // fgets is better to use, rather than scanf...
    printf("Enter input: ");
    fgets(word, 20, stdin);

    // strcspn(word, "\n") returns the index in the target word where we come across target char
    // placing it in the word array changes this to a 0
    word[strcspn(word, "\n")] = 0;

    // call function to test if palindrome or not
    bool isT = isAPal(word);

    // print output of isAPal (1 or 0)
    printf("Is \"%s\" a pal: %d\n", word, isT);
    
}