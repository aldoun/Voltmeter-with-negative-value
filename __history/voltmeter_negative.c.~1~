#include <16F88.h>
#device ADC=10
#include <string.h>
#use delay(clock=8000000)
#fuses NOWDT,NOPROTECT,NOLVP,INTRC_IO,NOMCLR
#include "lcd.h"
void main()
{
   //add your variables here
   
   
   
   char mystring[20];
   setup_oscillator(OSC_8MHZ | OSC_INTRC);
   setup_adc_ports(sAN0|sAN1|sAN2|sAN3);
   setup_adc(ADC_CLOCK_DIV_16);
   lcd_initial();
   
   lcd_putc('\f');
   lcd_putc('W');
   lcd_putc('e');
   lcd_putc('l');
   lcd_putc('c');
   lcd_putc('o');
   lcd_putc('m');
   lcd_putc('e');
   
   delay_ms(1000);
   while(1)
   {
      int16 digital;
      float analog;
      int8 i;
      set_adc_channel(1);
      delay_ms(1);
      digital =read_adc();
      if(digital <= 1)
      {
         set_adc_channel(4);
         delay_ms(1);
         digital =read_adc();
         if(digital <= 290){
               lcd_putc('\f');
               mystring = "1mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000); 
               continue;
         }
         else if(digital > 290 && digital <= 348){
               lcd_putc('\f');
               mystring = "2mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 348 && digital <= 406){
               lcd_putc('\f');
               mystring = "3mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 406 && digital <= 464){
               lcd_putc('\f');
               mystring = "4mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 464 && digital <= 521){
               lcd_putc('\f');
               mystring = "5mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 521 && digital <= 579){
               lcd_putc('\f');
               mystring = "6mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 579 && digital <= 637){
               lcd_putc('\f');
               mystring = "7mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 637 && digital <= 695){
               lcd_putc('\f');
               mystring = "8mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 695 && digital <= 753){
               lcd_putc('\f');
               mystring = "9mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
         else if(digital > 753){
               lcd_putc('\f');
               mystring = "10mV";
               for(i=0;i<strlen(mystring);i++)
               lcd_putc(mystring[i]);
               delay_ms(1000);
               continue;
         }
      }
      if(digital<1023)
      {
         analog = (digital*5/1024.0) * 2;
         
         //analog = (analog + (5/44999)) * 20 + 0.5;
         lcd_putc('\f');
         sprintf(mystring,"%3.6f",analog);
         for(i=0;i<strlen(mystring);i++)
         lcd_putc(mystring[i]);
         lcd_putc('V');
         delay_ms(1000);
      }
      else
      {
         set_adc_channel(2);
         delay_ms(1);
         digital =read_adc();
         if(digital<1023)
         {
            analog = digital*5/1024.0;
            analog = analog * 5;
            //analog = (analog - 2.5) * 20 + 0.5;
            lcd_putc('\f');
            sprintf(mystring,"%3.6f",analog);
            for(i=0;i<strlen(mystring);i++)
            lcd_putc(mystring[i]);
            lcd_putc('V');
            delay_ms(1000);
         }
         else
         {
            set_adc_channel(3);
            delay_ms(1);
            digital =read_adc();
            analog = digital*5/1024.0;
            analog = analog * 9;
            //analog = (analog - 2.5) * 20 + 0.5;
            lcd_putc('\f');
            sprintf(mystring,"%3.6f",analog);
            for(i=0;i<strlen(mystring);i++)
            lcd_putc(mystring[i]);
            lcd_putc('V');
            delay_ms(1000);
         }
      }
     
     
   }
}
