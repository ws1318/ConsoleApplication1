// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

class clsFamily
{
private:
	string m_sName;
	int m_iAge;
	
public:
	void SetMembers(string, int);
	string GetName();
	int GetAge();
	

};

string clsFamily::GetName()
{
	return m_sName;
}

int clsFamily::GetAge()
{
	return m_iAge;
}

void clsFamily::SetMembers(string sName, int iAge)
{

	m_sName = sName;
	m_iAge = iAge;

}

class clsParty
{
private:

	int m_iPartyID;
	vector <clsFamily> m_objFamilyMembers;
	int m_iPartySize;
	int m_iPartyAdults;
	int m_iPartyChildren;

public:

	int GetPartyAdults();
	int GetPartyChildren();
	void SetPartyAdults(int);
	void SetPartyChildren(int);
	void SetMemberNumber(int);
	int GetFamilySize();
	void SetFamilyDetails(string, int, int);
	string GetMemberName(int);
	int GetMemberAge(int);


};

string clsParty::GetMemberName(int iNumber)
{

	return m_objFamilyMembers[iNumber].GetName();
}

int clsParty::GetMemberAge(int iNumber)
{

	return m_objFamilyMembers[iNumber].GetAge();

}

void clsParty::SetFamilyDetails(string sName, int iAge, int iNumber)
{

	m_objFamilyMembers[iNumber].SetMembers(sName, iAge);

}

void clsParty::SetPartyAdults(int iNumber)
{

	m_iPartyAdults = iNumber;

}

void clsParty::SetPartyChildren(int iNumber)
{

	m_iPartyChildren = iNumber;

}

int clsParty::GetFamilySize()
{

	return m_objFamilyMembers.size();

}

void clsParty::SetMemberNumber(int iNumber)
{

	m_objFamilyMembers.resize(iNumber);
	m_iPartySize = iNumber;

}

int clsParty::GetPartyAdults()
{
	return m_iPartyAdults;
}

int clsParty::GetPartyChildren()
{
	return m_iPartyChildren;
}


void PopulateFamily(vector <clsParty> &objParties)
{
	string sNamePass = "";
	int iAgePass = 0;
	int iPartyChildrenPass = 0;
	int iPartyAdultPass = 0;



	objParties[0].SetMemberNumber(4);

	for (int iCount = 0; iCount < objParties[0].GetFamilySize(); iCount++)
	{
		cout << "\nPlease enter person " << iCount + 1 << "'s name.\n";
		cin >> sNamePass;
		cout << "\nPlease enter person " << iCount + 1 << "'s age.\n";
		cin >> iAgePass;

		if (iAgePass < 16)
		{

			iPartyChildrenPass++;
		}
		else
		{
			iPartyAdultPass++;
		}

		objParties[0].SetPartyAdults(iPartyAdultPass);
		objParties[0].SetPartyChildren(iPartyChildrenPass);
		objParties[0].SetFamilyDetails(sNamePass, iAgePass, iCount);

	}
}

void GetMembers(vector <clsParty>& objParties)
{

	for (int iCount = 0; iCount < objParties[0].GetFamilySize(); iCount++)
	{

			cout << "\nPerson " << iCount + 1 << "'s name is: " << objParties[0].GetMemberName(iCount);
			cout << "\nPerson " << iCount + 1 << "'s age is: " << objParties[0].GetMemberAge(iCount);

	}

			cout << "\nThere are " << objParties[0].GetFamilySize() << " people in your party.";
			cout << "\nThere are " << objParties[0].GetPartyChildren() << " Children in your party.";
			cout << "\nThere are " << objParties[0].GetPartyAdults() << "  in your party.";
}

int main()
{
	vector <clsParty> objParties(1);

	PopulateFamily(objParties);
	GetMembers(objParties);

}



