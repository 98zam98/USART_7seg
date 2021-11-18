#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#include "hardware.h"



// digits   D3  D2  D1  D0
// LOGIC    W   X   Y   Z

#define z 0
#define y 1
#define x 2
#define w 3


//a = w + y + (x^z)'
#define a(reg) checkbit0(reg,w)|checkbit0(reg,y)|(!(checkbit0(reg,x)^checkbit0(reg,z)))
//b = w + x' + (y^z)'
#define b(reg) checkbit0(reg,w)|(!checkbit0(reg,x))|(!(checkbit0(reg,y)^checkbit0(reg,z)))
//c = w + x + y' + z
#define c(reg) checkbit0(reg,w)|checkbit0(reg,x)|(!checkbit0(reg,y))|checkbit0(reg,z)
//d = w +  x'(y'z)' + x(y^z)  
#define d(reg) checkbit0(reg,w)|(!checkbit0(reg,x)&(!((!checkbit0(reg,y))&checkbit0(reg,z))))|(checkbit0(reg,x)&(checkbit0(reg,y)^checkbit0(reg,z)))
//e = w + yz' + (x + y + z)'
#define e(reg) (checkbit0(reg,w)&!((!checkbit0(reg,x))&(!checkbit0(reg,y))&checkbit0(reg,z)))|(checkbit0(reg,y)&(!checkbit0(reg,z)))|(!(checkbit0(reg,x)|checkbit0(reg,y)|checkbit0(reg,z)))
//f = (y+z)' + w'x(yz)' 
#define f(reg) checkbit0(reg,w)|!(checkbit0(reg,y)|checkbit0(reg,z))|(!checkbit0(reg,w))&checkbit0(reg,x)&(!(checkbit0(reg,y)&checkbit0(reg,z)))
//g = w + (w' ( ( x' y ) + (x (y z)')))
#define g(reg) checkbit0(reg,w)|((!checkbit0(reg,w))&(((!checkbit0(reg,x))&(checkbit0(reg,y)))|(checkbit0(reg,x)&!(checkbit0(reg,y)&checkbit0(reg,z)))))


// =========================================================


void sev_seg_inti();

void sev_seg_flush(char x_var);

#endif /* SEV_SEG_H_ */