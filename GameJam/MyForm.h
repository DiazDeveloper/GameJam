#pragma once
#include "Carrera.h"

namespace GameJam {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		Graphics^ canvas;
		BufferedGraphicsContext^ context;
		BufferedGraphics^ buffer;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Timer^ timer3;
		   Carrera* carrera;

	public:
		MyForm(void)
		{
			InitializeComponent();
			canvas = this->CreateGraphics();
			context = BufferedGraphicsManager::Current;
			buffer = context->Allocate(canvas, this->ClientRectangle);
			carrera = new Carrera();  
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(182, 204);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(308, 168);
			this->button1->TabIndex = 0;
			this->button1->Text = L"CARRERITAS :D";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(569, 203);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(293, 169);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Carritos Chocones :O";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1002, 601);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
	}


	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{

		carrera->mostrar(canvas);
		carrera->moverCarrera(canvas);  
		carrera->AcabarCarrera(canvas);

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer1->Enabled = true;
		button1->Visible = false;
		button2->Visible = false;
	}
	
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		int numero = carrera->GenerarNumeroRandom();
		carrera->GenerarCarro(numero); 
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		timer2->Enabled = true;
		timer3->Enabled = true;
		button1->Visible = false;
		button2->Visible = false;
	}

    
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) 
    {
	    carrera->mostrar(canvas); 
	    carrera->moverDiagonal(canvas);
		carrera->detectarColision1(); 
		carrera->detectarColision2();
		carrera->detectarColision3();  
    }
};
}
