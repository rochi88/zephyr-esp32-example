#include "memfault/components.h"

void memfault_platform_get_device_info(sMemfaultDeviceInfo *info) {
  *info = (sMemfaultDeviceInfo){
      .device_serial = "DEMOSERIAL",
      .software_type = "zephyr-app",
      .software_version = "0.0.1" ZEPHYR_MEMFAULT_EXAMPLE_GIT_SHA1,
      .hardware_version = CONFIG_BOARD,
  };
}
