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
	private: System::Collections::Generic::List<Shell^>^ shellList;
	private: System::Collections::Generic::List<Shell^>^ bufferShellList;
	private: Team team1, team2;
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
		//初始化遊戲設定
		void InitializeGame(void)
		{
			this->DoubleBuffered = true;	//開啟雙緩衝防止畫面閃爍

			bitmap = gcnew Bitmap(441, 441);	//初始化bitmap大小
			g = Graphics::FromImage(bitmap);	//初始化畫布
			this->ClientSize = System::Drawing::Size(W, H);	//調整遊戲視窗大小


			//測試隊伍新增船艦
			team1.fleetList->Add(gcnew Fleet());
			team1.fleetList[0]->setMove(2.0, 270);
			team1.fleetList->Add(gcnew Fleet("Yori", PointF(200, 200)));
			team1.fleetList[1]->setMove(2.0, 150);

			//測試砲彈集合
			shellList = gcnew System::Collections::Generic::List<Shell^>;

		}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawImage(bitmap, 50, 100);	//實際畫在視窗上
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		//迭代器讓所有船隻移動
		for each (Fleet^ var in team1.fleetList)
		{
			var->Move();
			Random r;
			if (r.Next(20) == 0)
				var->Fire(shellList, gcnew PointF(150, 150));	//測試開砲
		}

		
		for each (Shell^ var in shellList)	//迭代器讓所有砲彈移動
		{
			var->Move();
		}
		bufferShellList = gcnew System::Collections::Generic::List<Shell^>(shellList);
		for each (Shell^ var in shellList)	//迭代器讓所有定位砲彈消失(之後要加傷害)
		{
			if (var->getIsBoom())
				bufferShellList->Remove(var);
		}
		shellList = bufferShellList;

		UpdateCanvas();		//更新畫布
		this->Refresh();	//call My_Form Paint
	}

	private: System::Void UpdateCanvas()
	{
		g->Clear(System::Drawing::Color::White);	//先清空畫布

		myBoard.Draw(g);	//重畫地圖
		
		//畫船
		for each (Fleet ^ var in team1.fleetList)
		{
			var->Draw(g);
		}

		//畫砲
		for each (Shell^ var in shellList)
		{
			var->Draw(g);
		}
	}
	};
}
