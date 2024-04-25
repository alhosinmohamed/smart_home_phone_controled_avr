#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define set_Bit(var, Bit)     (var |= (1 << (Bit)))
#define clear_Bit(var, Bit)   (var &= ~(1 << (Bit)))
#define toggle_Bit(var, Bit)  (var ^= (1 << (Bit)))
#define get_Bit(var, Bit)     ((var >> (Bit)) & 1)

#endif
