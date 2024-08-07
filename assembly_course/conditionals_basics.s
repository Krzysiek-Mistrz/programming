.global _start
_start:
   MOV R0, #1
   MOV R1, #2
   CMP R0, R1
   BGT greater
   MOV R2, #2
   BAL default
greater:
   MOV R2, #1
default:
   MOV R2, #2 