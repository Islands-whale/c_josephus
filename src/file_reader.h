#ifndef __FILE_READER_H__
#define __FILE_READER_H__

#include "person.h"

typedef struct Reader Reader;

int reader_get_line_count(const char*, unsigned*);
Reader* reader_new();
int reader_destroy(Reader*);
int reader_create(Reader*, char*, unsigned);
int reader_get_people_data(Reader*, Person**);

#endif