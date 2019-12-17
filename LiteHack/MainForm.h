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

	public: System::Windows::Forms::CheckBox^ btnTestFunc;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnDeveloperMode = (gcnew System::Windows::Forms::CheckBox());
			this->btnTestFunc = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 106);
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
			this->btnDeveloperMode->Location = System::Drawing::Point(74, 57);
			this->btnDeveloperMode->Name = L"btnDeveloperMode";
			this->btnDeveloperMode->Size = System::Drawing::Size(73, 17);
			this->btnDeveloperMode->TabIndex = 1;
			this->btnDeveloperMode->Text = L"DevMode";
			this->btnDeveloperMode->UseVisualStyleBackColor = true;
			// 
			// btnTestFunc
			// 
			this->btnTestFunc->AutoSize = true;
			this->btnTestFunc->Location = System::Drawing::Point(177, 57);
			this->btnTestFunc->Name = L"btnTestFunc";
			this->btnTestFunc->Size = System::Drawing::Size(88, 17);
			this->btnTestFunc->TabIndex = 23;
			this->btnTestFunc->Text = L"TestFunction";
			this->btnTestFunc->UseVisualStyleBackColor = true;
			// 
			// MainUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 175);
			this->Controls->Add(this->btnTestFunc);
			this->Controls->Add(this->btnDeveloperMode);
			this->Controls->Add(this->button1);
			this->Name = L"MainUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainUI::MainUI_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainUI::MainUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnToggleHack(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
