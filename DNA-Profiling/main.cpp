#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include <fstream>
#include<stdlib.h>
#include<sstream>
#include<iostream>//including standard libraries

#include "ourvector.h"//including user defined libraries

using namespace std;//using name space

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
void SearchAll(int countAGATC,int countTTTTTTCT,int countAATG,int countTCTAG,int countGATA,int countTATC,int countGAAA,int countTCTG);
bool SearchAGATC(int countAGATC);
void NumberSplitter(int number);
bool CompareVectors();
bool ReadLine(string filename,string compare,int size);

//global variables declaration
string DATABASENAME;
string DNAFILENAME;
string SEARCHRESULT;
char COMPAREARRAY[100]={0};

int SPLITTED[10];
int COUNTER=0;
int TEMPCOUNTER=0;
int VECTORSIZE=0;



int PRESENT[30];
int TEST[30];

//global vectors declaration,
ourvector<char> DB;
ourvector<char> DNA;
ourvector<char> COMPARE;

//main function/ driver code, execution starts here
int main()
{
    while(1){//looping infinite times
        INVALIDCOMMAND://label
        char command[100]={0};
        string subcommand;
        bool success=false;//declaring & initializing variables
        Menu();//calling menu function
        cout<<"\nEnter Command:";//printing message
        cin.getline(command,100);//taking input
        subcommand=command;//assigning to subcommand
        if(subcommand.substr(0,7)=="load_db") {//if "load_db" command
            string databasename=subcommand.substr(8,(subcommand.length()-7));//getting database name by substringing
            success=LoadDb(databasename);//loading database
            if(DbLoaded(success,databasename)==false){//if db not loaded
                goto INVALIDCOMMAND;//goto INVALIDCOMMAND
            }
            PressKey();//calling function
        }//end of if
        else if(subcommand=="display"){//if "display" command
            success=Display(DATABASENAME, "Database");//calling display function for Database
            success=Display(DNAFILENAME, "DNA File");//calling display function for DNA
            cout<<"\n\n";//new line
            PressKey();//calling function
        }
        else if(subcommand.substr(0,8)=="load_dna"){//if "load_dna" command
            string dnafilename=subcommand.substr(9,(subcommand.length()-7));//getting dna file name by substringing
            success=LoadDna(dnafilename);//loading dna
            if(DnaLoaded(success,dnafilename)==false){//if dna not loaded
                goto INVALIDCOMMAND;//goto INVALIDCOMMAND
            }
        }
        else if(subcommand=="process"){//if process command
           CountAll();//calling function
        }
        else if(subcommand=="search"){//if search command
            cout<<"\nMatch Found--> "<<SEARCHRESULT<<endl;
            PressKey();
        }
        else if(subcommand=="#"){//if exit command
            exit(1);//exit
        }
        else {//if any other commmand
            cout<<"\nINVALID COMMAND!\n";//printing message
            PressKey();//calling function
            goto INVALIDCOMMAND;//goto INVALIDCOMMAND
        }
    }//end of while
    return 0;//returning zero
}//end of function

void SearchAll(int countAGATC,int countTTTTTTCT,int countAATG,int countTCTAG,int countGATA,int countTATC,int countGAAA,int countTCTG)
 {
    COMPARE.clear();
    VECTORSIZE=0;
    NumberSplitter(countAGATC);
    NumberSplitter(countTTTTTTCT);
    NumberSplitter(countAATG);
    NumberSplitter(countTCTAG);
    NumberSplitter(countGATA);
    NumberSplitter(countTATC);
    NumberSplitter(countGAAA);
    NumberSplitter(countTCTG);

    if(CompareVectors())
        cout<<"FOUND\n";
    else
        cout<<"NOT FOUND\n";

    }


bool CompareVectors()
{
     for(int i=0;i<30;i++)
     {
         PRESENT[i]=2;
     }

     VECTORSIZE=COMPARE.size()-1;

    string compare;
    for (int i = 0; i < COMPARE.size()-1; i++) {
        compare = compare + COMPARE[i];
    }

    bool found=ReadLine(DATABASENAME,compare,VECTORSIZE);

    return true;
}

bool ReadLine(string filename,string compare,int size)
{
    SEARCHRESULT="";
    std::ifstream file(filename);
    std::string str;

    int CompareLength = compare.length();
    char ArrayCompare[CompareLength + 1];
    strcpy(ArrayCompare, compare.c_str());

    while (std::getline(file, str))
    {
        int StrLength = str.length();
        char StrArray[StrLength + 1];
        strcpy(StrArray, str.c_str());

        int len=str.length()-size;

        if(compare==str.substr(len,size))
        {
            for(int i=0;i<len-1;i++)
            {
                SEARCHRESULT=SEARCHRESULT+StrArray[i];
            }
            return true;
        }
    }

    return false;
}

 void NumberSplitter(int Number)
 {
    int number=Number;
    int exponent = floor( log10( static_cast<double>(number) ) );
    int i=0;
	int divisor;
	int num;

	if(Number==0)
    {
        COMPARE.push_back(0+'0');
        COUNTER++;
    }

	while (number != 0)
	{
		divisor = pow(10.0, exponent);
		num=(number/divisor);
		COMPARE.push_back(num+'0');
        if(Number%10==0 && TEMPCOUNTER!=7)
        {
            COMPARE.push_back(0+'0');
        }
		number %= divisor;
		exponent--;
		COUNTER++;
	}

    COMPARE.push_back(',');
    COUNTER++;

    TEMPCOUNTER++;
 }

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

    SearchAll(countAGATC,countTTTTTTCT,countAATG,countTCTAG,countGATA,countTATC,countGAAA,countTCTG);

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

bool Display(string name,string type)//function to display last loaded Database & DNA, takes file name & returns bool
{
    cout<<"\n";//new line
	ifstream DisplayFile(name);//file object
    char character[10000];
    int i = 10000;//initializing variable

    if(!DisplayFile)//if file is not loaded
    {
        cout<<"No "<< type << " Loaded!!";//printing message
        return false;//returning false
    }

    cout<<type << " Loaded!!\n"<<endl;//printing message
    while(DisplayFile)//if opened
    {
        DisplayFile.getline(character, i);//reading file
        cout << character << endl;//printing all characters
    }
    DisplayFile.close();//closing file

    return true;//returning file
}//end of function

bool DbLoaded(bool success, string databasename)//function to verify database loading, takes bool & database name, returns bools
{
    if(success==true)//if database file loaded/opened
    {
        cout<<"Database *"<< databasename<< "* Loaded Successfully!!"<<endl;//printing message
    }
    else//if not loaded
    {
        DbNotLoaded();//calling function
        return false;//returning false
    }
    return true;//returning true
}//end of function

bool DnaLoaded(bool success, string dnafilename)//function to verify database loading, takes bool & dnafile , returns bool
{
    if(success==true)//if database file loaded/opened
    {
        cout<<"DNA File *"<< dnafilename<< "* Loaded Successfully!!"<<endl;
    }
    else//if not loaded
    {
        DnaNotLoaded();//calling function
        return false;//returning false
    }
    getchar();//get character
    return true;//returning true
}//end of function

bool LoadDna(string dnafilename)//function to load DNA file, takes filename, returns bool
{
    int COUNTER=0;
    DNA.clear();
    cout<<"Loading DNA File-->" << dnafilename<<endl;//printing message
    ifstream LoadDnaFile;//file object
    LoadDnaFile.open(dnafilename,ios::in);//opening file

    if(!LoadDnaFile)//if file not opened/found
    {
        return false;
    }
    else//if opened
    {
        char character;//initializing variable

		while (1)//looping
        {
			LoadDnaFile >> character;//getting data
			if (LoadDnaFile.eof())//checking if END OF FILE reached
				break;//breaking

			DNA.push_back(character);//pushing character to vector
		}
		LoadDnaFile.close();//closing file
        DNAFILENAME=dnafilename;//assigning value
    }

    return true;//returning true
}//end of function

bool LoadDb(string databasename)//function to load DATABASE file, takes filename, returns bool
{
    DB.clear();
    cout<<"Loading Database-->" << databasename<<endl;//printing message
    ifstream LoadDatabase;//file object
    LoadDatabase.open(databasename,ios::in);//opening file

    if(!LoadDatabase)//if file not opened/found
    {
        return false;//returning false
    }
    else//if found
    {
        char character;//initializing variable

		while (1) //looping
        {
			LoadDatabase >> character;//getting data
			if (LoadDatabase.eof())//checking if END OF FILE reached
				break;//breaking

			DB.push_back(character);//pushing character to vector
		}//end of while
        LoadDatabase.close();//closing file
        DATABASENAME=databasename;//assigning value
    }//end of else

    return true;//returning true
}//end of function

void DbNotLoaded()//if db file not opened, takes nothing, returns nothing
{
    cout<<"Database Not Found!!\n\n";//printing message
    PressKey();//calling function
}//end of function

void DnaNotLoaded()//if dna file not opened, takes nothing, returns nothing
{
    cout<<"DNA File Not Found/Loaded!!\n\n";//printing message
    PressKey();//calling function
}//end of function

void PressKey()//function to stop execution till enter is pressed, takes nothing, returns nothing
{
    cout<<"Press Enter To Continue!!\n";//printing message
    getchar();//get character
}//end of function

void Menu()//function to print menu, takes nothing, returns nothing
{
    system("cls");//clear screen
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
}//end of function
