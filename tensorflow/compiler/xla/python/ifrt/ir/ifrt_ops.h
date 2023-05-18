/* Copyright 2023 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_XLA_PYTHON_IFRT_IR_IFRT_OPS_H_
#define TENSORFLOW_COMPILER_XLA_PYTHON_IFRT_IR_IFRT_OPS_H_

#include "mlir/Dialect/Func/IR/FuncOps.h"  // from @llvm-project
#include "mlir/IR/BuiltinTypes.h"  // from @llvm-project
#include "mlir/IR/OpDefinition.h"  // from @llvm-project
#include "mlir/IR/OpImplementation.h"  // from @llvm-project
#include "mlir/IR/Operation.h"  // from @llvm-project
#include "mlir/IR/ValueRange.h"  // from @llvm-project
#include "mlir/IR/Visitors.h"  // from @llvm-project
#include "mlir/Interfaces/CallInterfaces.h"  // from @llvm-project
#include "mlir/Support/LogicalResult.h"  // from @llvm-project
#include "tensorflow/compiler/xla/python/ifrt/ir/constants.h"
#include "tensorflow/compiler/xla/python/ifrt/ir/ifrt_dialect.h"

namespace mlir {
namespace OpTrait {
namespace xla {
namespace ifrt {

namespace impl {

// Verifies `op` used in a FuncOp with `ifrt.function` attr.
LogicalResult verifyNestedInIfrtFunc(Operation* op);

}  // namespace impl

template <typename ConcreteType>
class NestedInIfrtFuncTrait
    : public TraitBase<ConcreteType, NestedInIfrtFuncTrait> {
 public:
  static LogicalResult verifyTrait(Operation* op) {
    return impl::verifyNestedInIfrtFunc(op);
  }
};

}  // namespace ifrt
}  // namespace xla
}  // namespace OpTrait
}  // namespace mlir

// Generated definitions.
#define GET_OP_CLASSES
#include "tensorflow/compiler/xla/python/ifrt/ir/ifrt_ops.h.inc"  // IWYU pragma: export

#endif  // TENSORFLOW_COMPILER_XLA_PYTHON_IFRT_IR_IFRT_OPS_H_
