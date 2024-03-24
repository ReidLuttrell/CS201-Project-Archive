FizzBuzz Algorithm Optimization Test - Reid Luttrell

The idea of this project was to implement the FizzBuzz game, but to make it more interesting, also explore
different types of optimization. I basically just thought of every different way of optimizing this
program as I could, and then analyzed the efficiency of those methods to see what the verdict is.

To compile this, just do "gcc fizzbuzz.c" and that should work.

It takes two command-line arguments.

The first argument is the number of iterations or how many number you want to check the divisibility of

The second argument is the number of the algorithm you want to test.
Algorithm options: (1) Normal Fizz Buzz, (2) Switch Fizz Buzz, (3) Unrolled Fizz Buzz

The output of the number's divisibility as well as how long the process took in microseconds will then be displayed.

The Normal Fizz Buzz algorithm uses if statements to check divisibility

The Switch Fizz Buzz algorithm uses switch statements to check divisibility

The Unrolled Fizz Buzz takes advantage of the fact that there will always be a recurring
pattern of fizz's and buzz's and then you will eventually hit the fizzbuzz on every multiple of 15.
We can then "unroll" this loop somewhat, by making it count by 15's. The problem with this, i learned,
is that when you don't know the number of iterations being performed at compile time, and that number
of iterations happens to not be divisible by 15, you will end up outputting more than you need.
Because of this I needed to have a check on every output to make sure we aren't going to go over.
This certainly heavily impacted the performance, and I couldn't think of a way to get rid of those
conditionals.

I recommend you use a large number of iterations to more accurately test the runtime of the algorithms.
