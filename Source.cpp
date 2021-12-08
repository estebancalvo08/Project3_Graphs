#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace std;
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    GoogleGraph1::MyForm form;
    Application::Run(% form);
	return 0;
}