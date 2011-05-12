/*
 	Ray
    Copyright (C) 2010, 2011  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (COPYING).  
	see <http://www.gnu.org/licenses/>

*/

// TYPE: FRAMEWORK
#ifndef _Parameters
#define _Parameters

#include<map>
#include<common_functions.h>
#include<set>
#include<string>
#include<vector>
using namespace std;

/**
 * This class is the implementation of an interpreter for the RayInputFile.
 * It allows the following commands:
 * 	LoadSingleEndReads <FileA>
 * 	LoadPairedEndReads <FileLeft> <FileRight> <FragmentLength> <StandardDeviation>
 *
 */
class Parameters{
	bool m_showMemoryUsage;
	bool m_showEndingContext;
	bool m_debugSeeds;
	bool m_profiler;
	bool m_debugBubbles;

	int m_reducerPeriod;
	int m_maximumDistance;

	string m_memoryFilePrefix;

	bool m_reducerIsActivated;
	int m_size;
	int m_maxCoverage;
	int m_rank;
	int m_peakCoverage;

	map<int,int> m_libraryAverageLength;
	map<int,int> m_libraryDeviation;
	int m_numberOfLibraries;
	int m_minimumCoverage;
	bool m_error;
	string m_prefix;
	bool m_amos;
	bool m_initiated;
	vector<string> m_singleEndReadsFile;
	vector<uint64_t> m_numberOfSequencesInFile;
	uint64_t m_totalNumberOfSequences;
	map<int,int> m_fileLibrary;
	set<int> m_automaticLibraries;

	string m_directory;
	string m_outputFile;
	int m_wordSize;
	int m_minimumContigLength;
	set<int> m_leftFiles;
	set<int> m_rightFiles;
	set<int> m_interleavedFiles;
	int m_seedCoverage;
	bool m_colorSpaceMode;
	string m_input;
	vector<string> m_commands;
	map<int,map<int,int> >  m_observedDistances;
	vector<int> m_observedAverageDistances;
	vector<int> m_observedStandardDeviations;
	void loadCommandsFromArguments(int argc,char**argv);
	void loadCommandsFromFile(char*file);
	void parseCommands();

	string getLibraryFile(int library);

public:
	Parameters();
	string getReceivedMessagesFile();
	void constructor(int argc,char**argv,int rank);
	bool isInitiated();
	vector<string> getAllFiles();
	string getDirectory();
	int getMinimumContigLength();
	string getOutputFile();
	int getWordSize();
	int getLibraryAverageLength(int i);
	int getLibraryStandardDeviation(int i);
	bool isLeftFile(int i);
	bool isRightFile(int i);
	bool getColorSpaceMode();
	bool useAmos();
	string getInputFile();
	string getAmosFile();
	string getParametersFile();
	string getCoverageDistributionFile();
	vector<string> getCommands();
	bool getError();
	void addDistance(int library,int distance,int count);
	void computeAverageDistances();
	uint64_t getNumberOfSequences(int n);
	void setNumberOfSequences(uint64_t n);
	int getNumberOfFiles();
	bool isAutomatic(int library);
	int getLibrary(int file);
	void printFinalMessage();
	bool isInterleavedFile(int i);
	void setPeakCoverage(int a);
	int getPeakCoverage();
	void addLibraryData(int library,int average,int deviation);
	int getNumberOfLibraries();

	int getMaxCoverage();
	int getSeedCoverage();
	void setSeedCoverage(int a);
	string getPrefix();
	int getRank();
	int getSize();
	void setSize(int a);
	bool runReducer();
	void showUsage();
	int getReducerValue();

	int getRankFromGlobalId(uint64_t a);
	int getIdFromGlobalId(uint64_t a);
	int getMaximumDistance();
	uint64_t getGlobalIdFromRankAndLocalId(int rank,int id);
	int getMaximumAllowedCoverage();
	int getMinimumCoverage();
	void setMinimumCoverage(int a);
	uint64_t _complementVertex(uint64_t a);
	bool hasPairedReads();
	int _vertexRank(uint64_t a);
	string getMemoryPrefix();
	/**
	* run the profiler
	*/
	bool runProfiler();
	/**
	* debug the code for bubble detection
	*/
	bool debugBubbles();
	/** 
	* debug the code that computes seeds
	*/
	bool debugSeeds();
	bool showMemoryUsage();
	bool showEndingContext();
};

#endif

