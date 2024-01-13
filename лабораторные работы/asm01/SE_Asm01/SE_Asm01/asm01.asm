.586P													; система команд(процессор Pentium)
.MODEL FLAT, STDCALL									; модель памяти, соглашение о вызовах
includelib kernel32.lib									; компановщику: компановать с kernel32

ExitProcess PROTO : DWORD								; прототип ф-ии завершения процесса Windows
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	; прототип API-функции MessageBox

.STACK 4096												; выделение 4мб стека

.CONST													; сегмент констант

.DATA
MB_OK	EQU 0											; EQU - константа
STR1	DB "Моия первая программа", 0					; строка размером 1 байт, первый элемент данные + нулевой бит
STR2	DB "Привет всем", 0								; строка размером 1 байт, первый элемент данные + нулевой бит
HW		DD ?											; двойное слово длиной 4 байта, неинициализировано

.CODE													; сегмент кода

main PROC												; точка входа main
START :													; метка начала
		PUSH MB_OK;
		PUSH OFFSET STR1;
		PUSH OFFSET STR2;
		PUSH HW;
		CALL MessageBoxA;								;вызов функции

		INVOKE MessageBoxA, HW, OFFSET STR2, OFFSET STR1, MB_OK

	push - 1											; код возврата процесса Windows(параметр ExitProcess)
	call ExitProcess									; так возращается любой процесс Windows

main ENDP												; конец процедуры

end main												; конец модуля main