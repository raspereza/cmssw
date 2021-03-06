#include "FWCore/Framework/interface/LuminosityBlockForOutput.h"

#include "FWCore/Framework/interface/LuminosityBlockPrincipal.h"
#include "FWCore/Framework/interface/RunForOutput.h"
#include "FWCore/Utilities/interface/Algorithms.h"
#include "FWCore/Utilities/interface/get_underlying_safe.h"

namespace edm {

  LuminosityBlockForOutput::LuminosityBlockForOutput(LuminosityBlockPrincipal const& lbp, ModuleDescription const& md,
                                   ModuleCallingContext const* moduleCallingContext) :
        OccurrenceForOutput(lbp, md, moduleCallingContext),
        aux_(lbp.aux()),
        run_(new RunForOutput(lbp.runPrincipal(), md, moduleCallingContext)) {
  }

  LuminosityBlockForOutput::~LuminosityBlockForOutput() {
  }

  LuminosityBlockPrincipal const&
  LuminosityBlockForOutput::luminosityBlockPrincipal() const {
    return dynamic_cast<LuminosityBlockPrincipal const&>(principal());
  }
}
