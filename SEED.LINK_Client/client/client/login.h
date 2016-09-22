#pragma once

namespace client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	private: bool dragging;
	private: System::Windows::Forms::TextBox^  username;
	private: System::Windows::Forms::TextBox^  password;
	private: System::Windows::Forms::Button^  close;
	private: System::Windows::Forms::Button^  minimize;
	private: Point offset;
	public:
		login(void)
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
		~login()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(login::typeid));
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->close = (gcnew System::Windows::Forms::Button());
			this->minimize = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// username
			// 
			this->username->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->username->Font = (gcnew System::Drawing::Font(L"Lato", 16, System::Drawing::FontStyle::Bold));
			this->username->ForeColor = System::Drawing::SystemColors::Window;
			this->username->Location = System::Drawing::Point(74, 184);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(311, 32);
			this->username->TabIndex = 0;
			this->username->TextChanged += gcnew System::EventHandler(this, &login::username_TextChanged);
			// 
			// password
			// 
			this->password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->password->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password->Font = (gcnew System::Drawing::Font(L"Lato", 16, System::Drawing::FontStyle::Bold));
			this->password->ForeColor = System::Drawing::SystemColors::Window;
			this->password->Location = System::Drawing::Point(74, 271);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(311, 32);
			this->password->TabIndex = 1;
			// 
			// close
			// 
			this->close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->close->FlatAppearance->BorderSize = 0;
			this->close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.Image")));
			this->close->Location = System::Drawing::Point(435, 4);
			this->close->Margin = System::Windows::Forms::Padding(0);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(20, 20);
			this->close->TabIndex = 0;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &login::close_Click);
			// 
			// minimize
			// 
			this->minimize->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->minimize->FlatAppearance->BorderSize = 0;
			this->minimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimize->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize.Image")));
			this->minimize->Location = System::Drawing::Point(403, 4);
			this->minimize->Name = L"minimize";
			this->minimize->Size = System::Drawing::Size(20, 20);
			this->minimize->TabIndex = 2;
			this->minimize->UseVisualStyleBackColor = true;
			this->minimize->Click += gcnew System::EventHandler(this, &login::minimize_Click);
			// 
			// login
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(460, 590);
			this->Controls->Add(this->minimize);
			this->Controls->Add(this->close);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" ";
			this->Load += gcnew System::EventHandler(this, &login::login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void login_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dragging = false;
	}
	//dragging
	private: System::Void LoginForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = true;
		this->offset = Point(e->X, e->Y);
	}

	private: System::Void LoginForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (this->dragging) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
		}
	}

	private: System::Void  LoginForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->dragging = false; //this bool is awesome
	}

	private: System::Void username_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void close_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void minimize_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
}	
};
	//dragging functions end
}
