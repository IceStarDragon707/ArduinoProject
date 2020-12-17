#include <iostream>
#include <vector>

using namespace std;

char find(char c);

int main(){
	
	while(true){
		int amounts=0, here=0;
		cout << "please don't enter any space between each value\n";
		cout << "input key --->($ to stop;| to sperate data, but you must use at same place below)\n";
		char c;
		vector<char> vec1;
		while(cin >> c){
			if(c=='$') break;
			else vec1.push_back(c);
		}
		cout << "input key height-level --->(auto stop)\n";
		char i;string s="", tmp="";
		vector<string> vec;
		for(vector<char>::iterator it=vec1.begin();it!=vec1.end();it++){
			cin >> i;
			if(*it=='|' && vec.size()>0){
				for(vector<string>::iterator it=vec.begin();it!=vec.end();it++){
					cout << *it << ", ";
				}
				printf("////%d+%d\n", here, vec.size());
				here+=vec.size();
				vec.clear();
			}else{
				amounts+=1;
				if(i<0) break;
				else{
					if (*it=='0'){
						s = "0";
					}else{
						tmp = find(*it);
						s = "NOTE_"+tmp;
						tmp = i;
						s = s+tmp;
					}
					vec.push_back(s);
				}
			}
		}
		
		if(vec.size()>0)
			for(vector<string>::iterator it=vec.begin();it!=vec.end();it++)
				cout << *it << ", ";
		
		printf("\nSuccess : %d Keys \n\n\n", amounts);
	}
	
}

char find(char c){
	switch(c){
		case '1':
			return 'C';
		case '2':
			return 'D';
		case '3':
			return 'E';
		case '4':
			return 'F';
		case '5':
			return 'G';
		case '6':
			return 'A';
		case '7':
			return 'B';
		case '0':
			return 'x';
	}
}
