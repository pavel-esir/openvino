// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#include <node_context.hpp>

#include "default_opset.hpp"

namespace ov {
namespace frontend {
namespace pdpd {
namespace op {
NamedOutputs softplus(const NodeContext& node) {
    auto data = node.get_ng_input("X");
    auto beta = node.get_attribute<float>("beta");
    auto threshold = node.get_attribute<float>("threshold");
    float supported_beta = 1.0;
    float supported_threshold = 20.0;
    const float EPSINON = 1e-6;

    if (!(abs(beta - supported_beta) <= EPSINON) || !(abs(threshold - supported_threshold) <= EPSINON)) {
        PDPD_OP_VALIDATION_CHECK(node, false, "only support beta==1.0 && threshold==20.0");
    }
    return node.default_single_output_mapping({std::make_shared<default_opset::SoftPlus>(data)}, {"Out"});
}
}  // namespace op
}  // namespace pdpd
}  // namespace frontend
}  // namespace ov
