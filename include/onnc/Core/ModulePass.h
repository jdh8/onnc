//===- ModulePass.h -------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_CORE_MODULE_PASS_H
#define ONNC_CORE_MODULE_PASS_H
#include <onnc/Core/Pass.h>

#include <cassert>

namespace onnc {

/** \class onnc::ModulePass
 *  \brief encapsulate transformation algorithms.
 */
class ModulePass : public Pass
{
public:
  ModulePass() = default;

  virtual ~ModulePass() = default;

  Kind getPassKind() const override {
    return kPT_Module;
  }

  /// Virtual method overridden by subclasses to process the module
  /// being operated on.
  virtual ReturnType runOnModule(Module &pModule) = 0;

  static bool classof(const Pass* pPass) {
      assert(pPass != nullptr);
      return kPT_Module == pPass->getPassKind();
  }
};

} // namespace of onnc

#endif
