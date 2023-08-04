#pragma once
#include "hash_map.h"
#include "key_val.h"
#include "container.h"
#include <fstream>

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

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
			hashMap = new HashMap();
			keyPair = new AssociationList();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			delete hashMap;
			delete keyPair;
			if (components)
			{
				delete components;
			}
		}
	private:
		HashMap *hashMap;
		AssociationList *keyPair;

	private: System::Windows::Forms::RadioButton^ keypairRadio;
	private: System::Windows::Forms::RadioButton^ hashtableRadio;
	private: System::Windows::Forms::Label^ zipLabel;
	protected:

	protected:



	private: System::Windows::Forms::DataVisualization::Charting::Chart^ zipChart;


	private: System::Windows::Forms::Button^ loadChart;
	private: System::Windows::Forms::Label^ runtimeLabel;


	private: System::Windows::Forms::TextBox^ runtimeDisplay;

	private: System::Windows::Forms::TextBox^ zipInput;

	private: System::Windows::Forms::ListView^ zipList;
	private: System::Windows::Forms::Button^ resetButton;


	protected:

	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->keypairRadio = (gcnew System::Windows::Forms::RadioButton());
			this->hashtableRadio = (gcnew System::Windows::Forms::RadioButton());
			this->zipLabel = (gcnew System::Windows::Forms::Label());
			this->zipChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->loadChart = (gcnew System::Windows::Forms::Button());
			this->runtimeLabel = (gcnew System::Windows::Forms::Label());
			this->runtimeDisplay = (gcnew System::Windows::Forms::TextBox());
			this->zipInput = (gcnew System::Windows::Forms::TextBox());
			this->zipList = (gcnew System::Windows::Forms::ListView());
			this->resetButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zipChart))->BeginInit();
			this->SuspendLayout();
			// 
			// keypairRadio
			// 
			this->keypairRadio->AutoSize = true;
			this->keypairRadio->Checked = true;
			this->keypairRadio->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keypairRadio->Location = System::Drawing::Point(39, 9);
			this->keypairRadio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->keypairRadio->Name = L"keypairRadio";
			this->keypairRadio->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->keypairRadio->Size = System::Drawing::Size(156, 45);
			this->keypairRadio->TabIndex = 7;
			this->keypairRadio->TabStop = true;
			this->keypairRadio->Text = L"Key-Pair";
			this->keypairRadio->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->keypairRadio->UseVisualStyleBackColor = true;
			// 
			// hashtableRadio
			// 
			this->hashtableRadio->AutoSize = true;
			this->hashtableRadio->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->hashtableRadio->Location = System::Drawing::Point(39, 60);
			this->hashtableRadio->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->hashtableRadio->Name = L"hashtableRadio";
			this->hashtableRadio->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->hashtableRadio->Size = System::Drawing::Size(197, 45);
			this->hashtableRadio->TabIndex = 7;
			this->hashtableRadio->Text = L"Hash Table";
			this->hashtableRadio->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->hashtableRadio->UseVisualStyleBackColor = true;
			// 
			// zipLabel
			// 
			this->zipLabel->AutoSize = true;
			this->zipLabel->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->zipLabel->Location = System::Drawing::Point(45, 114);
			this->zipLabel->Name = L"zipLabel";
			this->zipLabel->Size = System::Drawing::Size(156, 41);
			this->zipLabel->TabIndex = 9;
			this->zipLabel->Text = L"Zip-Code:";
			// 
			// zipChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->zipChart->ChartAreas->Add(chartArea1);
			this->zipChart->Location = System::Drawing::Point(28, 314);
			this->zipChart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->zipChart->Name = L"zipChart";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Zipcode";
			this->zipChart->Series->Add(series1);
			this->zipChart->Size = System::Drawing::Size(443, 362);
			this->zipChart->TabIndex = 10;
			this->zipChart->Text = L"chart1";
			this->zipChart->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// loadChart
			// 
			this->loadChart->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->loadChart->Location = System::Drawing::Point(28, 255);
			this->loadChart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loadChart->Name = L"loadChart";
			this->loadChart->Size = System::Drawing::Size(443, 53);
			this->loadChart->TabIndex = 11;
			this->loadChart->Text = L"Load Chart";
			this->loadChart->UseVisualStyleBackColor = true;
			this->loadChart->Click += gcnew System::EventHandler(this, &MyForm::loadChart_Click);
			// 
			// runtimeLabel
			// 
			this->runtimeLabel->AutoSize = true;
			this->runtimeLabel->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->runtimeLabel->Location = System::Drawing::Point(80, 748);
			this->runtimeLabel->Name = L"runtimeLabel";
			this->runtimeLabel->Size = System::Drawing::Size(146, 41);
			this->runtimeLabel->TabIndex = 13;
			this->runtimeLabel->Text = L"Runtime:";
			// 
			// runtimeDisplay
			// 
			this->runtimeDisplay->Enabled = false;
			this->runtimeDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->runtimeDisplay->Location = System::Drawing::Point(232, 744);
			this->runtimeDisplay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->runtimeDisplay->MaxLength = 9999;
			this->runtimeDisplay->Name = L"runtimeDisplay";
			this->runtimeDisplay->Size = System::Drawing::Size(183, 45);
			this->runtimeDisplay->TabIndex = 14;
			this->runtimeDisplay->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// zipInput
			// 
			this->zipInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zipInput->Location = System::Drawing::Point(207, 111);
			this->zipInput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->zipInput->MaxLength = 5;
			this->zipInput->Name = L"zipInput";
			this->zipInput->Size = System::Drawing::Size(177, 45);
			this->zipInput->TabIndex = 15;
			this->zipInput->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged_1);
			this->zipInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			// 
			// zipList
			// 
			this->zipList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zipList->HideSelection = false;
			this->zipList->Location = System::Drawing::Point(28, 162);
			this->zipList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->zipList->Name = L"zipList";
			this->zipList->Size = System::Drawing::Size(443, 86);
			this->zipList->TabIndex = 16;
			this->zipList->UseCompatibleStateImageBehavior = false;
			this->zipList->View = System::Windows::Forms::View::SmallIcon;
			this->zipList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged_1);
			// 
			// resetButton
			// 
			this->resetButton->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->resetButton->Location = System::Drawing::Point(28, 680);
			this->resetButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(443, 53);
			this->resetButton->TabIndex = 17;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &MyForm::resetButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(501, 800);
			this->Controls->Add(this->resetButton);
			this->Controls->Add(this->zipList);
			this->Controls->Add(this->zipInput);
			this->Controls->Add(this->runtimeDisplay);
			this->Controls->Add(this->runtimeLabel);
			this->Controls->Add(this->loadChart);
			this->Controls->Add(this->zipChart);
			this->Controls->Add(this->zipLabel);
			this->Controls->Add(this->hashtableRadio);
			this->Controls->Add(this->keypairRadio);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zipChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::fstream file("data.csv");
		if (!file.is_open()) {
			MessageBox::Show("Error opening file");
			return;
		}
		else {
			file.clear();
			file.seekg(0, std::ios::beg); // reset file pointer
			keyPair->createFromFile(file);
			file.clear();
			file.seekg(0, std::ios::beg); // reset file pointer
			hashMap->createTableFromFile(file);
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
	private: System::Void maskedTextBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		((MaskedTextBox^)sender)->SelectionStart = 0;
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void maskedTextBox2_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == (char)13) {
			String^ zipCode = this->zipInput->Text;
			bool validEntry = true;
			for each (ListViewItem ^ i in zipList->Items) {
				if (i->Text == zipCode) {
					MessageBox::Show("Please enter a unique 5 digit zip-code");
					validEntry = false;
					return;
				}
			}
			if (zipCode->Length == 5 && System::Text::RegularExpressions::Regex::IsMatch(zipCode, "^[0-9]*$")) {
				ListViewItem^ item = gcnew ListViewItem(zipCode);
				this->zipList->Items->Add(item);
				this->zipInput->Clear();
			}
			else {
				MessageBox::Show("Please enter a 5 digit zip-code");
			}
		}
	}
	
	private: System::Void fillChart() {
		for each (ListViewItem ^ i in zipList->Items) {
			String^ currentZipcode = i->Text;
			bool exists = false;
			for each (DataVisualization::Charting::DataPoint ^ point in zipChart->Series["Zipcode"]->Points) {
				if (point->AxisLabel == currentZipcode) {
					exists = true;
					break;
				}
			}
			if (!exists) {
				int currentZipcodeInt  = System::Convert::ToInt32(currentZipcode);
				int zipVal = 0;
				if (this->keypairRadio->Checked) {
					std::pair<bool, AssociationList::Container> result = keyPair->retrieve(currentZipcodeInt);
					zipVal = result.second.zipCode;
				}
				else if (this->hashtableRadio->Checked) {
					std::pair<bool, HashMap::Container> result = hashMap->retrieve(currentZipcodeInt);
					zipVal = result.second.zipCode;
				}
				zipChart->Series["Zipcode"]->Points->AddXY(currentZipcode, zipVal);
			}
		}
	}

	private: System::Void listView1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void loadChart_Click(System::Object^ sender, System::EventArgs^ e) {
		Stopwatch^ stopwatch = gcnew Stopwatch(); // run time display
		stopwatch->Start();
		fillChart();
		stopwatch->Stop();
		double timeElapsed = stopwatch->Elapsed.TotalMilliseconds;
		String^ elapsedTime = String::Format("{0} ms", timeElapsed);
		runtimeDisplay->Text = elapsedTime;
	}
	private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
		zipChart->Series["Zipcode"]->Points->Clear(); // clear chart
		this->zipList->Items->Clear(); // clear zip code list
	}
};
}
