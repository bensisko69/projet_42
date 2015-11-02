
#somme comment
.name "test prog"

#other

.comment "Ha, Ha, Ha,fuckin test"


    sti	r1, %:live2, %1		;change live by the right value
bibi:
    live2:
dudu:
sti     r1, r4,     %2	;  T_DIR | T_REG   Direct : Le caractère DIRECT_CHAR suivi d’une valeur numérique %n doit error
ldi     r2 , %-4, r1;
xor r2, r3, r4
add r1, r2, r3
xor 3 , 0, r1
and %:bibi, r1, r2
add r1, r2, r3
live %12
lldi %12, 12, r2