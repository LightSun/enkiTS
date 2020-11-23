//
// Created by Administrator on 2020/11/18 0018.
//

#include <jni.h>
#include <stdio.h>
#include "system_wrappers/interface/timer_wrapper.h"
#include "system_wrappers/interface/thread_wrapper.h"
#include "and_log.h"

#ifdef __cplusplus
extern "C" {
#endif

gn::TimerWrapper* timer =NULL;
int32_t _timer_id;

extern int
main0(int argc, const char *path[]);

int
main_timer(int argc, const char *path[]);

JNIEXPORT void JNICALL Java_com_heaven7_android_enkits_MainActivity_nTest0(JNIEnv *env, jclass cla) {
main0(0, NULL);
}

JNIEXPORT void JNICALL Java_com_heaven7_android_enkits_MainActivity_nTestTimer(JNIEnv *env, jclass cla) {
main_timer(0, NULL);
}
JNIEXPORT void JNICALL Java_com_heaven7_android_enkits_MainActivity_nReleaseTimer(JNIEnv *env, jclass cla) {
    if(timer){
        timer->KillTimer(_timer_id);
        delete timer;
        timer = NULL;
    }
}

void timer_callback0(int32_t timerID, void* userData){
    LOGD("timer callback is invoked...tid = %u", gn::ThreadWrapper::GetThreadId());
}
int
main_timer(int argc, const char *path[]){
    LOGD("main_timer is invoked...tid = %u", gn::ThreadWrapper::GetThreadId());
    timer = gn::TimerWrapper::CreateTimer();
    _timer_id = timer->SetTimer(2000, timer_callback0, NULL);
    return _timer_id;
}


#ifdef __cplusplus
}
#endif