package(default_visibility=["//visibility:public"])

cc_binary(
    name = "verilator_top",
    srcs = [
        "top.cc"
    ],
    deps = [
        "@verilator_v4.224//:svdpi",
        "@verilator_v4.224//:libverilator",
        "//:verilator_cc_lib",
        "//vendor/opentitan/simutil_verilator/cpp:simutil_verilator",
    ],
    copts = ["-Ibazel-bin/build.verilator_build/archive-verilator"]
)