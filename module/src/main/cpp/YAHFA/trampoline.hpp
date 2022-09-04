//
// Created by liuruikai756 on 05/07/2017.
//

#ifndef YAHFA_TAMPOLINE_H
#define YAHFA_TAMPOLINE_H

#ifdef __cplusplus
extern "C" {
#endif
void setupTrampoline(unsigned char offset);

void *genTrampoline(void *toMethod, void *entrypoint);
#ifdef __cplusplus
}
#endif

#define TRAMPOLINE_SPACE_SIZE 4096 // 4k mem page size

#endif //YAHFA_TAMPOLINE_H
