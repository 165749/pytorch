#pragma once

#include <atomic>

#include <ATen/Tensor.h>

namespace at {
namespace vulkan {

struct VulkanImplInterface {
  virtual void enable_op_profiling() const = 0;
  virtual void disable_op_profiling() const = 0;
  virtual void reset_querypool() const = 0;

  virtual ~VulkanImplInterface() = default;
  virtual bool is_vulkan_available() const = 0;
  virtual at::Tensor& vulkan_copy_(at::Tensor& self, const at::Tensor& src)
      const = 0;
};

extern std::atomic<const VulkanImplInterface*> g_vulkan_impl_registry;

class VulkanImplRegistrar {
 public:
  VulkanImplRegistrar(VulkanImplInterface*);
};

at::Tensor& vulkan_copy_(at::Tensor& self, const at::Tensor& src);

} // namespace vulkan
} // namespace at
