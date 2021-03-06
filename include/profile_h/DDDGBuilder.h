#ifndef __DDDGBUILDER_H__
#define __DDDGBUILDER_H__

#include <fstream>
#include <map>
#include <set>
#include <stack>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <zlib.h>

#include "profile_h/auxiliary.h"
#include "profile_h/opcodes.h"

#ifdef FUTURE_CACHE
#define FILE_FUTURE_CACHE "futurecache.db"
#define FILE_FUTURE_CACHE_MAGIC_STRING "!BU"

class FutureCache {
public:
	struct elemTy {
		long int gzCursor;
		uint64_t byteFrom;
		uint64_t instCount;
		long int progressiveTraceCursor;
		uint64_t progressiveTraceInstCount;
		uint64_t lastInstExitingCounter;
		uint64_t to;

		elemTy(
			long int gzCursor, uint64_t byteFrom, uint64_t instCount,
			long int progressiveTraceCursor, uint64_t progressiveTraceInstCount,
			uint64_t lastInstExitingCounter, uint64_t to
		) :
			gzCursor(gzCursor), byteFrom(byteFrom), instCount(instCount),
			progressiveTraceCursor(progressiveTraceCursor), progressiveTraceInstCount(progressiveTraceInstCount),
			lastInstExitingCounter(lastInstExitingCounter), to(to) { }
	};
	typedef std::map<std::string, elemTy>::iterator iterator;

private:
	std::map<std::string, elemTy> cache;
	unsigned cacheMiss;
	unsigned cacheHit;

	std::string constructKey(std::string wholeLoopName, unsigned datapathType, long int progressiveTraceCursor, uint64_t progressiveTraceInstCount);

public:
	FutureCache() : cacheMiss(0), cacheHit(0) { };
	void dumpSummary(std::ofstream *summaryFile);

	bool load();
	void save();

	iterator find(std::string wholeLoopName, unsigned datapathType, long int progressiveTraceCursor, uint64_t progressiveTraceInstCount);
	std::pair<iterator, bool> insert(
		std::string wholeLoopName, unsigned datapathTYpe,
		long int progressiveTraceCursor, uint64_t progressiveTraceInstCount,
		elemTy &elem
	);
	void clear() { cache.clear(); cacheMiss = 0; cacheHit = 0; }
	iterator end() { return cache.end(); }
};

extern FutureCache futureCache;
#endif

typedef std::unordered_map<std::string, std::string> instName2bbNameMapTy;
extern instName2bbNameMapTy instName2bbNameMap;

typedef std::map<std::pair<std::string, std::string>, std::string> headerBBFuncNamePair2lastInstMapTy;
extern headerBBFuncNamePair2lastInstMapTy headerBBFuncNamePair2lastInstMap;
extern headerBBFuncNamePair2lastInstMapTy exitingBBFuncNamePair2lastInstMap;

typedef std::pair<std::string, std::string> lpNameLevelStrPairTy;
typedef std::map<lpNameLevelStrPairTy, std::string> lpNameLevelPair2headBBnameMapTy;
extern lpNameLevelPair2headBBnameMapTy lpNameLevelPair2headBBnameMap;
extern lpNameLevelPair2headBBnameMapTy lpNameLevelPair2exitingBBnameMap;

typedef std::map<std::string, std::vector<unsigned> > loopName2levelUnrollVecMapTy;
extern loopName2levelUnrollVecMapTy loopName2levelUnrollVecMap;

typedef std::map<std::pair<std::string, std::string>, unsigned> funcBBNmPair2numInstInBBMapTy;
extern funcBBNmPair2numInstInBBMapTy funcBBNmPair2numInstInBBMap;

typedef std::map<std::string, bool> wholeloopName2perfectOrNotMapTy;
extern wholeloopName2perfectOrNotMapTy wholeloopName2perfectOrNotMap;

typedef std::tuple<uint64_t, uint64_t, uint64_t> intervalTy;

typedef std::map<std::string, std::pair<std::string, unsigned> > headerBBlastInst2loopNameLevelPairMapTy;

typedef std::unordered_map<std::string, unsigned> s2uMap;

struct edgeNodeInfo {
	unsigned sink;
	int paramID;
};

typedef std::unordered_multimap<unsigned, edgeNodeInfo> u2eMMap;

typedef std::unordered_map<int64_t, unsigned> i642uMap;

class BaseDatapath;

class ParsedTraceContainer {
	BaseDatapath *datapath;

	std::string funcFileName;
	std::string instIDFileName;
	std::string lineNoFileName;
	std::string memoryTraceFileName;
	std::string getElementPtrFileName;
	std::string prevBasicBlockFileName;
	std::string currBasicBlockFileName;
	std::string resultSizeFileName;

	gzFile funcFile;
	gzFile instIDFile;
	gzFile lineNoFile;
	gzFile memoryTraceFile;
	gzFile getElementPtrFile;
	gzFile prevBasicBlockFile;
	gzFile currBasicBlockFile;
	gzFile resultSizeFile;

	std::vector<std::string> funcList;
	std::vector<std::string> instIDList;
	std::vector<int> lineNoList;
	std::unordered_map<int, std::pair<int64_t, unsigned>> memoryTraceList;
	std::unordered_map<int, std::pair<std::string, int64_t>> getElementPtrList;
	std::vector<std::string> prevBasicBlockList;
	std::vector<std::string> currBasicBlockList;
	std::unordered_map<int, unsigned> resultSizeList;

	bool compressed;
	bool keepAliveRead;
	bool keepAliveWrite;
	bool locked;

public:
	ParsedTraceContainer(std::string kernelName);
	~ParsedTraceContainer();

	void openAndClearAllFiles();
	void openAllFilesForRead();
	void closeAllFiles();
	void lock();

	void appendToFuncList(std::string elem);
	void appendToInstIDList(std::string elem);
	void appendToLineNoList(int elem);
	void appendToMemoryTraceList(int key, int64_t elem, unsigned elem2);
	void appendToGetElementPtrList(int key, std::string elem, int64_t elem2);
	void appendToPrevBBList(std::string elem);
	void appendToCurrBBList(std::string elem);
	void appendToResultSizeList(int key, unsigned elem);

	const std::vector<std::string> &getFuncList();
	const std::vector<std::string> &getInstIDList();
	const std::vector<int> &getLineNoList();
	const std::unordered_map<int, std::pair<int64_t, unsigned>> &getMemoryTraceList();
	const std::unordered_map<int, std::pair<std::string, int64_t>> &getGetElementPtrList();
	const std::vector<std::string> &getPrevBBList();
	const std::vector<std::string> &getCurrBBList();
	const std::unordered_map<int, unsigned> &getResultSizeList();
};

class DDDGBuilder {
	BaseDatapath *datapath;
	ParsedTraceContainer &PC;

	std::string rest;
	uint8_t prevMicroop, currMicroop;
	std::string currInstID;
	std::string currDynamicFunction;
	std::string calleeFunction;
	std::stack<std::pair<std::string, int>> activeMethod;
	s2uMap functionCounter;
	std::string prevBB, currBB;
	int numOfInstructions;
	bool lastParameter;
	std::vector<int64_t> parameterValuePerInst;
	std::vector<unsigned> parameterSizePerInst;
	std::vector<std::string> parameterLabelPerInst;
	s2uMap registerLastWritten;
	std::string calleeDynamicFunction;
	int lastCallSource;
	u2eMMap registerEdgeTable;
	u2eMMap memoryEdgeTable;
	unsigned numOfRegDeps, numOfMemDeps;
	i642uMap addressLastWritten;

	intervalTy getTraceLineFromTo(gzFile &traceFile);
	void parseTraceFile(gzFile &traceFile, intervalTy interval);
	void parseInstructionLine();
	void parseResult();
	void parseForward();
	void parseParameter(int param);

	bool lookaheadIsSameLoopLevel(gzFile &traceFile, unsigned loopLevel);

	void writeDDDG();

public:
	DDDGBuilder(BaseDatapath *datapath, ParsedTraceContainer &PC);

	intervalTy getTraceLineFromToBeforeNestedLoop(gzFile &traceFile);
	intervalTy getTraceLineFromToAfterNestedLoop(gzFile &traceFile);
	intervalTy getTraceLineFromToBetweenAfterAndBefore(gzFile &traceFile);

	void buildInitialDDDG();
	void buildInitialDDDG(intervalTy interval);

	unsigned getNumOfRegisterDependencies();
	unsigned getNumOfMemoryDependencies();
};

#endif
