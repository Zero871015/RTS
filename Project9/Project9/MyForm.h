#pragma once
#include <cmath>
#include "Board.h"
#include "Fleet.h"
#include "Team.h"
#include "BB.h"
#include "CarrierVessel.h"
#include "Destroyer.h"
#include "FlyingMissileCruiser.h"

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
	private: System::Windows::Forms::TextBox^  textBox2;
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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->BtnStart = (gcnew System::Windows::Forms::Button());
			this->BtnPause = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 67;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(714, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(292, 834);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Command Box";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox2->Location = System::Drawing::Point(6, 424);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(280, 394);
			this->textBox2->TabIndex = 1;
			this->textBox2->Tag = L"B";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(6, 24);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(280, 394);
			this->textBox1->TabIndex = 0;
			this->textBox1->Tag = L"A";
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

		void ReadCommand(System::Windows::Forms::TextBox ^ textBox,Team ^ team)
		{
			System::Collections::Generic::List<System::String ^> lines;
			System::String ^ temp="";

			for (auto i = 0; i < textBox->Text->Length; i++)
			{
				if (textBox->Text[i] == '\r')
				{
					lines.Add(temp);
					temp = "";
					i++;
				}
				else if (i == textBox->Text->Length - 1)
				{
					temp += textBox->Text[i];
					lines.Add(temp);
					temp = "";
				}
				else
				{
					temp += textBox->Text[i];
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
						if (words[2] == "CV")
						{
							team->fleetList->Add(words[1], gcnew CarrierVessel(words[1],
								gcnew PointF(float::Parse(words[3]),
									float::Parse(words[4]))));
						}
						else if (words[2] == "BB")
						{
							team->fleetList->Add(words[1], gcnew BB(words[1],
								gcnew PointF(float::Parse(words[3]),
									float::Parse(words[4]))));
						}
						else if (words[2] == "CG")
						{
							team->fleetList->Add(words[1], gcnew FlyingMissileCruiser(words[1],
								gcnew PointF(float::Parse(words[3]),
									float::Parse(words[4]))));
						}
						else if (words[2] == "DD")
						{
							team->fleetList->Add(words[1], gcnew Destroyer(words[1],
								gcnew PointF(float::Parse(words[3]),
									float::Parse(words[4]))));
						}
						else
						{
							System::Diagnostics::Debug::WriteLine("沒有這種船艦");
							break;
						}
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
						if (team->fleetList->ContainsKey(words[1]))
						{
							words[2]=words[2]->Remove(0,1);
							words[3]=words[3]->Remove(words[3]->Length - 1,1);
							
							team->fleetList[words[1]]->Fire(team->shellList,
								"Sheel" + textBox->Tag + team->count,
								gcnew PointF(float::Parse(words[2]), float::Parse(words[3])));
							team->count++;
						}
						else
						{
							System::Diagnostics::Debug::WriteLine("找不到此船艦");
						}
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("指令錯誤");
						break;
					}
				}
				else if (words[0] == "DEFENSE")
				{
					if (words->Length == 3)
					{
						if (team->fleetList->ContainsKey(words[1]))
						{
							bool isFound = false;
							isFound = team->fleetList[words[1]]->Defense(words[2], team1.shellList);
							if(!isFound)
								isFound = team->fleetList[words[1]]->Defense(words[2], team2.shellList);
							if(!isFound)
								System::Diagnostics::Debug::WriteLine("找不到此砲彈");
						}
						else
						{
							System::Diagnostics::Debug::WriteLine("找不到此船艦");
						}
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("指令錯誤");
						break;
					}
				}
				else if (words[0] == "TAG")
				{
					if (words->Length == 3)
					{
						if (team->fleetList->ContainsKey(words[1]) && !team->fleetList->ContainsKey(words[2]))
						{
							Fleet ^ temp = gcnew Fleet();
							temp = team->fleetList[words[1]];
							temp->setName(words[2]);
							team->fleetList->Add(words[2],temp);
							team->fleetList->Remove(words[1]);
						}
						else
						{
							System::Diagnostics::Debug::WriteLine("取名失敗");
							break;
						}
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("指令錯誤");
						break;
					}
				}
				else if (words[0] == "MOVE")
				{
					if (words->Length == 4)
					{
						if (team->fleetList->ContainsKey(words[1]))
						{
							team->fleetList[words[1]]->setMove(float::Parse(words[2]), float::Parse(words[3]));
						}
						else
						{
							System::Diagnostics::Debug::WriteLine("找不到此船艦");
						}
					}
					else
					{
						System::Diagnostics::Debug::WriteLine("取名失敗");
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
		}
		for each (auto var in team2.fleetList)
		{
			var.Value->Move();
		}
		
		for each (Shell^ var in team1.shellList)	//迭代器讓所有砲彈移動
		{
			var->Move();
		}
		for each (Shell^ var in team2.shellList)	//迭代器讓所有砲彈移動
		{
			var->Move();
		}

		team1.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team1.shellList);
		team2.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team2.shellList);
		for each (Shell^ var in team1.shellList)	//迭代器讓所有定位砲彈消失(之後要加傷害)
		{
			if (var->getIsBoom())
			{
				for each (auto fleet in team1.fleetList)
				{
					float dis = sqrt(powf(var->getLocation()->X-fleet.Value->getLocation()->X,2)+
						powf(var->getLocation()->Y - fleet.Value->getLocation()->Y, 2));
					if (dis < 1.5)
					{
						fleet.Value->setHP(fleet.Value->getHP() - var->getDamage());
						System::Diagnostics::Debug::WriteLine("擊中船艦");
					}
				}
				team1.bufferShellList->Remove(var);
			}
		}
		for each (Shell^ var in team2.shellList)	//迭代器讓所有定位砲彈消失(之後要加傷害)
		{
			if (var->getIsBoom())
				team2.bufferShellList->Remove(var);
		}
		team1.shellList = team1.bufferShellList;
		team2.shellList = team2.bufferShellList;

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
		for each (auto var in team2.fleetList)
		{
			var.Value->Draw(g);
		}

		//畫砲
		for each (Shell^ var in team1.shellList)
		{
			var->Draw(g);
		}
		for each (Shell^ var in team2.shellList)
		{
			var->Draw(g);
		}
	}
	private: System::Void BtnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		ReadCommand(textBox1,%team1);
		ReadCommand(textBox2,%team2);
		timer1->Enabled = true;
		BtnPause->Enabled = true;
		BtnStart->Enabled = false;
		textBox1->ReadOnly = true;
		textBox2->ReadOnly = true;
	}
	private: System::Void BtnPause_Click(System::Object^  sender, System::EventArgs^  e) {
		timer1->Enabled = false;
		BtnStart->Enabled = true;
		BtnPause->Enabled = false;
		textBox1->ReadOnly = false;
		textBox2->ReadOnly = false;
	}
};
}
