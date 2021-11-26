#include "define/stdafx.h"
#include "api/xor.h"
#include "api/api.h"
#include "driver/driver.h"
#include "inject/injector.h"
#include "api/drvutils.h"

int main() 
{
    start_driver();
    cout << endl;

    inject(xor_a("Halo Infinite"), xor_w(L"test.dll"));

    cout << endl;
	system("pause");
}