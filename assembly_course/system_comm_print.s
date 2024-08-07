.global _start
_start:
   MOV R0, #1
   MOV R1, =message
   MOV R2, =len
   MOV R7, #4
   SWI 0
   MOV R7, #1
   SWI 0

.data
message:
   .asciiz “hello world \n”
len = .-message