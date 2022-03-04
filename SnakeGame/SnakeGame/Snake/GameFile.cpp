#include<iostream>
#include<fstream>
#include"GameHeader.h"


using namespace std;

class Result {
public:
	int firstHighestScore, secondHighestScore, thirdHighestScore;
	Result() {
		firstHighestScore = 0;
		secondHighestScore = 0;
		thirdHighestScore = 0;
	}
};



void updateScoreInFile(int currentScore)
{
	fstream f;
	Result res;
	f.open("Result.txt", ios::in );
	if (!f) 
	{                                                    // this , executes , when there is no file created
		cout << endl << "    creating file first time !!!!";    
		f.open("Result.txt", ios::out);
		f.write((char*)&res, sizeof(res));
		f.close();
		f.open("Result.txt", ios::in);
	}
	f.read((char*)&res, sizeof(res));
	if (res.firstHighestScore == 0) 
	{                                                   // this , updates the records for the first time
		cout << endl << "    updating record first time ...";
		f.close();
		f.open("Result.txt", ios::out);
		res.firstHighestScore = currentScore;
		f.write((char*)&res, sizeof(res));
	}
	else
	{                                             // this , updates the record as usual
		bool fileUpdated= false;
		if (currentScore > res.firstHighestScore)
		{
			res.thirdHighestScore = res.secondHighestScore;
			res.secondHighestScore = res.firstHighestScore;
			res.firstHighestScore = currentScore;
			fileUpdated=true;
	    }
		
		else if (currentScore > res.secondHighestScore) 
		{
			res.thirdHighestScore = res.secondHighestScore;
			res.secondHighestScore = currentScore;
			fileUpdated = true;
		}
		else if (currentScore > res.thirdHighestScore)
		{
			res.thirdHighestScore = currentScore;
			fileUpdated = true;
		}
		if (fileUpdated) 
		{
			f.close();
			f.open("Result.txt", ios::out);
			f.write((char*)&res, sizeof(res));
		}
	
	}
	f.close();
}

void displayScoreFromFile()
{
	system("cls");
	ifstream f;
	Result res;
	int counter = 1;
	f.open("Result.txt", ios::in);
	if (!f)
	{
		cout << endl<<"  No data found !!!!! , play the game to score high."<<endl<<endl;
		return;
	}
	f.read((char*)&res, sizeof(res));
    cout << counter << " : " << res.firstHighestScore << endl;
	++counter;  
	cout << counter << " : " << res.secondHighestScore << endl;
	++counter;
	cout << counter << " : " << res.thirdHighestScore << endl;
	f.close();
	return;
}


