package(default_visibility=["//visibility:public"])

cc_library(
    name = "simutil_verilator",
    srcs = [
        "verilated_toplevel.cc",
        "verilator_sim_ctrl.cc",
    ],
    hdrs = [
        "verilated_toplevel.h",
        "verilator_sim_ctrl.h",
        "sim_ctrl_extension.h",
    ],
    defines = [
        "TOPLEVEL_NAME=top",
        "VM_TRACE_FMT_FST",
        "VL_USER_STOP",
        "VL_THREADED",
    ],
    includes = [
        "./"
    ],
    deps = [
        "@verilator_v4.224//:svdpi",
        "@verilator_v4.224//:libverilator",
        "//:verilator_cc_lib",
    ]
)