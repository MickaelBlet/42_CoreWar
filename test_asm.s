.name		woih
.comment

.name
.comment

.test

:
labO:
	inv		r1, 1337, 0
	st		r0, :labinV
	st		%:lab, r1
	st		r1, :
	sti		r1 r0
	st		r1, r2, r2
