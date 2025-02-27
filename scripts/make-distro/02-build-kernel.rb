
KERNEL_ARCH = ENV["KERNEL_ARCH"] || "x86_64"
KERNEL_CROSS_COMPILE = ENV["KERNEL_CROSS_COMPILE"] || "x86_64-linux-gnu-"
KERNEL_VERSION = ENV["KERNEL_VERSION"] || "linux-6.13.5"
KERNEL_BUILD_JOBS = ENV["KERNEL_BUILD_JOBS"] || "8"

def run(runner, build_root)
    runner.task("Download kernel source") do
        runner.exec("wget", "https://cdn.kernel.org/pub/linux/kernel/v6.x/#{KERNEL_VERSION}.tar.xz")
    end

    runner.task("Extract kernel source") do
        runner.exec("tar", "xvf", "#{KERNEL_VERSION}.tar.xz")
    end

    runner.task("Build kernel") do
        runner.exec("make", "-C", KERNEL_VERSION, "ARCH=#{KERNEL_ARCH}", "CROSS_COMPILE=#{KERNEL_CROSS_COMPILE}", "defconfig")
        runner.exec("make", "-C", KERNEL_VERSION, "ARCH=#{KERNEL_ARCH}", "CROSS_COMPILE=#{KERNEL_CROSS_COMPILE}", "-j#{KERNEL_BUILD_JOBS}")
    end
end
