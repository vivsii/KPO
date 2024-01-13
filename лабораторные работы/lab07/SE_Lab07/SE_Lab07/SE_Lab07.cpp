#include "Call.h"

using namespace Call;
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	int a = 5;
	int res_cdevl = cdevl(2, 7, 5);

	int res_cstd = cstd(a, 8, 2);

	int res_cfst = cfst(8, 2, 2, 9);


	cout << res_cdevl << endl;
	cout << res_cstd << endl;
	cout << res_cfst << endl;
}