.name		"NEWLINE"
.comment	"Jump jUmp juMp jumP"

	ld		%0x4a, r2
	ld		%0x55, r3
	ld		%0x4d, r4
	ld		%0x50, r5
	ld		%0x0a, r6
	aff		r2
	aff		r3
	aff		r4
	aff		r5
	aff		r6
	st		r1, 6
loop:
	live	%0x99999999
	fork	%:loop
start:
	st		r1, 36
	st		r1, 113
;	st		r1, 119
	st		r1, 137
	st		r1, 161
	st		r1, 185
	fork	%:fork1
	ld		%0, r16

fork1:
	live	%0x99999999
	fork	%:fork2
	zjmp	%:preproc1
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc2 	; 3

fork2:
	zjmp	%:preproc2
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc3		; 2

preproc1:
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc4		; 4

preproc2:
	zjmp	%:proc1		; 1

; proc0 20
; proc1 45
; proc2 20
; proc3 45

proc4:
	live	%0x99999999
	ld		%0x00e50000, r2
	ld		%0xef037003, r3
	ld		%0, r16
	zjmp	%:jump

proc3:
	live	%0x99999999
	ld		%0xef037003, r2
	ld		%0xf7037003, r3
	ld		%0, r16
	zjmp	%:jump

proc2:
	live	%0x99999999
	ld		%0xffff0900, r2
	ld		%0xfa037003, r3
	ld		%0, r16
	zjmp	%:jump

proc1:
	live	%0x99999999
	ld		%0x03700200, r2
	ld		%0xf3037003, r3
	ld		%0, r16
	zjmp	%:jump

jump:
	st		r2, 0xef
	st		r3, -1
live:
	zjmp	%0xe5

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
