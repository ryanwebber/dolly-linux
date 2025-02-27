WUSO_BUILD_JOBS = ENV["WUSO_BUILD_JOBS"] || "8"

def run(runner, build_root)
    runner.task("Build user space") do
        runner.exec("make", "-C", "#{build_root}/userspace", "-j#{WUSO_BUILD_JOBS}")
    end
end
