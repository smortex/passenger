#  Phusion Passenger - https://www.phusionpassenger.com/
#  Copyright (c) 2010-2017 Phusion Holding B.V.
#
#  "Passenger", "Phusion Passenger" and "Union Station" are registered
#  trademarks of Phusion Holding B.V.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#  THE SOFTWARE.

AGENT_TARGET = "#{AGENT_OUTPUT_DIR}#{PhusionPassenger::AGENT_EXE}"
AGENT_MAIN_OBJECT = "#{AGENT_OUTPUT_DIR}AgentMain.o"
AGENT_OBJECTS = {
  AGENT_MAIN_OBJECT =>
    "src/agent/AgentMain.cpp",
  "#{AGENT_OUTPUT_DIR}AgentFundamentals.o" =>
    "src/agent/Shared/Fundamentals/Implementation.cpp",
  "#{AGENT_OUTPUT_DIR}WatchdogMain.o" =>
    "src/agent/Watchdog/WatchdogMain.cpp",
  "#{AGENT_OUTPUT_DIR}CoreMain.o" =>
    "src/agent/Core/CoreMain.cpp",
  "#{AGENT_OUTPUT_DIR}CoreApplicationPool.o" =>
    "src/agent/Core/ApplicationPool/Implementation.cpp",
  "#{AGENT_OUTPUT_DIR}CoreController.o" =>
    "src/agent/Core/Controller/Implementation.cpp",
  "#{AGENT_OUTPUT_DIR}SystemMetricsMain.o" =>
    "src/agent/SystemMetrics/SystemMetricsMain.cpp",
  "#{AGENT_OUTPUT_DIR}TempDirToucherMain.o" =>
    "src/agent/TempDirToucher/TempDirToucherMain.cpp",
  "#{AGENT_OUTPUT_DIR}SpawnPreparerMain.o" =>
    "src/agent/SpawnPreparer/SpawnPreparerMain.cpp"
}

# Agent-specific compiler flags.
let(:agent_cflags) do
  result = []
  result << '-O' if OPTIMIZE
  result << '-DUSE_SELINUX' if USE_SELINUX
  result << '-flto' if LTO
  result.join(' ')
end

# Agent-specific linker flags.
let(:agent_ldflags) do
  result = []
  result << '-O' if OPTIMIZE
  result << '-flto' if LTO
  result << '-lselinux' if USE_SELINUX
  # Extra linker flags for backtrace_symbols() to generate useful output (see agent/Base.cpp).
  result << PlatformInfo.export_dynamic_flags
  # Enable dead symbol elimination on OS X.
  result << '-Wl,-dead_strip' if PlatformInfo.os_name_simple == 'macosx'
  result.join(' ')
end

# Define compilation tasks for object files.
AGENT_OBJECTS.each_pair do |object, source|
  define_cxx_object_compilation_task(
    object,
    source,
    lambda { {
      :include_paths => [
        "src/agent",
        *CXX_SUPPORTLIB_INCLUDE_PATHS
      ],
      :flags => [
        agent_cflags,
        libev_cflags,
        libuv_cflags,
        websocketpp_cflags,
        PlatformInfo.curl_flags,
        PlatformInfo.zlib_flags
      ]
    } }
  )
end

# Define compilation task for the agent executable.
agent_libs = COMMON_LIBRARY.
  only(:base, :base64, :union_station_filter, :process_management_ruby, :other).
  exclude('WatchdogLauncher.o')
dependencies = AGENT_OBJECTS.keys + [
  LIBBOOST_OXT,
  agent_libs.link_objects,
  LIBEV_TARGET,
  LIBUV_TARGET
].flatten.compact
file(AGENT_TARGET => dependencies) do
  sh "mkdir -p #{AGENT_OUTPUT_DIR}" if !File.directory?(AGENT_OUTPUT_DIR)
  create_cxx_executable(AGENT_TARGET,
    [
      agent_libs.link_objects_as_string,
      AGENT_OBJECTS.keys,
      LIBBOOST_OXT_LINKARG
    ],
    :flags => [
      libev_libs,
      libuv_libs,
      websocketpp_libs,
      PlatformInfo.curl_libs,
      PlatformInfo.zlib_libs,
      PlatformInfo.crypto_libs,
      PlatformInfo.portability_cxx_ldflags,
      agent_ldflags
    ]
  )
end

desc 'Build the agent'
task :agent => AGENT_TARGET

task 'common:clean' do
  sh "rm -rf #{AGENT_OUTPUT_DIR}"
end
