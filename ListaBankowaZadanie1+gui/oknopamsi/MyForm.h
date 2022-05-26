#pragma once
#include "pamsi.h"
namespace oknopamsi {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	kolejka nowa_kolejka;
	int max = 0,pom=0;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 35);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Pobierz bilet";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 167);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(270, 32);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Sprawdz ile jest osob w kolejce";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(13, 215);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(270, 32);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Obsluz pierwszą osobę";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(398, 215);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(270, 32);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Wyjście";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(397, 167);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(270, 32);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Wyczysc kolejke";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(397, 121);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(271, 35);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Sprawdz wielkosc struktury";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label1
			// 
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(692, 45);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Witamy w naszym banku !";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->UseCompatibleTextRendering = true;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(212, 82);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"->";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(30, 45);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(25, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"->";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 290);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	nowa_kolejka.wyczysc();
	exit(0);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	max++;
	int liczba = nowa_kolejka.daj_wielkosc();

	if (liczba > max) { max = liczba; }
	else if (liczba == max) { max++; }
	nowa_kolejka.zakolejkuj(max);

	label4->Text = "Kolejka -> ";
	int * kolejka = nowa_kolejka.wypisz_kolejke();
	int i = 0;
	pom = liczba;
	while (i< pom+1)
	{
	label4->Text = label4->Text+(System::Convert::ToString(kolejka[i])+ " ");
	i++;
	}
	
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	label3->Text = "Ilosc osob w kolejce to: " + System::Convert::ToString(nowa_kolejka.daj_wielkosc());
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nowa_kolejka.daj_wielkosc() > 0) {
		ilosc--;
		pom--;
		label3->Text = "Obsluzony numer: " + System::Convert::ToString(nowa_kolejka.zdejmij());
		
	}
	else
	{
		
		label3->Text = "Brak ludzi w kolejce !!! ";
	}
	label4->Text = "Kolejka -> ";
	int* kolejka = nowa_kolejka.wypisz_kolejke();
	int i = 0;
	while (i < pom+1)
	{
		label4->Text = label4->Text + (System::Convert::ToString(kolejka[i]) + " ");
		i++;
	}
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	label3->Text = "Wielkosc struktury to: " + System::Convert::ToString((ilosc * 16 + 24)) +" bajtow.";
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	nowa_kolejka.wyczysc();
	pom = 0;
	max = 0;

	label4->Text = "Kolejka -> ";
	int* kolejka = nowa_kolejka.wypisz_kolejke();
	int i = 0;
	while (i < pom)
	{
		label4->Text = label4->Text + (System::Convert::ToString(kolejka[i]) + " ");
		i++;
	}
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
