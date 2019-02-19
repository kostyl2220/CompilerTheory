#pragma once
#include "Program.h"
#include "Exceptions.h"
namespace course_work {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  buildToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  runToolStripMenuItem1;
	public: Program* pr;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->runToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buildToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->runToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(-2, 27);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(746, 330);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->runToolStripMenuItem,
					this->buildToolStripMenuItem, this->runToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(744, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// runToolStripMenuItem
			// 
			this->runToolStripMenuItem->Name = L"runToolStripMenuItem";
			this->runToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->runToolStripMenuItem->Text = L"Build&Run";
			this->runToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::runToolStripMenuItem_Click);
			// 
			// buildToolStripMenuItem
			// 
			this->buildToolStripMenuItem->Name = L"buildToolStripMenuItem";
			this->buildToolStripMenuItem->Size = System::Drawing::Size(46, 20);
			this->buildToolStripMenuItem->Text = L"Build";
			this->buildToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::buildToolStripMenuItem_Click);
			// 
			// runToolStripMenuItem1
			// 
			this->runToolStripMenuItem1->Name = L"runToolStripMenuItem1";
			this->runToolStripMenuItem1->Size = System::Drawing::Size(40, 20);
			this->runToolStripMenuItem1->Text = L"Run";
			this->runToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::runToolStripMenuItem1_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(0, 364);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(597, 100);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(604, 364);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Variables:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(607, 380);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(125, 84);
			this->richTextBox3->TabIndex = 4;
			this->richTextBox3->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 467);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(760, 506);
			this->Name = L"MyForm";
			this->Text = L"Compiler";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//compile & run a program
	private: System::Void runToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		array<String^>^ lines = this->richTextBox1->Lines;
		vector<char*> code;
		for (int i = 0; i < lines->Length; ++i)//convert code from RichTextBox to vector<string>
		{
			IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(lines[i]->ToString());
			char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
			if (strlen(nativeString) != 0)
				code.push_back(nativeString);
		}
		richTextBox2->Clear();//clear output
		richTextBox3->Clear();
		pr = new Program();
		try {
			pr->addCode(code);//build code
			pr->runProgram(richTextBox2);//run code
		}
		catch (CompileExeption& e) {//diiferent errors
			showMessage(e.error(), "Compile error");
		}
		catch (VariableExistsException& e){
			showMessage(e.error(), "Variable exist");
		}
		catch (VariableNotFoundException& e) {
			showMessage(e.error(), "Variable not found");
		}
		catch (TypeException& e) {
			showMessage(e.error(), "Type mismatch");
		}
		pr->outVarList(richTextBox3);
	}

	 void showMessage(string mes, char* type) {
		 MessageBoxButtons btns = MessageBoxButtons::OK;
		 String^ message = gcnew String(mes.c_str());
		 String^ caption = gcnew String(type);
		 MessageBox::Show(this, message, caption, btns);
	 }
	 //for resize of form
	private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
		this->richTextBox1->Width = this->ClientSize.Width;
		this->richTextBox2->Width = this->ClientSize.Width * 0.8;
		this->richTextBox1->Height = this->ClientSize.Height * 0.70;
		this->richTextBox2->Height = this->ClientSize.Height * 0.30 - 10 - this->MainMenuStrip->Height;
		this->richTextBox2->Top = this->ClientSize.Height * 0.70 + 10 + this->MainMenuStrip->Height;
		this->label1->Top = this->richTextBox2->Top;
		this->label1->Left = this->ClientSize.Width * 0.8 + 10;
		this->richTextBox3->Top = this->label1->Bottom;
		this->richTextBox3->Left = this->label1->Left;
		this->richTextBox3->Width = this->ClientSize.Width * 0.2 - 20;
		this->richTextBox3->Height = this->richTextBox2->Height - this->label1->Height;
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void buildToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {//only build
	array<String^>^ lines = this->richTextBox1->Lines;
	vector<char*> code;
	for (int i = 0; i < lines->Length; ++i)
	{
		IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(lines[i]->ToString());
		char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
		if (strlen(nativeString) != 0)
			code.push_back(nativeString);
	}
	pr = new Program();
	try {
		pr->addCode(code);
	}
	catch (CompileExeption& e) {
		showMessage(e.error(), "Compile error");
	}
}
private: System::Void runToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {//only run 
	richTextBox2->Clear();
	richTextBox3->Clear();
	try {
		pr->runProgram(richTextBox2);
	}
	catch (VariableExistsException& e){
		showMessage(e.error(), "Variable exist");
	}
	catch (VariableNotFoundException& e) {
		showMessage(e.error(), "Variable not found");
	}
	catch (TypeException& e) {
		showMessage(e.error(), "Type mismatch");
	}
	pr->outVarList(richTextBox3);
}
};
}


