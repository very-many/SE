    .data
str:
    .asciiz "Hallo INF"
    .text
main:
    li $v0, 4
    la $a0, str
    syscall
    
    li $v0, 1
    li $a0, 22
    syscall
    
    add $t0, $zero, 10
    add $t1, $zero, 20
    
    add $s0, $t0, $t1

    la $t2, str
    lw $s1, 0($t2)
    beq $s1, $t0, main
    

    li $v0, 10
    syscall
