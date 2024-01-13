.586P													; ������� ���������(��������� Pentium)
.MODEL FLAT, STDCALL									; ������ ������, ���������� � ������
includelib kernel32.lib									; ���������� ���������� � �������� ExitProcess, ������������: ����������� � kernel32								
includelib user32.lib

ExitProcess PROTO :DWORD								; �������� ������� ��� ���������� �������� Windows
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD		; �������� API-������� MessageBoxA(�����: ����� ��� ����� 4 �����)

.STACK 4096												;������� ����� �������� 4096 �����

.DATA													;������� ������
		myBytes		BYTE	10h, 20h, 30h, 40h
		myWords		WORD	8Ah, 3Bh, 44h, 5Fh, 99h
		myDoubles	DWORD	1, 2, 3, 4, 5, 6, 7
		SUM			DWORD   0

		str0		db		"�������� ��������, ���� 2, ���� 4 ", 0			
		str1		db		"������ �������� 0 ", 0
		str2		db		"������ �� �������� 0 ", 0

.CODE													
main PROC												
start:	
		mov ESI, OFFSET myWords							;�������� myWords -> esi(��������� �������)
		mov AX, [ESI + 4]
		mov BX, [ESI + 2]

		mov edi, OFFSET myDoubles						;�������� myDoubles -> edi(��������� �������)
		mov ecx, 7										;�������
CYCLE:													;����� ��������
		mov eax, [edi]
		add SUM, eax
		add edi, type myDoubles
loop CYCLE												;��������� ���� ������ �������� ��� �� ���

		mov edi, OFFSET myDoubles						;�������� myDoubles -> edi(��������� �������)
		mov ecx, 7										;�������
CYCLE_2:
		mov eax, [edi]									;eax -> edi
		add edi, type myDoubles							
		
		cmp eax, 0				
		jz  EXIT										;if eax

		cmp ecx,1
		jz  EXIT_2
loop CYCLE_2											;��������� ���� ������ �������� ��� �� ���

EXIT:													
		mov eax, SUM									;�������� � ������� eax(����������� ��� ������������� ������) �������� ���������� a
		mov EBX, 0
		invoke MessageBoxA, 0, offset str1, offset str0, 0	;���������� ������ ��� ������ ������� � ����������, offset �������� ����� ������ ������������ ��������
		push 0											;��� �������� �������� Windows (�������� ExitProcess)
		call ExitProcess								;��� ����������� ����� ������� Windows


EXIT_2:													
		mov eax, SUM									;�������� � ������� eax(����������� ��� ������������� ������) �������� ���������� SUM
		mov EBX, 1
		invoke MessageBoxA, 0, offset str2, offset str0, 0	;���������� ������ ��� ������ ������� � ����������, offset �������� ����� ������ ������������ ��������
		push 0											;��� �������� �������� Windows (�������� ExitProcess)
		call ExitProcess								;��� ����������� ����� ������� Windows

main ENDP												;����� ��������� 

end main												;��������� ���������� ���������, � ��� ����������� ����� ����� � ��������� 