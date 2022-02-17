package(default_visibility = ["//visibility:public"])

java_binary(
  name = "wrapper",
  create_executable = False,
  runtime_deps = [
    "//:license",
    "//org/brotli/wrapper/enc",
    "//org/brotli/wrapper/dec",
  ],
)

java_binary(
  name = "native",
  create_executable = False,
  runtime_deps = [],
  resources = [
    "//:brotli_jni.dll",
  ],
)
