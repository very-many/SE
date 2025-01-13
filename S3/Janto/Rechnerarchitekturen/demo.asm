.data
value:
        .word 0x12345678

value2:
        .word 0xabcdef00

.text
addi $s1, $zero, 1000
addi $s2, $zero, 70

add $t0, $s1, $s2

lw $s3, value
lw $s4, value2
