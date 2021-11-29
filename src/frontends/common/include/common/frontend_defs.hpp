// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/core/visibility.hpp"

// Increment each time when FrontEnd/InputModel/Place interface is changed
#define OV_FRONTEND_API_VERSION 1

#if defined(USE_STATIC_FRONTEND_COMMON) || defined(OPENVINO_STATIC_LIBRARY)
#    define FRONTEND_API
#else
// Defined if cmake is building the frontend_common DLL (instead of using it)
#    ifdef frontend_common_EXPORTS
#        define FRONTEND_API OPENVINO_CORE_EXPORTS
#    else
#        define FRONTEND_API OPENVINO_CORE_IMPORTS
#    endif  // frontend_common_EXPORTS
#endif      // USE_STATIC_FRONTEND_COMMON || OPENVINO_STATIC_LIBRARY
