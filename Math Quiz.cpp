#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

enum enLevel { Easy = 1, Med = 2, Hard = 3, MixLevel = 4 };

enum enOpp { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOpp = 5 };

struct stFinalResult {
	short NumOfQst;
	enLevel QstLevel;
	enOpp OpType;
	short NumRightAnswr;
	short NumWrongAnswr;
};
int RandomNum(int from, int to) {
	return rand() % (to - from + 1) + from;
}
short HowManyQeustion() {
	short hwm;
	cout << "how many question you want to answer ? ";
	cin >> hwm;
	return hwm;
}
enLevel ReadLevel() {
	short lvl;
	cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	cin >> lvl;
	return(enLevel)lvl;
}
enOpp ReadOpp() {
	short opp;
	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  ";
	cin >> opp;
	return(enOpp)opp;
}

void ChoseLevel(enLevel level, int& from, int& to) {
	if (level == enLevel::MixLevel) {
		level = (enLevel)RandomNum(1, 3);
	}

	switch (level)
	{
	case enLevel::Easy: from = 1; to = 9; break;
	case enLevel::Med: from = 10; to = 49; break;
	case enLevel::Hard: from = 50; to = 99; break;
	}
}

bool CheckResult(int num1, int num2, char opp) {
	int result;
	cin >> result;
	switch (opp)
	{
	case '+':return(result == (num1 + num2));
		break;
	case '-':return(result == (num1 - num2));
		break;
	case '*':return(result == (num1 * num2));
		break;
	case '/':return(result == (num1 / num2));
		break;
	}
}
void PrintResult(bool ch, stFinalResult& FR) {
	if (ch)
	{
		system("color 2f");
		cout << "\nRight Answer : -)\n";
		FR.NumRightAnswr++;
	}
	else
	{
		system("color 4f");
		cout << "\nWrong Answer :-(\n";
		FR.NumWrongAnswr++;
	}
}
void pAdd(int num1, int num2, char opp, stFinalResult& FR) {
	bool ch;
	cout << num1 << "\n"
		<< num2 << "  +"
		<< "\n-------------\n";
	ch = CheckResult(num1, num2, opp);
	PrintResult(ch, FR);

}
void pSub(int num1, int num2, char opp, stFinalResult& FR) {
	bool ch;
	cout << num1 << "\n"
		<< num2 << "  -"
		<< "\n-------------\n";
	ch = CheckResult(num1, num2, opp);
	PrintResult(ch, FR);
}
void pMul(int num1, int num2, char opp, stFinalResult& FR) {
	bool ch;
	cout << num1 << "\n"
		<< num2 << "  *"
		<< "\n-------------\n";
	ch = CheckResult(num1, num2, opp);
	PrintResult(ch, FR);
}
void pDiv(int num1, int num2, char opp, stFinalResult& FR) {
	bool ch;
	cout << num1 << "\n"
		<< num2 << "  /"
		<< "\n-------------\n";
	ch = CheckResult(num1, num2, opp);
	PrintResult(ch, FR);
}

void ChoseOpp(enOpp opp, int from, int to, stFinalResult& FR) {
	if (opp == enOpp::MixOpp) {
		opp = (enOpp)RandomNum(1, 4);
	}

	int num1 = RandomNum(from, to);
	int num2 = RandomNum(from, to);

	switch (opp)
	{
	case enOpp::Add: pAdd(num1, num2, '+', FR); break;
	case enOpp::Sub: pSub(num1, num2, '-', FR); break;
	case enOpp::Mul: pMul(num1, num2, '*', FR); break;
	case enOpp::Div: pDiv(num1, num2, '/', FR); break;
	}
}
void OneQst(stFinalResult& FR, int qst, int from, int to) {
	cout << "Question [" << qst << "/" << FR.NumOfQst << "]\n";
	ChoseLevel(FR.QstLevel, from, to);
	ChoseOpp(FR.OpType, from, to, FR);
}
string PassOrFail(stFinalResult FR) {
	if (FR.NumRightAnswr >= FR.NumWrongAnswr)
	{
		return "PASS :-)";
	}
	else if (FR.NumWrongAnswr > FR.NumRightAnswr)
	{
		return "FAIL :-(";
	}
}
string GetLevel(enLevel level) {
	switch (level)
	{
	case enLevel::Easy:return "Easy";
		break;
	case enLevel::Med:return "Med";
		break;
	case enLevel::Hard:return "Hard";
		break;
	case enLevel::MixLevel:return "Mix";
		break;
	}
}
string GetOpp(enOpp opp) {
	switch (opp)
	{
	case enOpp::Add:return "Add";
		break;
	case enOpp::Sub:return "Sub";
		break;
	case enOpp::Mul:return "Mul";
		break;
	case enOpp::Div:return "Div";
		break;
	case enOpp::MixOpp:return "Mix";
		break;
	}
}
void PrintFinalResult(stFinalResult& FR) {
	cout << "\n\n-----------------------------------------------------\n\n"
		<< " Final Result is " << PassOrFail(FR)
		<< "\n\n-----------------------------------------------------\n"
		<< "Number Of Questions     : " << FR.NumOfQst << endl
		<< "Question of level       : " << GetLevel(FR.QstLevel) << endl
		<< "OPtype                  :" << GetOpp(FR.OpType) << endl
		<< "Number Of Right Answer  :" << FR.NumRightAnswr << endl
		<< "Number Of Wrong Answer :" << FR.NumWrongAnswr << endl
		<< "-----------------------------------------------------\n\n";

}
void PlayGame(stFinalResult& FR) {
	FR.NumRightAnswr = 0, FR.NumWrongAnswr = 0;
	FR.NumOfQst = HowManyQeustion();
	if (FR.NumOfQst > 0) {
		FR.QstLevel = ReadLevel();
		int from = 0, to = 0;
		FR.OpType = ReadOpp();
		for (size_t i = 1; i <= FR.NumOfQst; i++)
		{
			OneQst(FR, i, from, to);
		}
	}
}
void ResetScreen() {
	system("cls");
	system("color 0f");
}
void MathGame() {
	char PlayAgain;
	stFinalResult FR;
	do
	{
		ResetScreen();
		PlayGame(FR);
		PrintFinalResult(FR);
		cout << "do you want to play again ? [y/Y] : ";
		cin >> PlayAgain;

	} while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
	srand((unsigned)time(NULL));
	MathGame();

}