; codesize: 2609
;#### Alien 3 Title.rmta - converted by 7800rmt2asm 0.1 Jun 19 2023 16:37:31

RMTSTART SET .


 ; #### RMT header...
   .byte "RMT4"              ; magic
   .byte $40                 ; tracklen
   .byte $03                 ; song speed
   .byte $01                 ; player freq
   .byte $01                 ; format version number
   .word (RMTSTART+$0010)   ; pointer to instrument pointers
   .word (RMTSTART+$0028)   ; pointer to track pointers, lo
   .word (RMTSTART+$004c)   ; pointer to track pointers, hi
   .word (RMTSTART+$08c0)   ; pointer to song

 ; #### Instrument Pointer Table...
   .word (RMTSTART+$0070) , (RMTSTART+$0089) , (RMTSTART+$009c) , (RMTSTART+$00b8) , (RMTSTART+$0107) , (RMTSTART+$013b) , (RMTSTART+$0157) , (RMTSTART+$0172) , (RMTSTART+$018d) , (RMTSTART+$01a8) , (RMTSTART+$01c3) , (RMTSTART+$01d6) 

 ; #### Track Pointer Table, Lo...
 .byte <(RMTSTART+$01e9)
 .byte <(RMTSTART+$0263)
 .byte <(RMTSTART+$02e1)
 .byte <(RMTSTART+$02f7)
 .byte <(RMTSTART+$0314)
 .byte <(RMTSTART+$0334)
 .byte <(RMTSTART+$0355)
 .byte <(RMTSTART+$0373)
 .byte <(RMTSTART+$038f)
 .byte <(RMTSTART+$0403)
 .byte <(RMTSTART+$0438)
 .byte <(RMTSTART+$047c)
 .byte <(RMTSTART+$04c0)
 .byte <(RMTSTART+$04d8)
 .byte <(RMTSTART+$04f4)
 .byte <(RMTSTART+$0518)
 .byte <(RMTSTART+$053a)
 .byte <(RMTSTART+$0558)
 .byte <(RMTSTART+$0574)
 .byte <(RMTSTART+$0592)
 .byte <(RMTSTART+$05b0)
 .byte <(RMTSTART+$062d)
 .byte <(RMTSTART+$0677)
 .byte <(RMTSTART+$06d9)
 .byte <(RMTSTART+$071f)
 .byte <(RMTSTART+$074f)
 .byte <(RMTSTART+$0782)
 .byte <(RMTSTART+$07a7)
 .byte <(RMTSTART+$07d7)
 .byte <(RMTSTART+$07f3)
 .byte <(RMTSTART+$080b)
 .byte <(RMTSTART+$083c)
 .byte <(RMTSTART+$0880)
 .byte <(RMTSTART+$088a)
 .byte <(RMTSTART+$08a4)
 .byte <(RMTSTART+$08ac)

 ; #### Track Pointer Table, Hi...
 .byte >(RMTSTART+$01e9)
 .byte >(RMTSTART+$0263)
 .byte >(RMTSTART+$02e1)
 .byte >(RMTSTART+$02f7)
 .byte >(RMTSTART+$0314)
 .byte >(RMTSTART+$0334)
 .byte >(RMTSTART+$0355)
 .byte >(RMTSTART+$0373)
 .byte >(RMTSTART+$038f)
 .byte >(RMTSTART+$0403)
 .byte >(RMTSTART+$0438)
 .byte >(RMTSTART+$047c)
 .byte >(RMTSTART+$04c0)
 .byte >(RMTSTART+$04d8)
 .byte >(RMTSTART+$04f4)
 .byte >(RMTSTART+$0518)
 .byte >(RMTSTART+$053a)
 .byte >(RMTSTART+$0558)
 .byte >(RMTSTART+$0574)
 .byte >(RMTSTART+$0592)
 .byte >(RMTSTART+$05b0)
 .byte >(RMTSTART+$062d)
 .byte >(RMTSTART+$0677)
 .byte >(RMTSTART+$06d9)
 .byte >(RMTSTART+$071f)
 .byte >(RMTSTART+$074f)
 .byte >(RMTSTART+$0782)
 .byte >(RMTSTART+$07a7)
 .byte >(RMTSTART+$07d7)
 .byte >(RMTSTART+$07f3)
 .byte >(RMTSTART+$080b)
 .byte >(RMTSTART+$083c)
 .byte >(RMTSTART+$0880)
 .byte >(RMTSTART+$088a)
 .byte >(RMTSTART+$08a4)
 .byte >(RMTSTART+$08ac)

 ; #### Track+Instrument Data...
   .byte $0c,$0c,$16,$16,$00,$00,$0c,$00,$18,$03,$00,$00,$00,$ff,$5a,$00
   .byte $dd,$0a,$00,$cc,$0a,$00,$aa,$0a,$00,$0c,$0c,$10,$10,$00,$00,$0c
   .byte $00,$18,$03,$00,$00,$00,$aa,$5b,$13,$aa,$0b,$00,$0c,$0c,$19,$19
   .byte $00,$00,$1c,$00,$00,$00,$00,$00,$00,$00,$0e,$00,$ff,$0c,$00,$ee
   .byte $0c,$00,$dd,$0c,$00,$cc,$0c,$00,$0c,$0c,$4c,$4c,$00,$00,$00,$00
   .byte $00,$00,$00,$00,$00,$ff,$10,$07,$dd,$1a,$88,$cc,$1a,$98,$bb,$1a
   .byte $c8,$88,$1a,$df,$99,$10,$05,$88,$18,$05,$77,$18,$04,$66,$18,$04
   .byte $55,$18,$04,$44,$18,$04,$33,$18,$04,$22,$18,$04,$22,$18,$04,$11
   .byte $18,$04,$11,$18,$04,$11,$18,$04,$11,$18,$04,$11,$18,$04,$11,$18
   .byte $04,$11,$18,$04,$00,$18,$00,$0c,$0c,$31,$31,$00,$00,$00,$00,$03
   .byte $00,$10,$00,$00,$00,$20,$00,$bb,$2a,$00,$aa,$2a,$00,$99,$2a,$00
   .byte $99,$2a,$00,$99,$2a,$00,$99,$2a,$00,$99,$2a,$00,$99,$2a,$00,$88
   .byte $2a,$00,$88,$2a,$00,$77,$2a,$00,$00,$20,$00,$0c,$0c,$19,$19,$00
   .byte $00,$1c,$00,$00,$00,$00,$00,$00,$00,$0e,$00,$ff,$0e,$00,$ee,$0e
   .byte $00,$dd,$0e,$00,$cc,$0e,$00,$0e,$0c,$18,$18,$01,$00,$0c,$00,$00
   .byte $00,$00,$00,$00,$07,$05,$ff,$0a,$00,$dd,$0a,$00,$cc,$0a,$00,$aa
   .byte $0a,$00,$0e,$0c,$18,$18,$01,$00,$0c,$00,$00,$00,$00,$00,$00,$0a
   .byte $05,$ff,$0a,$00,$dd,$0a,$00,$cc,$0a,$00,$aa,$0a,$00,$0e,$0c,$18
   .byte $18,$01,$00,$0c,$00,$00,$00,$00,$00,$00,$09,$05,$ff,$5a,$00,$dd
   .byte $0a,$00,$cc,$0a,$00,$aa,$0a,$00,$0e,$0c,$18,$18,$01,$00,$0c,$00
   .byte $00,$00,$00,$00,$00,$08,$03,$ff,$5a,$00,$dd,$0a,$00,$cc,$0a,$00
   .byte $aa,$0a,$00,$0c,$0c,$10,$10,$00,$00,$0c,$00,$18,$03,$00,$00,$00
   .byte $aa,$5b,$81,$aa,$0b,$00,$0c,$0c,$10,$10,$00,$00,$0c,$00,$18,$03
   .byte $00,$00,$00,$aa,$5b,$11,$aa,$0b,$00,$15,$02,$95,$00,$4e,$01,$4e
   .byte $00,$0e,$02,$8e,$00,$55,$01,$53,$00,$1a,$02,$9a,$00,$4e,$01,$4e
   .byte $00,$0e,$02,$8e,$00,$5a,$01,$5a,$00,$18,$02,$98,$00,$4e,$01,$4e
   .byte $00,$1a,$02,$9a,$00,$58,$01,$58,$00,$13,$02,$93,$00,$5a,$01,$5a
   .byte $00,$15,$02,$95,$00,$53,$01,$53,$00,$11,$02,$91,$00,$55,$01,$55
   .byte $00,$0e,$02,$8e,$00,$51,$01,$51,$00,$0c,$02,$8c,$00,$4e,$01,$4e
   .byte $00,$0e,$02,$8e,$00,$4c,$01,$4c,$00,$13,$02,$93,$00,$4e,$01,$4e
   .byte $00,$11,$02,$91,$00,$53,$01,$53,$00,$13,$02,$93,$00,$51,$01,$51
   .byte $00,$bf,$38,$12,$02,$92,$00,$55,$01,$55,$00,$0e,$02,$8e,$00,$52
   .byte $01,$52,$00,$0c,$02,$8c,$00,$4e,$01,$4e,$00,$0e,$02,$8e,$00,$4c
   .byte $01,$4c,$00,$13,$02,$93,$00,$4e,$01,$4e,$00,$12,$02,$92,$00,$53
   .byte $01,$53,$00,$13,$02,$93,$00,$52,$01,$52,$00,$15,$02,$95,$00,$53
   .byte $01,$53,$00,$12,$02,$92,$00,$55,$01,$55,$00,$0e,$02,$8e,$00,$52
   .byte $01,$52,$00,$0c,$02,$8c,$00,$4e,$01,$4e,$00,$0e,$02,$8e,$00,$4c
   .byte $01,$4c,$00,$09,$02,$89,$00,$4e,$01,$4e,$00,$0c,$02,$8c,$00,$49
   .byte $01,$49,$00,$0e,$02,$8e,$00,$4c,$01,$4c,$00,$11,$02,$91,$00,$bf
   .byte $14,$9a,$02,$3e,$13,$18,$2a,$3e,$07,$98,$02,$7e,$9a,$02,$7e,$a1
   .byte $02,$3e,$17,$1c,$2a,$3e,$07,$a4,$02,$fe,$a3,$02,$fe,$a0,$02,$fe
   .byte $a1,$02,$3e,$1b,$1c,$2a,$3e,$07,$a0,$02,$fe,$a1,$02,$fe,$9d,$02
   .byte $fe,$99,$02,$fe,$9a,$02,$3e,$07,$96,$2d,$3e,$07,$a2,$02,$3e,$07
   .byte $98,$2d,$3e,$07,$a4,$02,$3e,$07,$d3,$2d,$3e,$07,$9f,$02,$3e,$07
   .byte $1a,$2e,$3e,$07,$a1,$02,$7e,$a2,$02,$7e,$a1,$02,$3e,$07,$9d,$02
   .byte $fe,$9f,$02,$fe,$a1,$02,$fe,$9d,$02,$fe,$9f,$02,$fe,$9a,$02,$3e
   .byte $19,$d3,$2d,$3e,$05,$5d,$02,$3e,$07,$5b,$02,$fe,$5d,$02,$3e,$13
   .byte $3d,$01,$bd,$00,$3e,$0a,$5e,$02,$3e,$07,$65,$02,$fe,$67,$02,$fe
   .byte $65,$02,$fe,$5d,$02,$3e,$07,$5b,$02,$fe,$5d,$02,$3e,$13,$3d,$01
   .byte $bd,$00,$3e,$0a,$67,$02,$3e,$07,$65,$02,$fe,$5e,$02,$3e,$07,$02
   .byte $02,$3d,$02,$3d,$02,$3d,$02,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$bd
   .byte $01,$bd,$01,$bd,$01,$bd,$01,$7d,$01,$7d,$01,$7d,$01,$7d,$01,$3d
   .byte $01,$3d,$01,$3d,$01,$3d,$01,$fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd
   .byte $00,$bd,$00,$bd,$00,$bd,$00,$7d,$00,$7d,$00,$7d,$00,$7d,$00,$82
   .byte $01,$bd,$01,$bd,$01,$bd,$01,$7d,$01,$7d,$01,$7d,$01,$7d,$01,$3d
   .byte $01,$3d,$01,$3d,$01,$3d,$01,$fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd
   .byte $00,$bd,$00,$bd,$00,$bd,$00,$7d,$00,$7d,$00,$7d,$00,$7d,$00,$18
   .byte $02,$3e,$07,$17,$02,$3e,$0f,$3d,$01,$bd,$00,$3e,$0e,$86,$12,$7e
   .byte $3d,$00,$3e,$05,$86,$12,$7e,$3d,$00,$7e,$84,$12,$3d,$00,$be,$84
   .byte $12,$3d,$00,$84,$12,$3d,$00,$82,$12,$3d,$00,$be,$86,$12,$7e,$86
   .byte $12,$7e,$3d,$00,$7e,$86,$12,$7e,$1a,$1a,$3d,$02,$3d,$02,$3d,$02
   .byte $fd,$01,$fd,$01,$fd,$01,$fd,$01,$bd,$01,$bd,$01,$bd,$01,$bd,$01
   .byte $7d,$01,$7d,$01,$7d,$01,$7d,$01,$3d,$01,$3d,$01,$3d,$01,$3d,$01
   .byte $fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd,$00,$bd,$00,$bd,$00,$bd,$00
   .byte $7d,$00,$7d,$00,$7d,$00,$7d,$00,$1a,$1e,$bf,$02,$1a,$22,$3d,$02
   .byte $3d,$02,$3d,$02,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$bd,$01,$bd,$01
   .byte $bd,$01,$bd,$01,$7d,$01,$7d,$01,$7d,$01,$7d,$01,$3d,$01,$3d,$01
   .byte $3d,$01,$3d,$01,$fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd,$00,$bd,$00
   .byte $bd,$00,$bd,$00,$7d,$00,$7d,$00,$7d,$00,$7d,$00,$17,$26,$bf,$02
   .byte $3e,$04,$9a,$01,$3e,$13,$18,$29,$3e,$07,$96,$01,$98,$01,$9a,$01
   .byte $7e,$a1,$01,$3e,$17,$1c,$29,$fe,$3e,$04,$a4,$01,$fe,$a3,$01,$fe
   .byte $a0,$01,$fe,$a1,$01,$3e,$1b,$1c,$29,$3e,$07,$a0,$01,$fe,$a1,$01
   .byte $fe,$9d,$01,$fe,$99,$01,$fe,$9a,$01,$3e,$0b,$9c,$01,$fe,$9d,$01
   .byte $fe,$9f,$01,$fe,$a1,$01,$3e,$0b,$a2,$01,$3e,$07,$a1,$01,$fe,$9d
   .byte $01,$fe,$9f,$01,$fe,$9a,$01,$fe,$3e,$04,$a1,$01,$7e,$a2,$01,$7e
   .byte $a1,$01,$3e,$07,$9d,$01,$fe,$9f,$01,$fe,$a1,$01,$fe,$9d,$01,$fe
   .byte $9f,$01,$fe,$9a,$01,$3e,$19,$13,$2d,$7e,$11,$02,$3e,$07,$0f,$02
   .byte $fe,$11,$02,$3e,$13,$3d,$01,$bd,$00,$3e,$0a,$0f,$02,$3e,$07,$0d
   .byte $02,$fe,$0c,$02,$fe,$08,$02,$fe,$11,$02,$3e,$07,$0f,$02,$fe,$11
   .byte $02,$3e,$13,$3d,$01,$bd,$00,$3e,$0a,$0f,$02,$3e,$07,$0d,$02,$fe
   .byte $0c,$02,$3e,$07,$22,$02,$3e,$07,$20,$02,$fe,$22,$02,$3e,$13,$3d
   .byte $01,$bd,$00,$3e,$0a,$24,$02,$3e,$07,$25,$02,$fe,$24,$02,$fe,$20
   .byte $02,$fe,$25,$02,$3e,$07,$24,$02,$fe,$25,$02,$3e,$13,$3d,$01,$bd
   .byte $00,$3e,$0a,$24,$02,$3e,$07,$25,$02,$fe,$24,$02,$fe,$20,$02,$fe
   .byte $66,$02,$7d,$02,$7d,$02,$7d,$02,$3d,$02,$3d,$02,$3d,$02,$3d,$02
   .byte $fd,$01,$fd,$01,$fd,$01,$fd,$01,$bd,$01,$bd,$01,$bd,$01,$bd,$01
   .byte $7d,$01,$7d,$01,$7d,$01,$7d,$01,$3d,$01,$3d,$01,$3d,$01,$3d,$01
   .byte $fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd,$00,$bd,$00,$bd,$00,$bd,$00
   .byte $5a,$02,$7d,$01,$58,$02,$7d,$01,$55,$02,$7d,$01,$5a,$02,$7d,$01
   .byte $58,$02,$7d,$01,$55,$02,$7d,$01,$5a,$02,$7d,$01,$58,$02,$7d,$01
   .byte $55,$02,$7d,$01,$5a,$02,$7d,$01,$58,$02,$7d,$01,$55,$02,$7d,$01
   .byte $5a,$02,$7d,$01,$58,$02,$7d,$01,$55,$02,$7d,$01,$be,$4e,$02,$7d
   .byte $02,$7d,$02,$7d,$02,$3d,$02,$3d,$02,$3d,$02,$3d,$02,$fd,$01,$fd
   .byte $01,$fd,$01,$fd,$01,$bd,$01,$bd,$01,$bd,$01,$bd,$01,$7d,$01,$7d
   .byte $01,$7d,$01,$7d,$01,$3d,$01,$3d,$01,$3d,$01,$3d,$01,$fd,$00,$fd
   .byte $00,$fd,$00,$fd,$00,$bd,$00,$bd,$00,$bd,$00,$bd,$00,$7d,$00,$7d
   .byte $00,$7d,$00,$7d,$00,$3e,$1c,$3e,$08,$15,$0a,$7e,$16,$0a,$7e,$00
   .byte $02,$7e,$01,$02,$7e,$02,$02,$3d,$02,$3d,$02,$3d,$02,$fd,$01,$fd
   .byte $01,$fd,$01,$fd,$01,$bd,$01,$bd,$01,$bd,$01,$bd,$01,$7d,$01,$7d
   .byte $01,$7d,$01,$7d,$01,$3d,$01,$3d,$01,$3d,$01,$3d,$01,$fd,$00,$fd
   .byte $00,$fd,$00,$fd,$00,$bd,$00,$bd,$00,$bd,$00,$bd,$00,$bd,$00,$bd
   .byte $00,$bd,$00,$bd,$00,$7d,$00,$7d,$00,$7d,$00,$7d,$00,$7d,$00,$7d
   .byte $00,$7d,$00,$7d,$00,$15,$02,$3e,$07,$13,$02,$3d,$02,$3d,$02,$3d
   .byte $02,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$fd,$01,$fd
   .byte $01,$bd,$01,$bd,$01,$bd,$01,$bd,$01,$87,$01,$bd,$01,$bd,$01,$bd
   .byte $01,$3d,$01,$3d,$01,$3d,$01,$3d,$01,$00,$05,$3d,$01,$3d,$01,$3d
   .byte $01,$fd,$00,$fd,$00,$fd,$00,$fd,$00,$bd,$00,$7d,$00,$3e,$1e,$8e
   .byte $15,$fe,$8e,$09,$fe,$fd,$00,$fe,$8e,$15,$fe,$8c,$15,$fe,$8c,$09
   .byte $fe,$fd,$00,$fe,$8c,$15,$fe,$8e,$15,$fe,$8e,$09,$fe,$fd,$00,$fe
   .byte $8e,$15,$fe,$91,$15,$fe,$91,$09,$fe,$fd,$00,$fe,$91,$15,$fe,$8e
   .byte $15,$fe,$8e,$09,$fe,$fd,$00,$fe,$8e,$15,$fe,$8c,$15,$fe,$8c,$09
   .byte $fe,$fd,$00,$fe,$8c,$15,$fe,$8e,$15,$fe,$8e,$09,$fe,$fd,$00,$fe
   .byte $8e,$15,$fe,$88,$09,$fe,$89,$09,$fe,$fd,$00,$fe,$8e,$15,$7e,$fd
   .byte $00,$7e,$93,$15,$fe,$93,$09,$fe,$fd,$00,$fe,$93,$15,$fe,$93,$15
   .byte $fe,$93,$09,$fe,$fd,$00,$fe,$93,$15,$fe,$95,$15,$fe,$95,$09,$fe
   .byte $fd,$00,$fe,$95,$15,$bf,$17,$8e,$15,$fe,$8e,$09,$fe,$fd,$00,$fe
   .byte $8e,$15,$fe,$8e,$15,$fe,$8e,$09,$fe,$fd,$00,$fe,$8e,$15,$fe,$8e
   .byte $15,$fe,$8e,$09,$fe,$fd,$00,$fe,$8e,$15,$fe,$91,$15,$fe,$91,$09
   .byte $fe,$fd,$00,$fe,$91,$15,$fe,$8a,$09,$3e,$07,$88,$09,$fe,$8a,$09
   .byte $3e,$07,$fd,$00,$3e,$17,$92,$15,$3e,$07,$92,$09,$fe,$88,$09,$fe
   .byte $94,$09,$fe,$8e,$15,$fe,$8e,$15,$fe,$fd,$00,$fe,$8e,$15,$3e,$07
   .byte $8e,$15,$fe,$fd,$00,$fe,$8e,$15,$fe,$bf,$00,$8e,$15,$fe,$8e,$15
   .byte $fe,$fd,$00,$fe,$8e,$15,$3e,$07,$8e,$15,$fe,$fd,$00,$fe,$8e,$15
   .byte $fe,$8e,$15,$fe,$8e,$15,$fe,$fd,$00,$fe,$8e,$15,$fe,$8e,$15,$fe
   .byte $91,$15,$fe,$fd,$00,$fe,$93,$15,$7e,$fd,$00,$7e,$3d,$00,$3e,$0b
   .byte $00,$0e,$7e,$00,$0e,$7e,$00,$0e,$fe,$00,$0e,$3e,$07,$00,$0e,$fe
   .byte $cc,$13,$7e,$cb,$13,$7e,$3d,$00,$7e,$cb,$13,$7e,$c9,$13,$7e,$c9
   .byte $13,$7e,$ce,$13,$7e,$c9,$13,$7e,$c7,$13,$7e,$c6,$13,$7e,$c6,$13
   .byte $7e,$c7,$13,$7e,$c5,$13,$7e,$c5,$13,$7e,$c6,$13,$7e,$c5,$13,$7e
   .byte $3d,$00,$3e,$07,$00,$0e,$3e,$08,$bf,$02,$3e,$08,$00,$0e,$3e,$0f
   .byte $00,$0e,$3e,$0f,$00,$0e,$3e,$0f,$00,$0e,$7e,$00,$0e,$7e,$3d,$00
   .byte $7e,$00,$0e,$7e,$3e,$08,$00,$0e,$3e,$07,$bf,$00,$3d,$00,$3e,$13
   .byte $00,$0e,$7e,$00,$0e,$7e,$00,$0e,$fe,$00,$0e,$fe,$00,$0e,$3e,$1f

 ; #### Song Data...
   .byte $00,$08,$16,$ff,$01,$09,$17,$1f,$00,$0a,$18,$20,$01,$0b,$19,$21
   .byte $00,$0a,$18,$22,$01,$0b,$19,$21,$02,$0c,$18,$22,$03,$0d,$19,$21
   .byte $04,$0e,$1a,$22,$05,$0f,$1b,$21,$02,$0c,$18,$22,$03,$0d,$19,$21
   .byte $04,$0e,$1a,$22,$05,$0f,$1b,$21,$06,$10,$1c,$23,$07,$11,$1c,$23
   .byte $06,$12,$1c,$23,$07,$13,$1c,$23,$00,$14,$1d,$22,$01,$15,$1e,$21
   .byte $fe,$02,$c8,$48,$14,$49,$2c,$4a,$41,$6c,$69,$65,$6e,$20,$33,$20
   .byte $54,$69,$74,$6c,$65,$20,$53,$63,$72,$65,$65,$6e,$20,$2d,$20,$4d
   .byte $61,$74,$74,$20,$46,$75,$72,$6e,$69,$73,$73,$20,$2d,$20,$32,$30
   .byte $31,$38,$20,$2d,$20,$41,$72,$72,$61,$6e,$67,$65,$64,$20,$62,$79
   .byte $20,$56,$69,$6e,$00,$4c,$65,$61,$64,$20,$49,$6e,$73,$74,$72,$75
   .byte $6d,$65,$6e,$74,$00,$4c,$65,$61,$64,$20,$50,$6f,$72,$74,$61,$6d
   .byte $65,$6e,$74,$6f,$20,$43,$6f,$6e,$74,$69,$6e,$75,$65,$00,$42,$61
   .byte $73,$73,$6c,$69,$6e,$65,$20,$43,$00,$53,$6e,$61,$72,$65,$20,$64
   .byte $72,$75,$6d,$20,$76,$69,$6e,$00,$6e,$6f,$74,$65,$20,$74,$6f,$6d
   .byte $20,$6c,$6f,$6e,$67,$20,$66,$73,$68,$69,$66,$74,$00,$42,$61,$73
   .byte $73,$20,$45,$20,$46,$69,$6c,$6c,$65,$72,$00,$61,$72,$70,$65,$67
   .byte $67,$69,$6f,$20,$30,$30,$2d,$30,$37,$2d,$30,$35,$00,$61,$72,$70
   .byte $65,$67,$67,$69,$6f,$20,$30,$30,$2d,$30,$41,$2d,$30,$35,$00,$61
   .byte $72,$70,$65,$67,$67,$69,$6f,$20,$30,$30,$2d,$30,$39,$2d,$30,$35
   .byte $00,$61,$72,$70,$65,$67,$67,$69,$6f,$20,$30,$30,$2d,$30,$38,$2d
   .byte $30,$33,$00,$4c,$65,$61,$64,$20,$50,$6f,$72,$74,$61,$6d,$65,$6e
   .byte $74,$6f,$20,$73,$6c,$6f,$77,$65,$72,$00,$4c,$65,$61,$64,$20,$50
   .byte $6f,$72,$74,$61,$6d,$65,$6e,$74,$6f,$20,$6d,$65,$64,$69,$75,$6d
   .byte $00

