.name       "NEWLINE"
.comment    "Jump jUmp juMp jumP"


label_0:
    st      r1, 41
    st      r1, 118
    st      r1, 119
    st      r1, 137
    st      r1, 161
    st      r1, 185
    fork    %:label_40
    ld      %0, r16

label_40:
    live    %-1717986919
    fork    %:label_75
    zjmp    %:label_95
    ld      %0, r16
    ld      %0, r16
    ld      %0, r16
    zjmp    %:label_180

label_75:
    zjmp    %:label_119
    ld      %0, r16
    ld      %0, r16
    zjmp    %:label_151

label_95:
    ld      %0, r16
    ld      %0, r16
    ld      %0, r16
    zjmp    %:label_122

label_119:
    zjmp    %:label_209

label_122:
    live    %-1717986919
    ld      %-1717986919, r2
    ld      %251883523, r3
    ld      %0, r16
    zjmp    %:label_238

label_151:
    live    %-1717986919
    ld      %251883523, r2
    ld      %386101251, r3
    ld      %0, r16
    zjmp    %:label_238

label_180:
    live    %-1717986919
    ld      %-65280, r2
    ld      %436432899, r3
    ld      %0, r16
    zjmp    %:label_238

label_209:
    live    %-1717986919
    ld      %57672192, r2
    ld      %318992387, r3
    ld      %0, r16
    zjmp    %:label_238

label_238:
    st      r2, 15
    st      r3, -1
    live    %0
