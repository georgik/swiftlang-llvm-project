//===--- Xtensa.cpp - Implement Xtensa target feature support -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements Xtensa TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "Xtensa.h"
#include "clang/Basic/MacroBuilder.h"
#include "clang/Basic/TargetBuiltins.h"

using namespace clang;
using namespace clang::targets;

void XtensaTargetInfo::getTargetDefines(const LangOptions &Opts,
                                        MacroBuilder &Builder) const {
  Builder.defineMacro("__XTENSA__");
  Builder.defineMacro("__xtensa__");
}

ArrayRef<const char *> XtensaTargetInfo::getGCCRegNames() const {
  static const char *const GCCRegNames[] = {
      // Integer registers
      "a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7",
      "a8", "a9", "a10", "a11", "a12", "a13", "a14", "a15"
  };
  return llvm::ArrayRef(GCCRegNames);
}

ArrayRef<TargetInfo::GCCRegAlias> XtensaTargetInfo::getGCCRegAliases() const {
  static const TargetInfo::GCCRegAlias GCCRegAliases[] = {
      {{"sp"}, "a1"},
  };
  return llvm::ArrayRef(GCCRegAliases);
}
