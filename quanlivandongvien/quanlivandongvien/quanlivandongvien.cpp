#include<iostream>
#include<string>
using namespace std;



//class 
class athlete
{
private:
	string name;
	int age;
	string nameofsport;
	float weight;
	float hight;
public:
	athlete()
	{
		name = "";
		age = 0;
		nameofsport = "";
		weight = 0;
		hight = 0;
	}

	~athlete()
	{
		name = "";
		age = 0;
		nameofsport = "";
		weight = 0;
		hight = 0;
	}

	athlete(string name, int age, string nameofsport, float weight, float hight)
	{
		this->name = name;
		this->age = age;
		this->nameofsport = nameofsport;
		this->hight = hight;
		this->weight = weight;
	}

	friend istream& operator >> (istream& is, athlete& A)
	{
		cin.ignore();
		cout << "nhap ten van dong vien: ";
		getline(is, A.name);
		cout << "nhap tuoi van dong vien:";
		is >> A.age;
		cin.ignore();
		cout << "nhap ten mon thi dau:";
		getline(is, A.nameofsport);
		cout << "nhap can nag:";
		is >> A.weight;
		cout << "nhap chieu cao:";
		is >> A.hight;
		
		return is;
	}

	friend ostream& operator <<(ostream& os, athlete B)
	{
		os << "ten:";
		os << B.name << endl;
		os << "tuoi: " << B.age << endl;
		os << "mon:" << B.nameofsport << endl;
		os << "can nang:" << B.weight << endl;
		os << "chieu cao:" << B.hight << endl;
		return os;
	}

	friend bool operator >(athlete A, athlete B)
	{
		if (A.hight > B.hight) {
			return true;
		}
		else if (A.hight < B.hight)
		{
			return false;
		}
		else if (A.hight == B.hight)
		{
			if (A.weight > B.weight) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

};

void out(athlete* p, int n) 
{
	for (int i = 0; i < n; i++) {
		cout << "van dong vien thu " << i + 1 << endl;
		cout << p[i];
		cout << "--------------" << endl;
	}
}
void sort(athlete* p, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (p[min]>p[j])
			{
				min = j;
			}
		}
		athlete swap = p[min];
		p[min] = p[i];
		p[i] = swap;
	}
}

int main()
{
	athlete A("pham cong cuong", 21, "cau long", 56.3, 1.62);
	cout << A;
	int n;
	cout << "nhap so luong van dong vien can quan li:";
	cin >> n;
	athlete* p = new athlete[n];
	for (int i = 0; i < n; i++) {
		cout << "nhap thong tin van dong vien thu " << i+1 << endl;
		cin >> p[i];
	}
	cout << "___________________________________" << endl;
	cout << " danh sach van dong vien truoc khi sap xep:" << endl;
	out(p, n);
	cout << "___________________________________" << endl;
	cout << "danh sach van dong vien sau khi sap xep:" << endl;
	sort(p, n);
	out(p, n);
	system("pause");
	return 0;
}