.intel_syntax noprefix

.global read
.global write
.global open
.global close
.global newstat
.global newfstat
.global newlstat
.global poll
.global lseek
.global mmap
.global mprotect
.global munmap
.global brk
.global rt_sigaction
.global rt_sigprocmask
.global rt_sigreturn
.global ioctl
.global pread64
.global pwrite64
.global readv
.global writev
.global access
.global pipe
.global select
.global sched_yield
.global mremap
.global msync
.global mincore
.global madvise
.global shmget
.global shmat
.global shmctl
.global dup
.global dup2
.global pause
.global nanosleep
.global getitimer
.global alarm
.global setitimer
.global getpid
.global sendfile64
.global socket
.global connect
.global accept
.global sendto
.global recvfrom
.global sendmsg
.global recvmsg
.global shutdown
.global bind
.global listen
.global getsockname
.global getpeername
.global socketpair
.global setsockopt
.global getsockopt
.global clone
.global fork
.global vfork
.global execve
.global exit
.global wait4
.global kill
.global newuname
.global semget
.global semop
.global semctl
.global shmdt
.global msgget
.global msgsnd
.global msgrcv
.global msgctl
.global fcntl
.global flock
.global fsync
.global fdatasync
.global truncate
.global ftruncate
.global getdents
.global getcwd
.global chdir
.global fchdir
.global rename
.global mkdir
.global rmdir
.global creat
.global link
.global unlink
.global symlink
.global readlink
.global chmod
.global fchmod
.global chown
.global fchown
.global lchown
.global umask
.global gettimeofday
.global getrlimit
.global getrusage
.global sysinfo
.global times
.global ptrace
.global getuid
.global syslog
.global getgid
.global setuid
.global setgid
.global geteuid
.global getegid
.global setpgid
.global getppid
.global getpgrp
.global setsid
.global setreuid
.global setregid
.global getgroups
.global setgroups
.global setresuid
.global getresuid
.global setresgid
.global getresgid
.global getpgid
.global setfsuid
.global setfsgid
.global getsid
.global capget
.global capset
.global rt_sigpending
.global rt_sigtimedwait
.global rt_sigqueueinfo
.global rt_sigsuspend
.global sigaltstack
.global utime
.global mknod
.global fstatfs
.global sysfs
.global getpriority
.global setpriority
.global sched_setparam
.global sched_getparam
.global sched_setscheduler
.global sched_getscheduler
.global sched_get_priority_max
.global sched_get_priority_min
.global sched_rr_get_interval
.global mlock
.global munlock
.global mlockall
.global munlockall
.global vhangup
.global modify_ldt
.global pivot_root
.global setrlimit
.global chroot
.global sync
.global acct
.global settimeofday
.global mount
.global umount
.global swapon
.global swapoff
.global reboot
.global sethostname
.global setdomainname
.global iopl
.global ioperm
.global lsetxattr
.global fsetxattr
.global getxattr
.global lgetxattr
.global fgetxattr
.global listxattr
.global llistxattr
.global flistxattr
.global removexattr
.global lremovexattr
.global fremovexattr
.global tkill
.global time
.global futex
.global sched_setaffinity
.global sched_getaffinity
.global io_submit
.global io_cancel
.global restart_syscall
.global semtimedop
.global fadvise64
.global timer_create
.global timer_settime
.global timer_gettime
.global timer_getoverrun
.global timer_delete
.global clock_settime
.global clock_gettime
.global clock_getres
.global clock_nanosleep
.global exit_group
.global epoll_wait
.global epoll_ctl
.global tgkill
.global utimes
.global mq_open
.global mq_unlink
.global mq_timedsend
.global mq_timedreceive
.global mq_notify
.global mq_getsetattr
.global kexec_load
.global waitid
.global add_key
.global request_key
.global keyctl
.global ioprio_set
.global ioprio_get
.global inotify_init
.global inotify_add_watch
.global inotify_rm_watch
.global migrate_pages
.global openat
.global mkdirat
.global mknodat
.global fchownat
.global futimesat
.global newfstatat
.global unlinkat
.global renameat
.global linkat
.global symlinkat
.global readlinkat
.global fchmodat
.global faccessat
.global pselect6
.global ppoll
.global unshare
.global set_robust_list
.global get_robust_list
.global splice
.global tee
.global sync_file_range
.global vmsplice
.global move_pages
.global utimensat
.global epoll_pwait
.global signalfd
.global timerfd_create
.global eventfd
.global fallocate
.global timerfd_settime
.global timerfd_gettime
.global accept4
.global signalfd4
.global eventfd2
.global epoll_create1
.global dup3
.global pipe2
.global inotify_init1
.global preadv
.global pwritev
.global rt_tgsigqueueinfo
.global perf_event_open
.global recvmmsg
.global fanotify_init
.global fanotify_mark
.global prlimit64
.global name_to_handle_at
.global open_by_handle_at
.global clock_adjtime
.global syncfs
.global sendmmsg
.global setns
.global getcpu
.global process_vm_readv
.global process_vm_writev
.global kcmp
.global finit_module
.global sched_setattr
.global sched_getattr
.global renameat2
.global seccomp
.global getrandom
.global memfd_create
.global kexec_file_load
.global bpf
.global execveat
.global userfaultfd
.global membarrier
.global mlock2
.global copy_file_range
.global preadv2
.global pwritev2
.global pkey_mprotect
.global pkey_alloc
.global pkey_free
.global statx
.global io_pgetevents
.global rseq
.global uretprobe
.global io_uring_register
.global open_tree
.global move_mount
.global fsopen
.global fsconfig
.global fsmount
.global fspick
.global pidfd_open
.global clone3
.global close_range
.global openat2
.global pidfd_getfd
.global faccessat2
.global process_madvise
.global epoll_pwait2
.global mount_setattr
.global quotactl_fd
.global landlock_create_ruleset
.global landlock_add_rule
.global landlock_restrict_self
.global memfd_secret
.global process_mrelease
.global futex_waitv
.global set_mempolicy_home_node
.global cachestat
.global fchmodat2
.global map_shadow_stack
.global futex_wake
.global futex_wait
.global futex_requeue
.global statmount
.global listmount
.global lsm_get_self_attr
.global lsm_set_self_attr
.global lsm_list_modules
.global mseal
.global setxattrat
.global getxattrat
.global listxattrat
.global removexattrat

read:
    mov rax, 0
    syscall
    ret

write:
    mov rax, 1
    syscall
    ret

open:
    mov rax, 2
    syscall
    ret

close:
    mov rax, 3
    syscall
    ret

newstat:
    mov rax, 4
    syscall
    ret

newfstat:
    mov rax, 5
    syscall
    ret

newlstat:
    mov rax, 6
    syscall
    ret

poll:
    mov rax, 7
    syscall
    ret

lseek:
    mov rax, 8
    syscall
    ret

mmap:
    mov rax, 9
    syscall
    ret

mprotect:
    mov rax, 10
    syscall
    ret

munmap:
    mov rax, 11
    syscall
    ret

brk:
    mov rax, 12
    syscall
    ret

rt_sigaction:
    mov rax, 13
    syscall
    ret

rt_sigprocmask:
    mov rax, 14
    syscall
    ret

rt_sigreturn:
    mov rax, 15
    syscall
    ret

ioctl:
    mov rax, 16
    syscall
    ret

pread64:
    mov rax, 17
    syscall
    ret

pwrite64:
    mov rax, 18
    syscall
    ret

readv:
    mov rax, 19
    syscall
    ret

writev:
    mov rax, 20
    syscall
    ret

access:
    mov rax, 21
    syscall
    ret

pipe:
    mov rax, 22
    syscall
    ret

select:
    mov rax, 23
    syscall
    ret

sched_yield:
    mov rax, 24
    syscall
    ret

mremap:
    mov rax, 25
    syscall
    ret

msync:
    mov rax, 26
    syscall
    ret

mincore:
    mov rax, 27
    syscall
    ret

madvise:
    mov rax, 28
    syscall
    ret

shmget:
    mov rax, 29
    syscall
    ret

shmat:
    mov rax, 30
    syscall
    ret

shmctl:
    mov rax, 31
    syscall
    ret

dup:
    mov rax, 32
    syscall
    ret

dup2:
    mov rax, 33
    syscall
    ret

pause:
    mov rax, 34
    syscall
    ret

nanosleep:
    mov rax, 35
    syscall
    ret

getitimer:
    mov rax, 36
    syscall
    ret

alarm:
    mov rax, 37
    syscall
    ret

setitimer:
    mov rax, 38
    syscall
    ret

getpid:
    mov rax, 39
    syscall
    ret

sendfile64:
    mov rax, 40
    syscall
    ret

socket:
    mov rax, 41
    syscall
    ret

connect:
    mov rax, 42
    syscall
    ret

accept:
    mov rax, 43
    syscall
    ret

sendto:
    mov rax, 44
    syscall
    ret

recvfrom:
    mov rax, 45
    syscall
    ret

sendmsg:
    mov rax, 46
    syscall
    ret

recvmsg:
    mov rax, 47
    syscall
    ret

shutdown:
    mov rax, 48
    syscall
    ret

bind:
    mov rax, 49
    syscall
    ret

listen:
    mov rax, 50
    syscall
    ret

getsockname:
    mov rax, 51
    syscall
    ret

getpeername:
    mov rax, 52
    syscall
    ret

socketpair:
    mov rax, 53
    syscall
    ret

setsockopt:
    mov rax, 54
    syscall
    ret

getsockopt:
    mov rax, 55
    syscall
    ret

clone:
    mov rax, 56
    syscall
    ret

fork:
    mov rax, 57
    syscall
    ret

vfork:
    mov rax, 58
    syscall
    ret

execve:
    mov rax, 59
    syscall
    ret

exit:
    mov rax, 60
    syscall
    ret

wait4:
    mov rax, 61
    syscall
    ret

kill:
    mov rax, 62
    syscall
    ret

newuname:
    mov rax, 63
    syscall
    ret

semget:
    mov rax, 64
    syscall
    ret

semop:
    mov rax, 65
    syscall
    ret

semctl:
    mov rax, 66
    syscall
    ret

shmdt:
    mov rax, 67
    syscall
    ret

msgget:
    mov rax, 68
    syscall
    ret

msgsnd:
    mov rax, 69
    syscall
    ret

msgrcv:
    mov rax, 70
    syscall
    ret

msgctl:
    mov rax, 71
    syscall
    ret

fcntl:
    mov rax, 72
    syscall
    ret

flock:
    mov rax, 73
    syscall
    ret

fsync:
    mov rax, 74
    syscall
    ret

fdatasync:
    mov rax, 75
    syscall
    ret

truncate:
    mov rax, 76
    syscall
    ret

ftruncate:
    mov rax, 77
    syscall
    ret

getdents:
    mov rax, 78
    syscall
    ret

getcwd:
    mov rax, 79
    syscall
    ret

chdir:
    mov rax, 80
    syscall
    ret

fchdir:
    mov rax, 81
    syscall
    ret

rename:
    mov rax, 82
    syscall
    ret

mkdir:
    mov rax, 83
    syscall
    ret

rmdir:
    mov rax, 84
    syscall
    ret

creat:
    mov rax, 85
    syscall
    ret

link:
    mov rax, 86
    syscall
    ret

unlink:
    mov rax, 87
    syscall
    ret

symlink:
    mov rax, 88
    syscall
    ret

readlink:
    mov rax, 89
    syscall
    ret

chmod:
    mov rax, 90
    syscall
    ret

fchmod:
    mov rax, 91
    syscall
    ret

chown:
    mov rax, 92
    syscall
    ret

fchown:
    mov rax, 93
    syscall
    ret

lchown:
    mov rax, 94
    syscall
    ret

umask:
    mov rax, 95
    syscall
    ret

gettimeofday:
    mov rax, 96
    syscall
    ret

getrlimit:
    mov rax, 97
    syscall
    ret

getrusage:
    mov rax, 98
    syscall
    ret

sysinfo:
    mov rax, 99
    syscall
    ret

times:
    mov rax, 100
    syscall
    ret

ptrace:
    mov rax, 101
    syscall
    ret

getuid:
    mov rax, 102
    syscall
    ret

syslog:
    mov rax, 103
    syscall
    ret

getgid:
    mov rax, 104
    syscall
    ret

setuid:
    mov rax, 105
    syscall
    ret

setgid:
    mov rax, 106
    syscall
    ret

geteuid:
    mov rax, 107
    syscall
    ret

getegid:
    mov rax, 108
    syscall
    ret

setpgid:
    mov rax, 109
    syscall
    ret

getppid:
    mov rax, 110
    syscall
    ret

getpgrp:
    mov rax, 111
    syscall
    ret

setsid:
    mov rax, 112
    syscall
    ret

setreuid:
    mov rax, 113
    syscall
    ret

setregid:
    mov rax, 114
    syscall
    ret

getgroups:
    mov rax, 115
    syscall
    ret

setgroups:
    mov rax, 116
    syscall
    ret

setresuid:
    mov rax, 117
    syscall
    ret

getresuid:
    mov rax, 118
    syscall
    ret

setresgid:
    mov rax, 119
    syscall
    ret

getresgid:
    mov rax, 120
    syscall
    ret

getpgid:
    mov rax, 121
    syscall
    ret

setfsuid:
    mov rax, 122
    syscall
    ret

setfsgid:
    mov rax, 123
    syscall
    ret

getsid:
    mov rax, 124
    syscall
    ret

capget:
    mov rax, 125
    syscall
    ret

capset:
    mov rax, 126
    syscall
    ret

rt_sigpending:
    mov rax, 127
    syscall
    ret

rt_sigtimedwait:
    mov rax, 128
    syscall
    ret

rt_sigqueueinfo:
    mov rax, 129
    syscall
    ret

rt_sigsuspend:
    mov rax, 130
    syscall
    ret

sigaltstack:
    mov rax, 131
    syscall
    ret

utime:
    mov rax, 132
    syscall
    ret

mknod:
    mov rax, 133
    syscall
    ret

personality:
    mov rax, 135
    syscall
    ret

ustat:
    mov rax, 136
    syscall
    ret

statfs:
    mov rax, 137
    syscall
    ret

fstatfs:
    mov rax, 138
    syscall
    ret

sysfs:
    mov rax, 139
    syscall
    ret

getpriority:
    mov rax, 140
    syscall
    ret

setpriority:
    mov rax, 141
    syscall
    ret

sched_setparam:
    mov rax, 142
    syscall
    ret

sched_getparam:
    mov rax, 143
    syscall
    ret

sched_setscheduler:
    mov rax, 144
    syscall
    ret

sched_getscheduler:
    mov rax, 145
    syscall
    ret

sched_get_priority_max:
    mov rax, 146
    syscall
    ret

sched_get_priority_min:
    mov rax, 147
    syscall
    ret

sched_rr_get_interval:
    mov rax, 148
    syscall
    ret

mlock:
    mov rax, 149
    syscall
    ret

munlock:
    mov rax, 150
    syscall
    ret

mlockall:
    mov rax, 151
    syscall
    ret

munlockall:
    mov rax, 152
    syscall
    ret

vhangup:
    mov rax, 153
    syscall
    ret

modify_ldt:
    mov rax, 154
    syscall
    ret

pivot_root:
    mov rax, 155
    syscall
    ret

prctl:
    mov rax, 157
    syscall
    ret

arch_prctl:
    mov rax, 158
    syscall
    ret

adjtimex:
    mov rax, 159
    syscall
    ret

setrlimit:
    mov rax, 160
    syscall
    ret

chroot:
    mov rax, 161
    syscall
    ret

sync:
    mov rax, 162
    syscall
    ret

acct:
    mov rax, 163
    syscall
    ret

settimeofday:
    mov rax, 164
    syscall
    ret

mount:
    mov rax, 165
    syscall
    ret

umount:
    mov rax, 166
    syscall
    ret

swapon:
    mov rax, 167
    syscall
    ret

swapoff:
    mov rax, 168
    syscall
    ret

reboot:
    mov rax, 169
    syscall
    ret

sethostname:
    mov rax, 170
    syscall
    ret

setdomainname:
    mov rax, 171
    syscall
    ret

iopl:
    mov rax, 172
    syscall
    ret

ioperm:
    mov rax, 173
    syscall
    ret

init_module:
    mov rax, 175
    syscall
    ret

delete_module:
    mov rax, 176
    syscall
    ret

quotactl:
    mov rax, 179
    syscall
    ret

gettid:
    mov rax, 186
    syscall
    ret

readahead:
    mov rax, 187
    syscall
    ret

setxattr:
    mov rax, 188
    syscall
    ret

lsetxattr:
    mov rax, 189
    syscall
    ret

fsetxattr:
    mov rax, 190
    syscall
    ret

getxattr:
    mov rax, 191
    syscall
    ret

lgetxattr:
    mov rax, 192
    syscall
    ret

fgetxattr:
    mov rax, 193
    syscall
    ret

listxattr:
    mov rax, 194
    syscall
    ret

llistxattr:
    mov rax, 195
    syscall
    ret

flistxattr:
    mov rax, 196
    syscall
    ret

removexattr:
    mov rax, 197
    syscall
    ret

lremovexattr:
    mov rax, 198
    syscall
    ret

fremovexattr:
    mov rax, 199
    syscall
    ret

tkill:
    mov rax, 200
    syscall
    ret

time:
    mov rax, 201
    syscall
    ret

futex:
    mov rax, 202
    syscall
    ret

sched_setaffinity:
    mov rax, 203
    syscall
    ret

sched_getaffinity:
    mov rax, 204
    syscall
    ret

io_setup:
    mov rax, 206
    syscall
    ret

io_destroy:
    mov rax, 207
    syscall
    ret

io_getevents:
    mov rax, 208
    syscall
    ret

io_submit:
    mov rax, 209
    syscall
    ret

io_cancel:
    mov rax, 210
    syscall
    ret

epoll_create:
    mov rax, 213
    syscall
    ret

remap_file_pages:
    mov rax, 216
    syscall
    ret

getdents64:
    mov rax, 217
    syscall
    ret

set_tid_address:
    mov rax, 218
    syscall
    ret

restart_syscall:
    mov rax, 219
    syscall
    ret

semtimedop:
    mov rax, 220
    syscall
    ret

fadvise64:
    mov rax, 221
    syscall
    ret

timer_create:
    mov rax, 222
    syscall
    ret

timer_settime:
    mov rax, 223
    syscall
    ret

timer_gettime:
    mov rax, 224
    syscall
    ret

timer_getoverrun:
    mov rax, 225
    syscall
    ret

timer_delete:
    mov rax, 226
    syscall
    ret

clock_settime:
    mov rax, 227
    syscall
    ret

clock_gettime:
    mov rax, 228
    syscall
    ret

clock_getres:
    mov rax, 229
    syscall
    ret

clock_nanosleep:
    mov rax, 230
    syscall
    ret

exit_group:
    mov rax, 231
    syscall
    ret

epoll_wait:
    mov rax, 232
    syscall
    ret

epoll_ctl:
    mov rax, 233
    syscall
    ret

tgkill:
    mov rax, 234
    syscall
    ret

utimes:
    mov rax, 235
    syscall
    ret

mbind:
    mov rax, 237
    syscall
    ret

set_mempolicy:
    mov rax, 238
    syscall
    ret

get_mempolicy:
    mov rax, 239
    syscall
    ret

mq_open:
    mov rax, 240
    syscall
    ret

mq_unlink:
    mov rax, 241
    syscall
    ret

mq_timedsend:
    mov rax, 242
    syscall
    ret

mq_timedreceive:
    mov rax, 243
    syscall
    ret

mq_notify:
    mov rax, 244
    syscall
    ret

mq_getsetattr:
    mov rax, 245
    syscall
    ret

kexec_load:
    mov rax, 246
    syscall
    ret

waitid:
    mov rax, 247
    syscall
    ret

add_key:
    mov rax, 248
    syscall
    ret

request_key:
    mov rax, 249
    syscall
    ret

keyctl:
    mov rax, 250
    syscall
    ret

ioprio_set:
    mov rax, 251
    syscall
    ret

ioprio_get:
    mov rax, 252
    syscall
    ret

inotify_init:
    mov rax, 253
    syscall
    ret

inotify_add_watch:
    mov rax, 254
    syscall
    ret

inotify_rm_watch:
    mov rax, 255
    syscall
    ret

migrate_pages:
    mov rax, 256
    syscall
    ret

openat:
    mov rax, 257
    syscall
    ret

mkdirat:
    mov rax, 258
    syscall
    ret

mknodat:
    mov rax, 259
    syscall
    ret

fchownat:
    mov rax, 260
    syscall
    ret

futimesat:
    mov rax, 261
    syscall
    ret

newfstatat:
    mov rax, 262
    syscall
    ret

unlinkat:
    mov rax, 263
    syscall
    ret

renameat:
    mov rax, 264
    syscall
    ret

linkat:
    mov rax, 265
    syscall
    ret

symlinkat:
    mov rax, 266
    syscall
    ret

readlinkat:
    mov rax, 267
    syscall
    ret

fchmodat:
    mov rax, 268
    syscall
    ret

faccessat:
    mov rax, 269
    syscall
    ret

pselect6:
    mov rax, 270
    syscall
    ret

ppoll:
    mov rax, 271
    syscall
    ret

unshare:
    mov rax, 272
    syscall
    ret

set_robust_list:
    mov rax, 273
    syscall
    ret

get_robust_list:
    mov rax, 274
    syscall
    ret

splice:
    mov rax, 275
    syscall
    ret

tee:
    mov rax, 276
    syscall
    ret

sync_file_range:
    mov rax, 277
    syscall
    ret

vmsplice:
    mov rax, 278
    syscall
    ret

move_pages:
    mov rax, 279
    syscall
    ret

utimensat:
    mov rax, 280
    syscall
    ret

epoll_pwait:
    mov rax, 281
    syscall
    ret

signalfd:
    mov rax, 282
    syscall
    ret

timerfd_create:
    mov rax, 283
    syscall
    ret

eventfd:
    mov rax, 284
    syscall
    ret

fallocate:
    mov rax, 285
    syscall
    ret

timerfd_settime:
    mov rax, 286
    syscall
    ret

timerfd_gettime:
    mov rax, 287
    syscall
    ret

accept4:
    mov rax, 288
    syscall
    ret

signalfd4:
    mov rax, 289
    syscall
    ret

eventfd2:
    mov rax, 290
    syscall
    ret

epoll_create1:
    mov rax, 291
    syscall
    ret

dup3:
    mov rax, 292
    syscall
    ret

pipe2:
    mov rax, 293
    syscall
    ret

inotify_init1:
    mov rax, 294
    syscall
    ret

preadv:
    mov rax, 295
    syscall
    ret

pwritev:
    mov rax, 296
    syscall
    ret

rt_tgsigqueueinfo:
    mov rax, 297
    syscall
    ret

perf_event_open:
    mov rax, 298
    syscall
    ret

recvmmsg:
    mov rax, 299
    syscall
    ret

fanotify_init:
    mov rax, 300
    syscall
    ret

fanotify_mark:
    mov rax, 301
    syscall
    ret

prlimit64:
    mov rax, 302
    syscall
    ret

name_to_handle_at:
    mov rax, 303
    syscall
    ret

open_by_handle_at:
    mov rax, 304
    syscall
    ret

clock_adjtime:
    mov rax, 305
    syscall
    ret

syncfs:
    mov rax, 306
    syscall
    ret

sendmmsg:
    mov rax, 307
    syscall
    ret

setns:
    mov rax, 308
    syscall
    ret

getcpu:
    mov rax, 309
    syscall
    ret

process_vm_readv:
    mov rax, 310
    syscall
    ret

process_vm_writev:
    mov rax, 311
    syscall
    ret

kcmp:
    mov rax, 312
    syscall
    ret

finit_module:
    mov rax, 313
    syscall
    ret

sched_setattr:
    mov rax, 314
    syscall
    ret

sched_getattr:
    mov rax, 315
    syscall
    ret

renameat2:
    mov rax, 316
    syscall
    ret

seccomp:
    mov rax, 317
    syscall
    ret

getrandom:
    mov rax, 318
    syscall
    ret

memfd_create:
    mov rax, 319
    syscall
    ret

kexec_file_load:
    mov rax, 320
    syscall
    ret

bpf:
    mov rax, 321
    syscall
    ret

execveat:
    mov rax, 322
    syscall
    ret

userfaultfd:
    mov rax, 323
    syscall
    ret

membarrier:
    mov rax, 324
    syscall
    ret

mlock2:
    mov rax, 325
    syscall
    ret

copy_file_range:
    mov rax, 326
    syscall
    ret

preadv2:
    mov rax, 327
    syscall
    ret

pwritev2:
    mov rax, 328
    syscall
    ret

pkey_mprotect:
    mov rax, 329
    syscall
    ret

pkey_alloc:
    mov rax, 330
    syscall
    ret

pkey_free:
    mov rax, 331
    syscall
    ret

statx:
    mov rax, 332
    syscall
    ret

io_pgetevents:
    mov rax, 333
    syscall
    ret

rseq:
    mov rax, 334
    syscall
    ret

uretprobe:
    mov rax, 335
    syscall
    ret

pidfd_send_signal:
    mov rax, 424
    syscall
    ret

io_uring_setup:
    mov rax, 425
    syscall
    ret

io_uring_enter:
    mov rax, 426
    syscall
    ret

io_uring_register:
    mov rax, 427
    syscall
    ret

open_tree:
    mov rax, 428
    syscall
    ret

move_mount:
    mov rax, 429
    syscall
    ret

fsopen:
    mov rax, 430
    syscall
    ret

fsconfig:
    mov rax, 431
    syscall
    ret

fsmount:
    mov rax, 432
    syscall
    ret

fspick:
    mov rax, 433
    syscall
    ret

pidfd_open:
    mov rax, 434
    syscall
    ret

clone3:
    mov rax, 435
    syscall
    ret

close_range:
    mov rax, 436
    syscall
    ret

openat2:
    mov rax, 437
    syscall
    ret

pidfd_getfd:
    mov rax, 438
    syscall
    ret

faccessat2:
    mov rax, 439
    syscall
    ret

process_madvise:
    mov rax, 440
    syscall
    ret

epoll_pwait2:
    mov rax, 441
    syscall
    ret

mount_setattr:
    mov rax, 442
    syscall
    ret

quotactl_fd:
    mov rax, 443
    syscall
    ret

landlock_create_ruleset:
    mov rax, 444
    syscall
    ret

landlock_add_rule:
    mov rax, 445
    syscall
    ret

landlock_restrict_self:
    mov rax, 446
    syscall
    ret

memfd_secret:
    mov rax, 447
    syscall
    ret

process_mrelease:
    mov rax, 448
    syscall
    ret

futex_waitv:
    mov rax, 449
    syscall
    ret

set_mempolicy_home_node:
    mov rax, 450
    syscall
    ret

cachestat:
    mov rax, 451
    syscall
    ret

fchmodat2:
    mov rax, 452
    syscall
    ret

map_shadow_stack:
    mov rax, 453
    syscall
    ret

futex_wake:
    mov rax, 454
    syscall
    ret

futex_wait:
    mov rax, 455
    syscall
    ret

futex_requeue:
    mov rax, 456
    syscall
    ret

statmount:
    mov rax, 457
    syscall
    ret

listmount:
    mov rax, 458
    syscall
    ret

lsm_get_self_attr:
    mov rax, 459
    syscall
    ret

lsm_set_self_attr:
    mov rax, 460
    syscall
    ret

lsm_list_modules:
    mov rax, 461
    syscall
    ret

mseal:
    mov rax, 462
    syscall
    ret

setxattrat:
    mov rax, 463
    syscall
    ret

getxattrat:
    mov rax, 464
    syscall
    ret

listxattrat:
    mov rax, 465
    syscall
    ret

removexattrat:
    mov rax, 466
    syscall
    ret
