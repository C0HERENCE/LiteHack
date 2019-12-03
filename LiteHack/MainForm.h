#pragma once

namespace LiteHack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainUI : public System::Windows::Forms::Form
	{
	public:
		MainUI(void)
		{
			Application::EnableVisualStyles();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::CheckBox^ btnDeveloperMode;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	public:
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;

	public:
	private:


	protected:

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
			this->btnDeveloperMode = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(235, 563);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start Hack";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainUI::btnToggleHack);
			// 
			// btnDeveloperMode
			// 
			this->btnDeveloperMode->AutoSize = true;
			this->btnDeveloperMode->Location = System::Drawing::Point(363, 567);
			this->btnDeveloperMode->Name = L"btnDeveloperMode";
			this->btnDeveloperMode->Size = System::Drawing::Size(73, 17);
			this->btnDeveloperMode->TabIndex = 1;
			this->btnDeveloperMode->Text = L"DevMode";
			this->btnDeveloperMode->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(79, 97);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(80, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(79, 167);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(256, 45);
			this->trackBar1->TabIndex = 3;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(79, 218);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(422, 310);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(414, 284);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"tabPage1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(414, 230);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"tabPage2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// MainUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 619);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->btnDeveloperMode);
			this->Controls->Add(this->button1);
			this->Name = L"MainUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainUI::MainUI_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainUI::MainUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnToggleHack(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	};
}
