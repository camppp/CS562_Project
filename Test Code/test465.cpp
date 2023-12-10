#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRReader.h>
#include <llvm/IR/KernelDumper.h>
#include <llvm/Support/Error.h>
#include <llvm/Support/raw_ostream.h>

void processIRFile(const std::string& irFilename, const std::string& kernelname, bool add_ir_to_cl) {
    // Create an LLVM context
    llvm::LLVMContext context;

    // Create a module from the IR file
    llvm::SMDiagnostic error;
    std::unique_ptr<llvm::Module> module = llvm::parseIRFile(irFilename, error, context);

    // Check if parsing failed
    if (!module) {
        llvm::errs() << "failed to parse IR file: " << error.getMessage() << "\n";
        throw std::runtime_error("failed to parse IR");
    }

    // Create a KernelDumper object
    llvm::KernelDumper dumper(module.get(), kernelname);

    // Add the IR to the OpenCL compiler
    if (add_ir_to_cl) {
        dumper.addIRToCl();
    }
}
