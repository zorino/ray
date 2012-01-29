/*
 	Ray
    Copyright (C) 2010, 2011, 2012  Sébastien Boisvert

	http://DeNovoAssembler.SourceForge.Net/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You have received a copy of the GNU Lesser General Public License
    along with this program (lgpl-3.0.txt).  
	see <http://www.gnu.org/licenses/>

*/

#include <plugins/RegisteredPlugin.h>
#include <iostream>
using namespace std;

RegisteredPlugin::RegisteredPlugin(){
	m_name="UnnamedPlugin";
	m_description="No description available";
}

void RegisteredPlugin::setName(string name){
	m_name=name;
}

void RegisteredPlugin::addAllocatedSlaveMode(SlaveMode slaveMode){
	m_allocatedSlaveModes.insert(slaveMode);
}

void RegisteredPlugin::addAllocatedMasterMode(MasterMode masterMode){
	m_allocatedMasterModes.insert(masterMode);
}

void RegisteredPlugin::addAllocatedMessageTag(MessageTag messageTag){
	m_allocatedMessageTags.insert(messageTag);
}

void RegisteredPlugin::addRegisteredSlaveModeHandler(SlaveMode slaveMode){
	m_registeredSlaveModeHandlers.insert(slaveMode);
}

void RegisteredPlugin::addRegisteredMasterModeHandler(MasterMode masterMode){
	m_registeredMasterModeHandlers.insert(masterMode);
}

void RegisteredPlugin::addRegisteredMessageTagHandler(MessageTag messageTag){
	m_registeredMessageTagHandlers.insert(messageTag);
}

void RegisteredPlugin::addRegisteredSlaveModeSymbol(SlaveMode slaveMode){
	m_registeredSlaveModeSymbols.insert(slaveMode);
}

void RegisteredPlugin::addRegisteredMasterModeSymbol(MasterMode masterMode){
	m_registeredMasterModeSymbols.insert(masterMode);
}

void RegisteredPlugin::addRegisteredMessageTagSymbol(MessageTag messageTag){
	m_registeredMessageTagSymbols.insert(messageTag);
}

bool RegisteredPlugin::hasSlaveMode(SlaveMode mode){
	return m_allocatedSlaveModes.count(mode)>0;
}

bool RegisteredPlugin::hasMasterMode(MasterMode mode){
	return m_allocatedMasterModes.count(mode)>0;
}

bool RegisteredPlugin::hasMessageTag(MessageTag tag){
	return m_allocatedMessageTags.count(tag)>0;
}

string RegisteredPlugin::getName(){
	return m_name;
}

void RegisteredPlugin::print(ostream*stream){

	(*stream)<<" Name: "<<getName()<<endl;
	(*stream)<<" Description: "<<getDescription()<<endl;
	(*stream)<<endl;
	
	(*stream)<<" Allocated handles"<<endl;
	(*stream)<<endl;

	(*stream)<<"  -> Allocated master mode handles: "<<m_allocatedMasterModes.size()<<endl;
	(*stream)<<"     -> with a registered handler: "<<m_registeredMasterModeHandlers.size()<<endl;
	(*stream)<<"     -> with a registered symbol: "<<m_registeredMasterModeSymbols.size()<<endl;
	(*stream)<<endl;

	(*stream)<<"  -> Allocated slave mode handles: "<<m_allocatedSlaveModes.size()<<endl;
	(*stream)<<"     -> with a registered handler: "<<m_registeredSlaveModeHandlers.size()<<endl;
	(*stream)<<"     -> with a registered symbol: "<<m_registeredSlaveModeSymbols.size()<<endl;
	(*stream)<<endl;

	(*stream)<<"  -> Allocated message tag handles: "<<m_allocatedMessageTags.size()<<endl;
	(*stream)<<"     -> with a registered handler: "<<m_registeredMessageTagHandlers.size()<<endl;
	(*stream)<<"     -> with a registered symbol: "<<m_registeredMessageTagSymbols.size()<<endl;
	(*stream)<<"     -> with a registered reply tag: "<<m_registeredMessageTagReplyTags.size()<<endl;
	(*stream)<<endl;

	(*stream)<<" Resolved symbols"<<endl;

	(*stream)<<endl;
	(*stream)<<"  -> Resolved master mode symbols: "<<m_resolvedMasterModes.size()<<endl;
	(*stream)<<"  -> Resolved slave mode symbols: "<<m_resolvedSlaveModes.size()<<endl;
	(*stream)<<"  -> Resolved message tag symbols: "<<m_resolvedMessageTags.size()<<endl;

	(*stream)<<endl;
}

void RegisteredPlugin::addRegisteredMessageTagReplyTag(MessageTag handle){
	m_registeredMessageTagReplyTags.insert(handle);
}

void RegisteredPlugin::addResolvedMessageTag(MessageTag handle){
	m_resolvedMessageTags.insert(handle);
}

void RegisteredPlugin::addResolvedSlaveMode(SlaveMode handle){
	m_resolvedSlaveModes.insert(handle);
}

void RegisteredPlugin::addResolvedMasterMode(MasterMode handle){
	m_resolvedMasterModes.insert(handle);
}

void RegisteredPlugin::setDescription(string a){
	m_description=a;
}

string RegisteredPlugin::getDescription(){
	return m_description;
}