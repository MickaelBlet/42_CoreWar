.name		"NEWLINE"
.comment	"Jump jUmp juMp jumP"

start:
	sti		r1, %:fork1, %1
	sti		r1, %:fork2, %1
	sti		r1, %:fork3, %1
	ld		%1, r15
	ld		%2, r14
	ld		%4, r13
ini:
	ld		%-8, r16
	fork	%:fork1
	add		r16, r15, r16

fork1:
	live	%0xface
	fork	%:fork2
	add		r16, r14, r16

fork2:
	live	%0xface
	fork	%:fork3
	add		r16, r13, r16

fork3:
	live	%0xface
	zjmp	%:preproc4
	add		r16, r15, r16
	zjmp	%:ini			;preproc8
	add		r16, r15, r16
	zjmp	%:ini			;preproc7
	add		r16, r15, r16
	zjmp	%:preproc5
	add		r16, r15, r16
	zjmp	%:wall_jump		;preproc6
	add		r16, r15, r16
	zjmp	%:preproc1
	add		r16, r15, r16
	zjmp	%:preproc2
	add		r16, r15, r16
	zjmp	%:preproc3

preproc4:
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc4

;preproc8:
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%:proc8

;preproc7:
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%:proc7

preproc5:
	zjmp	%3
	zjmp	%3
	zjmp	%3
	zjmp	%3
	zjmp	%3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc5

;preproc6:
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;zjmp	%3
	;ld		%0, r16
	;ld		%0, r16
	;zjmp	%:proc6

preproc1:
	zjmp	%3
	zjmp	%3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc1

preproc2:
	zjmp	%3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc2

preproc3:
	zjmp	%:proc3

wall_jump:
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	st		r16, -250
	zjmp	%:fork_live

proc1:
	ld		%0x03700201, r2
	ld		%0xf3037003, r3
	ld		%0, r16
	zjmp	%:jump

proc2:
	ld		%0xef037003, r2
	ld		%0xf7037003, r3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

proc3:
	ld		%0xffff0100, r2
	ld		%0xfa037003, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

fake:
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1
	ld		%0, r1

proc4:
	st		r1, r2
	ld		%0xfe037003, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

proc5:
	ld		%0x0901e000, r2
	ld		%0xef037003, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

fork_live:
	st		r1, 6
	live	%42
	fork	%:fork_live
	st		r1, 6
	live	%42
	fork	%:fork_live
	st		r1, 6
	live	%42
	xor		r16, r16, r16
	fork	%:fork_live

infinit:
	st		r1, 6
	live	%42
	zjmp	%:infinit

jump:
	;aff		r1
	st		r2, 0x1ef
	st		r3, -1
live:
	live	%42
	zjmp	%0x1e0

;proc6:
;proc7:
;proc8:

#proc:
#	ldi		%:proc, r2, r3	; 6 > 25
#	sti		r3, %400, r2	; 6 > 25
#	live	%42				; 5 > 10
#	add		r2, r4, r2		; 6 > 10
#	xor		r2, r5, r15		; 6 > 6
#	zjmp	%:set1			; 3 > 20
#	ld		%0, r15			; 7 > 5
#	zjmp	%:proc			; 3 > 20
#
#set1:
#	xor		r2, r2, r2		; 6 > 6
#	zjmp	%361			; 3 > 20
#							; length  == 40
