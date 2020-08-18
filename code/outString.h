/* date = August 14th 2020 9:18 pm */

#ifndef OUTSTRING_H
#define OUTSTRING_H

typedef struct {
    char* data;
    uint32_t allocation;
    size_t length;
} outString;

internal void outStringUpdateLength(outString* str) {
    int i = 0;
    
    while (str->data[i] != '\0') {
        i = i + 1;
    }
    
    str->length = i;
}

#endif //OUTSTRING_H