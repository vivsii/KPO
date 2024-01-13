.586P
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO : DWORD
.STACK 4096

.CONST

.DATA

LONGF	DD 765432
BYTEF	DB 5
.CODE

main PROC

START: 
	push 0
	call ExitProcess
main ENDP
end main
