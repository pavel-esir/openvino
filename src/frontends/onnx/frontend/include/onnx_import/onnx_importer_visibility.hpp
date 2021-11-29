// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "ngraph/visibility.hpp"

#ifdef OPENVINO_STATIC_LIBRARY
#    define ONNX_IMPORTER_API
#else
#    ifdef onnx_ov_frontend_EXPORTS
#        define ONNX_IMPORTER_API OPENVINO_CORE_EXPORTS
#    else
#        define ONNX_IMPORTER_API OPENVINO_CORE_IMPORTS
#    endif  // onnx_ov_frontend_EXPORTS
#endif      // OPENVINO_STATIC_LIBRARY
