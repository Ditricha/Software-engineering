#include "MyForm.h"
#include "about.h"
#include "integral.h"

using namespace Project2;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew MyForm());
    return 0;
}
