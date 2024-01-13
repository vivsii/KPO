#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "Rus");

    Log::LOG log = Log::INITLOG;
    Out::OUT out = Out::INITOUT;
    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        log = Log::getlog(parm.log);
        out = Out::getout(parm.out);
        Log::WriteLine(log, "����: ", "��� ������ ", "");
        Log::WriteLine(log, L"����: ", L"��� ������\n ", L"");
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm.in);
        Log::WriteIn(log, in);
        Out::WriteIn(out, in);
        LT::LexTable lexTable;
        IT::IdTable	idTable;

        LA::FindLex(in, lexTable, idTable);

        lexTable.PrintLexTable(L"TableOfLexems.txt");
        idTable.PrintIdTable(L"TableOfIdentificators.txt");

        MFST_TRACE_START										//�������
            MFST::Mfst mfst(lexTable, GRB::getGreibach());			//�������
        mfst.start();											// ����� ��������������� �������
        mfst.savededucation();									//��������� ������� ������
        mfst.printrules();										//�������: ������� ������� ������

        for (int iter = 0, lt_position; iter < lexTable.size; iter++)
        {
            if (lexTable.table[iter - 1].lexema == LEX_EQUAL_SIGN)
            {
                if (PolishNotation::PolishNotation(iter, lexTable, idTable))
                {
                    cout << "�������� ������ ���������; ������: " << lexTable.table[iter].sn << endl;
                }
                else
                    cout << "�������� ������ �� ���������; ������: " << lexTable.table[iter].sn << endl;
            }
        }

        lexTable.PrintLexTable(L"TableOfLexemsPN.txt");

        LT::Delete(lexTable);
        IT::Delete(idTable);
        Log::Close(log);
        Out::Close(out);
    }
    catch (Error::ERROR e)
    {
        Log::WriteError(log, e);
        Out::WriteError(out, e);
    }
    system("pause");
    return 0;
}


