#ifndef INSTRUMENT_FOR_DDDG_PASS_H
#define INSTRUMENT_FOR_DDDG_PASS_H

#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <string.h>

#include "llvm/Pass.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_os_ostream.h"
#include "llvm/Transforms/Utils/Cloning.h"
#include "llvm/Transforms/Utils/ValueMapper.h"

#include "profile_h/BaseDatapath.h"
#include "profile_h/DDDG.h"
#include "profile_h/DynamicDatapath.h"
#include "profile_h/Passes.h"
#include "profile_h/SlotTracker.h"
#include "profile_h/TraceFunctions.h"
#include "profile_h/auxiliary.h"
#include "profile_h/generic_func.h"

#define RESULT_LINE 19134
#define FORWARD_LINE 24601

namespace llvm {

typedef struct {
	Function *log0;
	Function *logInt;
	Function *logDouble;
	Function *logIntNoReg;
	Function *logDoubleNoReg;

	void initialiseDefaults(Module &M);
} TraceLogger;

class Injector {
	Module *M;
	TraceLogger *TL;

	int getMemSizeInBits(Type *T);
	Constant *createGlobalVariableAndGetGetElementPtr(std::string value);

public:
	void initialise(Module &M, TraceLogger &TL);

	void injectTraceHeader(BasicBlock::iterator it, int lineNo, std::string funcID, std::string bbID, std::string instID, int opcode);
	void injectTrace(BasicBlock::iterator it, int lineNo, std::string regOrFuncID, Type *T, Value *value, bool isReg);
};

class InstrumentForDDDG : public ModulePass {
	TraceLogger TL;
	Injector IJ;
	Module *currModule;
	Function *currFunction;
	SlotTracker *ST;
	enum {
		NOT_TRACE = 0,
		TRACE_INTRINSIC = 1,
		TRACE_FUNCTION_OF_INTEREST = 2,
		TRACE_DMA_STORE = 98,
		TRACE_DMA_LOAD = 99
	};

	std::unordered_map<int, int> unrollingConfig;
	std::vector<std::string> pipelineLoopLevelVec;

	void extractMemoryTraceForAccessPattern();
	int shouldTrace(std::string call);

public:
	static char ID;

	InstrumentForDDDG();
	void getAnalysisUsage(AnalysisUsage &AU) const;
	bool doInitialization(Module &M);
	bool runOnModule(Module &M);

#if 0
	/// Function used to instrument LLVM-IR
	void printLine(BasicBlock::iterator it, int line, int lineNo, std::string funcOrRegID,
					std::string bbID, std::string instID, int opcodeOrType, int dataSize = 0, Value *value = NULL, 
					bool isReg = false);
	void insertInstID(std::string instID, unsigned opcode);
	void insertInstid2bbName(std::string instID, std::string bbName);
#endif

	bool getInstID(Instruction *I, std::string bbID, int &instCnt, std::string &instID);

	std::string getBBID(Value *BB);

	bool performOnBasicBlock(BasicBlock &BB);

	void removeConfig(std::string kernelName, std::string inputPath);
	void parseConfig(std::string kernelName, std::string inputPath);
	void getUnrollingConfiguration(lpNameLevelPair2headBBnameMapTy &lpNameLvPair2headerBBMap);
	bool readUnrollingConfig(loopName2levelUnrollVecMapTy &lpName2levelUrPairVecMap, std::unordered_map<int, int> &unrollingConfig);

	void loopBasedTraceAnalysis();

	void openSummaryFile(std::ofstream &summaryFile, std::string kernelName);
	void closeSummaryFile(std::ofstream &summaryFile);
};

// Embedded Profiler Engine
class ProfilingEngine {
	Module &M;
	TraceLogger &TL;

public:
	ProfilingEngine(Module &M, TraceLogger &TL);
	void runOnProfiler();
};

struct ProfilingJITContext {
	ProfilingEngine *P;
	ProfilingJITContext();
};

struct ProfilingJITSingletonContext {
	ProfilingJITSingletonContext(ProfilingEngine *P);
	~ProfilingJITSingletonContext();
};

static ManagedStatic<ProfilingJITContext> GlobalContextDDDG;

} // End of llvm namespace

#endif // End of INSTRUMENT_FOR_DDDG_PASS_H
