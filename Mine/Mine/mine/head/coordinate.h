#ifndef COORDINATE_H_
#define COORDINATE_H_

#include "cgds/cgds_queue.h"



typedef	struct _coordinate {
	int x;
	int y;
}Coordinate;

CGDS_GENERATE_QUEUE_INC( CoordinateQueue, Coordinate )

#endif // !COORDINATE_H_
