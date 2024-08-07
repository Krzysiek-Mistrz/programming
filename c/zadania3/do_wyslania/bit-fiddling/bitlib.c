#include "bitlib.h"

void decompose_into_bytes(uint16_t val, uint8_t* byte_hi, uint8_t* byte_lo) {
    *byte_hi = (uint8_t) (val >> 8U);   //przesuwamy o 8 bitow w prawo wartosc val, a pozniej rzutujemy obcinajac najbardziej znaczace nie zmieniajac zmiennej val 16 bit
    *byte_lo = (uint8_t) val;   
}

int last_two_bits(int val) {
    return (int)(val & 0x03); //0x03 to 00000011
}
