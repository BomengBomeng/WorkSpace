#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 1000;
struct bign{
	int len;
	char s[maxn];
	//无参构造
	bign(){
		memset(s, 0, sizeof(s));
		len=1;
	}
	//重载赋值符
	bign operator = (const char *num){
		len = strlen(num);
		//逆置存入数组
		for(int i=0; i<len; i++)
			s[i] = num[len-i-1]-'0';
		return *this;
	}
	bign operator = (int num){
		len=0;
		while(num>0){
			s[len++] = num%10;
			num /= 10;
		}
		return *this;	
	}
	//有参构造
	bign(int num){	//调用赋值运算重载1
		*this = num;
	}
	bign(const char *num){	//调用赋值运算重载2
		*this = num;
	}
	//转发为字符串
	string str() const {
		string res = "";
		for(int i=0; i<len; i++)
			res = (char)(s[i]+'0') + res;
		if(res=="")
			res = "0";
		return res;
	}
	void clean(){
		while(len>1 &&!s[len-1])
			len--;
	}
	//重载 + 
	bign operator + (const bign &b) const{
		bign c;
		c.len = 0;
		for(int i=0, g=0; g || i<max(len, b.len); i++ ){
			int x=g;
			if(i<len)
				x += s[i];
			if(i<b.len)
				x += b.s[i];
			c.s[c.len++] = x%10;
			g = x/10;
		}
		return c;
	}
	//重载 -
	bign operator - (const bign &b){
		bign c;
		c.len = 0;
		for(int i=0,g=0; i<len; i++){
			int x = s[i]-g;
			if(i<b.len)
				x -= b.s[i];
			if(x >= 0)
				g = 0;
			else{
				g = 1;
				x += 10;
			}
			c.s[c.len++] = x;
		}
		c.clean();
		return c;
	}
	//重载 * 
	bign operator * (const bign &b) {
		bign c;
		c.len = len+b.len;
		for(int i=0; i<len ;i++)
			for(int j=0; j<b.len; j++)
				c.s[i+j] += s[i]*b.s[j];
		for(int i=0; i<c.len-1; i++){
			c.s[i+1] += c.s[i]/10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}
	//重载 += -= *=
	bign operator += (const bign &b){
		*this = *this + b;
		return *this;
	}
	bign operator -= (const bign &b){
		*this = *this -b;
		return *this;
	}
	bign operator *= (const bign &b){
		*this = *this *b;
		return *this;
	}
	//重载 < > <= >= != ==
	bool operator < (const bign &b) const{
		if(len!=b.len)
			return len < b.len;
		for(int i=len-1; i>=0; i--)
			if(s[i]!=b.s[i])
				return s[i]<b.s[i];
		return false;	//相等
	}
	bool operator > (const bign &b) const{
		return b<*this;
	}
	bool operator <= (const bign &b) const{
		return !(b<*this);
	}
	bool operator >= (const bign &b) const{
		return !(*this<b);
	}
	bool operator != (const bign &b) const{
		return b<*this || *this<b;
	}
	bool operator == (const bign &b) const{
		return !(b<*this) || !(*this<b);
	}
};
	
//重载>>
istream& operator >> (istream &in, bign &x){
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

//重载<<
ostream& operator<<(ostream &out, const bign &x){
	out << x.str();
	return out;
}	

int main(){
	bign a,b;
	cin >> a >> b;
	cout << a*b << endl;
	return 0;
}
