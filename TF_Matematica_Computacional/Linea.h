#pragma once
using namespace std;
using namespace System;

class Linea {
private:

public:

    Linea() {}
    ~Linea() {}

    void dibujar(Graphics^ graphics, int x0, int y0, int x1, int y1) {

        graphics->DrawLine(gcnew Pen(Color::Gray), x0, y0, x1, y1);

        graphics->DrawLine(gcnew Pen(Color::Gray), x0 + 5, y0 - 3, x1, y1);
        graphics->DrawLine(gcnew Pen(Color::Gray), x0 + 5, y0 + 3, x1, y1);

    }


};
