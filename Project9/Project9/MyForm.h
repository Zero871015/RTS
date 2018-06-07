#pragma once
#include "Board.h"
#include "Fleet.h"
#include "Team.h"

//�C�������j�p
#define W 1080
#define H 720

namespace Project9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm ���K�n
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
			InitializeGame();
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: Board myBoard;
	private: Bitmap ^ bitmap;
	private: Graphics ^ g;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Collections::Generic::List<Shell^>^ shellList;
	private: System::Collections::Generic::List<Shell^>^ bufferShellList;
	private: Team team1, team2;
	public:

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 17;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(714, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(292, 817);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 24);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 394);
			this->textBox1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 673);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//��l�ƹC���]�w
		void InitializeGame(void)
		{
			this->DoubleBuffered = true;	//�}�����w�Ĩ���e���{�{

			bitmap = gcnew Bitmap(441, 441);	//��l��bitmap�j�p
			g = Graphics::FromImage(bitmap);	//��l�Ƶe��
			this->ClientSize = System::Drawing::Size(W, H);	//�վ�C�������j�p


			//���ն���s�W��ĥ
			team1.fleetList->Add(gcnew Fleet());
			team1.fleetList[0]->setMove(2.0, 270);
			team1.fleetList->Add(gcnew Fleet("Yori", PointF(200, 200)));
			team1.fleetList[1]->setMove(2.0, 150);

			//���կ��u���X
			shellList = gcnew System::Collections::Generic::List<Shell^>;

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawImage(bitmap, 50, 100);	//��ڵe�b�����W
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		//���N�����Ҧ������
		for each (Fleet^ var in team1.fleetList)
		{
			var->Move();
			Random r;
			if (r.Next(20) == 0)
				var->Fire(shellList, gcnew PointF(150, 150));	//���ն}��
		}

		
		for each (Shell^ var in shellList)	//���N�����Ҧ����u����
		{
			var->Move();
		}
		bufferShellList = gcnew System::Collections::Generic::List<Shell^>(shellList);
		for each (Shell^ var in shellList)	//���N�����Ҧ��w�쯥�u����(����n�[�ˮ`)
		{
			if (var->getIsBoom())
				bufferShellList->Remove(var);
		}
		shellList = bufferShellList;

		UpdateCanvas();		//��s�e��
		this->Refresh();	//call My_Form Paint
	}

	private: System::Void UpdateCanvas()
	{
		g->Clear(System::Drawing::Color::White);	//���M�ŵe��

		myBoard.Draw(g);	//���e�a��
		
		//�e��
		for each (Fleet ^ var in team1.fleetList)
		{
			var->Draw(g);
		}

		//�e��
		for each (Shell^ var in shellList)
		{
			var->Draw(g);
		}
	}
	};
}
