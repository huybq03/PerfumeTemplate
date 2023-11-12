 #include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
ifstream cinAdmin;
ifstream cinBook;
ifstream cinPhieu;
ifstream cinUser;
ofstream coutAdmin;
ofstream coutBook;
ofstream coutPhieu;
ofstream coutUser;
void setposition(int x, int y)
{
	CursorPosition.X=x;
	CursorPosition.Y=y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotocolor(int x,int y,string s,int mau)
{
	setposition(x,y);
	textcolor(mau);
	cout << s;
	textcolor(7);
}
void textmau(int x,int y,int mau)
{
	setposition(x,y);
	textcolor(mau);
	textcolor(7);
}
void write(int x, int y, string z)
{
	setposition(x, y);
	cout << z;
}
class Sach{
	public:
		string masach;
		string tensach;
		string tacgia;
		string nhaxuatban;
		float giaban;
		long nam;
		long sotrang;
		string ngaynhap;
		long tinhtrangsach;
	public:
		void operator = (Sach s)
		{
			masach=s.masach;
			tensach=s.tensach;
			tacgia=s.tacgia;
			nhaxuatban=s.nhaxuatban;
			giaban=s.giaban;
			nam=s.nam;
			sotrang=s.sotrang;
			ngaynhap=s.ngaynhap;
			tinhtrangsach=s.tinhtrangsach;
		}
		~Sach(){}
		friend istream& operator >> (istream& is,Sach& s)
		{
			getline(is,s.masach);
			getline(is,s.tensach);
			getline(is,s.tacgia);
			getline(is,s.nhaxuatban);
			is >> s.giaban;
			is >> s.nam;
			is >> s.sotrang;
			is.ignore();
			getline(is,s.ngaynhap);
			is >> s.tinhtrangsach;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,Sach s)
		{
			os << s.masach << '\n' << s.tensach << '\n' << s.tacgia << '\n' << s.nhaxuatban << '\n' << s.giaban << '\n' << s.nam << '\n' << s.sotrang << '\n' << s.ngaynhap << '\n' << s.tinhtrangsach << '\n';
			return os;
		}
		bool operator ==(Sach s)
		{
			return (masach==s.masach);
		}
};
class Phieu{
	public:
		long sophieu;
		string mabandoc;
		string masach;
		string ngaymuon;
		string ngaytra;
		long tinhtrang;
	public:
		void operator = (Phieu p)
		{
			sophieu=p.sophieu;
			mabandoc=p.mabandoc;
			masach=p.masach;
			ngaymuon=p.ngaymuon;
			tinhtrang=p.tinhtrang;
		}
		~Phieu(){}
		friend istream& operator >> (istream& is,Phieu& p)
		{
			is >> p.sophieu;
			is.ignore();
			getline(is,p.mabandoc);
			getline(is,p.masach);
			getline(is,p.ngaymuon);
			getline(is,p.ngaytra);
			is >> p.tinhtrang;
			is.ignore();
			return is;
		}
		friend ostream& operator << (ostream& os,Phieu p)
		{
			os << p.sophieu << '\n' << p.mabandoc << '\n' << p.masach << '\n' << p.ngaymuon << '\n' << p.ngaytra << '\n' << p.tinhtrang << '\n';
			return os;
		}
};
class Admin{
	string user;
	string password;
	public:
		string getuser(){return user;}
		string getpassword(){return password;} 
		bool operator == (Admin a)
		{
			if (user==a.user && password==a.password)
				return true;
			return false;
		}
		void operator = (Admin a)
		{
			user=a.user;
			password=a.password;
		}
		Admin(string a,string b)
		{
			user=a;
			password=b;
		}
		~Admin(){}
		friend istream& operator >> (istream& is,Admin& ad)
		{
			setposition(101,20);is >> ad.user;
			is >> ad.password;
			return is;
		}
		friend ostream& operator << (ostream& os,Admin ad)
		{
			os << ad.user << '\n' << ad.password;
			return os;
		}
};
class User{
	public:
		string ma;
		string hoten;
		string ngaydangky;
	public:
		void operator = (User us)
		{
			ma=us.ma;
			hoten=us.hoten;
			ngaydangky=us.ngaydangky;
		}
		~User(){}
		friend istream& operator >> (istream& is,User& us)
		{
			getline(is,us.ma);
			getline(is,us.hoten);
			getline(is,us.ngaydangky);
			return is;
		}
};
vector<Admin> Ad;
list<Sach> Sa;
list<Phieu> Ph;
list<User> Us;
void savedatasach()
{
	coutBook.open("Sach.txt",ios_base::out);
	for (auto it=Sa.begin();it!=Sa.end();it++)
		coutBook << *it;
	coutBook.close();
}
void savedataphieu()
{
	coutPhieu.open("PhieuMuon.txt",ios_base::out);
	for (auto it=Ph.begin();it!=Ph.end();it++)
		coutPhieu << *it;
	coutPhieu.close();
}
void login()
{
	textcolor(14);
	setposition(50,10);cout << "* * * * * * * * * * * * * * * * *";
	setposition(50,11); cout << "*";
	textcolor(10);
	setposition(57,11);cout << "DANG NHAP HE THONG";
	textcolor(14);
	setposition(82,11); cout << "*";
	setposition(50,12);cout << "* * * * * * * * * * * * * * * * *";
}
int ddem=1;
void DATA()
{
	Admin A({"",""});
	User U;
	cinBook.open("Sach.txt",ios_base::in);
	cinAdmin.open("Admin.txt",ios_base::in);
	Sach S;
	cinPhieu.open("PhieuMuon.txt",ios_base::in);
	cinUser.open("User.txt",ios_base::in);
	while(!cinAdmin.eof())
	{
		cinAdmin >> A;
		Ad.push_back(A);
	}
	while(!cinBook.eof())
	{
		cinBook >> S;
		if (S.masach=="")
			continue;
		Sa.push_back(S);
	}
	while(!cinPhieu.eof())
	{
		Phieu P({0,"","","","",-1});
		cinPhieu >> P;
		if (P.mabandoc=="" && P.masach=="" && P.ngaytra=="" && P.tinhtrang==-1)
			continue;
		ddem++;
		Ph.push_back(P);
	}
	while(!cinUser.eof())
	{
		cinUser >> U;
		Us.push_back(U);
	}
	cinAdmin.close();
	cinBook.close();
	cinPhieu.close();
	cinUser.close();
}
string input_password(int x,int y)
{
	string tmp;
	char a;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (8==a && !tmp.empty())
		{
			tmp.resize(tmp.size()-1);
			setposition(x-1,y);cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ')
		{
			setposition(x,y);cout << "*";
			tmp.push_back(a);
			x++;
		}
		if (a==0x1B)
			exit(0);
		if ('\b'==a && !tmp.empty())
			tmp.resize(tmp.size()-1);
	}
	while (13!=a);
		return tmp;
}
string input(int x,int y,int& dem)
{
	string tmp;
	char a;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((isalpha(a) || isalnum(a) || isprint(a)) && a != ' ')
		{
			setposition(x,y);cout << a;
			tmp.push_back(a);
			x++;
		}
		if (a==0x1B)
			exit(0);
	}
	while (13!=a);
		return tmp;
}
string inputstringtacgia(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
	do
	{
		a=_getch();
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if (((b>=65 && b<=90) || (b>=97 && b<=122) || b==' '))
				goto hoi;
			else
				so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || a==' ')
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		else
		{
			if (a!=13)
			{
				if (a==8)
					continue;
				so++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
string inputstringtensach(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;	
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if (((b>=65 && b<=90) || (b>=97 && b<=122) || (b>='0' && b<='9') || b==' ' || b=='&' || b=='-'))
				goto hoi;
			else
				so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || (a>='0' && a<='9') || a==' ' || a=='&' || a=='-')
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		else
		{
			if (a!=13)
			{
				if (a==8)
					continue;
				so++;
				tmp.push_back(a);
				setposition(x,y); cout << a;
				x++;
			}
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
string inputstringmasach(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=65 && b<=90) || (b>=97 && b<=122) || (b>='0' && b<='9'))
				goto hoi;
			so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if (a==' ')
		{
			so++;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if ((a>=65 && a<=90) || (a>=97 && a<=122) || (a>='0' && a<='9'))
		{
			tmp.push_back(a);
			setposition(x,y); cout << a;
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			so++;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0)
			return tmp;
		return "";
	}
}
template <class T>
T chuyenso(string tmp)
{
	stringstream ss(tmp);
	T k;
	ss >> k;
	return k;
}
float inputsothuc(int x,int y,int& dem)
{
	string tmp="";
	char a;
	char b;
	int so=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=48 && b<=57) || b == '.')
				goto hoi;
			else
				so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=48 && a<=57) || a == '.')
		{
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			so++;
		}
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0 && tmp.size()<=10)
			return chuyenso<float>(tmp);
		else
			return -1;
	}
}
long inputsonguyen(int x,int y,int& dem)
{
	string tmp="";
	char a,b;
	int so=0;
	do
	{
		a=_getch();
		if (tmp.size()>100 && a!=8)
			continue;
		if (a==8 && !tmp.empty())
		{
			b=tmp[tmp.size()-1];
			if ((b>=48 && b<=57))
				goto hoi;
			else
				so--;
			hoi:
			tmp.resize(tmp.size()-1);
			setposition(x-1,y); cout << char(32);
			x--;
			setposition(x,y);
			continue;
		}
		if ((a>=48 && a<=57))
		{
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			continue;
		}
		if (a!=13)
		{
			if (a==8)
				continue;
			setposition(x,y); cout << a;
			tmp.push_back(a);
			x++;
			so++;
		}
		
	}
	while (13!=a);
	{
		dem+=so;
		if (so==0 && tmp.size()<=10)
			return chuyenso<long>(tmp);
		else
			return -1;
	}
}
void ham(int n,int k)
{
	int m=20;
	textcolor(14);
	setposition(106,m); cout << "<-";
	setposition(106,m+1); cout << "  ";
	int null=0;
	while (true)
	{
		textcolor(11);
		//setposition(105,k); cout << "[BACK]";
		gotocolor(110,m,"[BACK]",11);
		//setposition(105,n); cout << "[EXIT]";
		gotocolor(110,m+1,"[EXIT]",11);
		textcolor(14);
		system("pause>nul");
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (k!=n)
			{
				setposition(106,m); cout << "  ";
				k++;
				setposition(106,m+1); cout << "X";
				null++;	
			}
			continue;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (k!=n-1)
			{
				setposition(106,m); cout << "<-";
				k--;
				setposition(106,m+1); cout << "  ";
				null--;
			}
			continue;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			textcolor(7);
			if (null==0)
				return;
			if (null==1)
			{
				system("cls");
				exit(0);
			}
		}
	}
}
bool checkuser(string a,string b)
{
	for (int i=0;i<Ad.size();i++)
		if (a==Ad[i].getuser() && b==Ad[i].getpassword())
			return true;
	return false;
}
void run()
{
	int so=3;
	int chay=0;
	while (so!=0)
	{
		int dem=0;
		string U_ser;
		string P_ass;
		login();
		setposition(85,19);
		if (chay!=0)
		{
			textcolor(11);
			cout << "User hoac Password sai, Ban con " << so << " luot nhap";
		}
		textcolor(2);
		setposition(55,15); cout << "User:";
		setposition(55,17); cout << "Password:";
		setposition(60,15); 
		textcolor(15);
		U_ser=input(60,15,dem);
		setposition(65,17);
		P_ass=input_password(64,17);
		if (checkuser(U_ser,P_ass))
			return;
		chay++;
		so--;
		system("cls");
	}
	exit(0);
}
void xuatsach(Sach tmp,int n)
{
	n=n-9;
	textcolor(15);
	setposition(1,n); cout << tmp.masach;
	setposition(9,n); cout << tmp.tensach;
	setposition(37,n); cout << tmp.tacgia;
	setposition(57,n); cout << tmp.nhaxuatban;
	setposition(70,n); cout << tmp.giaban;
	setposition(83,n); cout << tmp.nam;
	setposition(95,n); cout << tmp.sotrang;
	setposition(104,n); cout << tmp.ngaynhap;
	setposition(118,n); cout<<tmp.tinhtrangsach;
	textcolor(7);
}
void inforsach(int& n)
{
	textcolor(7);
	gotocolor(1,n-10,"MA SACH",14);
	gotocolor(15,n-10,"TEN SACH",14);
	gotocolor(40,n-10,"TAC GIA",14);
	gotocolor(57,n-10,"NHA XUAT BAN",14);
	gotocolor(70,n-10,"GIA BAN",14);
	gotocolor(80,n-10,"NAM PHAT HANH",14);
	gotocolor(95,n-10,"SO TRANG",14);
	gotocolor(104,n-10,"NGAY NHAP KHO",14);
	gotocolor(118,n-10,"TINH TRANG SACH",14);
	int chay=n-8;
	for (int i=0;i<=Sa.size();i++)
	{
		if (i==Sa.size())
		{
			if (!Sa.empty())
				for (int j=0;j<=132;j+=2)
					write(j,chay+(Sa.size()*2)+1,"--");
			break;
		}	
		/*for (int j=0;j<=118;j++){	//DO BỊ DƯ NHÌN KHÔNG ĐẸP
			write(j,chay,"-");
		}*/	
	}
	int so=n-10;
	for (int i=0;i<=(Sa.size()+1)*2;i++)
	{
		/*if (i==1)
		{
			so++;
			continue;
		}*/
		write(0,so,"|");
		write(8,so,"|");
		write(36,so,"|");
		write(56,so,"|");
		write(69,so,"|");
		write(79,so,"|");
		write(94,so,"|");
		write(103,so,"|");
		write(117,so,"|");
		so++;
	}
		n+=2;
         for (list<Sach>::iterator it=Sa.begin();it!=Sa.end();it++){
		xuatsach(*it,n);
		n=n+2;
	}
	n+=3;
}
void xuatuser(int n,User us)
{
	textcolor(15);
	setposition(1,n); cout << us.ma;
	setposition(10,n); cout << us.hoten;
	setposition(49,n); cout << us.ngaydangky;
	textcolor(7);
}
void inforuser(int& n)
{ 
     n=n+4;
	textcolor(15);
	gotocolor(1,n,"MA USER",14);
	gotocolor(10,n,"HO TEN",14);
	gotocolor(47,n,"NGAY DANG KY",14);
	textcolor(3);
	int so=n;
	for (int i=0;i<=Us.size()+2;i++)
	{
		/*if (i==1)
		{
			so++;
			continue;
		}*/
		
		write(0,so,"|");
		write(9,so,"|");
		write(45,so,"|");
		write(61,so,"|");
		so++;
	}
	int chay=n-2;
	/*for (int i=1;i<=3;i++)
	{
		if (i==3)
		{
			if (!Us.empty())
				for (int j=0;j<=112;j+=2)
					write(j,((chay+Us.size()+2)*2)+1,"--");
			break;
		}	
		chay+=i;
		//for (int j=15;j<=199;j+=2)
		//	write(j,chay,"--");
	}*/
	n+=1;
	for (list<User>::iterator it=Us.begin();it!=Us.end();it++)
		xuatuser(n++,*it);
	n+=3;
}
void hienthi()
{
	int n=10;
	system("cls");
	inforsach(n);
	ham(n,n-1);
}
bool checksach(Sach tmp)
{
	for (list<Sach>::iterator i=Sa.begin();i!=Sa.end();i++)
		if (*i==tmp)
			return true;
	return false;
}
bool loinhapsach(Sach tmp)
{
	if (tmp.giaban==-1 || tmp.nam==-1 || tmp.sotrang==-1)
		return true;
	return false;
}
string setstring(int x,int y,int& dem)
{
	string chay=input(x,y,dem);
	return chay;
}
void themsach()
{
	system("cls");
	Sach tmp({"","","","",-1,-1,-1});
	textcolor(15);
	setposition(15,23); cout << "MA SACH:";
	setposition(15,24); cout << "TEN SACH:";
	setposition(15,25); cout << "TAC GIA:";
	setposition(15,26); cout << "NHA XUAT BAN:";
	setposition(15,27); cout << "GIA BAN:";
	setposition(15,28); cout << "NAM PHAT HANH:";
	setposition(15,29); cout << "SO TRANG:";
	int n=17;
	textcolor(11);
	setposition(45,n-14); cout << "THONG TIN SACH";
	inforsach(n);
	textcolor(6);
	int dem=0;
	setposition(23,23);tmp.masach=inputstringmasach(23,23,dem);
	setposition(24,24);tmp.tensach=inputstringtensach(24,24,dem);
	setposition(23,25);tmp.tacgia=inputstringtacgia(23,25,dem);
	setposition(28,26);tmp.nhaxuatban=inputstringtacgia(28,26,dem);
	setposition(23,27);tmp.giaban=inputsothuc(23,27,dem);
	setposition(29,28);tmp.nam=inputsonguyen(29,28,dem);
	setposition(24,29);tmp.sotrang=inputsonguyen(24,29,dem);
	tmp.tinhtrangsach=0;
	time_t now = time(0);
	tm *ltm=localtime(&now);
	int day=ltm->tm_mday;
	int month=ltm->tm_mon;
	month++;
	int nam=ltm->tm_year;
	nam+=1900;
	tmp.ngaynhap=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
	textcolor(14);
	if (dem!=0)
	{
		setposition(100,25);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	if (checksach(tmp))
	{
		setposition(100,25);
		cout << "SACH DA TON TAI!";
	}
	else
	{
		setposition(100,25);
		cout << "THEM SACH THANH CONG!";
		Sa.push_back(tmp);
		savedatasach();
	}
	hoi:
	ham(n,n-1);
}
void kiemtramasach(string s)
{
	Sach k;
	textcolor(14);
	for (auto i=Sa.begin();i!=Sa.end();i++)
	{
		k=*i;
		if (k.masach==s)
		{
			if (k.tinhtrangsach==0)
			{
				Sa.erase(i);
				setposition(100,5); cout << "XOA SACH THANH CONG";
				savedatasach();
				return;
			}
			setposition(100,5); cout << "SACH DANG DUOC MUON";
			return;	
		}
	}	
	setposition(100,5); cout << "SACH KHONG TON TAI";
}
void xoasach()
{
	system("cls");
	string s;
	textcolor(14);
	setposition(15,20); cout << "NHAP MA SACH CAN XOA:";
	textcolor(11);
	int n=11;
	setposition(30,1); cout << "THONG TIN SACH";
	inforsach(n=n+2);
	textcolor(6);
	int dem=0;
	setposition(36,20);s=inputstringmasach(36,20,dem);
	if (dem!=0)
	{
		setposition(100,5);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	kiemtramasach(s);
	hoi:
	ham(n,n-1);
}
void quanlysach()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(56,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(60,16); cout << "->";
		setposition(60,17); cout << " ";
		setposition(60,18); cout << " ";
		setposition(60,19); cout << " ";
		while(true)
		{
			textcolor(15);
			setposition(62,16); cout << "HIEN THI THONG TIN SACH";
			setposition(62,17); cout << "THEM SACH";
			setposition(62,18); cout << "XOA SACH";
			setposition(62,19); cout << "[BACK]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(60,k); cout << "  ";
					k++;
					setposition(60,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(60,k); cout << "  ";
					k--;
					setposition(60,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				textcolor(7);
				if (null==0)
				{
					hienthi();
					break;
				}
				if (null==1)
				{
					themsach();
					break;
				}
				if (null==2)
				{
					xoasach();
					break;
				}
				if (null==3)
					return;
			}
		}
	}
}

void xuatphieu(Phieu ph,int n)
{
	n=n-11;
	setposition(7,n); cout << ph.sophieu;
	setposition(18,n); cout << ph.mabandoc;
	setposition(30,n); cout << ph.masach;
	setposition(40,n); cout << ph.ngaymuon;
	setposition(54,n); cout << ph.ngaytra;
	setposition(75,n); cout << ph.tinhtrang;
}
void inforphieu(int& n)
{
	textcolor(14);
	setposition(1,n-9); cout << "SO PHIEU MUON";
	setposition(17,n-9); cout << "MA BAN DOC";
	setposition(30,n-9); cout << "MA SACH";
	setposition(40,n-9); cout << "NGAY MUON";
	setposition(52,n-9); cout << "NGAY PHAI TRA";
	setposition(67,n-9); cout << "TINH TRANG PHIEU MUON";
	textcolor(9);
	int so=n-9;
	for (int i=0;i<=((Ph.size())*2)+1;i++)
	{
		/*if (i==1)
		{
			so++;
			continue;
		}*/
		write(0,so,"|");
		write(15,so,"|");
		write(28,so,"|");
		write(38,so,"|");
		write(50,so,"|");
		write(66,so,"|");
		write(89,so,"|");
		//write(200,so,"|");
		so++;
	}
		int chay=n-7;
		for (int i=0;i<=Ph.size();i++)
	{
		if (i==Ph.size())
		{
			if (!Ph.size())
				for (int j=0;j<=100;j+=2){
					write(j,chay+(Ph.size()*2)+1,"--");
				}
			break;
		}	
		/*for (int j=0;j<=118;j++){	//DO BỊ DƯ NHÌN KHÔNG ĐẸP
			write(j,chay,"-");
		}*/	
	}
	n+=2;
	textcolor(15);
	for (list<Phieu>::iterator i=Ph.begin();i!=Ph.end();i++)
		xuatphieu(*i,n=n+2);
	n+=3;
}
void thongtin()
{
	system("cls");
	int n=10;
	inforphieu(n);
	ham(n,n-1);
}
int so=0;
void checkbook(Sach pp,string a)
{
	if (pp.masach==a)
	{
		if (pp.tinhtrangsach==0)
			so=1;
		so++;
	}	
}
bool checkbandoc(User us,string a)
{
	if (us.ma==a)
		return true;
	return false;
}
void truyvet(Sach& sa,string a)
{
	Phieu tmp;
	for (list<User>::iterator i=Us.begin();i!=Us.end();i++)
	{
		if (checkbandoc(*i,a))
		{
			so++;
			sa.tinhtrangsach=ddem;
			tmp.sophieu=ddem;
			tmp.mabandoc=a;
			tmp.masach=sa.masach;
			time_t now = time(0);
			tm *ltm=localtime(&now);
			int day=ltm->tm_mday;
			int month=ltm->tm_mon;
			month++;
			int nam=ltm->tm_year;
			nam+=1900;
			tmp.ngaymuon=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
			if (month==2)
			{
				if (nam%4==0 && nam%400==0)
				{
					day+=7;
					if (day>29)
					{
						day-=29;
						month++;
					}
				}
				else
				{
					day+=7;
					if (day>28)
					{
						day-=28;
						month++;
					}
				}
			}
			else
			{
				if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
				{
					day+=7;
					if (day>31)
					{
						day-=31;
						month++;
						if (month>12)
						{
							nam++;
							month-=12;
						}
						else
							month++;
					}
				}
				else
				{
					day+=7;
					if (day>30)
					{
						day-=30;
						month++;
					}
				}
			}
			tmp.ngaytra=to_string(day)+"/"+to_string(month)+"/"+to_string(nam);
			tmp.tinhtrang=1;
			ddem++;
			Ph.push_back(tmp);
			savedataphieu();
			savedatasach();
			return;
		}
	}
}
void muonsach()
{
	system("cls");
	textcolor(15);
	setposition(100,13); cout << "MA SACH:";
	setposition(100,14); cout << "MA BAN DOC:";
	textcolor(6);
	string book="";
	string bn="";
	int n=13;
	textcolor(11);
	setposition(30,0);cout << "THONG TIN SACH";
	inforsach(n=n-2);
	textcolor(11);
	n++;
 	setposition(30,n-11);cout << "THONG TIN PHIEU";
 	n--;
	inforphieu(n);
	textcolor(11);
	n++;
	setposition(30,n-12);cout << "THONG TIN USER";
	n=n-14;
	inforuser(n);
	int dem=0;
	so=0;
	textcolor(6);
	setposition(108,13);book=inputstringmasach(108,13,dem);
	setposition(111,14);bn=inputstringmasach(111,14,dem);
	if (dem!=0)
	{
		setposition(100,15);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<Sach>::iterator i=Sa.begin();i!=Sa.end();i++)
	{
		checkbook(*i,book);
		if (so==2)
		{
			truyvet(*i,bn);
			break;
		}
		if (so==1)
			break;
		so=0;
	}
	textcolor(14);
	if (so==0)
	{
		setposition(100,15);
		cout << "SACH KHONG TON TAI";
	}
	if (so==1)
	{
		setposition(100,15);
		cout << "SACH DANG DUOC MUON";
	}
	if (so==2)
	{
		setposition(100,15);
		cout << "MA BAN DOC KHONG TON TAI";
	}
	if (so==3)
	{
		setposition(100,15);
		cout << "SACH MUON THANH CONG";
	}
	hoi:
	ham(n,n-1);
}
bool timsach(Sach& tmp,string a)
{
	if (tmp.masach==a)
	{
		tmp.tinhtrangsach=0;
		return true;
	}
	return false;
}
bool checkphieumuon(Phieu& tmp,int n)
{
	so=0;
	if (n==tmp.sophieu)
	{
		so=1;
		if (tmp.tinhtrang!=0)
		{
			tmp.tinhtrang=0;
			for (auto i=Sa.begin();i!=Sa.end();i++)
				if (timsach(*i,tmp.masach))
				{
					savedataphieu();
					savedatasach();
					break;
				}
			so=2;
		}
		return true;	
	}
	return false;
}
void trasach()
{
	system("cls");
	textcolor(15);
	setposition(100,15); cout << "SO PHIEU MUON:";
	textcolor(6);
	string book="";
	string bn="";
	int n=11;
	textcolor(11);
	setposition(30,0);cout << "THONG TIN SACH";
	inforsach(n);
	textcolor(11);
	n++;
 	setposition(15,n-10);cout << "THONG TIN PHIEU";
	inforphieu(n);
	textcolor(6);
	long tmp;
	int dem=0;
	setposition(114,15);tmp=inputsonguyen(114,15,dem);
	if (dem!=0)
	{
		setposition(100,15);
		cout << "LOI NHAP SAI HE THONG!";
		goto hoi;
	}
	for (list<Phieu>::iterator i=Ph.begin();i!=Ph.end();i++)
		if (checkphieumuon(*i,tmp))
			break;
	textcolor(14);
	if (so==0)
	{
		setposition(100,16);
		cout << "PHIEU MUON KHONG TON TAI!";
	}
	if (so==1)
	{
		setposition(100,16);
		cout << "KHONG THE TRA SACH!";
	}
	if (so==2)
	{
		setposition(100,16);
		cout << "TRA SACH THANH CONG!";
	}
	textcolor(14);
	hoi:
	ham(n,n-1);
}
void quanlyphieumuon()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(56,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(60,16); cout << "->";
		setposition(60,17); cout << " ";
		setposition(60,18); cout << " ";
		setposition(60,19); cout << " ";
		while(true)
		{
			textcolor(15);
			setposition(62,16); cout << "THONG TIN PHIEU MUON";
			setposition(62,17); cout << "MUON SACH";
			setposition(62,18); cout << "TRA SACH";
			setposition(62,19); cout << "[BACK]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(60,k); cout << "  ";
					k++;
					setposition(60,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(60,k); cout << "  ";
					k--;
					setposition(60,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (null==0)
				{
					thongtin();
					break;
				}
				if (null==1)
				{
					muonsach();
					break;
				}
				if (null==2)
				{
					trasach();
					break;
				}
				if (null==3)
					return;
			}
		}
	}
}
bool menu()
{
	while(true)
	{
		system("cls");
		int null=0;
		int k=16;
		textcolor(11);
		setposition(56,15); cout << "*******CAC SU LUA CHON*******";
		textcolor(14);
		setposition(60,16); cout << "->";
		setposition(60,17); cout << " ";
		setposition(60,18); cout << " ";
		setposition(60,19); cout << " ";
		while (true)
		{
		//	setposition(90,16); cout << ;
			textcolor(15);
			setposition(62,16); cout << "QUAN LY SACH";
			setposition(62,17); cout << "QUAN LY PHIEU MUON";
			setposition(62,18); cout << "[Dang Xuat]";
			setposition(62,19); cout << "[EXIT]";
			textcolor(14);
			system("pause>nul");
			if (GetAsyncKeyState(VK_DOWN))
			{
				if (k!=19)
				{
					setposition(60,k); cout << "  ";
					k++;
					setposition(60,k); cout << "->";
					null++;	
				}
				continue;
			}
			if (GetAsyncKeyState(VK_UP))
			{
				if (k!=16)
				{
					setposition(60,k); cout << "  ";
					k--;
					setposition(60,k); cout << "->";
					null--;
				}
				continue;
			}
			if (GetAsyncKeyState(VK_RETURN))
			{
				if (null==0)
				{
					quanlysach();
					break;
				}
				if (null==1)
				{
					quanlyphieumuon();
					break;
				}
				if (null==2)
					return false;
				if (null==3)
				{
					system("cls");
					exit(0);
				}
			}
		}
	}
	return true;
}
int main()
{
	DATA();
	for(;;)
	{
		run();
		system("cls");
		if (menu())
			return 0;
		system("cls");
	}
	return 0;
}
