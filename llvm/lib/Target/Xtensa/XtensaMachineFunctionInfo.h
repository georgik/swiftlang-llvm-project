//===- XtensaMachineFunctionInfo.h - Xtensa machine function info --*- C++ -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file declares  Xtensa-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

namespace llvm {

/// XtensaMachineFunctionInfo - This class is derived from MachineFunction 
/// and contains private Xtensa target-specific information for each MachineFunction.
class XtensaMachineFunctionInfo : public MachineFunctionInfo {
  virtual void anchor();

  /// VarArgsFirstGPR - Index of the first GPR used for VarArgs
  unsigned VarArgsFirstGPR = 0;

  /// VarArgsInRegsFrameIndex - FrameIndex for start of VarArgs area in registers
  int VarArgsInRegsFrameIndex = 0;

  /// VarArgsOnStackFrameIndex - FrameIndex for start of VarArgs area on stack
  int VarArgsOnStackFrameIndex = 0;

  /// SaveFrameRegister - True if the function saves the frame register
  bool SaveFrameRegister = false;

  /// BranchRelaxationScratchFrameIndex - Frame index for branch relaxation scratch register
  int BranchRelaxationScratchFrameIndex = -1;

  /// LabelUID - Counter for creating unique labels
  unsigned LabelUID = 0;

public:
  XtensaMachineFunctionInfo(const Function &F, const TargetSubtargetInfo *STI)
      : VarArgsFirstGPR(0), VarArgsInRegsFrameIndex(0), 
        VarArgsOnStackFrameIndex(0), SaveFrameRegister(false),
        BranchRelaxationScratchFrameIndex(-1), LabelUID(0) {}

  MachineFunctionInfo *
  clone(BumpPtrAllocator &Allocator, MachineFunction &DestMF,
        const DenseMap<MachineBasicBlock *, MachineBasicBlock *> &Src2DstMBB)
      const override;

  unsigned getVarArgsFirstGPR() const { return VarArgsFirstGPR; }
  void setVarArgsFirstGPR(unsigned GPR) { VarArgsFirstGPR = GPR; }

  int getVarArgsInRegsFrameIndex() const { return VarArgsInRegsFrameIndex; }
  void setVarArgsInRegsFrameIndex(int FI) { VarArgsInRegsFrameIndex = FI; }

  int getVarArgsOnStackFrameIndex() const { return VarArgsOnStackFrameIndex; }
  void setVarArgsOnStackFrameIndex(int FI) { VarArgsOnStackFrameIndex = FI; }

  bool isSaveFrameRegister() const { return SaveFrameRegister; }
  void setSaveFrameRegister() { SaveFrameRegister = true; }

  int getBranchRelaxationScratchFrameIndex() const { 
    return BranchRelaxationScratchFrameIndex; 
  }
  void setBranchRelaxationScratchFrameIndex(int FI) { 
    BranchRelaxationScratchFrameIndex = FI; 
  }

  unsigned createLabelUID() { return LabelUID++; }
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_XTENSA_XTENSAMACHINEFUNCTIONINFO_H
