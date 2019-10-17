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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(127, 458);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Debug Info";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::btnDebug_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(223, 458);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"DumpSDK";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::btnDump_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(333, 458);
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
			this->dataGridView1->Size = System::Drawing::Size(399, 408);
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
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(413, 440);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(405, 414);
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
			this->tabPage2->Size = System::Drawing::Size(299, 442);
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
			this->dataGridView2->Size = System::Drawing::Size(293, 436);
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
			this->tabPage3->Size = System::Drawing::Size(299, 442);
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
			this->dataGridView3->Size = System::Drawing::Size(293, 436);
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
			this->tabPage4->Size = System::Drawing::Size(299, 442);
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
			this->dataGridView4->Size = System::Drawing::Size(293, 436);
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
			this->numericUpDown1->Location = System::Drawing::Point(31, 458);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999999, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(75, 20);
			this->numericUpDown1->TabIndex = 6;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(437, 492);
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
			this->ResumeLayout(false);

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
	dataGridView1->Rows->Add(gcnew array<String^>{"Outer", gcnew String(obj.GetOuter().GetName().c_str())});
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
	dataGridView3->Rows->Add(gcnew array<String^>{"Actor", String::Format("{0:x}", GWorld.CurrentLevel().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"Actor Count", GWorld.CurrentLevel().Actors().GetAddress().ToString()});
	dataGridView3->Rows->Add(gcnew array<String^>{"UGameInstance", String::Format("{0:x}", GWorld.OwningGameInstance().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"LocalPlayer", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"APlayerController", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().PlayerController().GetAddress())});
	dataGridView3->Rows->Add(gcnew array<String^>{"LocalPawn", String::Format("{0:x}", GWorld.OwningGameInstance().LocalPlayer().PlayerController().LocalPawn().GetAddress())});
}