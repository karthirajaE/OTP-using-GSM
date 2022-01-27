#include<reg51.h>
//#include"lcd_driver.h"
sbit r0=P1^0;
sbit r1=P1^1;
sbit r2=P1^2;
sbit r3=P1^3;
sbit c0=P1^4;
sbit c1=P1^5;
sbit c2=P1^6;
int arr[4][3] = {1,2,3,4,5,6,7,8,9,0,0,13};
int key();
unsigned char* key_rx();

unsigned char* key_rx(){
	unsigned char i=0,k;
	static unsigned char a[20];
	for(i=0;i<20;i++){
		k=key();
		if(k!=13){
			a[i] = k+48;
			wr_data(a[i]);
		}
		else{
			break;
		}
	}
	a[i] = '\0';
	return a;
}

int key(){
	int rv,cv;
	r1=r2=r3=r0=0;
	while((c1&c2&c0)==1);
	while(1){
	r0=0;
	r1=r2=r3=1;
	if((c0&c1&c2)==0){
		rv=0;
		break;
	}
	r1=0;
	r0=r2=r3=1;
	if((c0&c1&c2)==0){
		rv=1;
		break;
	}
	r2=0;
	r1=r0=r3=1;
	if((c0&c1&c2)==0){
		rv=2;
		break;
	}
	r3=0;
	r1=r2=r0=1;
	if((c0&c1&c2)==0){
		rv=3;
		break;
	}
}
	if(c0==0)
		cv=0;
	else if(c1==0)
		cv=1;
	else if(c2==0)
		cv=2;
	while((c1&c2&c0)==0);
	return arr[rv][cv];
}