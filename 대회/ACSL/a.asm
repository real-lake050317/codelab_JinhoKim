NUM  DC    440
M    DC    0

TOP1 LOAD  NUM
     SUB   =2
     BL    STOP
     LOAD  =2
     STORE NUM

TOP2 LOAD  NUM
     DIV   FACT
     STORE QUOT
     MULT  FACT
     SUB   NUM
     BE    NEXT
     LOAD  FACT
     ADD   =1
     STORE FACT
     BU    TOP2

NEXT LOAD  FACT
     SUB   M
     BL    CONT
     LOAD  FACT
     STORE MULT

CONT LOAD  QUOT
     STORE NUM
     BU    TOP1

STOP PRINT MULT
     END

