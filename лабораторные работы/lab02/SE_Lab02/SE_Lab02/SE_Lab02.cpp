#include <iostream>
#include <cmath>

// 2
#define X 12
#define Y 13
#define Z 14
#define S 4.0
//12 = 0000 0000 0000 1100 = 0000 000c

void func();
void func2();

int main()
{
    // 4
    bool b_first = false; //00
    bool b_second = true; //01

    // 5
    char c_latin = 'v'; //76

    // 6
    char c_cyrillic = 'в'; //e2

    // 7
    wchar_t wc_latin = L'E'; // UTF-16 00 45

    // 8
    wchar_t wc_cyrillic = L'е'; // UTF-16 04 35

    size_t size = sizeof(wchar_t); //00 00 00 02 // вызываем размер типа данных

    //9
    short n_first = X; // 0000 0000 0000 1100(пк) = 00 c0 = 12
    short n_second = -X; // 0000 0000 0000 1100(пк) = 1111 1111 1111 00 11(ок) = 1111 1111 1111 0110(дк) = ff fс = -12

    // 10
    short n_max = 0x7fff; // 32767 = 7f ff = 0111 1111 1111 1111(пк)
    short n_min = 0x8000; // -32768 = 80 00 = 0111 1111 1111 1111(пк) = 1000 0000 0000 0000(ок) = 1000 0000 0000 0000 0001(дк)

    // 11
    unsigned short un_max = 0xffff; // 65535 = ff ff = 1111 1111 1111 1111 
    unsigned short un_min = 0x0000; // 0

    // 12
    int i_first = Y; // 13 = 00 00 00 10 = 858993460 = 00 00 00 0d = 0000 0000 0000 1010
    int i_second = -Y; // 13 = ff ff ff f0 = -858993460 = 0000 0000 0000 1010(пк) = 1111 1111 1111 0101(ок) = 1111 1111 1111 0110(дк)

    // 13
    int i_max = 0x7fffffff; // 2147483647 = 7f ff ff ff = 0111 1111 1111 1111 1111 1111 1111 1111 
    int i_min = 0x80000000; // -2147483648 = 80 00 00 00 = 0111 1111 1111 1111 1111 1111 1111 1111(пк) = 1000 0000 0000 0000 0000 0000 0000 0000(ок) = 1000 0000 0000 0000 0000 0000 0000 0001(дк)
    // 14
    unsigned int ui_max = 0xffffffff; // 4294967295 = ff ff ff ff = 1111 1111 1111 1111 1111 1111 1111 1111
    unsigned int ui_min = 0x00000000; // 0

    // 15
    long l_first = Z; // 00 00 00 00 00 00 00 14 = 00 00 00 0e = 0000 0000 0000 0000 0000 0000 0000 1110
    long l_second = -Z; // ff ff ff ff ff ff ff ef = ff ff ff f2 = 0000 0000 0000 0000 0000 0000 0000 1110(пк) = 1111 1111 1111 1111 1111 1111 1111 0001(ок) = 1111 1111 1111 1111 1111 1111 1111 0010(дк)

    // 16
    long l_max = 0x7fffffff; // 9223372036854775807 = ff ff ff ff = 1111 1111 1111 1111 1111 1111 1111 1111
    long l_min = 0x80000000; // -9223372036854775808 = 00 00 00 00

    // 17
    unsigned long ul_max = 0xffffffff; // 18446744073709551615 = ff ff ff ff = 1111 1111 1111 1111 1111 1111 1111 1111
    unsigned long ul_min = 0x00000000; // 0

    // 18
    float f_first = S; // 40 80 00 00 = | 0.10000001.1000000100000000000000 стандарт IEEE 754 бит знака.смещенная экспонента.мантисса
    float f_second = -S; // c0 e0 00 00 | 1.10000001.1000000100000000000000

    // 19
    float f_p_inf = f_first / 0; //7f 80 00 00
    float f_m_inf = f_second / 0; //ff 80 00 00
    float f_m_nan = std::sqrt(f_second); //ff c0 00 00S

    // 20
    char* p_char = &c_latin;
    wchar_t* p_wchar = &wc_latin;
    short* p_short = &n_first;
    int* p_int = &i_first;
    float* p_float = &f_first;
    double fl_double = S;
    double* p_double = &fl_double;

    p_char += 3;
    p_wchar += 3;
    p_short += 3;
    p_int += 3;
    p_float += 3;
    fl_double += 3;
    p_double += 3;

    // 21
    void (*fn)();
    fn = func;
    fn();
    fn = func2;
    fn();

    return 0;
}

void func()
{
    std::cout << "First func";
}

void func2() {
    std::cout << "Second func";
}
