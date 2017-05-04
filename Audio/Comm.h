/* Comm.h
 * See whether song needs to start or stop playing
 * Trey Boehm and Emily Steck, 2017-05-03
 * PD3 is start signal, PD4 is stop signal
 */

void Comm_Init(void);

unsigned int Comm_In(void);
