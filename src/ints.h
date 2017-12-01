#include <stdint.h>

void DisableInterrupts(void);
void EnableInterrupts(void);
long StartCritical(void);
void EndCritical(long sr);
void WaitForInterrupt(void);


