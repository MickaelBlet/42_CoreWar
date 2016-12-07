# Newline random champion by mblet
# 2016(c)

.name		"NEWLINE"
.comment	"Jump jUmp juMp jumP"

start:
	sti		r1, %:fork1, %1
	sti		r1, %:fork2, %1
	sti		r1, %:fork3, %1
	sti		r1, %:ini_fork, %1
	st		r2, -7				# delete prev sti
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
	add		r16, r15, r16
	zjmp	%:ini_fork		;preproc8
	add		r16, r15, r16
	zjmp	%:ini_fork		;preproc7
	add		r16, r15, r16
	zjmp	%:preproc5
	add		r16, r15, r16
	zjmp	%:ini_fork		;preproc6
	add		r16, r15, r16
	zjmp	%:preproc1
	add		r16, r15, r16
	zjmp	%:preproc2
	add		r16, r15, r16
	zjmp	%:preproc3
	; preproc4

preproc4:
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc4

preproc5:
	zjmp	%3
	zjmp	%3
	zjmp	%3
	zjmp	%3
	zjmp	%3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:proc5

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

proc1:
	ld		%0x03700200, r2
	ld		%0xd7037003, r3
	ld		%0, r16
	zjmp	%:jump

ini_fork:
	live	%0xface
	zjmp	%:ini_fork

proc2:
	ld		%0xd3037003, r2
	ld		%0xdb037003, r3
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

proc3:
	ld		%0xffff0100, r2
	ld		%0xde037003, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

proc4:
	st		r1, r2
	ld		%0xe2037003, r3
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	ld		%0, r16
	zjmp	%:jump

proc5:
	ld		%0x0900c400, r2
	ld		%0xd3037003, r3
	zjmp	%3
	ld		%0, r16
	zjmp	%:jump

jump:
	st		r2,  0xd3
	st		r3, -1
live:
	live	%0xfeedface
	zjmp	%0xc4
