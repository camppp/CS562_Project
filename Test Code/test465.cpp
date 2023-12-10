#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/ErrorHandling.h>
#include <stdexcept>
#include "KernelDumper.h"  // Assuming the existence of KernelDumper class

void processIRFile(const std::string& irFilename, const std::string& kernelname, bool add_ir_to_cl) {
    llvm::LLVMContext context;
    llvm::SMDiagnostic smDiagnostic;

    std::unique_ptr<llvm::Module> M = llvm::parseIRFile(irFilename, smDiagnostic, context);
    if (!M) {
        smDiagnostic.print("irtoopencl", llvm::errs());
        throw std::runtime_error("failed to parse IR");
    }

    KernelDumper kernelDumper(M.get(), kernelname);
    if (add_ir_to_cl) {
        kernelDumper.addIRToCl();
    }
}
