/* date = August 14th 2020 9:18 pm */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define kiloBytes(value) (value * 1024LL)
#define megaBytes(value) (kiloBytes(value) * 1024LL)
#define gigaBytes(value) (megaBytes(value) * 1024LL)
#define teraBytes(value) (gigaBtes(value) * 1024LL)

#define internal static
#define global static
#define localPersist static

#define DEFAULT_STRING_SIZE megaBytes(2)

#endif //MAIN_H

