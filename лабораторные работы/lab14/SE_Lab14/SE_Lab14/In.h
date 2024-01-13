#pragma once
#pragma once
#define IN_MAX_LEN_TEXT 1024*1024 // ������������ ������ ��������� ����
#define IN_CODE_ENDL '\n' // ������ ����� ������

// ������� �������� ������� ����������, ������ = ��� (Windows-1251) �������
// �������� IN::F - ����������� ������, IN::F = ����������� ������, IN::F - ������������ (�� �������),
// ���� 0 <= �������� < 256 - �� �������� ������ ��������

#define MAX_LEN_LINE 1000
namespace In
{
    void dell_in(char* str, int index);
    struct IN
    {
        enum
        {
            T = 1024, // ���������� ������
            F = 2048, // ������������
            I = 4096 // ������������, ����� ��������
        };

        int size, // ������ ��������� ����
            lines, // ���������� �����
            ignore; // ���������� ����������������� ��������

        unsigned char* text; // �������� ���(Windows-1251);

        int code[256] =
        {
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 0
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 16
          IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, // 32
          IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 48
          IN::F, IN::T, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, // 64
          IN::F, IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::F, IN::I, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 80
          IN::F, IN::T, IN::F, IN::F, IN::F, IN::T, IN::F, IN::I, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, // 96
          IN::F, IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, // 112

          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 128
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 144
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 160
          IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, // 176
          '-', IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::F, // 192
          IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, // 208
          IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::T, IN::T, IN::F, // 224
          IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T
        }; // ������� ��������: T, F, I ����� ��������

        IN()
        {
            code[248] = IN::T;
        }

    };

    IN getin(wchar_t infile[]);
}