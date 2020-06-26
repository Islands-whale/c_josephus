#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include "person.h"

typedef struct _Reader *Reader;

int reader_get_line_count(const char*, unsigned*);
Reader reader_new();
void reader_destroy(Reader);
void reader_init(Reader, const char*, unsigned);
int reader_get_people_data(Reader, Person*);

#endif