
class Runner
    attr_reader :scopes
  
    def initialize
        @scopes = []
    end
  
    def task(name)
        puts "(Task) [#{scopes.join('::')}] #{name}"
  
        begin
            yield
        rescue => e
            puts "Error: #{e.message}"
            puts "Scope: [#{scopes.join('::')}] #{name}"
            puts "Backtrace:\n\t#{e.backtrace.join("\n\t")}"
            exit 1
        end
    end
  
    def scope(name)
        @scopes.push(name)
        yield
        puts "Scope [#{scopes.join('::')}] complete"
    ensure
        @scopes.pop
    end
  
    def exec(cmd, *args)
        puts " > #{cmd} #{args.join(' ')}"
        system(cmd, *args) || raise("Failed to execute command")
    end
end

scripts = [
    "01-build-user-space",
    "02-build-kernel",
]

if ARGV.length > 0
    scripts = ARGV
end

runner = Runner.new
build_root = ENV["WUSO_BUILD_ROOT"]

runner.scope("make-distro") do
    for script in scripts
        runner.scope(script) do
            require_relative script
            run(runner, build_root)
        end
    end
end

puts "Distro build complete!"
