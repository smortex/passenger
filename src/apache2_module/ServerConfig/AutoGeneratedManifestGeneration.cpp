/*
 *  Phusion Passenger - https://www.phusionpassenger.com/
 *  Copyright (c) 2017 Phusion Holding B.V.
 *
 *  "Passenger", "Phusion Passenger" and "Union Station" are registered
 *  trademarks of Phusion Holding B.V.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

/*
 * ServerConfig/AutoGeneratedManifestGeneration.cpp is automatically generated from ServerConfig/AutoGeneratedManifestGeneration.cpp.cxxcodebuilder,
 * using definitions from src/ruby_supportlib/phusion_passenger/apache2/config_options.rb.
 * Edits to ServerConfig/AutoGeneratedManifestGeneration.cpp will be lost.
 *
 * To update ServerConfig/AutoGeneratedManifestGeneration.cpp:
 *   rake apache2
 *
 * To force regeneration of ServerConfig/AutoGeneratedManifestGeneration.cpp:
 *   rm -f src/apache2_module/ServerConfig/AutoGeneratedManifestGeneration.cpp
 *   rake src/apache2_module/ServerConfig/AutoGeneratedManifestGeneration.cpp
 */

#include "../ConfigGeneral/ManifestGeneration.h"

namespace Passenger {
namespace Apache2Module {


void
ConfigManifestGenerator::autoGenerated_generateConfigManifestForServerConfig() {
	Json::Value &globalOptionsContainer = manifest["global_configuration"];

	if (serverConfig.dataBufferDirExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerDataBufferDir",
			sizeof("PassengerDataBufferDir") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.dataBufferDirSourceFile,
			serverConfig.dataBufferDirSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.dataBufferDir.data(),
			serverConfig.dataBufferDir.data() + serverConfig.dataBufferDir.size());
	}
	if (serverConfig.defaultGroupExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerDefaultGroup",
			sizeof("PassengerDefaultGroup") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.defaultGroupSourceFile,
			serverConfig.defaultGroupSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.defaultGroup.data(),
			serverConfig.defaultGroup.data() + serverConfig.defaultGroup.size());
	}
	if (serverConfig.defaultRubyExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerDefaultRuby",
			sizeof("PassengerDefaultRuby") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.defaultRubySourceFile,
			serverConfig.defaultRubySourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.defaultRuby.data(),
			serverConfig.defaultRuby.data() + serverConfig.defaultRuby.size());
	}
	if (serverConfig.defaultUserExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerDefaultUser",
			sizeof("PassengerDefaultUser") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.defaultUserSourceFile,
			serverConfig.defaultUserSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.defaultUser.data(),
			serverConfig.defaultUser.data() + serverConfig.defaultUser.size());
	}
	if (serverConfig.disableSecurityUpdateCheckExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerDisableSecurityUpdateCheck",
			sizeof("PassengerDisableSecurityUpdateCheck") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.disableSecurityUpdateCheckSourceFile,
			serverConfig.disableSecurityUpdateCheckSourceLine);
		hierarchyMember["value"] = serverConfig.disableSecurityUpdateCheck;
	}
	if (serverConfig.fileDescriptorLogFileExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerFileDescriptorLogFile",
			sizeof("PassengerFileDescriptorLogFile") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.fileDescriptorLogFileSourceFile,
			serverConfig.fileDescriptorLogFileSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.fileDescriptorLogFile.data(),
			serverConfig.fileDescriptorLogFile.data() + serverConfig.fileDescriptorLogFile.size());
	}
	if (serverConfig.instanceRegistryDirExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerInstanceRegistryDir",
			sizeof("PassengerInstanceRegistryDir") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.instanceRegistryDirSourceFile,
			serverConfig.instanceRegistryDirSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.instanceRegistryDir.data(),
			serverConfig.instanceRegistryDir.data() + serverConfig.instanceRegistryDir.size());
	}
	if (serverConfig.logFileExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerLogFile",
			sizeof("PassengerLogFile") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.logFileSourceFile,
			serverConfig.logFileSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.logFile.data(),
			serverConfig.logFile.data() + serverConfig.logFile.size());
	}
	if (serverConfig.logLevelExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerLogLevel",
			sizeof("PassengerLogLevel") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.logLevelSourceFile,
			serverConfig.logLevelSourceLine);
		hierarchyMember["value"] = serverConfig.logLevel;
	}
	if (serverConfig.maxPoolSizeExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerMaxPoolSize",
			sizeof("PassengerMaxPoolSize") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.maxPoolSizeSourceFile,
			serverConfig.maxPoolSizeSourceLine);
		hierarchyMember["value"] = serverConfig.maxPoolSize;
	}
	if (serverConfig.poolIdleTimeExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerPoolIdleTime",
			sizeof("PassengerPoolIdleTime") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.poolIdleTimeSourceFile,
			serverConfig.poolIdleTimeSourceLine);
		hierarchyMember["value"] = serverConfig.poolIdleTime;
	}
	if (serverConfig.prestartURLsExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerPreStart",
			sizeof("PassengerPreStart") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.prestartURLsSourceFile,
			serverConfig.prestartURLsSourceLine);
		hierarchyMember["value"] = strCollectionToJson< std::set<std::string>, std::string >(
			serverConfig.prestartURLs);
	}
	if (serverConfig.responseBufferHighWatermarkExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerResponseBufferHighWatermark",
			sizeof("PassengerResponseBufferHighWatermark") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.responseBufferHighWatermarkSourceFile,
			serverConfig.responseBufferHighWatermarkSourceLine);
		hierarchyMember["value"] = serverConfig.responseBufferHighWatermark;
	}
	if (serverConfig.rootExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerRoot",
			sizeof("PassengerRoot") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.rootSourceFile,
			serverConfig.rootSourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.root.data(),
			serverConfig.root.data() + serverConfig.root.size());
	}
	if (serverConfig.securityUpdateCheckProxyExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerSecurityUpdateCheckProxy",
			sizeof("PassengerSecurityUpdateCheckProxy") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.securityUpdateCheckProxySourceFile,
			serverConfig.securityUpdateCheckProxySourceLine);
		hierarchyMember["value"] = Json::Value(
			serverConfig.securityUpdateCheckProxy.data(),
			serverConfig.securityUpdateCheckProxy.data() + serverConfig.securityUpdateCheckProxy.size());
	}
	if (serverConfig.showVersionInHeaderExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerShowVersionInHeader",
			sizeof("PassengerShowVersionInHeader") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.showVersionInHeaderSourceFile,
			serverConfig.showVersionInHeaderSourceLine);
		hierarchyMember["value"] = serverConfig.showVersionInHeader;
	}
	if (serverConfig.socketBacklogExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerSocketBacklog",
			sizeof("PassengerSocketBacklog") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.socketBacklogSourceFile,
			serverConfig.socketBacklogSourceLine);
		hierarchyMember["value"] = serverConfig.socketBacklog;
	}
	if (serverConfig.statThrottleRateExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerStatThrottleRate",
			sizeof("PassengerStatThrottleRate") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.statThrottleRateSourceFile,
			serverConfig.statThrottleRateSourceLine);
		hierarchyMember["value"] = serverConfig.statThrottleRate;
	}
	if (serverConfig.turbocachingExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerTurbocaching",
			sizeof("PassengerTurbocaching") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.turbocachingSourceFile,
			serverConfig.turbocachingSourceLine);
		hierarchyMember["value"] = serverConfig.turbocaching;
	}
	if (serverConfig.userSwitchingExplicitlySet) {
		Json::Value &optionContainer = findOrCreateOptionContainer(globalOptionsContainer,
			"PassengerUserSwitching",
			sizeof("PassengerUserSwitching") - 1);
		Json::Value &hierarchyMember = addOptionContainerHierarchyMember(optionContainer,
			serverConfig.userSwitchingSourceFile,
			serverConfig.userSwitchingSourceLine);
		hierarchyMember["value"] = serverConfig.userSwitching;
	}
}



} // namespace Apache2Module
} // namespace Passenger
