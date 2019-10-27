#pragma once
#include "LiteHack/HackManager.h"
#include "GWorld/UWorld.h"
#include "GObjects/Generator.h"
#include <Psapi.h>

// Global Variable:
UWorld GWorld;
HackManager Hack;
Memory GameMemory;
NamesStore GlobalNames;
ObjectsStore GlobalObjects;
uint64 GameBaseAddress = 0;
HANDLE GameProcessHandle = NULL;

namespace LiteHackForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Properties;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Value;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	public: System::Windows::Forms::DataGridView^ dataGridView2;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	public: System::Windows::Forms::DataGridView^ dataGridView3;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::TabPage^ tabPage4;
	public: System::Windows::Forms::DataGridView^ dataGridView4;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox6;




	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::LinkLabel^ linkLabel2;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::LinkLabel^ linkLabel3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox1;


	private:

	public:



	public:



	public:
		Thread^ MainLoopThread;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;



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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Properties = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Value = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(408, 413);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"DebugID";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::btnDebug_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(667, 416);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"DumpSDK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::btnDump_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start Hack";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::BtnToggleHack_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Properties,
					this->Value
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView1->Size = System::Drawing::Size(399, 367);
			this->dataGridView1->TabIndex = 4;
			// 
			// Properties
			// 
			this->Properties->HeaderText = L"Property";
			this->Properties->Name = L"Properties";
			this->Properties->ReadOnly = true;
			this->Properties->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Properties->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Value
			// 
			this->Value->HeaderText = L"Value";
			this->Value->Name = L"Value";
			this->Value->ReadOnly = true;
			this->Value->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Value->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(336, 11);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(413, 399);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(405, 373);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"UObject";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(405, 373);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"GNames";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->Location = System::Drawing::Point(3, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView2->Size = System::Drawing::Size(399, 367);
			this->dataGridView2->TabIndex = 5;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Property";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Value";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(405, 373);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"GWorld";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->AllowUserToAddRows = false;
			this->dataGridView3->AllowUserToDeleteRows = false;
			this->dataGridView3->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView3->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn3,
					this->dataGridViewTextBoxColumn4
			});
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(3, 3);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->ReadOnly = true;
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView3->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView3->Size = System::Drawing::Size(399, 367);
			this->dataGridView3->TabIndex = 5;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Property";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			this->dataGridViewTextBoxColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Value";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->ReadOnly = true;
			this->dataGridViewTextBoxColumn4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->dataGridView4);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(405, 373);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"STExtraPlayer";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// dataGridView4
			// 
			this->dataGridView4->AllowUserToAddRows = false;
			this->dataGridView4->AllowUserToDeleteRows = false;
			this->dataGridView4->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView4->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6
			});
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView4->Location = System::Drawing::Point(3, 3);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->ReadOnly = true;
			this->dataGridView4->RowHeadersVisible = false;
			this->dataGridView4->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView4->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView4->Size = System::Drawing::Size(399, 367);
			this->dataGridView4->TabIndex = 6;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Property";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->ReadOnly = true;
			this->dataGridViewTextBoxColumn5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Value";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->ReadOnly = true;
			this->dataGridViewTextBoxColumn6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTextBoxColumn6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(351, 416);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999999, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(51, 20);
			this->numericUpDown1->TabIndex = 6;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(5, 6);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(79, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"EnemyESP";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(20, 34);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(68, 17);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"Skeleton";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Checked = true;
			this->checkBox3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox3->Location = System::Drawing::Point(94, 34);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(44, 17);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"Box";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Checked = true;
			this->checkBox4->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox4->Location = System::Drawing::Point(164, 34);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(57, 17);
			this->checkBox4->TabIndex = 10;
			this->checkBox4->Text = L"Health";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Location = System::Drawing::Point(237, 34);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(46, 17);
			this->checkBox5->TabIndex = 11;
			this->checkBox5->Text = L"Line";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Checked = true;
			this->checkBox6->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox6->Location = System::Drawing::Point(5, 183);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(58, 17);
			this->checkBox6->TabIndex = 12;
			this->checkBox6->Text = L"Aimbot";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox6_CheckedChanged);
			this->checkBox6->EnabledChanged += gcnew System::EventHandler(this, &MainForm::CheckBox6_EnabledChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(15, 21);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(51, 17);
			this->radioButton1->TabIndex = 17;
			this->radioButton1->Text = L"Head";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(89, 21);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(53, 17);
			this->radioButton2->TabIndex = 18;
			this->radioButton2->Text = L"Pelvis";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(159, 21);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(51, 17);
			this->radioButton3->TabIndex = 19;
			this->radioButton3->Text = L"Neck";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButton3_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Checked = true;
			this->radioButton4->Location = System::Drawing::Point(232, 21);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(49, 17);
			this->radioButton4->TabIndex = 20;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Body";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::RadioButton4_CheckedChanged);
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 50;
			this->trackBar1->Location = System::Drawing::Point(120, 68);
			this->trackBar1->Maximum = 500;
			this->trackBar1->Minimum = 50;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(101, 45);
			this->trackBar1->SmallChange = 50;
			this->trackBar1->TabIndex = 21;
			this->trackBar1->TickFrequency = 50;
			this->trackBar1->Value = 300;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::TrackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"Skeleton Distance:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(234, 68);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"300 (m)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(229, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 26;
			this->label3->Text = L"5 (steps)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Aimbot Speed:";
			// 
			// trackBar2
			// 
			this->trackBar2->LargeChange = 1;
			this->trackBar2->Location = System::Drawing::Point(122, 59);
			this->trackBar2->Minimum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(101, 45);
			this->trackBar2->TabIndex = 24;
			this->trackBar2->TickFrequency = 50;
			this->trackBar2->Value = 5;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MainForm::TrackBar2_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->linkLabel3);
			this->groupBox1->Controls->Add(this->linkLabel2);
			this->groupBox1->Controls->Add(this->linkLabel1);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->trackBar1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(14, 29);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(297, 148);
			this->groupBox1->TabIndex = 27;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Options";
			// 
			// linkLabel3
			// 
			this->linkLabel3->ActiveLinkColor = System::Drawing::Color::Yellow;
			this->linkLabel3->AutoSize = true;
			this->linkLabel3->LinkColor = System::Drawing::Color::Red;
			this->linkLabel3->Location = System::Drawing::Point(198, 109);
			this->linkLabel3->Name = L"linkLabel3";
			this->linkLabel3->Size = System::Drawing::Size(64, 13);
			this->linkLabel3->TabIndex = 26;
			this->linkLabel3->TabStop = true;
			this->linkLabel3->Text = L"Visible Color";
			this->linkLabel3->VisitedLinkColor = System::Drawing::Color::Red;
			this->linkLabel3->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::LinkLabel3_LinkClicked);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->LinkColor = System::Drawing::Color::DodgerBlue;
			this->linkLabel2->Location = System::Drawing::Point(117, 109);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(50, 13);
			this->linkLabel2->TabIndex = 25;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"Bot Color";
			this->linkLabel2->VisitedLinkColor = System::Drawing::Color::DodgerBlue;
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::LinkLabel2_LinkClicked);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->linkLabel1->Location = System::Drawing::Point(17, 109);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(68, 13);
			this->linkLabel1->TabIndex = 24;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Human Color";
			this->linkLabel1->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::LinkLabel1_LinkClicked);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->trackBar3);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->radioButton3);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->radioButton4);
			this->groupBox2->Controls->Add(this->trackBar2);
			this->groupBox2->Location = System::Drawing::Point(14, 206);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(297, 142);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Options";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(229, 98);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(60, 13);
			this->label5->TabIndex = 29;
			this->label5->Text = L"250 (pixels)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 98);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 13);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Aimbot Radius:";
			// 
			// trackBar3
			// 
			this->trackBar3->LargeChange = 1;
			this->trackBar3->Location = System::Drawing::Point(120, 98);
			this->trackBar3->Maximum = 600;
			this->trackBar3->Minimum = 50;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(101, 45);
			this->trackBar3->TabIndex = 27;
			this->trackBar3->TickFrequency = 50;
			this->trackBar3->Value = 250;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &MainForm::TrackBar3_Scroll);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->checkBox8);
			this->panel1->Controls->Add(this->checkBox7);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->checkBox6);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Enabled = false;
			this->panel1->Location = System::Drawing::Point(3, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(327, 392);
			this->panel1->TabIndex = 28;
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Location = System::Drawing::Point(82, 354);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(94, 17);
			this->checkBox8->TabIndex = 28;
			this->checkBox8->Text = L"Predict Aimbot";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox8_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Checked = true;
			this->checkBox7->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox7->Location = System::Drawing::Point(5, 354);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(71, 17);
			this->checkBox7->TabIndex = 26;
			this->checkBox7->Text = L"Auto FPS";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CheckBox7_CheckedChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(239, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Test Mode";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::Button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(595, 416);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(66, 23);
			this->button5->TabIndex = 30;
			this->button5->Text = L"DebugAddress";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::Button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(489, 416);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 31;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 446);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LiteHack";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabPage4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDebug_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnDump_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BtnToggleHack_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);


	private:System::Void DebugUObjectByAddress(uint64 address);

	private:System::Void DebugUObjectByID(int index);

	private:System::Void DebugGNamesByID(int index);

	private:System::Void DebugGWorld();

	private:System::Void DebugPlayer();

private: System::Void CheckBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	groupBox1->Enabled = checkBox1->Checked;
	groupBox2->Enabled = checkBox1->Checked;
	checkBox6->Enabled = checkBox1->Checked;
	Hack.options.Enemy = checkBox1->Checked;
}
private: System::Void CheckBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.Skeleton = checkBox2->Checked;
}
private: System::Void CheckBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.Box = checkBox3->Checked;
}
private: System::Void CheckBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.Health = checkBox4->Checked;
}
private: System::Void CheckBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.Line = checkBox5->Checked;
}
private: System::Void CheckBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	groupBox2->Enabled = checkBox6->Checked;
	Hack.options.Aimbot = checkBox6->Checked;

}
private: System::Void RadioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton1->Checked)
	{
		Hack.options.aimpos = AimbotPos::Head;
	}
}
private: System::Void RadioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton2->Checked){
		Hack.options.aimpos = AimbotPos::Pelvis;
	}
}
private: System::Void RadioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton3->Checked) {
		Hack.options.aimpos = AimbotPos::Neck;
	}
}
private: System::Void RadioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton4->Checked) {
		Hack.options.aimpos = AimbotPos::Body;
	}
}
private: System::Void CheckBox6_EnabledChanged(System::Object^ sender, System::EventArgs^ e) {
	groupBox2->Enabled = checkBox6->Enabled;
}
private: System::Void TrackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.maxSkeletonDistance = trackBar1->Value;
	label2->Text = String::Format("{0:G} (m)", trackBar1->Value);
}
private: System::Void TrackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.aimbotSpeed = trackBar2->Value;
	label3->Text = String::Format("{0:G} (steps)", trackBar2->Value);
}
private: System::Void TrackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.aimbotRadius = trackBar3->Value;
	label5->Text= String::Format("{0:G} (pixels)", trackBar3->Value);
}
private: System::Void LinkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	ColorDialog^ dialog = gcnew ColorDialog();
	auto result = dialog->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK)
	{
		linkLabel1->VisitedLinkColor = dialog->Color;
		linkLabel1->LinkColor = dialog->Color;
		Hack.options.HumanColor = FColor(dialog->Color.R, dialog->Color.G, dialog->Color.B);
	}
}
private: System::Void LinkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	ColorDialog^ dialog = gcnew ColorDialog();
	auto result = dialog->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK)
	{
		linkLabel2->VisitedLinkColor = dialog->Color;
		linkLabel2->LinkColor = dialog->Color;
		Hack.options.BotColor = FColor(dialog->Color.R, dialog->Color.G, dialog->Color.B);
	}
}
private: System::Void CheckBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.autoFPS = checkBox7->Checked;
}
private: System::Void LinkLabel3_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	ColorDialog^ dialog = gcnew ColorDialog();
	auto result = dialog->ShowDialog();
	if (result == Windows::Forms::DialogResult::OK)
	{
		linkLabel3->VisitedLinkColor = dialog->Color;
		linkLabel3->LinkColor = dialog->Color;
		Hack.options.BotColor = FColor(dialog->Color.R, dialog->Color.G, dialog->Color.B);
	}
}
private: System::Void Button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Width = this->Width == 770 ? 350: 770;
}
private: System::Void CheckBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	Hack.options.predictaimbot = checkBox8->Checked;
}
private: System::Void Button5_Click(System::Object^ sender, System::EventArgs^ e);
};
}
void LiteHackForm::MainForm::DebugUObjectByID(int id)
{
	dataGridView1->Rows->Clear();
	UEObject obj = GlobalObjects.GetById(id);
	dataGridView1->Rows->Add(gcnew array<String^>{"Address", String::Format("{0:x}", obj.GetAddress())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Internal Index", obj.GetIndex().ToString()});
	dataGridView1->Rows->Add(gcnew array<String^>{"Name", gcnew String(obj.GetName().c_str())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Class", gcnew String(obj.GetClass().GetName().c_str())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Class Address", String::Format("{0:x}", obj.GetClass().GetAddress())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Outer", gcnew String(obj.GetOuter().GetName().c_str())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Outer Address", String::Format("{0:x}", obj.GetOuter().GetAddress())});
}

void LiteHackForm::MainForm::DebugGNamesByID(int id)
{
	dataGridView2->Rows->Clear();
	dataGridView2->Rows->Add(gcnew array<String^>{"GName Address", String::Format("{0:x}", GlobalNames.GetAddress())});
	dataGridView2->Rows->Add(gcnew array<String^>{"Index", id.ToString()});
	dataGridView2->Rows->Add(gcnew array<String^>{"Name", gcnew String(GlobalNames.GetById(id).c_str())});
}

void LiteHackForm::MainForm::DebugUObjectByAddress(uint64 address)
{
	dataGridView1->Rows->Clear();
	UEObject obj = UEObject(address);
	dataGridView1->Rows->Add(gcnew array<String^>{"Address", String::Format("{0:x}", obj.GetAddress())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Internal Index", obj.GetIndex().ToString()});
	dataGridView1->Rows->Add(gcnew array<String^>{"Name", gcnew String(obj.GetName().c_str())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Class", gcnew String(obj.GetClass().GetName().c_str())});
	dataGridView1->Rows->Add(gcnew array<String^>{"Outer", gcnew String(obj.GetOuter().GetName().c_str())});
}

void LiteHackForm::MainForm::DebugGWorld()
{
	dataGridView3->Rows->Clear();
	dataGridView3->Rows->Add(gcnew array<String^>{"ULevel", String::Format("{0:x}", GWorld.CurrentLevel().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"Actor", String::Format("{0:x}", GWorld.CurrentLevel().Actors().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"Actor Count", GWorld.CurrentLevel().Actors().Length().ToString()});
	dataGridView3->Rows->Add(gcnew array<String^>{"UGameInstance", String::Format("{0:x}", GWorld.OwningGameInstance().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"LocalPlayer", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"APlayerController", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().PlayerController().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"LocalPawn", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().GetAddress())});
}

void LiteHackForm::MainForm::DebugPlayer()
{
	auto player = GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn();
	dataGridView4->Rows->Clear();
	dataGridView4->Rows->Add(gcnew array<String^>{"APawn", String::Format("{0:x}", player.GetAddress())});
	dataGridView4->Rows->Add(gcnew array<String^>{"Health", player.Health().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"TeamID", player.TeamID().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"PlayerName", gcnew String(player.PlayerName().ToString().c_str())});
	dataGridView4->Rows->Add(gcnew array<String^>{"Mesh", String::Format("{0:x}", player.Mesh().GetAddress())});
	dataGridView4->Rows->Add(gcnew array<String^>{"RootComponent", String::Format("{0:x}", player.RootComponent().GetAddress())});
	dataGridView4->Rows->Add(gcnew array<String^>{"WeaponManagerComponent", String::Format("{0:x}", player.WeaponManagerComponent().GetAddress())});

	dataGridView4->Rows->Add(gcnew array<String^>{"RootComponent: ", ""});
	dataGridView4->Rows->Add(gcnew array<String^>{"Location", player.RootComponent().Location().X.ToString() + "," + player.RootComponent().Location().Y.ToString() + "," + player.RootComponent().Location().Z.ToString() });
	dataGridView4->Rows->Add(gcnew array<String^>{"Velocity", player.RootComponent().ComponentVelocity().X.ToString() + "," + player.RootComponent().ComponentVelocity().Y.ToString() + "," + player.RootComponent().ComponentVelocity().Z.ToString() });
	dataGridView4->Rows->Add(gcnew array<String^>{"Visible", player.RootComponent().Visible().ToString()});

	dataGridView4->Rows->Add(gcnew array<String^>{"CurrentWeapon: ", ""});
	dataGridView4->Rows->Add(gcnew array<String^>{"CurrentWeapon", String::Format("{0:x}", player.WeaponManagerComponent().CurrentWeapon().GetAddress())});
	dataGridView4->Rows->Add(gcnew array<String^>{"WeaponAvatarID", player.WeaponManagerComponent().CurrentWeapon().WeaponAvatarID().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"CurBulletNumInClip", player.WeaponManagerComponent().CurrentWeapon().CurBulletNumInClip().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"CurMaxBulletNumInOneClip", player.WeaponManagerComponent().CurrentWeapon().CurMaxBulletNumInOneClip().ToString()});

	dataGridView4->Rows->Add(gcnew array<String^>{"WeaponEntityComp: ", ""});
	//dataGridView4->Rows->Add(gcnew array<String^>{"FireMode", player.WeaponManagerComponent().CurrentWeapon().FireMode()});
	dataGridView4->Rows->Add(gcnew array<String^>{"WeaponID", player.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().WeaponID().ToString()});
	//dataGridView4->Rows->Add(gcnew array<String^>{"WeaponType", player.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().WeaponType().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"BulletFireSpeed", player.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().BulletFireSpeed().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"HasAutoFireMode", player.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().HasAutoFireMode().ToString()});
	dataGridView4->Rows->Add(gcnew array<String^>{"BulletNumSingleShot", player.WeaponManagerComponent().CurrentWeapon().WeaponEntityComp().BulletNumSingleShot().ToString()});
}

