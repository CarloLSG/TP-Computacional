#include<iostream>
#include "MyForm.h"
using namespace std;
using namespace System;
using namespace TFMatematicaComputacional;
[STAThreadAttribute]

int main() {
	srand(time(NULL));

	MyForm^ miFormulario = gcnew MyForm();
	Application::Run(miFormulario);
	return 0;
}