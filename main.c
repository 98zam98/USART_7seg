#include "config.h"
#include "led.h"
#include "led.c"
#include "macros.h"
#include "hardware.h"
#include <avr/interrupt.h>
#include "uart.h"
#include "uart.c"
#include "sev_seg.h"
#include "sev_seg.c"

int main()
{
  led_init();

  sev_seg_inti();

  char x_var = 0;
  char i;
  char aa = 0;
  char bb = 0;
  char cc = 0;
  char dd = 0;
  char ee = 0;
  char ff = 0;
  char gg = 0;

  zUART0.zusart_x2_mode = x2_no;
  zUART0.zusart_baud = 9600;
  zUART0.zusart_mode = usart_Asynchronous;
  zUART0.zusart_multi_processor_communication_mode = multi_processor_no;
  zUART0.zusart_int_mode = int_enable_rx_tx;
  zUART0.zusart_transmit_receive_mode = transmit_receive_mode_both;
  zUART0.zusart_CH_size = CH_size_8;
  zUART0.zusart_parity_mode = parity_Disabled;
  zUART0.zusart_stop_bit_mode = stop_1_bit;
  const uint8_t start[] = "ZAM Program Start\n\r";
  uint8_t data = 'A';

  uart_init();
  sei();

  uart_send_string(start);
  while (1)
  {

    if (uart_read_count() > 0)
    {
      data = uart_read();
      uart_send_byte(data);
    }
    if ((data >= '0') && (data <= '9'))
    {
      i = data - 48;
      
      x_var = 0;

      aa = a(i);
      bb = b(i);
      cc = c(i);
      dd = d(i);
      ee = e(i);
      ff = f(i);
      gg = g(i);

      assignbit(x_var, abit, aa);
      assignbit(x_var, bbit, bb);
      assignbit(x_var, cbit, cc);
      assignbit(x_var, dbit, dd);
      assignbit(x_var, ebit, ee);
      assignbit(x_var, fbit, ff);
      assignbit(x_var, gbit, gg);
      sev_seg_flush(x_var);
      led_ontooff(i, (10-i));
    }
    else if (data == 'b')
    {
      led_on();
    }
    else if (data == 'd')
    {
      led_off();
    }
    else if (data == 'a')
    {
      led_toggle();
    }
  }
  return 0;
}
//void led_ontooff(char on,char off);
