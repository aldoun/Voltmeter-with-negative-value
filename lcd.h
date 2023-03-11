/*
 * Name: mylcd.c
 * Author: Mahmoud Adel
 * Description: This file contains main information of lcd driver
 * Version: v1.0
 * */
 #use delay(clock=8000000)

/////////////////////////////////////
struct lcd_pin_map {
BOOLEAN rs;
BOOLEAN rw;
BOOLEAN enable;
BOOLEAN unused;
int data : 4;
} lcd;
/////////////////////////////////////
void Enable(boolean en)
{
   //change value of enable in lcd and output the value on the correct pin
   lcd.enable = en;
   if(en)
   output_high(pin_b2);
   else
   output_low(pin_b2);
}
void RW(boolean value)
{
   //change value of RW in lcd and output the value on the correct pin
   lcd.rw = value;
   if(value)
   output_high(pin_b1);
   else
   output_low(pin_b1);
}
void RS(boolean value)
{
   //change value of RS in lcd and output the value on the correct pin
   lcd.rs = value;
   if(value)
   output_high(pin_b0);
   else
   output_low(pin_b0);
}


boolean read_busy()
{
   //declare an int1 variable to recieve busy flag in
   boolean busy;

  
   //set tristate as given 
   
   set_tris_b(0xf0);
   
   
   //do output sequence as given
   RS(0);
   delay_us(1);
   RW(1);
   delay_us(1);
   Enable(1);
   delay_us(1);

   //read busy flag as given
   busy = input(PIN_b7);

   //follow end sequence as given
   Enable(0);
   delay_us(1);
   Enable(1);
   delay_us(1);
   Enable(0);   

   //set tristate again as given 
   set_tris_b(0x00);
   
   //return variable
   return busy;
   
}
void send_nibble(int data)
{
   
   //follow start sequence 
   RW(0);
   delay_us(1);
   
   //put value in data in lcd
   lcd.data = data;

   //and then cast LCD on port b as an int8 (like the casting example
   output_b((int8)lcd);

   //follow end sequence
   delay_us(1);
   Enable(1);
   delay_us(2);
   Enable(0);

}
void send_byte(int data,boolean IorD)
{
   int upper = data >> 4;
   //clear the upper nibble
   int lower = data; 
   //wait for busy flag to be zero
   
   while(read_busy());
   
   //follow sequence
   RS(IorD);
   delay_us(1);
   
   
   //send upper nibble by calling send_nibble
   send_nibble(upper);
   
   //send lower nibble by calling send_nibble
   send_nibble(lower);
   
}
void lcd_initial()
{
   
   //wait 15 msec
   delay_ms(15);
   
   //set rs as zero using function
   RS(0);
   
   //delay 1 us
   delay_us(1);
  
   //send nibble 0b0011
   send_nibble(3);
   
   //delay 5 msec
   delay_ms(5);
   
   //send nibble 0b0011
   send_nibble(3);
   
   //delay 5 msec
   delay_ms(5);
   
   //send nibble 0b0011
   send_nibble(3);
   
   //delay 5 msec
   delay_ms(5);
   
   //send nibble 0b0010
   send_nibble(2);
   
   //send byte 0b00100000 with iord 0
   send_byte(32, 0);
   
   //send byte 0b00001100 with iord 0
   send_byte(12, 0);
   
   //send byte 0b00000001 with iord 0
   send_byte(1, 0);
   
   //send byte 0b00000110 with iord 0
   send_byte(6, 0);
   
   
   
}
void lcd_putc(char ch)
{
   //if character is '\f'
   if(ch == '\f'){
     //send byte 1 with iord 0 and wait for 2 msec
     send_byte(1, 0);
     delay_ms(2);
   }

   //else 
   else
   //send byte (the input character) with iord 1
   send_byte(ch, 1);
   
   
}
