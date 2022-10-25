#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

class Grid {
private:
	int num_elementos, random;

public:
	Grid() {}
	Grid(DataGridView^ datagridView1, int num_elementos) {

		this->num_elementos = num_elementos;
		datagridView1->RowCount = num_elementos;
		datagridView1->ColumnCount = num_elementos;
		datagridView1->RowHeadersVisible = false;
		datagridView1->ColumnHeadersVisible = false;

		for (int i = 0; i < num_elementos; i++) {
			for (int j = 0; j < num_elementos; j++) {

				datagridView1->Columns[j]->Width = 600 / num_elementos;
				datagridView1->Rows[j]->Height = 600 / num_elementos;
				datagridView1->Rows[i]->Cells[j]->Value = 0;
			}
		}
	}
	~Grid() {}

    void actualizarGrid(DataGridView^ datagridView1, int** matrix) {

        for (int i = 0; i < num_elementos; i++) {
            for (int j = 0; j < num_elementos; j++) {
                if (i == j) {
                    matrix[i][j] = 0;
                }
                if (j == 0) {
                    matrix[i][j] = 0;
                }
                if (i == num_elementos - 1) {
                    matrix[i][j] = 0;
                }
                if (matrix[i][j] != 0 && matrix[j][i] != 0) {
                    random = rand() % 2;
                    if (random == 0) {
                        matrix[i][j] = 0;
                    }
                    if (random == 1) {
                        matrix[j][i] = 0;
                    }
                }
                datagridView1->Rows[i]->Cells[j]->Value = matrix[i][j];
            }
        }
    }
};
