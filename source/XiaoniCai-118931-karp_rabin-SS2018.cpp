#include <iostream>
#include <string>

using namespace std;
const int ascii=16;  // d
const int primzahl=6999997; // q

// erste Schritt: k[i]=(a[i]*d^{m-1})+(a[i+1]*d^{m-2})+...+(a[i+m-2]*d^1)+a[i+m-1]
// zweite Schritt: do H(k[i])=k[i] mod p
int rechnen_pow_mod(string const& pattern){
	int sum_pow=1;
	int i=1;
	while(i<=pattern.length()-1){
		sum_pow=(sum_pow*ascii)%primzahl;
		i++;
	}
	return sum_pow;
}

void check_for_every_letter(string const& pattern,string const& text, int pattern_hashwert, int text_hashwert,int sum_pow){
	int m=0;
		while(m<text.length()-pattern.length()+1){
			if( pattern_hashwert==text_hashwert ){
				int n=0;
				while(n<pattern.length()){
					if( text[m+n] != pattern[n]){
						break;
					}
					n++;
				}
				if(n==pattern.length()){
					cout<< "Pattern wird am Index "<<m<<" bis "<<"Index "<<m+pattern.length()-1<<" gefunden"<<endl;
				}
			}
				if( m < text.length()-pattern.length() ){
					text_hashwert=( ascii*(text_hashwert-text[m]*sum_pow%primzahl+primzahl )+ text[pattern.length()+m])%primzahl ;
				}
		m++;	
		}
}

void karp_rabin(string const& pattern, string const& text, int primzahl ,int ascii){
	// T-Text P-Pattern
	int text_length=text.length(); //n
	int pattern_length=pattern.length(); //m
	if(text_length<pattern_length){
		cout<<"Es macht kein Sinn. Dein pattern_length ist zu gross."<<endl;
		return ;
	}
	//else{
		int pattern_hashwert=0; //p
		int text_hashwert=0; // t

		int sum_pow=rechnen_pow_mod(pattern);

		int j=0;
		while(j<pattern_length){
			pattern_hashwert=(ascii*pattern_hashwert+pattern[j])%primzahl;
			text_hashwert=(ascii*text_hashwert+text[j])%primzahl;
			j++;
		}

		check_for_every_letter(pattern,text,pattern_hashwert,text_hashwert,sum_pow);
		cout<<"Am Ende"<<endl;
		return ;
	//}
}

int main(){
	string pattern = "cba";  
    string text = "abccbaabc";  
    cout<<"Jezt finde wir string ' "<<pattern<<" ' << ";
    karp_rabin(pattern,text,primzahl,ascii);
	return 0;
}
