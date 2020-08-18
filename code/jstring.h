/* date = August 6th 2020 7:24 pm */

#ifndef JSTRING_H
#define JSTRING_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define internal static
#define global static
#define localPersist static

#define kiloBytes(value) ((value) * 1024LL)
#define megaBytes(value) (kiloBytes(value) * 1024LL)
#define gigaBytes(value) (megaBytes(value) * 1024LL)
#define teraBytes(value) (gigaBytes(value) * 1024LL)

#define DEFAULT_STRING_SIZE megaBytes(2)

//define a string
typedef struct {
    size_t alloc; //Stores the # of bytes allocated
    size_t length;
    char* data;
} jString;

//length of string
unsigned int jStrLen(const char* charStr) {
    unsigned int len = 0;
    char* p = (char*)charStr; 
    
    while(*p != '\0') {
        ++len;
        ++p;
    }
    
    return (len);
}

//create a new string
jString jStringNew(const char* charStr) {
    jString str;
    
    if (*charStr != NULL) {
        str.length = jStrLen(charStr);
        str.data = (char*)malloc(DEFAULT_STRING_SIZE);
        memmove(str.data,
                charStr,
                str.length);
        str.alloc = DEFAULT_STRING_SIZE; //2MB
        str.data[str.length] = '\0';
    } else {
        str.length = 0;
        str.data = (char*)malloc(1);
        str.alloc = 1;
        str.data[0] = '\0';
    }
    
    return (str);
}

//grow the string
inline internal void jStringGrow(jString* str) {
    str->data = (char*)realloc(str->data,
                               (str->alloc + megaBytes(2)));
    str->alloc = str->alloc + megaBytes(2);
}

void jStringAdd(jString* str, const char* newChars) {
    unsigned int strLength = str->length;
    unsigned int newCharLength = jStrLen(newChars);
    unsigned int newLength = strLength + newCharLength;
    
    if ((strLength + newCharLength) >= str->alloc) {
        jStringGrow(str);
    }
    memmove((str->data + str->length), 
            newChars, 
            newCharLength);
    str->data[newLength] = '\0';
    str->length = newLength;
}

//free memory after use
void jStringFree(jString* str) {
    free(str->data);
}

#endif //JSTRING_H
