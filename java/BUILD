package(
    default_visibility = ["//visibility:public"],
)

# Use the JNI headers bundled with Bazel for the selected target platform.
alias(
    name = "jni_inc",
    actual = "@bazel_tools//tools/jdk:jni",
)

genrule(
    name = "license_resource",
    srcs = ["@org_brotli//:LICENSE"],
    outs = ["META-INF/LICENSE"],
    cmd = "cp -f $< $@",
)

java_library(
    name = "license",
    resources = [":license_resource"],
)

########################################################
# WARNING: do not (transitively) depend on this target!
########################################################
cc_binary(
    name = "brotli_jni.dll",
    srcs = [
        "//org/brotli/wrapper/common:jni_src",
        "//org/brotli/wrapper/dec:jni_src",
        "//org/brotli/wrapper/enc:jni_src",
        "@org_brotli//:common_headers",
        "@org_brotli//:common_sources",
        "@org_brotli//:dec_headers",
        "@org_brotli//:dec_sources",
        "@org_brotli//:enc_headers",
        "@org_brotli//:enc_sources",
    ],
    linkshared = 1,
    deps = [
        ":jni_inc",
        "@org_brotli//:brotli_inc",
    ],
)

########################################################
# WARNING: do not (transitively) depend on this target!
########################################################
cc_binary(
    name = "brotli_jni_no_dictionary_data.dll",
    srcs = [
        "//org/brotli/wrapper/common:jni_src",
        "//org/brotli/wrapper/dec:jni_src",
        "//org/brotli/wrapper/enc:jni_src",
        "@org_brotli//:common_headers",
        "@org_brotli//:common_sources",
        "@org_brotli//:dec_headers",
        "@org_brotli//:dec_sources",
        "@org_brotli//:enc_headers",
        "@org_brotli//:enc_sources",
    ],
    defines = [
        "BROTLI_EXTERNAL_DICTIONARY_DATA=",
    ],
    linkshared = 1,
    deps = [
        ":jni_inc",
        "@org_brotli//:brotli_inc",
    ],
)
