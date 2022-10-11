#include <stdio.h>
#include <stdlib.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h>     // for sleep()

//This program takes in a number from the command line.
//Then computes the factorial using a loop.
//Then displays the result along with the runtime

//function for calculating factorial of a number using recursion
long double factorial(long double n)
{
    if (n == 0)
        return 1;
    else
        return(n * factorial(n-1));
}

int main(int argc, char *argv[])
{

    long double number;
    long double fact;
    // to store the execution time of code
    double time_spent = 0.0;

    //scan argument from command lin into number
    sscanf(argv[1], "%Lf", &number);

    //checking input
    if(number < 0 || number > 100)
    {
        fprintf(stderr, "Error: incorrect value inputted.  Please enter numbers between 0 and 100 inclusive\n");
        exit(1);
    }

    //begin time
    clock_t begin = clock();
    //calculate factorial
    fact = factorial(number);
    //print result
    printf("Factorial of %.0Lf using recursion is %.0Lf\n", number, fact);
    //end time
    clock_t end = clock();

    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    //print time elapsed
    printf("The elapsed time is %f seconds\n", time_spent);

    return 0;
}
