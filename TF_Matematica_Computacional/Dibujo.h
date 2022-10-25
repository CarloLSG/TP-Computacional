#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Dibujo {
private:
    int n;
    int x, y;
    int width, height;

public:
    Dibujo(int n, int x, int y, int width, int height) { //el n es el numero que se dibuja, x e y son las coordenada 
        this->n = n;
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }
    ~Dibujo() {}

    void dibujar(Graphics^ g) {
        Pen^ p = gcnew Pen(Color::Gray, 2);
        Font^ f = gcnew Font("Arial", 14);
        String^ namba = gcnew String(to_string(n).c_str());
        g->DrawEllipse(p, x, y, width, height);
        g->DrawString(namba, f, Brushes::Gray, x + 8, y + 5.5);
    }

    int getn() {
        return this->n;
    }

    int getx() {
        return this->x;
    }

    int gety() {
        return this->y;
    }

    void linea(Graphics^ g, int x1, int y1) {
        g->DrawLine(Pens::Black, x + width, y + height / 2, x1, y1 + height / 2);
    }

    Rectangle getRectangle() {
        return Rectangle(x, y, width, height);
    }

    void peso(Graphics^g, int x1, int num) {
        Font^ f = gcnew Font("Arial", 10);
        g->DrawString(num.ToString(), f, Brushes::Black, ((x + width / 2) + (x1 + width / 2)) / 2, (y - height / 2) + 15);

    }

};

//vector<Dibujo*> dibujo; 
//este vector debe almacenar 
//0(hago que el primero que se guarde sea en ese orden)->1->3
//1(posicion del vector)->4->10->5
//primero dibujas los circulos
//después el línea que va desde dibujo->getx(), dibujo->gety()