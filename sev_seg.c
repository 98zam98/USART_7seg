#include "sev_seg.h"



void sev_seg_inti()
{
    
  sev_seg_dir_low = 0x0F;
  sev_seg_PORT_low &= 0xF0;

  sev_seg_dir_high = 0xF0;
  sev_seg_PORT_high &= 0x0F;

}

void sev_seg_flush(char x_var)
{
    

      sev_seg_PORT_low &= 0xF0;
      sev_seg_PORT_low |= (x_var & 0x0F);

      sev_seg_PORT_high &= 0x0F;
      sev_seg_PORT_high |= (x_var & 0xF0);
}