#ifndef timer_h
#define timer_h

	uint64_t time_begin;
	uint64_t time_current;
    int64_t nbrNano;

    static inline uint64_t rdtsc();
    void timer();
    int64_t getMicro();
    int64_t getNano();
    void setup_timer();

#endif