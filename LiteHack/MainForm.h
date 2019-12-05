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
	public: System::Windows::Forms::CheckBox^ switchAimbot;

	public: System::Windows::Forms::NumericUpDown^ aimSpeed;

	public: System::Windows::Forms::TrackBar^ aimRadius;
	public: System::Windows::Forms::CheckBox^ switchNoRecoil;






	public: System::Windows::Forms::CheckBox^ switchEnemyESP;
	private:

	public: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::TrackBar^ maxBoneDis;
	public: System::Windows::Forms::CheckBox^ switchBone;








	public: System::Windows::Forms::GroupBox^ groupBox2;
	public: System::Windows::Forms::CheckBox^ noanimkick;


	public: System::Windows::Forms::CheckBox^ norecoil;
	public: System::Windows::Forms::CheckBox^ nosway;



	public: System::Windows::Forms::CheckBox^ nospread;

	private:





	public: System::Windows::Forms::GroupBox^ groupBox3;
	private:


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public: System::Windows::Forms::NumericUpDown^ aimPart;
	private: System::Windows::Forms::Button^ btnUpdateOptions;
	private: System::Windows::Forms::Label^ visColor;
	private: System::Windows::Forms::Label^ botColor;
	private: System::Windows::Forms::Label^ humColor;
	public: System::Windows::Forms::NumericUpDown^ secondAimPart;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	public:
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private:

	private:
	public:

	public:
	private:



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
			this->switchAimbot = (gcnew System::Windows::Forms::CheckBox());
			this->aimSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->aimRadius = (gcnew System::Windows::Forms::TrackBar());
			this->switchNoRecoil = (gcnew System::Windows::Forms::CheckBox());
			this->switchEnemyESP = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->visColor = (gcnew System::Windows::Forms::Label());
			this->botColor = (gcnew System::Windows::Forms::Label());
			this->humColor = (gcnew System::Windows::Forms::Label());
			this->maxBoneDis = (gcnew System::Windows::Forms::TrackBar());
			this->switchBone = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->secondAimPart = (gcnew System::Windows::Forms::NumericUpDown());
			this->aimPart = (gcnew System::Windows::Forms::NumericUpDown());
			this->noanimkick = (gcnew System::Windows::Forms::CheckBox());
			this->norecoil = (gcnew System::Windows::Forms::CheckBox());
			this->nosway = (gcnew System::Windows::Forms::CheckBox());
			this->nospread = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnUpdateOptions = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimRadius))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxBoneDis))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secondAimPart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimPart))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(622, 303);
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
			this->btnDeveloperMode->Location = System::Drawing::Point(611, 280);
			this->btnDeveloperMode->Name = L"btnDeveloperMode";
			this->btnDeveloperMode->Size = System::Drawing::Size(73, 17);
			this->btnDeveloperMode->TabIndex = 1;
			this->btnDeveloperMode->Text = L"DevMode";
			this->btnDeveloperMode->UseVisualStyleBackColor = true;
			// 
			// switchAimbot
			// 
			this->switchAimbot->AutoSize = true;
			this->switchAimbot->Checked = true;
			this->switchAimbot->CheckState = System::Windows::Forms::CheckState::Checked;
			this->switchAimbot->Location = System::Drawing::Point(290, 43);
			this->switchAimbot->Name = L"switchAimbot";
			this->switchAimbot->Size = System::Drawing::Size(15, 14);
			this->switchAimbot->TabIndex = 5;
			this->switchAimbot->UseVisualStyleBackColor = true;
			this->switchAimbot->CheckedChanged += gcnew System::EventHandler(this, &MainUI::switchAimbot_CheckedChanged);
			// 
			// aimSpeed
			// 
			this->aimSpeed->Location = System::Drawing::Point(22, 25);
			this->aimSpeed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->aimSpeed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->aimSpeed->Name = L"aimSpeed";
			this->aimSpeed->Size = System::Drawing::Size(120, 20);
			this->aimSpeed->TabIndex = 7;
			this->aimSpeed->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// aimRadius
			// 
			this->aimRadius->LargeChange = 100;
			this->aimRadius->Location = System::Drawing::Point(22, 63);
			this->aimRadius->Maximum = 600;
			this->aimRadius->Minimum = 100;
			this->aimRadius->Name = L"aimRadius";
			this->aimRadius->Size = System::Drawing::Size(133, 45);
			this->aimRadius->SmallChange = 50;
			this->aimRadius->TabIndex = 8;
			this->aimRadius->TickFrequency = 50;
			this->aimRadius->Value = 400;
			// 
			// switchNoRecoil
			// 
			this->switchNoRecoil->AutoSize = true;
			this->switchNoRecoil->Checked = true;
			this->switchNoRecoil->CheckState = System::Windows::Forms::CheckState::Checked;
			this->switchNoRecoil->Location = System::Drawing::Point(572, 43);
			this->switchNoRecoil->Name = L"switchNoRecoil";
			this->switchNoRecoil->Size = System::Drawing::Size(15, 14);
			this->switchNoRecoil->TabIndex = 9;
			this->switchNoRecoil->UseVisualStyleBackColor = true;
			this->switchNoRecoil->CheckedChanged += gcnew System::EventHandler(this, &MainUI::switchNoRecoil_CheckedChanged);
			// 
			// switchEnemyESP
			// 
			this->switchEnemyESP->AutoSize = true;
			this->switchEnemyESP->Checked = true;
			this->switchEnemyESP->CheckState = System::Windows::Forms::CheckState::Checked;
			this->switchEnemyESP->Location = System::Drawing::Point(36, 43);
			this->switchEnemyESP->Name = L"switchEnemyESP";
			this->switchEnemyESP->Size = System::Drawing::Size(15, 14);
			this->switchEnemyESP->TabIndex = 11;
			this->switchEnemyESP->UseVisualStyleBackColor = true;
			this->switchEnemyESP->CheckedChanged += gcnew System::EventHandler(this, &MainUI::switchEnemyESP_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->visColor);
			this->groupBox1->Controls->Add(this->botColor);
			this->groupBox1->Controls->Add(this->humColor);
			this->groupBox1->Controls->Add(this->maxBoneDis);
			this->groupBox1->Controls->Add(this->switchBone);
			this->groupBox1->Location = System::Drawing::Point(57, 43);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 175);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Enemy ESP";
			// 
			// visColor
			// 
			this->visColor->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->visColor->Location = System::Drawing::Point(128, 113);
			this->visColor->Name = L"visColor";
			this->visColor->Size = System::Drawing::Size(50, 25);
			this->visColor->TabIndex = 9;
			// 
			// botColor
			// 
			this->botColor->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->botColor->Location = System::Drawing::Point(72, 113);
			this->botColor->Name = L"botColor";
			this->botColor->Size = System::Drawing::Size(50, 25);
			this->botColor->TabIndex = 8;
			// 
			// humColor
			// 
			this->humColor->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->humColor->Location = System::Drawing::Point(16, 113);
			this->humColor->Name = L"humColor";
			this->humColor->Size = System::Drawing::Size(50, 25);
			this->humColor->TabIndex = 7;
			// 
			// maxBoneDis
			// 
			this->maxBoneDis->Location = System::Drawing::Point(33, 26);
			this->maxBoneDis->Maximum = 200;
			this->maxBoneDis->Minimum = 10;
			this->maxBoneDis->Name = L"maxBoneDis";
			this->maxBoneDis->Size = System::Drawing::Size(133, 45);
			this->maxBoneDis->TabIndex = 3;
			this->maxBoneDis->TickFrequency = 10;
			this->maxBoneDis->Value = 75;
			// 
			// switchBone
			// 
			this->switchBone->AutoSize = true;
			this->switchBone->Checked = true;
			this->switchBone->CheckState = System::Windows::Forms::CheckState::Checked;
			this->switchBone->Location = System::Drawing::Point(33, 77);
			this->switchBone->Name = L"switchBone";
			this->switchBone->Size = System::Drawing::Size(68, 17);
			this->switchBone->TabIndex = 6;
			this->switchBone->Text = L"Skeleton";
			this->switchBone->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->secondAimPart);
			this->groupBox2->Controls->Add(this->aimPart);
			this->groupBox2->Controls->Add(this->aimSpeed);
			this->groupBox2->Controls->Add(this->aimRadius);
			this->groupBox2->Location = System::Drawing::Point(311, 43);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(189, 175);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Aimbot";
			// 
			// secondAimPart
			// 
			this->secondAimPart->Location = System::Drawing::Point(94, 113);
			this->secondAimPart->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->secondAimPart->Name = L"secondAimPart";
			this->secondAimPart->Size = System::Drawing::Size(61, 20);
			this->secondAimPart->TabIndex = 10;
			this->secondAimPart->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			// 
			// aimPart
			// 
			this->aimPart->Location = System::Drawing::Point(22, 114);
			this->aimPart->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->aimPart->Name = L"aimPart";
			this->aimPart->Size = System::Drawing::Size(61, 20);
			this->aimPart->TabIndex = 9;
			this->aimPart->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// noanimkick
			// 
			this->noanimkick->AutoSize = true;
			this->noanimkick->Checked = true;
			this->noanimkick->CheckState = System::Windows::Forms::CheckState::Checked;
			this->noanimkick->Location = System::Drawing::Point(16, 68);
			this->noanimkick->Name = L"noanimkick";
			this->noanimkick->Size = System::Drawing::Size(88, 17);
			this->noanimkick->TabIndex = 14;
			this->noanimkick->Text = L"No anim kick";
			this->noanimkick->UseVisualStyleBackColor = true;
			// 
			// norecoil
			// 
			this->norecoil->AutoSize = true;
			this->norecoil->Checked = true;
			this->norecoil->CheckState = System::Windows::Forms::CheckState::Checked;
			this->norecoil->Location = System::Drawing::Point(16, 45);
			this->norecoil->Name = L"norecoil";
			this->norecoil->Size = System::Drawing::Size(68, 17);
			this->norecoil->TabIndex = 15;
			this->norecoil->Text = L"No recoil";
			this->norecoil->UseVisualStyleBackColor = true;
			// 
			// nosway
			// 
			this->nosway->AutoSize = true;
			this->nosway->Checked = true;
			this->nosway->CheckState = System::Windows::Forms::CheckState::Checked;
			this->nosway->Location = System::Drawing::Point(16, 114);
			this->nosway->Name = L"nosway";
			this->nosway->Size = System::Drawing::Size(67, 17);
			this->nosway->TabIndex = 16;
			this->nosway->Text = L"No sway";
			this->nosway->UseVisualStyleBackColor = true;
			// 
			// nospread
			// 
			this->nospread->AutoSize = true;
			this->nospread->Checked = true;
			this->nospread->CheckState = System::Windows::Forms::CheckState::Checked;
			this->nospread->Location = System::Drawing::Point(16, 91);
			this->nospread->Name = L"nospread";
			this->nospread->Size = System::Drawing::Size(75, 17);
			this->nospread->TabIndex = 17;
			this->nospread->Text = L"No spread";
			this->nospread->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->norecoil);
			this->groupBox3->Controls->Add(this->nospread);
			this->groupBox3->Controls->Add(this->noanimkick);
			this->groupBox3->Controls->Add(this->nosway);
			this->groupBox3->Location = System::Drawing::Point(593, 43);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(147, 154);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"No Recoil";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(61, 226);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(97, 75);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// btnUpdateOptions
			// 
			this->btnUpdateOptions->Location = System::Drawing::Point(609, 226);
			this->btnUpdateOptions->Name = L"btnUpdateOptions";
			this->btnUpdateOptions->Size = System::Drawing::Size(100, 23);
			this->btnUpdateOptions->TabIndex = 20;
			this->btnUpdateOptions->Text = L"Apply Changes";
			this->btnUpdateOptions->UseVisualStyleBackColor = true;
			this->btnUpdateOptions->Click += gcnew System::EventHandler(this, &MainUI::btnUpdateOptions_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(446, 303);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(141, 17);
			this->radioButton1->TabIndex = 21;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Hijack Notepad Window";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(446, 326);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(136, 17);
			this->radioButton2->TabIndex = 22;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Create Custom Window";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// MainUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 377);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->btnUpdateOptions);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->switchEnemyESP);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->switchAimbot);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->switchNoRecoil);
			this->Controls->Add(this->btnDeveloperMode);
			this->Controls->Add(this->button1);
			this->Name = L"MainUI";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainUI::MainUI_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainUI::MainUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimRadius))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->maxBoneDis))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secondAimPart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->aimPart))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainUI_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnToggleHack(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainUI_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void btnUpdateOptions_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void switchEnemyESP_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void switchNoRecoil_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void switchAimbot_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
