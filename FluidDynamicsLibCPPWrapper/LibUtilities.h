
#ifndef _LIB_UTILITIES_H_
#define _LIB_UTILITIES_H_

//Only useful macros

// ABS(x) value of x
#ifndef ABS
#define ABS(x) (((x < 0)) ? -(x) : (x))
#endif

// Max(x,y)
#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif

// Min(x,y)
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif

#endif /*_LIB_UTLITIES_H_*/
