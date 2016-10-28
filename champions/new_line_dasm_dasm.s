.name       "fluttershy"
.comment    "oh, my, what a scary project"


label_0:
    fork    %:label_144
    st      r1, 6
    live    %42
    fork    %:label_382
    st      r1, 6
    live    %42
    fork    %:label_267

label_29:
    st      r1, 6

label_34:
    live    %213904

label_39:
    fork    %:label_34

label_42:
    sti     r1, %:label_94, %1
    st      r1, 6

label_54:
    live    %43123
    sti     r1, %:label_121, %1
    ld      %-6, r2
    ld      %-6, r3
    ld      %150994953, r4
    ld      %-186, r5

label_94:
    live    %295423
    sti     r4, %:label_29, r2

label_105:
    add     r2, r3, r2
    sti     r4, %:label_29, r2
    add     r2, r3, r2

label_121:
    live    %3940641
    xor     r2, r5, r15

label_131:
    zjmp    %:label_42
    ld      %0, r16
    zjmp    %:label_94

label_144:
    st      r1, 6

label_149:
    live    %123012

label_154:
    fork    %:label_149

label_157:
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    st      r1, 58
    ld      %0, r16

label_214:
    live    %985341
    live    %985341

label_224:
    live    %985341
    live    %985341
    live    %985341
    live    %985341
    live    %985341
    live    %985341
    live    %985341
    live    %985341
    zjmp    %:label_214

label_267:
    st      r1, 6

label_272:
    live    %213904

label_277:
    fork    %:label_272

label_280:
    sti     r1, %:label_332, %1
    st      r1, 6

label_292:
    live    %43123
    sti     r1, %:label_359, %1
    ld      %0, r2
    ld      %6, r3
    ld      %150994953, r4
    ld      %180, r5

label_332:
    live    %295423
    sti     r4, %153, r2

label_343:
    add     r2, r3, r2
    sti     r4, %142, r2
    add     r2, r3, r2

label_359:
    live    %3940641
    xor     r2, r5, r15

label_369:
    zjmp    %:label_280
    ld      %0, r16
    zjmp    %:label_332

label_382:
    st      r1, 6

label_387:
    live    %96824

label_392:
    fork    %:label_387

label_395:
    ld      %0, r2
    ld      %4, r3

label_409:
    ld      %96, r5
    sti     r1, %:label_467, %1
    st      r1, 6

label_428:
    live    %8008135
    ldi     %:label_395, r2, r4

label_439:
    sti     r4, %400, r2
    add     r2, r3, r2
    ldi     %:label_395, r2, r4
    sti     r4, %383, r2
    add     r2, r3, r2

label_467:
    live    %89523
    xor     r2, r5, r15

label_477:
    zjmp    %362
    ld      %0, r15
    zjmp    %:label_428
