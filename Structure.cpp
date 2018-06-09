//============================================================================
// Name        : Structure.cpp
// Author      : Usama Zafar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <string.h>
#include <iostream>
using namespace std;



struct Student//Q1
{
private:
	int rollNo;
	char * name;
	string city;
	string phone;
public:
	void Initialize()//Q2
	{
		rollNo=0;
		name = new char[25];
		city ="";
		phone="";
	}
	void Destroy()//Q3
	{
		delete [] name;
	}
	bool setRollNo(int r)
	{
		if(rollNo>=1001)
				{
					rollNo=r;
					return true;
				}
		else
		{
			return false;
		}
	}
	int getRollNo()
	{
		return rollNo;
	}
	bool setName(char* n)
	{
		if(strlen(n)>4)
		{
			name=n;
			return true;
		}
		else
		{
			return false;
		}

	}
	char* getName()
	{
		return name;
	}
	bool setCity(string c)
	{
		if(city!="")
		{
			city=c;
			return true;
		}
		else
		{
			return false;
		}

	}
	string getCity()
	{
		return city;
	}
	bool setPhone(string c)
	{
		if(phone!="")
		{
			phone=c;
			return true;
		}
		else
		{
			return false;
		}
	}
	string getPhone()
	{
		return phone;
	}

};
struct Employee//Q7
{
private:
	int empNo;
	long basicPay;
	long houseRent ;
	long medicalAllow ;
	long  conveyanceAllow ;
	long netPay;
public:
	void setBasicPay(int bp)
	{
		basicPay=bp;
	}
	int getBasicPay()
	{
		return basicPay;
	}
	void setEmpNo(int e)
	{
		empNo=e;
	}
	int getEmpNo()
	{
		return basicPay;
	}
	void calculateHouseRent()//Q8
	{
		houseRent=(0.45*basicPay);
	}
	void calculateMedicalAllowance()
	{
		medicalAllow=(0.05*basicPay);
	}
	void calculateConveyanceAllowance()
	{
		conveyanceAllow=(0.1*basicPay);
	}
	void calculateNetPay()
	{
		netPay=basicPay + houseRent + medicalAllow + conveyanceAllow ;
	}
	long gethouseRent()
	{
		return houseRent;
	}
	long getMedicalAllowance()
	{
		return medicalAllow;
	}
	long getConveyanceAllowance()
	{
		return conveyanceAllow;
	}
	long getNetPay()
	{
		return netPay;
	}
};
struct accountCategory
{
private:
	int Id;
	string Name;
public:
	void setId(int ID)
		{
			Id=ID;
		}
	void setName(string name)
			{
		Name=name;
			}
};
struct BankAccount
{
private:
	string depositorName;
	string accountNumber;
	accountCategory accountCat;
	long Balance;
public:

	void Initilaize(string dp, string an, int acountTypeId, string accountTypeName, long balance)
	{
		depositorName=dp;
		accountNumber=an;
		accountCat.setId(acountTypeId);
		accountCat.setName(accountTypeName);
		Balance=balance;
	}
	bool depositAmount(long amountToDeposite)
{
		if(amountToDeposite>0)
		{
			Balance=amountToDeposite;
			return true;
		}
		else
		{
			return false;
		}
}
bool withdrawAmount(long amountToWithdraw)
{
	if(Balance>=amountToWithdraw)
	{
		Balance-=amountToWithdraw;
		return true;
	}
	else
	{
		return false;
	}
}

long getAmount()
{
	return Balance;
}
};
struct CourseRegistrations
{
private:
	string Coursecode;
	string CourseTitle;
	int CreditHours;
	char Section;
	int RepeatCount;
public:
	int  getCreditHours()
		{
			return CreditHours;
		}
	string  getCoursecode()
		{
			return Coursecode;
		}
};
struct SemesterRegistration
{
private:
	string SemesterCode;
public:
	CourseRegistrations Cr[5];
};

void SetStudentArray(Student arr[],int size,char* n[],string c[],string p)//Q5
{
	for(int i=0;i<size;i++)
	{
		arr[i].setName(n[i]);
		arr[i].setCity(c[i]);
		arr[i].setPhone(p);
		arr[i].setRollNo(1001+i);
	}
}
void GetStudentArray(Student arr[], int size)//Q6
{
	for(int i=0;i<size;i++)
		{
		cout<<arr[i].getName()<<endl;
		cout<<arr[i].getCity()<<endl;
		cout<<arr[i].getPhone()<<endl;
		cout<<arr[i].getRollNo()<<endl;
		}
}
void Swap(Employee & emp1, Employee & emp2)//Q9
{
	long temp1=emp1.getBasicPay();
	long temp2=emp2.getBasicPay();
	emp1.setBasicPay(temp2);
	emp2.setBasicPay(temp1);
	int  temp3=emp1.getEmpNo();
	int  temp4=emp2.getEmpNo();
	emp1.setEmpNo(temp4);
	emp2.setEmpNo(temp3);

}
int  GetCreditHoursCount(SemesterRegistration Sr)//Q11
{
	int count;
	for(int i=0;i<5;i++)
	{
		count+=Sr.Cr[i].getCreditHours();
	}
	return count;
}
int FindCourseInSemesterRegistration(SemesterRegistration Sr,string  Coursecode)
{
	for(int i=0;i<5;i++)
	{
		if(Sr.Cr[i].getCoursecode()==Coursecode)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
struct ShoppingItems
{
private:
	string name;
	int quantity;
	int price;
	int fix;
public:
	void initializeFix()
	{
		fix=0;
	}
	int  getfix()
	{
		return fix;
	}
	int  getquantity()
	{
		return quantity;
	}
	int  getprice()
	{
		return price;
	}
	string  getname()
	{
		return name;
	}
	void InputItem(string Name, int Quantity, float rupees) {
			name = Name;
			quantity = Quantity;
			price = rupees;
		}
	void Display()
	{
		cout<<getquantity();
		cout<<getprice();
		cout<<getname();
	}
	void setname(string Name) {
		name = Name;
	}

	void setquantity(int Quantity) {
		quantity = Quantity;
	}

	void setprice(float Price) {
		price = Price;
	}
};
struct ShoppingList//Q12
{
	ShoppingItems Si[10];
	bool AddItem(ShoppingItems si)
	{
		for (int i = 0; i < 10; i++)
		{
			if (Si[i].getname() != "")
			{
				Si[i].setname(si.getname());
				Si[i].setprice(si.getprice());
				Si[i].setquantity(si.getquantity());
				return 1;
			}
		}
		return 0;
	}
	void print() {
			for (int i = 0; i < 10; i++) {
				if (Si[i].getname() != "")
					cout << Si[i].getname()<<" ";
			}
			cout <<"\n";
		}
	float TotalCost() {
		float Temp = 0;
		for (int i = 0; i < 10; i++) {
			Temp += Si[i].getprice();
		}
		return Temp;
	}
};
int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
