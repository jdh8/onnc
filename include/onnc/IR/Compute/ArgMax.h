//===- ArgMax.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_IR_COMPUTE_OPERATOR_ARGMAX_H
#define ONNC_IR_COMPUTE_OPERATOR_ARGMAX_H
#include <onnc/IR/ComputeOperator.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/Compute/Attributes.h>
#include <onnc/Support/IOStream.h>

namespace onnc {

class ArgMax : public ComputeOperator
{
public:
  enum IOConst {
    kData = 0,
    kReduced = 0
  };

public:
  ArgMax();

  ArgMax(const IntAttr& pAxis,
         const IntAttr& pKeepdims);

  ~ArgMax() { }

  const IntAttr& getAxis() const { return m_Axis; }

  const IntAttr& getKeepdims() const { return m_Keepdims; }

  Tensor* getInput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  const Tensor* getInput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  Tensor* getOutput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  const Tensor* getOutput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  Tensor* getData() { return getInput(kData); }

  Tensor* getReduced() { return getOutput(kReduced); }

  void setData(Tensor& pTensor) { m_Inputs[kData] = &pTensor; }

  void setReduced(Tensor& pTensor) { m_Outputs[kReduced] = &pTensor; }

  void print(std::ostream& pOS) const override;

  void dump() const { print(errs()); }

  void accept(ComputeVisitor& pVisitor) override { pVisitor.visit(*this); }
private:
  IntAttr m_Axis;
  IntAttr m_Keepdims;
};

} // namespace of onnc

#endif