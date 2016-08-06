#ifndef timer_h
#define timer_h

bool timerEnabled;

struct program {

	bool clear_con;

};

struct program *program;
void timer_callBack();
void InitializeTimer(uint32_t freq);

#endif
