//============================================================================
// Name        : HomeWork2.cpp
// Author      : Evan Lilga
// Version     :
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include<map>
#include<vector>
using namespace std;



class LexAnalyzer{
private:
	vector<char> lexemes;  // source code file lexemes
	vector<string> tokens;   // source code file tokens
	map<string, string> tokenmap;  // valid lexeme/token pairs
	// other private methods
public:

LexAnalyzer(istream& infile){
// pre: parameter refers to open data file consisting of token and
// lexeme pairs i.e.  s_and and t_begin begin t_int 27.  Each pair    // appears on its own input line.
// post: tokenmap has been populated
	string token;
	string lex;
	infile >> token >> lex;
	while(!infile.eof()){
		tokenmap[lex]=token;
		//cout << tokenmap[lex]<<endl;
		infile >> token >> lex;
	}
}
void scanFile(istream& infile, ostream& outfile){
// pre: 1st parameter refers to an open text file that contains source
// code in the language, 2nd parameter refers to an open empty output
// file
// post: If no error, the token and lexeme pairs for the given input
// file have been written to the output file.  If there is an error,
// the incomplete token/lexeme pairs, as well as an error message have // written to the output file.  A success or fail message has printed // to the console.
	string str;
	string line;
	bool restart;
	bool newline = false;
	getline(infile, line);
		while(!infile.eof()){
			for (int i = 0; i < line.length(); i++){
				//fills vector from line from file
				lexemes.push_back(line[i]);
				//cout << vtest[i] << endl;
			}
			for (int i = 0; i < lexemes.size(); i++){
				if (newline){
					while(lexemes[i]!='"'){
						str = str + lexemes[i];
						i++;
					}
					i++;
					outfile<<findToken("tstr")<< " : " << str <<endl;
					str = "";
					restart = true;
					newline = false;
				}
				restart = false;
				if (lexemes[i]=='b' && lexemes[i+1]=='e' && lexemes[i+2]=='g' && lexemes[i+3]=='i' && lexemes[i+4]=='n' && !restart){
					outfile<<findToken("begin")<< " : begin"<<endl;i = i+4;restart = true;}
				if (lexemes[i]=='e' && lexemes[i+1]=='n' && lexemes[i+2]=='d' && !restart){
					outfile<<findToken("end")<<" : end"<<endl;i = i+2;restart = true;}
				if (lexemes[i]=='e' && lexemes[i+1]=='l' && lexemes[i+2]=='s' && lexemes[i+3]=='e' && !restart){
					outfile<<findToken("else")<<" : else"<<endl;i = i+3;restart = true;}
				if (lexemes[i]=='i' && lexemes[i+1]=='f'&& !restart){
					outfile<<findToken("if")<<" : if"<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='i' && lexemes[i+1]=='n' && lexemes[i+2]=='p' && lexemes[i+3]=='u' && lexemes[i+4]=='t'&& !restart){
					outfile<<findToken("input")<<" : input"<<endl;i = i+4;restart = true;}
				if (lexemes[i]=='i' && lexemes[i+1]=='n' && lexemes[i+2]=='t' && lexemes[i+3]=='e' && lexemes[i+4]=='g' && lexemes[i+5]=='e' && lexemes[i+6]=='r' && !restart){
					outfile<<findToken("integer")<<" : integer"<<endl;i = i+6;restart = true;}
				if (lexemes[i]=='s' && lexemes[i+1]=='t' && lexemes[i+2]=='r' && lexemes[i+3]=='i' && lexemes[i+4]=='n' && lexemes[i+5]=='g' && !restart){
					outfile<<findToken("string")<<" : string"<<endl;i = i+5;restart = true;}
				if (lexemes[i]=='l' && lexemes[i+1]=='o' && lexemes[i+2]=='o' && lexemes[i+3]=='p'&& !restart){
					outfile<<findToken("loop")<<" : loop"<<endl;i = i+3;restart = true;}
				if (lexemes[i]=='m' && lexemes[i+1]=='a' && lexemes[i+2]=='i' && lexemes[i+3]=='n'&& !restart){
					outfile<<findToken("main")<<" : main"<<endl;i = i+3;restart = true;}
				if (lexemes[i]=='o' && lexemes[i+1]=='u' && lexemes[i+2]=='t' && lexemes[i+3]=='p' && lexemes[i+4]=='u' && lexemes[i+5]=='t'&& !restart){
					outfile<<findToken("output")<<" : output"<<endl;i = i+5;restart = true;}
				if (lexemes[i]=='t' && lexemes[i+1]=='h' && lexemes[i+2]=='e' && lexemes[i+3]=='n'&& !restart){
					outfile<<findToken("then")<<" : than"<<endl;i = i+3;restart = true;}
				if (lexemes[i]=='v' && lexemes[i+1]=='a' && lexemes[i+2]=='r'&& !restart){
					outfile<<findToken("var")<<" : var"<<endl;i = i+2;restart = true;}
				if (lexemes[i]=='w' && lexemes[i+1]=='h' && lexemes[i+2]=='i' && lexemes[i+3]=='l' && lexemes[i+4]=='e'&& !restart){
					outfile<<findToken("while")<<" : while"<<endl;i = i+4;restart = true;}
				if (lexemes[i]=='<'&& lexemes[i+1]=='='&& !restart){
					outfile<<findToken("<=")<<" : <="<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='>'&& lexemes[i+1]=='='&& !restart){
					outfile<<findToken(">=")<<" : >="<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='='&& lexemes[i+1]=='='&& !restart){
					outfile<<findToken("==")<<" : =="<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='!'&& lexemes[i+1]=='='&& !restart){
					outfile<<findToken("!=")<<" : !="<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='&'&& lexemes[i+1]=='&'&& !restart){
					outfile<<findToken("&&")<<" : &&"<<endl;i = i+1;restart = true;}
				if (lexemes[i]=='|'&& lexemes[i+1]=='|'&& !restart){
					outfile<<findToken("||")<<" : ||"<<endl;i = i+1;restart = true;}
				if (lexemes[i]==','&& !restart){
					outfile<<findToken(",")<<" : ,"<<endl;restart = true;}
				if (lexemes[i]=='('&& !restart){
					outfile<<findToken("(")<<" : ("<<endl;restart = true;}
				if (lexemes[i]==')'&& !restart){
					outfile<<findToken(")")<<" : )"<<endl;restart = true;}
				if (lexemes[i]==';'&& !restart){
					outfile<<findToken(";")<<" : ;"<<endl;restart = true;}
				if (lexemes[i]=='='&& !restart){
					outfile<<findToken("=")<<" : ="<<endl;restart = true;}
				if (lexemes[i]=='<'&& !restart){
					outfile<<findToken("<")<<" : >"<<endl;restart = true;}
				if (lexemes[i]=='>'&& !restart){
					outfile<<findToken(">")<<" : >"<<endl;restart = true;}
				if (lexemes[i]=='+'&& !restart){
					outfile<<findToken("+")<<" : +"<<endl;restart = true;}
				if (lexemes[i]=='-'&& !restart){
					outfile<<findToken("-")<<" : -"<<endl;restart = true;}
				if (lexemes[i]=='*'&& !restart){
					outfile<<findToken("*")<<" : *"<<endl;restart = true;}
				if (lexemes[i]=='/'&& !restart){
					outfile<<findToken("/")<<" : /"<<endl;restart = true;}
				if (lexemes[i]=='%'&& !restart){
					outfile<<findToken("%")<<" : %"<<endl;restart = true;}
				if (lexemes[i]=='!'&& !restart){
					outfile<<findToken("!")<<" : !"<<endl;restart = true;}

				if (int(lexemes[i]) >= 48 && int(lexemes[i]) <= 57 && !restart){
					str = str + lexemes[i];
					i++;
					while ((int(lexemes[i]) >= 48 && int(lexemes[i]) <= 57)){
						str = str + lexemes[i];
						i++;
					}
					outfile <<findToken("tint")<< " : " << str << endl;
					str = "";
					restart = true;
				}

				if(lexemes[i]=='"'&& !restart){
					i++;
					while(lexemes[i]!='"' && !newline){
						str = str + lexemes[i];
						i++;
						if(i == lexemes.size()){
							newline = true;
						}
					}
					outfile<<findToken("tstr")<< " : " << str <<endl;
					str = "";
					restart = true;

				}


				if(((int(lexemes[i]) >= 65 && int(lexemes[i]) <= 90) || (int(lexemes[i]) >= 97 && int(lexemes[i]) <= 122)) && !restart){
					str = str + lexemes[i];
					while((int(lexemes[i+1]) >= 65 && int(lexemes[i+1]) <= 90) || (int(lexemes[i+1]) >= 97 && int(lexemes[i+1]) <= 122) || (int(lexemes[i+1]) >= 48 && int(lexemes[i+1]) <= 57)){
						str = str + lexemes[i+1];
						i++;
					}
					outfile<<findToken("identify")<< " : " << str <<endl;
					str = "";
					restart = true;
				}
				if(!restart && lexemes[i] != ' ' && !newline){
					cout<<"error unexpected : "<< line <<endl;
					outfile<<"error unexpected : "<< line <<endl;
				}
			}
			lexemes.clear();
			getline(infile, line);
		}
	}
	string findToken(string word){
		return tokenmap[word];
	}


};

int main() {
	string test;
	vector<char> vtest;
	string scfile;
	string outFile;
	cout << "please enter the source code file name" << endl;
	cin >> scfile;
	cout << "please enter the output file name" << endl;
	cin >> outFile;
	ifstream lexfile("LexFile.txt");
	//ifstream infile("sourceCode.txt"); HARD CODED FILE
	ifstream infile(scfile);
	//ofstream  outfile("outPut.txt"); HARD CODED FILE
	ofstream  outfile(outFile);
	if(!infile){
			exit(-1);
		}
	LexAnalyzer lexTest(lexfile);
	lexTest.scanFile(infile, outfile);
	cout << "Thank you for using the lexical analysis!"<<endl;

	return 0;
}

