#pragma once
#include "Board.h"
#include "Fleet.h"
#include "Team.h"

//遊戲視窗大小
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
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
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
		/// 清除任何使用中的資源。
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
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
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
		//初始化遊戲設定
		void InitializeGame(void)
		{
			this->DoubleBuffered = true;	//開啟雙緩衝防止畫面閃爍

			bitmap = gcnew Bitmap(441, 441);	//初始化bitmap大小
			g = Graphics::FromImage(bitmap);	//初始化畫布
			this->ClientSize = System::Drawing::Size(W, H);	//調整遊戲視窗大小


			//測試隊伍新增船艦
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
					System::Diagnostics::Debug::WriteLine("空的一行");
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
						System::Diagnostics::Debug::WriteLine("指令錯誤");
						break;
					}
				}
				else if (words[0] == "FIRE")
				{
					if (words->Length == 4)
					{
						//有這船艦
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
						System::Diagnostics::Debug::WriteLine("指令錯誤");
						break;
					}
				}
			}

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawImage(bitmap, 50, 100);	//實際畫在視窗上
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		//迭代器讓所有船隻移動
		for each (auto var in team1.fleetList)
		{
			var.Value->Move();
			Random r;
			if (r.Next(20) == 0)
				var.Value->Fire(team1.shellList, gcnew PointF(150, 150));	//測試開砲
		}

		
		for each (Shell^ var in team1.shellList)	//迭代器讓所有砲彈移動
		{
			var->Move();
		}
		team1.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team1.shellList);
		for each (Shell^ var in team1.shellList)	//迭代器讓所有定位砲彈消失(之後要加傷害)
		{
			if (var->getIsBoom())
				team1.bufferShellList->Remove(var);
		}
		team1.shellList = team1.bufferShellList;

		UpdateCanvas();		//更新畫布
		this->Refresh();	//call My_Form Paint
	}

	private: System::Void UpdateCanvas()
	{
		g->Clear(System::Drawing::Color::White);	//先清空畫布

		myBoard.Draw(g);	//重畫地圖
		
		//畫船
		for each (auto var in team1.fleetList)
		{
			var.Value->Draw(g);
		}

		//畫砲
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
