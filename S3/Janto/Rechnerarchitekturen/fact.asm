# Nach Beispiel aus Patterson & Hennessy

	.data
msg1:
	.asciiz "fact("
msg2:
	.asciiz ") = "
	.text
	.globl main
main:
	addiu $sp, $sp, -32	# 32 Bytes für Stack-Frame reservieren (Calling-Convention: minimum stack frame 24 bytes)
	sw $ra, 20($sp)		# return-Adresse auf Stack legen (bei main eigentlich unnötig)
	sw $fp, 16($sp)		# alten $fp auf Stack legen
	addiu $fp, $sp, 28	# fp auf erste Variable zeigen lassen

	li $s0, 7		# $s0 = n
	move $a0, $s0		# Argumentregister
	jal fact		# Aufruf von fact, Ergebnis in v0
	
	move $s1, $v0		# sichere Ergebnis in $s1
	
	li $v0, 4		# print string
	la $a0, msg1
	syscall
	li $v0, 1
	move $a0, $s0
	syscall
	li $v0, 4		# print string
	la $a0, msg2
	syscall
	li $v0, 1		# print int
	move $a0, $s1		# schiebe Ergebnis nach $a0
	syscall
	
	lw $ra, 20($sp)		# ra zurücklesen
	lw $fp, 16($sp)		# fp zurücklesen
	addiu $sp, $sp, 32	# pop
	
	li $v0, 10		# exit
	syscall

fact:
	# Prozedureinsprung
	addiu $sp, $sp, -32	# push stack frame (32 Byte)
	sw $ra, 20($sp)		# return-Adresse auf Stack legen wg. Rekursion
	sw $fp, 16($sp)		# alten $fp auf Stack legen
	addiu $fp, $sp, 28	# fp auf erste Variable zeigen lassen
	sw $a0, 0($fp)		# n als Variable auf Stack speichern via fp

	# Eigentlicher Code
	lw $v0, 0($fp)		# speichere n in v0
	bgtz $v0, factGe0	# springe falls $v0 > 0
	li $v0, 1		# ansonsten 1 zurückgeben
	j factEnd
factGe0:
	lw $a0, 0($fp)		# speichere n in a0
	subu $a0, $a0, 1	# a0 = a0 - 1
	jal fact		# Rekursion, Ergebnis in v0
	lw $t0, 0($fp)		# t0 = n
	mul $v0, $v0, $t0	# n*(n-1)
factEnd:
	lw $ra, 20($sp)		# $ra zurücklesen
	lw $fp, 16($sp)		# $fp zurücksetzen
	addiu $sp, $sp, 32	# pop
	jr $ra
