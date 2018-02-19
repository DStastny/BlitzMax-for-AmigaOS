#include "tags.h"
#include "amigaos.h"

struct TagItem *bbIntArrayToTagList(BBArray *tags)
{
	return IUtility->CloneTagItems(BBINTARRAYTOTAGS(tags));
}

void bbFreeTagList(struct TagItem *tags)
{
	IUtility->FreeTagItems(tags);
}

