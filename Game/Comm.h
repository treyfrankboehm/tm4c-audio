/* Comm.h
 * Communicate to the other board whether to start/stop song
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD3 is the start signal, PD4 is the stop signal
 */

void Comm_Init(void);

void Comm_Start(void);

void Comm_Stop(void);

void Comm_Tacet(void);
