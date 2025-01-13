 	
	.text			  # ab hier steht ein Progamm
				  # das einen Trap ausloest
    				  # ausloesene Befehlsadresse in EPC speichern
				  # Cause in Cause speichern
				  # zu exception handler Adresse 0x80000180 springen

main:
	addi $a1,$zero,1	  # ...irgendwo im Programm
	addi $a1,$zero,2
	addi $a1,$zero,3

#	teq	$zero, $zero      	  # Exceptiontester ausloesen
                                                                          # trap if equal => immer Trap #13

#	lui $a1,32767	  # Ausloesen eines Artithm. Overflows Trap #12
#	ori $a1,$a1,65535        # durch Erzeugen der groessten 2k-Zahl
#	addi $a1,$a1,1             # und Addieren von 1
     
	lui $a0,4096
	lw $t0,15($a0)               # Ausloesen einer Exception durch falsche LW-Speicheradresse Trap #4

	addi $a1,$zero,4	  # ...weiter im Programm
	addi $a1,$zero,5
	addi $a1,$zero,6

	li $v0, 10		# exit
	syscall
