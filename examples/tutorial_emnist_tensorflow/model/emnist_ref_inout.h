#ifndef _EMNIST_REF_INOUT_H_
#define _EMNIST_REF_INOUT_H_
#include "emnist_model.h"

#define QMN(type, fraq, val)   (type)(val * (1u << (fraq)) + ((val >= 0)? 0.5f: -0.5f))
#define FRQ_BITS(int_part, el_type) ((sizeof(el_type)*8)-int_part-1)
#define INQ(val)   ((unsigned char)val)
#define PBQ(val)  (val)
#define IN_IMG_1_SHAPE {28,28,1}
#define IN_IMG_1_RANK (3)
#define IN_IMG_1 {\
INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),\
    INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 255.000000000),INQ( 255.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),\
    INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000),INQ( 0.000000000)\
};

#define OUT_PROB_1_SHAPE {26}
#define OUT_PROB_1_RANK (1)
#define OUT_PROB_1 {\
PBQ( 0.995107770),PBQ( 0.000012002),PBQ( 0.000000020),PBQ( 0.000000089),PBQ( 0.000000319),PBQ( 0.000006562),PBQ( 0.000163523),PBQ( 0.004668054),PBQ( 0.000000019),PBQ( 0.000000048),\
    PBQ( 0.000002859),PBQ( 0.000000078),PBQ( 0.000009990),PBQ( 0.000003079),PBQ( 0.000000008),PBQ( 0.000002969),PBQ( 0.000005244),PBQ( 0.000016414),PBQ( 0.000000086),PBQ( 0.000000039),\
    PBQ( 0.000000346),PBQ( 0.000000002),PBQ( 0.000000204),PBQ( 0.000000176),PBQ( 0.000000155),PBQ( 0.000000026)\
};

#endif // _EMNIST_REF_INOUT_H_