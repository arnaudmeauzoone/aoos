#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "timer.h"

static inline uint64_t rdtsc()
{
    uint64_t ret;
    asm volatile ( "rdtsc" : "=A"(ret) );
    return ret;
}

int64_t getNano(){

  return nbrNano;

}

int64_t getMicro(){

return ((float)nbrNano/(1000));

}    
void setup_timer() {

    time_begin =rdtsc();
    time_current =rdtsc();
    nbrNano =0;
}


void timer(){
        
		time_current = rdtsc();
		if(time_current - time_begin >= 2564){
			nbrNano++;
			time_begin = time_current;
			// 1 nanosecond = 2564 ticks
}
}