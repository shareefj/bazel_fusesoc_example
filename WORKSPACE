workspace(name = "workspace")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# --------------------------------------------------------------------------------
# gRPC
# --------------------------------------------------------------------------------

http_archive(
    name = "com_github_grpc_grpc",
    urls = [
        "https://github.com/grpc/grpc/archive/refs/tags/v1.51.0-pre1.tar.gz",
    ],
    strip_prefix = "grpc-1.51.0-pre1",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()
load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

# --------------------------------------------------------------------------------
# OpenTitan
# --------------------------------------------------------------------------------

git_repository(
    name = "opentitan",
    remote="https://github.com/lowRISC/opentitan",
    commit="c9aadf090739261178a00a78c59f5c3aadbe7d23",
    init_submodules=True,
    shallow_since="1669211646"
)

# --------------------------------------------------------------------------------
# Nonhermetic repo imports environment variables required for tool flows
# --------------------------------------------------------------------------------

load("@opentitan//rules:nonhermetic.bzl", "nonhermetic_repo")
nonhermetic_repo(name = "nonhermetic")

# --------------------------------------------------------------------------------
# Verilator Rules
# --------------------------------------------------------------------------------

http_archive(
    name = "rules_verilator",
    strip_prefix = "rules_verilator-0.1-rc5",
    sha256 = "0b40bd8359cb9e4bff964e2527283f1687d0b4c9dd179bb832e7c9fc0c472a1d",
    url = "https://github.com/shareefj/rules_verilator/archive/v0.1-rc5.zip",
)

load(
    "@rules_verilator//verilator:repositories.bzl",
    "rules_verilator_dependencies",
    "rules_verilator_toolchains",
)

rules_verilator_dependencies()
rules_verilator_toolchains()

