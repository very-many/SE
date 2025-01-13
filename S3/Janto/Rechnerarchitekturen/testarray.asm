.data
msgElemCount:
	.asciiz "Anzahl Elemente: "
msgInpValue:
	.asciiz "Wert "
msgColon:
	.asciiz ":"

.text
main:
	li $v0, 4
	la $a0, msgElemCount
	syscall			# print string
	
	li $v0, 5		# read int
	syscall
	move $s0, $v0		# Ergebnis in s0 sichern
	
	move $fp, $sp		# setze frame-Pointer auf initialen Wert des sp
	sll $t0, $s0, 2		# Berechne Array-Groesse in Bytes ($s0 * 4)
	sub $sp, $sp, $t0	# Reserviere Platz auf dem Stack
	
	addi $t1, $zero, 0		# t1=0
	# lese Werte einzeln ein...
readValues:
	beq $t1, $s0, readValuesEnd	# while $t1 != $s0
	li $v0, 4
	la $a0, msgInpValue
	syscall
	li $v0, 1
	addi $a0, $t1, 1
	syscall				# print int
	li $v0, 4
	la $a0, msgColon
	syscall
	li $v0, 5
	syscall				# read int
	sll $t0, $t1, 2
	sub $t0, $fp, $t0		# Berechne Adresse für Array-Element a[$t1]
	sw $v0, ($t0)
	addi $t1, $t1, 1
	j readValues
readValuesEnd:
	li $v0, 10
	syscall				# exit
	