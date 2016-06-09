#using <System.Data.dll>
#using <System.Transactions.dll>
#using <System.EnterpriseServices.dll>
#using <System.Xml.dll>
#using <System.Drawing.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Windows::Forms;


#pragma once
ref class DBControl
{
private:
	
public:
	DBControl();
	
	void getData(String^ selectCommand, SqlDataAdapter^ dataAdapter, DataGridView^ dgView, BindingSource^ bnSrc) {
		try {
			String^ connectionString = "Data Source=(localdb)\\ProjectsV13;Initial Catalog=NARZEDZIA_DB;Integrated Security=True";
			//Data Source=CF11001\SQLEXPRESS;Initial Catalog=NARZEDZIA_1;Integrated Security=True
			//Data Source=(localdb)\ProjectsV13;Initial Catalog=NARZEDZIA_DB;Integrated Security=True

			dataAdapter = gcnew SqlDataAdapter(selectCommand, connectionString);

			gcnew SqlCommandBuilder(dataAdapter);

			DataTable^ table = gcnew DataTable();
			dataAdapter->Fill(table);
			//BindingSource^ bnSrc = gcnew BindingSource();
			bnSrc->DataSource = table;
			dgView->DataSource = bnSrc;
			dgView->AutoResizeColumns(
				DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader);

		}
		catch (SqlException^ e) {
			String^ errorMessage = e->Message;
			MessageBox::Show("Coœ posz³o nie tak z baz¹. Problem: " + errorMessage + ". Proszê przekazaæ treœæ tej wiadomoœci administratorowi.");
		}
	}


	void insertData(String^ insertCommand, SqlDataAdapter^ dataAdapter, DataSet^ ds) {
		try {
			String^ connectionString = "Data Source=(localdb)\\ProjectsV13;Initial Catalog=NARZEDZIA_DB;Integrated Security=True";
			dataAdapter = gcnew SqlDataAdapter(insertCommand, connectionString);
			gcnew SqlCommandBuilder(dataAdapter);

		}
		catch (SqlException^ e) {
			String^ eMessage = e->Message;
			MessageBox::Show(eMessage);
		}
	}

	void updateTable(SqlDataAdapter^ adapter, BindingSource^ bnSrc, DataGridView^ dgView) {
		adapter->Update((DataTable^)bnSrc->DataSource);
	}
};

