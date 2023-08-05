#pragma once
#include "../include/hash_map.h"
#include "../include/key_val.h"
#include "../include/assoc_list.h"
#include "../include/helpers.h"
#include "../include/resource.h"
#include "../include/tax_info.h"

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
	/// Zip Code Income Visualizer GUI
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			hashMap = new HashMap<TaxInfo>();
			keyPair = new AssociationList<TaxInfo>();
			incomeRanges = gcnew array<String^>(6);
			incomeRanges[0] = "<$25k";
			incomeRanges[1] = "$25k-$50k";
			incomeRanges[2] = "$50k-$75k";
			incomeRanges[3] = "$75k-$100k";
			incomeRanges[4] = "$100k-$200k";
			incomeRanges[5] = ">$200k";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (hashMap) // if hashmap exists, delete it
			{
				delete hashMap;
				hashMap = nullptr; // avoid dangling pointer
			}
			if (keyPair) // if keypair exists, delete it
			{
				delete keyPair;
				keyPair = nullptr; // avoid dangling pointer
			}
			if (components) // if components exist, delete them
			{
				delete components;
			}
		}
	private:
		HashMap<TaxInfo>* hashMap;
		AssociationList<TaxInfo>* keyPair;
		array<String^>^ incomeRanges;

	private: System::Windows::Forms::RadioButton^ keypairRadio;
	private: System::Windows::Forms::RadioButton^ hashtableRadio;
	private: System::Windows::Forms::Label^ zipLabel;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ zipChart;
	private: System::Windows::Forms::Button^ loadChart;
	private: System::Windows::Forms::Label^ runtimeLabel;
	private: System::Windows::Forms::TextBox^ runtimeDisplay;
	private: System::Windows::Forms::TextBox^ zipInput;
	private: System::Windows::Forms::ListView^ zipList;
	private: System::Windows::Forms::Button^ resetButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
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
			this->keypairRadio->Location = System::Drawing::Point(966, 75);
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
			this->hashtableRadio->Location = System::Drawing::Point(966, 131);
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
			this->zipLabel->Location = System::Drawing::Point(139, 29);
			this->zipLabel->Name = L"zipLabel";
			this->zipLabel->Size = System::Drawing::Size(156, 41);
			this->zipLabel->TabIndex = 9;
			this->zipLabel->Text = L"Zip-Code:";
			this->zipLabel->Click += gcnew System::EventHandler(this, &MyForm::zipLabel_Click);
			// 
			// zipChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->zipChart->ChartAreas->Add(chartArea1);
			legend1->AutoFitMinFontSize = 5;
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->zipChart->Legends->Add(legend1);
			this->zipChart->Location = System::Drawing::Point(27, 257);
			this->zipChart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->zipChart->Name = L"zipChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Zipcode";
			this->zipChart->Series->Add(series1);
			this->zipChart->Size = System::Drawing::Size(1215, 491);
			this->zipChart->TabIndex = 10;
			this->zipChart->Text = L"chart1";
			this->zipChart->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// loadChart
			// 
			this->loadChart->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->loadChart->Location = System::Drawing::Point(146, 187);
			this->loadChart->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->loadChart->Name = L"loadChart";
			this->loadChart->Size = System::Drawing::Size(549, 53);
			this->loadChart->TabIndex = 11;
			this->loadChart->Text = L"Load Chart";
			this->loadChart->UseVisualStyleBackColor = true;
			this->loadChart->Click += gcnew System::EventHandler(this, &MyForm::loadChart_Click);
			// 
			// runtimeLabel
			// 
			this->runtimeLabel->AutoSize = true;
			this->runtimeLabel->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->runtimeLabel->Location = System::Drawing::Point(557, 30);
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
			this->runtimeDisplay->Location = System::Drawing::Point(709, 26);
			this->runtimeDisplay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->runtimeDisplay->MaxLength = 9999;
			this->runtimeDisplay->Name = L"runtimeDisplay";
			this->runtimeDisplay->Size = System::Drawing::Size(208, 45);
			this->runtimeDisplay->TabIndex = 14;
			this->runtimeDisplay->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// zipInput
			// 
			this->zipInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zipInput->Location = System::Drawing::Point(301, 26);
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
			this->zipList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zipList->HideSelection = false;
			this->zipList->Location = System::Drawing::Point(146, 86);
			this->zipList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->zipList->Name = L"zipList";
			this->zipList->Size = System::Drawing::Size(769, 86);
			this->zipList->TabIndex = 16;
			this->zipList->UseCompatibleStateImageBehavior = false;
			this->zipList->View = System::Windows::Forms::View::SmallIcon;
			this->zipList->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged_1);
			// 
			// resetButton
			// 
			this->resetButton->Font = (gcnew System::Drawing::Font(L"Malgun Gothic", 18, System::Drawing::FontStyle::Bold));
			this->resetButton->Location = System::Drawing::Point(723, 187);
			this->resetButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->resetButton->Name = L"resetButton";
			this->resetButton->Size = System::Drawing::Size(192, 53);
			this->resetButton->TabIndex = 17;
			this->resetButton->Text = L"Reset";
			this->resetButton->UseVisualStyleBackColor = true;
			this->resetButton->Click += gcnew System::EventHandler(this, &MyForm::resetButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1270, 785);
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
			this->Text = L"Zip Code Income Visualizer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->zipChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::fstream file("data/data.csv");
		if (!file.is_open()) {
			MessageBox::Show("Error opening file");
			return;
		}
		else {
			file.clear();
			file.seekg(0, std::ios::beg); // reset file pointer
			createTaxTableFromFile(file, *keyPair);
			file.clear();
			file.seekg(0, std::ios::beg); // reset file pointer
			createTaxTableFromFile(file, *hashMap);
		}
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
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
		if (e->KeyChar == (char)13) { // enter key
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

	private: System::Void fillChart(bool& chartDrawn, String^& message) {

		zipChart->Series->Clear();
		System::Collections::Generic::List<String^> badZipCodes;

		for (int i = 0; i < 6; i++) {
			auto series = gcnew System::Windows::Forms::DataVisualization::Charting::Series(); // Create series
			series->Name = incomeRanges[i];
			series->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar; // Chart styling
			zipChart->Series->Add(series); // Adding series
		}

		for each (ListViewItem ^ i in zipList->Items) {
			String^ currentZipcode = i->Text;
			bool exists = false;

			if (!exists) {
				int currentZipcodeInt = System::Convert::ToInt32(currentZipcode);
				std::array<int, 6> zipIncomes; // Array to hold each income value
				bool success = false;
				if (this->keypairRadio->Checked) {
					std::pair<bool, TaxInfo> result = keyPair->retrieve(currentZipcodeInt);
					zipIncomes = result.second.incomes;// Retrieve income from respective data structure
					success = result.first;
				}
				else if (this->hashtableRadio->Checked) {
					std::pair<bool, TaxInfo> result = hashMap->retrieve(currentZipcodeInt);
					zipIncomes = result.second.incomes; // Retrieve income from respective data structure
					success = result.first;
				}
				// list of all unsuccessful zipcodes
				if (success) {
					for (int i = 0; i < 6; i++) {
						zipChart->Series[incomeRanges[i]]->Points->AddXY(currentZipcode, zipIncomes[i]); // Add data to chart, 6 bars for each zipcode
					}
				}
				else {
					badZipCodes.Add(currentZipcode);
				}
			}
		}
		if (badZipCodes.Count == 0) {
			zipChart->Legends[0]->Enabled = true; // show legend
			chartDrawn = true;
		}
		else {
			message = "The following zip codes are invalid and were not shown: ";
			for (int i = 0; i < badZipCodes.Count; i++) {
				message += "\n" + badZipCodes[i];
			}
			chartDrawn = badZipCodes.Count == zipList->Items->Count ? false : true;
			zipChart->Legends[0]->Enabled = chartDrawn;
		}
	}

	private: System::Void listView1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void loadChart_Click(System::Object^ sender, System::EventArgs^ e) {
		bool chartDrawn = false;
		String^ message = "";
		Stopwatch^ stopwatch = gcnew Stopwatch(); // run time display
		stopwatch->Start();
		fillChart(chartDrawn, message);
		stopwatch->Stop();
		double timeElapsed = stopwatch->Elapsed.TotalMilliseconds;
		String^ elapsedTime = String::Format("{0} ms", timeElapsed);
		if (chartDrawn) {
			runtimeDisplay->Text = elapsedTime;
		}
		if (message != "") {
			MessageBox::Show(message);
		}
	}
	private: System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < 6; i++) {
			zipChart->Series[incomeRanges[i]]->Points->Clear(); // clear chart
		}
		this->zipList->Items->Clear(); // clear zip code list
		zipChart->Legends[0]->Enabled = false; // hides legend
		runtimeDisplay->Text = "";
	}
	private: System::Void zipLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}