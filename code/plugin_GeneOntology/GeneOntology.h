/*
 	Ray
    Copyright (C) 2010, 2011, 2012 Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You have received a copy of the GNU General Public License
    along with this program (gpl-3.0.txt).  
	see <http://www.gnu.org/licenses/>
*/

#ifndef _GeneOntology_h
#define _GeneOntology_h

#include <core/ComputeCore.h>
#include <plugins/CorePlugin.h>
#include <handlers/SlaveModeHandler.h>
#include <plugin_Searcher/ColorSet.h>
#include <handlers/MasterModeHandler.h>
#include <handlers/MessageTagHandler.h>
#include <application_core/Parameters.h>
#include <plugin_VerticesExtractor/GridTable.h>
#include <profiling/TimePrinter.h>

#include <plugin_Searcher/Searcher.h>
#include <plugin_GeneOntology/types.h>
#include <plugin_GeneOntology/GeneOntology_adapters.h>

#include <set>
#include <stdint.h>
#include <map>
using namespace std;

/** 
 * a plugin to know what is present in a sample 
 * in terms of functions
 * \author Sébastien Boisvert
 */
class GeneOntology: public CorePlugin{

	bool m_listedRelevantColors;

	set<PhysicalKmerColor> m_colorsForOntology;

	GridTable*m_subgraph;
	Parameters*m_parameters;
	SwitchMan*m_switchMan;
	StaticVector*m_outbox;
	RingAllocator*m_outboxAllocator;
	ColorSet*m_colorSet;

	Rank m_rank;
	int m_size;

	StaticVector*m_inbox;
	RingAllocator*m_inboxAllocator;
	TimePrinter*m_timePrinter;

	ComputeCore*m_core;

	bool m_started;

	Searcher*m_searcher;

	MasterMode RAY_MASTER_MODE_ONTOLOGY_MAIN;
	MasterMode RAY_MASTER_MODE_KILL_RANKS;
	MasterMode RAY_MASTER_MODE_NEIGHBOURHOOD;

	SlaveMode RAY_SLAVE_MODE_ONTOLOGY_MAIN;

	MessageTag RAY_MPI_TAG_ONTOLOGY_MAIN;

	Adapter_RAY_MASTER_MODE_ONTOLOGY_MAIN m_adapter_RAY_MASTER_MODE_ONTOLOGY_MAIN;
	Adapter_RAY_SLAVE_MODE_ONTOLOGY_MAIN m_adapter_RAY_SLAVE_MODE_ONTOLOGY_MAIN;

	void fetchRelevantColors /**/ ();
public:

	void call_RAY_MASTER_MODE_ONTOLOGY_MAIN();
	void call_RAY_SLAVE_MODE_ONTOLOGY_MAIN();

	void registerPlugin(ComputeCore*core);
	void resolveSymbols(ComputeCore*core);

};

#endif

