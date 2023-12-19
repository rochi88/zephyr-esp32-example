//! @file

// clang-format off
#include "memfault/ports/zephyr/include_compatibility.h"

#include MEMFAULT_ZEPHYR_INCLUDE(kernel.h)
#include MEMFAULT_ZEPHYR_INCLUDE(logging/log.h)
#include <string.h>

#include "memfault/components.h"
#include "memfault/ports/zephyr/http.h"
// clang-format on

LOG_MODULE_REGISTER(mflt_app, LOG_LEVEL_DBG);

MEMFAULT_STATIC_ASSERT(
  sizeof(CONFIG_MEMFAULT_PROJECT_KEY) > 1,
  "No Memfault Project Key Set! Please set CONFIG_MEMFAULT_PROJECT_KEY in prj.conf");

sMfltHttpClientConfig g_mflt_http_client_config = {
  .api_key = CONFIG_MEMFAULT_PROJECT_KEY,
};

void memfault_platform_get_device_info(sMemfaultDeviceInfo *info) {
  *info = (sMemfaultDeviceInfo){
    .device_serial = "DEMOSERIAL",
    .software_type = "zephyr-app",
    .software_version =
      CONFIG_MEMFAULT_EXAMPLE_SOFTWARE_VERSION "+" ZEPHYR_MEMFAULT_EXAMPLE_GIT_SHA1,
    .hardware_version = CONFIG_BOARD,
  };
}

int main(void) {
  LOG_INF("Memfault Demo App! Board %s\n", CONFIG_BOARD);

  printk(MEMFAULT_BANNER_COLORIZED);

  memfault_device_info_dump();
  memfault_zephyr_port_install_root_certs();

  return 0;
}
