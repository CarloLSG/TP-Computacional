#pragma once
using namespace std;
using namespace System;

class Grafo {
private:
	char origen;
	char destino;
	int peso;

public:

	Grafo() {}
	~Grafo() {}

	void setOrigen(char origen) { this->origen = origen; }
	char getOrigen() { return origen; }
	void setDestino(char destino){ this->destino = destino; }
	char getDestino(){ return destino; }
	void setPeso(int peso) { this->peso = peso; }
	int getPeso() { return peso; }

	void dibujar(Graphics^ graphics, int x, int y) {

		graphics->DrawRectangle(Pens::Gray, x, y, 35, 35);

		/*graphics->DrawEllipse(Pens::Black, x, y, 35, 35);*/
	
	}
};