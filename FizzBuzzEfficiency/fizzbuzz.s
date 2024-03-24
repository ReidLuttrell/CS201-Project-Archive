.global FizzBuzzASM

.text

string: .asciz "%d "
fizz: .asciz "Fizz "
buzz: .asciz "Buzz "
fizzbuzz: .asciz "FizzBuzz\n"

# %rdi = int itr

FizzBuzzASM:
    movq $1, %rcx
.startLoop:
    cmpq

.endLoop:

    retq
