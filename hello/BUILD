cc_library(
    name = "hello",
    srcs = ["hello.cc"],
    hdrs = ["hello.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "hello_test",
    size = "small",
    srcs = ["hello_test.cc"],
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "hello",
    ],
)