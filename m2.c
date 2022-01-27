#include<reg51.h>
#include<stdlib.h>
#include"lcd_driver.h"
#include"key_pad_driver.h"
#include"uart_driver.h"
unsigned short int otp(unsigned char *);

void main(){
	unsigned char *m;
	unsigned short int n;
	while(1){
		initial();
		start();
		wr_string("mob no:");
		m = key_rx();
		wr_command(0xc0);
		wr_string("generating OTP...");
		n = otp(m);
		wr_command(0x94);
		wr_string("enter the OTP : ");
		if(n == atoi(key_rx())){
			wr_command(0xd4);
			wr_string("access granted...");
			delay(1000);
		}
		else{
			wr_command(0xd4);
			wr_string("wrong OTP..");
			delay(1000);
		}
	}
}

unsigned short int otp(unsigned char *m){
	unsigned short int n;
	n = (rand()%9999-1000+1)+1000;
	string_tx("AT");
	tx(13);
	delay(500);
	string_tx("AT+CMGF=1");
	tx(13);
	delay(500);
	string_tx("AT+CMGS=\"");
	string_tx(m);
	string_tx("\"");
	tx(13);
	delay(500);
	string_tx("you got otp from at89c51 : ");
	int_tx(n);
	delay(100);
	tx(0x1a);
	delay(500);
	return n;
}