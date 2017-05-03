#ifndef CGDS_QUEUE_H_

#include <cgds/cgds_tool.h>


#define CGDS_GENERATE_QUEUE_INC( name, type )\
typedef type name##Val;\
typedef struct _##name##Entry\
{\
	name##Val data;\
	struct _##name##Entry *next;\
}name##Entry;\
\
typedef struct _##name\
{\
	name##Entry *head;\
	name##Entry *tail;\
	/*You should not visit this value*/\
	int _LENGTH;\
}name;\
\
void name##_new( name ** queue );\
void name##_free( name ** queue);\
int name##_en( name * queue, name##Val data);\
name##Val name##_de(name * queue);\
name##Val name##_first( name * queue );\
int name##_length( name * queue );\
int name##_isEmpty( name * queue);


#define  CGDS_GENERATE_QUEUE_SRC( name, type )\
void name##_new( name ** queue ) {\
	name *queueNew;\
	queueNew = (name *) malloc(sizeof(name));\
	if (!queueNew){\
		*queue = NULL;\
		return;\
	}\
	queueNew->head = NULL;\
	queueNew->tail = NULL;\
	queueNew->_LENGTH = 0;\
	*queue = queueNew;\
}\
\
void name##_free( name ** queue ) {\
	name *thequeue = *queue;\
	if(*queue == NULL)\
		return;\
	while (thequeue->_LENGTH){\
		name##_de(thequeue);\
	}\
	free(thequeue);\
	*queue = NULL;\
}\
\
int name##_en( name * queue, name##Val data) {\
	name##Entry *new_entry = (name##Entry *)(malloc(sizeof(name##Entry)));\
	if (new_entry == NULL){\
		return FAILURE;\
	}\
	if (queue == NULL){\
		free(new_entry);\
		return FAILURE;\
	}\
	new_entry->data = data;\
	new_entry->next = NULL;\
	if (queue->tail == NULL){\
		queue->tail = new_entry;\
		queue->head = new_entry;\
	}\
	else{\
		queue->tail->next = new_entry;\
		queue->tail = queue->tail->next;\
	}\
	(queue->_LENGTH)++;\
	return SUCCESS;\
}\
\
name##Val name##_de( name * queue ) {\
	name##Val resultData;\
	name##Entry *del_entry;\
	memset(&resultData, 0, sizeof(name##Val));\
	if (queue == NULL || queue->head == NULL){\
		return resultData;\
	}\
	resultData = queue->head->data;\
	(queue->_LENGTH)--;\
	if (queue->tail == queue->head){\
		free(queue->head);\
		queue->tail = NULL;\
		queue->head = NULL;\
	}\
	else{\
		del_entry = queue->head;\
		queue->head = queue->head->next;\
		free(del_entry);\
	}\
	return resultData;\
}\
name##Val name##_first( name * queue ) {\
	name##Val resultData;\
	memset(&resultData, 0, sizeof(name##Val));\
	if (queue->tail == NULL)\
		return resultData;\
	return queue->tail->data;\
}\
\
int name##_length( name * queue ) {\
	return queue->_LENGTH;\
}\
\
int name##_isEmpty( name * queue) {\
	return queue->_LENGTH ? 0 : 1;\
}
//#define CGDS_GENERATE_QUEUE_INC( name, type )\
//typedef type name##Val;\
//typedef struct _##name##Entry\
//{\
//	name##Val data;\
//	struct _##name##Entry *prev;\
//	struct _##name##Entry *next;\
//}name##Entry;\
//\
//typedef struct _##name##Queue\
//{\
//	name##Entry *head;\
//	name##Entry *tail;\
//	int length;\
//}name;\
//\
//void name##_new( name ** queue );\
//int name##_en( name * queue, name##Val data);\
//name##Val name##_de( name * queue );\
//name##Val name##_first( name * queue );\
//void name##_free( name ** queue);
//
//
//#define CGDS_GENERATE_QUEUE_SRC( name, type )\
//void name##_new( name ** queue){\
//	name *queueNew;\
//	queueNew = (name *) malloc(sizeof(name));\
//	if (!queueNew){\
//		*queue = NULL;\
//		return;\
//	}\
//	queueNew->head = NULL;\
//	queueNew->tail = NULL;\
//	queueNew->length = 0;\
//	*queue = queueNew;\
//}\
//void name##_free( name ** queue){\
//	name *thequeue = *queue;\
//	if(*queue == NULL)\
//		return;\
//	while (thequeue->length){\
//		name##_de(thequeue);\
//	}\
//	free(thequeue);\
//	*queue = NULL;\
//}\
//\
//int name##_en( name * queue, name##Val data){\
//	name##Entry *new_entry = (name##Entry *)(malloc(sizeof(name##Entry)));\
//	if (new_entry == NULL){\
//		return FAILURE;\
//	}\
//	if (queue == NULL){\
//		free(new_entry);\
//		return FAILURE;\
//	}\
//	new_entry->data = data;\
//	new_entry->next = NULL;\
//	new_entry->prev = NULL;\
//	if (queue->head == NULL){\
//		queue->head = new_entry;\
//		queue->tail = new_entry;\
//	}else{\
//		new_entry->next = queue->head;\
//		queue->head->prev = new_entry;\
//		queue->head = new_entry;\
//	}\
//	(queue->length)++;\
//	return SUCCESS;\
//}\
//\
//name##Val name##_de( name * queue ){\
//	name##Val resultData;\
//	name##Entry *del_entry;\
//	if (queue == NULL || queue->tail == NULL){\
//		return ((name##Val)(0));\
//	}\
//	resultData = queue->tail->data;\
//	(queue->length)--;\
//	if (queue->tail == queue->head){\
//		free(queue->tail);\
//		queue->tail = NULL;\
//		queue->head = NULL;\
//	}\
//	else{\
//		del_entry = queue->tail;\
//		queue->tail->prev->next = NULL;\
//		queue->tail = queue->tail->prev;\
//		free(del_entry);\
//	}\
//	return resultData;\
//}\
//\
//name##Val name##_first( name * queue ){\
//	if (queue->tail == NULL)\
//		return ((name##Val)(0));\
//	return queue->tail->data;\
//}


#endif


