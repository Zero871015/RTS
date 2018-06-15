#pragma once
#include <cmath>
#include "Board.h"
#include "Fleet.h"
#include "Team.h"
#include "BB.h"
#include "CarrierVessel.h"
#include "Destroyer.h"
#include "FlyingMissileCruiser.h"
#include "Exceptions.h"
#include <cctype>
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
	private: System::Windows::Forms::Label^  lblTime;
	private: System::Windows::Forms::TextBox^  Log;
	private: System::Windows::Forms::Button^  BtnNextSec;
	private: System::Windows::Forms::Button^  BtnClearLog;
	private: System::Windows::Forms::ColorDialog^  colorDialogFleetA;
	private: System::Windows::Forms::Button^  BtnColorA;
	private: System::Windows::Forms::Button^  BtnColorB;



	private: System::Windows::Forms::ColorDialog^  colorDialogFleetB;

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
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->Log = (gcnew System::Windows::Forms::TextBox());
			this->BtnNextSec = (gcnew System::Windows::Forms::Button());
			this->BtnClearLog = (gcnew System::Windows::Forms::Button());
			this->colorDialogFleetA = (gcnew System::Windows::Forms::ColorDialog());
			this->BtnColorA = (gcnew System::Windows::Forms::Button());
			this->BtnColorB = (gcnew System::Windows::Forms::Button());
			this->colorDialogFleetB = (gcnew System::Windows::Forms::ColorDialog());
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
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"華康秀風體W3", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox1->Location = System::Drawing::Point(661, 12);
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
			this->BtnStart->Font = (gcnew System::Drawing::Font(L"Impact", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnStart->Location = System::Drawing::Point(30, 749);
			this->BtnStart->Name = L"BtnStart";
			this->BtnStart->Size = System::Drawing::Size(285, 80);
			this->BtnStart->TabIndex = 1;
			this->BtnStart->Text = L"Start";
			this->BtnStart->UseVisualStyleBackColor = true;
			this->BtnStart->Click += gcnew System::EventHandler(this, &MyForm::BtnStart_Click);
			// 
			// BtnPause
			// 
			this->BtnPause->Enabled = false;
			this->BtnPause->Font = (gcnew System::Drawing::Font(L"Impact", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnPause->Location = System::Drawing::Point(340, 749);
			this->BtnPause->Name = L"BtnPause";
			this->BtnPause->Size = System::Drawing::Size(285, 80);
			this->BtnPause->TabIndex = 2;
			this->BtnPause->Text = L"Pause";
			this->BtnPause->UseVisualStyleBackColor = true;
			this->BtnPause->Click += gcnew System::EventHandler(this, &MyForm::BtnPause_Click);
			// 
			// lblTime
			// 
			this->lblTime->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lblTime->Font = (gcnew System::Drawing::Font(L"Ink Free", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTime->Location = System::Drawing::Point(1060, 36);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(222, 73);
			this->lblTime->TabIndex = 3;
			this->lblTime->Text = L"00:00";
			this->lblTime->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Log
			// 
			this->Log->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Log->Location = System::Drawing::Point(961, 130);
			this->Log->Multiline = true;
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->Size = System::Drawing::Size(421, 700);
			this->Log->TabIndex = 2;
			this->Log->Tag = L"";
			// 
			// BtnNextSec
			// 
			this->BtnNextSec->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnNextSec->Location = System::Drawing::Point(30, 707);
			this->BtnNextSec->Name = L"BtnNextSec";
			this->BtnNextSec->Size = System::Drawing::Size(285, 36);
			this->BtnNextSec->TabIndex = 4;
			this->BtnNextSec->Text = L"NextSec";
			this->BtnNextSec->UseVisualStyleBackColor = true;
			this->BtnNextSec->Click += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// BtnClearLog
			// 
			this->BtnClearLog->Font = (gcnew System::Drawing::Font(L"Impact", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnClearLog->Location = System::Drawing::Point(340, 707);
			this->BtnClearLog->Name = L"BtnClearLog";
			this->BtnClearLog->Size = System::Drawing::Size(285, 36);
			this->BtnClearLog->TabIndex = 5;
			this->BtnClearLog->Text = L"ClearLog";
			this->BtnClearLog->UseVisualStyleBackColor = true;
			this->BtnClearLog->Click += gcnew System::EventHandler(this, &MyForm::BtnClearLog_Click);
			// 
			// BtnColorA
			// 
			this->BtnColorA->Location = System::Drawing::Point(30, 23);
			this->BtnColorA->Name = L"BtnColorA";
			this->BtnColorA->Size = System::Drawing::Size(125, 45);
			this->BtnColorA->TabIndex = 6;
			this->BtnColorA->Text = L"Change TeamA Color";
			this->BtnColorA->UseVisualStyleBackColor = true;
			this->BtnColorA->Click += gcnew System::EventHandler(this, &MyForm::BtnColorFleetA_Click);
			// 
			// BtnColorB
			// 
			this->BtnColorB->Location = System::Drawing::Point(30, 74);
			this->BtnColorB->Name = L"BtnColorB";
			this->BtnColorB->Size = System::Drawing::Size(125, 45);
			this->BtnColorB->TabIndex = 6;
			this->BtnColorB->Text = L"Change TeamB Color";
			this->BtnColorB->UseVisualStyleBackColor = true;
			this->BtnColorB->Click += gcnew System::EventHandler(this, &MyForm::BtnColorFleetB_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1486, 1041);
			this->Controls->Add(this->BtnColorB);
			this->Controls->Add(this->BtnColorA);
			this->Controls->Add(this->BtnClearLog);
			this->Controls->Add(this->BtnNextSec);
			this->Controls->Add(this->Log);
			this->Controls->Add(this->lblTime);
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
			this->PerformLayout();

		}
#pragma endregion
		//初始化遊戲設定
		void InitializeGame(void)
		{
			this->DoubleBuffered = true;	//開啟雙緩衝防止畫面閃爍

			bitmap = gcnew Bitmap(441, 441);	//初始化bitmap大小
			g = Graphics::FromImage(bitmap);	//初始化畫布
			this->ClientSize = System::Drawing::Size(W, H);	//調整遊戲視窗大小

			UpdateCanvas();		//更新畫布
			this->Refresh();	//call My_Form Paint
		}
		bool allIsDigit(System::String ^ number)
		{
			for (int i = 0; i < number->Length; i++)
			{
				if (isdigit(number[i]) == false)
					return false;
			}
			return true;
		}
		void ReadCommand(System::Windows::Forms::TextBox ^ textBox, Team ^ team)
		{
			System::Collections::Generic::List<System::String ^> lines;
			System::String ^ temp = "";

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
				try
				{
					array<System::String ^>^ words;
					words = var->Split(gcnew array<System::String ^>{" ", ","}, System::StringSplitOptions::RemoveEmptyEntries);
					if (words->Length == 0)
						throw gcnew Exceptions(words, error::blankLine);
					if (words[0] == "SET")
					{
						if (words->Length == 5)
						{
							words[3] = words[3]->Remove(0, 1);
							words[4] = words[4]->Remove(words[4]->Length - 1, 1);
							if (allIsDigit(words[3]) == false || allIsDigit(words[4]) == false) // 不是數字
								throw gcnew Exceptions(words, error::errorCommand);
							if (team->fleetList->ContainsKey(words[1]) == true) // 相同船艦名字
								throw gcnew Exceptions(words, error::errorSET);
							if (words[2] == "CV")
							{
								team->fleetList->Add(words[1], gcnew CarrierVessel(words[1],
									gcnew PointF(float::Parse(words[3]) + 1,
										float::Parse(words[4]) + 1)));
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									" SET " + words[1] + " with CV at (" + words[3] + "," + words[4] + ") -> Success\r\n";
							}
							else if (words[2] == "BB")
							{
								team->fleetList->Add(words[1], gcnew BB(words[1],
									gcnew PointF(float::Parse(words[3]) + 1,
										float::Parse(words[4]) + 1)));
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									" SET " + words[1] + " with BB at (" + words[3] + "," + words[4] + ") -> Success\r\n";
							}
							else if (words[2] == "CG")
							{
								team->fleetList->Add(words[1], gcnew FlyingMissileCruiser(words[1],
									gcnew PointF(float::Parse(words[3]) + 1,
										float::Parse(words[4]) + 1)));
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									" SET " + words[1] + " with CG at (" + words[3] + "," + words[4] + ") -> Success\r\n";
							}
							else if (words[2] == "DD")
							{
								team->fleetList->Add(words[1], gcnew Destroyer(words[1],
									gcnew PointF(float::Parse(words[3]) + 1,
										float::Parse(words[4]) + 1)));
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									" SET " + words[1] + " with DD at (" + words[3] + "," + words[4] + ") -> Success\r\n";
							}
							else
							{
								throw gcnew Exceptions(words, error::errorCommand);
							}
						}
						else
						{
							throw gcnew Exceptions(words, error::errorCommand);
						}
					}
					else if (words[0] == "FIRE")
					{
						if (words->Length == 4)
						{
							//有這船艦
							if (team->fleetList->ContainsKey(words[1]))
							{
								words[2] = words[2]->Remove(0, 1);
								words[3] = words[3]->Remove(words[3]->Length - 1, 1);
								if (allIsDigit(words[2]) == false || allIsDigit(words[3]) == false) // 不是數字
									throw gcnew Exceptions(words, error::errorCommand);
								if (team->fleetList[words[1]]->Fire(team->shellList,
									"Shell" + textBox->Tag + team->count,
									gcnew PointF(float::Parse(words[2]) + 1, float::Parse(words[3]) + 1)))
								{
									Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
										" " + words[1] + " Fire to (" + words[2] + "," + words[3] + ") -> " + "Shell" + textBox->Tag + team->count + "\r\n";
									team->count++;
								}
								else
								{
									throw gcnew Exceptions(words, error::errorFIRE);
								}
							}
							else
							{
								System::Diagnostics::Debug::WriteLine("找不到此船艦");
							}
						}
						else
						{
							throw gcnew Exceptions(words, error::errorCommand);
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
								if (!isFound)
									isFound = team->fleetList[words[1]]->Defense(words[2], team2.shellList);
								team->fleetList[words[1]]->SetDefenseCD();
								if (isFound)
								{
									Log->Text += "[" + lblTime->Text + "] " + words[1] +
										" Defense " + words[2] + " -> Hit\r\n";
								}
								else
								{
									throw gcnew Exceptions(words, error::errorDEFENSE);
								}
							}
							else
							{
								throw gcnew Exceptions(words, error::errorDEFENSE);
							}
						}
						else
						{
							throw gcnew Exceptions(words, error::errorCommand);
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
								team->fleetList->Add(words[2], temp);
								team->fleetList->Remove(words[1]);
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									" Rename " + words[1] + " to " + words[2] + " -> Success\r\n";
							}
							else
							{
								throw gcnew Exceptions(words, error::errorTAG);
							}
						}
						else
						{
							throw gcnew Exceptions(words, error::errorCommand);
						}
					}
					else if (words[0] == "MOVE")
					{
						if (words->Length == 4)
						{
							if (team->fleetList->ContainsKey(words[1]))
							{
								team->fleetList[words[1]]->setMove(float::Parse(words[2]), float::Parse(words[3]));
								Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
									words[1] + " Move to " + words[3] + " as " + words[2] + " -> Success\r\n";
							}
							else
							{
								throw gcnew Exceptions(words, error::errorMOVE);
							}
						}
						else
						{
							throw gcnew Exceptions(words, error::errorCommand);
						}
					}
				}
				catch (Exceptions ^e)
				{
					switch (e->getType())
					{
					case error::blankLine:
					{
						//有空行
					}
					case error::errorCommand:
					{
						//指令錯誤
					}
					case error::errorSET:
					{
						Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
							" SET " + e->text[1] + " with " + e->text[2] + " at (" + e->text[3] + "," + e->text[4] + ") -> Fail\r\n";
						break;
					}
					case error::errorFIRE:
					{
						Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
							" " + e->text[1] + " Fire to (" + e->text[2] + "," + e->text[3] + ") -> Fail\r\n";
						break;
					}
					case error::errorDEFENSE:
					{
						Log->Text += "[" + lblTime->Text + "] " + e->text[1] +
							" Defense " + e->text[2] + " -> Fail\r\n";
						break;
					}
					case error::errorTAG:
					{
						Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
							" Rename " + e->text[1] + " to " + e->text[2] + " -> Fail\r\n";
						break;
					}
					case error::errorMOVE:
					{
						Log->Text += "[" + lblTime->Text + "]" + " Team" + textBox->Tag +
							e->text[1] + " Move to " + e->text[2] + " as " + e->text[3] + " -> Fail\r\n";
						break;
					}
					default:
						break;
					}
				}
				catch (...)
				{

				}
			}

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawImage(bitmap, 20, 100);	//實際畫在視窗上
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		//計數器顯示
		static int S = 0;
		static int M = 0;
		S++;
		if (S > 59)
		{
			S = 0;
			M++;
		}
		if (M < 10)lblTime->Text = "0";
		else lblTime->Text = "";
		lblTime->Text += M + ":";
		if (S < 10)lblTime->Text += "0";
		lblTime->Text += S;

		//更新所有船艦冷卻時間
		for each (auto var in team1.fleetList)
		{
			var.Value->UpdataCD();
		}
		for each (auto var in team2.fleetList)
		{
			var.Value->UpdataCD();
		}

		//迭代器讓所有船隻移動
		for each (auto var in team1.fleetList)
		{
			var.Value->Move();
		}
		for each (auto var in team2.fleetList)
		{
			var.Value->Move();
		}

		//迭代器讓所有砲彈移動
		for each (Shell^ var in team1.shellList)
		{
			var->Move();
		}
		for each (Shell^ var in team2.shellList)
		{
			var->Move();
		}

		team1.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team1.shellList);
		team2.bufferShellList = gcnew System::Collections::Generic::List<Shell^>(team2.shellList);
		//若是砲彈到達定位，爆炸並造成傷害
		for each (Shell^ var in team1.shellList)
		{
			if (var->getIsBoom())
			{
				System::Collections::Generic::List<System::String ^>^ fleetsName = gcnew System::Collections::Generic::List<System::String ^>;
				for each (auto fleet in team1.fleetList)
				{
					float dis = sqrt(powf(var->getLocation()->X - fleet.Value->getLocation()->X, 2) +
						powf(var->getLocation()->Y - fleet.Value->getLocation()->Y, 2));
					if (dis < 1.5)
					{
						fleetsName->Add(gcnew System::String("TeamA " + fleet.Key));
						fleet.Value->setHP(fleet.Value->getHP() - var->getDamage());
						System::Diagnostics::Debug::WriteLine("擊中船艦");
					}
				}
				for each (auto fleet in team2.fleetList)
				{
					float dis = sqrt(powf(var->getLocation()->X - fleet.Value->getLocation()->X, 2) +
						powf(var->getLocation()->Y - fleet.Value->getLocation()->Y, 2));
					if (dis < 1.5)
					{
						fleetsName->Add(gcnew System::String("TeamB " + fleet.Key));
						fleet.Value->setHP(fleet.Value->getHP() - var->getDamage());
						System::Diagnostics::Debug::WriteLine("擊中船艦");
					}
				}
				//砲彈命中與否Log
				if (fleetsName->Count != 0)
				{
					Log->Text += "[" + lblTime->Text + "] " + var->getName() +
						" arrived (" + (var->getLocation()->X - 1) + "," + (var->getLocation()->Y - 1) + ") -> hit {";
					for (int i = 0; i < fleetsName->Count; i++)
					{
						if (i != fleetsName->Count - 1)
							Log->Text += fleetsName[i] + ", ";
						else
							Log->Text += fleetsName[i] + "}\r\n";
					}
				}
				else
				{
					Log->Text += "[" + lblTime->Text + "] " + var->getName() +
						" arrived (" + (var->getLocation()->X - 1) + "," + (var->getLocation()->Y - 1) + ") -> miss\r\n";
				}
				team1.bufferShellList->Remove(var);
			}
		}
		for each (Shell^ var in team2.shellList)
		{
			if (var->getIsBoom())
			{
				System::Collections::Generic::List<System::String ^>^ fleetsName = gcnew System::Collections::Generic::List<System::String ^>;
				for each (auto fleet in team1.fleetList)
				{
					float dis = sqrt(powf(var->getLocation()->X - fleet.Value->getLocation()->X, 2) +
						powf(var->getLocation()->Y - fleet.Value->getLocation()->Y, 2));
					if (dis < 1.5)
					{
						fleetsName->Add(gcnew System::String("TeamA " + fleet.Key));
						fleet.Value->setHP(fleet.Value->getHP() - var->getDamage());
						System::Diagnostics::Debug::WriteLine("擊中船艦");
					}
				}
				for each (auto fleet in team2.fleetList)
				{
					float dis = sqrt(powf(var->getLocation()->X - fleet.Value->getLocation()->X, 2) +
						powf(var->getLocation()->Y - fleet.Value->getLocation()->Y, 2));
					if (dis < 1.5)
					{
						fleetsName->Add(gcnew System::String("TeamB " + fleet.Key));
						fleet.Value->setHP(fleet.Value->getHP() - var->getDamage());
						System::Diagnostics::Debug::WriteLine("擊中船艦");
					}
				}
				//砲彈命中與否Log
				if (fleetsName->Count != 0)
				{
					Log->Text += "[" + lblTime->Text + "] " + var->getName() +
						" arrived (" + (var->getLocation()->X - 1) + "," + (var->getLocation()->Y - 1) + ") -> hit {";
					for (int i = 0; i < fleetsName->Count; i++)
					{
						if (i != fleetsName->Count - 1)
							Log->Text += fleetsName[i] + ", ";
						else
							Log->Text += fleetsName[i] + "}\r\n";
					}
				}
				else
				{
					Log->Text += "[" + lblTime->Text + "] " + var->getName() +
						" arrived (" + (var->getLocation()->X - 1) + "," + (var->getLocation()->Y - 1) + ") -> miss\r\n";
				}
				team2.bufferShellList->Remove(var);
			}
		}
		team1.shellList = team1.bufferShellList;
		team2.shellList = team2.bufferShellList;

		System::Collections::Generic::Dictionary<System::String ^, Fleet ^>^ temp;
		//檢查是否有船艦被擊沉
		temp = gcnew System::Collections::Generic::Dictionary<System::String ^, Fleet ^>(team1.fleetList);
		for each (auto var in temp)
		{
			if (var.Value->getHP() <= 0)
			{
				team1.fleetList->Remove(var.Key);
				System::Diagnostics::Debug::WriteLine("船艦被擊沉");
				Log->Text += "[" + lblTime->Text + "]" + " TeamA " +
					var.Key + " destoryed\r\n";
			}
		}
		temp = gcnew System::Collections::Generic::Dictionary<System::String ^, Fleet ^>(team2.fleetList);
		for each (auto var in temp)
		{
			if (var.Value->getHP() <= 0)
			{
				team2.fleetList->Remove(var.Key);
				System::Diagnostics::Debug::WriteLine("船艦被擊沉");
				Log->Text += "[" + lblTime->Text + "]" + " TeamB " +
					var.Key + " destoryed\r\n";
			}
		}

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
			var.Value->Draw(g, colorDialogFleetA->Color);
		}
		for each (auto var in team2.fleetList)
		{
			var.Value->Draw(g, colorDialogFleetB->Color);
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
		ReadCommand(textBox1, %team1);
		ReadCommand(textBox2, %team2);
		timer1->Enabled = true;
		BtnPause->Enabled = true;
		BtnStart->Enabled = false;
		BtnNextSec->Enabled = false;
		textBox1->ReadOnly = true;
		textBox2->ReadOnly = true;
	}
	private: System::Void BtnPause_Click(System::Object^  sender, System::EventArgs^  e) {
		textBox1->Text = "";
		textBox2->Text = "";

		timer1->Enabled = false;
		BtnStart->Enabled = true;
		BtnPause->Enabled = false;
		BtnNextSec->Enabled = true;
		textBox1->ReadOnly = false;
		textBox2->ReadOnly = false;
	}
	private: System::Void BtnClearLog_Click(System::Object^  sender, System::EventArgs^  e) {
		Log->Text = "";
	}
	private: System::Void BtnColorFleetA_Click(System::Object^  sender, System::EventArgs^  e) {
		if (colorDialogFleetA->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
		{
			System::Diagnostics::Debug::WriteLine("改變顏色");
		}
	}
	private: System::Void BtnColorFleetB_Click(System::Object^  sender, System::EventArgs^  e) {
		if (colorDialogFleetB->ShowDialog() == ::System::Windows::Forms::DialogResult::OK)
		{
			System::Diagnostics::Debug::WriteLine("改變顏色");
		}
	}
};
}