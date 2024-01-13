.586P
.MODEL FLAT, STDCALL

includelib kernel32.lib
includelib "..\Debug\SE_asm01a.lib"

ExitProcess      PROTO: DWORD
SetConsoleTitleA  PROTO: DWORD
GetStdHandle    PROTO: DWORD
WriteConsoleA    PROTO: DWORD, : DWORD, : DWORD, : DWORD, : DWORD
getmin        PROTO: DWORD, : DWORD
getmax        PROTO: DWORD, : DWORD

.STACK 4096

.CONST 
consoletitle  DB 'SE_asm01b', 0
Arr        DD 56, 32, 82, -2, 10, 98, -17, -11, 7, 4

.DATA
result1      BYTE "getmax + getmin = ", 0
result      sdword 0
result2      BYTE 40 dup(0)
consolehandle  DD 0h

.CODE
main PROC

  invoke SetConsoleTitleA, offset consoletitle          ; ������������� ��������� �������
  push -11                            ; �������� ����� ������� ��� ������
  call GetStdHandle
  mov consolehandle, eax

  invoke getmin, offset Arr, lengthof Arr            ; �������� ������� getmin ��� ������� Arr

  mov result, eax

  invoke getmax, offset Arr, lengthof Arr

  add result, eax                        ; ���������� ���������� getmin � getmax
  xor eax, eax							 ; ��� ������� �������

  push result							 ; ���������� result � ����
  push offset result2                    ; ���������� � ���� ������ �� ������ ���� ����� ������ ���������
  call tochar							 ; ����������� ��������� � ������

  invoke WriteConsoleA, consolehandle, offset result1, sizeof result1, 0, 0
  invoke WriteConsoleA, consolehandle, offset result2, sizeof result2, 0, 0

  push 0
  call ExitProcess

main ENDP

tochar PROC uses eax ebx ecx edi esi, pstr : dword, intfield : sdword
  mov edi, pstr
  mov esi, 0
  mov eax, intfield
  cdq
  mov ebx, 10
  idiv ebx
cycle:
  push dx								 ; ��������� ������� � ����
  inc esi
  test eax, eax                          ; ���� ��������� ������� �� 10 ����� 0, ��������� ����
  jz fin								 ; ���������� �� 64 ���
  cdq									 ; ������� ����� �� 10
  idiv ebx
  jmp cycle
fin:
  mov ecx, esi							 ; ���������� ���� � �����
write: 
  pop bx								 ; ��������� ������� �� �����
  add bl, '0'							 ; ����������� � ASCII � ���������� � ������
  mov[edi], bl
  inc edi
  loop write							; ��������� � ��������� �����
  ret
tochar ENDP

END main