require "rake/extensiontask"
require 'rubygems/package_task'
require './lib/polylines_gti/version'

Rake::ExtensionTask.new "polylines_gti" do |ext|
  ext.lib_dir = "lib/polylines_gti"
end

s = Gem::Specification.new do |s|
  s.name = 'polylines_gti'
  s.version = PolylinesGti::VERSION
  s.date = Time.now.utc.strftime("%Y-%m-%d")
  s.summary = "A fast polyline decoder implemented in C"
  s.description = "A fast polyline decoder implemented in C."
  s.homepage = "https://github.com/stianselland/polylines_gti"
  s.authors = ["Stian Selland"]
  s.email = "stian@quicklog.no"
  s.license = "GPL2"
  s.extensions = %w[ext/polylines_gti/extconf.rb]
  s.files = %w[ 
    LICENSE
    Rakefile
    ext/polylines_gti/extconf.rb
    ext/polylines_gti/polylines_gti.c
    lib/polylines_gti.rb
    lib/polylines_gti/version.rb
  ]
end

# Creates the gem package
Gem::PackageTask.new s do end

# Sanity test
task test: %w[compile] do
  ruby '-Ilib', '-rpolylines_gti', '-e', 'p PolylinesGti.new()'
end

task default: :test
