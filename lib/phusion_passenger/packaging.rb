#  Phusion Passenger - https://www.phusionpassenger.com/
#  Copyright (c) 2010-2013 Phusion
#
#  "Phusion Passenger" is a trademark of Hongli Lai & Ninh Bui.
#
#  See LICENSE file for license information.

module PhusionPassenger

module Packaging
	# A list of HTML files that are generated with Asciidoc.
	ASCII_DOCS = [
		'doc/Users guide Apache.html',
		'doc/Users guide Nginx.html',
		'doc/Users guide Standalone.html',
		'doc/Security of user switching support.html',
		'doc/Architectural overview.html'
	]

	# Files that must be generated before packaging.
	PREGENERATED_FILES = [
		'ext/common/Constants.h',
		'doc/Packaging.html'
	] + ASCII_DOCS
	
	USER_EXECUTABLES = [
		'passenger',
		'passenger-install-apache2-module',
		'passenger-install-nginx-module',
		'passenger-config'
	]
	
	SUPER_USER_EXECUTABLES = [
		'passenger-status',
		'passenger-memory-stats',
		'passenger-irb'
	]
	
	# A list of globs which match all files that should be packaged
	# in the Phusion Passenger gem or tarball.
	GLOB = [
		'.gitignore',
		'.travis.yml',
		'configure',
		'Rakefile',
		'README.md',
		'CONTRIBUTORS',
		'CONTRIBUTING.md',
		'LICENSE',
		'INSTALL.md',
		'NEWS',
		'passenger-enterprise-server.gemspec',
		'build/*.rb',
		'lib/*.rb',
		'lib/**/*.rb',
		'lib/**/*.py',
		'bin/*',
		'doc/**/*',
		'man/*',
		'debian.template/**/*',
		'rpm/**/*',
		'helper-scripts/**/*',
		'ext/common/**/*.{cpp,c,h,hpp,md,erb}',
		'ext/apache2/*.{cpp,h,hpp,c}',
		'ext/nginx/*.{c,cpp,h,erb}',
		'ext/nginx/config',
		'ext/boost/**/*',
		'ext/libev/{LICENSE,Changes,README,Makefile.am,Makefile.in}',
		'ext/libev/{*.m4,autogen.sh,config.guess,config.h.in,config.sub}',
		'ext/libev/{configure,configure.ac,depcomp,install-sh,ltmain.sh,missing,mkinstalldirs}',
		'ext/libev/{*.h,*.c}',
		'ext/libeio/{LICENSE,Changes,README,Makefile.am,Makefile.in}',
		'ext/libeio/{*.m4,autogen.sh,config.guess,config.h.in,config.sub}',
		'ext/libeio/{configure,configure.ac,install-sh,ltmain.sh,missing,mkinstalldirs}',
		'ext/libeio/{*.h,*.c}',
		'ext/oxt/*.hpp',
		'ext/oxt/*.cpp',
		'ext/oxt/*.txt',
		'ext/oxt/detail/*.hpp',
		'ext/ruby/*.{c,rb}',
		'dev/*',
		'resources/**/*',
		'test/.rspec',
		'test/*.example',
		'test/*.travis',
		'test/*.supp',
		'test/support/*.{c,cpp,h,rb}',
		'test/tut/*',
		'test/cxx/**/*.{cpp,h}',
		'test/oxt/*.{cpp,hpp}',
		'test/ruby/**/*',
		'test/integration_tests/**/*',
		'test/stub/**/*',
		'test/stub/**/.*'
	]
	
	EXCLUDE_GLOB = [
		'test/stub/rails_apps/3.0/empty/help/**/*',
		'test/stub/*.dSYM'
	]

	# Files that should be excluded from the Debian tarball.
	DEBIAN_EXCLUDE_GLOB = [
		"debian.template/**/*",
	]

	def self.files
		return Dir[*GLOB] - Dir[*EXCLUDE_GLOB]
	end

	def self.debian_orig_tarball_files
		return files - Dir[*DEBIAN_EXCLUDE_GLOB]
	end
end

end # module PhusionPassenger
