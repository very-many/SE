# Einfacher Exception Handler
# faengt nur eine Exception mit Cause 13 ab

		.kdata	#in kernel data segment
_k_v0:		.word	1
_k_v1:		.word	2		
_k_a0:		.word	3
_k_a1:		.word	4
_k_t0:		.word	5
_k_t1:		.word	6
_k_t2:		.word	7
_k_t3:		.word	8
_k_t4:		.word	9
_k_ra:		.word	10

_k_msg1:	.asciiz	"Meldung vom Betriebssystem  \n..\n Exception aufgetreten, Rechner im Kernelmode\n Register gerettet, Ruecksprungadresse gespeichert \n"
_k_msg2:	.asciiz	"\n\n Grund & Adresszeile der Exception gefunden : Trap Nr. 13 \n Fehlerbehandlungsroutine fuer Trap-Nr13 - \nFehler wuerde nun ablaufen\n"
_k_msg3:	.asciiz	"\n\n Exception abgehandelt \n Register wiederhergestellt, zurueck ins Hauptprogramm \n"
_k_msg4:	.asciiz	"\n\n Exception nicht bekannt\n Fehlerbehandlung nicht moeglich, bitte CPU-Hersteller kontaktieren ! \n"


	
	.ktext	0x80000180
				
   				# Registerrettung auf Kernelstack
	lui 	$k0,0x9000    	# Basisadresse Kernelstack in $k0
	sw	$v0, 0($k0)     # v0 retten
	sw	$v1, 4($k0)	# v1 retten
	sw	$a0, 8($k0)	# a0 retten
	sw	$a1, 12($k0)	# a1 retten
	sw	$t0, 16($k0)	# t0 retten
	sw	$t1, 20($k0)	# t1 retten
	sw	$t2, 24($k0)	# t2 retten
	sw	$t3, 28($k0)	# t3 retten
	sw	$t4, 32($k0)	# t4 retten
	sw	$ra, 36($sp)	# Ruecksprungadresse retten
				
				# Syscall fuer Exception-Meldung
	la	$a0, _k_msg1	# RAM-Adresse des Strings in $a0
	li	$v0, 4		# Wert 4 in v0 
	syscall			# Syscall 4 fuer Print String

				  # Grund der Exeption feststellen
	mfc0	$t0, $13 	  # $13=Cause register auslesen
	srl	$t0, $t0, 2	  # Exception Code Bits lesen
	andi	$t0, $t0, 0xf     # (Bits 2-6 aus $13)

        
	beq	$t0, 13,Fehlerroutine13   # Pseudo-Befehl ! Ursache war Trap-Nr 13, 
					   # weiter mit Adresse rausfinden
	j unbekannte_exception  # Zeile wird nie erreicht
				           # hier ggf. Interrupt-Handling 
	
Fehlerroutine13:

	mfc0 $t4, $14       	# EPC auslesen
	addi $t4,$t4,4 		# EPC=EPC+4  
   	mtc0 $t4,$14  		# hier gehts nachher weiter

				# Syscall fuer Adresse-Meldung
	la	$a0, _k_msg2	# RAM-Adresse des Strings in $a0
	li	$v0, 4		# Wert 4 in v0 
	syscall			# Syscall 4 fuer Print String

 	j exit_exception_handler

unbekannte_exception:

	la	$a0, _k_msg4	# RAM-Adresse des Strings in $a0
	li	$v0, 4		# Wert 4 in v0 
	syscall			# Syscall 4 fuer Print String

exit_exception_handler :

	lui 	$k0,0x9000    	# Basisadresse Kernelstack in $k0
	lw	$v0, 0($k0)
	lw	$v1, 4($k0)
	lw	$a0, 8($k0)
	lw	$a1, 12($k0)
	lw	$t0, 16($k0)
	lw	$t1, 20($k0)
	lw	$t2, 24($k0)
	lw	$t3, 28($k0)
	lw	$t4, 32($k0)
	lw	$ra, 36($sp)

	# Syscall fuer Exception-Behandlung
	la	$a0, _k_msg3	# RAM-Adresse des Strings in $a0
	li	$v0, 4		# Wert 4 in v0 
	syscall			# Syscall 4 fuer Print String

	eret			# Zurueck ins Hauptprogramm
