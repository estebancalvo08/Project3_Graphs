#pragma once
#include "project3.h"
static Graph graph; 

namespace GoogleGraph1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label1->Location = System::Drawing::Point(56, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(739, 44);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to the Google+ Social Connector";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->Location = System::Drawing::Point(74, 200);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(289, 168);
			this->button1->TabIndex = 1;
			this->button1->Text = L"DFS Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->Location = System::Drawing::Point(74, 406);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(289, 168);
			this->button2->TabIndex = 2;
			this->button2->Text = L"BFS Search";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button3->Location = System::Drawing::Point(74, 615);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(289, 168);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Dijkstra";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button4->Location = System::Drawing::Point(518, 200);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(289, 168);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Connectedness";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button5->Location = System::Drawing::Point(518, 406);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(289, 168);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Mapping of vertices";
			this->button5->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button6->Location = System::Drawing::Point(518, 615);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(289, 168);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Time Complexity";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(74, 830);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(289, 22);
			this->textBox1->TabIndex = 7;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(518, 830);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(289, 22);
			this->textBox2->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(130, 798);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 18);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Enter the Start Vertex";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label3->Location = System::Drawing::Point(581, 798);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 18);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Enter the End Vertex";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(74, 875);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(733, 22);
			this->textBox3->TabIndex = 11;
			this->textBox3->Text = L"Hello";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1032, 938);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			int startV = System::Convert::ToInt32(textBox1->Text);
			int endV = System::Convert::ToInt32(textBox2->Text);
			//Checks that the vertices are within range for the graph. If not, will not execute
			if(startV >= graph.getNumvertices() || endV >= graph.getNumvertices())
				textBox3->Text = "Please Enter Valid Vertices for Start and End";
			else
			{
				vector<int> pred(graph.getNumvertices());
				vector<int> dist(graph.getNumvertices());
				vector<int> DFS = graph.DFS(startV, endV, pred, dist);
				int nextNode = endV;
				vector<int> path;
				path.push_back(nextNode);
				while (nextNode != startV) {
					nextNode = pred[nextNode];
					path.push_back(nextNode);
				}
				String^ sol = "";
				for (int i = path.size() - 1; i > 0; i--) {
					sol += System::Convert::ToString(path[i]) + " -> ";
				}
				sol += path[0];

				textBox3->Text = "DFS: " + sol;
			}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int startV = System::Convert::ToInt32(textBox1->Text);
		int endV = System::Convert::ToInt32(textBox2->Text);
		//Checks that the vertices are within range for the graph, if not, will not execute
		if (startV >= graph.getNumvertices() || endV >= graph.getNumvertices())
			textBox3->Text = "Please Enter Valid Vertices for Start and End";
		else {
			vector<int> pred(graph.getNumvertices());
			vector<int> dist(graph.getNumvertices());
			vector<int> BFS = graph.BFS(startV, endV, pred, dist);
			int nextNode = endV;
			vector<int> path;
			path.push_back(nextNode);
			while (nextNode != startV) {
				nextNode = pred[nextNode];
				path.push_back(nextNode);
			}
			String^ sol = "";
			for (int i = path.size() - 1; i > 0; i--) {
				sol += System::Convert::ToString(path[i]) + " -> ";
			}
			sol += path[0];

			textBox3->Text = "BFS: " + sol;
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		int startV = System::Convert::ToInt32(textBox1->Text);
		if (startV >= graph.getNumvertices())
			textBox3->Text = "Please Enter A Valid Vertex";
		else
		{
			vector<pair<int, int>> distances = graph.Dijkstra(startV);
			cout << "\n\nHere are the distances and paths to all other nodes in the graph: \n\n";

			cout << "Vertices   " << '|' << setfill(' ') << setw(23) << "Distances from " << startV << setfill(' ') << setw(7 - to_string(startV).length()) << "|" << setfill(' ') << setw(20) << "Previous Vertex" << endl;
			for (unsigned int i = 0; i < distances.size(); i++)
			{
				cout << i << setfill(' ') << setw(12 - to_string(i).length());
				cout << '|' << setfill(' ') << setw(15) << distances[i].first;
				cout << setfill(' ') << setw(15) << '|' << setfill(' ') << setw(15) << distances[i].second << endl;
			}
			textBox3->Text = "Dijkstra shown in the Command Line";
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		cout << '\n' << "Connectedness: " << endl;
		vector<int> deg = graph.degree();
		for (unsigned int i = 0; i < deg.size(); i++)
		{
			cout << i << " " << deg[i] << endl;
		}
		int mostConnected = graph.getMostConnected().first;
		int numConnections = graph.getMostConnected().second;
		string vertex;
		unordered_map<string, int> temp = graph.getMapping();
		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			if ((*iter).second == mostConnected)
				vertex = (*iter).first;
		}
		String ^ sol = "Most connected Vertex was " + mostConnected  + " with " + numConnections + " connections";
		textBox3->Text = sol;

		
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		cout << '\n' << "Mapping of strings" << endl;
		graph.printMapping();
		textBox3->Text = "Mapping shown in the Command Line";
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		cout << '\n' << "Time Complexities" << endl;
		statistics(graph);
		textBox3->Text = "Statistics shown in the Command Line";
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
