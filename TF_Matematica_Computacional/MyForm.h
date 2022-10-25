#pragma once
#include <iostream>
#include "Grid.h"
#include "FordFulkerson.h"
#include "Dibujo.h"
#include <vector>

#include "Grafo.h"
#include "Linea.h"
#include "Numero.h"

namespace TFMatematicaComputacional {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
			graphics = miForm->CreateGraphics();
		}

	protected:

		~MyForm() {
			if (components) {
				delete components;
			}
			delete graphics;
			delete grid_obj;
		}

	private:

		Grid* grid_obj;
		FordFulkerson* ford;
		int n, random, fuente, sumidero;
		int** matrix = new int* [n];
		Graphics^ graphics;
		Pen^ pen;
		Form^ miForm = gcnew Form;

		System::Windows::Forms::TextBox^ tbN;
		System::Windows::Forms::Label^ txtN;
		System::Windows::Forms::Button^ btnGenerar;
		System::Windows::Forms::ComboBox^ cbFormato;
		System::Windows::Forms::Label^ txtFormato;
		System::Windows::Forms::DataGridView^ dataGridView;
		System::Windows::Forms::Timer^ timer1;
		System::Windows::Forms::Label^ capacidad;
		System::Windows::Forms::Label^ txtCapacidad;
		System::Windows::Forms::Label^ lblCoord1;
		System::Windows::Forms::Label^ lblDestino;
		System::Windows::Forms::Label^ destino;
		System::Windows::Forms::Label^ origen;
		System::ComponentModel::IContainer^ components;
		System::Windows::Forms::Label^ txtRespuesta;
		System::Windows::Forms::Label^ txtans;
		System::Windows::Forms::TextBox^ tbSumidero;
		System::Windows::Forms::TextBox^ tbFuente;
		System::Windows::Forms::Label^ txtFuente;
		System::Windows::Forms::Label^ txtSumidero;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   System::Windows::Forms::Button^ btnGraficar;


#pragma region Windows Form Designer generated code

		   void InitializeComponent(void) {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			   this->tbN = (gcnew System::Windows::Forms::TextBox());
			   this->txtN = (gcnew System::Windows::Forms::Label());
			   this->btnGenerar = (gcnew System::Windows::Forms::Button());
			   this->cbFormato = (gcnew System::Windows::Forms::ComboBox());
			   this->txtFormato = (gcnew System::Windows::Forms::Label());
			   this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->capacidad = (gcnew System::Windows::Forms::Label());
			   this->txtCapacidad = (gcnew System::Windows::Forms::Label());
			   this->lblCoord1 = (gcnew System::Windows::Forms::Label());
			   this->lblDestino = (gcnew System::Windows::Forms::Label());
			   this->destino = (gcnew System::Windows::Forms::Label());
			   this->origen = (gcnew System::Windows::Forms::Label());
			   this->txtRespuesta = (gcnew System::Windows::Forms::Label());
			   this->txtans = (gcnew System::Windows::Forms::Label());
			   this->tbSumidero = (gcnew System::Windows::Forms::TextBox());
			   this->tbFuente = (gcnew System::Windows::Forms::TextBox());
			   this->txtFuente = (gcnew System::Windows::Forms::Label());
			   this->txtSumidero = (gcnew System::Windows::Forms::Label());
			   this->btnGraficar = (gcnew System::Windows::Forms::Button());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // tbN
			   // 
			   this->tbN->Location = System::Drawing::Point(28, 50);
			   this->tbN->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tbN->Name = L"tbN";
			   this->tbN->Size = System::Drawing::Size(117, 22);
			   this->tbN->TabIndex = 2;
			   this->tbN->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // txtN
			   // 
			   this->txtN->AutoSize = true;
			   this->txtN->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtN->Location = System::Drawing::Point(51, 26);
			   this->txtN->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtN->Name = L"txtN";
			   this->txtN->Size = System::Drawing::Size(65, 17);
			   this->txtN->TabIndex = 1;
			   this->txtN->Text = L"n∈[5, 15]";
			   // 
			   // btnGenerar
			   // 
			   this->btnGenerar->BackColor = System::Drawing::SystemColors::Control;
			   this->btnGenerar->Enabled = false;
			   this->btnGenerar->Location = System::Drawing::Point(356, 50);
			   this->btnGenerar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnGenerar->Name = L"btnGenerar";
			   this->btnGenerar->Size = System::Drawing::Size(120, 26);
			   this->btnGenerar->TabIndex = 3;
			   this->btnGenerar->Text = L"Generar";
			   this->btnGenerar->UseVisualStyleBackColor = false;
			   this->btnGenerar->Click += gcnew System::EventHandler(this, &MyForm::btnGenerar_Click);
			   // 
			   // cbFormato
			   // 
			   this->cbFormato->Enabled = false;
			   this->cbFormato->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Personalizado", L"Aleatorio" });
			   this->cbFormato->Location = System::Drawing::Point(172, 50);
			   this->cbFormato->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->cbFormato->Name = L"cbFormato";
			   this->cbFormato->Size = System::Drawing::Size(160, 24);
			   this->cbFormato->TabIndex = 4;
			   // 
			   // txtFormato
			   // 
			   this->txtFormato->AutoSize = true;
			   this->txtFormato->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtFormato->Location = System::Drawing::Point(219, 27);
			   this->txtFormato->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtFormato->Name = L"txtFormato";
			   this->txtFormato->Size = System::Drawing::Size(60, 17);
			   this->txtFormato->TabIndex = 5;
			   this->txtFormato->Text = L"Formato";
			   // 
			   // dataGridView
			   // 
			   this->dataGridView->AllowUserToAddRows = false;
			   this->dataGridView->AllowUserToDeleteRows = false;
			   this->dataGridView->AllowUserToResizeColumns = false;
			   this->dataGridView->AllowUserToResizeRows = false;
			   this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView->GridColor = System::Drawing::Color::Black;
			   this->dataGridView->Location = System::Drawing::Point(25, 172);
			   this->dataGridView->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->dataGridView->Name = L"dataGridView";
			   this->dataGridView->RowHeadersWidth = 51;
			   this->dataGridView->Size = System::Drawing::Size(800, 738);
			   this->dataGridView->TabIndex = 242;
			   this->dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView_CellClick);
			   this->dataGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellEndEdit);
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 10;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // capacidad
			   // 
			   this->capacidad->AutoSize = true;
			   this->capacidad->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->capacidad->Location = System::Drawing::Point(669, 59);
			   this->capacidad->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->capacidad->Name = L"capacidad";
			   this->capacidad->Size = System::Drawing::Size(13, 17);
			   this->capacidad->TabIndex = 243;
			   this->capacidad->Text = L"-";
			   // 
			   // txtCapacidad
			   // 
			   this->txtCapacidad->AutoSize = true;
			   this->txtCapacidad->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtCapacidad->Location = System::Drawing::Point(641, 26);
			   this->txtCapacidad->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtCapacidad->Name = L"txtCapacidad";
			   this->txtCapacidad->Size = System::Drawing::Size(75, 17);
			   this->txtCapacidad->TabIndex = 244;
			   this->txtCapacidad->Text = L"Capacidad";
			   // 
			   // lblCoord1
			   // 
			   this->lblCoord1->AutoSize = true;
			   this->lblCoord1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->lblCoord1->Location = System::Drawing::Point(482, 26);
			   this->lblCoord1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblCoord1->Name = L"lblCoord1";
			   this->lblCoord1->Size = System::Drawing::Size(51, 17);
			   this->lblCoord1->TabIndex = 245;
			   this->lblCoord1->Text = L"Origen";
			   // 
			   // lblDestino
			   // 
			   this->lblDestino->AutoSize = true;
			   this->lblDestino->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->lblDestino->Location = System::Drawing::Point(562, 26);
			   this->lblDestino->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->lblDestino->Name = L"lblDestino";
			   this->lblDestino->Size = System::Drawing::Size(56, 17);
			   this->lblDestino->TabIndex = 246;
			   this->lblDestino->Text = L"Destino";
			   // 
			   // destino
			   // 
			   this->destino->AutoSize = true;
			   this->destino->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->destino->Location = System::Drawing::Point(581, 59);
			   this->destino->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->destino->Name = L"destino";
			   this->destino->Size = System::Drawing::Size(13, 17);
			   this->destino->TabIndex = 247;
			   this->destino->Text = L"-";
			   // 
			   // origen
			   // 
			   this->origen->AutoSize = true;
			   this->origen->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->origen->Location = System::Drawing::Point(500, 59);
			   this->origen->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->origen->Name = L"origen";
			   this->origen->Size = System::Drawing::Size(13, 17);
			   this->origen->TabIndex = 248;
			   this->origen->Text = L"-";
			   // 
			   // txtRespuesta
			   // 
			   this->txtRespuesta->AutoSize = true;
			   this->txtRespuesta->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtRespuesta->Location = System::Drawing::Point(541, 102);
			   this->txtRespuesta->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtRespuesta->Name = L"txtRespuesta";
			   this->txtRespuesta->Size = System::Drawing::Size(89, 17);
			   this->txtRespuesta->TabIndex = 250;
			   this->txtRespuesta->Text = L"Flujo máximo";
			   // 
			   // txtans
			   // 
			   this->txtans->AutoSize = true;
			   this->txtans->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtans->Location = System::Drawing::Point(581, 135);
			   this->txtans->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtans->Name = L"txtans";
			   this->txtans->Size = System::Drawing::Size(13, 17);
			   this->txtans->TabIndex = 251;
			   this->txtans->Text = L"-";
			   // 
			   // tbSumidero
			   // 
			   this->tbSumidero->Enabled = false;
			   this->tbSumidero->Location = System::Drawing::Point(187, 126);
			   this->tbSumidero->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tbSumidero->Name = L"tbSumidero";
			   this->tbSumidero->Size = System::Drawing::Size(117, 22);
			   this->tbSumidero->TabIndex = 252;
			   this->tbSumidero->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // tbFuente
			   // 
			   this->tbFuente->Enabled = false;
			   this->tbFuente->Location = System::Drawing::Point(25, 126);
			   this->tbFuente->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->tbFuente->Name = L"tbFuente";
			   this->tbFuente->Size = System::Drawing::Size(117, 22);
			   this->tbFuente->TabIndex = 253;
			   this->tbFuente->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // txtFuente
			   // 
			   this->txtFuente->AutoSize = true;
			   this->txtFuente->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtFuente->Location = System::Drawing::Point(56, 102);
			   this->txtFuente->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtFuente->Name = L"txtFuente";
			   this->txtFuente->Size = System::Drawing::Size(52, 17);
			   this->txtFuente->TabIndex = 254;
			   this->txtFuente->Text = L"Fuente";
			   // 
			   // txtSumidero
			   // 
			   this->txtSumidero->AutoSize = true;
			   this->txtSumidero->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			   this->txtSumidero->Location = System::Drawing::Point(212, 101);
			   this->txtSumidero->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->txtSumidero->Name = L"txtSumidero";
			   this->txtSumidero->Size = System::Drawing::Size(68, 17);
			   this->txtSumidero->TabIndex = 255;
			   this->txtSumidero->Text = L"Sumidero";
			   // 
			   // btnGraficar
			   // 
			   this->btnGraficar->BackColor = System::Drawing::SystemColors::Control;
			   this->btnGraficar->Location = System::Drawing::Point(356, 123);
			   this->btnGraficar->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->btnGraficar->Name = L"btnGraficar";
			   this->btnGraficar->Size = System::Drawing::Size(171, 28);
			   this->btnGraficar->TabIndex = 256;
			   this->btnGraficar->Text = L"Calcular Flujo Máximo";
			   this->btnGraficar->UseVisualStyleBackColor = false;
			   this->btnGraficar->Click += gcnew System::EventHandler(this, &MyForm::btnGraficar_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(723, 26);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(120, 120);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 257;
			   this->pictureBox1->TabStop = false;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			   this->ClientSize = System::Drawing::Size(855, 934);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->btnGraficar);
			   this->Controls->Add(this->txtSumidero);
			   this->Controls->Add(this->txtFuente);
			   this->Controls->Add(this->tbFuente);
			   this->Controls->Add(this->tbSumidero);
			   this->Controls->Add(this->txtans);
			   this->Controls->Add(this->txtRespuesta);
			   this->Controls->Add(this->origen);
			   this->Controls->Add(this->destino);
			   this->Controls->Add(this->lblDestino);
			   this->Controls->Add(this->lblCoord1);
			   this->Controls->Add(this->txtCapacidad);
			   this->Controls->Add(this->capacidad);
			   this->Controls->Add(this->dataGridView);
			   this->Controls->Add(this->txtFormato);
			   this->Controls->Add(this->cbFormato);
			   this->Controls->Add(this->btnGenerar);
			   this->Controls->Add(this->tbN);
			   this->Controls->Add(this->txtN);
			   this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			   this->Name = L"MyForm";
			   this->Text = L"Flujo Maximo";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();
			   this->BackColor = Color(Color::Black);
			   miForm->ClientSize = System::Drawing::Size(810, 600);
			   miForm->BackColor = Color(Color::Black);
		   }
#pragma endregion

	private:

		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {}

		System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
			if (tbN->Text != "") {
				n = Convert::ToInt32(tbN->Text);

				if (n >= 5 && n <= 15) {
					cbFormato->Enabled = true;

					if (cbFormato->Text == "Aleatorio") {
						for (int i = 0; i < n; i++) {
							matrix[i] = new int[n];
							for (int j = 0; j < n; j++) {
								matrix[i][j] = rand() % 7 + 1;

								if (i == j) {
									matrix[i][j] = 0;
								}
								if (j == 0) {
									matrix[i][j] = 0;
								}
								if (i == n - 1) {
									matrix[i][j] = 0;
								}
								if (j == n-1 && i == 0) {
									matrix[i][j] = 0;
								}
							}
						}
						
					}

					else if (cbFormato->Text == "Personalizado") {
						for (int i = 0; i < n; i++) {
							matrix[i] = new int[n];
							for (int j = 0; j < n; j++) {
								matrix[i][j] = 0;
							}
						}
					}
					cbFormato->Enabled = true;
					btnGenerar->Enabled = true;
				}
			}
			

		}

		System::Void btnGenerar_Click(System::Object^ sender, System::EventArgs^ e) {
			grid_obj = new Grid(dataGridView, n);
			grid_obj->actualizarGrid(dataGridView, matrix);
			tbN->Text = "";
			cbFormato->Text = "";
			tbFuente->Enabled = true;
			tbSumidero->Enabled = true;
			btnGenerar->Enabled = false;
		}

		System::Void dataGridView1_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

			if (dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value != NULL) {
				matrix[int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())]
					  [int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())]
				     = int::Parse(dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString());

				if (int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString()) == int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())) {
					MessageBox::Show("La matriz no puede ser Reflexiva");
					dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = 0;
					matrix[int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())]
						  [int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())] = 0;
				}

				else if (matrix[int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())]
					           [int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())] != 0 && 
					     matrix[int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())]
					           [int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())] != 0) {
					dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = 0;
					matrix[int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())]
						  [int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())] = 0;
					MessageBox::Show("La matriz debe de ser Antisimetrica");
				}
				grid_obj->actualizarGrid(dataGridView, matrix);
			}
		}

		System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
			origen->Text = dataGridView->Rows[e->RowIndex]->Index.ToString();
			destino->Text = dataGridView->Columns[e->ColumnIndex]->Index.ToString();
			capacidad->Text = matrix[int::Parse(dataGridView->Rows[e->RowIndex]->Index.ToString())]
				                    [int::Parse(dataGridView->Columns[e->ColumnIndex]->Index.ToString())].ToString();
		}
	
		System::Void btnGraficar_Click(System::Object^ sender, System::EventArgs^ e) {
			vector<vector<Dibujo*> > dibujo;
			vector<Dibujo*> aux;

			int cont, inicio, fin;

			if (miForm->Visible) {
				miForm->Hide();
			}
			miForm->Show();

			if (tbFuente->Text != "" && tbSumidero->Text != "") {
				if (int::Parse(tbFuente->Text->ToString()) >= 0 && int::Parse(tbFuente->Text->ToString()) < n) {
					if (int::Parse(tbSumidero->Text->ToString()) >= 0 && int::Parse(tbSumidero->Text->ToString()) < n) {
						fuente = int::Parse(tbFuente->Text->ToString());
						sumidero = int::Parse(tbSumidero->Text->ToString());
					}
				}
			}
			else {
				fuente = 0;
				sumidero = n - 1;
			}

			ford = new FordFulkerson(n);
			txtans->Text = ford->fordFulkerson(matrix, fuente, sumidero).ToString();

			Grafo* grafo = new Grafo;
			Numero* numero = new Numero;
			Linea* linea = new Linea;

			for (int i = 0; i < n; i++) {
				grafo->dibujar(graphics, 0, i * 40.3);
				numero->escribir(graphics, i, 0, i * 40.3, 15);
			}


			for (int i = 0; i < n; i++) {
				cont = 1;
				inicio = 35;

				for (int j = 0; j < n; j++) {
					if (matrix[i][j] > 0) {
						grafo->dibujar(graphics, cont * 50, i * 40.3);
						numero->escribir(graphics, j, cont * 50, i * 40.3, 15);
						linea->dibujar(graphics, inicio, 17.5 + (i * 40.3), inicio + 15, 17.5 + (i * 40.3));
						numero->escribir(graphics, matrix[i][j], (inicio - 15 / 2), (i * 40.3) - 4.5, 9);

						inicio += 50;
						cont++;
					}
				}
			}

			tbFuente->Text = "";
			tbSumidero->Text = "";
			tbN->Text = "";
			cbFormato->Text = "";
		}

		System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			timer1->Enabled = false;
			miForm->Close();
		}
	};
}
