// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

/**
 * @brief Defines primitives priority attribute
 * @file primitives_priority_attribute.hpp
 */

#pragma once

#include <assert.h>
#include <functional>
#include <memory>
#include <string>
#include <set>

#include <ngraph/node.hpp>
#include <ngraph/variant.hpp>

namespace ov {
/**
 * @ingroup ie_runtime_attr_api
 * @brief getPrimitivesPriority return string with primitive priorities value
 * @param[in] node The node will be used to get PrimitivesPriority attribute
 */
NGRAPH_API std::string getPrimitivesPriority(const std::shared_ptr<ngraph::Node> & node);

class NGRAPH_API PrimitivesPriority : public VariantImpl<std::string> {
public:
    OPENVINO_RTTI("primitives_priority", "0");

    PrimitivesPriority() = default;

    ~PrimitivesPriority() override = default;

    PrimitivesPriority(const value_type &value) : VariantImpl<value_type>(value) {}

    Any merge(const ngraph::NodeVector & nodes) override;

    Any init(const std::shared_ptr<ngraph::Node> & node) override;

    bool visit_attributes(AttributeVisitor & visitor) override;
};
}  // namespace ov
