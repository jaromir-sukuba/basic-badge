#include <xc.h>
#include "hw.h"
#include "disp.h"

const char font[96*12] = 
{
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0000000, 0b0001000, 0b0000000, 0b0000000,   
0b0101000, 0b0101000, 0b0101000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0010100, 0b0010100, 0b0010100, 0b1111111, 0b0010100, 0b0010100, 0b1111111, 0b0010100, 0b0010100, 0b0010100, 0b0000000, 0b0000000,   
0b0010100, 0b0111110, 0b1010101, 0b1010100, 0b0111110, 0b0010101, 0b0010101, 0b1010101, 0b0111110, 0b0010100, 0b0000000, 0b0000000,   
0b0000000, 0b1110000, 0b1010001, 0b1110010, 0b0000100, 0b0001000, 0b0010000, 0b0100111, 0b1000101, 0b0000111, 0b0000000, 0b0000000,   
0b0111000, 0b1000100, 0b1000100, 0b1001000, 0b0110000, 0b0110000, 0b1001000, 0b1000101, 0b1000010, 0b0111101, 0b0000000, 0b0000000,   
0b0011000, 0b0011000, 0b0010000, 0b0100000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0001000, 0b0000100, 0b0000010, 0b0000000, 0b0000000,   
0b0100000, 0b0010000, 0b0001000, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b0000000, 0b0000000,   
0b0000000, 0b0001000, 0b1001001, 0b0101010, 0b0011100, 0b1111111, 0b0011100, 0b0101010, 0b1001001, 0b0001000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0001000, 0b0001000, 0b0001000, 0b1111111, 0b0001000, 0b0001000, 0b0001000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0011000, 0b0011000, 0b0010000, 0b0100000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1111111, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0110000, 0b0110000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1000000, 0b0000000, 0b0000000, 0b0000000,   
0b0011100, 0b0100010, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0011100, 0b0000000, 0b0000000,   
0b0001000, 0b0011000, 0b0101000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0111110, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000001, 0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1111111, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b0000001, 0b0000010, 0b0001100, 0b0000010, 0b0000001, 0b0000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b0000010, 0b0000110, 0b0001010, 0b0010010, 0b0100010, 0b1000010, 0b1000010, 0b1111111, 0b0000010, 0b0000010, 0b0000000, 0b0000000,   
0b1111111, 0b1000000, 0b1000000, 0b1111100, 0b0000010, 0b0000001, 0b0000001, 0b0000001, 0b1000010, 0b0111100, 0b0000000, 0b0000000,   
0b0001110, 0b0010000, 0b0100000, 0b1000000, 0b1111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1111111, 0b0000001, 0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b0100000, 0b0100000, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000001, 0b0100010, 0b0011100, 0b0100010, 0b1000001, 0b1000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0111111, 0b0000001, 0b0000010, 0b0000100, 0b0111000, 0b0000000, 0b0000000,   
0b0000000, 0b0011000, 0b0011000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0011000, 0b0011000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0011000, 0b0011000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0011000, 0b0011000, 0b0010000, 0b0000000, 0b0000000,   
0b0000000, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b0010000, 0b0001000, 0b0000100, 0b0000010, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1111111, 0b0000000, 0b1111111, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0100000, 0b0010000, 0b0001000, 0b0000100, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0010000, 0b0000000, 0b0010000, 0b0000000, 0b0000000,   
0b0011100, 0b0100010, 0b1000001, 0b1001001, 0b1010101, 0b1010110, 0b1001000, 0b1000000, 0b0100001, 0b0011110, 0b0000000, 0b0000000,   
0b0001000, 0b0010100, 0b0100010, 0b1000001, 0b1000001, 0b1000001, 0b1111111, 0b1000001, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b1111110, 0b1000001, 0b1000001, 0b1000010, 0b1111100, 0b1000010, 0b1000001, 0b1000001, 0b1000001, 0b1111110, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1111100, 0b1000010, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000010, 0b1111100, 0b0000000, 0b0000000,  
0b1111111, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1111110, 0b1000000, 0b1000000, 0b1000000, 0b1111111, 0b0000000, 0b0000000,   
0b1111111, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1111110, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000000, 0b1000000, 0b1000000, 0b1001111, 0b1000001, 0b1000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1111111, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b0011100, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0011100, 0b0000000, 0b0000000,   
0b0000001, 0b0000001, 0b0000001, 0b0000001, 0b0000001, 0b0000001, 0b1000001, 0b1000001, 0b0100010, 0b0011100, 0b0000000, 0b0000000,   
0b1000001, 0b1000010, 0b1000100, 0b1001000, 0b1110000, 0b1010000, 0b1001000, 0b1000100, 0b1000010, 0b1000001, 0b0000000, 0b0000000,   
0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1111111, 0b0000000, 0b0000000,   
0b1000001, 0b1100011, 0b1010101, 0b1001001, 0b1001001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1100001, 0b1010001, 0b1001001, 0b1000101, 0b1000011, 0b1000001, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1111110, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000101, 0b1000010, 0b0111101, 0b0000000, 0b0000000,   
0b1111110, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1111110, 0b1001000, 0b1000100, 0b1000010, 0b1000001, 0b0000000, 0b0000000,   
0b0111110, 0b1000001, 0b1000000, 0b0100000, 0b0011100, 0b0000010, 0b0000001, 0b0000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1111111, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0111110, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0010100, 0b0001000, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1001001, 0b1010101, 0b1100011, 0b1000001, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0010100, 0b0001000, 0b0010100, 0b0100010, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0010100, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0000000, 0b0000000,   
0b1111111, 0b0000001, 0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1000000, 0b1111111, 0b0000000, 0b0000000,   
0b0011100, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0011100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b1000000, 0b0100000, 0b0010000, 0b0001000, 0b0000100, 0b0000010, 0b0000001, 0b0000000, 0b0000000, 0b0000000,   
0b0011100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0011100, 0b0000000, 0b0000000,   
0b0001000, 0b0010100, 0b0100010, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b1111111, 0b0000000, 0b0000000,   
0b0010000, 0b0001000, 0b0000100, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0111100, 0b0000010, 0b0000001, 0b0111111, 0b1000001, 0b1000011, 0b0111101, 0b0000000, 0b0000000,   
0b1000000, 0b1000000, 0b1000000, 0b1111100, 0b1000010, 0b1000001, 0b1000001, 0b1000001, 0b1000010, 0b1111100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0011111, 0b0100000, 0b1000000, 0b1000000, 0b1000000, 0b0100000, 0b0011111, 0b0000000, 0b0000000,   
0b0000001, 0b0000001, 0b0000001, 0b0011111, 0b0100001, 0b1000001, 0b1000001, 0b1000001, 0b0100001, 0b0011111, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0111110, 0b1000001, 0b1000001, 0b1111111, 0b1000000, 0b1000000, 0b0111111, 0b0000000, 0b0000000,   
0b0000110, 0b0001000, 0b0001000, 0b0001000, 0b0011110, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0011100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0011100, 0b0100010, 0b1000001, 0b1000001, 0b0100001, 0b0011111, 0b0000001, 0b0000001, 0b0011110,   
0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1011100, 0b1100010, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b0000000, 0b0001000, 0b0000000, 0b0011000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0011100, 0b0000000, 0b0000000,   
0b0000000, 0b0000100, 0b0000000, 0b0001100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0000100, 0b0100100, 0b0011000,   
0b1000000, 0b1000000, 0b1000000, 0b1000011, 0b1000100, 0b1001000, 0b1011000, 0b1100100, 0b1000010, 0b1000001, 0b0000000, 0b0000000,   
0b0011000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0011100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1010110, 0b1101001, 0b1001001, 0b1001001, 0b1001001, 0b1001001, 0b1001001, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1011100, 0b1100010, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0011100, 0b0100010, 0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0011100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1111100, 0b1000010, 0b1000001, 0b1000001, 0b1000010, 0b1111100, 0b1000000, 0b1000000, 0b1000000,   
0b0000000, 0b0000000, 0b0000000, 0b0011111, 0b0100001, 0b1000001, 0b1000001, 0b0100001, 0b0011111, 0b0000001, 0b0000001, 0b0000001,   
0b0000000, 0b0000000, 0b0000000, 0b1011110, 0b1100001, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b1000000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0111111, 0b1000000, 0b1000000, 0b0111110, 0b0000001, 0b0000001, 0b1111110, 0b0000000, 0b0000000,   
0b0010000, 0b0010000, 0b0010000, 0b0111100, 0b0010000, 0b0010000, 0b0010000, 0b0010000, 0b0010010, 0b0001100, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b1000011, 0b0111101, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0100010, 0b0010100, 0b0001000, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1000001, 0b1000001, 0b1000001, 0b1001001, 0b1010101, 0b1100011, 0b1000001, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1000001, 0b0100010, 0b0010100, 0b0001000, 0b0010100, 0b0100010, 0b1000001, 0b0000000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b1000001, 0b1000001, 0b1000001, 0b1000001, 0b0100001, 0b0011111, 0b0000001, 0b0000010, 0b0111100,   
0b0000000, 0b0000000, 0b0000000, 0b1111111, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1111111, 0b0000000, 0b0000000,   
0b0000110, 0b0001000, 0b0001000, 0b0001000, 0b0010000, 0b0100000, 0b0010000, 0b0001000, 0b0001000, 0b0001000, 0b0000110, 0b0000000,   
0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0001000, 0b0000000, 0b0000000,   
0b0110000, 0b0001000, 0b0001000, 0b0001000, 0b0000100, 0b0000010, 0b0000100, 0b0001000, 0b0001000, 0b0001000, 0b0110000, 0b0000000,   
0b0000000, 0b0000000, 0b0000000, 0b0110000, 0b1001000, 0b0001001, 0b0000110, 0b0000000, 0b0000000, 0b0000000, 0b0000000, 0b0000000,   
0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b1111111, 0b0000000, 0b0000000
	};



void tft_disp_buffer_refresh(unsigned char * buff, unsigned int col, unsigned int back)
	{
	unsigned int i,j,ad;
	for (i=0;i<20;i++)
		for (j=0;j<40;j++)	
			tft_print_char(buff[j+(i*40)],j*8,i*12,col,back);
	}

void tft_disp_buffer_refresh_part(unsigned char * buff, unsigned int col, unsigned int back)
	{
    static unsigned char dr_cnt=0;
	unsigned int i,j,ad;
	for (i=(dr_cnt);i<(dr_cnt+2);i++)
		for (j=0;j<40;j++)	
			tft_print_char(buff[j+(i*40)],j*8,i*12,col,back);
    dr_cnt = dr_cnt + 2;
    if (dr_cnt == 20)
        dr_cnt = 0;

    }



inline void tft_print_char (unsigned char val, unsigned int x, unsigned int y, unsigned int col, unsigned int back)
	{
	unsigned int fl,i,j;
	unsigned int c1,c2,c3,b1,b2,b3;
	c1 = (col>>16)&0xFF;
	c2 = (col>>8)&0xFF;
	c3 = (col>>0)&0xFF;
	b1 = (back>>16)&0xFF;
	b2 = (back>>8)&0xFF;
	b3 = (back>>0)&0xFF;
	tft_set_write_area(x,y,7,11);
	TFT_24_7789_Write_Command(0x2C);
	if (val<' ')
		{
		for (i=0;i<12;i++)
			{
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			TFT_24_7789_Write_Data3(b1,b2,b3);
			}
				
		}
	else
		{
		for (i=0;i<12;i++)
			{
			fl = font[i+12*(val-' ')];
			if (fl&0x80)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x40)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x20)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x10)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x08)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x04)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);				
			if (fl&0x02)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);
			if (fl&0x01)
				TFT_24_7789_Write_Data3(c1,c2,c3);
			else
				TFT_24_7789_Write_Data3(b1,b2,b3);	
			}
		}
	}


void tft_fill_area (unsigned int x, unsigned int y, unsigned int xlen, unsigned int ylen, unsigned int back)
{
    unsigned int i,j;
    tft_set_write_area(x,y,xlen,ylen);
    TFT_24_7789_Write_Command(0x2C);
    //FIXME: Why do I need these +1 adjustments. Off-by-one in tft_set_write_area?
    for (i=0; i<((xlen+1)*(ylen+1)); i++)
    {
	TFT_24_7789_Write_Data3((back>>16)&0xFF,(back>>8)&0xFF,(back>>0)&0xFF);
    }
}

inline void tft_set_write_area (unsigned int x, unsigned int y, unsigned int xlen, unsigned int ylen)
	{
	TFT_24_7789_Write_Command(0x002A);
	TFT_24_7789_Write_Data((x>>8)&0xFF);
	TFT_24_7789_Write_Data((x>>0)&0xFF);
	TFT_24_7789_Write_Data(((x+xlen)>>8)&0xFF);
	TFT_24_7789_Write_Data(((x+xlen)>>0)&0xFF);
	TFT_24_7789_Write_Command(0x2B);
	TFT_24_7789_Write_Data((y>>8)&0xFF);
	TFT_24_7789_Write_Data((y>>0)&0xFF);
	TFT_24_7789_Write_Data(((y+ylen)>>8)&0xFF);
	TFT_24_7789_Write_Data(((y+ylen)>>0)&0xFF);
	}



/*******************************************************************************/
void TFT_24_7789_Write_Command(unsigned int command)
{
LCD_RD = 1;
LCD_DC = 0;
LCD_WR_CLR;
LCD_PORT = command;
LCD_WR_SET;
LCD_DC = 1;
}
/*******************************************************************************/
inline void TFT_24_7789_Write_Data(unsigned int data1)
{
LCD_WR_CLR;
LCD_PORT = data1;
LCD_WR_SET;
}

inline void TFT_24_7789_Write_Data3(unsigned int data1,unsigned int data2, unsigned int data3)
{
LCD_WR_CLR;
LCD_PORT = data1;
LCD_WR_SET;
LCD_WR_CLR;
LCD_PORT = data2;
LCD_WR_SET;
LCD_WR_CLR;
LCD_PORT = data3;
LCD_WR_SET;
}

/*******************************************************************************/
void TFT_24_7789_Init(void)
{
LCD_RES = 0;
LCD_RD = 1;
LCD_WR = 1;
//wait_ms(2);
LCD_RES = 1;
wait_ms(2);
TFT_24_7789_Write_Command(0x0029);//exit SLEEP mode
wait_ms(2);
TFT_24_7789_Write_Command(0x0036);
TFT_24_7789_Write_Data(0x70);//MADCTL: memory data access control
TFT_24_7789_Write_Command(0x003A);
TFT_24_7789_Write_Data(0x0066);//COLMOD: Interface Pixel format
TFT_24_7789_Write_Command(0x00B2);
TFT_24_7789_Write_Data(0x0C);
TFT_24_7789_Write_Data(0x0C);
TFT_24_7789_Write_Data(0x00);
TFT_24_7789_Write_Data(0x33);
TFT_24_7789_Write_Data(0x33);//PORCTRK: Porch setting
TFT_24_7789_Write_Command(0x00B7);
TFT_24_7789_Write_Data(0x0035);//GCTRL: Gate Control
TFT_24_7789_Write_Command(0x00BB);
TFT_24_7789_Write_Data(0x002B);//VCOMS: VCOM setting
TFT_24_7789_Write_Command(0x00C0);
TFT_24_7789_Write_Data(0x002C);//LCMCTRL: LCM Control
TFT_24_7789_Write_Command(0x00C2);
TFT_24_7789_Write_Data(0x0001);
TFT_24_7789_Write_Data(0xFF);//VDVVRHEN: VDV and VRH Command Enable
TFT_24_7789_Write_Command(0x00C3);
TFT_24_7789_Write_Data(0x0011);//VRHS: VRH Set
TFT_24_7789_Write_Command(0x00C4);
TFT_24_7789_Write_Data(0x0020);//VDVS: VDV Set[10]
TFT_24_7789_Write_Command(0x00C6);
TFT_24_7789_Write_Data(0x000F);//FRCTRL2: Frame Rate control in normal mode
TFT_24_7789_Write_Command(0x00D0);
TFT_24_7789_Write_Data(0x00A4);
TFT_24_7789_Write_Data(0xA1);//PWCTRL1: Power Control 1
TFT_24_7789_Write_Command(0x00E0);
TFT_24_7789_Write_Data(0x00D0);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0005);
TFT_24_7789_Write_Data(0x000E);
TFT_24_7789_Write_Data(0x0015);
TFT_24_7789_Write_Data(0x000D);
TFT_24_7789_Write_Data(0x0037);
TFT_24_7789_Write_Data(0x0043);
TFT_24_7789_Write_Data(0x0047);
TFT_24_7789_Write_Data(0x0009);
TFT_24_7789_Write_Data(0x0015);
TFT_24_7789_Write_Data(0x0012);
TFT_24_7789_Write_Data(0x0016);
TFT_24_7789_Write_Data(0x0019);//PVGAMCTRL: Positive Voltage Gamma control
TFT_24_7789_Write_Command(0x00E1);
TFT_24_7789_Write_Data(0x00D0);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0005);
TFT_24_7789_Write_Data(0x000D);
TFT_24_7789_Write_Data(0x000C);
TFT_24_7789_Write_Data(0x0006);
TFT_24_7789_Write_Data(0x002D);
TFT_24_7789_Write_Data(0x0044);
TFT_24_7789_Write_Data(0x0040);
TFT_24_7789_Write_Data(0x000E);
TFT_24_7789_Write_Data(0x001C);
TFT_24_7789_Write_Data(0x0018);
TFT_24_7789_Write_Data(0x0016);
TFT_24_7789_Write_Data(0x0019);//NVGAMCTRL: Negative Voltage Gamma control
TFT_24_7789_Write_Command(0x002A);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0001);
TFT_24_7789_Write_Data(0x003F);//X address set
TFT_24_7789_Write_Command(0x002B);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x0000);
TFT_24_7789_Write_Data(0x00EF);//Y address set
TFT_24_7789_Write_Command(0x11);
TFT_24_7789_Write_Command(0x38);
TFT_24_7789_Write_Command(0x13);

}
/*******************************************************************************/

