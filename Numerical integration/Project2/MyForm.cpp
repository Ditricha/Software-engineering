#include "MyForm.h" //the header name for your form
#include "about.h"
#include "integral.h"

using namespace Project2; //name of your project
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    //Project2::MyForm form;   //Project2 - name of your project
    //Application::Run(% form);

    Application::Run(gcnew MyForm());
    return 0;
}