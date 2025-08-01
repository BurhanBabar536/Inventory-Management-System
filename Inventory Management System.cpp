////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Inventory Management Project  //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////////////// Prototypes/////////////////////////////////////////////////////////
void copyArrays(char destination[], const char source[]);
void swapInt(int& a, int& b);
void swapArray(char str1[], char str2[]);
void display(int* id, char* names[], int* quantity, int* price, int Size);
void sortIdAscending(int* arr, int Size);
void sortIdDescending(int* arr, int Size);
int customStringCompare(const char* str1, const char* str2);
void sortNameDescending(int* id, char* names[], int* quantity, int* price, int Size);
void customStringSwap(char*& str1, char*& str2);
void sortNameAescending(int* id, char* names[], int* quantity, int* price, int Size);
int searchIndexById(int* id, int Size, int searchingId);
void newEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size, const int entries);
void deleteEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size);
void searchId(int* id, char* names[], int* quantity, int* price, int Size, int searchingId);
void searchName(int* id, char* names[], int* quantity, int* price, int Size, const char* nameToSearch);
void searchPrice(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper);
void searchQuantity(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper);
void lowStock(int* id, char* names[], int* quantity, int* price, int Size, int stock);
int totalInventory(int* quantity, int* price, int Size);
void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity);
void updatePrice(int* price, int Size, int idToUpdate, int newPrice);
void backup(int* id, char* names[], int* quantity, int* price, int Size);
void restore(int*& id, char* names[], int*& quantity, int*& price, int& Size);
int customAStringCompare(const char* str1, const char* str2);
void customAStringSwap(char*& str1, char*& str2);
void Menu();
//////////////////////////////////////////  Main Function //////////////////////////////////////////////////////////////////////////////////
int main()
{
	const int size = 20;
	const int entries = 25;
	int* id = new int[entries];
	char** names = new char*[entries];
	for (int i = 0; i < entries; ++i)
	{
		names[i] = new char[50];
	}
	int* quantity = new int[entries];
	int* price = new int[entries];
	int Size = 0;
	char option;

	do
	{
		Menu();
		cout << "Enter your option: ";
		cin >> option;

		switch (option)
		{
		case '1':
			sortIdAscending(id, Size);
			display(id, names, quantity, price, Size);
			break;
		case '2':
			sortIdDescending(id, Size);
			display(id, names, quantity, price, Size);
			break;
		case '3':
			sortIdAscending(quantity, Size);
			display(id, names, quantity, price, Size);
			break;
		case '4':
			sortIdDescending(quantity, Size);
			display(id, names, quantity, price, Size);
			break;
		case '5':
			sortIdAscending(price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '6':
			sortIdDescending(price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '7':
			sortNameAescending(id, names, quantity, price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '8':
			sortNameDescending(id, names, quantity, price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '9':
			newEntry(id, names, quantity, price, Size, entries);
			break;
		case 'D':
		case 'd':
			deleteEntry(id, names, quantity, price, Size);
			break;
		case 'S':
		case 's':
		{
					int searchingId;
					cout << "Enter the Id to search: ";
					cin >> searchingId;
					searchId(id, names, quantity, price, Size, searchingId);
		}
			break;
		case 'N':
		case 'n':
		{
					char nameToSearch[50];
					cout << "Enter the product name to search: ";
					cin.ignore();
					cin.getline(nameToSearch, 50);
					searchName(id, names, quantity, price, Size, nameToSearch);
		}
			break;
		case 'R':
		case 'r':
		{
					int lower, upper;
					cout << "Enter the price range (lower and upper): ";
					cin >> lower >> upper;
					searchPrice(id, names, quantity, price, Size, lower, upper);
		}
			break;
		case 'Q':
		case 'q':
		{
					int lower, upper;
					cout << "Enter the quantity range (lower and upper): ";
					cin >> lower >> upper;
					searchQuantity(id, names, quantity, price, Size, lower, upper);
		}
			break;
		case 'L':
		case 'l':
		{
					int stock;
					cout << "Enter the stock for low stock items: ";
					cin >> stock;
					lowStock(id, names, quantity, price, Size, stock);
		}
			break;
		case 'V':
		case 'v':
		{
					int value = totalInventory(quantity, price, Size);
					cout << "Total Inventory Value: " << value << "\n";
		}
			break;
		case 'U':
		case 'u':
		{
					int idToUpdate, newQuantity;
					cout << "Enter the Id to update quantity: ";
					cin >> idToUpdate;
					cout << "Enter the new quantity: ";
					cin >> newQuantity;
					void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity);
					display(id, names, quantity, price, Size);
		}
			break;
		case 'P':
		case 'p':
		{
					int idToUpdate, newPrice;
					cout << "Enter the Id to update price: ";
					cin >> idToUpdate;
					cout << "Enter the new price: ";
					cin >> newPrice;
					updatePrice(price, Size, idToUpdate, newPrice);
		}
			break;
		case 'B':
		case 'b':
			backup(id, names, quantity, price, Size);
			break;
		case 'O':
		case 'o':
			restore(id, names, quantity, price, Size);
			break;
		case 'E':
		case 'e':
			cout << "Exiting the program.\n";
			break;
		default:
			cout << "Invalid Choice. Please try again.\n";
			break;
		}
	} while (option != 'E' && option != 'e');

	delete[] id;
	for (int i = 0; i < entries; ++i)
	{
		delete[] names[i];
	}
	delete[] names;
	delete[] quantity;
	delete[] price;

	cout << endl;
	system("pause");
	return 0;
}

///////////////////////////////////////////// Functions /////////////////////////////////////////////////////////

void Menu()
{
	cout << "\\Main Menu\\\n";
	cout << "1. Sort and display all records Id-wise in ascending order\n";
	cout << "2. Sort and display all records Id-wise in descending order\n";
	cout << "3. Sort and display all records in ascending order based on quantity\n";
	cout << "4. Sort and display all records in descending order based on quantity\n";
	cout << "5. Sort and display all records in ascending order based on price\n";
	cout << "6. Sort and display all records in descending order based on price\n";
	cout << "7. Sort and display all records in ascending order (alphabetically) based on Product name\n";
	cout << "8. Sort and display all records in descending order (alphabetically) based on Product name\n";
	cout << "9. Add a new entry\n";
	cout << "D. Delete an item based on the product Id\n";
	cout << "S. Search an item based on Id\n";
	cout << "N. Search an item based on Product Name\n";
	cout << "R. Search an item based on range of price\n";
	cout << "Q. Search an item based on range of quantity\n";
	cout << "L. Display low stock items\n";
	cout << "V. Display Total Inventory Value\n";
	cout << "U. Update an item (quantity)\n";
	cout << "P. Update an item (price)\n";
	cout << "B. Backup the data\n";
	cout << "O. Restore the data\n";
	cout << "E. Exit\n";
}
void copyArrays(char destination[], const char source[])
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		++i;
	}
	destination[i] = '\0';
}

void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapArray(char str1[], char str2[])
{
	char temp[50];
	copyArrays(temp, str1);
	copyArrays(str1, str2);
	copyArrays(str2, temp);
}

void display(int* id, char* names[], int* quantity, int* price, int Size)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
	}
}
//////////////////////////////////////////  ascending by ID /////////////////////////////////////////////////////////
void sortIdAscending(int* arr, int Size)
{
	for (int i = 0; i < Size - 1; ++i)
	{
		for (int j = 0; j < Size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapInt(arr[j], arr[j + 1]);
			}
		}
	}
}
////////////////////////////////////////// Decending by ID /////////////////////////////////////////////////////////
void sortIdDescending(int* arr, int Size)
{
	for (int i = 0; i < Size - 1; ++i)
	{
		for (int j = 0; j < Size - 1 - i; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swapInt(arr[j], arr[j + 1]);
			}
		}
	}
}////////////////////////////////////////// Ascendiny by Name /////////////////////////////////////////////////////////
int customAStringCompare(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return (*str2 - *str1);
		}
		++str1;
		++str2;
	}
	return (*str2 - *str1);
}

void sortNameAescending(int* id, char* names[], int* quantity, int* price, int Size) {
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = 0; j < Size - 1 - i; ++j) {
			if (customAStringCompare(names[j], names[j + 1]) < 0) {
				swapInt(id[j], id[j + 1]);
				swapInt(quantity[j], quantity[j + 1]);
				swapInt(price[j], price[j + 1]);
				customAStringSwap(names[j], names[j + 1]);
			}
		}
	}
}
void customAStringSwap(char*& str1, char*& str2) {
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}
////////////////////////////////////////// Decending by name /////////////////////////////////////////////////////////
int customStringCompare(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return (*str1 - *str2);
		}
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

void sortNameDescending(int* id, char* names[], int* quantity, int* price, int Size) {
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = 0; j < Size - 1 - i; ++j) {
			if (customStringCompare(names[j], names[j + 1]) < 0) {
				swapInt(id[j], id[j + 1]);
				swapInt(quantity[j], quantity[j + 1]);
				swapInt(price[j], price[j + 1]);
				customStringSwap(names[j], names[j + 1]);
			}
		}
	}
}
void customStringSwap(char*& str1, char*& str2) {
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}

////////////////////////////////////////// search ind by id /////////////////////////////////////////////////////////
int searchIndexById(int* id, int Size, int searchingId)
{
	for (int i = 0; i < Size; ++i)
	{
		if (id[i] == searchingId)
		{
			return i;
		}
	}
	return -1;
}
////////////////////////////////////////// new entry /////////////////////////////////////////////////////////
void newEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size, const int entries)
{
	if (Size < entries)
	{
		cout << "Enter details for the new entry:\n";
		++Size;

		cout << "Product Id: ";
		cin >> id[Size - 1];

		while (searchIndexById(id, Size - 1, id[Size - 1]) != -1)
		{
			cout << "Id already exists. Enter a unique Id: ";
			cin >> id[Size - 1];
		}

		cout << "Product Name: ";
		cin.ignore();
		cin.getline(names[Size - 1], 50);

		cout << "Quantity: ";
		cin >> quantity[Size - 1];

		cout << "Price: ";
		cin >> price[Size - 1];

		cout << "New Item Added Successfully!\n\n";
	}
	else
	{
		cout << "Maximum entries reached. Cannot add more entries.\n\n";
	}
}
////////////////////////////////////////// delete entry /////////////////////////////////////////////////////////
void deleteEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size)
{
	int deletionId;
	cout << "Enter the desired Id to delete: ";
	cin >> deletionId;

	int position = searchIndexById(id, Size, deletionId);

	if (position != -1)
	{
		for (int i = position; i < Size - 1; ++i)
		{
			id[i] = id[i + 1];
			copyArrays(names[i], names[i + 1]);
			quantity[i] = quantity[i + 1];
			price[i] = price[i + 1];
		}
		--Size;

		cout << "Item with Id " << deletionId << " deleted successfully.\n\n";
	}
	else
	{
		cout << "Item with Id " << deletionId << " not found.\n\n";
	}
}
////////////////////////////////////////// search by id /////////////////////////////////////////////////////////
void searchId(int* id, char* names[], int* quantity, int* price, int Size, int searchingId)
{
	cout << "Enter the Id to search: ";
	cin >> searchingId;

	int position = searchIndexById(id, Size, searchingId);

	if (position != -1)
	{
		cout << "Id\tPName\tQuant\tPrice\n";
		cout << id[position] << "\t" << names[position] << "\t" << quantity[position] << "\t" << price[position] << "\n";
	}
	else
	{
		cout << "Item with Id " << searchingId << " not found.\n";
	}
}
////////////////////////////////////////// search by name /////////////////////////////////////////////////////////
void searchName(int* id, char* names[], int* quantity, int* price, int Size, const char* nameToSearch)
{
	bool flag = false;
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (strcmp(names[i], nameToSearch) == 0)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "No entry found with the given name.\n\n";
	}
}
////////////////////////////////////////// search by price /////////////////////////////////////////////////////////
void searchPrice(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (price[i] >= lower && price[i] <= upper)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// search by quantity /////////////////////////////////////////////////////////
void searchQuantity(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (quantity[i] >= lower && quantity[i] <= upper)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// low stck /////////////////////////////////////////////////////////
void lowStock(int* id, char* names[], int* quantity, int* price, int Size, int stock)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (quantity[i] < stock)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// total inventory/////////////////////////////////////////////////////////
int totalInventory(int* quantity, int* price, int Size)
{
	int value = 0;
	for (int i = 0; i < Size; ++i)
	{
		value += quantity[i] * price[i];
	}
	return value;
}
////////////////////////////////////////// update quantity /////////////////////////////////////////////////////////
void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity)
{
	int position = searchIndexById(quantity, Size, idToUpdate);
	if (position != -1)
	{
		quantity[position] = newQuantity;
		cout << "Quantity updated successfully.\n\n";
	}
	else
	{
		cout << "Id not found. Update failed.\n\n";
	}
}

////////////////////////////////////////// update price /////////////////////////////////////////////////////////
void updatePrice(int* price, int Size, int idToUpdate, int newPrice)
{
	int position = searchIndexById(price, Size, idToUpdate);
	if (position != -1)
	{
		price[position] = newPrice;
		cout << "Price updated successfully.\n\n";
	}
	else
	{
		cout << "Id not found. Update failed.\n\n";
	}
}
////////////////////////////////////////// backup /////////////////////////////////////////////////////////
void backup(int* id, char* names[], int* quantity, int* price, int Size)
{
	ofstream outFile("Inventory.txt");
	if (outFile.is_open())
	{
		for (int i = 0; i < Size; ++i)
		{
			outFile << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}

		cout << "Backup successful.\n\n";
		outFile.close();
	}
	else
	{
		cout << "Unable to open backup file.\n\n";
	}
}
////////////////////////////////////////// restore /////////////////////////////////////////////////////////
void restore(int*& id, char* names[], int*& quantity, int*& price, int& Size)
{
	ifstream inFile("Inventory.txt");

	if (inFile.is_open())
	{
		while (inFile >> id[Size] >> names[Size] >> quantity[Size] >> price[Size])
		{
			++Size;
		}

		cout << "Restore successful.\n\n";
		inFile.close();
	}
	else
	{
		cout << "Unable to open backup file for restore.\n\n";
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Inventory Management Project  //////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////////////// Prototypes/////////////////////////////////////////////////////////
void copyArrays(char destination[], const char source[]);
void swapInt(int& a, int& b);
void swapArray(char str1[], char str2[]);
void display(int* id, char* names[], int* quantity, int* price, int Size);
void sortIdAscending(int* arr, int Size);
void sortIdDescending(int* arr, int Size);
int customStringCompare(const char* str1, const char* str2);
void sortNameDescending(int* id, char* names[], int* quantity, int* price, int Size);
void customStringSwap(char*& str1, char*& str2);
void sortNameAescending(int* id, char* names[], int* quantity, int* price, int Size);
int searchIndexById(int* id, int Size, int searchingId);
void newEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size, const int entries);
void deleteEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size);
void searchId(int* id, char* names[], int* quantity, int* price, int Size, int searchingId);
void searchName(int* id, char* names[], int* quantity, int* price, int Size, const char* nameToSearch);
void searchPrice(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper);
void searchQuantity(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper);
void lowStock(int* id, char* names[], int* quantity, int* price, int Size, int stock);
int totalInventory(int* quantity, int* price, int Size);
void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity);
void updatePrice(int* price, int Size, int idToUpdate, int newPrice);
void backup(int* id, char* names[], int* quantity, int* price, int Size);
void restore(int*& id, char* names[], int*& quantity, int*& price, int& Size);
int customAStringCompare(const char* str1, const char* str2);
void customAStringSwap(char*& str1, char*& str2);
void Menu();
//////////////////////////////////////////  Main Function //////////////////////////////////////////////////////////////////////////////////
int main()
{
	const int size = 20;
	const int entries = 25;
	int* id = new int[entries];
	char** names = new char*[entries];
	for (int i = 0; i < entries; ++i)
	{
		names[i] = new char[50];
	}
	int* quantity = new int[entries];
	int* price = new int[entries];
	int Size = 0;
	char option;

	do
	{
		Menu();
		cout << "Enter your option: ";
		cin >> option;

		switch (option)
		{
		case '1':
			sortIdAscending(id, Size);
			display(id, names, quantity, price, Size);
			break;
		case '2':
			sortIdDescending(id, Size);
			display(id, names, quantity, price, Size);
			break;
		case '3':
			sortIdAscending(quantity, Size);
			display(id, names, quantity, price, Size);
			break;
		case '4':
			sortIdDescending(quantity, Size);
			display(id, names, quantity, price, Size);
			break;
		case '5':
			sortIdAscending(price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '6':
			sortIdDescending(price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '7':
			sortNameAescending(id, names, quantity, price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '8':
			sortNameDescending(id, names, quantity, price, Size);
			display(id, names, quantity, price, Size);
			break;
		case '9':
			newEntry(id, names, quantity, price, Size, entries);
			break;
		case 'D':
		case 'd':
			deleteEntry(id, names, quantity, price, Size);
			break;
		case 'S':
		case 's':
		{
					int searchingId;
					cout << "Enter the Id to search: ";
					cin >> searchingId;
					searchId(id, names, quantity, price, Size, searchingId);
		}
			break;
		case 'N':
		case 'n':
		{
					char nameToSearch[50];
					cout << "Enter the product name to search: ";
					cin.ignore();
					cin.getline(nameToSearch, 50);
					searchName(id, names, quantity, price, Size, nameToSearch);
		}
			break;
		case 'R':
		case 'r':
		{
					int lower, upper;
					cout << "Enter the price range (lower and upper): ";
					cin >> lower >> upper;
					searchPrice(id, names, quantity, price, Size, lower, upper);
		}
			break;
		case 'Q':
		case 'q':
		{
					int lower, upper;
					cout << "Enter the quantity range (lower and upper): ";
					cin >> lower >> upper;
					searchQuantity(id, names, quantity, price, Size, lower, upper);
		}
			break;
		case 'L':
		case 'l':
		{
					int stock;
					cout << "Enter the stock for low stock items: ";
					cin >> stock;
					lowStock(id, names, quantity, price, Size, stock);
		}
			break;
		case 'V':
		case 'v':
		{
					int value = totalInventory(quantity, price, Size);
					cout << "Total Inventory Value: " << value << "\n";
		}
			break;
		case 'U':
		case 'u':
		{
					int idToUpdate, newQuantity;
					cout << "Enter the Id to update quantity: ";
					cin >> idToUpdate;
					cout << "Enter the new quantity: ";
					cin >> newQuantity;
					void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity);
		}
			break;
		case 'P':
		case 'p':
		{
					int idToUpdate, newPrice;
					cout << "Enter the Id to update price: ";
					cin >> idToUpdate;
					cout << "Enter the new price: ";
					cin >> newPrice;
					updatePrice(price, Size, idToUpdate, newPrice);
		}
			break;
		case 'B':
		case 'b':
			backup(id, names, quantity, price, Size);
			break;
		case 'O':
		case 'o':
			restore(id, names, quantity, price, Size);
			break;
		case 'E':
		case 'e':
			cout << "Exiting the program.\n";
			break;
		default:
			cout << "Invalid Choice. Please try again.\n";
			break;
		}
	} while (option != 'E' && option != 'e');

	delete[] id;
	for (int i = 0; i < entries; ++i)
	{
		delete[] names[i];
	}
	delete[] names;
	delete[] quantity;
	delete[] price;

	cout << endl;
	system("pause");
	return 0;
}

///////////////////////////////////////////// Functions /////////////////////////////////////////////////////////

void Menu()
{
	cout << "\\Main Menu\\\n";
	cout << "1. Sort and display all records Id-wise in ascending order\n";
	cout << "2. Sort and display all records Id-wise in descending order\n";
	cout << "3. Sort and display all records in ascending order based on quantity\n";
	cout << "4. Sort and display all records in descending order based on quantity\n";
	cout << "5. Sort and display all records in ascending order based on price\n";
	cout << "6. Sort and display all records in descending order based on price\n";
	cout << "7. Sort and display all records in ascending order (alphabetically) based on Product name\n";
	cout << "8. Sort and display all records in descending order (alphabetically) based on Product name\n";
	cout << "9. Add a new entry\n";
	cout << "D. Delete an item based on the product Id\n";
	cout << "S. Search an item based on Id\n";
	cout << "N. Search an item based on Product Name\n";
	cout << "R. Search an item based on range of price\n";
	cout << "Q. Search an item based on range of quantity\n";
	cout << "L. Display low stock items\n";
	cout << "V. Display Total Inventory Value\n";
	cout << "U. Update an item (quantity)\n";
	cout << "P. Update an item (price)\n";
	cout << "B. Backup the data\n";
	cout << "O. Restore the data\n";
	cout << "E. Exit\n";
}
void copyArrays(char destination[], const char source[])
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		++i;
	}
	destination[i] = '\0';
}

void swapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapArray(char str1[], char str2[])
{
	char temp[50];
	copyArrays(temp, str1);
	copyArrays(str1, str2);
	copyArrays(str2, temp);
}

void display(int* id, char* names[], int* quantity, int* price, int Size)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
	}
}
//////////////////////////////////////////  ascending by ID /////////////////////////////////////////////////////////
void sortIdAscending(int* arr, int Size)
{
	for (int i = 0; i < Size - 1; ++i)
	{
		for (int j = 0; j < Size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swapInt(arr[j], arr[j + 1]);
			}
		}
	}
}
////////////////////////////////////////// Decending by ID /////////////////////////////////////////////////////////
void sortIdDescending(int* arr, int Size)
{
	for (int i = 0; i < Size - 1; ++i)
	{
		for (int j = 0; j < Size - 1 - i; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swapInt(arr[j], arr[j + 1]);
			}
		}
	}
}////////////////////////////////////////// Ascendiny by Name /////////////////////////////////////////////////////////
int customAStringCompare(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return (*str2 - *str1);
		}
		++str1;
		++str2;
	}
	return (*str2 - *str1);
}

void sortNameAescending(int* id, char* names[], int* quantity, int* price, int Size) {
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = 0; j < Size - 1 - i; ++j) {
			if (customAStringCompare(names[j], names[j + 1]) < 0) {
				swapInt(id[j], id[j + 1]);
				swapInt(quantity[j], quantity[j + 1]);
				swapInt(price[j], price[j + 1]);
				customAStringSwap(names[j], names[j + 1]);
			}
		}
	}
}
void customAStringSwap(char*& str1, char*& str2) {
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}
////////////////////////////////////////// Decending by name /////////////////////////////////////////////////////////
int customStringCompare(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return (*str1 - *str2);
		}
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

void sortNameDescending(int* id, char* names[], int* quantity, int* price, int Size) {
	for (int i = 0; i < Size - 1; ++i) {
		for (int j = 0; j < Size - 1 - i; ++j) {
			if (customStringCompare(names[j], names[j + 1]) < 0) {
				swapInt(id[j], id[j + 1]);
				swapInt(quantity[j], quantity[j + 1]);
				swapInt(price[j], price[j + 1]);
				customStringSwap(names[j], names[j + 1]);
			}
		}
	}
}
void customStringSwap(char*& str1, char*& str2) {
	char* temp = str1;
	str1 = str2;
	str2 = temp;
}

////////////////////////////////////////// search ind by id /////////////////////////////////////////////////////////
int searchIndexById(int* id, int Size, int searchingId)
{
	for (int i = 0; i < Size; ++i)
	{
		if (id[i] == searchingId)
		{
			return i;
		}
	}
	return -1;
}
////////////////////////////////////////// new entry /////////////////////////////////////////////////////////
void newEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size, const int entries)
{
	if (Size < entries)
	{
		cout << "Enter details for the new entry:\n";
		++Size;

		cout << "Product Id: ";
		cin >> id[Size - 1];

		while (searchIndexById(id, Size - 1, id[Size - 1]) != -1)
		{
			cout << "Id already exists. Enter a unique Id: ";
			cin >> id[Size - 1];
		}

		cout << "Product Name: ";
		cin.ignore();
		cin.getline(names[Size - 1], 50);

		cout << "Quantity: ";
		cin >> quantity[Size - 1];

		cout << "Price: ";
		cin >> price[Size - 1];

		cout << "New Item Added Successfully!\n\n";
	}
	else
	{
		cout << "Maximum entries reached. Cannot add more entries.\n\n";
	}
}
////////////////////////////////////////// delete entry /////////////////////////////////////////////////////////
void deleteEntry(int*& id, char* names[], int*& quantity, int*& price, int& Size)
{
	int deletionId;
	cout << "Enter the desired Id to delete: ";
	cin >> deletionId;

	int position = searchIndexById(id, Size, deletionId);

	if (position != -1)
	{
		for (int i = position; i < Size - 1; ++i)
		{
			id[i] = id[i + 1];
			copyArrays(names[i], names[i + 1]);
			quantity[i] = quantity[i + 1];
			price[i] = price[i + 1];
		}
		--Size;

		cout << "Item with Id " << deletionId << " deleted successfully.\n\n";
	}
	else
	{
		cout << "Item with Id " << deletionId << " not found.\n\n";
	}
}
////////////////////////////////////////// search by id /////////////////////////////////////////////////////////
void searchId(int* id, char* names[], int* quantity, int* price, int Size, int searchingId)
{
	cout << "Enter the Id to search: ";
	cin >> searchingId;

	int position = searchIndexById(id, Size, searchingId);

	if (position != -1)
	{
		cout << "Id\tPName\tQuant\tPrice\n";
		cout << id[position] << "\t" << names[position] << "\t" << quantity[position] << "\t" << price[position] << "\n";
	}
	else
	{
		cout << "Item with Id " << searchingId << " not found.\n";
	}
}
////////////////////////////////////////// search by name /////////////////////////////////////////////////////////
void searchName(int* id, char* names[], int* quantity, int* price, int Size, const char* nameToSearch)
{
	bool flag = false;
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (strcmp(names[i], nameToSearch) == 0)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
			flag = true;
		}
	}

	if (!flag)
	{
		cout << "No entry found with the given name.\n\n";
	}
}
////////////////////////////////////////// search by price /////////////////////////////////////////////////////////
void searchPrice(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (price[i] >= lower && price[i] <= upper)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// search by quantity /////////////////////////////////////////////////////////
void searchQuantity(int* id, char* names[], int* quantity, int* price, int Size, int lower, int upper)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (quantity[i] >= lower && quantity[i] <= upper)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// low stck /////////////////////////////////////////////////////////
void lowStock(int* id, char* names[], int* quantity, int* price, int Size, int stock)
{
	cout << "Id\tPName\tQuant\tPrice\n";
	for (int i = 0; i < Size; ++i)
	{
		if (quantity[i] < stock)
		{
			cout << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}
	}
}
////////////////////////////////////////// total inventory/////////////////////////////////////////////////////////
int totalInventory(int* quantity, int* price, int Size)
{
	int value = 0;
	for (int i = 0; i < Size; ++i)
	{
		value += quantity[i] * price[i];
	}
	return value;
}
////////////////////////////////////////// update quantity /////////////////////////////////////////////////////////
void updateQuantity(int* quantity, int Size, int idToUpdate, int newQuantity)
{
	int position = searchIndexById(quantity, Size, idToUpdate);
	if (position != -1)
	{
		quantity[position] = newQuantity;
		cout << "Quantity updated successfully.\n\n";
	}
	else
	{
		cout << "Id not found. Update failed.\n\n";
	}
}

////////////////////////////////////////// update price /////////////////////////////////////////////////////////
void updatePrice(int* price, int Size, int idToUpdate, int newPrice)
{
	int position = searchIndexById(price, Size, idToUpdate);
	if (position != -1)
	{
		price[position] = newPrice;
		cout << "Price updated successfully.\n\n";
	}
	else
	{
		cout << "Id not found. Update failed.\n\n";
	}
}
////////////////////////////////////////// backup /////////////////////////////////////////////////////////
void backup(int* id, char* names[], int* quantity, int* price, int Size)
{
	ofstream outFile("Inventory.txt");
	if (outFile.is_open())
	{
		for (int i = 0; i < Size; ++i)
		{
			outFile << id[i] << "\t" << names[i] << "\t" << quantity[i] << "\t" << price[i] << "\n";
		}

		cout << "Backup successful.\n\n";
		outFile.close();
	}
	else
	{
		cout << "Unable to open backup file.\n\n";
	}
}
////////////////////////////////////////// restore /////////////////////////////////////////////////////////
void restore(int*& id, char* names[], int*& quantity, int*& price, int& Size)
{
	ifstream inFile("Inventory.txt");

	if (inFile.is_open())
	{
		while (inFile >> id[Size] >> names[Size] >> quantity[Size] >> price[Size])
		{
			++Size;
		}

		cout << "Restore successful.\n\n";
		inFile.close();
	}
	else
	{
		cout << "Unable to open backup file for restore.\n\n";
	}
}
//////////////////////////////////// END ////////////////////////////////////////////////////////////////////////