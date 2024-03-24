# external data file
# assemble with as --64 external.s -o external.o
# compile with gcc -g *.o

.data
    .local crcTable
    .comm crcTable, 256

.global crcInit
.global crcFast

.text

    # Function Standard:
    #
    # return value passed through %rax
    # arg1: %rdi
    # arg2: %rsi
    # arg3: %rdi
    # arg4: %rcx
    # arg5: %r8
    # arg6: %r9

    # code goes below


    #rcx : dividend - int
    #rax : remainder - char
    #rdx : bit - char

crcInit:
    xorq %rcx, %rcx # set up everything
    xorq %rax, %rax
    xorq %rdx, %rdx
    xorq %rbx, %rbx 

.startLoop:
    cmpl $255, %ecx # if dividend > 255
    jg .endLoop

    movb %cl, %al # remainder = dividend 

    movb $8, %dl # bit = 8
.startLoop2:
    cmpb $1, %dl # if bit < 1
    jl .endLoop2
   
    movq %rax, %rbx # ebx = remainder
    
    andq $0x80, %rbx # rbx &= 0x80 
    
    test %rbx, %rbx
    je .else

    addq %rax, %rax # reminder << 1
    xorb $0xD5, %al # remainder ^ POLYNOMIAL

    jmp .skip
.else:
    
    addq %rax, %rax # remainder << 1

.skip:

    subb $1, %dl # byte -= 1
    jmp .startLoop2
.endLoop2:
 
    movq $crcTable, %rsi
    movb %al, (%rsi, %rcx) #crcTable[dividend] = remainder

    addl $1, %ecx # dividend += 1
    jmp .startLoop
.endLoop:
    retq # idk what to return for void i guess this works

crcFast:
#rdi = message - char*, rsi = nBytes - long
# rax = remainder - char, rcx = byte - long, rdx = data - unsigned char
    xorq %rax, %rax
    xorq %rcx, %rcx
    xorq %rdx, %rdx

    xorq %rbx, %rbx # temp storage of message[byte] ^ remainder

.startLoop3:
    cmpq %rsi, %rcx # i think this is the right way
    jge .endLoop3

    movq (%rdi, %rcx), %rbx # store address of message at index

    xorb %al, %bl # bl = message[byte] ^ remainder
    movb %bl, %dl # data = message[byte] ^ remainder

    xorq %rbx, %rbx # clear for re-use

    movq $crcTable, %rbx # rbx = crcTable addy

    movq (%rbx, %rdx), %rax # rbx = crcTable[data] addy, this may need to be %dl instead of rdx

    addl $1, %ecx
    jmp .startLoop3
.endLoop3:
    retq
