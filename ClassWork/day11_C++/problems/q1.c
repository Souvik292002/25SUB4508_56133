/*Q. Print series 0,3,8,15,24,35,48,63,80,99*/

#include <stdio.h>

int main() {

    /*
        We need to print 10 terms
        n starts from 0 to 9
    */
    for (int n = 0; n < 10; n++) {

        // Calculate the term using the formula
        int term = (n * n) + (2 * n);

        /*
            Print comma only before terms
            except the first one
        */
        if (n != 0) {
            printf(",");
        }

        // Print the term
        printf("%d", term);
    }

    return 0;   // End of program
}
