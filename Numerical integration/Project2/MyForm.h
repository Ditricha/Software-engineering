#pragma once
#include <cmath>
#include "about.h"
#include "integral.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ func_type;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ x1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ x2;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оЗаданииToolStripMenuItem;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ result;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ step;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ precision;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ method;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->result = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->step = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->precision = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->method = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->x2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->x1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->func_type = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оЗаданииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(3, 29);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(651, 515);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->result);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->step);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->precision);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->method);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->x2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->x1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->func_type);
			this->groupBox1->Location = System::Drawing::Point(663, 29);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(413, 518);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные данные";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 452);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(221, 20);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Результат интегрирования:";
			// 
			// result
			// 
			this->result->Location = System::Drawing::Point(235, 449);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(168, 26);
			this->result->TabIndex = 14;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(184, 380);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(201, 34);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Вычислить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// step
			// 
			this->step->Location = System::Drawing::Point(168, 335);
			this->step->Name = L"step";
			this->step->Size = System::Drawing::Size(235, 26);
			this->step->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 338);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Введите шаг:";
			// 
			// precision
			// 
			this->precision->Location = System::Drawing::Point(169, 290);
			this->precision->Name = L"precision";
			this->precision->Size = System::Drawing::Size(235, 26);
			this->precision->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 293);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Введите точность:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(337, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Выберите методля вычисления интеграла";
			// 
			// method
			// 
			this->method->FormattingEnabled = true;
			this->method->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"метод средних прямоугольников с точностью", L"метод трапеции с шагом",
					L"метод дихотомии с точностью"
			});
			this->method->Location = System::Drawing::Point(6, 247);
			this->method->Name = L"method";
			this->method->Size = System::Drawing::Size(398, 28);
			this->method->TabIndex = 7;
			this->method->Text = L"(пока не выбрано)";
			this->method->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::method_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 140);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Конечная точка:";
			// 
			// x2
			// 
			this->x2->Location = System::Drawing::Point(168, 137);
			this->x2->Name = L"x2";
			this->x2->Size = System::Drawing::Size(236, 26);
			this->x2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Начальная точка:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// x1
			// 
			this->x1->Location = System::Drawing::Point(169, 95);
			this->x1->Name = L"x1";
			this->x1->Size = System::Drawing::Size(235, 26);
			this->x1->TabIndex = 3;
			this->x1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(184, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(201, 32);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(267, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выберите функцию для проверки";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// func_type
			// 
			this->func_type->FormattingEnabled = true;
			this->func_type->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"y = cos(x)", L"y = 1/2 * ((x^2) - 5) * sin(3*x)" });
			this->func_type->Location = System::Drawing::Point(6, 52);
			this->func_type->Name = L"func_type";
			this->func_type->Size = System::Drawing::Size(398, 28);
			this->func_type->TabIndex = 0;
			this->func_type->Text = L"(пока не выбрано)";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->справкаToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1076, 36);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->оЗаданииToolStripMenuItem });
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(97, 32);
			this->справкаToolStripMenuItem->Text = L"Справка";
			// 
			// оЗаданииToolStripMenuItem
			// 
			this->оЗаданииToolStripMenuItem->Name = L"оЗаданииToolStripMenuItem";
			this->оЗаданииToolStripMenuItem->Size = System::Drawing::Size(199, 34);
			this->оЗаданииToolStripMenuItem->Text = L"О задании";
			this->оЗаданииToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оЗаданииToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1076, 547);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Графики";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Click += gcnew System::EventHandler(this, &MyForm::оЗаданииToolStripMenuItem_Click);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		double max;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (func_type->SelectedIndex != -1 && x1->Text != "" && x2->Text != "") {
			chart1->Series["Series1"]->Points->Clear();
			max = Convert::ToDouble(x2->Text);
			switch (func_type->SelectedIndex) {
			case 0:
				for (double i = Convert::ToDouble(x1->Text); i < max; i += 0.1)
					chart1->Series["Series1"]->Points->AddXY(i, cos(i));
				break;
			case 1:
				for (double i = Convert::ToDouble(x1->Text); i < max; i += 0.1)
					chart1->Series["Series1"]->Points->AddXY(i, (0.5 * (pow(i, 2) - 5) * sin(3 * i)));
				break;
			}
		}
		else MessageBox::Show("Возможно, не все поля заполнены.\nПроверьте данные и повторите попыткую.");
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void оЗаданииToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	about^ ab = gcnew about();
	ab->ShowDialog();
}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	double eps, h, a, b, integral;
	
	a = Convert::ToDouble(x1->Text);
	b = Convert::ToDouble(x2->Text);

	if (func_type->SelectedIndex == 0 && x1->Text != "" && x2->Text != "") {
		switch (method->SelectedIndex) {
		case 0:
			if (precision->Text != "" && step->Text == "") {
				precision->Text = precision->Text->Replace(".", ",");
				eps = Convert::ToDouble(precision->Text);
				integral = RectangleMethod(a, b, eps, f1);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
			break;
		case 1:
			if (step->Text != "" && precision->Text == "") {
				step->Text = step->Text->Replace(".", ",");
				h = Convert::ToDouble(step->Text);
				integral = TrapezoidalRule(a, b, h, f1);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
			break;
		case 2:
			if (precision->Text != "" && step->Text == "") {
				precision->Text = precision->Text->Replace(".", ",");
				eps = Convert::ToDouble(precision->Text);
				integral = DichotomyMethod(a, b, eps, f1);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
		default:
			MessageBox::Show("Возможно, где-то ошибка.\nПроверьте данные и повторите попыткую.");
		}
	}
	else if (func_type->SelectedIndex == 1 && x1->Text != "" && x2->Text != "") {
		switch (method->SelectedIndex) {
		case 0:
			if (precision->Text != "" && step->Text == "") {
				precision->Text = precision->Text->Replace(".", ",");
				eps = Convert::ToDouble(precision->Text);
				integral = RectangleMethod(a, b, eps, f2);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
			break;
		case 1:
			if (step->Text != "" && precision->Text == "") {
				step->Text = step->Text->Replace(".", ",");
				h = Convert::ToDouble(step->Text);
				integral = TrapezoidalRule(a, b, h, f2);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
			break;
		case 2:
			if (precision->Text != "" && step->Text == "") {
				precision->Text = precision->Text->Replace(".", ",");
				eps = Convert::ToDouble(precision->Text);
				integral = DichotomyMethod(a, b, eps, f2);
				result->Text = Convert::ToString(Math::Round(integral, 5));
			}
			else MessageBox::Show("Возможно, не все поля правильно заполнены.\nДобавьте или удалите данные и повторите попыткую.");
		default:
			MessageBox::Show("Возможно, где-то ошибка.\nПроверьте данные и повторите попыткую.");
		}
	}
}
private: System::Void method_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
