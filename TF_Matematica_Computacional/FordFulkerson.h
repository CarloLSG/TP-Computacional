#pragma once

#include <queue>

class FordFulkerson {
private:

	bool* flag;
	int respuesta;
	int peso;
	int** Grafo;
	int n;

public:
	FordFulkerson(int n) {
		this->n = n;
		respuesta = 0;
		Grafo = new int* [n];
	}

	~FordFulkerson() {}

	bool BFS(int** matrix, int origen, int sumidero, int m[]) {

		flag = new bool[n];

		for (int i = 0; i < n; i++) {
			flag[i] = 0;
		}

		queue<int> cola;
		cola.push(origen);
		flag[origen] = true;
		m[origen] = -1;

		while (!cola.empty()) {
			int aux = cola.front();
			cola.pop();

			for (int i = 0; i <= n - 1; i++) {
				if (flag[i] == false && matrix[aux][i] > 0) {
					if (i == sumidero) {
						m[i] = aux;
						return true;
					}
					cola.push(i);
					m[i] = aux;
					flag[i] = true;
				}
			}
		}
		return false;
	}

	int fordFulkerson(int** matrix, int origen, int sumidero) {
		int i;
		int j;
		int* aux = new int[n];

		for (i = 0; i < n; i++) {
			Grafo[i] = new int[n];
			for (j = 0; j < n; j++) {
				Grafo[i][j] = matrix[i][j];
			}
		}

		while (BFS(Grafo, origen, sumidero, aux)) {
			int peso;
			for (j = sumidero; j != origen; j = aux[j]) {
				i = aux[j];
				peso = min(peso, Grafo[i][j]);
			}

			for (j = sumidero; j != origen; j = aux[j]) {
				i = aux[j];
				Grafo[i][j] -= peso;
				Grafo[j][i] += peso;
			}
			respuesta += peso;
		}

		return respuesta;
	}
};