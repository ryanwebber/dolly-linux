.global __syscall$read
.global __syscall$write
.global __syscall$open
.global __syscall$close
.global __syscall$newstat
.global __syscall$newfstat
.global __syscall$newlstat
.global __syscall$poll
.global __syscall$lseek
.global __syscall$mmap
.global __syscall$mprotect
.global __syscall$munmap
.global __syscall$brk
.global __syscall$rt_sigaction
.global __syscall$rt_sigprocmask
.global __syscall$rt_sigreturn
.global __syscall$ioctl
.global __syscall$pread64
.global __syscall$pwrite64
.global __syscall$readv
.global __syscall$writev
.global __syscall$access
.global __syscall$pipe
.global __syscall$select
.global __syscall$sched_yield
.global __syscall$mremap
.global __syscall$msync
.global __syscall$mincore
.global __syscall$madvise
.global __syscall$shmget
.global __syscall$shmat
.global __syscall$shmctl
.global __syscall$dup
.global __syscall$dup2
.global __syscall$pause
.global __syscall$nanosleep
.global __syscall$getitimer
.global __syscall$alarm
.global __syscall$setitimer
.global __syscall$getpid
.global __syscall$sendfile64
.global __syscall$socket
.global __syscall$connect
.global __syscall$accept
.global __syscall$sendto
.global __syscall$recvfrom
.global __syscall$sendmsg
.global __syscall$recvmsg
.global __syscall$shutdown
.global __syscall$bind
.global __syscall$listen
.global __syscall$getsockname
.global __syscall$getpeername
.global __syscall$socketpair
.global __syscall$setsockopt
.global __syscall$getsockopt
.global __syscall$clone
.global __syscall$fork
.global __syscall$vfork
.global __syscall$execve
.global __syscall$exit
.global __syscall$wait4
.global __syscall$kill
.global __syscall$newuname
.global __syscall$semget
.global __syscall$semop
.global __syscall$semctl
.global __syscall$shmdt
.global __syscall$msgget
.global __syscall$msgsnd
.global __syscall$msgrcv
.global __syscall$msgctl
.global __syscall$fcntl
.global __syscall$flock
.global __syscall$fsync
.global __syscall$fdatasync
.global __syscall$truncate
.global __syscall$ftruncate
.global __syscall$getdents
.global __syscall$getcwd
.global __syscall$chdir
.global __syscall$fchdir
.global __syscall$rename
.global __syscall$mkdir
.global __syscall$rmdir
.global __syscall$creat
.global __syscall$link
.global __syscall$unlink
.global __syscall$symlink
.global __syscall$readlink
.global __syscall$chmod
.global __syscall$fchmod
.global __syscall$chown
.global __syscall$fchown
.global __syscall$lchown
.global __syscall$umask
.global __syscall$gettimeofday
.global __syscall$getrlimit
.global __syscall$getrusage
.global __syscall$sysinfo
.global __syscall$times
.global __syscall$ptrace
.global __syscall$getuid
.global __syscall$syslog
.global __syscall$getgid
.global __syscall$setuid
.global __syscall$setgid
.global __syscall$geteuid
.global __syscall$getegid
.global __syscall$setpgid
.global __syscall$getppid
.global __syscall$getpgrp
.global __syscall$setsid
.global __syscall$setreuid
.global __syscall$setregid
.global __syscall$getgroups
.global __syscall$setgroups
.global __syscall$setresuid
.global __syscall$getresuid
.global __syscall$setresgid
.global __syscall$getresgid
.global __syscall$getpgid
.global __syscall$setfsuid
.global __syscall$setfsgid
.global __syscall$getsid
.global __syscall$capget
.global __syscall$capset
.global __syscall$rt_sigpending
.global __syscall$rt_sigtimedwait
.global __syscall$rt_sigqueueinfo
.global __syscall$rt_sigsuspend
.global __syscall$sigaltstack
.global __syscall$utime
.global __syscall$mknod
.global __syscall$fstatfs
.global __syscall$sysfs
.global __syscall$getpriority
.global __syscall$setpriority
.global __syscall$sched_setparam
.global __syscall$sched_getparam
.global __syscall$sched_setscheduler
.global __syscall$sched_getscheduler
.global __syscall$sched_get_priority_max
.global __syscall$sched_get_priority_min
.global __syscall$sched_rr_get_interval
.global __syscall$mlock
.global __syscall$munlock
.global __syscall$mlockall
.global __syscall$munlockall
.global __syscall$vhangup
.global __syscall$modify_ldt
.global __syscall$pivot_root
.global __syscall$setrlimit
.global __syscall$chroot
.global __syscall$sync
.global __syscall$acct
.global __syscall$settimeofday
.global __syscall$mount
.global __syscall$umount
.global __syscall$swapon
.global __syscall$swapoff
.global __syscall$reboot
.global __syscall$sethostname
.global __syscall$setdomainname
.global __syscall$iopl
.global __syscall$ioperm
.global __syscall$lsetxattr
.global __syscall$fsetxattr
.global __syscall$getxattr
.global __syscall$lgetxattr
.global __syscall$fgetxattr
.global __syscall$listxattr
.global __syscall$llistxattr
.global __syscall$flistxattr
.global __syscall$removexattr
.global __syscall$lremovexattr
.global __syscall$fremovexattr
.global __syscall$tkill
.global __syscall$time
.global __syscall$futex
.global __syscall$sched_setaffinity
.global __syscall$sched_getaffinity
.global __syscall$io_submit
.global __syscall$io_cancel
.global __syscall$restart_syscall
.global __syscall$semtimedop
.global __syscall$fadvise64
.global __syscall$timer_create
.global __syscall$timer_settime
.global __syscall$timer_gettime
.global __syscall$timer_getoverrun
.global __syscall$timer_delete
.global __syscall$clock_settime
.global __syscall$clock_gettime
.global __syscall$clock_getres
.global __syscall$clock_nanosleep
.global __syscall$exit_group
.global __syscall$epoll_wait
.global __syscall$epoll_ctl
.global __syscall$tgkill
.global __syscall$utimes
.global __syscall$mq_open
.global __syscall$mq_unlink
.global __syscall$mq_timedsend
.global __syscall$mq_timedreceive
.global __syscall$mq_notify
.global __syscall$mq_getsetattr
.global __syscall$kexec_load
.global __syscall$waitid
.global __syscall$add_key
.global __syscall$request_key
.global __syscall$keyctl
.global __syscall$ioprio_set
.global __syscall$ioprio_get
.global __syscall$inotify_init
.global __syscall$inotify_add_watch
.global __syscall$inotify_rm_watch
.global __syscall$migrate_pages
.global __syscall$openat
.global __syscall$mkdirat
.global __syscall$mknodat
.global __syscall$fchownat
.global __syscall$futimesat
.global __syscall$newfstatat
.global __syscall$unlinkat
.global __syscall$renameat
.global __syscall$linkat
.global __syscall$symlinkat
.global __syscall$readlinkat
.global __syscall$fchmodat
.global __syscall$faccessat
.global __syscall$pselect6
.global __syscall$ppoll
.global __syscall$unshare
.global __syscall$set_robust_list
.global __syscall$get_robust_list
.global __syscall$splice
.global __syscall$tee
.global __syscall$sync_file_range
.global __syscall$vmsplice
.global __syscall$move_pages
.global __syscall$utimensat
.global __syscall$epoll_pwait
.global __syscall$signalfd
.global __syscall$timerfd_create
.global __syscall$eventfd
.global __syscall$fallocate
.global __syscall$timerfd_settime
.global __syscall$timerfd_gettime
.global __syscall$accept4
.global __syscall$signalfd4
.global __syscall$eventfd2
.global __syscall$epoll_create1
.global __syscall$dup3
.global __syscall$pipe2
.global __syscall$inotify_init1
.global __syscall$preadv
.global __syscall$pwritev
.global __syscall$rt_tgsigqueueinfo
.global __syscall$perf_event_open
.global __syscall$recvmmsg
.global __syscall$fanotify_init
.global __syscall$fanotify_mark
.global __syscall$prlimit64
.global __syscall$name_to_handle_at
.global __syscall$open_by_handle_at
.global __syscall$clock_adjtime
.global __syscall$syncfs
.global __syscall$sendmmsg
.global __syscall$setns
.global __syscall$getcpu
.global __syscall$process_vm_readv
.global __syscall$process_vm_writev
.global __syscall$kcmp
.global __syscall$finit_module
.global __syscall$sched_setattr
.global __syscall$sched_getattr
.global __syscall$renameat2
.global __syscall$seccomp
.global __syscall$getrandom
.global __syscall$memfd_create
.global __syscall$kexec_file_load
.global __syscall$bpf
.global __syscall$execveat
.global __syscall$userfaultfd
.global __syscall$membarrier
.global __syscall$mlock2
.global __syscall$copy_file_range
.global __syscall$preadv2
.global __syscall$pwritev2
.global __syscall$pkey_mprotect
.global __syscall$pkey_alloc
.global __syscall$pkey_free
.global __syscall$statx
.global __syscall$io_pgetevents
.global __syscall$rseq
.global __syscall$uretprobe
.global __syscall$io_uring_register
.global __syscall$open_tree
.global __syscall$move_mount
.global __syscall$fsopen
.global __syscall$fsconfig
.global __syscall$fsmount
.global __syscall$fspick
.global __syscall$pidfd_open
.global __syscall$clone3
.global __syscall$close_range
.global __syscall$openat2
.global __syscall$pidfd_getfd
.global __syscall$faccessat2
.global __syscall$process_madvise
.global __syscall$epoll_pwait2
.global __syscall$mount_setattr
.global __syscall$quotactl_fd
.global __syscall$landlock_create_ruleset
.global __syscall$landlock_add_rule
.global __syscall$landlock_restrict_self
.global __syscall$memfd_secret
.global __syscall$process_mrelease
.global __syscall$futex_waitv
.global __syscall$set_mempolicy_home_node
.global __syscall$cachestat
.global __syscall$fchmodat2
.global __syscall$map_shadow_stack
.global __syscall$futex_wake
.global __syscall$futex_wait
.global __syscall$futex_requeue
.global __syscall$statmount
.global __syscall$listmount
.global __syscall$lsm_get_self_attr
.global __syscall$lsm_set_self_attr
.global __syscall$lsm_list_modules
.global __syscall$mseal
.global __syscall$setxattrat
.global __syscall$getxattrat
.global __syscall$listxattrat
.global __syscall$removexattrat

__syscall$read:
    mov rax, 0
    syscall
    ret

__syscall$write:
    mov rax, 1
    syscall
    ret

__syscall$open:
    mov rax, 2
    syscall
    ret

__syscall$close:
    mov rax, 3
    syscall
    ret

__syscall$newstat:
    mov rax, 4
    syscall
    ret

__syscall$newfstat:
    mov rax, 5
    syscall
    ret

__syscall$newlstat:
    mov rax, 6
    syscall
    ret

__syscall$poll:
    mov rax, 7
    syscall
    ret

__syscall$lseek:
    mov rax, 8
    syscall
    ret

__syscall$mmap:
    mov rax, 9
    syscall
    ret

__syscall$mprotect:
    mov rax, 10
    syscall
    ret

__syscall$munmap:
    mov rax, 11
    syscall
    ret

__syscall$brk:
    mov rax, 12
    syscall
    ret

__syscall$rt_sigaction:
    mov rax, 13
    syscall
    ret

__syscall$rt_sigprocmask:
    mov rax, 14
    syscall
    ret

__syscall$rt_sigreturn:
    mov rax, 15
    syscall
    ret

__syscall$ioctl:
    mov rax, 16
    syscall
    ret

__syscall$pread64:
    mov rax, 17
    syscall
    ret

__syscall$pwrite64:
    mov rax, 18
    syscall
    ret

__syscall$readv:
    mov rax, 19
    syscall
    ret

__syscall$writev:
    mov rax, 20
    syscall
    ret

__syscall$access:
    mov rax, 21
    syscall
    ret

__syscall$pipe:
    mov rax, 22
    syscall
    ret

__syscall$select:
    mov rax, 23
    syscall
    ret

__syscall$sched_yield:
    mov rax, 24
    syscall
    ret

__syscall$mremap:
    mov rax, 25
    syscall
    ret

__syscall$msync:
    mov rax, 26
    syscall
    ret

__syscall$mincore:
    mov rax, 27
    syscall
    ret

__syscall$madvise:
    mov rax, 28
    syscall
    ret

__syscall$shmget:
    mov rax, 29
    syscall
    ret

__syscall$shmat:
    mov rax, 30
    syscall
    ret

__syscall$shmctl:
    mov rax, 31
    syscall
    ret

__syscall$dup:
    mov rax, 32
    syscall
    ret

__syscall$dup2:
    mov rax, 33
    syscall
    ret

__syscall$pause:
    mov rax, 34
    syscall
    ret

__syscall$nanosleep:
    mov rax, 35
    syscall
    ret

__syscall$getitimer:
    mov rax, 36
    syscall
    ret

__syscall$alarm:
    mov rax, 37
    syscall
    ret

__syscall$setitimer:
    mov rax, 38
    syscall
    ret

__syscall$getpid:
    mov rax, 39
    syscall
    ret

__syscall$sendfile64:
    mov rax, 40
    syscall
    ret

__syscall$socket:
    mov rax, 41
    syscall
    ret

__syscall$connect:
    mov rax, 42
    syscall
    ret

__syscall$accept:
    mov rax, 43
    syscall
    ret

__syscall$sendto:
    mov rax, 44
    syscall
    ret

__syscall$recvfrom:
    mov rax, 45
    syscall
    ret

__syscall$sendmsg:
    mov rax, 46
    syscall
    ret

__syscall$recvmsg:
    mov rax, 47
    syscall
    ret

__syscall$shutdown:
    mov rax, 48
    syscall
    ret

__syscall$bind:
    mov rax, 49
    syscall
    ret

__syscall$listen:
    mov rax, 50
    syscall
    ret

__syscall$getsockname:
    mov rax, 51
    syscall
    ret

__syscall$getpeername:
    mov rax, 52
    syscall
    ret

__syscall$socketpair:
    mov rax, 53
    syscall
    ret

__syscall$setsockopt:
    mov rax, 54
    syscall
    ret

__syscall$getsockopt:
    mov rax, 55
    syscall
    ret

__syscall$clone:
    mov rax, 56
    syscall
    ret

__syscall$fork:
    mov rax, 57
    syscall
    ret

__syscall$vfork:
    mov rax, 58
    syscall
    ret

__syscall$execve:
    mov rax, 59
    syscall
    ret

__syscall$exit:
    mov rax, 60
    syscall
    ret

__syscall$wait4:
    mov rax, 61
    syscall
    ret

__syscall$kill:
    mov rax, 62
    syscall
    ret

__syscall$newuname:
    mov rax, 63
    syscall
    ret

__syscall$semget:
    mov rax, 64
    syscall
    ret

__syscall$semop:
    mov rax, 65
    syscall
    ret

__syscall$semctl:
    mov rax, 66
    syscall
    ret

__syscall$shmdt:
    mov rax, 67
    syscall
    ret

__syscall$msgget:
    mov rax, 68
    syscall
    ret

__syscall$msgsnd:
    mov rax, 69
    syscall
    ret

__syscall$msgrcv:
    mov rax, 70
    syscall
    ret

__syscall$msgctl:
    mov rax, 71
    syscall
    ret

__syscall$fcntl:
    mov rax, 72
    syscall
    ret

__syscall$flock:
    mov rax, 73
    syscall
    ret

__syscall$fsync:
    mov rax, 74
    syscall
    ret

__syscall$fdatasync:
    mov rax, 75
    syscall
    ret

__syscall$truncate:
    mov rax, 76
    syscall
    ret

__syscall$ftruncate:
    mov rax, 77
    syscall
    ret

__syscall$getdents:
    mov rax, 78
    syscall
    ret

__syscall$getcwd:
    mov rax, 79
    syscall
    ret

__syscall$chdir:
    mov rax, 80
    syscall
    ret

__syscall$fchdir:
    mov rax, 81
    syscall
    ret

__syscall$rename:
    mov rax, 82
    syscall
    ret

__syscall$mkdir:
    mov rax, 83
    syscall
    ret

__syscall$rmdir:
    mov rax, 84
    syscall
    ret

__syscall$creat:
    mov rax, 85
    syscall
    ret

__syscall$link:
    mov rax, 86
    syscall
    ret

__syscall$unlink:
    mov rax, 87
    syscall
    ret

__syscall$symlink:
    mov rax, 88
    syscall
    ret

__syscall$readlink:
    mov rax, 89
    syscall
    ret

__syscall$chmod:
    mov rax, 90
    syscall
    ret

__syscall$fchmod:
    mov rax, 91
    syscall
    ret

__syscall$chown:
    mov rax, 92
    syscall
    ret

__syscall$fchown:
    mov rax, 93
    syscall
    ret

__syscall$lchown:
    mov rax, 94
    syscall
    ret

__syscall$umask:
    mov rax, 95
    syscall
    ret

__syscall$gettimeofday:
    mov rax, 96
    syscall
    ret

__syscall$getrlimit:
    mov rax, 97
    syscall
    ret

__syscall$getrusage:
    mov rax, 98
    syscall
    ret

__syscall$sysinfo:
    mov rax, 99
    syscall
    ret

__syscall$times:
    mov rax, 100
    syscall
    ret

__syscall$ptrace:
    mov rax, 101
    syscall
    ret

__syscall$getuid:
    mov rax, 102
    syscall
    ret

__syscall$syslog:
    mov rax, 103
    syscall
    ret

__syscall$getgid:
    mov rax, 104
    syscall
    ret

__syscall$setuid:
    mov rax, 105
    syscall
    ret

__syscall$setgid:
    mov rax, 106
    syscall
    ret

__syscall$geteuid:
    mov rax, 107
    syscall
    ret

__syscall$getegid:
    mov rax, 108
    syscall
    ret

__syscall$setpgid:
    mov rax, 109
    syscall
    ret

__syscall$getppid:
    mov rax, 110
    syscall
    ret

__syscall$getpgrp:
    mov rax, 111
    syscall
    ret

__syscall$setsid:
    mov rax, 112
    syscall
    ret

__syscall$setreuid:
    mov rax, 113
    syscall
    ret

__syscall$setregid:
    mov rax, 114
    syscall
    ret

__syscall$getgroups:
    mov rax, 115
    syscall
    ret

__syscall$setgroups:
    mov rax, 116
    syscall
    ret

__syscall$setresuid:
    mov rax, 117
    syscall
    ret

__syscall$getresuid:
    mov rax, 118
    syscall
    ret

__syscall$setresgid:
    mov rax, 119
    syscall
    ret

__syscall$getresgid:
    mov rax, 120
    syscall
    ret

__syscall$getpgid:
    mov rax, 121
    syscall
    ret

__syscall$setfsuid:
    mov rax, 122
    syscall
    ret

__syscall$setfsgid:
    mov rax, 123
    syscall
    ret

__syscall$getsid:
    mov rax, 124
    syscall
    ret

__syscall$capget:
    mov rax, 125
    syscall
    ret

__syscall$capset:
    mov rax, 126
    syscall
    ret

__syscall$rt_sigpending:
    mov rax, 127
    syscall
    ret

__syscall$rt_sigtimedwait:
    mov rax, 128
    syscall
    ret

__syscall$rt_sigqueueinfo:
    mov rax, 129
    syscall
    ret

__syscall$rt_sigsuspend:
    mov rax, 130
    syscall
    ret

__syscall$sigaltstack:
    mov rax, 131
    syscall
    ret

__syscall$utime:
    mov rax, 132
    syscall
    ret

__syscall$mknod:
    mov rax, 133
    syscall
    ret

__syscall$personality:
    mov rax, 135
    syscall
    ret

__syscall$ustat:
    mov rax, 136
    syscall
    ret

__syscall$statfs:
    mov rax, 137
    syscall
    ret

__syscall$fstatfs:
    mov rax, 138
    syscall
    ret

__syscall$sysfs:
    mov rax, 139
    syscall
    ret

__syscall$getpriority:
    mov rax, 140
    syscall
    ret

__syscall$setpriority:
    mov rax, 141
    syscall
    ret

__syscall$sched_setparam:
    mov rax, 142
    syscall
    ret

__syscall$sched_getparam:
    mov rax, 143
    syscall
    ret

__syscall$sched_setscheduler:
    mov rax, 144
    syscall
    ret

__syscall$sched_getscheduler:
    mov rax, 145
    syscall
    ret

__syscall$sched_get_priority_max:
    mov rax, 146
    syscall
    ret

__syscall$sched_get_priority_min:
    mov rax, 147
    syscall
    ret

__syscall$sched_rr_get_interval:
    mov rax, 148
    syscall
    ret

__syscall$mlock:
    mov rax, 149
    syscall
    ret

__syscall$munlock:
    mov rax, 150
    syscall
    ret

__syscall$mlockall:
    mov rax, 151
    syscall
    ret

__syscall$munlockall:
    mov rax, 152
    syscall
    ret

__syscall$vhangup:
    mov rax, 153
    syscall
    ret

__syscall$modify_ldt:
    mov rax, 154
    syscall
    ret

__syscall$pivot_root:
    mov rax, 155
    syscall
    ret

__syscall$prctl:
    mov rax, 157
    syscall
    ret

__syscall$arch_prctl:
    mov rax, 158
    syscall
    ret

__syscall$adjtimex:
    mov rax, 159
    syscall
    ret

__syscall$setrlimit:
    mov rax, 160
    syscall
    ret

__syscall$chroot:
    mov rax, 161
    syscall
    ret

__syscall$sync:
    mov rax, 162
    syscall
    ret

__syscall$acct:
    mov rax, 163
    syscall
    ret

__syscall$settimeofday:
    mov rax, 164
    syscall
    ret

__syscall$mount:
    mov rax, 165
    syscall
    ret

__syscall$umount:
    mov rax, 166
    syscall
    ret

__syscall$swapon:
    mov rax, 167
    syscall
    ret

__syscall$swapoff:
    mov rax, 168
    syscall
    ret

__syscall$reboot:
    mov rax, 169
    syscall
    ret

__syscall$sethostname:
    mov rax, 170
    syscall
    ret

__syscall$setdomainname:
    mov rax, 171
    syscall
    ret

__syscall$iopl:
    mov rax, 172
    syscall
    ret

__syscall$ioperm:
    mov rax, 173
    syscall
    ret

__syscall$init_module:
    mov rax, 175
    syscall
    ret

__syscall$delete_module:
    mov rax, 176
    syscall
    ret

__syscall$quotactl:
    mov rax, 179
    syscall
    ret

__syscall$gettid:
    mov rax, 186
    syscall
    ret

__syscall$readahead:
    mov rax, 187
    syscall
    ret

__syscall$setxattr:
    mov rax, 188
    syscall
    ret

__syscall$lsetxattr:
    mov rax, 189
    syscall
    ret

__syscall$fsetxattr:
    mov rax, 190
    syscall
    ret

__syscall$getxattr:
    mov rax, 191
    syscall
    ret

__syscall$lgetxattr:
    mov rax, 192
    syscall
    ret

__syscall$fgetxattr:
    mov rax, 193
    syscall
    ret

__syscall$listxattr:
    mov rax, 194
    syscall
    ret

__syscall$llistxattr:
    mov rax, 195
    syscall
    ret

__syscall$flistxattr:
    mov rax, 196
    syscall
    ret

__syscall$removexattr:
    mov rax, 197
    syscall
    ret

__syscall$lremovexattr:
    mov rax, 198
    syscall
    ret

__syscall$fremovexattr:
    mov rax, 199
    syscall
    ret

__syscall$tkill:
    mov rax, 200
    syscall
    ret

__syscall$time:
    mov rax, 201
    syscall
    ret

__syscall$futex:
    mov rax, 202
    syscall
    ret

__syscall$sched_setaffinity:
    mov rax, 203
    syscall
    ret

__syscall$sched_getaffinity:
    mov rax, 204
    syscall
    ret

__syscall$io_setup:
    mov rax, 206
    syscall
    ret

__syscall$io_destroy:
    mov rax, 207
    syscall
    ret

__syscall$io_getevents:
    mov rax, 208
    syscall
    ret

__syscall$io_submit:
    mov rax, 209
    syscall
    ret

__syscall$io_cancel:
    mov rax, 210
    syscall
    ret

__syscall$epoll_create:
    mov rax, 213
    syscall
    ret

__syscall$remap_file_pages:
    mov rax, 216
    syscall
    ret

__syscall$getdents64:
    mov rax, 217
    syscall
    ret

__syscall$set_tid_address:
    mov rax, 218
    syscall
    ret

__syscall$restart_syscall:
    mov rax, 219
    syscall
    ret

__syscall$semtimedop:
    mov rax, 220
    syscall
    ret

__syscall$fadvise64:
    mov rax, 221
    syscall
    ret

__syscall$timer_create:
    mov rax, 222
    syscall
    ret

__syscall$timer_settime:
    mov rax, 223
    syscall
    ret

__syscall$timer_gettime:
    mov rax, 224
    syscall
    ret

__syscall$timer_getoverrun:
    mov rax, 225
    syscall
    ret

__syscall$timer_delete:
    mov rax, 226
    syscall
    ret

__syscall$clock_settime:
    mov rax, 227
    syscall
    ret

__syscall$clock_gettime:
    mov rax, 228
    syscall
    ret

__syscall$clock_getres:
    mov rax, 229
    syscall
    ret

__syscall$clock_nanosleep:
    mov rax, 230
    syscall
    ret

__syscall$exit_group:
    mov rax, 231
    syscall
    ret

__syscall$epoll_wait:
    mov rax, 232
    syscall
    ret

__syscall$epoll_ctl:
    mov rax, 233
    syscall
    ret

__syscall$tgkill:
    mov rax, 234
    syscall
    ret

__syscall$utimes:
    mov rax, 235
    syscall
    ret

__syscall$mbind:
    mov rax, 237
    syscall
    ret

__syscall$set_mempolicy:
    mov rax, 238
    syscall
    ret

__syscall$get_mempolicy:
    mov rax, 239
    syscall
    ret

__syscall$mq_open:
    mov rax, 240
    syscall
    ret

__syscall$mq_unlink:
    mov rax, 241
    syscall
    ret

__syscall$mq_timedsend:
    mov rax, 242
    syscall
    ret

__syscall$mq_timedreceive:
    mov rax, 243
    syscall
    ret

__syscall$mq_notify:
    mov rax, 244
    syscall
    ret

__syscall$mq_getsetattr:
    mov rax, 245
    syscall
    ret

__syscall$kexec_load:
    mov rax, 246
    syscall
    ret

__syscall$waitid:
    mov rax, 247
    syscall
    ret

__syscall$add_key:
    mov rax, 248
    syscall
    ret

__syscall$request_key:
    mov rax, 249
    syscall
    ret

__syscall$keyctl:
    mov rax, 250
    syscall
    ret

__syscall$ioprio_set:
    mov rax, 251
    syscall
    ret

__syscall$ioprio_get:
    mov rax, 252
    syscall
    ret

__syscall$inotify_init:
    mov rax, 253
    syscall
    ret

__syscall$inotify_add_watch:
    mov rax, 254
    syscall
    ret

__syscall$inotify_rm_watch:
    mov rax, 255
    syscall
    ret

__syscall$migrate_pages:
    mov rax, 256
    syscall
    ret

__syscall$openat:
    mov rax, 257
    syscall
    ret

__syscall$mkdirat:
    mov rax, 258
    syscall
    ret

__syscall$mknodat:
    mov rax, 259
    syscall
    ret

__syscall$fchownat:
    mov rax, 260
    syscall
    ret

__syscall$futimesat:
    mov rax, 261
    syscall
    ret

__syscall$newfstatat:
    mov rax, 262
    syscall
    ret

__syscall$unlinkat:
    mov rax, 263
    syscall
    ret

__syscall$renameat:
    mov rax, 264
    syscall
    ret

__syscall$linkat:
    mov rax, 265
    syscall
    ret

__syscall$symlinkat:
    mov rax, 266
    syscall
    ret

__syscall$readlinkat:
    mov rax, 267
    syscall
    ret

__syscall$fchmodat:
    mov rax, 268
    syscall
    ret

__syscall$faccessat:
    mov rax, 269
    syscall
    ret

__syscall$pselect6:
    mov rax, 270
    syscall
    ret

__syscall$ppoll:
    mov rax, 271
    syscall
    ret

__syscall$unshare:
    mov rax, 272
    syscall
    ret

__syscall$set_robust_list:
    mov rax, 273
    syscall
    ret

__syscall$get_robust_list:
    mov rax, 274
    syscall
    ret

__syscall$splice:
    mov rax, 275
    syscall
    ret

__syscall$tee:
    mov rax, 276
    syscall
    ret

__syscall$sync_file_range:
    mov rax, 277
    syscall
    ret

__syscall$vmsplice:
    mov rax, 278
    syscall
    ret

__syscall$move_pages:
    mov rax, 279
    syscall
    ret

__syscall$utimensat:
    mov rax, 280
    syscall
    ret

__syscall$epoll_pwait:
    mov rax, 281
    syscall
    ret

__syscall$signalfd:
    mov rax, 282
    syscall
    ret

__syscall$timerfd_create:
    mov rax, 283
    syscall
    ret

__syscall$eventfd:
    mov rax, 284
    syscall
    ret

__syscall$fallocate:
    mov rax, 285
    syscall
    ret

__syscall$timerfd_settime:
    mov rax, 286
    syscall
    ret

__syscall$timerfd_gettime:
    mov rax, 287
    syscall
    ret

__syscall$accept4:
    mov rax, 288
    syscall
    ret

__syscall$signalfd4:
    mov rax, 289
    syscall
    ret

__syscall$eventfd2:
    mov rax, 290
    syscall
    ret

__syscall$epoll_create1:
    mov rax, 291
    syscall
    ret

__syscall$dup3:
    mov rax, 292
    syscall
    ret

__syscall$pipe2:
    mov rax, 293
    syscall
    ret

__syscall$inotify_init1:
    mov rax, 294
    syscall
    ret

__syscall$preadv:
    mov rax, 295
    syscall
    ret

__syscall$pwritev:
    mov rax, 296
    syscall
    ret

__syscall$rt_tgsigqueueinfo:
    mov rax, 297
    syscall
    ret

__syscall$perf_event_open:
    mov rax, 298
    syscall
    ret

__syscall$recvmmsg:
    mov rax, 299
    syscall
    ret

__syscall$fanotify_init:
    mov rax, 300
    syscall
    ret

__syscall$fanotify_mark:
    mov rax, 301
    syscall
    ret

__syscall$prlimit64:
    mov rax, 302
    syscall
    ret

__syscall$name_to_handle_at:
    mov rax, 303
    syscall
    ret

__syscall$open_by_handle_at:
    mov rax, 304
    syscall
    ret

__syscall$clock_adjtime:
    mov rax, 305
    syscall
    ret

__syscall$syncfs:
    mov rax, 306
    syscall
    ret

__syscall$sendmmsg:
    mov rax, 307
    syscall
    ret

__syscall$setns:
    mov rax, 308
    syscall
    ret

__syscall$getcpu:
    mov rax, 309
    syscall
    ret

__syscall$process_vm_readv:
    mov rax, 310
    syscall
    ret

__syscall$process_vm_writev:
    mov rax, 311
    syscall
    ret

__syscall$kcmp:
    mov rax, 312
    syscall
    ret

__syscall$finit_module:
    mov rax, 313
    syscall
    ret

__syscall$sched_setattr:
    mov rax, 314
    syscall
    ret

__syscall$sched_getattr:
    mov rax, 315
    syscall
    ret

__syscall$renameat2:
    mov rax, 316
    syscall
    ret

__syscall$seccomp:
    mov rax, 317
    syscall
    ret

__syscall$getrandom:
    mov rax, 318
    syscall
    ret

__syscall$memfd_create:
    mov rax, 319
    syscall
    ret

__syscall$kexec_file_load:
    mov rax, 320
    syscall
    ret

__syscall$bpf:
    mov rax, 321
    syscall
    ret

__syscall$execveat:
    mov rax, 322
    syscall
    ret

__syscall$userfaultfd:
    mov rax, 323
    syscall
    ret

__syscall$membarrier:
    mov rax, 324
    syscall
    ret

__syscall$mlock2:
    mov rax, 325
    syscall
    ret

__syscall$copy_file_range:
    mov rax, 326
    syscall
    ret

__syscall$preadv2:
    mov rax, 327
    syscall
    ret

__syscall$pwritev2:
    mov rax, 328
    syscall
    ret

__syscall$pkey_mprotect:
    mov rax, 329
    syscall
    ret

__syscall$pkey_alloc:
    mov rax, 330
    syscall
    ret

__syscall$pkey_free:
    mov rax, 331
    syscall
    ret

__syscall$statx:
    mov rax, 332
    syscall
    ret

__syscall$io_pgetevents:
    mov rax, 333
    syscall
    ret

__syscall$rseq:
    mov rax, 334
    syscall
    ret

__syscall$uretprobe:
    mov rax, 335
    syscall
    ret

__syscall$pidfd_send_signal:
    mov rax, 424
    syscall
    ret

__syscall$io_uring_setup:
    mov rax, 425
    syscall
    ret

__syscall$io_uring_enter:
    mov rax, 426
    syscall
    ret

__syscall$io_uring_register:
    mov rax, 427
    syscall
    ret

__syscall$open_tree:
    mov rax, 428
    syscall
    ret

__syscall$move_mount:
    mov rax, 429
    syscall
    ret

__syscall$fsopen:
    mov rax, 430
    syscall
    ret

__syscall$fsconfig:
    mov rax, 431
    syscall
    ret

__syscall$fsmount:
    mov rax, 432
    syscall
    ret

__syscall$fspick:
    mov rax, 433
    syscall
    ret

__syscall$pidfd_open:
    mov rax, 434
    syscall
    ret

__syscall$clone3:
    mov rax, 435
    syscall
    ret

__syscall$close_range:
    mov rax, 436
    syscall
    ret

__syscall$openat2:
    mov rax, 437
    syscall
    ret

__syscall$pidfd_getfd:
    mov rax, 438
    syscall
    ret

__syscall$faccessat2:
    mov rax, 439
    syscall
    ret

__syscall$process_madvise:
    mov rax, 440
    syscall
    ret

__syscall$epoll_pwait2:
    mov rax, 441
    syscall
    ret

__syscall$mount_setattr:
    mov rax, 442
    syscall
    ret

__syscall$quotactl_fd:
    mov rax, 443
    syscall
    ret

__syscall$landlock_create_ruleset:
    mov rax, 444
    syscall
    ret

__syscall$landlock_add_rule:
    mov rax, 445
    syscall
    ret

__syscall$landlock_restrict_self:
    mov rax, 446
    syscall
    ret

__syscall$memfd_secret:
    mov rax, 447
    syscall
    ret

__syscall$process_mrelease:
    mov rax, 448
    syscall
    ret

__syscall$futex_waitv:
    mov rax, 449
    syscall
    ret

__syscall$set_mempolicy_home_node:
    mov rax, 450
    syscall
    ret

__syscall$cachestat:
    mov rax, 451
    syscall
    ret

__syscall$fchmodat2:
    mov rax, 452
    syscall
    ret

__syscall$map_shadow_stack:
    mov rax, 453
    syscall
    ret

__syscall$futex_wake:
    mov rax, 454
    syscall
    ret

__syscall$futex_wait:
    mov rax, 455
    syscall
    ret

__syscall$futex_requeue:
    mov rax, 456
    syscall
    ret

__syscall$statmount:
    mov rax, 457
    syscall
    ret

__syscall$listmount:
    mov rax, 458
    syscall
    ret

__syscall$lsm_get_self_attr:
    mov rax, 459
    syscall
    ret

__syscall$lsm_set_self_attr:
    mov rax, 460
    syscall
    ret

__syscall$lsm_list_modules:
    mov rax, 461
    syscall
    ret

__syscall$mseal:
    mov rax, 462
    syscall
    ret

__syscall$setxattrat:
    mov rax, 463
    syscall
    ret

__syscall$getxattrat:
    mov rax, 464
    syscall
    ret

__syscall$listxattrat:
    mov rax, 465
    syscall
    ret

__syscall$removexattrat:
    mov rax, 466
    syscall
    ret
