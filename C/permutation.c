/*用1,2,3,...,9组成3个三位数 abc,def和ghi,每个数字恰好用一次，
	要求：abc:def:ghi=1:2:3。输出所有解*/
#include<stdio.h>

int main(){
	int abc, def, ghi;
	int a,b,c,d,e,f,g,h,i;
	for(abc=123; abc<=329; abc++){
		def = 2*abc;
		ghi = 3*abc;
		
		a = abc/100;
		b = (abc % 100) / 10;
		c = abc % 10;
		
		d = def/100;
		e = (def % 100) / 10;
		f = def % 10;

		g = ghi/100;
		h = (ghi % 100) / 10;
		i = ghi % 10;
		if(a+b+c+d+e+f+g+h+i == 45 && a*b*c*d*e*f*g*h*i == 362880){
			printf("%d %d %d\n",abc,def,ghi);
		}
	}
	return 0;
}
