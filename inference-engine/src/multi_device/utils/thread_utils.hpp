// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef MULTIDEVICEPLUGIN_THREADUTILS_H
#define MULTIDEVICEPLUGIN_THREADUTILS_H

#include <cstdint>
#include <string>

#ifdef  MULTIUNITTEST
#define MOCKTESTMACRO virtual
#define MultiDevicePlugin MockMultiDevicePlugin
#else
#define MOCKTESTMACRO
#endif

#if (defined(_WIN32) || defined(_WIN64))
#include <windows.h>
#include <winsock.h>
#include <intrin.h>
namespace MultiDevicePlugin {
namespace ThreadUtils {
DWORD getThreadId();
} // namespace ThreadUtils
#elif defined(__linux__)
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#include <unistd.h>
namespace MultiDevicePlugin {
namespace ThreadUtils {
long getThreadId();
} // namespace ThreadUtils
#elif defined(__APPLE__)
#include <pthread.h>
#include <sys/proc_info.h>
namespace MultiDevicePlugin {
namespace ThreadUtils {
long getThreadId();
} // namespace ThreadUtils
#else
namespace MultiDevicePlugin {
namespace ThreadUtils {
long getThreadId();
} // namespace ThreadUtils
#endif



namespace ThreadUtils {
uint64_t getRdtsc();
std::string getName();

void setName(const char* name);
void setName(const std::string& name);
void getName(char* name, size_t size);
void saveThreadInfo(const std::string& threadName, const std::string& saveFile = "threads.info");
} // namespace ThreadUtils
} // namespace MultiDevicePlugin

#endif //MULTIDEVICEPLUGIN_THREADUTILS_H
