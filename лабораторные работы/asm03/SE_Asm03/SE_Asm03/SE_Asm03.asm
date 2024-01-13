.586P													; система подкоманд(процессор Pentium)
.MODEL FLAT, STDCALL									; модель памяти, соглашение о вызове
includelib kernel32.lib									; подключаем библиотеку с функцией ExitProcess, компановщику: компоновать с kernel32								
includelib user32.lib

ExitProcess PROTO :DWORD								; прототип функции для завершения процесса Windows
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD		; прототип API-функции MessageBoxA(парам: слово без знака 4 байта)

.STACK 4096												;сегмент стека размером 4096 Мбайт

.DATA													;сегмент данных
		myBytes		BYTE	10h, 20h, 30h, 40h
		myWords		WORD	8Ah, 3Bh, 44h, 5Fh, 99h
		myDoubles	DWORD	1, 2, 3, 4, 5, 6, 7
		SUM			DWORD   0

		str0		db		"Евсеенко Виктория, курс 2, ПОИТ 4 ", 0			
		str1		db		"Массив содержит 0 ", 0
		str2		db		"Массив не содержит 0 ", 0

.CODE													
main PROC												
start:	
		mov ESI, OFFSET myWords							;смещение myWords -> esi(косвенный операнд)
		mov AX, [ESI + 4]
		mov BX, [ESI + 2]

		mov edi, OFFSET myDoubles						;смещение myDoubles -> edi(косвенный операнд)
		mov ecx, 7										;счетчик
CYCLE:													;метка перехода
		mov eax, [edi]
		add SUM, eax
		add edi, type myDoubles
loop CYCLE												;выполняет блок команд заданное кол во раз

		mov edi, OFFSET myDoubles						;смещение myDoubles -> edi(косвенный операнд)
		mov ecx, 7										;счетчик
CYCLE_2:
		mov eax, [edi]									;eax -> edi
		add edi, type myDoubles							
		
		cmp eax, 0				
		jz  EXIT										;if eax

		cmp ecx,1
		jz  EXIT_2
loop CYCLE_2											;выполняет блок команд заданное кол во раз

EXIT:													
		mov eax, SUM									;загрузка в регистр eax(аккумулятор для промежуточных данных) значения переменной a
		mov EBX, 0
		invoke MessageBoxA, 0, offset str1, offset str0, 0	;встроенный макрос для вызова функции с прототипом, offset смещение метки данных относительно сегмента
		push 0											;код возврата процесса Windows (параметр ExitProcess)
		call ExitProcess								;так завершается любой процесс Windows


EXIT_2:													
		mov eax, SUM									;загрузка в регистр eax(аккумулятор для промежуточных данных) значения переменной SUM
		mov EBX, 1
		invoke MessageBoxA, 0, offset str2, offset str0, 0	;встроенный макрос для вызова функции с прототипом, offset смещение метки данных относительно сегмента
		push 0											;код возврата процесса Windows (параметр ExitProcess)
		call ExitProcess								;так завершается любой процесс Windows

main ENDP												;конец процедуры 

end main												;последняя инструкция программы, в ней указывается точка входа в программу 