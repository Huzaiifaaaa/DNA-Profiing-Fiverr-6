#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include <fstream>
#include<stdlib.h>
#include<iostream>
#include "ourvector.h"

using namespace std;

void Menu();
void PressKey();
void DbNotLoaded();
bool DbLoaded(bool success,string databaename);
void DnaNotLoaded();
bool DnaLoaded(bool success, string dnafilename);
bool Display(string name,string type);
bool LoadDb(string databasename);
bool LoadDna(string dnafilename);
int CountAGATC();
int CountTTTTTTCT();
int CountAATG();
int CountTCTAG();
int CountGATA();
int CountTATC();
int CountGAAA();
int CountTCTG();
void CountAll();

string DATABASENAME;
string DNAFILENAME;
ourvector<char> DB;
ourvector<char> DNA;

int main()
{
    while(1)
    {
        INVALIDCOMMAND:
        char command[100]={0};
        string subcommand;
        bool success=false;

        Menu();

        cout<<"\nEnter Command:";
        cin.getline(command,100);
        subcommand=command;

        if(subcommand.substr(0,7)=="load_db")
        {
            string databasename=subcommand.substr(8,(subcommand.length()-7));
            success=LoadDb(databasename);

            if(DbLoaded(success,databasename)==false)
            {
                goto INVALIDCOMMAND;
            }

            PressKey();
        }
        else if(subcommand=="display")
        {
            success=Display(DATABASENAME, "Database");
            success=Display(DNAFILENAME, "DNA File");
            cout<<"\n\n";
            PressKey();
        }
        else if(subcommand.substr(0,8)=="load_dna")
        {
            string dnafilename=subcommand.substr(9,(subcommand.length()-7));
            success=LoadDna(dnafilename);

            if(DnaLoaded(success,dnafilename)==false)
            {
                goto INVALIDCOMMAND;
            }
        }
        else if(subcommand=="process")
        {
           CountAll();
        }
        else if(subcommand=="search")
        {

        }
        else if(subcommand=="#")
        {
            exit(1);
        }
        else
        {
            cout<<"\nINVALID COMMAND!\n";
            PressKey();
            goto INVALIDCOMMAND;
        }
    }

    return 0;
}

void CountAll()
{
    cout<<"\nDNA Is Being Processed!!"<<endl;

    int countAGATC=CountAGATC();
    int countTTTTTTCT=CountTTTTTTCT();
    int countAATG=CountAATG();
    int countTCTAG=CountTCTAG();
    int countGATA=CountGATA();
    int countTATC= CountTATC();
    int countGAAA=CountGAAA();
    int countTCTG=CountTCTG();

    cout<<"\nAGATC    : "<<countAGATC<<endl;
    cout<<"TTTTTTCT : "<<countTTTTTTCT<<endl;
    cout<<"AATG     : "<< countAATG<<endl;
    cout<<"TCTAG    : "<<countTCTAG<<endl;
    cout<<"GATA     : "<<countGATA<<endl;
    cout<<"TATC     : "<<countTATC<<endl;
    cout<<"GAAA     : "<<countGAAA<<endl;
    cout<<"TCTG     : "<<countTCTG<<endl;

    cout<<"\nDNA Processed Successfully!!"<<endl;
    PressKey();
}

int CountAGATC()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>5)
        {
            if(DNA[i]=='A' && DNA[i+1]=='G' && DNA[i+2]=='A' && DNA[i+3]=='T' && DNA[i+4]=='C')
            {
                count++;
            }
        }
    }

    return count;
}

int CountTTTTTTCT()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if (DNA.size()-i>8)
        {
             if(DNA[i]=='T' && DNA[i+1]=='T' && DNA[i+2]=='T' && DNA[i+3]=='T' && DNA[i+4]=='T'  && DNA[i+5]=='T'  && DNA[i+6]=='C' && DNA[i+7]=='T')
            {
                count++;
            }
        }
    }

    return count;
}

int CountAATG()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>4)
        {
             if(DNA[i]=='A' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='G')
            {
                count++;
            }
        }
    }

    return count;
}

int CountTCTAG()
{
        int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>5)
        {
            if(DNA[i]=='T' && DNA[i+1]=='C' && DNA[i+2]=='T' && DNA[i+3]=='A' && DNA[i+4]=='G')
            {
                count++;
            }
        }
    }

    return count;
}

int CountGATA()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>4)
        {
             if(DNA[i]=='G' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='A')
            {
                count++;
            }
        }
    }

    return count;
}

int CountTATC()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>4)
        {
            if(DNA[i]=='T' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='C')
            {
                count++;
            }
        }
    }

    return count;
}
int CountGAAA()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>4)
        {
            if(DNA[i]=='G' && DNA[i+1]=='A' && DNA[i+2]=='A' && DNA[i+3]=='A')
            {
                count++;
            }
        }
    }

    return count;
}
int CountTCTG()
{
    int count=0;

    for(int i=0;i<DNA.size();i++)
    {
        if(DNA.size()-i>4)
        {
            if(DNA[i]=='T' && DNA[i+1]=='C' && DNA[i+2]=='T' && DNA[i+3]=='G')
            {
                count++;
            }
        }
    }

    return count;
}

bool Display(string name,string type)
{
    cout<<"\n";
	ifstream DisplayFile(name);
    char character[10000];
    int i = 10000;

    if(!DisplayFile)
    {
        cout<<"No "<< type << " Loaded!!";
        return false;
    }

    cout<<type << " Loaded!!\n"<<endl;
    while(DisplayFile)
    {
        DisplayFile.getline(character, i);
        cout << character << endl;
    }
    DisplayFile.close();

    return true;
}

bool DbLoaded(bool success, string databasename)
{
    if(success==true)
    {
        cout<<"Database *"<< databasename<< "* Loaded Successfully!!"<<endl;
    }
    else
    {
        DbNotLoaded();
        return false;
    }
    return true;
}

bool DnaLoaded(bool success, string dnafilename)
{
    if(success==true)
    {
        cout<<"DNA File *"<< dnafilename<< "* Loaded Successfully!!"<<endl;
    }
    else
    {
        DnaNotLoaded();
        return false;
    }
    getchar();
    return true;
}

bool LoadDna(string dnafilename)
{
    cout<<"Loading DNA File-->" << dnafilename<<endl;
    ifstream LoadDnaFile;
    LoadDnaFile.open(dnafilename,ios::in);
    if(!LoadDnaFile)
    {
        return false;
    }
    else
    {
        char character;

		while (1) {
			LoadDnaFile >> character;
			if (LoadDnaFile.eof())
				break;

			DNA.push_back(character);
		}
		LoadDnaFile.close();
        DNAFILENAME=dnafilename;
    }

    return true;
}

bool LoadDb(string databasename)
{
    cout<<"Loading Database-->" << databasename<<endl;
    ifstream LoadDatabase;
    LoadDatabase.open(databasename,ios::in);
    if(!LoadDatabase)
    {
        return false;
    }
    else
    {
        char character;

		while (1) {
			LoadDatabase >> character;
			if (LoadDatabase.eof())
				break;

			DB.push_back(character);
		}
		DATABASENAME=databasename;
        LoadDatabase.close();
    }

    return true;
}

void DbNotLoaded()
{
    cout<<"Database Not Found!!\n\n";
    PressKey();
}

void DnaNotLoaded()
{
    cout<<"DNA File Not Found/Loaded!!\n\n";
    PressKey();
}

void PressKey()
{
    cout<<"Press Enter To Continue!!\n";
    getchar();
}

void Menu()
{
    system("cls");
    cout<<"\n";
    cout<<"WELCOME TO DNA PROFILING APPLICATION\n";
    cout<<"\n";
    cout<<"MENU:\t\t";
    cout<<"\n\n";
    cout<<"1-LOAD DATABASE--> load_db dbname.txt\n";
    cout<<"2-DISPLAY--> display\n";
    cout<<"3-LOAD DNA--> load_dna name.txt\n";
    cout<<"4-PROCESS--> process\n";
    cout<<"5-SEARCH--> search\n";
    cout<<"6-EXIT--> #\n";
}
