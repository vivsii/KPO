.586P													; ������� ������(��������� Pentium)
.MODEL FLAT, STDCALL									; ������ ������, ���������� � �������
includelib kernel32.lib									; ������������: ����������� � kernel32

ExitProcess PROTO : DWORD								; �������� �-�� ���������� �������� Windows
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	; �������� API-������� MessageBox

.STACK 4096												; ��������� 4�� �����

.CONST													; ������� ��������

.DATA
MB_OK	EQU 0											; EQU - ���������
STR1	DB "���� ������ ���������", 0					; ������ �������� 1 ����, ������ ������� ������ + ������� ���
STR2	DB "������ ����", 0								; ������ �������� 1 ����, ������ ������� ������ + ������� ���
HW		DD ?											; ������� ����� ������ 4 �����, ������������������

.CODE													; ������� ����

main PROC												; ����� ����� main
START :													; ����� ������
		PUSH MB_OK;
		PUSH OFFSET STR1;
		PUSH OFFSET STR2;
		PUSH HW;
		CALL MessageBoxA;								;����� �������

		INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK

	push - 1											; ��� �������� �������� Windows(�������� ExitProcess)
	call ExitProcess									; ��� ����������� ����� ������� Windows

main ENDP												; ����� ���������

end main												; ����� ������ main