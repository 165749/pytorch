rm -f build_android/bin/*torch
BUILD_PYTORCH_MOBILE=1 USE_VULKAN=1 USE_VULKAN_FP16_INFERENCE=1 USE_VULKAN_RELAXED_PRECISION=1 ANDROID_ABI=arm64-v8a ./scripts/build_android.sh -DBUILD_BINARY=ON
adb push build_android/bin/speed_benchmark_torch /data/local/tmp
