require './lib/polylines_gti/version'

Gem::Specification.new do |s|
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