
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include<sstream>  
#include <cstring>
#include <vector>
using namespace std;




//special charracter
int character(string str) {
	int k = 0, i = 0;
	while (str[i]) {
		if (str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$'
			|| str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*'
			|| str[i] == '(' || str[i] == ')' || str[i] == '-' || str[i] == '{'
			|| str[i] == '}' || str[i] == '[' || str[i] == ']' || str[i] == ':'
			|| str[i] == ';' || str[i] == '"' || str[i] == '<' || str[i] == '\''
			|| str[i] == '>' || str[i] == '.' || str[i] == '/' || str[i] == '?'
			|| str[i] == '~' || str[i] == '`' || str[i] == '\\' || str[i] == '|'
			|| str[i] == ',' || str[i] == '_' || str[i] == '+' || str[i] == '=')
		{
			k++;
			break;
		}
		i++;
	}
	return k;
}




// middle height
void height() {
	for (int i = 0; i < 10; i++)
	{
		cout << '\n';
	}
}




// diggit check
int numcheck(string sch) {
	int i = 0, k = 0, z = 0;
	string str;
	str = sch;
	k = character(str);
	while (sch[z])
	{
		if (sch[z] >= '0' && sch[z] <= '9') {
			k++; break;
		}
		if (k > 0) {
			break;
		}
		z++;
	}

	return k;
}




// letter check
int letcheck(string lch) {
	int i = 0, k = 0, z = 0;
	string str;
	str = lch;
	k = character(str);
	while (lch[z])
	{
		if ((lch[z] >= 'A' && lch[z] <= 'Z' || lch[z] >= 'a' && lch[z] <= 'z')) {
			k++; break;
		}
		if (k == 1) {
			break;
		}
		z++;
	}
	return k;
}




// middle from right
void aling() {
	for (int i = 0; i < 47; i++)
	{
		cout << " ";
	}
}




//convert  to int
int conv(string am) {
	int k = stoi(am);
	return k;
}




//getdate of bd
string date() {
	string day, month, year, lch, am, bd;
	int f, f1, f2, ff, k;
	int ld, lm, ly;
	int m, d, y;
	do {
		do {
			aling();
			cout << "Enter the day of birth: ";
			cin >> day;
			lch = day;
			f = letcheck(lch);
		} while (f != 0);

		do {
			aling();
			cout << "Enter the month of birth: ";
			cin >> month;
			lch = month;
			f1 = letcheck(lch);
		} while (f1 != 0);

		do {
			aling();
			cout << "Enter the year: ";
			cin >> year;
			lch = year;
			f2 = letcheck(lch);
		} while (f2 != 0);


		ff = 0;
		f = 0;
		am = month;
		m = conv(am);
		am = year;
		y = conv(am);
		am = day;
		d = conv(am);
		ld = 31;

		if ((m == 1) || (m == 3) || (m == 5) || (m == 7) ||
			(m == 8) || (m == 10) || (m == 12))
		{
			ld = 31;
		}

		else if ((m == 4) || (m == 6) || (m == 9) || (m == 11))
		{
			ld = 30;
		}
		else if ((m == 2) && (y % 4 == 0))
		{
			ld = 29;
		}
		else if ((m == 2) && (y % 4 != 0))
		{
			ld = 28;
		}

		if (m > 12 || m < 1) {
			ff += 1;
		}
		if (d > ld || d < 1) {
			ff += 1;
		}
		if (y < 1900 || y>2021) {
			ff += 1;
		}


	} while (ff != 0);

	bd = day + "." + month + "." + year;
	return bd;
}




//name registration
string rname() {
	string name, sch;
	int k = 1;
	while (k != 0) {
		aling();
		cout << "Enter your name: ";
		cin >> name;
		sch = name;
		k = numcheck(sch);
	}
	return name;
}




//surname registration
string rsurname() {
	string surname, sch;
	int k = 1;
	while (k != 0) {
		aling();
		cout << "Enter your surname: ";
		cin >> surname;
		sch = surname;
		k = numcheck(sch);
	}
	return surname;

}




//passport series reg
string rps() {
	string series, sch;
	int k = 1, l = 0;
	do {
		aling();
		cout << "Enter the passport series(2 letters): ";
		cin >> series;
		k = 1;
		sch = series;
		k = numcheck(sch);
		l = size(series);
	} while ((l != 2) || (k != 0));

	return series;
}




//passport number reg
string rpn() {
	string pnum, lch;
	int  l = 0, k = 1;
	do {
		aling();
		cout << "Enter the number of the passport(7 digits): ";
		cin >> pnum;
		k = 1;
		lch = pnum;
		k = letcheck(lch);
		//cout << k << endl;
		l = size(pnum);
	} while ((l != 7) || (k != 0));

	return pnum;
}




//password reg 
string rpassword() {
	string password, lch, confirm;
	int i = 2, k = 1;
	do {
		aling();
		cout << "Enter the password 4 digits: ";
		cin >> password;
		lch = password;
		k = letcheck(lch);
		i = size(password);
	} while ((i != 4) || (k != 0));

	//confirmation
	do {
		aling();
		cout << "Confirm the password: ";
		cin >> confirm;
		lch = confirm;
		k = letcheck(lch);
		i = size(confirm);
	} while ((i != 4) || (k != 0) || (confirm != password));
	return password;
}




//rewrite doc
string change(int il, string name, string surname, string bd, string passport, string password, string money, int allid)
{
	string filename, id;
	int n = 1;
	ifstream ifs("lib.txt");
	string finded, replaced;
	vector<std::string> Vec;
	int cnt = 1;
	id = to_string(il);
	replaced = id + " " + name + " " + surname + " " + bd + " " + passport + " " + password + " " + money;
	do
	{
		string tmp;
		getline(ifs, tmp);

		//cout << cnt << " " <<tmp << endl;
		if (cnt == il)
		{
			tmp = replaced;

		}
		tmp += "\n";
		++cnt;
		Vec.push_back(tmp);
	} while (!ifs.eof());
	ofstream ofs("lib.txt");
	system("cls");
	for (std::vector<std::string>::const_iterator it = Vec.begin();
		it != Vec.end(); ++it) {
		//cout << n << " " << *it << endl;
		if (n <= allid) {
			ofs << *it;
		}
		n++;
	}

	//ofs << "\n";
	//system("pause");
	ofs.close();
	ifs.close();
	return "yes";
}




//widthdraw money ---
string widthdraw(int il, int allid) {
	string res, money, width, id, name, surname, bd;
	string am, passport, password, lch;
	int mon, min, k = 1, f = 0;
	ifstream in;
	in.open("lib.txt", ios_base::in);


	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
	}
	in.close();

	system("cls");
	height();
	aling();
	cout << "Withdraw money" << endl << endl;
	aling();
	cout << "Enter e to exit" << endl;
	aling();
	cout << "Balance: " << money << endl;
	mon = stoi(money);

	do {
		aling();
		cout << "Amount money to widthdraw: ";
		cin >> width;
		lch = width;
		if (width == "e") {
			break;
		}
		else {
			k = letcheck(lch);
		}
	} while (k != 0);

	min = 0;

	if (width != "e") {
		am = width;
		min = conv(am);
	}

	//cout << endl << min << "    " << mon << endl;
	while (min > mon) {
		if (width == "e" || am == "e") {
			break;
		}
		cout << endl;
		aling();
		cout << "You can not widthdraw more money than you have!" << endl << endl;
		do {
			aling();
			cout << "Amount money to widthdraw: ";
			cin >> am;
			if (am == "e") {
				break;
			}
			lch = am;
			k = letcheck(lch);
		} while (k != 0);
		min = conv(am);

	}

	if (mon >= min) {
		mon -= min;
		f = 1;
		money = to_string(mon);
		change(il, name, surname, bd, passport, password, money, allid);

	}

	system("cls");
	if (f == 1) {
		aling();
		cout << "Money withdraw successed";
	}
	return res;
}




//add money +++
string deposit(int il, int allid) {
	string res, money, width, s, id, name, surname;
	string am, passport, password, lch, bd;
	__int64 mon, add, k = 1, f = 0;
	ifstream in;
	in.open("lib.txt", ios_base::in);


	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
	}
	in.close();

	system("cls");
	height();
	aling();
	cout << "Deposit money" << endl << endl;
	aling();
	cout << "Enter e to exit" << endl;
	aling();
	cout << "Balance: " << money << endl;
	mon = stoi(money);

	do {
		aling();
		cout << "Amount money to deposit: ";
		cin >> width;
		lch = width;
		if (width == "e") {
			break;
		}
		else {
			k = letcheck(lch);
		}
	} while (k != 0);

	if (width != "e") {
		am = width;
		add = conv(am);
	}
	else {
		add = 0;
	}

	do {
		mon += add;
		f = 1;
		money = to_string(mon);
		change(il, name, surname, bd, passport, password, money, allid);
	} while (f != 1);

	system("cls");
	if (f == 1) {
		aling();
		cout << "Money deposit successed";
	}
	return res;

}




//account information version
int accinfo(int il) {
	string e = "1";
	system("cls");
	string name, surname, passport, id, bd, password, money;

	ifstream in;
	in.open("lib.txt", ios_base::in);


	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
	}
	in.close();
	height();
	aling();
	cout << "Account information: " << endl << endl;
	aling();
	cout << "Account ID: " << id << endl;
	aling();
	cout << "Name: " << name << endl;
	aling();
	cout << "Surname: " << surname << endl;
	aling();
	cout << "Birth day: " << bd << endl;
	aling();
	cout << "Passport: " << passport << endl;

	do {
		aling();
		cout << "Enter 'e' to exit ";
		cin >> e;
	} while (e != "e");

	system("cls");
	return 0;
}




//balance version
int balance(int il) {
	string res, money, width, s, id, name, surname, passport, password, bd;
	ifstream in;
	in.open("lib.txt", ios_base::in);


	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
	}
	in.close();
	string e = "1";
	system("cls");
	height();
	aling();
	cout << "Balance of account" << endl << endl;
	aling();
	cout << "Money: " << money << endl;

	do {
		aling();
		cout << "Enter 'e' to exit ";
		cin >> e;
	} while (e != "e");

	system("cls");
	return 0;
}




// change account data
string chacc(int il, int allid) {
	string z;
	string id;
	string ser, num;
	string name, surname, passport, bd, password, money;

	ifstream in;
	in.open("lib.txt", ios_base::in);


	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
	}
	in.close();


	while (true) {
		system("cls");
		height();
		aling();
		cout << "Change personal data" << endl << endl;
		aling();
		cout << "1)Name:" << name << endl;
		aling();
		cout << "2)Surname: " << surname << endl;
		aling();
		cout << "3)Passport: " << passport << endl;
		aling();
		cout << "4)Birth year: " << bd << endl;
		aling();
		cout << "5)Password: " << password << endl;
		aling();
		cout << "Enter e to exit" << endl;
		do {
			aling();
			cout << "Enter variation: ";
			cin >> z;

			if (z == "1" || z == "2" || z == "3" || z == "4" || z == "5" || z == "e") {
				break;
			}
		} while (true);

		if (z == "e") {
			break;
		}

		if (z == "1") {
			name = rname();
			change(il, name, surname, bd, passport, password, money, allid);
			system("cls");
		}

		if (z == "2") {
			surname = rsurname();
			change(il, name, surname, bd, passport, password, money, allid);
			system("cls");
		}

		if (z == "3") {
			ser = rps();
			num = rpn();
			passport = ser + num;
			change(il, name, surname, bd, passport, password, money, allid);
			system("cls");
		}

		if (z == "4") {
			bd = date();
			change(il, name, surname, bd, passport, password, money, allid);
			system("cls");
		}
		if (z == "5") {
			password = rpassword();
			change(il, name, surname, bd, passport, password, money, allid);
			system("cls");
		}
	}
	system("cls");
	return "yes";
}




//loged version
string loged(string res, int allid)
{
	string z;
	string id, name, surname, passport, money, password, date, bd;
	ifstream in;
	in.open("lib.txt", ios_base::in);
	int il;
	il = stoi(res);

	for (int i = 0; i < il; i++)
	{
		in >> id;
		in >> name;
		in >> surname;
		in >> bd;
		in >> passport;
		in >> password;
		in >> money;
		in >> date;
	}
	in.close();
	system("cls");

	while (true) {
		//cout << res << endl;
		height();
		aling();
		cout << "Log in successed" << endl;
		aling();
		cout << "1)Balance enquiry" << endl;
		aling();
		cout << "2)Deposit amount" << endl;
		aling();
		cout << "3)Withdraw money" << endl;
		aling();
		cout << "4)Account Info" << endl;
		aling();
		cout << "5)Change personal data" << endl;
		aling();
		cout << "e to exit" << endl;

		do {
			aling();
			cout << "Enter variation: ";
			cin >> z;

			if (z == "1" || z == "2" || z == "3" || z == "4" || z == "5" || z == "e") {
				break;
			}
		} while (true);

		if (z == "e") {
			break;
		}

		if (z == "4") {
			accinfo(il);

		}

		if (z == "1") {
			balance(il);
		}

		if (z == "2") {
			deposit(il, allid);
		}

		if (z == "3") {
			widthdraw(il, allid);
		}

		if (z == "5") {
			chacc(il, allid);
		}
	}

	system("cls");
	return "hi";

}




//registration check
string regcheck(string name, string surname, string series, string pnum, int id) {
	string lname, lsurname, lpassword, res, lpassport, passport, bd;
	int  idd;
	ifstream in;
	in.open("lib.txt", ios_base::in);
	in >> idd;
	passport = series + pnum;
	for (int i = 0; i < id; i++)
	{
		//getline(in,text);
		in >> lname;
		in >> lsurname;
		in >> bd;
		in >> lpassport;
		in >> lpassword;

		//cout << name << " " << surname << " " << password << endl;
		if (name == lname && surname == lsurname && lpassport == passport)
		{
			res = "Reg";
			break;
		}

		else {
			res = "New";
		}
	}

	//cout << res;
	return res;
}




// registration
int	registration(int id) {
	string password, name, surname, confirm, series;
	string pnum, sch, lch, res, day, month, year, bd, am;
	int l = 0, i = 0, money = 0, z = 0, pro;
	int f, f1, f2, s = 0;

	ofstream fout;
	fout.open("lib.txt", ios_base::app);
	//
	id += 1;

	system("cls");
	height();
	aling();
	cout << "Regestration" << endl << endl;
	// Name
	name = rname();



	// Surname
	surname = rsurname();

	// bd date	
	bd = date();

	// Passport Series
	series = rps();


	// PassportNumber
	pnum = rpn();

	// password;
	password = rpassword();


	res = regcheck(name, surname, series, pnum, id);


	if (res == "Reg") {

		system("cls");
		aling();
		cout << "You already have been registered" << endl;

	}
	if (res == "New") {
		for (int i = 0; i < id + 1; i++)
		{
			if (i == id) {
				fout << id << " " << name << " " << surname << " " << bd << " " << series << pnum << " " << password << " " << 0 << std::endl;
				system("cls");
				aling();
				cout << "Registration completed" << endl;
			}
		}

	}


	fout.close();
	return id;
}




//login check
string checking(string lname, string lsurname, string lpassword, int id) {
	string name, surname, res, money, password, text, passport, bd;
	string  idd;
	ifstream in;
	in.open("lib.txt", ios_base::in);

	for (int i = 0; i < id; i++)
	{
		in >> idd;
		//cout <<"id : "<<idd << endl;
		//getline(in,text);
		in >> name;
		//cout << "name:" <<name << endl;
		in >> surname;
		in >> bd;
		//cout <<"sur" <<  surname << endl;
		in >> passport;
		//cout << "pass "<< passport << endl;
		in >> password;
		in >> money;

		//cout << name << " " << surname << " " << password << endl;
		if (name == lname && surname == lsurname && password == lpassword)
		{
			res = idd;
			break;
		}

		else {
			res = "No";
		}

	}

	in.close();
	//system("pause");
	return res;
}




//login
void login(int id) {
	string lname, lsurname, lpassword, answer, res, sch, lch;
	int l = 0, k = 1, allid;
	int iz = id;
	system("cls");
	height();
	aling();
	cout << "Log in " << endl << endl;
	while (k != 0) {
		aling();
		cout << "Enter your name: ";
		cin >> lname;
		sch = lname;
		k = numcheck(sch);
	}

	k = 1;

	while (k != 0) {
		aling();
		cout << "Enter your surname: ";
		cin >> lsurname;
		sch = lsurname;
		k = numcheck(sch);
	}

	k = 1;

	while (l != 4 || k != 0) {
		aling();
		cout << "Enter the password 4 digits: ";
		cin >> lpassword;
		l = size(lpassword);
		lch = lpassword;
		k = letcheck(lch);
	}

	cout << endl;

	//cout << checking(lname, lsurname, lpassword, id) << endl << endl;
	res = checking(lname, lsurname, lpassword, id);
	if (res == "No") {
		system("cls");
		aling();
		cout << "No matches found" << endl;

	}

	else {
		system("cls");
		aling();
		allid = id;
		loged(res, allid);
	}

}




// main
int main() {
	system("cls");
	int id = 0, l = 0, i = 0, k = 0;
	string x1;
	string line, lch;
	ifstream in;
	in.open("lib.txt");
	while (getline(in, line)) {
		if (empty(line)) {
			break;
		}
		l += 1;
	}
	id = l;
	in.close();
	cout << id;

	while (true) {
		height();
		aling();
		cout << "Vens1k International Bank Official UZ" << endl << endl;
		aling();
		cout << "1) Registration" << endl;
		aling();
		cout << "2) Log in" << endl;
		aling();
		cout << "Enter e to exit" << endl;
		do {
			aling();
			cout << "Enter chosen variation: ";
			cin >> x1;
			cout << endl;
			if (x1 == "1" || x1 == "2" || x1 == "e") {
				break;
			}
		} while (true);

		if (x1 == "e") {
			break;
		}
		if (x1 == "1")
		{
			id = registration(id);

		}
		if (x1 == "2") {
			login(id);

		}



	}

	return 0;
}

