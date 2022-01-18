#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<iostream>//including standard libraries

#include "ourvector.h"//including user defined libraries

using namespace std;//using namespace

//function declaration
void Menu();
void PressKey();
bool LoadDb(string databasename);
void DbNotLoaded();
bool DbLoaded(bool success,string databaename);
bool LoadDna(string dnafilename);
void DnaNotLoaded();
bool DnaLoaded(bool success, string dnafilename);
bool Display(string name,string type);
int CountAGATC();
int CountTTTTTTCT();
int CountAATG();
int CountTCTAG();
int CountGATA();
int CountTATC();
int CountGAAA();
int CountTCTG();
void CountAll();

//global variables declaration
string DATABASENAME;
string DNAFILENAME;

//global vectors declaration,
ourvector<char> DB;
ourvector<char> DNA;

//main function/ driver code, execution starts here
int main()
{
    while(1)//looping infinite times
    {
        INVALIDCOMMAND://label

        char command[100]={0};
        string subcommand;
        bool success=false;//declaring & initializing variables

        Menu();//calling menu function

        cout<<"\nEnter Command:";//printing message
        cin.getline(command,100);//taking input
        subcommand=command;//assigning to subcommand

        if(subcommand.substr(0,7)=="load_db")//if "load_db" command
        {
            string databasename=subcommand.substr(8,(subcommand.length()-7));//getting database name by substringing
            success=LoadDb(databasename);//loading database

            if(DbLoaded(success,databasename)==false)//if db not loaded
            {
                goto INVALIDCOMMAND;//goto INVALIDCOMMAND
            }

            PressKey();//calling function
        }//end of if
        else if(subcommand=="display")//if "display" command
        {
            success=Display(DATABASENAME, "Database");//calling display function for Database
            success=Display(DNAFILENAME, "DNA File");//calling display function for DNA
            cout<<"\n\n";//new line
            PressKey();//calling function
        }
        else if(subcommand.substr(0,8)=="load_dna")//if "load_dna" command
        {
            string dnafilename=subcommand.substr(9,(subcommand.length()-7));//getting dna file name by substringing
            success=LoadDna(dnafilename);//loading dna

            if(DnaLoaded(success,dnafilename)==false)//if dna not loaded
            {
                goto INVALIDCOMMAND;//goto INVALIDCOMMAND
            }
        }
        else if(subcommand=="process")//if process command
        {
           CountAll();//calling function
        }
        else if(subcommand=="search")//if search command
        {

        }
        else if(subcommand=="#")//if exit command
        {
            exit(1);//exit
        }
        else//if any other commmand
        {
            cout<<"\nINVALID COMMAND!\n";//printing message
            PressKey();//calling function
            goto INVALIDCOMMAND;//goto INVALIDCOMMAND
        }
    }//end of while

    return 0;//returning zero
}//end of function

void CountAll()//function to count STRS
{
    cout<<"\nDNA Is Being Processed!!"<<endl;//printing message

    int countAGATC=CountAGATC();
    int countTTTTTTCT=CountTTTTTTCT();
    int countAATG=CountAATG();
    int countTCTAG=CountTCTAG();
    int countGATA=CountGATA();
    int countTATC= CountTATC();
    int countGAAA=CountGAAA();
    int countTCTG=CountTCTG();//counting each sequence

    cout<<"\nAGATC    : "<<countAGATC<<endl;
    cout<<"TTTTTTCT : "<<countTTTTTTCT<<endl;
    cout<<"AATG     : "<< countAATG<<endl;
    cout<<"TCTAG    : "<<countTCTAG<<endl;
    cout<<"GATA     : "<<countGATA<<endl;
    cout<<"TATC     : "<<countTATC<<endl;
    cout<<"GAAA     : "<<countGAAA<<endl;
    cout<<"TCTG     : "<<countTCTG<<endl;//printing occurence

    cout<<"\nDNA Processed Successfully!!"<<endl;//printing message
    PressKey();//calling function
}

int CountAGATC()//function to count AGATC occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>5)//if i>DNA.SIZE()
        {
            if(DNA[i]=='A' && DNA[i+1]=='G' && DNA[i+2]=='A' && DNA[i+3]=='T' && DNA[i+4]=='C')//checking for AGTAC
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountTTTTTTCT()//function to count TTTTTTCT occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if (DNA.size()-i>8)//if i>DNA.SIZE()
        {
             if(DNA[i]=='T' && DNA[i+1]=='T' && DNA[i+2]=='T' && DNA[i+3]=='T' && DNA[i+4]=='T'  && DNA[i+5]=='T'  && DNA[i+6]=='C' && DNA[i+7]=='T')//checking for TTTTTTCT
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountAATG()//function to count AATG occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>4)//if i>DNA.SIZE()
        {
             if(DNA[i]=='A' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='G')//checking for AATG
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountTCTAG()//function to count TCTAG occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>5)//if i>DNA.SIZE()
        {
            if(DNA[i]=='T' && DNA[i+1]=='C' && DNA[i+2]=='T' && DNA[i+3]=='A' && DNA[i+4]=='G')//checking for TCTAG
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountGATA()//function to count GATA occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>4)//if i>DNA.SIZE()
        {
             if(DNA[i]=='G' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='A')//checking for GATA
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountTATC()//function to count TATC occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>4)//if i>DNA.SIZE()
        {
            if(DNA[i]=='T' && DNA[i+1]=='A' && DNA[i+2]=='T' && DNA[i+3]=='C')//checking for TATC
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountGAAA()//function to count GAAA occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>4)//if i>DNA.SIZE()
        {
            if(DNA[i]=='G' && DNA[i+1]=='A' && DNA[i+2]=='A' && DNA[i+3]=='A')//checking for GAAA
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

int CountTCTG()//function to count TCTG occurences, takes nothing, returns int
{
    int count=0;//initializing variable

    for(int i=0;i<DNA.size();i++)//looping DNA.SIZE() Times
    {
        if(DNA.size()-i>4)//if i>DNA.SIZE()
        {
            if(DNA[i]=='T' && DNA[i+1]=='C' && DNA[i+2]=='T' && DNA[i+3]=='G')//checking for TCTG
            {
                count++;//if found, count++
            }
        }
    }//end of for

    return count;//return count
}//end of function

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
