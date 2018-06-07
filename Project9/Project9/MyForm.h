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
	private: Team team1, team2;
	private: System::Windows::Forms::Button^  BtnStart;
	private: System::Windows::Forms::Button^  BtnPause;
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
			this->BtnStart = (gcnew System::Windows::Forms::Button());
			this->BtnPause = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
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
			// BtnStart
			// 
			this->BtnStart->Location = System::Drawing::Point(453, 806);
			this->BtnStart->Name = L"BtnStart";
			this->BtnStart->Size = System::Drawing::Size(75, 23);
			this->BtnStart->TabIndex = 1;
			this->BtnStart->Text = L"Start";
			this->BtnStart->UseVisualStyleBackColor = true;
			this->BtnStart->Click += gcnew System::EventHandler(this, &MyForm::BtnStart_Click);
			// 
			// BtnPause
			// 
			this->BtnPause->Enabled = false;
			this->BtnPause->Location = System::Drawing::Point(563, 806);
			this->BtnPause->Name = L"BtnPause";
			this->BtnPause->Size = System::Drawing::Size(75, 23);
			this->BtnPause->TabIndex = 2;
			this->BtnPause->Text = L"Pause";
			this->BtnPause->UseVisualStyleBackColor = true;
			this->BtnPause->Click += gcnew System::EventHandler(this, &MyForm::BtnPause_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 1041);
			this->Controls->Add(this->BtnPause);
			this->Controls->Add(this->BtnStart);
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
			team1.fleetList->Add("GG",gcnew Fleet());
			team1.fleetList["GG"]->setMove(2.0, 270);
			team1.fleetList->Add("DAGG",gcnew Fleet("DAGG", PointF(15, 15)));
			team1.fleetList["DAGG"]->setMove(2.0, 150);

		}
		void ReadCommand()
		{
			System::Collections::Generic::List<System::String ^> lines;
			System::String ^ temp="";

			for (auto i = 0; i < textBox1->Text->Length; i++)
			{
				if (textBox1->Text[i] == '\r')
				{
					lines.Add(temp);
					temp = "";
					i++;
				}
				else if (i == textBox1->Text->Length - 1)
				{
					temp += textBox1->Text[i];
					lines.Add(temp);
					temp = "";
				}
				else
				{
					temp += textBox1->Text[i];
				}
			}

			for each (System::String ^ var in lines)
			{
				array<System::String ^>^ words;
				words=var->Split(' ',',');
				if (words->Length == 0)
				{
					System::Diagnostics::Debug::WriteLine("�Ū��@��");
					break;
				}
				if (words[0] == "SET")
				{
					if (words->Length == 5)
					{
						words[3]=words[3]->Remove(0,1);
						words[4]=words[4]->Remove(words[4]->Length - 1,1);
						team1.fleetList->Add(words[1],gcnew Fleet(words[1],
							gcnew PointF(float::Parse(words[3]),
								float::Parse(words[4]))));
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("���O���~");
						break;
					}
				}
				else if (words[0] == "FIRE")
				{
					if (words->Length == 4)
					{
						//���o��ĥ
						if (team1.fleetList->ContainsKey(words[1]))
						{
							words[2]=words[2]->Remove(0,1);
							words[3]=words[3]->Remove(words[3]->Length - 1,1);

							team1.shellList->Add(gcnew Shell("Sheel_A" + team1.count.ToString(),
								team1.fleetList[words[1]]->getSheelSpeed(),
								team1.fleetList[words[1]]->getLocation(),
								gcnew PointF(float::Parse(words[2]), float::Parse(words[3]))));
							team1.count++;
						}
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("���O���~");
						break;
					}
				}
			}

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawImage(bitmap, 50, 100);	//��ڵe�b�����W
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		//���N�����Ҧ������
		for each (auto var in team1.fleetList)
		{
			var.Value->Move();
			Random r;
			if (r.Next(20) == 0)
				var.Value->Fire(team1.shellList, gcnew PointF(150, 150));	//���ն}��
		}

		
		for each (Shell^ var in team1.shellList)	//���N�����Ҧ����u����
		{
			var->Move();
		}
		team1.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team1.shellList);
		for each (Shell^ var in team1.shellList)	//���N�����Ҧ��w�쯥�u����(����n�[�ˮ`)
		{
			if (var->getIsBoom())
				team1.bufferShellList->Remove(var);
		}
		team1.shellList = team1.bufferShellList;

		UpdateCanvas();		//��s�e��
		this->Refresh();	//call My_Form Paint
	}

	private: System::Void UpdateCanvas()
	{
		g->Clear(System::Drawing::Color::White);	//���M�ŵe��

		myBoard.Draw(g);	//���e�a��
		
		//�e��
		for each (auto var in team1.fleetList)
		{
			var.Value->Draw(g);
		}

		//�e��
		for each (Shell^ var in team1.shellList)
		{
			var->Draw(g);
		}
	}
	private: System::Void BtnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		ReadCommand();

		timer1->Enabled = true;
		BtnPause->Enabled = true;
		BtnStart->Enabled = false;
		textBox1->ReadOnly = true;
	}
	private: System::Void BtnPause_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		BtnStart->Enabled = true;
		BtnPause->Enabled = false;
		textBox1->ReadOnly = false;
	}
};
}
