#pragma once
using namespace std;
using namespace System;

class Numero {
private:

public:

    Numero() {}
    ~Numero() {}

    void escribir(Graphics^ graphics, int num, int x, int y, int tama�o) {

        FontFamily^ fntFamily = gcnew FontFamily("Times New Roman");
        System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, tama�o, FontStyle::Regular);
        graphics->DrawString(num.ToString(), fntWrite, Brushes::Gray, x+10, y+5.5);
    }


};