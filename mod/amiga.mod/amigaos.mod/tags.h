#ifndef TAGS_H
#define TAGS_H 
 
#include <brl.mod/blitz.mod/blitz.h>
#include <proto/utility.h>


struct TagItem *bbIntArrayToTagList(BBArray *tags);
void bbFreeTagList(struct TagItem *tags);

#endif