package(default_visibility=["//visibility:public"])

load("@opentitan//rules:fusesoc.bzl", "fusesoc_build")
load("@bazel_skylib//rules:common_settings.bzl", "string_list_flag")

# --------------------------------------------------------------------------------
# Verilator
# --------------------------------------------------------------------------------

string_list_flag(
    name = "verilator_options",
    build_setting_default = [
        "--threads",
        "4",
    ],
)

string_list_flag(
    name = "make_options",
    build_setting_default = [
        "-j",
        "4",
    ],
)

fusesoc_build(
    name = "verilator_build",
    srcs = [
        ":all_rtl_files",
    ],
    cores = [
        "rtl/top.core"
    ],
    make_options = ":make_options",
    output_groups = {
        "archive": [
            "archive-verilator/Vtop__ALL.a",
        ],
        "headers": [
            "archive-verilator/Vtop.h",
        ]
    },
    systems = ["idex:test:top"],
    target = "archive",
    verilator_options = ":verilator_options",
)

filegroup(
    name = "all_rtl_files",
    srcs = glob(["rtl/**/*.sv"])
)

filegroup(
    name = "verilator_archive",
    srcs = [":verilator_build"],
    output_group = "archive"
)

filegroup(
    name = "verilator_headers",
    srcs = [":verilator_build"],
    output_group = "headers"
)

cc_library(
    name = "verilator_cc_lib",
    srcs = [":verilator_archive"],
    hdrs = [":verilator_headers"],
    linkstatic=1,
    includes = ["bazel-bin/build.verilator_build"]
)